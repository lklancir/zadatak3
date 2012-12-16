#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//#include "red_pokazivac.h"
#include "red_polje.h"

int n;
klijenti klijent[1000];
string ip[]={"Matija Matic","Ivo Ivic","Marko Markic","Ana Anic","Ivan Ivic","Djuro Djuric","Sara Saric","Mateo Mateic","Ivana Ivanovski","Josip Joso",
             "Stef Stefic","Tina Tinic","Tihana Tihic","Andreja Drejic","Darko Darkic","Emanuel Emanu","Franjo Franjic","Helena Helenic","Grga Grgic","Janko Jankci",
             "Jadro Jadran","Kuzma Kuzmic","Koraljka Koralj","Mato Matek","Vesna Vesnic","Pero Peric","Pavao Pavlic","Juraj Jurcevic","Matija Kovacek","Romano Kovac",
             "Valentina Bobetic","Ivan Djuras","Ana Erdelja","Antonija Pantelic","Boris Levajac","Luka Markovic","Ivan Cesar","Emanuel Djolo","Ivan Cvetko","Boris Sprem",
             "Stipe Mesar","Jozo Jozic","Jura Balic","Vlatka Blatka","Blakna Vodopija","Maja Majic","Nikola Misec","Roko Bianso","Steven Blank","Katica Hedelj",};

void generiraj(int n)
{
     srand(time(0));
     for (int i=0;i<n;i++)
     {
       klijent[i].ai=rand()%401+100;
       klijent[i].bi=rand()%401+100;
       klijent[i].ci=rand()%6 +1;
       klijent[i].di=rand()%4 +1;
     }   
}

void sort()
{
  for(int i=(n+n+n+n+(n/2)); i>0; i--)                                     
     {
       for(int j=0; j<i; j++)
         if(klijent[j].ci > klijent[i].ci)
        {
          klijenti pomKlijent = klijent[j];
          klijent[j] = klijent[i];
          klijent[i] = pomKlijent;
        
        }
     }
}
void zapis(int n)
{     
      RED Rpom;
      InitQ(Rpom);
      int godina=2012,mjesec=12,dan=14, razlikaG, razlikaM;
      for (int i=0; i<(n*5);i++)
      {
        int random=rand()%50;
        klijent[i].ime_prezime=ip[random];
        cout<<endl<<"Ime i prezime: "<<klijent[i].ime_prezime<<endl;
        
        int god=rand()% 81 +10;
        klijent[i].brgod=god;
        cout<<"Broj brgod: "<<klijent[i].brgod<<endl;
        
        klijent[i].godina=2012-klijent[i].brgod;
        int mjesec=rand()%12+1;
        klijent[i].mjesec=mjesec;
        int dan=rand()% 30+1;
        klijent[i].dan=dan;
        cout<<"Datum rodjenja: "<<klijent[i].dan<<"."<<klijent[i].mjesec<<"."<<klijent[i].godina<<endl;
        
        int broj=rand()%5000+1;
        cout<<"Stanje na tekucem racunu: ",klijent[i].tekuci=broj, cout<<klijent[i].tekuci<<" kn"<<endl;
        
        int broj2=rand()%4901+10;
        cout<<"Stanje na deviznom racunu: ",klijent[i].devizni=broj2, cout<<klijent[i].devizni<<" $"<<endl;
        
        cout<<"Klijent prioriteta: "; 
        if(klijent[i].di==2)
        {
          klijent[i].ci=rand()%5 +1;  
          if(klijent[i].ci==2)
            cout<<"2. invalid "<<endl;
          else if(klijent[i].ci==3)
            cout<<"3. trudnica "<<endl;
          else if(klijent[i].ci==4)
            cout<<"4. VIP klijent banke "<<endl;
          else  
            cout<<"5. ostali klijenti banke "<<endl;
       }
        else
        {
          klijent[i].ci=rand()%6 +1;
          if(klijent[i].ci==1)
            cout<<"1. Umirovljenik "<<endl;
          else if(klijent[i].ci==2)
            cout<<"2. invalid "<<endl;
          else if(klijent[i].ci==3)
            cout<<"3. trudnica "<<endl;
          else if(klijent[i].ci==4)
            cout<<"4. VIP klijent banke "<<endl;
          else if (klijent[i].ci==5)
            cout<<"5. ostali klijenti banke "<<endl;
          else
            cout<<"6. nisu klijenti banke "<<endl;
        }
         cout<<"Transakcija: ";
         klijent[i].di=rand()%4 +1;
         while (klijent[i].ci==6 && klijent[i].di==2)
           klijent[i].di=rand()%4 +1;
         if(klijent[i].di==1)
           cout<<"Uplata"<<endl;
         else if(klijent[i].di==2)
           cout<<"Isplata"<<endl;
         else if(klijent[i].di==3)
           cout<<"Placanje racuna"<<endl;
         else
           cout<<"Kredit"<<endl;
         EnQueueQ(klijent[i],Rpom);     
  }  
     
   
    sort(); 
    InitQ(R);
    for(int i=0;i<(n*5);i++) 
    { klijent[i].ime_prezime;
      klijent[i].brgod;
      klijent[i].dan,klijent[i].mjesec,klijent[i].godina;
      klijent[i].tekuci;
      klijent[i].devizni;
      klijent[i].ci;
      klijent[i].di;
      EnQueueQ(klijent[i],R);            
    }
    
    
     
      cout<<endl<<"Klijenti koji na racunu imaju više od 10.000,00 kuna u stranoj valuti ( $ )"<<endl;
      for(int i=0;i<(n*5);i++)
      {
         if(klijent[i].devizni*6>10000)
         {
             cout<<endl<<"Ime i prezime: "<<klijent[i].ime_prezime<<endl;
             cout<<"Iznos deviznog racuna ($): "<<klijent[i].devizni<<endl;
             cout<<"Iznos deviznog racuna (HRK): "<<(klijent[i].devizni*6)<<endl;
             cout<< "Prioritet: ";
             if(klijent[i].ci==1)
               cout<<"1. Umirovljenik "<<endl;
             else if(klijent[i].ci==2)
               cout<<"2. invalid "<<endl;
             else if(klijent[i].ci==3)
               cout<<"3. trudnica "<<endl;
             else if(klijent[i].ci==4)
               cout<<"4. VIP klijent banke "<<endl;
             else if (klijent[i].ci==5)
               cout<<"5. ostali klijenti banke "<<endl;
             else
               cout<<"6. nisu klijenti banke "<<endl;
             cout<< "Transakcija ";
             if(klijent[i].di==1)
               cout<<"1. Uplata"<<endl;
             else if(klijent[i].di==2)
               cout<<"2. Isplata"<<endl;
             else if(klijent[i].di==3)
               cout<<"3. Placanje racuna"<<endl;
             else
               cout<<"4. Kredit"<<endl; 
             cout<<"Datum rodjenja: "<<klijent[i].dan<<"."<<klijent[i].mjesec<<"."<<klijent[i].godina<<endl;
             cout<<"Broj brgod: "<<klijent[i].brgod<<endl;
         }  
      }  
}

