#include "Doch1.h" // public
int Doch1::fun()
{
	int size = GetSize();	// size получает размер очереди
	int* arr = new int[size];	// под массив arr выдел€етс€ динамическа€ пам€ть размером size 

	for (int i = 0; i < size; i++) {
		int save = pop();	// вытаскиваетс€ элемент из очереди
		arr[i] = save;		// элемент записываетс€ в массив
		this->push(save);	// элемент записываетс€ в конец очереди
	}
	int imin = 0, imax = 0, result = 0, sum = 0, count = 0; // объ€вл€ем переменные

	for (int i = 0; i < size; i++) { // находим минимальный и максимальный элементы массива
		if (arr[i] <= arr[imin]) imin = i;
		if (arr[i] > arr[imax]) imax = i;
	}
	if (imin < imax)	// если мин. элемент идет до макс., то начина€ с мин. элемента прибавл€ть к sum значение массива, после чего увеличивать count.
		for (int i = imin; i <= imax; i++) {
			sum += arr[i];
			count++;
		}
	else // иначе сделать то же самое, но начина€ с макс. элемента.
		for (int i = imax; i <= imin; i++) {
			sum += arr[i];
			count++;
		}
	sum = sum / count * 1.0;	// вывчмисление среднего арифметического.

	for (int i = 0; i < size; i++)	// нахождение первого числа, которое больше среднего арифметического.
		if (arr[i] > sum) {
			result = arr[i]; break;
		}

	delete[] arr;	// освобождение динамической пам€ти.
	return result;
}