#include<iostream>
#include<string>
using namespace std;

int main(){
  string buffer;
  cout << "Podaj tekst:";
  getline(cin,buffer);
  
  for(int i = 0; i < buffer.length(); i++){
    if(buffer[i] == 'a'){cout << "usunieto litere: " << buffer[i] << endl;buffer.erase(i,1);}
    if(buffer[i] == 'e'){cout << "usunieto litere: " << buffer[i] << endl;buffer.erase(i,1);}
    if(buffer[i] == 'i'){cout << "usunieto litere: " << buffer[i] << endl;buffer.erase(i,1);}
    if(buffer[i] == 'o'){cout << "usunieto litere: " << buffer[i] << endl;buffer.erase(i,1);}
    if(buffer[i] == 'u'){cout << "usunieto litere: " << buffer[i] << endl;buffer.erase(i,1);}
  }
  // cout << (int)'a'<< endl;
  // cout << (int)'e'<< endl;
  // cout << (int)'i'<< endl;
  // cout << (int)'o'<< endl;
  // cout << (int)'u'<< endl;
  //
  cout << buffer << endl;


   //string buffer;
   //cout << "Podaj tekst:";
   //cin >> buffer;
   //cout << "string length: "<< buffer.length() << endl;
   //buffer.erase(2,1);
   //cout << "erased 2,1" << endl;
   //cout << buffer << endl;

  return 0;
}
