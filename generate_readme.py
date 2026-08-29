import openpyxl
import os
import re

script_dir = os.path.dirname(os.path.abspath(__file__))
excel_path = os.path.join(script_dir, "DSA_Complete_Roadmap_1_to_Interview.xlsx")
readme_path = os.path.join(script_dir, "README.md")
svg_path = os.path.join(script_dir, "progress.svg")

if not os.path.exists(excel_path):
    print("Excel file not found at:", excel_path)
    exit(1)

wb = openpyxl.load_workbook(excel_path, data_only=True)
sheet = wb["Master Roadmap"]

# Helper to clean name for filename
def clean_filename(problem_name):
    name = re.sub(r'\([^)]*\)', '', problem_name)
    words = re.split(r'[\s\-/\+\\\._]+', name)
    clean_words = []
    for w in words:
        if w:
            w_clean = re.sub(r'[^a-zA-Z0-9]', '', w)
            if w_clean:
                clean_words.append(w_clean.capitalize())
    return "".join(clean_words)

# Mapping of custom solved files
solved_mapping = {
    1: "23Celibrity.cpp",
    2: "24MajorityElement.cpp",
    3: "7TwoSum.cpp",
    6: "14palandrom.cpp",
    20: "17reverselist.cpp",
    52: "11rotateArray.cpp",
    53: "6mergeSortedArrays.cpp",
    92: "8maximumSubarray.cpp"
}

problems = []
solved_count = 0

for r in range(2, sheet.max_row + 1):
    no_val = sheet.cell(row=r, column=1).value
    level = sheet.cell(row=r, column=2).value
    pattern = sheet.cell(row=r, column=3).value
    problem_name = sheet.cell(row=r, column=4).value
    difficulty = sheet.cell(row=r, column=5).value
    why_skill = sheet.cell(row=r, column=6).value
    status = sheet.cell(row=r, column=7).value
    
    if not problem_name:
        continue
        
    try:
        no_val = int(no_val)
    except (TypeError, ValueError):
        continue
        
    is_solved = (status == "Solved")
    if is_solved:
        solved_count += 1
        
    # Get local filename link
    if no_val in solved_mapping:
        local_file = solved_mapping[no_val]
    else:
        safe_name = clean_filename(problem_name)
        local_file = f"No_{no_val:03d}_{safe_name}.cpp"
        
    problems.append({
        'no': no_val,
        'level': level,
        'pattern': pattern,
        'name': problem_name,
        'difficulty': difficulty,
        'why': why_skill,
        'solved': is_solved,
        'file': local_file
    })

total_problems = len(problems)
pct = (solved_count / total_problems) * 100 if total_problems else 0
fill_width = 400 * (solved_count / total_problems) if total_problems else 0

# Count by level
level_stats = {}
for p in problems:
    lvl = p['level']
    if lvl not in level_stats:
        level_stats[lvl] = {'total': 0, 'solved': 0}
    level_stats[lvl]['total'] += 1
    if p['solved']:
        level_stats[lvl]['solved'] += 1

# Generate progress.svg
svg_content = f"""<svg width="400" height="60" viewBox="0 0 400 60" fill="none" xmlns="http://www.w3.org/2000/svg">
  <style>
    .track {{
      fill: #e1e4e8;
    }}
    .fill {{
      fill: url(#grad);
      animation: load 2s cubic-bezier(0.4, 0, 0.2, 1) forwards;
      width: 0px;
    }}
    .text {{
      font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Helvetica, Arial, sans-serif;
      font-size: 14px;
      font-weight: 600;
      fill: #24292e;
      opacity: 0;
      animation: fadeIn 0.5s ease-out 1s forwards;
    }}
    @keyframes load {{
      to {{ width: {fill_width:.1f}px; }}
    }}
    @keyframes fadeIn {{
      to {{ opacity: 1; }}
    }}
    @media (prefers-color-scheme: dark) {{
      .track {{
        fill: #21262d;
        stroke: #30363d;
      }}
      .text {{
        fill: #c9d1d9;
      }}
    }}
  </style>
  <defs>
    <linearGradient id="grad" x1="0%" y1="0%" x2="100%" y2="0%">
      <stop offset="0%" stop-color="#4facfe" />
      <stop offset="100%" stop-color="#00f2fe" />
    </linearGradient>
  </defs>
  
  <text x="0" y="18" class="text" style="animation: fadeIn 0.5s ease-out forwards; opacity: 1;">Roadmap Completion</text>
  <text x="360" y="18" class="text">{pct:.1f}%</text>

  <rect x="0" y="30" width="400" height="16" rx="8" class="track" />
  <rect x="0" y="30" height="16" rx="8" class="fill" />
</svg>
"""

