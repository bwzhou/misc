#!/usr/bin/python

import sys

with open(sys.argv[1]) as f:
  for line in f:
    row = line.strip().split()
    for i in range(2, len(row)):
      print sys.argv[1], row[0], row[1][2:], row[i]