void brzi()
{
  RED R2,R3;
  InitQ(R2);
  InitQ(R3);  
  
  
  while(!IsEmptyQ(R))
  {
    if(FrontQ(R).di == 3)
    {
      EnQueueQ(FrontQ(R), R2);

    }
    else
      EnQueueQ(FrontQ(R), R3);
    DeQueueQ(R);
  }
  
  InitQ(R); 
  cout << "+++++Stanje brzog reda+++++:" << endl;
  while(!IsEmptyQ(R2))
  {
    cout<<endl<<"Ime i prezime: " << FrontQ(R2).ime_prezime << endl;
    cout<< "Prioritet: ";
    if(FrontQ(R2).ci==1)
      cout<<"1. Umirovljenik "<<endl;
    else if(FrontQ(R2).ci==2)
      cout<<"2. invalid "<<endl;
    else if(FrontQ(R2).ci==3)
      cout<<"3. trudnica "<<endl;
    else if(FrontQ(R2).ci==4)
      cout<<"4. VIP klijent banke "<<endl;
    else if (FrontQ(R2).ci==5)
      cout<<"5. ostali klijenti banke "<<endl;
    else
      cout<<"6. nisu klijenti banke "<<endl;
    cout<< "Transakcija ";
    if(FrontQ(R2).di==3)
    cout<<"3. Placanje racuna"<<endl; 
    cout<<"Datum rodjenja: "<<FrontQ(R2).dan<<"."<<FrontQ(R2).mjesec<<"."<<FrontQ(R2).godina<<endl;
    cout<<"Broj brgod: "<<FrontQ(R2).brgod<<endl;
    cout<<"Stanje na tekucem racunu: "<<FrontQ(R2).tekuci<<" kn"<<endl;
    cout<<"Stanje na deviznom racunu: "<<FrontQ(R2).devizni<<" $"<<endl;
    
    
    EnQueueQ(FrontQ(R2), R);
    DeQueueQ(R2);
  }
 
   cout <<endl<<"+++++Stanje glavnog reda+++++:" << endl;
   while(!IsEmptyQ(R3))
  {
    cout<<endl<<"Ime i prezime: " << FrontQ(R3).ime_prezime << endl;
    cout<< "Prioritet: ";
    if(FrontQ(R3).ci==1)
      cout<<"1. Umirovljenik "<<endl;
    else if(FrontQ(R3).ci==2)
      cout<<"2. invalid "<<endl;
    else if(FrontQ(R3).ci==3)
      cout<<"3. trudnica "<<endl;
    else if(FrontQ(R3).ci==4)
      cout<<"4. VIP klijent banke "<<endl;
    else if (FrontQ(R3).ci==5)
      cout<<"5. ostali klijenti banke "<<endl;
    else
      cout<<"6. nisu klijenti banke "<<endl;
    cout<< "Transakcija ";
    if(FrontQ(R3).di==1)
      cout<<"1. Uplata"<<endl;
    else if(FrontQ(R3).di==2)
      cout<<"2. Isplata"<<endl;
    else if(FrontQ(R3).di==3)
      cout<<"3. Placanje racuna"<<endl;
    else
      cout<<"4. Kredit"<<endl; 
    cout<<"Datum rodjenja: "<<FrontQ(R3).dan<<"."<<FrontQ(R3).mjesec<<"."<<FrontQ(R3).godina<<endl;
    cout<<"Broj brgod: "<<FrontQ(R3).brgod<<endl;
    cout<<"Stanje na tekucem racunu: "<<FrontQ(R3).tekuci<<" kn"<<endl;
    cout<<"Stanje na deviznom racunu: "<<FrontQ(R3).devizni<<" $"<<endl;
    EnQueueQ(FrontQ(R3), R);
    DeQueueQ(R3);
  }
}

