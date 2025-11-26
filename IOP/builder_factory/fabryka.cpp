#include <iostream>

using namespace std;

class Wielokat {
  public:
    Wielokat() {
      id_ = total_++;
    }
    virtual void rysujWielokat() = 0;
  protected:
    int id_;
    static int total_;
};

class Owalny {
    public:
    Owalny() {
      id_ = total_++;
    }
    virtual void rysujOwalny() = 0;
  protected:
    int id_;
    static int total_;
};
int Wielokat::total_ = 0;
int Owalny::total_ = 0;

class Circle : public Owalny {
  public:
    void rysujOwalny() {
      cout << "circle " << id_ << ": draw" << endl;
    }
};
class Square : public Wielokat {
  public:
    void rysujWielokat() {
      cout << "square " << id_ << ": draw" << endl;
    }
};
class Ellipse : public Owalny {
  public:
    void rysujOwalny() {
      cout << "ellipse " << id_ << ": draw" << endl;
    }
};
class Rectangle : public Wielokat {
  public:
    void rysujWielokat() {
      cout << "rectangle " << id_ << ": draw" << endl;
    }
};

class Factory {
  public:
    virtual Owalny* createCurvedInstance() = 0;
    virtual Wielokat* createStraightInstance() = 0;
};

class SimpleShapeFactory : public Factory {
  public:
    Owalny* createCurvedInstance() {
      return new Circle;
    }
    Wielokat* createStraightInstance() {
      return new Square;
    }
};
class RobustShapeFactory : public Factory {
  public:
    Owalny* createCurvedInstance()   {
      return new Ellipse;
    }
    Wielokat* createStraightInstance() {
      return new Rectangle;
    }
};

int main() {

  Factory* factory;
  int w;
  cout << "Czy podluzne czy nie?" << endl;
  cout << "1. Podluzny " << endl;
  cout << "2. Nie podluzny " << endl;
  cin >> w;
  if(w == 1) {
    factory = new RobustShapeFactory;
  } else {
    factory = new SimpleShapeFactory;
  }


  Owalny *owalny = factory->createCurvedInstance();
  Wielokat *wielokat = factory->createStraightInstance();

  owalny->rysujOwalny();
  wielokat->rysujWielokat();

}
