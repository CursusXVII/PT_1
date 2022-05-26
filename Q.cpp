#include "Q.h"
using namespace std;

Q::Q() { // конструктор без параметра(по-умолчанию)
	size = 0;
	tail = nullptr;
}

Q::Q(int data) { // конструктор с параметром
	size = 1;
	tail = nullptr;
	tail = new Element{ data, tail };
}

void Q::push(int data) {	// ввод чисел
	tail = new Element{ data, tail };
	size++;
}

int Q::GetSize() { // размер очереди
	return size;
}

int Q::pop() {	// удаление чисел из очереди по порядку
	try {
		Element *iterator = tail;// Сохраняет первый элемент очереди в отдельную переменную
		Element *prevElement = iterator;
		//if (tail == nullptr) throw (404);
		while (iterator->pNext != nullptr) {// сдвигает остальные элементы на одну позицию в памяти к началу
			prevElement = iterator;
			iterator = iterator->pNext;
		}
		prevElement->pNext = nullptr;
		int save = iterator->data;
		delete iterator;
		size--;	//уменьшает счетчик элементов size
		if (size == 0) tail = nullptr;
		return save;
	}
	catch (int val) { cout << "Mistake! The queue is empty." << endl; }
}

void Q::Qprint() // вывод очереди на экран
{
	int i = size;	
	int save = 0;
	while (i != 0) {	// Посредством функции pop извлекаем элемент из очереди
		save = this->pop();
		cout << save << " ";	// через функцию cout выводим его на экран
		this->push(save);	// возвращаем через функцию push обратно в очередь
		i--;
	}
	cout << endl;
}

Q*Q::copy()  // копирование очереди
{
	Q*queue = new Q();
	int i = this->size;	
	int save = 0;
	while (i != 0) {	// Для копирования используется функция pop и возвращается элемент дважды
		save = this->pop();
		queue->push(save);	// в основную очередь 
		this->push(save);	// и в ее копию через функцию push - Новый экземпляр класса «очередь»
		i--;
	}
	return queue;
}

Q*Q::merge(Q *first, Q *second) // слияне очередей
{
	Q*FirstQueue = first;
	Q*SecondQueue = second;
	int i = SecondQueue->size;
	while (i > 0) {	// Добавляет скопированную очередь в конец основной очереди
		int save = SecondQueue->pop();	// посредством извлечения из скопированной очереди элементов через функцию pop
		FirstQueue->push(save);	// и добавлением при помощи функции push в основную
		i--;
	}
	FirstQueue->Qprint();
	delete SecondQueue;
	return FirstQueue;
}

Q::~Q() {	// деструктор
	this->tail = nullptr;
	size = 0;
}