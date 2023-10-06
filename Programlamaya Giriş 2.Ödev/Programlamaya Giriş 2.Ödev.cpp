/****************************************************************************
**							   SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**						  BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				            PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI....: 2
**				ÖĞRENCİ ADI......: Yavuzhan ALBAYRAK
**				ÖĞRENCİ NUMARASI.: G201210008
**				DERS GRUBU.......: A
****************************************************************************/

#include <Windows.h>
#include <iostream>
using namespace std;

void koordinat(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class kat {
public:
	int yukseklik;
	int genislik;

	void katciz(int gen,int yuk,int x,int y) {
		//Bu döngülerle katın yükseklik ve genişlik bilgileri alınmıştır.
		for (int i = 0; i < gen-1; i++) {
			koordinat(x+i, y);
			cout << char(219);
			Sleep(10);
		}
		for (int i = 0; i < yuk; i++) {
			koordinat(x + gen-1, y+i);
			cout << char(219);
			Sleep(10);
		}
		for (int i = 0; i < gen; i++) {
			koordinat(x + gen-1 - i , y+yuk-1);
			cout << char(219);
			Sleep(10);
		}
		for (int i = 0; i < yuk; i++) {
			koordinat(x, y + i);
			cout << char(219);
			Sleep(10);
		}

		
	}
	
};
class cati {
public:
	int yukseklik;
	void caticiz(int gen,int yuk,int x,int y,int catiyuk){
		int a = gen;
		int b = 1;
		//Burada çatının yüksekliği girilmiştir.
		for (int i = 0; i < catiyuk; i++) {
			for (int i = 0; i < a ; i++){
				koordinat(x+i+b-1 , y - b);
				cout << "*";
				Sleep(10);
			}
			a = a - 2;
			b = b + 1;
		}
		
	}
	
};
class kapi {
public:
	int yukseklik;
	int genislik;
	
	void kapiciz(int x, int y,int yuk) {
		int yukseklik = 0;
		int genislik = 3;
		//Kapının yükseklik ve genişlik özellikleri alınmıştır.
		for (int a = 0; a < 4; a++) {
			
			for (int i = 0; i < 4; i++) {
				koordinat(x + genislik + i, y + yuk - 1+yukseklik);
				cout << "#";
				Sleep(10);
			}
			yukseklik = yukseklik - 1;
		}
	}
};
class Ev   {
public:
	kat kat1;
	cati cati1;
	kapi kapi1;
};


int main()
{
	Ev ev;
	int x, y;
	cout << "Genislik: "; cin >> ev.kat1.genislik;
	cout << "Yukseklik: "; cin >> ev.kat1.yukseklik;
	cout << "Cati Yuksekligi: "; cin >> ev.cati1.yukseklik;
	cout << "x: "; cin >> x;
	cout << "y: "; cin >> y;
	//Ev çizimi yapılmıştır.
	ev.cati1.caticiz(ev.kat1.genislik, ev.kat1.yukseklik , x, y, ev.cati1.yukseklik);
	ev.kat1.katciz(ev.kat1.genislik, ev.kat1.yukseklik,x,y);
	ev.kapi1.kapiciz(x, y, ev.kat1.yukseklik);
	koordinat(x , y + ev.cati1.yukseklik + 30);
	cout << "Program Sonu.";

}
