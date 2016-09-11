#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H
//------------------------------------------------------------------------
//
//  Name:   ConsoleUtils.h
//
//  Desc:   Just a few handy utilities for dealing with consoles
//
//  Author: Mat Buckland (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <iostream>

//TODO separate this from rest of the code
#if defined WINDOWS
  #include <windows.h> //Platform.h
  #include <conio.h>   //ConsoleIO.h
#else
  #include "Apple.h"
#endif/*WINDOWS*/



//default text colors can be found in wincon.h
inline void SetTextColor(WORD colors)
{
  HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE); //TO_PORT
  SetConsoleTextAttribute(hConsole, colors); //TO_PORT
}

inline void PressAnyKeyToContinue()
{
  //change text color to white
  SetTextColor(FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN);

  std::cout << "\n\nPress any key to continue" << std::endl; 
  std::cin.ignore();
  while (!_kbhit()){} //TO_PORT:kbhit is a conio.h

  return;
}


#endif//CONSOLE_UTILS_H