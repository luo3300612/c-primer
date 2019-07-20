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
  unsigned size() const{
    return width * height;
  }
  friend void read(istream &, Screen s);
  friend void Window_mgr::clear(unsigned);
};

void Window_mgr::clear(unsigned index) {
  Screen &s = ss[index];
  s.content = string(s.width * s.height, ' ');
}

Window_mgr::Window_mgr() { ss = {Screen(5, 5, 'X')}; }

int main(int argc, char const *argv[]) {
  Screen myScreen(5, 5, 'X');
  myScreen.display(cout);
  myScreen.move(4, 0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";
}