#ifndef APPLE_H
#define APPLE_H

// windows types we won't be using, but will keep in place at this stage
#define _In_
#define WINAPI

// defining windows data types for non windows platforms
//https://msdn.microsoft.com/en-us/library/windows/desktop/aa383751(v=vs.85).aspx
typedef void * PVOID;
typedef PVOID HANDLE;
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef void VOID;
typedef int BOOL;
#define FALSE 0
#define TRUE 1
#define STD_INPUT_HANDLE 0 //stdin
#define STD_OUTPUT_HANDLE 1//stdout
#define STD_ERROR_HANDLE 2 //stderr
// coding terminal color output informed by this link
// http://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
// Because an or is used for set text color we have to work with that api and use flags
// note would be nice to actually debug in windows and make it actually match the windows
// color code
#define FOREGROUND_BLUE 1
#define FOREGROUND_RED 2
#define FOREGROUND_GREEN 4
#define FOREGROUND_INTENSITY 0 // this way when OR'd it won't impact the intensity



// defining windows API fon non windows machines

inline VOID WINAPI Sleep(_In_ DWORD dwMilliseconds)
{
  return;
}

inline BOOL WINAPI SetConsoleTextAttribute(HANDLE handle, WORD wAttributes)
{
  return TRUE;
}

inline HANDLE WINAPI GetStdHandle(_In_ DWORD nStdHandle)
{
  return NULL;
}

inline int _kbhit( void )
{
  return getchar();
}

#endif APPLE_H