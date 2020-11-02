#include <iostream>

using namespace std;

int main(){
    int a;
    int *aPtr;

    a = 7;
    aPtr = &a;

    cout << "O endereço de a é " << &a << endl;
    cout << "O valor de aPtr é " << aPtr << endl;
    cout << "O valor de *aPtr é " << *aPtr << endl;
    cout << "Os operadores * e & são inversos um do outro " << &*aPtr << endl;

    return 0;
}