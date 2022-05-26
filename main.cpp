#include "Doch1.h"
#include "Doch2.h"
#include "Doch3.h"
using namespace std;

int main() {
	int option;

	cout << "Choose the type of inheritance" << endl << "1 - Public" << endl << "2 - Protected" << endl << "3 - Private" << endl;

	Doch1 queue = Doch1();

	while (true) {

		system("cls"); // очищает экран консоли
		cout << "1 - Adding a new option" << endl << "2 - Retrieving the selected item " << endl << "3 - Displaying the queue on the screen" << endl << "4 - Finding the first element is greater than the arithmetic mean" << endl << "5 - Creating a copy of the queue" << endl << "6 - Merging queues" << endl << "7 - Exit" << endl;
		cin >> option;
		system("cls");

		switch (option) {
		case 1:
			int component;
			cout << "Adding a new option " << endl; 
			cin >> component;
			queue.push(component);
			cout << "Option " << component << " introduced" << endl;
			system("pause"); break;
		case 2:
			cout << "Retrieving the selected item " << queue.pop() << endl;
			system("pause"); break;
		case 3:
			queue.Qprint();
			system("pause"); break;
		case 4:
			cout << "The first element is greater than the arithmetic mean " << queue.fun() << endl;
			system("pause"); break;
		case 5:
			cout << "Creating a copy of the queue " << endl;
			queue.copy();
			system("pause"); break;
		case 6:
			Q * a = queue.copy();
			Q* b = queue.copy();
			queue.merge(a, b);
			system("pause"); break;
		}
		if (option == 7) break;
	}
}