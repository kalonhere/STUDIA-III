#ifndef _CART_
#define _CART_
#include<iostream>
#include<vector>
using namespace std;

#include"Product.h"


struct Entry{
    int quantity;
    Product product;
};


class Cart {
    public:
        vector<Entry> product_list;
        
        Cart();
        void addItem();
        void deleteItem();
        void changeQuantity(int quantity);

        float printPrice();
        




};

#endif
