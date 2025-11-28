#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int ft[255];

int fibonacci(int n){
    if(n == 0){return 0;}
    if(n == 1){return 1;}
    if(ft[n]!=0) return ft[n];
    return ft[n] = (fibonacci(n-2) + fibonacci(n-1));
}

int main(){
    

    int n = 255;
    int ft[255] = {0};
    ft[1] = 1;
    for(int i =2; i<=n;i++){ft[i] = ft[i-1] + ft[i-2];}
    
    cout << "\033[6;31m"<<ft[n]<< "\033[m" << endl;
    auto start = high_resolution_clock::now();
    
    int wynik = fibonacci(n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop-start);
    cout << wynik << endl << "czas: "<< duration.count() << endl;

}
