#include<iostream>
#include<string>

using namespace std;


string betweenA(string &text){
    int inpoint = 0;
    int outpoint = 0;
    bool flag = false;
    for (int i = 0; i <text.length(); i++){
        if (text[i] == 'a' && flag == false){
            inpoint = i+1;
            flag = true;
        }
        if(text[i] == 'a' && flag == true){
            outpoint = i-1;
        }
    }//for
    
    if(outpoint == 0){
        return "";
    }
    return text.substr(inpoint,outpoint);



}//function



int main(){
    
    string text = "";
    string output = "";
    getline(cin,text);

    output = betweenA(text);
    cout << "Wyluskany napis: "<<output << endl;

    return 0;
}
