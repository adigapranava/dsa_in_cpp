# Binary Search Methods

Binary search is a fundamental algorithm with **two main applications**:  
1. **Traditional Method** → searches for a specific target.  
2. **Condition-Based Method (Over-Under Technique)** → finds the first/last element that satisfies a condition.  

---

## 1. Traditional Binary Search

### Purpose & Prerequisites
- **Goal:** Check if a target number exists in a sorted array.  
- **Requirement:** Array must be **sorted** (ascending or descending).  

### Efficiency
- **Time Complexity:** `O(log N)` → halves the search space each step.  
- **Space Complexity:** `O(1)` → only uses a few variables (`L, R, M`).  

### Steps
1. **Initialize Pointers:**  
   - `L = 0` (left index)  
   - `R = n - 1` (right index)  

2. **Loop Condition:**  
   - While `L <= R` → keep searching.  
   - Stops when `L > R` (search space exhausted).  

3. **Find Midpoint:**  
   - `M = (L + R) // 2` (standard).  
   - Safer: `M = L + (R - L) // 2` (avoids overflow).  

4. **Comparison Logic:**  
   - If `arr[M] == target` → found → return **true**.  
   - If `target < arr[M]` → search **left** → `R = M - 1`.  
   - If `target > arr[M]` → search **right** → `L = M + 1`.  

5. **Termination:**  
   - Found → return **true**.  
   - Not found after loop → return **false**.  

### Broader Context
- Works on sorted arrays **and** ranges of values.  
- Foundation for advanced **condition-based (over-under)** binary search problems.  
- Essential algorithm for **interviews & problem solving**.  

---

## 2. Condition-Based Binary Search (Over-Under Technique)

### Purpose
- Used to find the **first or last element** that satisfies a given condition.  
- Locates a **“trigger point”** where the property of elements changes.  
- Examples:  
  - `[true, true, true, false, false]` → find **first false**.  
  - `[false, false, true, true]` → find **first true**.  
  - Real-world: First day a sick person feels better.  

### Input Requirement
- Input array/range must be divided into **two distinct parts**:  
  - All elements on the left side of one type.  
  - All elements on the right side of another type.  

### Key Differences (vs Traditional)
- **Loop Condition:**  
  - `while L < R` (instead of `L <= R`).  
  - Terminates when `L == R`, directly pointing to the answer.  

- **Pointer Updates:**  
  - If condition **satisfied** at `M` → move **R = M` (keep candidate).  
  - If condition **not satisfied** at `M` → move **L = M + 1`.  

- **Return Value:**  
  - Returns the **index (`L` or `R`)** of the first element satisfying the condition.  

### Efficiency
- **Time Complexity:** `O(log N)`  
- **Space Complexity:** `O(1)`  

### Versatility
- Works on arrays **and ranges of values** (e.g., searching from `2` to `1,000,000`).  
- Very common in **LeetCode / coding interview problems**.  
- Known as the **“secret method”** of binary search.  

---