#include <iostream>
#include <math.h>
#include <locale.h>
#include <iomanip>
#include <windows.h>

using namespace std;

struct Elementary_Particles 
{
	string particle;
	char group;
	double charge;
	long float rest_mass;
	Elementary_Particles* next;
};
Elementary_Particles* element, * first, * previous, * element_next, * term;
void CreateTable();
void ShowTable();
void SortTable();

void CreateTable() 
{
	element = new(Elementary_Particles);
	first = element;
	while (true) 
	{
		cout << "Введите: частицу, группу, заряд и массу покоя > \n";
		cin >> element->particle;
		cin >> element->group;
		cin >> element->charge;
		cin >> element->rest_mass;
		if (element->particle != "0" || element->group != '0' || element->charge != 0 || element->rest_mass != 0)
		{
			element->next = new(Elementary_Particles);
			previous = element;
			element = element->next;
		}
		else
		{
			previous->next = NULL;
			break;
		}
	}
}
void ShowTable()
{
	element = first;
	cout << "----------------------------------------------------------" << endl;
	cout << "| " << "Элементарные частицы                                   |" << endl;
	cout << "|--------------------------------------------------------|" << endl;
	cout << "|";
	cout.width(12);
	cout << left << "Частица" << setw(4) << "|" << setw(9) << "Группа" << setw(4) << "|" << setw(9) << "Заряд" << setw(5) << "|" << setw(13) << "Масса покоя" << "|" << "\n";
	cout << "|--------------------------------------------------------|" << endl;
	while (element != NULL)
	{
		cout << "|";
		cout.width(12);
		cout << left << element->particle << setw(6) << "|" << setw(7) << element->group << setw(6) << "|" << setw(7) << element->charge << setw(8) << "|" << setw(10) << element->rest_mass << "|" << "\n";
		element = element->next;
	}
	cout << "----------------------------------------------------------" << endl;
}

void SortTable()
{
	bool unsorted = true;
	while (unsorted)
	{
		unsorted = false;
		element = first;
		previous = NULL;
		while (element != NULL)
		{
			element_next = element->next;
			if (element_next == NULL)
				break;
			if (element_next->particle < element->particle)
			{
				if (element == first)
				{
					first = element_next;
				}
				if (previous != NULL)
				{
					previous->next = element_next;
				}
				previous = element->next;
				term = element_next->next;
				element_next->next = element;
				element->next = term;
				unsorted = true;
			}
			else
			{
				previous = element;
				element = element->next;
			}
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Укажите необходимые данные:  \n";
	cout << "Введите 0, чтобы завершить. \n";
	CreateTable();
	cout << "Создание таблицы: \n";
	ShowTable();
	SortTable();
	cout << endl;
	cout << "Отсортированная таблица: \n";
	ShowTable();
	system("pause");
	return 0;
}