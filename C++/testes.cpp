#include <iostream>
using namespace std;

struct Data{
  unsigned short data;
  void define(short d, short m, short a);
  void exibe(void);
};

void define(short d,short m,short a){

}

int main(){
  Data hoje;
  hoje.define(24,06,2020);
  hoje.exibe();
}
