#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class Przedzial{
public:
    int poczatek = 0;
    int koniec = 0;
    int faktycznyPoczatek = 0;
    int faktycznyKoniec = 0;
    int wiersz = 0;
    int nieparzyste = 0;
    int pierwsze = 0;
    char znaklewy, znakprawy;

    policzNieparzyste(){

          for(int i=poczatek;i<=koniec;i++){
            if(i%2!=0){
                nieparzyste+=1;
            }
        }
    }

    policzPierwsze(){
        for(int i=poczatek;i<=koniec;i++){
            if(i%2!=0&&i%3!=0&&i%5!=0&&i%7!=0&&i>0){
                pierwsze+=1;
            }
        }

    }



};

int main()
{
    fstream plik;
    plik.open("przedzialy.txt",ios::in);

    int liczba1,liczba2, licz = 0;
    char znak1, znak2, znak3;
    Przedzial przedzialy[50];
    int wartosciNiep[50] = {0};
    int wartosciPier[50] ={0};
    int calyprzedzial[201] = {0}; //201 bo maks zakres to <-100,100>, czyli z zerem 201 miejsc

    while(!plik.eof()){

        plik>>znak1;
        if(plik.eof()){
            break;
        }
        plik>>liczba1;
        plik>>znak2;
        plik>>liczba2;
        plik>>znak3;

        przedzialy[licz].faktycznyPoczatek=liczba1;
        przedzialy[licz].faktycznyKoniec=liczba2;
        przedzialy[licz].znaklewy = znak1;
        przedzialy[licz].znakprawy= znak3;

        if(znak1=='('){
                liczba1+=1;
            }

        if(znak3==')'){
                liczba2-=1;

        }


        przedzialy[licz].poczatek=liczba1;
        przedzialy[licz].koniec=liczba2;
        przedzialy[licz].wiersz=licz+1;
        przedzialy[licz].policzNieparzyste();
        przedzialy[licz].policzPierwsze();
        wartosciPier[licz] = przedzialy[licz].pierwsze;
        wartosciNiep[licz] = przedzialy[licz].nieparzyste;


        for(int i=przedzialy[licz].faktycznyPoczatek;i<=przedzialy[licz].faktycznyKoniec;i++){
            calyprzedzial[i+100]=1;
        }


        licz++;

        }

        sort(wartosciNiep,wartosciNiep+50);
        sort(wartosciPier,wartosciPier+50);

        cout<<endl<<" najwiecej nieparzystych: "<<wartosciNiep[49]<<endl;

        for(int q=0;q<50;q++){
            if(przedzialy[q].nieparzyste==wartosciNiep[49]){
                cout<<przedzialy[q].wiersz<<endl;
            }
        }

        cout<<endl<<" najwiecej pierwszych: "<<wartosciPier[49]<<endl;

        for(int q=0;q<50;q++){
            if(przedzialy[q].pierwsze==wartosciPier[49]){
                cout<<"wiersz: "<<przedzialy[q].wiersz<<" przedzial: "<<przedzialy[q].znaklewy<<przedzialy[q].faktycznyPoczatek<<","<<przedzialy[q].faktycznyKoniec<<przedzialy[q].znakprawy<<endl;
            }
        }

        for(int i=0;i<201;i++){
            cout<<calyprzedzial[i];
        }










    return 0;
}
