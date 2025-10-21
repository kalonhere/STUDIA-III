#include<iostream>
int main(){
    
    int menu;
    std::cin >> menu;

    switch(menu){

        case 1:
            std::cout << "Filip" << std::endl;
            std::cout << "Kalinowski" << std::endl;
            break;

        case 2:
            
            int x;
            std::cout << "Podaj numer indeksu:";
            std::cin >> x;
            std::cout << x << std::endl;

            break;

        case 3:
            char first;
            char second;
            char third;

            std::cout <<"Podaj 1, 2, 3 znak" << std::endl;
            std::cin >> first;
            std::cin >> second; 
            std::cin >> third;

            std::cout << third << "-";
            std::cout << second << "-";
            std::cout << first << "-";
            break;
        case 4:
            int a,b;
            a = 11;
            b = 4;

            std::cout << "a+b = " << (a+b) << std::endl;
            std::cout << "a-b = " << (a-b) << std::endl;
            std::cout << "a*b = " << (a*b) << std::endl;
            std::cout << "a/b = " << (a/b) << std::endl;
            std::cout << "a\%b = " << (a%b) << std::endl; 
            break;
        case 5:
            //wiem
            break;
        case 6:
            int x6;
            std::cout<< "Podaj dowolna liczbe calkowitoliczbowa: ";
            std::cin >> x6;

            if(x6>200){
                std::cout << "Jestem wieksza niz 200!";
            } else {
                std::cout << "Jestem mniejsza niz 200";
            }
            break;
        case 7:
            int c;
            c = 86;
            if(c%2 == 0){
                std::cout << "Liczba c jest parzysta i wynosi: " << c;
            }else {
                std::cout << "Liczba c jest nieparzysta i wynosi: " << c;
            }
            break;

        case 8: 
           int liczba;
           std::cin >> liczba;
            if((liczba >= -20) && (liczba <= 30)){
                std::cout << "malo";
            }
            else if((liczba >= 50)&&(liczba <=75)){
                std::cout << "duzo";
            }
            else { std::cout << "error"; }
            break;
        case 9:
            for(int i = 1; i<=20; i++){
                std::cout << i << ". == "<< (i*i) << std::endl;
            }
            break;
        case 10:
            {int wynik = 0;
            //wynik = 0;
            for (int i = 1; i<=10; i++){
                wynik = wynik + i;
            }
            std::cout << "Wynik wynosi: " << wynik;
            }
            break;
        case 11:
            int x11;
            std::cin >> x11;

            for(int i = 0; i<=x11; i++){
                if(i%3 == 0){
                    std::cout << i;
                }
                if(i%5 == 0){
                    std::cout << i;
                }
            }
            break;
        case 12:
            int n;
            int x12;
            x12 = 0;
            std::cin >> n;
            while(x12 != n){
                std::cout << x12;
                x12++;
            }
            break;
        case 13:
            char znak;
            znak = 0;
            while(std::cin >> znak){
                if(znak != 'Q'){
                    std::cout << (int)znak << std::endl;
                }
                if(znak == 'Q'){
                    break;
                }
            
            }
            break;
        case 14:
            int x14;
            int y14;
            char znak14;
            std::cin >> x14 ;
            std::cin >> y14 ;
            std::cin >> znak14;

            switch(znak14){
                case '+' :
                    std::cout << (x14+y14) << std::endl;
                    break;
                case '-' :
                    std::cout << (x14-y14) << std::endl;
                    break;
                case '*':
                    std::cout << (x14*y14) << std::endl;
                    break;
                case '/':
                    std::cout << (x14/y14) << std::endl;
                    break;
            }


            break;
    }//<<-- switch




    return 0;
}
