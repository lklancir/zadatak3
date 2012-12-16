#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct klijenti{
   string ime_prezime;
   int dan, mjesec,godina,brgod;
   float tekuci,devizni;  
   int ai,bi,ci,di;   
};

struct red
{
  klijenti klijent;
  struct red *sljedeci;
};

struct pok
{
  struct red *pocetak, *kraj;
};

typedef struct pok RED;
typedef struct red *element;

RED R;

klijenti FrontQ(RED R)
{
  return ((R.pocetak)->sljedeci)->klijent;
}

void EnQueueQ(klijenti x, RED &R)
{
  element novi = new red;
  novi->sljedeci = NULL;
  novi->klijent = x;
  (R.kraj)->sljedeci = novi;
  R.kraj = novi;
}

void DeQueueQ(RED &R)
{
  element brisi = R.pocetak;
  R.pocetak = (R.pocetak)->sljedeci;
  delete brisi;
}

void InitQ(RED &R)
{
 element novi = new red;
 novi->sljedeci = NULL;
 R.pocetak = novi;
 R.kraj = novi;
}

bool IsEmptyQ(RED R)
{
  if((int)R.pocetak == (int)R.kraj)
    return true;
  else
    return false;
}
