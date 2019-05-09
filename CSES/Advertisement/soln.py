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

def main():
    n = int(input())
    hs = list(map(int, input().split()))
    stack = [-1]
    hs.append(0)
    mx = 0
    for i, h in enumerate(hs):
        while stack and h < hs[stack[-1]]:
            height = hs[stack.pop()]
            width = i - stack[-1] - 1
            mx = max(mx, height * width)
        stack.append(i)
    print(mx)


if __name__ == "__main__":
    main()

