#ifndef FUNCIONES_H
#define FUNCIONES_H
#define color SetConsoleTextAttribute
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int anchoConsola();
void imprimirEspacio(int n);
void centrar(const string& text);
void centrarCin(int tamanotexto);
void separador(char c);
void enjaular(string text, char c);
void subrayar(string text, char c);
void linea(int n, char s, int salto);
void contenidoJaula(string text, int n, char s, int salto);
void enlinear(string texto, char s);


#endif
