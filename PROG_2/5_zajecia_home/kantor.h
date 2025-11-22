#ifndef _KANTOR_
#define _KANTOR_

typedef enum {
  USD = 1,
  PLN = 2
} CURRENCY;


class kantor{
private:
  float *history_pointer;
  int history_index;
  int history_size;

public:
  float kurs_kwota_USD;
  float kurs_kwota_PLN;
  float marza;

  kantor(float marza, int arr_size);

  void przeliczKwote(float kwota, CURRENCY input, CURRENCY output);

  ~kantor();

  void addHistory(float marza);

  void printHistory();

  };





#endif
