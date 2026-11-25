#!/usr/bin/env python3
"""Build DSF_Final_Problems.docx — print-ready practice sheet.

Layout: cover page, then 13 pages holding exactly TWO problems each
(one per column, side by side), for 14 pages total = 7 sheets
printed double-sided.

Steps: compile every Problems/NN_*.cpp (g++ -std=c++17), run it with the
embedded sample input, capture real stdout, then typeset.

Print notes (Epson L3120, A4 80gsm): 0.38in (9.7mm) margins stay clear of
the printer's unprintable border, light-gray shading only, 0.5pt borders.

Regenerate with:  python3 outputs/build_docx.py
(python-docx is vendored in outputs/pylibs if not installed system-wide)
"""
import os, sys, glob, re, subprocess

BASE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(BASE)
PROBLEMS = os.path.join(ROOT, "Problems")
EXPL = os.path.join(ROOT, "Explanations")
BUILD = os.path.join("/tmp", "dsbuild")
OUT_DOCX = os.path.join(BASE, "DSF_Final_Problems.docx")

try:
    import docx
except ImportError:
    sys.path.insert(0, os.path.join(BASE, "pylibs"))
    import docx

from docx import Document
from docx.shared import Pt, Inches, Cm
from docx.enum.section import WD_SECTION_START
from docx.enum.text import WD_ALIGN_PARAGRAPH
from docx.oxml.ns import qn
from docx.oxml import OxmlElement

# ------------------------- tunables ----------------------------------------
# one full column per problem -> comfortable sizes (spec ranges, upper half)
CODE_PT = 6.0        # code + i/o box font (spec range 5.5-6.5)
CODE_LINE = 7.0      # exact line height for code (pt)
STMT_PT = 7.0        # problem statement font (spec range 6.5-7.5)
STMT_LINE = 8.2
HDR_PT = 8.0         # "Problem N: Title" header font (spec range 7.5-8)
HDR_LINE = 9.5
LBL_PT = 6.5         # "Input:" / "Output:" labels
LBL_LINE = 7.5
GAP_AFTER = 4.0      # space after each problem block (pt)
DROP_BLANKS = False  # keep code exactly as written (blanks are single)
HDR_PAD = 3          # inner padding of the shaded title bar (pt)
BOX_PAD = 2          # inner padding of the Input/Output boxes (pt)
MARGIN = 0.38        # inches all sides (9.7mm — inside inkjet print area)
HDR_FILL = "D9D9D9"  # header shading (light — inkjet friendly)
OUT_FILL = "F2F2F2"  # output box shading
IN_FILL = "FFFFFF"   # input box shading
BORDER_COL = "808080"
MONO = "Courier New"
SANS = "Calibri"

# pair-table geometry: [left 3.70 | gutter 0.11 | right 3.70] = 7.51"
CELL_W = Inches(3.70)
GUTTER_W = Inches(0.11)
M_OUT = 58           # outer cell margin, twips (0.04")
M_IN = 29            # inner cell margin, twips (0.02")
COL_CHARS = int((3.70 - 0.06) * 72 / (CODE_PT * 0.6003))  # chars that fit

# ------------------------- data: titles + sample inputs -------------------
TITLES = [
    "Insert an Element into an Array at a Specific Position",
    "Queue Enqueue Operation with Overflow Checking",
    "Search an Element in a Queue",
    "Calculate the Sum of Stack Elements",
    "Calculate the Average of Stack Elements",
    "Copy Elements from One Stack to Another Stack",
    "Perform Enqueue and Dequeue Operations in a Queue",
    "Move the First Element of a Queue to the Rear",
    "Reverse a Queue Using a Stack",
    "Separate Even and Odd Elements into Two Queues",
    "Represent an Undirected Graph Using an Adjacency Matrix",
    "Count the Total Number of Edges in a Graph Using an Adjacency Matrix",
    "Linear Search and Identify the Element Position",
    "Binary Search in Ascending Order",
    "Binary Search in Descending Order",
    "Count Elements Smaller Than a Given Value Using Binary Search",
    "Bubble Sort in Ascending Order",
    "Insertion Sort in Ascending Order",
    "Selection Sort in Ascending Order",
    "Display Array After Each Pass of Selection Sort",
    "Quick Sort in Ascending Order",
    "Merge Sort in Ascending Order",
    "Find Elements That Changed Positions After Bubble Sort",
    "Arrange Even Numbers First and Odd Numbers Later Using Insertion Sort",
    "Insert an Element into an Array at a Given Position",
]

