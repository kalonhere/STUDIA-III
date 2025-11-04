#ifndef _KANTOR_H_
#define _KANTOR_H_


class Kantor{
    public:
    static float kurs;
    float marza;

    Kantor(float marza);

    float transfer(float kwota);
    void wypiszHistorie();

    ~Kantor();
};


#endif // _KANTOR_H_
