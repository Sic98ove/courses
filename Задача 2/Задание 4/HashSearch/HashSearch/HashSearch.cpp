#include "pch.h"
#include <iostream>
#include <set>
#include <time.h>

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "russian");

	std::cout << "Введите количество элементов массива ";
	int count;
	std::cin >> count;
	std::cout << std::endl;

	int *a = new int[count];
	std::set<int> search;					//множество, содержащее элементы с помощью хэша

	for (size_t i = 0; i < count; i++)
	{
		a[i] = rand() % 100 + 1;
		//std::cout << a[i] << std::endl;
		search.insert(a[i]);				//Каждый новый элемент добавляем в множество
	}

	std::cout << std::endl << "Введите значение для поиска ";
	int value;
	std::cin >> value;
	std::cout << std::endl;

	if (search.find(value) != search.end())	//Вызываем find и проверяем, что он указывает не на конец коллекции, если указывает на конец, значит элемент не найден
	{
		std::cout << "Элемент найден";
	}
	else
	{
		std::cout << "Элемент не найден";
	}
}
