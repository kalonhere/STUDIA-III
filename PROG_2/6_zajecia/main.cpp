#include<iostream>
using namespace std;
class Koszyk{
    private:
        int wlasciciel_id;
    public:
        int banany;
        int jablka;


        Koszyk(){
            this->banany = 0;
            this->jablka = 0;
        }
        Koszyk(int banany, int jablka){
            this->banany = banany;
            this->jablka = jablka;
        }
        

        int suma(){
            return (this->banany+this->jablka);
        }
        Koszyk dodaj_koszyki(Koszyk &input_koszyk){
            int sumaJablek = jablka + input_koszyk.jablka;
            int sumabananow = banany + input_koszyk.banany;

            return Koszyk(sumaJablek,sumabananow);

            
        }
        Koszyk pomnoz_koszyk(int n){
            return Koszyk ((this->banany * n), (this->jablka * n));
        }
        
        //KOSZYK * int zawsze koszyk po lewej stronie;
        Koszyk operator*(int n){
            return Koszyk(banany*n, jablka*n);
        }

        //cos czego nie nalezy robic 

        Koszyk operator- (Koszyk &k){
            int noweJablka = abs(jablka - k.jablka);
            int noweBanany = abs(banany - k.banany);

            return Koszyk(noweBanany,noweJablka);
        }

       // bool operator>(Koszyk &k){
       //     if()
       // }
       //
       friend std::ostream& operator<<(std::ostream &str, Koszyk &k);

};//class
  //
//++k
Koszyk operator++(Koszyk &k){
    k.jablka++;
    k.banany++;
    return k;
}
//k++
Koszyk operator++(Koszyk &k, int){
    Koszyk wynik = k;
    k.jablka++;
    k.banany++;
    return k;
}


Koszyk operator*(int n, Koszyk &k){
    return Koszyk(k.banany*n, k.jablka*n);
}

Koszyk operator+ (Koszyk &k1,Koszyk &k2){
    return Koszyk (
            k1.banany + k2.banany,
            k1.jablka + k2.jablka
            );
}

std::ostream& operator<<(std::ostream &str, Koszyk &k){
    str << k.wlasciciel_id << ": " << k.banany << " " << k.jablka;
    return str;
}


int main(){
    Koszyk k1(10,20);
    Koszyk k2(4,7);


    Koszyk k3 = k1 + k2;
    
    cout << k3.banany << " " << k3.jablka << endl;


    k3 = k3 - k2;
    cout << k3.banany << " " << k3.jablka << endl;
    
    cout << k1 << endl;




}
