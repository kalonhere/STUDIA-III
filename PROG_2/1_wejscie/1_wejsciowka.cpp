#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Podaj liczbe n: ";
    cin >> n;
    
    for (int i = -n; i<=n; i++){
        if (i%4 != 0){
            cout << i << endl;
        }
    }


    return 0;

}
