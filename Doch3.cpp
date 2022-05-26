#include "Doch3.h" // private
int Doch3::fun()
{
	int size = GetSize();
	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		int save = pop();
		arr[i] = save;
		this->push(save);
	}

	int imin = 0, imax = 0, result = 0, sum = 0, count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] <= arr[imin]) imin = i;
		if (arr[i] > arr[imax]) imax = i;	
	}

	if (imin < imax)
		for (int i = imin; i <= imax; i++) {
			sum += arr[i];
			count++;
		}
	else 
		for (int i = imax; i <= imin; i++) {
			sum += arr[i];
			count++;
		}

	sum = sum / count * 1.0;

	for (int i = 0; i < size; i++)
		if (arr[i] > sum) {
			result = arr[i]; break;
		}

	delete[] arr;
	return result;
}

void Doch3::push(int data) {
	Q::push(data);
}

int Doch3::pop() {
	return Q::pop();
}

void Doch3::show() {
	Q::Qprint();
}

Q* Doch3::copy() {
	return Q::copy();
}

int Doch3::GetSize() {
	return Q::GetSize();
}

Q* Doch3::merge(Q* first, Q* second) {
	return Q::merge(first, second);
}