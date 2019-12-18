#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <chrono>

int const SIZE = 1000;
long a[SIZE][SIZE]; // матрица смежности


int main()
{
	//srand(time(NULL));
	int D[SIZE] = { 0 }; // минимальное рассто€ние
	int prev[SIZE] = { 0 }; // посещенные вершины
	int t = 0; // врем€ работы алгоритма
	int temp, minindex, min, count, j, c;
	int begin_index = 0;
	
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int m = 0; m < SIZE; m++)
		{
			a[i][m] = { 0 }; // матрица смежности

		}
	}
		// »нициализаци€ матрицы св€зей
	for (int i = 0; i < (SIZE - 1); i++)
	{
		count = rand() % (SIZE - 1) + 1; //число вершин, смежных i
		for (int m = 0; m < count; m++)
		{
			j = 1 + rand() % (SIZE - 1); //номер вершины, смежной с i
			if ((a[j][i] == 0) && (j != i)) { //проверка на отсутствие петель
				a[i][j] = 1 + rand() % 30;
			}
		}
	}
	//»нициализаци€ вершин и рассто€ний
	for (int l = 0; l < 50; l++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			D[i] = 10000;
			prev[i] = 1;
		}
		D[begin_index] = 0;
		//—тарт секундомера
		auto begin = std::chrono::steady_clock::now();
		// Ўаг алгоритма
		do {
			minindex = 10000;
			min = 10000;
			for (int i = 0; i < SIZE; i++)
			{ // ≈сли вершину ещЄ не обошли и вес меньше min
				if ((prev[i] == 1) && (D[i] < min))
				{ // ѕереприсваиваем значени€
					min = D[i];
					minindex = i;
				}
			}
			// ƒобавл€ем найденный минимальный к текущему весу вершины и сравниваем с текущим минимальным весом вершины
			if (minindex != 10000)
			{
				for (int i = 0; i < SIZE; i++)
				{
					if (a[minindex][i] > 0)
					{
						temp = min + a[minindex][i];
						if (temp < D[i])
						{
							D[i] = temp;
						}
					}
				}
				prev[minindex] = 0;
			}
		} while (minindex < 10000);
		auto end = std::chrono::steady_clock::now();

		auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
		t = t + elapsed_ms.count();
		std::cout << "The time: " << elapsed_ms.count() << " n\n";

	}
	std::cout << t / 50 << std::endl;
	getchar(); getchar();
	return 0;
}