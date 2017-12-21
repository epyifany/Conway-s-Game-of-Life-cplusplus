//lifeboard.h
//Yifan Yu
#include <vector>
#include <iostream>
using namespace std;

//interface for the Lifeboard class
class Lifeboard {

public:
// Constructors and destructors
	Lifeboard();
	Lifeboard(int, int);
	~Lifeboard();
	

// Access Methods
	void setBoard(Lifeboard);
	vector< vector<bool> > getBoard();
	int getRows();
	int getColumns();


// Utility Methods
	bool returnEntry(int, int);	
	void addCell(int, int);
	void removeCell(int, int);
	void advanceBoard();	
	void print();
	
		

private:
	int rows;
	int columns;
	
	vector< vector<bool> > board;		

};
