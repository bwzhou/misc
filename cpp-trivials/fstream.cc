#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char **argv) {
  std::fstream ofs(argv[1], std::ios::out);
  if (ofs.is_open())
  {
    ofs << "lorem ipsum";
    std::cout << "Operation successfully performed\n";
  }
  else
  {
    std::cout << "Error opening file";
  }
  std::cout << ofs.tellp() << std::endl; // tell put position
  ofs.seekp(0, std::ios::beg);
  ofs << "hello, world" << std::endl;
  ofs << "hello, again" << std::endl;
  ofs.close();

  std::string buf;
  std::fstream ifs(argv[1], std::ios::in);
  if (ifs.is_open()) {
    while (std::getline(ifs, buf)) {
      std::cout << buf << std::endl;
    }
  }
  ifs.close();
  return 0;
}
