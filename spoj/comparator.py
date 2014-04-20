import sys
import random
import string
import subprocess

def invoke(a, i):
  return subprocess.Popen(a + '<' + i, shell = True, stdout=subprocess.PIPE).communicate()[0].splitlines()

A1 = sys.argv[1]
A2 = sys.argv[2]
L = int(sys.argv[3])
N = int(sys.argv[4])

f = open('/tmp/input', 'w')
f.write(str(N) + '\n')
for _ in range(N):
  l = random.randrange(1, L + 1)
  R = ''.join(random.choice(string.digits) for _ in range(l))
  f.write(R + '\n')
f.close()

i = 1
for R1, R2 in zip(invoke(A1, '/tmp/input'), invoke(A2, '/tmp/input')):
  if R1 != R2:
    print i, R1, R2
  i += 1
