#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** z, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** z, const int rowCount, const int colCount);
void Sort(int** z, const int rowCount, const int colCount);
void Change(int** z, const int row1, const int row2, const int colCount);
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 18;
	int High = 74;
	int rowCount = 9;
	int colCount = 6;
	int** z = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		z[i] = new int[colCount];
	Create(z, rowCount, colCount, Low, High);
	Print(z, rowCount, colCount);
	Sort(z, rowCount, colCount);
	Print(z, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(z, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(z, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] z[i];
	delete[] z;
	return 0;
}
void Create(int** z, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			z[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** z, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << z[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** z, const int rowCount, const int colCount)
{
	for (int i = 0; i < colCount - 1; i++)
		for (int j = 0; j < colCount - i - 1; j++)
		{
			//за зростанням
			if ((z[0][j] < z[0][j + 1])
				||
				(z[j][0] == z[j + 1][0] &&
					z[j][1] < z[j + 1][1])
				||
				(z[j][0] == z[j + 1][0] &&
					z[j][1] == z[j + 1][1] &&
					z[j][3] > z[j + 1][3]))
			{
				Change(z, j, j + 1, rowCount);
			}
		}
}
void Change(int** z, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int j = 0; j < rowCount; j++)
	{
		tmp = z[col1][j];
		z[col1][j] = z[col2][j];
		z[col2][j] = tmp;
	}
}
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (z[i][j] % 2 == 0 && !(z[i][j] % 7 == 0)) //непарні або кратні 7
			{
				S += z[i][j];
				k++;
				z[i][j] = 0; 
			}
}