INPUTS = {
    1:  "5\n10 20 30 40 50\n25\n3\n",
    2:  "2\n1 10\n1 20\n1\n2\n3\n",
    3:  "5\n12 5 8 20 9\n8\n",
    4:  "5\n10 20 30 40 50\n",
    5:  "3\n7 10 14\n",
    6:  "5\n1 2 3 4 5\n",
    7:  "2\n1 5\n1\n2\n2\n4\n",
    8:  "5\n10 20 30 40 50\n",
    9:  "5\n10 20 30 40 50\n",
    10: "7\n12 7 9 4 20 15 8\n",
    11: "4\n5\n1 2\n1 3\n2 4\n3 4\n2 3\n",
    12: "4\n0 1 1 0\n1 0 1 1\n1 1 0 1\n0 1 1 0\n",
    13: "6\n12 34 5 78 23 9\n78\n",
    14: "7\n2 5 8 12 16 23 38\n16\n",
    15: "6\n38 23 16 12 8 5\n12\n",
    16: "7\n3 8 15 20 25 30 45\n20\n",
    17: "5\n64 34 25 12 22\n",
    18: "6\n12 45 7 23 9 15\n",
    19: "5\n29 10 14 37 13\n",
    20: "5\n29 10 14 37 13\n",
    21: "8\n38 27 43 10 82 12 5 63\n",
    22: "6\n38 27 43 3 9 82\n",
    23: "5\n5 1 4 2 8\n",
    24: "8\n7 2 9 4 6 1 3 8\n",
    25: "4\n10 20 30 40\n99\n1\n",
}

# problems whose sample input here is a shorter variant than the one in
# Explanations/*.md (menu-driven programs, kept compact so a problem fits
# comfortably in one column)
SHORTENED = [2, 7]

COVER = {
    "course": "CSE 0613-122 — Data Structures Lab (DSF)",
    "subtitle": "Final Examination — Practice Problems and Solutions (C++)",
    "name": "Mahfuz Zayn",
    "id": "________________________",
    "section": "____________________",
    "semester": "2-1",
    "instructor": "____________________",
}

# ------------------------- helpers ----------------------------------------
def xml_preserve(run):
    for t in run._r.iter(qn("w:t")):
        t.set(qn("xml:space"), "preserve")

def pPr_insert(p, el):
    """Insert el into pPr at a schema-valid position."""
    pPr = p._p.get_or_add_pPr()
    ref = None
    for tag in ("w:spacing", "w:ind", "w:jc", "w:rPr"):
        f = pPr.find(qn(tag))
        if f is not None:
            ref = f
            break
    if ref is not None:
        ref.addprevious(el)
    else:
        pPr.append(el)

def shade(p, fill):
    e = OxmlElement("w:shd")
    e.set(qn("w:val"), "clear")
    e.set(qn("w:color"), "auto")
    e.set(qn("w:fill"), fill)
    pPr_insert(p, e)

def borders(p, sides, space=0, color=BORDER_COL):
    bd = OxmlElement("w:pBdr")
    for side in sides:
        b = OxmlElement("w:%s" % side)
        b.set(qn("w:val"), "single")
        b.set(qn("w:sz"), "4")
        b.set(qn("w:space"), str(space))
        b.set(qn("w:color"), color)
        bd.append(b)
    pPr_insert(p, bd)

def para(container, text, font=SANS, size=STMT_PT, bold=False, exact=None,
         before=0.0, after=0.0, keep=False, fill=None, sides=None,
         border_space=0, border_color=BORDER_COL,
         align=None, p=None):
    if p is None:
        p = container.add_paragraph()
    pf = p.paragraph_format
    pf.space_before = Pt(before)
    pf.space_after = Pt(after)
    if exact is not None:
        pf.line_spacing = Pt(exact)
    pf.keep_with_next = keep
    if align is not None:
        p.alignment = align
    if sides:
        borders(p, sides, space=border_space, color=border_color)
    if fill:
        shade(p, fill)
    r = p.add_run(text)
    r.font.name = font
    r.font.size = Pt(size)
    r.bold = bold
    xml_preserve(r)
    return p

def box_lines(container, lines, fill, mono_size=CODE_PT):
    """Bordered/shaded box of monospace lines (one paragraph per line)."""
    n = len(lines)
    for i, ln in enumerate(lines):
        sides = ["left", "right"]
        if i == 0:
            sides.append("top")
        if i == n - 1:
            sides.append("bottom")
        para(container, ln, font=MONO, size=mono_size, exact=CODE_LINE,
             keep=(i < n - 1), fill=fill, sides=sides, border_space=BOX_PAD,
             after=(GAP_AFTER if i == n - 1 else 0.0))

