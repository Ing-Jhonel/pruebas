#include "funciones.h"
#include <iostream>
#include <windows.h>
#include <locale.h> //libreria para incluir el idioma español
#define color SetConsoleTextAttribute

using namespace std;
	
// Función para obtener el ancho de la consola
int anchoConsola() {
    CONSOLE_SCREEN_BUFFER_INFO csbi; //declara variable de tipo CONSOLE_SCREEN_BUFFER_INFO (es una estructura definida en la libreria windows.h)
    // esta contiene info sobre el bufer de la pantalla de consola, como las dimensiones (lo que necesitamos)
    int columnas; //declara una variable "columnas" de tipo int

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); //con "GetStdHandle(STD_OUTPUT_HANDLE)" obtenemos un identificador para el bufer
    //de
    // Esta función obtiene información detallada sobre el búfer de pantalla de la consola y la guarda en la estructura csbi.
    columnas = csbi.srWindow.Right - csbi.srWindow.Left + 1; //csbi.srWindow.Right y csbi.srWindow.Left: Estas son propiedades de la estructura CONSOLE_SCREEN_BUFFER_INFO. 
	// srWindow es una estructura dentro de csbi que representa la ventana de visualización actual de la consola.
	// csbi.srWindow.Right representa la coordenada más a la derecha de la ventana de la consola.
	// csbi.srWindow.Left representa la coordenada más a la izquierda de la ventana de la consola.
	
	//ej
	
	// si la consola mide 100 caracteres, para que la pc lo sepa, entonces:
	// csbi.srWindow.Right = 99
	// csbi.srWindow.Left = 0
	// 	columnas = 99 +1 = 100, 
    return columnas;
}

// Funcion para imprimir un espacio entre el lado izquierdo de la pantalla hasta donde se indique
void imprimirEspacio(int n){
	for(int i=0; i<n; i++){
		cout << " ";
	}
}
// Función para centrar el texto
void centrar(const string& text) {
    int tamanoconsola = anchoConsola(); // ya que hallamos columnas con la funcion, le asignamos una variable al retorno
    int tamanotexto = text.length(); //"text.lenght()" halla el tamaño del texto en caracteres. le asignamos una variable de tipo int a la anchura del texto
    int espaciado = (tamanoconsola - tamanotexto) / 2; // la diferencia de ambos entre 2 es la distancia para centrar un texto
    // Imprimir espacios en blanco antes del texto
    imprimirEspacio(espaciado);
    // Imprimir el texto
    cout << text;
    
    imprimirEspacio(espaciado);
    
}

// Funcion para centrar una entrada "cin"
void centrarCin(int tamanotexto){

    int tamanoconsola = anchoConsola(); // ya que hallamos columnas con la funcion, le asignamos una variable al retorno
    int espaciado = (tamanoconsola - tamanotexto) / 2; // la diferencia de ambos entre 2 es la distancia para centrar un texto
    // Imprimir espacios en blanco antes del texto
    imprimirEspacio(espaciado);
}

// Funcion para generar una linea larga entre ambos extremos de la pantalla, ideal para separar secciones
void separador(char c){
	int tamanoconsola = anchoConsola();
	cout << endl;
	for(int i=0; i<tamanoconsola; i++){
		cout << c;
	}
}

// Funcion para enjaular un texto (genera un marco alrededor de el), solo una linea de texto, no varias
void enjaular(string text, char c){
	
	int tamanotexto = text.length();
	int anchojaula = tamanotexto+4;
	int tamanoconsola = anchoConsola();
	int espaciado = (tamanoconsola - anchojaula)/2;
	//largo de jaula es 3
	imprimirEspacio(espaciado);
	
	for(int i=0; i<anchojaula; i++){
		cout << c;
	}
	cout << endl;
	
	imprimirEspacio(espaciado);
	
	cout << c << " " << text << " " << c;
	cout << endl;
	
	imprimirEspacio(espaciado);
	
	for(int i=0; i<anchojaula; i++){
		cout << c;
	}

}

// Funcion para subrayar un texto
void subrayar(string text, char c){
	
	cout << endl;
	
	int tamanoconsola = anchoConsola();
	int tamanotexto = text.length();
	int espaciado = (tamanoconsola - tamanotexto)/2;
	
	imprimirEspacio(espaciado);
	
	for(int i=0; i<tamanotexto; i++){
		cout << c;
	}

}

// Funcion para generar una linea de un tamaño, si hay un "salto" de linea, generara entre ambos extremos de la linea un caracter mas, para generar una jaula en ese caso
void linea(int n, char s, int salto){
	int tamanoconsola = anchoConsola();
	int espaciado = (tamanoconsola - n)/2;
	
	imprimirEspacio(espaciado);
	
	for(int i=0; i<n; i++){
		cout << s;
	}
	
	// ej:   ******************	 ; salto = 0
	// 		 *				  *  ; salto = 1
	if(salto>0){
		cout << endl;
		
		imprimirEspacio(espaciado);
		
		cout << s;
		int espaciojaula = n-2;
		
		imprimirEspacio(espaciojaula);
		
		cout << s;
	} 
}

// Funcion para generar el contenido de una jaula, esto funcion se complementa con la funcion "linea"
void contenidoJaula(string text, int n, char s, int salto){
	int tamanoconsola = anchoConsola();
	int espaciado = (tamanoconsola - n)/2;
	
	imprimirEspacio(espaciado);
	
	cout << s;
	
	int tamanotexto = text.length();
	int entrelineas = n-2-tamanotexto;
	int entrelinea1 = (n-2-tamanotexto)/2;
	int entrelinea2 = entrelineas - entrelinea1;
	
	imprimirEspacio(entrelinea1);
	
	cout << text;

	imprimirEspacio(entrelinea2);
	
	cout << s;
	
	imprimirEspacio(espaciado);
	
	// *	texto	*
	if(salto>0){
		for(int i=0; i<salto; i++){
			cout << endl;
			
			imprimirEspacio(espaciado);
			
			cout << s;
			
			int espaciojaula=n-2;
			imprimirEspacio(espaciojaula);
			
			cout << s;
		}
		// *	texto	* ; salto = 0
		// *			* ; salto = 1
	}
	
}


// Funcion para enlinear un texto en el centro de la pantalla
// ej: 		*********** text ************
void enlinear(string texto, char s){
	int tamanoconsola = anchoConsola();
	int tamanotexto = texto.length();
	int tamanolinea = (tamanoconsola - tamanotexto)/2;
	
	for(int i=0; i<tamanolinea; i++){
		cout << s;
	}
	cout << " " << texto << " ";
	
	for(int i=1; i<tamanolinea; i++){
		cout << s;
	}
}
