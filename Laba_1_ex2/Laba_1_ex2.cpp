﻿
#include <iostream>
#include <iomanip>
using namespace std;
//Генерим одомерный массив
void oneD_Array(double* array,  int oneDlen) {

	for (int i = 0; i < oneDlen; i++){
	
		array[i] = i * sin(3.1415 * i / 25);//заполнение массива числами
		
		cout << array[i] << " ";
	}
}

double** twoD_Array(double* array1D, int twoDlen)
{
	double** arr2D = new double* [twoDlen]; // выделяем память под выходной массив 
	
	for (unsigned int i = 0; i < twoDlen; ++i){
	//еще под каждую строку\ряд
		*(arr2D + i) = new double[twoDlen];
	}
	
	for (unsigned int i = 0; i < twoDlen; ++i){
	
		for (int j = 0; j < twoDlen; ++j){
		
			 *(*(arr2D + i) + j) = *(array1D + i * twoDlen + j);
			
		}
	}

	for (int i = 0; i < twoDlen; i++) {
	
		for (int j = 0; j < twoDlen; j++) {

			if (j==0){//проверка на первый элемент 

				arr2D[i][j] = arr2D[i][j+1] + arr2D[i][j+2] + arr2D[i][j+3]; //сумма элементов массива. Первый элемент содержит сумму остальных
			}
		}
	}

	for (int i = 0; i < twoDlen; i++) {
	
		for (int j = 0; j < twoDlen; j++) {
		
			/*cout << " |" << arr2D[i][j] << "  |  ";*/\

			cout << setw(10) << arr2D[i][j] << "|";//вывод массива. выделение 10 позиций на каждый элемент массива
		}
		cout << "\n";
	}
	for (int i = 0; i < twoDlen; i++) //если не работает , то надо удалить. Пушил вручную, гит отказывался коммитить 
	{
		return arr2D;
		delete[] arr2D[i];
	}
	
}

int main()
{
	setlocale(LC_ALL, "ru");

	const unsigned int oneDlen = 25;
	const unsigned  int twoDlen = 5;

	double array1D[oneDlen];

	oneD_Array(array1D, oneDlen);
	cout<<"\n\n\n\n" << "\n";
	twoD_Array(array1D, twoDlen );
}