def clean_code(text):
    lines = [l.rstrip() for l in text.split("\n")]
    while lines and not lines[0].strip():
        lines.pop(0)
    while lines and not lines[-1].strip():
        lines.pop()
    out, blanks = [], 0
    for l in lines:
        if not l.strip():
            blanks += 1
            if DROP_BLANKS:
                continue
            if blanks <= 1:
                out.append("")
        else:
            blanks = 0
            out.append(l)
    return out

def statement_for(i):
    md = glob.glob(os.path.join(EXPL, "%02d_*.md" % i))
    if not md:
        return ""
    text = open(md[0], encoding="utf-8").read()
    m = re.search(r"## Problem Statement\s*\n(.*?)\n## ", text, re.S)
    if not m:
        return ""
    body = " ".join(l.strip() for l in m.group(1).strip().split("\n"))
    return re.sub(r"\s+", " ", body).strip()

def add_problem(cell, i, data, failures):
    """Write one problem block into a table cell, reusing the first para."""
    first = cell.paragraphs[0]
    # padded shaded title bar: invisible same-color borders at HDR_PAD
    # distance extend the shading outward = inner padding
    para(cell, "Problem %d: %s" % (i, TITLES[i - 1]), size=HDR_PT, bold=True,
         exact=HDR_LINE, after=4.0, keep=True, fill=HDR_FILL,
         sides=("top", "bottom", "left", "right"),
         border_space=HDR_PAD, border_color=HDR_FILL, p=first)
    d = data.get(i)
    if d is None:
        why = dict(failures).get(i, "missing")
        para(cell, "Could not be compiled or run — %s" % why, size=STMT_PT,
             exact=STMT_LINE, after=4.0, keep=True)
        return
    for ln in d["code"]:
        para(cell, ln, font=MONO, size=CODE_PT, exact=CODE_LINE, keep=True)
    para(cell, "Input:", size=LBL_PT, bold=True, exact=LBL_LINE,
         before=2.0, keep=True)
    box_lines(cell, d["in"], IN_FILL)
    para(cell, "Output:", size=LBL_PT, bold=True, exact=LBL_LINE,
         before=2.0, keep=True)
    box_lines(cell, d["out"], OUT_FILL)

def set_cell_margins(cell, left, right, top=0, bottom=0):
    tcPr = cell._tc.get_or_add_tcPr()
    mar = OxmlElement("w:tcMar")
    for side, w in (("top", top), ("left", left), ("bottom", bottom),
                    ("right", right)):
        e = OxmlElement("w:%s" % side)
        e.set(qn("w:w"), str(w))
        e.set(qn("w:type"), "dxa")
        mar.append(e)
    tcPr.append(mar)

def cant_split(row):
    trPr = row._tr.get_or_add_trPr()
    trPr.append(OxmlElement("w:cantSplit"))

# ------------------------- step 1: compile + run ---------------------------
def gather():
    os.makedirs(BUILD, exist_ok=True)
    data, failures = {}, []
    for i in range(1, 26):
        srcs = glob.glob(os.path.join(PROBLEMS, "%02d_*.cpp" % i))
        if not srcs:
            failures.append((i, "source file not found"))
            continue
        src = srcs[0]
        exe = os.path.join(BUILD, "p%02d" % i)
        r = subprocess.run(["g++", "-std=c++17", "-o", exe, src],
                           capture_output=True, text=True)
        if r.returncode != 0:
            failures.append((i, "compile error:\n" + r.stderr.strip()[:400]))
            continue
        try:
            run = subprocess.run([exe], input=INPUTS[i], capture_output=True,
                                 text=True, timeout=10)
            out = run.stdout
            if run.returncode != 0 or run.stderr.strip():
                failures.append((i, "runtime issue (rc=%d) stderr: %s"
                                 % (run.returncode, run.stderr.strip()[:200])))
        except Exception as e:
            failures.append((i, "could not run: %s" % e))
            continue
        code = clean_code(open(src, encoding="utf-8").read())
        data[i] = {"src": src, "code": code,
                   "in": [l for l in INPUTS[i].split("\n") if l != ""],
                   "out": [l for l in out.rstrip("\n").split("\n")]}
    return data, failures

