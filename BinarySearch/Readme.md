# Traditional Binary Search

## Purpose & Prerequisites
- **Goal:** Check if a target number exists in a sorted array.  
- **Requirement:** Array must be **sorted** (ascending or descending).  

## Efficiency
- **Time Complexity:** `O(log N)` → halves the search space each step.  
- **Space Complexity:** `O(1)` → only uses a few variables (`L, R, M`).  

## Steps
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

## Broader Context
- Works on sorted arrays **and** ranges of values.  
- Foundation for advanced **condition-based (over-under)** binary search problems.  
- Essential algorithm for **interviews & problem solving**.  
