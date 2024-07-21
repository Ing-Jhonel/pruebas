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
		
		char opcion;
		switch(modalidad){
			case 1:
				texto = "¡AHORA ERES EL DUEÑO DEL RESTAURANTE!";
				s= '*';
				enjaular(texto, s); cout << endl << endl;
				texto = "¿Que quieres hacer?";
				centrar(texto); cout << endl << endl;
				do{
					texto = "A) Administrar la cocina";
					centrar(texto); cout << endl << endl;
					texto = "B) Administrar el negocio";
					centrar(texto); cout << endl << endl;
					texto = "C) Administrar personal";
					centrar(texto); cout << endl << endl;
					texto = "D) Cambiar de rol";
					centrar(texto); cout << endl << endl;
					texto = "--------";
					centrar(texto); cout << endl;
					centrarCin(1);
					cin >> opcion;
					
					cout << endl;
					
					switch (opcion){
						case 'A':
							s = '-';
							separador(s);
							texto = "Entrando a la cocina...";
							enlinear(texto, s);
							separador(s); cout << endl << endl;
							texto = "Indique la accion que va a realizar";
							centrar(texto);
							s= '=';
							subrayar(texto, s); cout << endl << endl;
							do{
								anchoJaula = 40;
								salto = 0;
								s = '*';
								linea(anchoJaula, s, 2); cout << endl;
								texto = "a) Agregar una comida";
								contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
								texto = "b) Eliminar una comida";
								contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
								texto = "c) Actualizar una comida";
								contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
								texto = "d) Ver stock del menú";
								contenidoJaula(texto, anchoJaula, s, salto); cout << endl;
								texto = "e) Salir de la cocina";
								contenidoJaula(texto, anchoJaula, s, 1); cout << endl;
								linea(anchoJaula, s, 0); cout << endl << endl;
								texto = "--------";
								centrar(texto); cout << endl;
								centrarCin(1);
								cin >> opcion;
								cout << endl;
								
								int n=0;
								switch(opcion){
									case 'a':
										break;
									case 'b':
										if(n==0){
											
										}
										break;
								}
							} while(opcion!='e');
							break;
						case 'B':
							break;
						case 'C':
							break;
						default:
							break;
					}
				} while(opcion != 'D');
				
				break;
				
			case '2':
				break;
			case '3':
				break;
			default:
				cout << "Indique el numero de las modalidades disponibles.";
				break;
		}
	} while (modalidad!=4);
	return 0;
}
