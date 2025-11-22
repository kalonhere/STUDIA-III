#include <iostream>
#include <vector>
using namespace std;

int *pom;

void wypisz(const char* msg, int tab[], int lewy, int prawy) {
    cout << msg << " [";
    for(int i = lewy; i <= prawy; i++)
        cout << tab[i] << (i < prawy ? " " : "");
    cout << "] (od " << lewy << " do " << prawy << ")\n";
}

// SCALANIE
void scal(int tab[], int lewy, int srodek, int prawy) 
{
    cout << "\n--- SCALANIE ---\n";
    wypisz("Przed scalaniem: ", tab, lewy, prawy);

    int i = lewy, j = srodek + 1;

    // kopiowanie
    for(int k = lewy; k <= prawy; k++)
        pom[k] = tab[k];

    cout << "Lewa część: ";
    wypisz("", pom, lewy, srodek);

    cout << "Prawa część: ";
    wypisz("", pom, srodek+1, prawy);

    // scalanie
    for(int k = lewy; k <= prawy; k++) {
        if(i <= srodek) {
            if(j <= prawy) {
                if(pom[j] < pom[i])
                    tab[k] = pom[j++];
                else
                    tab[k] = pom[i++];
            } 
            else {
                tab[k] = pom[i++];
            }
        } 
        else {
            tab[k] = pom[j++];
        }
    }

    wypisz("Po scalaniu:   ", tab, lewy, prawy);
    cout << "--- KONIEC SCALANIA ---\n\n";
}

// REKURENCJA (DZIELENIE)
void sortowanie_przez_scalanie(int tab[], int lewy, int prawy)
{
    cout << "Wejście sortowania: lewy=" << lewy 
         << " prawy=" << prawy << "\n";

    if(prawy <= lewy) {
        cout << "  Zakres 1-elementowy → koniec\n";
        return;
    }

    int srodek = (prawy + lewy) / 2;

    cout << "  Dzielę na: (" 
         << lewy << "," << srodek 
         << ") oraz (" << srodek+1 << "," << prawy << ")\n";

    sortowanie_przez_scalanie(tab, lewy, srodek);
    sortowanie_przez_scalanie(tab, srodek + 1, prawy);

    scal(tab, lewy, srodek, prawy);
}

int main()
{
    int n;
    cin >> n;

    int *tab = new int[n];
    pom = new int[n];

    for(int i = 0; i < n; i++)
        cin >> tab[i];

    cout << "\n==== START MERGE SORT ====\n\n";

    sortowanie_przez_scalanie(tab, 0, n - 1);

    cout << "\n==== WYNIK KOŃCOWY ====\n";
    for(int i = 0; i < n; i++)
        cout << tab[i] << " ";

    cout << "\n";

    return 0;
}
