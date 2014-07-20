#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
char buf[4];
int off = 4;;
ifstream ifs;

void read4(char *buf) {
  for (int i = 0; i < 4; ++i) {
    *buf = ifs.get();
    ++buf;
  }
  off = 0;
}

void read(char *output, size_t size) {
  if (off < sizeof(buf)) {
    int todo = min(sizeof(buf) - off, size);
    memcpy(output, buf + off, todo);
    output += todo;
    size -= todo;
    off += todo;
  }
  while (size > 0) {
    read4(buf);
    int todo = min(sizeof(buf) - off, size);
    memcpy(output, buf + off, todo);
    output += todo;
    size -= todo;
    off += todo;
  }
}

int main(int argc, char **argv) {
  char output[4096];
  ifs.open(argv[1]);
  read(output, 2);
  for (int i = 0; i < 2; ++i)
    cout << output[i] << endl;
  read(output, 5);
  for (int i = 0; i < 5; ++i)
    cout << output[i] << endl;
  ifs.close();
}