# ------------------------- step 2: build the docx ---------------------------
def build(data, failures):
    doc = Document()
    cp = doc.core_properties
    cp.title = "DSF Final — Practice Problems and Solutions (C++)"
    cp.author = COVER["name"]

    # ---- section 1: cover (single column) ----
    sec = doc.sections[0]
    sec.page_width, sec.page_height = Cm(21.0), Cm(29.7)
    for m in ("left_margin", "right_margin", "top_margin", "bottom_margin"):
        setattr(sec, m, Inches(MARGIN))
    sec.header_distance = Inches(0.2)
    sec.footer_distance = Inches(0.2)

    para(doc, COVER["course"], size=16, bold=True, align=WD_ALIGN_PARAGRAPH.CENTER,
         exact=20, before=36, after=4)
    para(doc, COVER["subtitle"], size=12, bold=True, align=WD_ALIGN_PARAGRAPH.CENTER,
         exact=15, after=26)
    para(doc, "Name: %s     ID: %s" % (COVER["name"], COVER["id"]),
         size=10, align=WD_ALIGN_PARAGRAPH.CENTER, exact=13, after=2)
    para(doc, "Section: %s     Semester: %s     Instructor: %s"
         % (COVER["section"], COVER["semester"], COVER["instructor"]),
         size=10, align=WD_ALIGN_PARAGRAPH.CENTER, exact=13, after=22)
    para(doc, "Contents", size=11, bold=True, exact=14, after=4)

    toc = doc.add_table(rows=13, cols=2)
    toc.autofit = False
    for row in toc.rows:
        for c in row.cells:
            c.width = Inches(3.7)
    k = 0
    for row in toc.rows:
        for c in row.cells:
            if k < 25:
                p = c.paragraphs[0]
                pf = p.paragraph_format
                pf.space_before = Pt(0)
                pf.space_after = Pt(0)
                pf.line_spacing = Pt(9.5)
                r = p.add_run("%d. %s" % (k + 1, TITLES[k]))
                r.font.name = SANS
                r.font.size = Pt(7.5)
                xml_preserve(r)
                k += 1

    # ---- section 2: one pair-table per page (2 problems side by side) ----
    sec2 = doc.add_section(WD_SECTION_START.NEW_PAGE)
    sec2.page_width, sec2.page_height = Cm(21.0), Cm(29.7)
    for m in ("left_margin", "right_margin", "top_margin", "bottom_margin"):
        setattr(sec2, m, Inches(MARGIN))

    wrapped = 0
    pairs = [(a, a + 1 if a + 1 <= 25 else None) for a in range(1, 26, 2)]
    for pi, (a, b) in enumerate(pairs):
        if pi > 0:
            # tiny page-break paragraph (pageBreakBefore avoids double skips)
            brk = para(doc, "", size=2, exact=2)
            brk.paragraph_format.page_break_before = True
        tbl = doc.add_table(rows=1, cols=3)
        tbl.autofit = False
        row = tbl.rows[0]
        cant_split(row)
        widths = (CELL_W, GUTTER_W, CELL_W)
        for ci, w in enumerate(widths):
            row.cells[ci].width = w
            tbl.columns[ci].width = w
        left, mid, right = row.cells
        set_cell_margins(left, M_OUT, M_IN)
        set_cell_margins(right, M_IN, M_OUT)
        add_problem(left, a, data, failures)
        if b is not None:
            add_problem(right, b, data, failures)
        for d in (data.get(a), data.get(b) if b else None):
            if d:
                wrapped += sum(1 for ln in d["code"] if len(ln) > COL_CHARS)

    doc.save(OUT_DOCX)
    return wrapped

# ------------------------- main --------------------------------------------
if __name__ == "__main__":
    data, failures = gather()
    if len(data) != 25:
        print("WARNING: only %d/25 problems usable" % len(data))
    wrapped = build(data, failures)
    print("saved:", OUT_DOCX)
    print("layout: 2 problems per page (one per column), 13 pages + cover = 14")
    print("code font %.1fpt, line %.1fpt, column holds %d monospace chars"
          % (CODE_PT, CODE_LINE, COL_CHARS))
    print("code lines that wrap: %d" % wrapped)
    print("problems with shortened sample input (menu-driven): %s"
          % ", ".join(str(s) for s in SHORTENED))
    if failures:
        print("\nFAILURES:")
        for i, why in failures:
            print("  problem %02d: %s" % (i, why))
    else:
        print("all 25 compiled and ran cleanly")
