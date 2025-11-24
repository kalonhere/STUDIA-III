#include<iostream>
#include<cstdlib>
using namespace std;
struct zajecie{
    int start;
    int koniec;
};

int compare(const void *a, const void *b){
    zajecie *zajecie_a = (zajecie*)a;
    zajecie *zajecie_b = (zajecie*)b;

    if((zajecie_a->koniec) < (zajecie_b->koniec)){
        return -1;
    }else if((zajecie_a->koniec) > (zajecie_b->koniec)){
        return 1;
    }else{return 0;}
}


int main(){
    int n;
    //cout <<"n: ";
    cin >>n;

    zajecie *lista_zajec = new zajecie[n];

    for (int i = 0; i <n; i++){
        //cout <<"start koniec ";
        cin >> lista_zajec[i].start;
        cin >> lista_zajec[i].koniec;
    }
    
    //cout << "nieposortowana lista: ";
    //for(int i =0; i<n;i++){
    //    cout <<"["<<lista_zajec[i].start<<","<<lista_zajec[i].koniec<<") ";
    //}
    //    cout << "\n";
    qsort(lista_zajec,n,(sizeof(zajecie)),compare);
    
  // cout << "posortowana lista:";
  // for(int i =0; i<n;i++){
  //     cout <<"["<<lista_zajec[i].start<<","<<lista_zajec[i].koniec<<") ";
  // }
   //cout << "\n";


    int licznik_zajec = 0;
    zajecie ostatnie_zajecie;
    for(int i =0; i<n;i++){
        //cout <<"porownywany element: "<<lista_zajec[i].start << " " << lista_zajec[i].koniec << endl;
        //cout<<"Ostatnie zajecie:"<<ostatnie_zajecie.start<<" "<<ostatnie_zajecie.koniec<<endl;
        if(i==0){
          licznik_zajec++;
          ostatnie_zajecie = lista_zajec[i];
          //cout<<"Przypisano pierwszy element:"<<ostatnie_zajecie.start<<" "<<ostatnie_zajecie.koniec<<endl;
        }else if((lista_zajec[i].start) >= (ostatnie_zajecie.koniec)){
            
            licznik_zajec++;
            //cout << "Licznik zajec: "<<licznik_zajec;
            ostatnie_zajecie = lista_zajec[i];
            //cout<<"ostatni element: "<<ostatnie_zajecie.start<<" "<<ostatnie_zajecie.koniec<<endl;
        }else{continue;}
    }
    //cout << "licznik_zajec: "<<licznik_zajec;
    cout << licznik_zajec << endl;

    
    delete[] lista_zajec;

    return 0;
}
