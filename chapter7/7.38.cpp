#include <iostream>
#include <vector>
using namespace std;

class Screen;

class Window_mgr {
private:
  vector<Screen> ss;

public:
  Window_mgr();
  void clear(unsigned index);
};

class Screen {
private:
  string content = "";
  unsigned width = 10;
  unsigned height = 10;
  unsigned curse;

public:
  Screen() = default;
  Screen(const string &content, unsigned w, unsigned h)
      : content(content), width(w), height(h) {}
  Screen(const string &content, unsigned w, unsigned h, unsigned curse,
         unsigned y)
      : content(content), width(w), height(h), curse(curse) {}
  Screen(istream &is) { read(is, *this); }
  Screen(unsigned w, unsigned h, char c)
      : content(w * h, c), width(w), height(h) {}
  Screen move(unsigned r, unsigned c) {
    curse = r * width + c;
    return *this;
  }
  Screen set(char c) {
    content[curse] = c;
    return *this;
  }
  Screen display(ostream &os) {
    os << content << endl;
    return *this;
  }

  friend void read(istream &, Screen s);
  friend void Window_mgr::clear(unsigned);
};