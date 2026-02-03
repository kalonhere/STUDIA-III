#include<iostream>
#include<string>
using namespace std;
#include "Shop.h"
#include "Product.h"
#include "Cart.h"

int main(){
    Cart my_cart;
    my_cart.addItem();
    my_cart.addItem();
    my_cart.printPrice();
    



    return 0;
}
