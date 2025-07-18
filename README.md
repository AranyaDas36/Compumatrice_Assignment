# Bounded Path Planner in Grid with Weighted Teleports 

This project solves a pathfinding problem on a grid with walls, start/end points, and teleporters (A–Z), where each teleporter can be used 

>> Problem Statement

Given:
- A grid of characters with:
  - `S`: Start point
  - `E`: End point
  - `#`: Wall (impassable)
  - `.`: Open cell
  - `A-Z`: Teleporters (each pair used once)
- The goal is to reach from `S` to `E` in the minimum number of steps, optionally using teleporters.

### Input

- A list of strings (representing rows of the grid)

### Output

- Minimum number of steps to reach `E` from `S`
- Return `-1` if `E` is unreachable

---

## Files

- `assignment.cpp` – Main C++ implementation
- `assignment` – Compiled binary (after build)
- `README.md` – You're here!

---

## ▶️ How to Compile & Run

### 1. Compile (macOS / Linux):

```bash
clang++ -std=c++17 -stdlib=libc++ assignment.cpp -o assignment

then run
- ./assignment
