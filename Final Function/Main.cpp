#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>

//Заполнение массива случайными числами
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
		for (int i = 0; i < length; i++)
			arr[i] = rand() % (right - left) + left;
}

//Вывод массива
template <typename T>
void print_arr(T arr[], const int length){
	std::cout << "{";
	for (int i = 0; i < length;i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b}\n";
}

template<typename T>
void middle_sort(T arr[], const int lenght);
template<typename T>
void move_arr(T arr[], const int lenght, int steps);

void typeof(int num) { std::cout << "INT\n"; }
void typeof(double num) { std::cout << "DOUBLE\n"; }
void typeof(char num) { std::cout << "CHAR\n"; }

int sum_AB(int A, int B);// прототип функции sum_AB;



int main() {
	setlocale(LC_ALL, "ru");
	int n,m;

	//Задача 1. Тип данныых числа
	/*std::cout << " Задача 1\n";
	std::cout << " 7 - "; typeof(7);
	std::cout << " 0.15 - "; typeof(0.15);
	std::cout << "'E' - "; typeof('E');
	std::cout << std::endl;*/

	//Задача 2. Рекурсивная сумма диапазона.
	/*std::cout << " Задача 2.\n Введите начало диапазона ->";
	std::cin >> n;
	std::cout << " Введите конец диапазона ->";
	std::cin >> m;
	std::cout << " Сумма чисел от " << n << " до " << m << " = " << sum_AB(n, m) << "\n\n";*/

	//Задача 3. Сортировка середины.

	/*std::cout << " Выводиться изначальный массив:\n";
	const int size3 = 10;
	int arr3[size3]{};
	fill_arr(arr3, size3, -20, 21);
	print_arr(arr3, size3);
	middle_sort(arr3, size3);
	std::cout << " Итоговый массив \n";
	print_arr(arr3, size3);*/

	//Задача 4. Циклический сдвиг массива.
	std::cout << " Изначальный массив\n";
	const int size4 = 5;
	int arr4[size4]{ 1,2,3,4,5 };
	print_arr( arr4, size4);
	std::cout << " ВВедите кол-во сдвигов -> ";
	std::cin >> n;
	move_arr(arr4, size4, n);
	std::cout << " Итоговый массив\n";
	print_arr(arr4, size4);


	return 0;
}



//Реализация функции sum_AB;
int sum_AB(int A, int B) {
	if (A > B)
		std::swap(A, B);
	if (A == B)
		return A;
	return sum_AB(A, B - 1)+B;
}
//Сортировка середины
template<typename T>
void middle_sort(T arr[], const int lenght) {
	int first_negative = -1, last_negative= -1;
	for (int i = 0; i < lenght; i++)
		if (arr[i] < 0) {
			first_negative = i;
			break;
		}
	for (int i = lenght-1; i >=0; i--)
		if (arr[i] < 0) {
			last_negative = i;
			break;
		}
	//Пузырьковая сортировка
	/*for (int i = last_negative - 1; i > first_negative + 1; i--)
		for (int j = first_negative+1; j < i; j++)
			if(arr[j]>arr[j+1])
			std::swap(arr[j], arr[j + 1]);*/

	//Быстрая сортировка.
	if(first_negative != -1 && first_negative != last_negative)
		std::sort(arr + first_negative + 1, arr + last_negative - 1);
}



//Циклический сдвиг
template<typename T>
void move_arr(T arr[], const int lenght, int steps) {
	if (steps > 0) {
		for (int j = 0; j < steps; j++)
			for (int i = 0; i > lenght; i++)
				std::swap(arr[i + 1], arr[i]);
	}
	if(steps < 0)
		for(int j = 0;j < -steps;j++)
			for (int i = 0; i < lenght-1; i++)
				std::swap(arr[i], arr[i + 1]);
	
}


