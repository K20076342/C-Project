#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

using std::vector;
using std::set;



// TODO: Your Sudoku class goes here:

class Sudoku
{
private:
    
    int size;

    std::set<int> valuesPair [9][9];

    const std::set<int> totalValues{1,2,3,4,5,6,7,8,9};



public:
	int const N = 9;
	int const n = 3;

	vector <vector<set<int>>>board; 


	//constructor

	Sudoku(vector <vector<set<int>>> &board)
	{
		for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
		{
			setSquare(i,j, int board [i][j]);
		}
	}


	int getSquare(const int &row, const int &col) const {
		// If there is only one value in the set for that square, return the number in that set.
		if (board[i][j].size() == 1) {
			return board[i][j].begin();
		}
		return -1;
	}

	bool setSquare(const int &row, const int &col, const int &value)
	{	
		vector <vector<set<int>>> &cell;
		cell [row][col] = totalValues;

		// the set of possible values for that cell is cleared, and value is inserted. This forces that cell to have that value.
		cell [row][col].clear();
		cell [row][col].insert(value);
 
		// a loop begins, 
		for (int i =0; i<N; i++)
		{
			if (cell[row][i].size()==1 && i!= col && cell [row][i].erase(value)>0)
			{
				return setSquare(row, i, cell[row][i].begin());
			}
		}

		for  (int j =0; j<N; j++)
		{
			if (cell[col][j].size()==1 && j!= row&& cell[col][j].erase(value)>0])
			{
				return setSquare(col, j, cell[col][j].begin());
			}
		}

		int otherRow = row / 3 * 3;
        int otherCol = col / 3 * 3;

        for (int i = otherRow; i < otherRow + 3; i++) {
            for (int j = otherCol; j < otherCol + 3; j++) {
                if (j != row && j != col && cell[i][j].erase(value) > 0 && cell[i][j].size() == 1) {
                    return setSquare(i, j, *valuesPair[i][j].begin());
                }
            }
        }

        return true;

}

	};

#endif
