# 🚢 push_swap — 42 Project

## 📖 Overview

**push_swap** is a sorting algorithm project from the 42 curriculum that challenges you to sort data on a stack using a limited set of operations, while minimizing the total number of moves.

The goal is to write a program that sorts a stack of integers using two stacks and a set of predefined instructions, demonstrating mastery of algorithmic thinking, data structures, and optimization.

---

## ⚙️ Project Goals

- Implement sorting with **two stacks** (`stack A` and `stack B`)  
- Use only a limited set of operations (push, swap, rotate, reverse rotate)  
- Minimize the total number of instructions executed  
- Handle any number of integers passed as arguments  
- Detect and handle invalid input (duplicates, non-integers, overflow)  
- Write a **checker** program that verifies the correctness of the sorting instructions  

---

## 🚀 Allowed Operations

- `sa` — swap the first two elements of stack A  
- `sb` — swap the first two elements of stack B  
- `ss` — `sa` and `sb` at the same time  
- `pa` — push the first element of stack B to stack A  
- `pb` — push the first element of stack A to stack B  
- `ra` — rotate stack A (first element becomes last)  
- `rb` — rotate stack B  
- `rr` — `ra` and `rb` at the same time  
- `rra` — reverse rotate stack A (last element becomes first)  
- `rrb` — reverse rotate stack B  
- `rrr` — `rra` and `rrb` at the same time  

---

## 📦 Usage

```bash
# Compile your program
make
make bonus

# Run push_swap with a list of integers
./push_swap 3 2 1 5 4

# Optional: use the checker to verify a sequence of operations
./checker 3 2 1 5 4
```

---

## 🧩 Algorithm & Strategy
- Handle small input sizes (2-5 elements) with hardcoded efficient sequences

- For larger inputs, use a sorting algorithm optimized for the constraints (e.g., chunks sort, quicksort adapted to stack operations)

- Optimize instruction sequences by combining or skipping redundant moves

- Validate inputs strictly (check for duplicates, invalid characters, integer overflows)

---

## 🧪 Testing & Validation
- Extensive manual and automatic testing to ensure correctness

- Use checker to verify that output instructions correctly sort the input

- Benchmark instruction counts on large datasets to improve efficiency

---

## 🧠 What I Learned
- Implementing sorting algorithms using stack operations and constraints

- Algorithm optimization and complexity reduction in limited environments

- Handling edge cases and input validation thoroughly

- Developing both a functional program and a correctness verifier

- Working under strict project requirements and coding standards

## 🗂️ File Structure
```
├── push_swap.h
├── main.c
├── arr_alloc.c
├── ft_lstatoi.c
├── ft_parsing.c
├── libft_lst1.c
├── operations.c
├── push_swap_min.c
├── push_swap_max.c
└─────bouns part
├── checker_bonus.c
├── push_swap_checker.h
├── ft_lstatoi_bonus.c
├── ft_parsing_bonus.c
├── operations_bonus.c
├── libft_lst1_bonus.c
└────── Makefile
```
## ✍️ Author
  Amine Elsayed
    42 Network Student | Algorithm enthusiast

“Sorting is the heart of efficient algorithms — mastering it with constraints is a true challenge.”
