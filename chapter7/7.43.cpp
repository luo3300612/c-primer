class NoDefault{
  private:
  int A;
  public:
  NoDefault(int a):A(a){}
};


class C{
  NoDefault d;
  C():d(1){}
};

int main(int argc, char **argv){
  return 0;
}