#!/usr/bin/env python

import sys, math, random, operator

def topic_distance(loc1, loc2):
  return math.sqrt((loc1[0] - loc2[0])**2 + (loc1[1] - loc2[1])**2)

class heap:
  def __init__(self, limit):
    self.data = []
    self.limit = limit
  def size(self):
    return len(self.data)
  def insert(self, e):
    #print self.data
    if self.limit:
      if len(self.data) >= self.limit:
        if self.compare(self.data[0], e) > 0:
          self.data[0] = e
          self.bubbledown()
      else:
        self.data.append(e)
        self.bubbleup()
  def extract_max(self):
    if len(self.data) > 1:
      root = self.data[0]
      self.data[0] = self.data.pop()
      self.bubbledown()
      return root
    elif len(self.data) == 1:
      return self.data.pop()
    else:
      return -1
  def compare(self, x, y):
    if abs(x[0] - y[0]) < 0.001:
      res = y[1] - x[1]
    else:
      res = x[0] - y[0]
    return res
  def bubbleup(self):
    current = len(self.data) - 1
    while current > 0:
      parent = (current - 1) / 2
      if self.compare(self.data[current], self.data[parent]) > 0:
        tmp = self.data[current]
        self.data[current] = self.data[parent]
        self.data[parent] = tmp
        current = parent
      else:
        break
  def bubbledown(self):
    current = 0
    while True:
      left = current * 2 + 1
      right = current * 2 + 2
      if left < len(self.data) and right < len(self.data):
        child = left if self.compare(self.data[left], self.data[right]) > 0 else right
      elif left < len(self.data):
        child = left
      else:
        break

      if self.compare(self.data[current], self.data[child]) < 0:
        tmp = self.data[current]
        self.data[current] = self.data[child]
        self.data[child] = tmp
        current = child
      else:
        break

class Topic:
  def __init__(self, location):
    self.loc = location
    self.q = []
  def add_question(self, question_id):
    self.q.append(question_id)

def find_nearest(l, k):
  result = []
  q = heap(k)
  for each in l:
    if l[each] < 0:
      continue
    q.insert((l[each], each))
  while q.size() > 0:
    result.append(q.extract_max()[1])
  result.reverse()
  return result

def process(gen):
  number_topics = 0
  number_questions = 0
  number_queries = 0
  topics = {}
  i = 0
  ##failed_tests = []
  ##failed_count = 0
  for line in gen:
    row = line.strip().split()
    if i == 0:
      ##failed_tests.append(line)
      if len(row) == 3:
        number_topics = int(row[0])
        number_questions = int(row[1])
        number_queries = int(row[2])
        ##print 'topics:', number_topics
        ##print 'questions:', number_questions
        ##print 'queries:', number_queries
    elif i >= 1 and i <= number_topics:
      ##failed_tests.append(line)
      topics[int(row[0])] = Topic((float(row[1]), float(row[2])))
    elif i >= number_topics + 1 and i <= number_topics + number_questions:
      ##failed_tests.append(line)
      for cell in row[2:]:
        topic_id = int(cell)
        topics[topic_id].add_question(int(row[0]))
    elif i >= number_topics + number_questions + 1 and i <= number_topics + number_questions + number_queries:
      result_size = int(row[1])
      location = float(row[2]), float(row[3])
      dist = {}
      if row[0] == 't':
        for topic_id in topics:
          dist[topic_id] = topic_distance(location, topics[topic_id].loc)
      elif row[0] == 'q':
        for topic_id in topics:
          d = topic_distance(location, topics[topic_id].loc)
          for question_id in topics[topic_id].q:
            if question_id not in dist or d < dist[question_id]:
              dist[question_id] = d
      # answer
      top_ids = find_nearest(dist, result_size)

      # verify
      ##verify_ids = [each[0] for each in sorted(dist.iteritems(), key=lambda x: x[1] * 10000000 - x[0])[:result_size]]

      ##if not top_ids == verify_ids:
      ##  failed_tests.append(line)
      ##  failed_count += 1
      ##  print 'error:', row
      ##for index, each in enumerate(zip(top_ids, verify_ids)):
      ##  if each[0] != each[1]:
      ##    print index, each, dist[each[0]], dist[each[1]]

      # result
      print ' '.join([str(each) for each in top_ids])

    i += 1

  # Only output failed queries
  ##header = failed_tests[0].strip().split()
  ##header[2] = str(failed_count)
  ##failed_tests[0] = ' '.join(header) + '\n'
  ##f = open('test.in', 'w')
  ##for line in failed_tests:
  ##  f.write(line)
  ##f.close()

def random_test_gen():
  seed = random.randint(0, sys.maxint)
  print 'seed:', seed
  random.seed(seed)
  number_topics = random.randint(1, 10000)
  number_questions = random.randint(1, 1000)
  number_queries = random.randint(1, 10000)
  yield ' '.join([str(number_topics), str(number_questions), str(number_queries)]) + '\n'
  topic_begin = 1
  topic_end = number_topics
  question_begin = topic_end + 1
  question_end = topic_end + number_questions
  query_begin = question_end + 1
  query_end = question_end + number_queries
  for i in range(number_topics):
    x = random.randint(0, 10**7)/10.0
    y = random.randint(0, 10**7)/10.0
    yield ' '.join([str(i), str(x), str(y)]) + '\n'
  for i in range(number_questions):
    t = random.randint(0, 10)
    l = random.sample(range(number_topics), t)
    output = []
    output.append(str(i))
    output.append(str(t))
    output.extend([str(each) for each in l])
    yield ' '.join(output) + '\n'
  for i in range(number_queries):
    output = []
    output.append(random.choice(['t', 'q']))
    output.append(str(random.randint(0, 100)))
    x = random.randint(0, 10**7)/10.0
    y = random.randint(0, 10**7)/10.0
    output.append(str(x))
    output.append(str(y))
    yield ' '.join(output) + '\n'


def main():
  if len(sys.argv) > 1:
    process(random_test_gen())
  else:
    process(sys.stdin)

if __name__ == '__main__':
  main()
