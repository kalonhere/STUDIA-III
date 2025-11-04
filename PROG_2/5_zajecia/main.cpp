#include<iostream>
#include"Kantor.h"

using namespace std;


int main(){
    Kantor k(1.05);
    cout << k.transfer(100) << endl;

    
    Kantor k2(1.05);
    k2.kurs = 2;
    cout << k.transfer(100) << endl;

    return 0;
}
