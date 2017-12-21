//lifemain.cpp
//Yifan Yu

#include<iostream>
#include<vector>
#include <cstdlib>
#include <unistd.h>
#include<string>
#include<fstream>

using namespace std;
#include "lifeboard.h"

int main(int argc, char *argv[]){

	//Declaration
	bool interactiveMode;
	int cellRow, cellColumn; //number of rows and number of columns
	char userChoice = 'a';   //setting
	ifstream ifs;

	if(argc == 1){
		interactiveMode = true;
	}
	else if(argc >2){
		cout << "Error. Please type in one name of file to enter batch mode." << endl;
		return 1;
	}
	else
	{
		interactiveMode = false;
				ifs.open(argv[1]);

	}

	Lifeboard a,b;


	a.print();

	if(interactiveMode){
		while(userChoice != 'q'){


			cout << "Enter a to add a new live cell, r to remove a cell, n to advance, q to quite the program, p to play the game continuously." <<endl;
			cin >> userChoice;



			switch (userChoice){


			case 'a':
				cout << "Please enter the coordinates of the new live cell added: ";
				cin >> cellRow >> cellColumn;
				b.addCell(cellRow, cellColumn);
				break;

			case 'r':
				cout << "Please enter the coordinates of the live cell removed: ";
				cin >> cellRow >> cellColumn;
				b.removeCell(cellRow, cellColumn);
				break;

			case 'n':
				a.setBoard(b);
				b.advanceBoard();
				system("clear");
				a.print();
				break;

			case 'q':

				break;

			case 'p':


				while(1){

					b.print();
					usleep(200000);
					system("clear");
					b.advanceBoard();
				}
				break;


			}
		}
	}
	else{

		char userChoice = 'a';
		while(!ifs.eof() && userChoice != 'q'){

			ifs >> userChoice;

			switch (userChoice){


				case 'a':

					ifs >> cellRow >> cellColumn;
					b.addCell(cellRow, cellColumn);
					break;

				case 'r':

					ifs >> cellRow >> cellColumn;
					b.removeCell(cellRow, cellColumn);
					break;

				case 'n':
					a.setBoard(b);
					b.advanceBoard();
					system("clear");
					a.print();
					break;

				case 'q':

					break;

				case 'p':


					while(1){

						b.print();
						usleep(200000);
						system("clear");
						b.advanceBoard();
					}
					break;


			}
		}
	}
	return 0;
}
