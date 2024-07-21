#include "funciones.h"
#include <iostream>
#include <windows.h>
#include <locale.h> //libreria para incluir el idioma español
#define color SetConsoleTextAttribute
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	
	system("pause");
	setlocale(LC_ALL, ""); //parte de la liberia locale.h
	
	string texto;
	char s;
	int modalidad;
	int max= 100;
	do{
		color(hConsole, 79);
		cout << endl;
		s= '*';
		separador(s);
		texto = "ESIS'S RESTAURANT";
		centrar(texto);
		s = '*';
		separador(s); cout << endl;
		
		color(hConsole, 7);
		cout << endl << endl;
		texto = "Elije el modo de juego";
		s = '*';
		enjaular(texto, s); cout << endl << endl;
		
		texto = "Quiero ser el:";
		centrar(texto);
		s= '=';
		subrayar(texto, s); cout << endl << endl;
		
		int anchoJaula=40;
		int salto=2;
		s='*';
		linea(anchoJaula, s, salto); cout << endl;
		texto = "1. DUEÑO";
		contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
		texto = "2. CLIENTE";
		contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
		texto = "3. DELIVERY";
		contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
		texto = "4. ABANDONAR EMULADOR";
		contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
		linea(anchoJaula, s, 0); cout << endl;
		
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> modalidad;
		cout << endl;
		
	} while (modalidad!=4);
	return 0;
}
