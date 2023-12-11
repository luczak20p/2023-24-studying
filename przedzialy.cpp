#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

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
    int wielkosc = 0;

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

            if((i==przedzialy[licz].faktycznyPoczatek&&przedzialy[licz].znaklewy=='(')){
            calyprzedzial[i+100]=2;
            }

            else if(i==przedzialy[licz].faktycznyKoniec&&przedzialy[licz].znakprawy==')'){
            calyprzedzial[i+100]=3;
            }


        }


        licz++;

        }

        sort(wartosciNiep,wartosciNiep+50);
        sort(wartosciPier,wartosciPier+50);

        cout<<endl<<" najwiecej nieparzystych: "<<wartosciNiep[49]<<endl<<"w linijkach: "<<endl;

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

        string wynik = "";
        for(int i=0;i<201;i++){
            wynik+=to_string(calyprzedzial[i]);
        }

        cout<<endl<<"0 - brak w przedziale, 1 - w przedziale, 2 - lewy nawias, 3 - prawy nawias"<<endl;
        cout<<"tabela: "<<wynik<<endl;

        int maxdlugosc, dlugosc,endin, maxStart, maxEnd = 0;
        char NewZnak1, NewZnak2;
        int start = -100;

        cout<<endl<<"PRZEDZIALY PO SUMIE: "<<endl;
        for(int i=0;i<201;i++){
            switch(calyprzedzial[i]){
                case 1:
                    if(calyprzedzial[i+1]==0||calyprzedzial[i+1]==2) {
                            if(i==0){
                                NewZnak1='<';
                            }

                            dlugosc+=1;
                            endin = i-100;
                            NewZnak2='>';
                            if(dlugosc!=0){
                                cout<<NewZnak1<<start<<","<<endin<<NewZnak2<<" dlugosc: "<<dlugosc<<endl;
                            }
                            dlugosc=0;
                    }
                    else if(calyprzedzial[i-1]==0||calyprzedzial[i-1]==3) {
                            dlugosc+=1;
                            start = i-100;
                            NewZnak1='<';
                    }
                    else dlugosc+=1;
                    break;
                case 2:
                    if(calyprzedzial[i-1]==0){
                    NewZnak1='(';
                    start=i-100;
                    }
                    else{
                    endin = i-100;
                    if(dlugosc!=0){
                        cout<<NewZnak1<<start<<","<<endin<<NewZnak2<<" dlugosc: "<<dlugosc<<endl;
                    }
                    dlugosc=0;
                    NewZnak1='(';
                    start = i-100;
                    }

                    break;
                case 3:
                    NewZnak2=')';
                    endin=i-100;
                    if(dlugosc!=0){
                        cout<<NewZnak1<<start<<","<<endin<<NewZnak2<<" dlugosc: "<<dlugosc<<endl;
                    }
                    dlugosc=0;
                    break;

            }
        }

    return 0;
}
