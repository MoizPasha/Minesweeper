#include "Button.h"

class console
{
public:
	console();
	console(int , int );
	void fill(int,int);
	void placemine(int,int);
	/*int mine_found(int,int);*/
	void reset()
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				screen[i][j] = 10;
	}
	~console();

public:
	int** screen;
	int cols;
	int rows;
	tile* arr;
};

console::console()
{
	arr = nullptr;
	screen = nullptr;
	cols = 0;
	rows = 0;
}
console::console(int r, int c)
{
	arr = nullptr;
	rows = r;
	cols = c;
	screen = new int* [rows];
	for (int i = 0; i < rows; i++)
		screen[i] = new int[cols];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			screen[i][j] = 10;
	}
}
console::~console()
{
	for (int i = 0; i < rows; i++)
		delete[]screen[i];
	delete screen;
	delete arr;
}
void console::placemine(int r, int c)
{
	int i = -1;
	int j = 2;
	if (r - 1 < 0)
		i = 0;
	if (!(r + 1 < rows))
		j = 1;
	for (; i < j; i++)
	{
		if (c > 0 && screen[r + i][c - 1] != -1)
		{
			screen[r + i][c - 1]++;
		}
		if ((c + 1) < cols&&screen[r + i][c + 1] != -1)
			screen[r + i][c + 1]++;
		if (screen[r + i][c] != -1)
			screen[r + i][c]++;
	}
	screen[r][c] = -1;
}
//int console::mine_found(int r, int c)
//{
//	int mines = 0;
//	if (c > 0)
//	{
//		if (r + 1 < rows && screen[r + 1][c - 1] == -1)
//			mines++;
//		if (screen[r][c - 1] == -1)
//			mines++;
//		if (r > 0 && screen[r - 1][c - 1] == -1)
//			mines++;
//	}
//	if (c + 1 < cols)
//	{
//		if (r + 1 < rows && screen[r + 1][c + 1] == -1)
//			mines++;
//		if (r > 0&&screen[r - 1][c + 1] == -1)
//			mines++;
//		if (screen[r][c + 1] == -1)
//			mines++;
//	}
//	if ( r > 0 && screen[r - 1][c] == -1)
//			mines++;
//	if (r + 1 < rows && screen[r + 1][c] == -1)
//		mines++;
//	return mines;
//
//}
void console::fill(int r, int c)
{
	int height;
	if (r == 0)
		height = 0;
	else
		 height = rand() % r;
	int depth =1+ r + rand() % (rows - r);
	int	l_col;
	if (c == 0)
		l_col = 0;
	else
		l_col = rand() % c;
	int r_col = c + rand() % (cols - c) + 1;

	for (int i = height; i < depth; i++)
	{
		for (int j = l_col; j < r_col; j++)
			screen[i][j] = 0;
	}
	for (int i = 0; i < rows; i++)
	{
		if (i >= height && i < depth - 1)
		{
			for (int j = 0; j < l_col; j++)
			{
				if (rand() % 2 == 1)
					placemine(i, j);
			}
			for (int j = r_col; j < cols; j++)
			{
				if (rand() % 2 == 1)
					placemine(i, j);
			}
		}
		else
			for (int j = 0; j < cols; j++)
				if (rand() % 2 == 1)
					placemine(i, j);
	}
	
	
	for (int j = l_col,i=height; j < r_col; j++)
		if (screen[i][j] == 0)
			placemine(i, j);
	for (int i = height; i < depth; i++)
		if (screen[i][l_col] == 0)
			placemine(i, l_col);
	int j = r_col - 1;
	for (int i = height; i < depth; i++)
		if (screen[i][j] == 0)
			placemine(i, j);
	for (int j = l_col, i = depth-1; j < r_col; j++)
		if (screen[i][j] == 0)
			placemine(i, j);

}