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
 * main.cpp
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

#include "Calculator.h"

int main() // Esta parte requiere algo de trabajo tambien
{
  int menu = 0;
  bool sigue;
  
  Calculator myCalculator;
  
  // Hay que crear un menu
  
  do {
    cout << "======================================================================"
    << "\nPrograma para calcular promedios de vida de personajes del Imperium AO"
    << "\nCreado por Sarckz\n"
    << "\nhttp://sarckz.com.ar/\n"
    << "======================================================================"
    << endl;
    
    // Aca comienzan las funciones de calculo
    myCalculator.ingresoDatos();
    myCalculator.calcularPromedio();
    // Y aca finalizan
    
    // Esperar a que el usuario presione "Enter" para continuar
    system("PAUSE");
  
    cout << "Que deseas hacer ahora?\n"
    << "\n1_ Realizar nuevo calculo" << "\n2_ Salir\n"
    << "\nElige: ";
    cin >> menu;
    
    while ( menu < 1 || menu > 2 )
    {
      cout << "\nQue deseas hacer ahora?\n"
      << "\n1_ Realizar nuevo calculo" << "\n2_ Salir\n"
      << "\nElige: ";
      cin >> menu;
    }
    
    switch ( menu )
    {
      case 1:
	       sigue = true;
	       break;
	  
      case 2:
	       sigue = false;
           break;
	  
    }
      
  } while ( sigue == true );

  // Esperar a que el usuario presione "Enter" para salir
  system("PAUSE");
  
  return 0;
}
