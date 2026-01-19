#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

typedef enum KOLOR{
  BIALY,
  SZARY,
  CZARNY
}KOLOR;


int s = 0;

void dfsVisit(vector<vector<int>> &t, int wierzcholki, int k, int l){
    //cout<<"Visiting: "<<k+1<<" from "<<l+1<<endl;
    for(int i{}; i<wierzcholki; i++){
        if(t[k][i] == BIALY){
            t[k][i] = SZARY;
            t[i][k] = SZARY;
            dfsVisit(t, wierzcholki, i, k);
            t[k][i] = CZARNY;
            t[i][k] = CZARNY;
        }
    }
}

int main(){
    int wierzcholki, c;
    cin>>wierzcholki;
    string st;
    getline(cin, st);
    vector<int> tmp;
    vector<vector<int>> t;
    for(int i{}; i<wierzcholki; i++){
        tmp.push_back(0);
    }
    for(int i{}; i<wierzcholki; i++){
        t.push_back(tmp);
    }

    for(int i{}; i<wierzcholki; i++){
        getline(cin, st);
        stringstream ss(st);

        while((ss>>c) && (c > 0)){
            t[i][c-1] = BIALY;
            t[c-1][i] = BIALY;
        }
    }
    for(int i{}; i<wierzcholki; i++){
        for(int j{}; j<wierzcholki; j++){
            if(t[i][j] == BIALY){
                dfsVisit(t, wierzcholki, i, j);
                s++;
            }
        }
    }

    for(int i{}; i<wierzcholki; i++){
        int q = 0;
        for(int j{}; j<wierzcholki; j++){
            if(t[i][j] > 0){
                q = 1;
                break;
            }
        }
        if(!q) s++;
    }

    cout<<s<<endl;

    return 0;
}
