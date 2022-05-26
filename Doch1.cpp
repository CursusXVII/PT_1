#include "Doch1.h" // public
int Doch1::fun()
{
	int size = GetSize();	// size �������� ������ �������
	int* arr = new int[size];	// ��� ������ arr ���������� ������������ ������ �������� size 

	for (int i = 0; i < size; i++) {
		int save = pop();	// ������������� ������� �� �������
		arr[i] = save;		// ������� ������������ � ������
		this->push(save);	// ������� ������������ � ����� �������
	}
	int imin = 0, imax = 0, result = 0, sum = 0, count = 0; // ��������� ����������

	for (int i = 0; i < size; i++) { // ������� ����������� � ������������ �������� �������
		if (arr[i] <= arr[imin]) imin = i;
		if (arr[i] > arr[imax]) imax = i;
	}
	if (imin < imax)	// ���� ���. ������� ���� �� ����., �� ������� � ���. �������� ���������� � sum �������� �������, ����� ���� ����������� count.
		for (int i = imin; i <= imax; i++) {
			sum += arr[i];
			count++;
		}
	else // ����� ������� �� �� �����, �� ������� � ����. ��������.
		for (int i = imax; i <= imin; i++) {
			sum += arr[i];
			count++;
		}
	sum = sum / count * 1.0;	// ������������ �������� ���������������.

	for (int i = 0; i < size; i++)	// ���������� ������� �����, ������� ������ �������� ���������������.
		if (arr[i] > sum) {
			result = arr[i]; break;
		}

	delete[] arr;	// ������������ ������������ ������.
	return result;
}