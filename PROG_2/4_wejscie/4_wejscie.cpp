#include<iostream>
#include<string>

using namespace std;
class Telefon{
    private:
        int favourite_contacts[10];

    public:
        int number;

    Telefon(int new_number){
        number = new_number;
    }

    void setFavNumber(int i, int new_number){
        if(i >= 0 && i<10){
            favourite_contacts[i] = new_number;
        }//if

    }//set number

    bool isFavourite(Telefon tel_check){
        for(int i = 0; i<10; i++){
            if(favourite_contacts[i] == tel_check.number){
                return true;
            }
        }
        return false;
    }

};

int main(){
    Telefon tel1 = Telefon(10);
    Telefon tel2 = Telefon(20);
    Telefon tel3 = Telefon(30);

    tel1.setFavNumber(1,20);

    cout << tel1.isFavourite(tel2) << endl;
    cout << tel1.isFavourite(tel3) << endl;


    return 0;
}
