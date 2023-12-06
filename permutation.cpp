#include <iostream>
#include <fstream>
#include <vector>

//weź to zrozum

using namespace std;

void PrzodTyl(vector<char>& slowo, int poczatek, int koniec) {
    while (poczatek < koniec-1) {
        swap(slowo[poczatek], slowo[koniec-1]);
        poczatek++;
        koniec--;
    }
}

void nextPermutation(vector<char>& slowo) {
    int dlugosc = slowo.size();
    int i = dlugosc - 1;
    while (i >= 0 && slowo[i] >= slowo[i+1]) {
        i--;
    }
    if (i >= 0) {
        int j = dlugosc - 1;
        while (j >= 0 && slowo[j] <= slowo[i]) {
            j--;
        }
        swap(slowo[i], slowo[j]);
    }
    PrzodTyl(slowo, i+1, dlugosc);
}

int main()
{
    fstream plik;
    vector<char>v;
    char znaczek;
    string slowaNowe[120]={""}; //bo max 5 liter
    plik.open("teksty.txt", ios::in);
    if(plik.good()){
        cout<<"Plik otwarl sie poprawnie"<<endl;
    }

    while(!plik.eof()){
        plik>>znaczek;
        if(plik.eof()){
            break;
        }
        v.push_back(znaczek);
    }


    for( int i = 0; i < v.size(); i += 1 )
   {
       cout << v[i];
   }

   cout<<endl;
   nextPermutation(v);

       for( int i = 0; i < v.size(); i += 1 )
   {
       cout << v[i];
   }

   cout<<endl;
      nextPermutation(v);

       for( int i = 0; i < v.size(); i += 1 )
   {
       cout << v[i];
   }





    for(int i=0;i<sizeof(slowaNowe) / sizeof(string);i++){
        for(int j=0;j<sizeof(slowaNowe) / sizeof(string);j++){
            if(slowaNowe[j]==slowaNowe[i]&&i!=j){
                slowaNowe[j]="";
            }
        }
    }

    for(int i=0;i<sizeof(slowaNowe) / sizeof(string);i++){
        if(slowaNowe[i]!="")
        cout<<slowaNowe[i]<<endl;
    }




    return 0;
}