with open(svg_path, "w", encoding="utf-8") as f:
    f.write(svg_content)

# Generate README Content with badges and animated SVG
content = f"""# 🎯 ZTM DSA: 0 to Hero Placement Roadmap

Welcome to my personal Data Structures and Algorithms (DSA) workspace! This repository contains my implementations of foundational data structures from Andrei Neagoie's Zero To Mastery (ZTM) course, along with a curated **150-problem LeetCode roadmap** aimed at cracking product-based company placement drives.

<p align="left">
  <img src="https://img.shields.io/badge/LeetCode-{solved_count}%20%2F%20150%20Solved-blue?style=for-the-badge&logo=leetcode" alt="Leetcode Solved">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-orange?style=for-the-badge&logo=c%2B%2B" alt="Language">
  <img src="https://img.shields.io/badge/Placement-Prep-success?style=for-the-badge" alt="Placement Prep">
  <img src="https://img.shields.io/badge/Status-Grinding-red?style=for-the-badge" alt="Status">
</p>

---

## 📊 Progress Dashboard

Here is my interactive progress tracker. It features a custom animated bar that automatically updates whenever a problem is marked as solved!

<p align="left">
  <img src="./progress.svg" alt="Roadmap Progress" width="400">
</p>

| Difficulty Level | Problems Solved | Progress Percentage | Status |
| :--- | :---: | :---: | :---: |
"""

for lvl, stats in level_stats.items():
    l_pct = (stats['solved'] / stats['total']) * 100
    indicator = "🟢 Active" if stats['solved'] > 0 else "⚪ Not Started"
    if stats['solved'] == stats['total']:
        indicator = "🏆 Completed"
    content += f"| **{lvl}** | {stats['solved']} / {stats['total']} | {l_pct:.1f}% | {indicator} |\n"

content += f"""| **TOTAL** | **{solved_count} / {total_problems}** | **{pct:.1f}%** | **🧠 Grind Mode** |

---

## 🛠️ Tech Stack & Structure
* **Language:** C++ (using modern Standard Template Library - STL)
* **Compiler:** `g++` (C++17/C++20 standard)
* **Custom Codebases:** Core data structures (BST, Graphs, LinkedLists, HashTables) coded from scratch to build core pointer memory concepts.
* **Problem Set:** Curated by difficulty levels and algorithmic patterns (Sliding Window, Monotonic Stacks, DP, Dijkstra, Segment Trees).

---

## 📂 Detailed Roadmap

Below is the complete list of 150 problems categorized by level. Each problem links to its LeetCode description page and its local C++ source/template file.

"""

levels_ordered = ["Level 1", "Level 2", "Level 3", "Interview Mode"]

for lvl in levels_ordered:
    lvl_problems = [p for p in problems if p['level'] == lvl]
    stats = level_stats.get(lvl, {'total': 0, 'solved': 0})
    
    content += f"""
<details>
<summary><b>🔥 {lvl} ({stats['solved']}/{stats['total']} Solved)</b></summary>
<br>

| No. | Problem | Algorithmic Pattern | Difficulty | Local C++ Code | Status |
| :---: | :--- | :--- | :---: | :--- | :---: |
"""
    for p in lvl_problems:
        status_icon = "✅ Solved" if p['solved'] else "⏳ Not Started"
        diff_color = "🟢 Easy" if p['difficulty'] == "Easy" else ("🟡 Medium" if p['difficulty'] == "Medium" else "🔴 Hard")
        
        # Leetcode slug
        lc_slug = p['name'].lower().replace(' ', '-').replace('(', '').replace(')', '').replace("'", "").replace(",", "")
        lc_link = f"https://leetcode.com/problems/{lc_slug}/"
        
        content += f"| {p['no']} | [{p['name']}]({lc_link}) | {p['pattern']} | {diff_color} | [`{p['file']}`](./{p['file']}) | {status_icon} |\n"
        
    content += "\n</details>\n"

content += """
---

## 🚀 How to Compile and Run (C++)

To compile and run any C++ solution locally, use a terminal and run the following commands:

```bash
# Compile
g++ -std=c++17 -O3 <Filename>.cpp -o output.exe

# Execute (Windows)
./output.exe
```

---

*“The only way to learn a new programming language is by writing programs in it.” – Dennis Ritchie. Keep grinding!* 💻🔥
"""

with open(readme_path, "w", encoding="utf-8") as f:
    f.write(content)

print(f"SUCCESS: Re-generated README.md and progress.svg! (Solved: {solved_count}/{total_problems})")
