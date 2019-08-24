/* Programa para calcular promedios de vida de personajes del Imperium AO
 * Creado por Tobias Nahuel Paiva Orzel Mallo
 * http://tobiasmallo.wordpress.com/
 * 
 * <Inicio de la licencia>
 * 
 * Copyright (c) <2011> <Tobias Nahuel Paiva Orzel Mallo>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * 
 * <Fin de la licencia>
 * 
 * Calculator.cpp
 * Definición de las funciones de la clase Calculator
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "Calculator.h"

void Calculator::ingresoDatos()
{
  int claseElegida;
  int tuNivel;
  int constitucion;
  int vidaInicial;
  int tuVida;
  int humano;
  
  cout << "\nElige una clase:\n\n"
  << "1_ Asesino\n" << "2_ Bardo\n" << "3_ Cazador\n" << "4_ Gladiador\n"
  << "5_ Clerigo\n" << "6_ Druida\n" << "7_ Guerrero\n" << "8_ Ladron\n"
  << "9_ Mago\n" << "10_ Nigromante\n" << "11_ Paladin\n" << "12_ Mercenario\n"
  << endl;
  
  cout << "\nIngresa un numero del 1 al 12: ";
  cin >> claseElegida;
  
  while ( claseElegida < 1 || claseElegida > 12 )
  {
    cout << "\nElige una clase:\n\n"
    << "1_ Asesino\n" << "2_ Bardo\n" << "3_ Cazador\n" << "4_ Gladiador\n"
    << "5_ Clerigo\n" << "6_ Druida\n" << "7_ Guerrero\n" << "8_ Ladron\n"
    << "9_ Mago\n" << "10_ Nigromante\n" << "11_ Paladin\n" << "12_ Mercenario\n"
    << endl;
    
    cout << "\nIngresa un numero del 1 al 12: ";
    cin >> claseElegida;
  }
  
  // Acá se ingresa el nivel del personaje
  cout << "\nIngresa el nivel (2 a 60): ";
  cin >> tuNivel;
  
  while ( tuNivel < 2 || tuNivel > 60 )
  {
    cout << "\nIngresa el nivel (2 a 60): ";
    cin >> tuNivel;
  }
  
  setNivel( tuNivel );
  
  // Acá se ingresan los puntos de constitución del personaje
  cout << "\nIngresa constitucion (17 a 22): ";
  cin >> constitucion;
  
  while ( constitucion < 17 || constitucion > 22 )
  {
    cout << "\nIngresa constitucion (17 a 22): ";
    cin >> constitucion;
  }
  
  setConstitucion( constitucion );
  
  setClase( claseElegida );
  
  // Se ingresa la vida inicial del personaje
  // Tengo que averiguar bien el mínimo y máximo
  cout << "\nIngresa vida inicial (8 a 26): ";
  cin >> vidaInicial;
  
  while ( vidaInicial < 8 || vidaInicial > 26 )
  {
    cout << "\nIngresa vida inicial (8 a 26): ";
    cin >> vidaInicial;
  }
  
  setVidaInicial( vidaInicial );
  
  // Vida total del personaje
  cout << "\nIngresa vida total (12 a 625): ";
  cin >> tuVida;
  
  while ( tuVida < 12 || tuVida > 625 )
  {
    cout << "\nIngresa vida total (12 a 625): ";
    cin >> tuVida;
  }
  
  setVida( tuVida );
  
  cout << "\nLa raza de tu personaje es \"Humano\"?\n"
  << "1_ Si\n" << "2_ No\n" << "\nElige: ";
  cin >> humano;
  
  while ( humano < 1 || humano > 2 )
  {
    cout << "\nLa raza de tu personaje es \"Humano\"?\n"
    << "1_ Si\n" << "2_ No\n" << "\nElige: ";
    cin >> humano;
  }
  
  switch ( humano )
  {
    case 1:
      bonusHumano = ( nivelAjustado / 8 );
      esHumano = true;
      break;
      
    case 2:
      bonusHumano = 0;
      esHumano = false;
      break;
  }
}

void Calculator::setConstitucion( int constitucion )
{
  Constit = constitucion;
}

void Calculator::setClase( int claseElegida )
{
  switch ( claseElegida )
  {
    case 1:
      tuClase = "Asesino";
      if ( Constit == 22 )
	     setPromedio( 9 );
      if ( Constit == 21 )
	     setPromedio( 8.75 );
      if ( Constit == 20 )
	     setPromedio( 8 );
      if ( Constit == 19 )
	     setPromedio( 7.5 );
      if ( Constit == 18 )
	     setPromedio( 7.25 );
      if ( Constit == 17 )
	     setPromedio( 6.5 );
      break;
      
    case 2:
      tuClase = "Bardo";
      if ( Constit == 22 )
	     setPromedio( 8.5 );
      if ( Constit == 21 )
	     setPromedio( 8 );
      if ( Constit == 20 )
	     setPromedio( 7.5 );
      if ( Constit == 19 )
	     setPromedio( 7 );
      if ( Constit == 18 )
	     setPromedio( 6.75 );
      if ( Constit == 17 )
	     setPromedio( 6.5 );
      break;
      
    case 3:
      tuClase = "Cazador";
      if ( Constit == 22 )
	     setPromedio( 10 );
      if ( Constit == 21 )
	     setPromedio( 9.75 );
      if ( Constit == 20 )
	     setPromedio( 9.665 );
      if ( Constit == 19 )
	     setPromedio( 9.5 );
      if ( Constit == 18 )
	     setPromedio( 9.25 );
      if ( Constit == 17 )
	     setPromedio( 9 );
      break;
      
    case 4:
      tuClase = "Gladiador";
      if ( Constit == 22 )
	     setPromedio( 9.5 );
      if ( Constit == 21 )
	     setPromedio( 9.25 );
      if ( Constit == 20 )
	     setPromedio( 9 );
      if ( Constit == 19 )
	     setPromedio( 8.5 );
      if ( Constit == 18 )
	     setPromedio( 8 );
      if ( Constit == 17 )
	     setPromedio( 7.5 );
      break;
      
    case 5:
      tuClase = "Clerigo";
      if ( Constit == 22 )
	     setPromedio( 8.5 );
      if ( Constit == 21 )
	     setPromedio( 8 );
      if ( Constit == 20 )
	     setPromedio( 7.5 );
      if ( Constit == 19 )
	     setPromedio( 7 );
      if ( Constit == 18 )
	     setPromedio( 6.75 );
      if ( Constit == 17 )
	     setPromedio( 6.5 );
      break;
      
    case 6:
      tuClase = "Druida";
      if ( Constit == 22 )
	     setPromedio( 8.5 );
      if ( Constit == 21 )
	     setPromedio( 8 );
      if ( Constit == 20 )
	     setPromedio( 7.5 );
      if ( Constit == 19 )
	     setPromedio( 7 );
      if ( Constit == 18 )
	     setPromedio( 6.75 );
      if ( Constit == 17 )
	     setPromedio( 6.5 );
      break;
      
    case 7:
      tuClase = "Guerrero";
      if ( Constit == 22 )
	     setPromedio( 10 );
      if ( Constit == 21 )
	     setPromedio( 9.75 );
      if ( Constit == 20 )
	     setPromedio( 9.665 );
      if ( Constit == 19 )
	     setPromedio( 9.5 );
      if ( Constit == 18 )
	     setPromedio( 9.25 );
      if ( Constit == 17 )
	     setPromedio( 9 );
      break;
      
    case 8:
      tuClase = "Ladron";
      if ( Constit == 22 )
	     setPromedio( 8.5 );
      if ( Constit == 21 )
	     setPromedio( 8.25 );
      if ( Constit == 20 )
	     setPromedio( 8 );
      if ( Constit == 19 )
	     setPromedio( 7.5 );
      if ( Constit == 18 )
	     setPromedio( 7 );
      if ( Constit == 17 )
	     setPromedio( 6.5 );
      break;
      
    case 9:
      tuClase = "Mago";
      if ( Constit == 22 )
	     setPromedio( 7 );
      if ( Constit == 21 )
	     setPromedio( 6.75 );
      if ( Constit == 20 )
	     setPromedio( 6.5 );
      if ( Constit == 19 )
	     setPromedio( 6 );
      if ( Constit == 18 )
	     setPromedio( 5.75 );
      if ( Constit == 17 )
	     setPromedio( 5.5 );
      break;
      
    case 10:
      tuClase = "Nigromante";
      if ( Constit == 22 )
	     setPromedio( 8 );
      if ( Constit == 21 )
	     setPromedio( 7.5 );
      if ( Constit == 20 )
	     setPromedio( 7 );
      if ( Constit == 19 )
	     setPromedio( 6.75 );
      if ( Constit == 18 )
	     setPromedio( 6.5 );
      if ( Constit == 17 )
	     setPromedio( 6.25 );
      break;
      
    case 11:
      tuClase = "Paladin";
      if ( Constit == 22 )
	     setPromedio( 9.75 );
      if ( Constit == 21 )
	     setPromedio( 9.665 );
      if ( Constit == 20 )
	     setPromedio( 9.5 );
      if ( Constit == 19 )
	     setPromedio( 9 );
      if ( Constit == 18 )
	     setPromedio( 8.75 );
      if ( Constit == 17 )
         setPromedio( 8.5 );
      break;
      
    case 12:
      tuClase = "Mercenario";
      if ( Constit == 22 )
	     setPromedio( 9.5 );
      if ( Constit == 21 )
	     setPromedio( 9.25 );
      if ( Constit == 20 )
	     setPromedio( 9 );
      if ( Constit == 19 )
         setPromedio( 8.5 );
      if ( Constit == 18 )
	     setPromedio( 8 );
      if ( Constit == 17 )
	     setPromedio( 7.5 );
      break;
  }
}

void Calculator::setPromedio( double promedioRecibido )
{
  promedioClase = promedioRecibido;
}

void Calculator::setNivel( int tuNivel )
{
  if ( tuNivel > 50 )
    nivelAjustado = 50;
  else
    nivelAjustado = tuNivel;
}

void Calculator::setVidaInicial( int vidaInicial )
{
  inicial = vidaInicial;
}

void Calculator::setVida( int tuVida )
{
  vida = tuVida;
}

void Calculator::calcularPromedio() // Aún falta trabajar en esto
{
  double resultado;
  int bonusClerigo = 0;
  
  if ( tuClase == "Clerigo" )
    bonusClerigo = ( nivelAjustado / 5 );
  
  resultado = ( static_cast< double >( vida ) - bonusClerigo - bonusHumano - inicial ) / ( nivelAjustado - 1 );
  
  // En resultado vendría bien un fixed y un setprecision( 2 )
  cout << fixed << setprecision( 3 );
  cout << "\nEl promedio de tu personaje es: " << resultado << "\n" 
  << "El promedio de un " << tuClase << " con " << Constit << " puntos de constitucion es: "
  << promedioClase << "\n" << endl;
    
  // Agregar acá los resultados para el bonus de clérigo y humano
  if ( esHumano == true )
    cout << "Recibiste " << bonusHumano << " punto(s) extra de vida por el bonus de humano" << endl;
  if ( tuClase == "Clerigo" )
    cout << "Recibiste " << bonusClerigo << " punto(s) extra de vida por el bonus de clerigo" << endl;
  
  cout << endl;
}

// Fin de la clase Calculator
