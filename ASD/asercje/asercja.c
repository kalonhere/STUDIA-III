#include<stdio.h>
#include<assert.h>

void silnia(int n){
    assert (n >=0);
    int wynik = 1;
    for(int i = 1; i <= n;i++){
        wynik = wynik * i;
    }
    printf("silnia z %d jest rowna %d\n",n,wynik);
}

int main(){
    int suma = 0;
    int t[] = {5,5,2,3};
    for(int i = 0;i<3;i++){
        suma +=t[i];
    }
    assert (suma >= 10);
    printf("suma: %d\n",suma);
    silnia(suma);
    
    return 0;
}
