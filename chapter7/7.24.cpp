#include <iostream>

using namespace std;

class Screen {
private:
  string content = "";
  unsigned weight = 1920;
  unsigned height = 1080;
  unsigned x = 0;
  unsigned y = 0;

public:
  Screen() = default;
  Screen(const string &content, unsigned w, unsigned h)
      : content(content), weight(w), height(h) {}
  Screen(const string &content, unsigned w, unsigned h, unsigned x, unsigned y)
      : content(content), weight(w), height(h), x(x), y(y) {}
  Screen(istream &is) { read(is, *this); }
  Screen(char c, unsigned w, unsigned h) : content(c,1), weight(w), height(h) {}
  friend void read(istream &, Screen s);
};

int main(int argc, char const *argv[]){
  Screen s('a',10,20);
}