#include "Cart.h"
#include <string>

Cart::Cart(){
    product_list.clear();
}

void Cart::addItem(){
    int new_entry_id;
    int new_quantity;
    float new_price;
    string new_name;
    struct Entry new_entry;
    //print list of items
    //select product
    printf("Test version\n");
    cout << "Wybierz numer produktu: ";
    cin >> new_entry_id;
    cout << "Podaj ilosc produktu: ";
    cin >> new_quantity;
    cout << "Podaj cene produktu: ";
    cin >> new_price;
    cout << "Podaj nazwe produktu: ";
    cin >> new_name;

    new_entry.quantity = new_quantity;
    new_entry.product.unique_id = new_entry_id;
    new_entry.product.price = new_price;
    new_entry.product.name = new_name;

    product_list.push_back(new_entry);

}

void Cart::deleteItem(){
    int entry_id;
    cout << "Podaj numer produktu do usuniecia: ";
    cin >> entry_id;

    for(int i = 0; i < product_list.size(); i++){
        if(product_list.at(i).product.unique_id == entry_id){
            cout << "znaleziono element. usuwanie\n";
            product_list.erase(product_list.begin() + i);
            break;
            }
    }
    cout << "nie zaleziono elementu\n";
}

void Cart::changeQuantity(int new_quantity){
    int entry_id;
    cout << "Podaj numer produktu do zmiany: ";
    cin >> entry_id;
    
    for(int i = 0; i < product_list.size(); i++){
        if(product_list.at(i).product.unique_id == entry_id){
            cout << "znaleziono element. Podaj nowa ilosc: ";
            cin >> product_list.at(i).quantity;
            break;
        }
    }
    cout << "nie znaleziono elementu\n";
    
}

float Cart::printPrice(){
    struct Entry current_entry;
    float cart_price = 0;
    float suma = 0;
    for(int i = 0; i < product_list.size(); i++){
        cout << "========\n";
        suma = (current_entry.product.price * current_entry.quantity);
        current_entry = product_list.at(i);
        cout << "Produkt:\t"<<current_entry.product.name << endl;
        cout << "Ilosc:\t"<<current_entry.quantity << endl;
        cout << "Cena ilosciowa:\t"<<current_entry.product.price << endl;
        cout << "Typ produktu:\t"<<current_entry.product.unique_id << endl;
        cout << "Cena sumaryczna produktu:\t"<< suma << endl;

        cart_price = cart_price + suma;

    }
    cout << "========\n";
    cout << "Laczna wartosc koszyka:\t"<<cart_price << endl;
    return cart_price;
}
