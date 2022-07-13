#include <iostream>
#include <windows.h>
#include <conio.h>
#include "TitleScreen.h"
#include "Login.h"

// #include "Bptree.h"
//using namespace  std;


// driver code of the titleScreen
int main(){

	system("color 0E"); // colors the console screen
	// for title screen
	TitleScreen firstScreen;
	firstScreen.displayScreen();

	cout<<"\n\nPress any key......";
	getch();
	cout<<"\n\nLoading......." ;
	Sleep(2000);
	system("cls");

	LogIn a;
//	system("color 0E");
	a.display(); // main menu function

	return 0;
}
