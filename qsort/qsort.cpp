// ConsoleApplication9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <ctime>
using namespace std;


template<typename T>
void quicksort(T *mas, int first, int last)
{
	T mid;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (mas[f]<mid) f++;
		while (mas[l]>mid) l--;
		if (f <= l) //перестановка элементов
		{
			swap(mas[f],mas[l]);
			f++;
			l--;
		}
	} while (f<l);
	if (first<l) quicksort(mas, first, l);
	if (f<last) quicksort(mas, f, last);
}


int main() {

	int i = 0;
	int A[]= {2,4,5,43,2,52,1,3};
	int *p;
	p = A;
	//cout << sizeof(a) / 4 <<endl;
	quicksort(p,0,7);
	while (i < 8)
	{
		cout << A[i] << endl;
		i++;
	}
	cin.get();
	return 0;
}
