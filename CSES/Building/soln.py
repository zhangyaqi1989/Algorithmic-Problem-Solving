#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##################################
# University of Wisconsin-Madison
# Author: Yaqi Zhang
##################################
# This module contains ...
##################################

# standard library
import sys

def max_rectangle(hs):
    "compute the maximum rectangle of a histogram"
    hs.append(-1)
    stack = [-1]
    mx = 0
    for i, h in enumerate(hs):
        while h < hs[stack[-1]]:
            height = hs[stack.pop()]
            width = i - stack[-1] - 1
            mx = max(mx, width * height)
        stack.append(i)
    hs.pop()
    return mx

def main():
    r, c = map(int, input().split())
    grid = []
    for i in range(r):
        grid.append(input())

    hs = [1 if val == '.' else 0 for val in grid[0]]
    mx = max_rectangle(hs)
    for i in range(1, r):
        for j in range(c):
            if grid[i][j] == '*':
                hs[j] = 0
            else:
                hs[j] += 1
        mx = max(mx, max_rectangle(hs))
    print(mx)

if __name__ == "__main__":
    main()
