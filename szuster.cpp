//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <cstdlib>
TForm1 *Form1;
int rozm = 50; // rozmiar tile'i
int ods = 52; // odstęp

struct wspol {
	int x,y;
};
struct polozenie {
	TShape *pionek;
	int nr;
	int x,y;
    int ziel;
};
int planszax=50;
polozenie pion1,pion2,pion3,pion4;
wspol pola[41];
TShape *zielony, *zielony2, *zielony3, *zielony4;
//---------------------------------------------------------------------------
void rysujPlansze(int mX, int mY, TImage *parent) {


	int plansza[11][11] = {
		{2, 2, 0, 0, 1, 1, 3, 0, 0, 3, 3},
		{2, 2, 0, 0, 1, 3, 1, 0, 0, 3, 3},
		{0, 0, 0, 0, 1, 3, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 3, 1, 0, 0, 0, 0},

		{2, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1},
		{1, 2, 2, 2, 2, 0, 4, 4, 4, 4, 1},
		{1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 4},

		{0, 0, 0, 0, 1, 5, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 5, 1, 0, 0, 0, 0},
		{5, 5, 0, 0, 1, 5, 1, 0, 0, 4, 4},
		{5, 5, 0, 0, 5, 1, 1, 0, 0, 4, 4}
	};

	for (int j=0; j<11; j++) {
		for (int i=0; i<11; i++) {
			int kod = plansza[j][i];
			if (kod > 0) {
				int x1 = ods*i + mX;
				int y1 = j*ods + mY;
				int x2 = (ods*i)+rozm + mX;
				int y2 = (j*ods)+rozm + mY;

				switch (kod) {
					case 1:
						parent->Canvas->Brush->Color = clWhite;
						break;
					case 2:
						parent->Canvas->Brush->Color = clRed;
						break;
					case 3:
						parent->Canvas->Brush->Color = clBlue;
						break;
					case 4:
						parent->Canvas->Brush->Color = clGreen;
						break;
					case 5:
						parent->Canvas->Brush->Color = clYellow;
						break;
				}
				parent->Canvas->Rectangle(x1, y1, x2, y2);
			}
		}
	}
	zielony=new TShape(Form1);
	pion1.pionek=zielony;
	zielony->Left=planszax+pola[0].x+5;
	zielony->Top=pola[0].y+5+2;
	zielony->Parent=Form1;
	zielony->Width=rozm-10;
	zielony->Height=rozm-10;
	zielony->Brush->Color=clGreen;
	zielony->Shape=stCircle;
	pion1.ziel=0;

	zielony2=new TShape(Form1);
	pion2.pionek=zielony2;
	zielony2->Left=planszax+pola[0].x+5+ods;
	zielony2->Top=pola[0].y+5+2;
	zielony2->Parent=Form1;
	zielony2->Width=rozm-10;
	zielony2->Height=rozm-10;
	zielony2->Brush->Color=clGreen;
	zielony2->Shape=stCircle;
	pion2.ziel=0;

	zielony3=new TShape(Form1);
	pion3.pionek=zielony3;
	zielony3->Left=planszax+pola[0].x+5;
	zielony3->Top=pola[0].y+5+2+ods;
	zielony3->Parent=Form1;
	zielony3->Width=rozm-10;
	zielony3->Height=rozm-10;
	zielony3->Brush->Color=clGreen;
	zielony3->Shape=stCircle;
	pion3.ziel=0;

	zielony4=new TShape(Form1);
	pion4.pionek=zielony4;
	zielony4->Left=planszax+pola[0].x+5+ods;
	zielony4->Top=pola[0].y+5+2+ods;
	zielony4->Parent=Form1;
	zielony4->Width=rozm-10;
	zielony4->Height=rozm-10;
	zielony4->Brush->Color=clGreen;
	zielony4->Shape=stCircle;
	pion4.ziel=0;
}
//---------------------------konstruktor--------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Start1Click(TObject *Sender)
{
	rysujPlansze(planszax, 0, Image1);
    StaticText1->Visible=True;
	Button1->Visible=True;
	Button1->Enabled=True;
	Przerwijgr1->Enabled=True;
	Start1->Enabled=False;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

  int v1 = rand()%6+1;
  int v2 = rand()%4+1;
  StaticText1->Caption = "rzut kostka: "+ (String)v1;




  if(pion1.ziel==0){
	if(v1==6 && v2==1){
		pion1.ziel=1;
		zielony->Left=planszax+pola[pion1.ziel].x+5;
		zielony->Top=pola[pion1.ziel].y+5+2;
		v1=0;
	}
	else{
		pion1.ziel=0;
		v1=0;
    }
  }


	if (pion1.ziel>40) pion1.ziel=0;
	if(pion1.ziel!=0)pion1.ziel+=v1;
	zielony->Left=planszax+pola[pion1.ziel].x+5;
	zielony->Top=pola[pion1.ziel].y+5+2;




  if(pion2.ziel==0){
	if(v1==6 && v2==2){
		pion2.ziel=1;
		zielony2->Left=planszax+pola[pion2.ziel].x+5;
		zielony2->Top=pola[pion2.ziel].y+5+2;
		v1=0;
	}
	else{
		pion2.ziel=0;
		v1=0;
	}
  }

	if (pion2.ziel>40) pion2.ziel=0;
	if(pion2.ziel!=0)pion2.ziel+=v1;
	zielony2->Left=planszax+pola[pion2.ziel].x+5;
	zielony2->Top=pola[pion2.ziel].y+5+2;


  if(pion3.ziel==0){
	if(v1==6&&v2==3){
		pion3.ziel=1;
		zielony3->Left=planszax+pola[pion3.ziel].x+5;
		zielony3->Top=pola[pion3.ziel].y+5+2;
		v1=0;
	}
	else{
		pion3.ziel=0;
		v1=0;
    }
  }

	if (pion3.ziel>40) pion3.ziel=0;
	if(pion3.ziel!=0)pion3.ziel+=v1;
	zielony3->Left=planszax+pola[pion3.ziel].x+5;
	zielony3->Top=pola[pion3.ziel].y+5+2;


  if(pion4.ziel==0){
	if(v1==6&&v2==4){
		pion4.ziel=1;
		zielony4->Left=planszax+pola[pion4.ziel].x+5;
		zielony4->Top=pola[pion4.ziel].y+5+2;
		v1=0;
	}
	else{
		pion4.ziel=0;
		v1=0;
	}
  }

	if (pion4.ziel>40) pion4.ziel=0;
	if(pion4.ziel!=0)pion4.ziel+=v1;
	zielony4->Left=planszax+pola[pion4.ziel].x+5;
	zielony4->Top=pola[pion4.ziel].y+5+2;



	if(pion1.ziel==0){
	zielony->Left=planszax+pola[pion1.ziel].x+5;
	zielony->Top=pola[pion1.ziel].y+5+2;
	}

	if(pion2.ziel==0){
	zielony2->Left=planszax+pola[pion2.ziel].x+5+ods;
	zielony2->Top=pola[pion2.ziel].y+5+2;
	}

	if(pion3.ziel==0){
	zielony3->Left=planszax+pola[pion3.ziel].x+5;
	zielony3->Top=pola[pion3.ziel].y+5+2+ods;
	}

	if(pion4.ziel==0){
	zielony4->Left=planszax+pola[pion4.ziel].x+5+ods;
	zielony4->Top=pola[pion4.ziel].y+5+2+ods;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::inicjuj(TObject *Sender)
{
int i;
  for(i=1;i<=5;i++)
  {
	 pola[i].x=6*ods;
	 pola[i].y=-54+i*(ods);
  }
  for(i=6;i<=9;i++)
   {
	   pola[i].x=(i+1)*ods;
	   pola[i].y=4*ods;
   }
  for(i=10;i<12;i++)
  {
	  pola[i].x=10*ods;
	  pola[i].y=(i-5)*(ods);
  }
  for(i=12;i<16;i++)
  {
	  pola[i].x=(21-i)*ods;
	  pola[i].y=6*(ods);
  }
 for(i=16;i<20;i++)
  {
	  pola[i].x=6*ods;
	  pola[i].y=(i-9)*(ods);
  }
  for(i=20;i<22;i++)
  {
	  pola[i].x=(25-i)*ods;
	  pola[i].y=10*(ods);
  }
  for(i=22;i<26;i++)
  {
	  pola[i].x=4*ods;
	  pola[i].y=(31-i)*(ods);
  }
  for(i=26;i<30;i++)
  {
	  pola[i].x=(29-i)*ods;
	  pola[i].y=6*(ods);
  }
 for(i=30;i<32;i++)
  {
	  pola[i].x=0;
	  pola[i].y=(35-i)*(ods);
  }
 for(i=32;i<36;i++)
   {
	   pola[i].x=(i-31)*ods;
	   pola[i].y=4*ods;
   }
 for(i=36;i<40;i++)
  {
	  pola[i].x=4*ods;
	  pola[i].y=(39-i)*(ods);
  }
 pola[40].x=5*ods;
 pola[40].y=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Start2Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Przerwijgr1Click(TObject *Sender)
{
   Button1->Enabled=False;
   delete zielony;
   Start1->Enabled=True;
   Przerwijgr1->Enabled=False;

}
//---------------------------------------------------------------------------
