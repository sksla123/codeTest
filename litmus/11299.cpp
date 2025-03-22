#include <iostream>
using namespace std;


class BaseNum
{
protected:
  int* bnum;
public:
  BaseNum(int n) {
    bnum = new int[n];
  }
  virtual void print()
  {
    cout << bnum << endl;
  }
  virtual ~BaseNum()
  {
    delete[] bnum;
  }
};

class DerivedNum : public BaseNum
{
protected:
  int* dnum;
public:
  DerivedNum(int n1, int n2) : BaseNum(n2){
    dnum = new int[n1];
  }
  void print()
  {
    cout << dnum << endl;
  }
  ~DerivedNum()
  {
    delete[] dnum;
  }
};

int main()
{
  BaseNum* b = new BaseNum{ 10 };
  BaseNum* d = new DerivedNum{ 5 , -7 };

  b->print();
  d->print();

  delete b;
  delete d;

  return 0;
}