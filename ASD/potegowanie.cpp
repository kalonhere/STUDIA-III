#include<iostream>

int rek_potengowanie(int n, double x){
    if (n == 0) return 1;
    return x * rek_potengowanie(n-1,x);
};



int main(){
    int n = 3;
    double x = 7;
    int faking_wynik_ya = 0;

    faking_wynik_ya = rek_potengowanie(n,x);
    std::cout << faking_wynik_ya << std::endl;

    return 0;
}
