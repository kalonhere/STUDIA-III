#include<iostream>
#include<string>
using namespace std;

void addfloat(float &a, float b){
a = a + b;
}

int main(){

    int menu;
    cin >> menu;
    switch(menu){
        case 1:{
            int indexmax;
            int max = 0;
            string text;
            cin >> text;
            int alphabet[123] = {0};

            for (int i = 0; i <= text.length() ; i++) {
                alphabet[int(text[i])]++;
            }
            for(int i = 65; i <= 122; i++){
                //cout << (char)i << ": "<< alphabet[i] << endl;
                if(alphabet[i] > max){
                    indexmax = i;
                    max = alphabet[i];
                }
                
            }
            cout << char(indexmax) << endl;
            break;
               }//case
        case 2:{
                float a,b;
                cout <<"a: "; cin >> a;
                cout << "b: "; cin >> b;
                
                addfloat(a,b);
                cout << a;
                break;
               }
        case 3:{
                   int size;
                   cout << "rozmiar: "; cin >> size;
                   int *arrptr = new int[size];
                   
                   for(int i = 0; i < size; i++){

                   }
                   delete[] arrptr;
               }
    }//switch

    
    return 0;
}//main
