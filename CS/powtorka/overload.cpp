#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>


class Basket{
  private:
    int id;

  public:
    int apples;
    int bananas;
    
    
    Basket(){
      this-> apples = 0;
      this-> bananas = 0;
      this->id = (rand() % 100 + 1);
    }

    Basket(int apples, int bananas){
      this->apples = apples;
      this->bananas = bananas;
      this->id = (rand() % 100 + 1);
    }
    int printQuantity(){
      return this->apples + this->bananas;
    }
    Basket createSumBasket(Basket source){
      return Basket(source.apples, source.bananas); 
    }
    Basket createMultiplicatedBasket(int n){
      return Basket((this->apples * n), (this->bananas * n));
    }
};


int main(){
  srand(time(NULL));



  return 0;
}
