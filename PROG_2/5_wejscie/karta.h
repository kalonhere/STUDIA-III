#ifndef _KARTA_
#define _KARTA_

class karta {
    private:
        int numer_karty;
        int termin_karty;
        static int nastepny_numer_karty;
    public:
        karta(int termin_karty);
        int wypisz_date();
        static void zwieksz_numer_karty();
};




#endif
