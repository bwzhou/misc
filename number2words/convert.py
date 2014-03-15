#!/usr/bin/env python
import sys

with open('/usr/share/dict/words') as d:
  words = set(word.strip().lower() for word in d)

digit_map = {
    '2': 'abc',
    '3': 'def',
    '4': 'ghi',
    '5': 'jkl',
    '6': 'mno',
    '7': 'pqrs',
    '8': 'tuv',
    '9': 'wxyz',
}

def valid_words(s):
  return s[0:3] in words and s[3:] in words or s[0:4] in words and s[4:] in words or s in words

def word_numbers(input):
  input = str(input)
  ret = ['']
  for char in input:
    letters = digit_map.get(char, '')
    ret = [prefix+letter for prefix in ret for letter in letters]
  return [s for s in ret if valid_words(s)]

print word_numbers(sys.argv[1])