void VIP_umirovljenici(){
  RED R4,R5;
  InitQ(R4);
  InitQ (R5);
  
  
  while(!IsEmptyQ(R))
  {
    EnQueueQ(FrontQ(R), R4);
    DeQueueQ(R);
  }
  
    
   while(!IsEmptyQ(R4)){
      
      if((FrontQ(R4).ci==4 &&  FrontQ(R4).di==1 && FrontQ(R4).brgod<30)||(FrontQ(R4).ci==4 && FrontQ(R4).di==2 && FrontQ(R4).tekuci>5000 ))
      DeQueueQ(R4);
      else
      EnQueueQ(FrontQ(R4),R5);
      DeQueueQ(R4);
   }
   InitQ(R);
   cout<<endl<<"----Stanje u redu nakon brisanja VIP klijenata i umirovljenika----"<<endl;
   while(!IsEmptyQ(R5)){
                        
     cout<<endl<<"Ime i prezime: " << FrontQ(R5).ime_prezime << endl;
    cout<< "Prioritet: ";
    if(FrontQ(R5).ci==1)
      cout<<"1. Umirovljenik "<<endl;
    else if(FrontQ(R5).ci==2)
      cout<<"2. invalid "<<endl;
    else if(FrontQ(R5).ci==3)
      cout<<"3. trudnica "<<endl;
    else if(FrontQ(R5).ci==4)
      cout<<"4. VIP klijent banke "<<endl;
    else if (FrontQ(R5).ci==5)
      cout<<"5. ostali klijenti banke "<<endl;
    else
      cout<<"6. nisu klijenti banke "<<endl;
    cout<< "Transakcija ";
    if(FrontQ(R5).di==1)
      cout<<"1. Uplata"<<endl;
    else if(FrontQ(R5).di==2)
      cout<<"2. Isplata"<<endl;
    else if(FrontQ(R5).di==3)
      cout<<"3. Placanje racuna"<<endl;
    else
    cout<<"4. Kredit"<<endl; 
    cout<<"Datum rodjenja: "<<FrontQ(R5).dan<<"."<<FrontQ(R5).mjesec<<"."<<FrontQ(R5).godina<<endl;
    cout<<"Godina: "<<FrontQ(R5).brgod<<endl;
    cout<<"Stanje na tekucem racunu: "<<FrontQ(R5).tekuci<<" kn"<<endl;
    cout<<"Stanje na deviznom racunu: "<<FrontQ(R5).devizni<<" $"<<endl;                    
                        
    EnQueueQ(FrontQ(R5), R);
    DeQueueQ(R5);                    
   }
     
}

int main(){
    int izbor;
    do{
    cout<<endl<<"°°°°°°°°°°° SIMULACIJA REDA U BANCI °°°°°°°°°°°°"<<endl<<endl;
    cout<<"1. Generirajte red  "<<endl;
    cout<<"2. Brze transakcije "<<endl;
    cout<<"3. Izbaci VIP klijente i umirovljenike"<<endl<<endl; 
    cout<<"9. Izlaz iz programa"<<endl;
    cin>>izbor;
    
    switch(izbor){
                case 1: 
                        cout<<"Generiranje koliko N cetvorki?: ";
                        cin>>n;
                        generiraj (n);
                        zapis(n);
                        break;
                case 2:
                        brzi();
                        break;
                case 3:
                        VIP_umirovljenici();
                        break;
                default: cout<<"Unijeli ste krivi broj!"<<endl;
                         break;
                                  
    }
    
    }while(izbor!=9);
    
    return 0;
}
