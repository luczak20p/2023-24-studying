//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int startx=400, starty=200;
int wspx=0, wspy=0;
int kat=0, r=50, r2=100;
float alfa;
int skok = 2;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Ruch(TObject *Sender)
{


	alfa=(kat*M_PI/180)  ;
	wspx = r*cos(alfa);
	wspy=r*sin(alfa);



	Image1->Canvas->MoveTo(startx, starty);
	Image1->Canvas->Pen->Color=clWhite;
	Image1->Canvas->LineTo(startx+wspx,starty+wspy);

	//r2*r2-(starty+wspy)*(starty+wspy)=x

	Image1->Canvas->LineTo(600+wspx,200);
	Image1->Canvas->Rectangle(600+wspx,175,675+wspx,225);
	kat = (kat+1)%360;

    alfa=(kat*M_PI/180)  ;
	wspx = r*cos(alfa);
	wspy=r*sin(alfa);

	Image1->Canvas->MoveTo(startx, starty);
	Image1->Canvas->Pen->Color=clBlack;
	Image1->Canvas->LineTo(startx+wspx,starty+wspy);
	Image1->Canvas->LineTo(600+wspx,200);
	Image1->Canvas->Rectangle(600+wspx,175,675+wspx,225);
//	r=r+skok;                       Kw
//	if (r>200) skok=-skok;            i
//	if (r<10) skok=-skok;              at
//	wspx=(wspx+3)%800;
//	wspy=(wspy-3)%450;
//    startx=(startx+1)%700;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Timer1->Enabled=false;
  Image1->Canvas->Rectangle(0,0,800,450);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
