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

typedef int element;

struct red
{
  klijenti klijent[1000];
  element  pocetak, kraj;
};

typedef struct red RED;

int AddOne(int n)
{
  return((n+1)%1000);
}

RED R;

klijenti FrontQ(RED &R)
{
  return R.klijent[R. pocetak];
}

void EnQueueQ(klijenti x, RED &R)
{
  R.kraj = AddOne(R.kraj);
  R.klijent[R.kraj] = x;
}

void DeQueueQ(RED &R)
{
  R. pocetak = AddOne(R. pocetak);
}

void InitQ(RED &R)
{
 R.pocetak = 0;
 R.kraj = 999;
}

bool IsEmptyQ(RED &R)
{
  if(AddOne(R.kraj) == R. pocetak)
    return true;
  else
    return false;
}
