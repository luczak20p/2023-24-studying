//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

struct polozenie {
	TShape *pionek;
	int nr;
	int x,y;
};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
	  TShape *pionek1;

//---------------------------------------------------------------------------
void __fastcall TForm1::rysujPlansze(TObject *Sender)
{
int plansza[7][7] = {
		{0, 0, 1, 1, 1, 0, 0},
		{0, 0, 1, 1, 1, 0, 0},
		{1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1},
		{0, 0, 1, 1, 1, 0, 0},
		{0, 0, 1, 1, 1, 0, 0},
	};

    int rozm = 50; // rozmiar tile'i
	int ods = 52; // odstęp

	for (int j=0; j<7; j++) {
		for (int i=0; i<7; i++) {
			int kod = plansza[j][i];
			if (kod > 0) {
				int x1 = ods*i;
				int y1 = j*ods;
				int x2 = (ods*i)+rozm;
				int y2 = (j*ods)+rozm;

				Image1->Canvas->Rectangle(x1, y1, x2, y2);
			}
		}
	}

	int pola[33];


	polozenie pion1;
	pionek1=new TShape(Form1);
	pion1.pionek=pionek1;
	pionek1->Parent=Form1;
	pionek1->Shape=stCircle;
	pionek1->Width=rozm-10;
	pionek1->Height=rozm-10;
	pionek1->Left=4*ods+5;
	pionek1->Top=4*ods+5;
	pionek1->Brush->Color=clBlack;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::start(TObject *Sender)
{
	  rysujPlansze(Image1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ruch(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	//gdy w tshape X<=tshapex Y=>tshapey ebebe to wtedy akcja

}
//---------------------------------------------------------------------------
