#include<iostream>
using namespace std;
enum OPERATION{
    NEGATION,
    MOVE,
    SET_ONE,
    PRINT
};

void numberOperation(int &num, int n, OPERATION modifier){
    if(modifier == NEGATION){
        int buffer = num;
        buffer = (~buffer);
        num = buffer;
    }
    if(modifier == MOVE){
        int buffer = num;
        buffer = (buffer << n);
        num = buffer;
    }
    if(modifier == SET_ONE){
        int buffer = num;
        buffer = (buffer | (1 << n));
        num = buffer;
    }
    if(modifier == PRINT){
        
    }
}

int main(){
    int num = 61;
    int n = 3;


    numberOperation(num,n,NEGATION);
    cout << "NEGATION: " << num << endl;
    
    numberOperation(num,n,MOVE);
    cout << "MOVE: " << num << endl;
    
    numberOperation(num,n,SET_ONE);
    cout << "SET_ONE: " << num << endl;
    
    numberOperation(num,n,PRINT);
    cout << "PRINT" << num << endl;



    return 0;
}
