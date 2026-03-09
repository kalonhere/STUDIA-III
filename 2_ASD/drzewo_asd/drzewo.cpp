//algorytm napisany na potrzeby projektu Algorytmy i Struktury Danych  
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

struct wezel {
  char znak;
  wezel* lewo;
  wezel* prawo;

  wezel(char v) {
      znak = v;
      lewo = nullptr;
      prawo = nullptr;
  }
};

bool isOperator(const char& s) {
    if (s == '+' || s == '-' || s == '*' || s == '/'){
    return true;
  }
  return false;
}

// budowa drzewa z postfixa
wezel* buildTree(const vector<char>& postfix) {
  stack<wezel*> st;

  for (const char& znaczek : postfix) {
    if (!isOperator(znaczek)) {
      st.push(new wezel(znaczek));
    } else {
      wezel* prawo = st.top(); st.pop();
      wezel* lewo = st.top(); st.pop();

      wezel* nowy = new wezel(znaczek);
      nowy->lewo = lewo;
      nowy->prawo = prawo;

      st.push(nowy);
    }
  }

  return st.top();
}

// WYPISANIE POSTORDER (czyli postfix)
void printPostorder(wezel* korzen) {
  if (!korzen) return;
  printPostorder(korzen->lewo);
  printPostorder(korzen->prawo);
  cout << korzen->znak << " ";
}

// pomocniczo: rysunek drzewa
void rysuj(wezel* korzen, int depth = 0) {
  if (!korzen) return;

  rysuj(korzen->prawo, depth + 1);

  for (int i = 0; i < depth; i++)
      cout << "   ";
  cout << korzen->znak << endl;

  rysuj(korzen->lewo, depth + 1);
}

int main() {
  int ilosc = 0;
  string bufor;
  getline(cin,bufor);
  vector<char> vektorek;
  for (int i = 0; i < bufor.length(); i++ ){
    if(bufor[i] != ' '){
      ilosc++;
      vektorek.push_back(bufor[i]);
    }
  }
  wezel* korzen = buildTree(vektorek);
  cout << "\nDrzefko:\n";
  rysuj(korzen);

  return 0;
}

