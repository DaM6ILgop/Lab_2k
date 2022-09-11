// Laba_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void processArray(double array[], unsigned int N, int negElement[], unsigned int len2) {

	cout << "Массив заполненный рандомно" << "\n";
	for (int i = 0; i < N;i++) {
		array[i] = (double)(rand() % 30) - 15.0; //Заполнение массива числами в диапазоне от -15 до 15
		cout << array[i] << " ";
	}
	
	double average = 0.0;
	//Поиск среднего значения в массиве
	for (int i = 0; i < N; i++) {
		average += array[i];
	}

	average /= N;

	cout << "\nСреднее значение в массиве " << "\n";
	cout << average << "\n";

	cout << "\n" << " ";
		int a;
		int b;
	//Проверка на число положительное\отрицательное 
	cout << "Введите первое число диапазона. Число должно быть меньше нуля" <<"\n";
	cin >> a;
	while ( a >= 0) {
		cout << "Число должно быть меньше нуля! " << "\n";
		cin >> a;
	}

	cout << "Введите второе число диапазона. Число должно быть больше нуля "<<"\n";
	cin>> b;

	while (b <= 0) {
		cout << "Число должно быть больше нуля! " << "\n";
		cin >> b;
	}

	cout<<"\n" << "";

	int count = 0;
	cout<<"Перемноженный массив" << "\n";
	for (int i = 0; i < N; i++) {
		
		if ((i+1) % 2 == 0) { //проверка на четность индекса 
			array[i] = array[i] * (a + rand() % (b - a + 1)); //перемножение элементов с четными индыксами на случайное число из диапазона 
		}
		cout << array[i] << " ";

		if (array[i] < 0) { //присвоение отрицательных элементов массива в новый массив
			count++;
			negElement[i] = array[i];
		}
	}

	cout << "\nотрицательные элементы ==>:" << " ";
	cout<<count<<"\n";

	for (int i = 0; i < len2; i++){
		cout<<negElement[i] << " ";
	}
}	

int main()
{
	setlocale(LC_ALL, "ru"); //чтобы вывод на консоль не выдавал мусорные значения 
	const unsigned int len = 15;
	double array[len] = { 0,0 };
	const int len2 = 20;
	int negatElement[len2] = { 0,0 };
	srand(time(NULL)); //нужно для генерации чисел 
	processArray(array, len, negatElement, len2);
}

