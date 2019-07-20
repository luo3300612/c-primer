#include <iostream>

using namespace std;

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
};

int main(int argc, char const *argv[]) {
  Screen myScreen(5, 5, 'X');
  myScreen.display(cout);
  myScreen.move(4, 0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";
}