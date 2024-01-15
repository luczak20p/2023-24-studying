//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int startx=400, starty = 200;
int wspx = 0, wspy=0;
int kat=0, r=200;
float alfa;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ruch(TObject *Sender)
{
	alfa = (kat*M_PI/180);
	wspx=r*cos(alfa);
	wspy=r*sin(alfa);
	Image1->Canvas->MoveTo(startx,starty);
	Image1->Canvas->LineTo(startx+wspx,starty+wspy);
	kat=(kat+1)%360;
//	wspx=(wspx+5)%800;
//	wspy=(wspy+20)%450;
//	startx=(startx+1)%700;
//	starty=(starty+50)%450;
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
