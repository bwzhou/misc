#!/usr/bin/python
import re, requests, sys
from bs4 import BeautifulSoup
from collections import defaultdict

tasks = defaultdict(list)

with open(sys.argv[1]) as f:
  for line in f:
    row = line.strip().split()
    for url in row[2:]:
      resp = requests.get(url)
      soup = BeautifulSoup(resp.text)
      for td in soup.find_all('td'):
        for string in td.strings:
          if 'sec' in string:
            r = re.search('\((\d+mins,\s)?(\d+)sec\)', string)
            sec = int(r.group(2))
            if r.group(1):
              sec += int(re.search('\d+', r.group(1)).group(0)) * 60
            tasks[row[1], row[0]].append(sec)

for s, n in tasks:
  print s, n, ' '.join([str(each) for each in tasks[s, n]])
