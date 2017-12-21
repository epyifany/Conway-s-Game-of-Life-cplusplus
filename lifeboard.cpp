//lifeboard.coo
//Yifan Yu

//implementation for the Lifeboard class
#include"lifeboard.h"
#include<vector>

// Constructors and destructors

// default constructor has a 40 by 40 board
Lifeboard::Lifeboard()
{
	rows = 40;
	columns = 40;
	vector<bool> rowVect;
	for(int j = 0; j < columns; j++)
	  rowVect.push_back(false);
	for(int i = 0; i < rows; i++)
	  board.push_back(rowVect);
}

Lifeboard::Lifeboard(int r, int c)
{
	rows = r;
	columns = c;
	vector<bool> rowVect;
	for(int j = 0; j < columns; j++)
	  rowVect.push_back(false);
	for(int i = 0; i < rows; i++)
	  board.push_back(rowVect);
}

Lifeboard::~Lifeboard()
{

}



//get and set functions

void Lifeboard::setBoard(Lifeboard tempBoard)
{
	if (rows == tempBoard.getRows() && columns == tempBoard.getColumns()){
		for(int i = 0; i < rows; i++){
	  	for(int j = 0; j < columns; j++)
    		board[i][j] = tempBoard.returnEntry(i, j);
		}
	}

}

vector< vector<bool> > Lifeboard::getBoard()
{
	return board;
}

int Lifeboard::getRows()
{
	return rows;
}

int Lifeboard::getColumns()
{
	return columns;
}

bool Lifeboard::returnEntry(int r, int c)
{
	return board[r][c];
}


void Lifeboard::addCell(int r, int c)
{
if (r >= 0 && r < rows && c >= 0 && c < columns)
	board[r][c] = true;

}

//if the given coordinates fall on the board, change the entry
void Lifeboard::removeCell(int r, int c)
{
if (r >= 0 && r < rows && c >= 0 && c < columns)
	board[r][c] = false;

}
void Lifeboard::advanceBoard()
{
	//bool tempBoard2[40 + 2][columns + 2] = {0};
	vector< vector<bool> > tempBoard2;
	vector<bool> rowVect;
	for(int j = 0; j < columns + 2; j++)
		rowVect.push_back(false);
	for(int i = 0; i < rows + 2; i++)
		tempBoard2.push_back(rowVect);

	int liveCount = 0;

	for(int i = 0; i < rows; i++){
  	for(int j = 0; j < columns; j++)
  		tempBoard2 [i + 1][j + 1]= board[i][j];
  }


	for(int i = 0; i < rows; i++){
  	for(int j = 0; j < columns; j++){

			for(int i2 = i; i2 <= i + 2; i2++){
				for(int j2 = j; j2 <= j + 2; j2++){
					if (tempBoard2[i2][j2])
						liveCount++;
				}
			}

			if(tempBoard2[i+1][j+1])
				liveCount--;

			if (board[i][j]){
				if(!(liveCount == 3 || liveCount == 2))
					board[i][j] = false;
  		}

			else{
				if(liveCount ==3)
					board[i][j] = true;
			}

		liveCount = 0;
		}
	}


}



void Lifeboard::print()
{

  for(int j = 0; j < columns + 2; j++)
		cout << "-";
	cout <<endl;
	for(int i = 0; i < rows; i++){
		cout << "|";
		for(int j = 0; j < columns; j++){
			if (board[i][j])
				cout << "X";
			else
				cout << " ";
		}
		cout << "|" << i << endl;

	}
	for(int j = 0; j < columns + 2; j++)
		cout << "-";
	cout <<endl;


}
