#include <iostream>
#include <list>

using namespace std;

int startProgram() {
    int option = -1;
    cout << "Select an option" << endl;
    cout << "(1) Print list" << endl;
    cout << "(2) Insert to list" << endl;
    cout << "(3) Erase from list" << endl;
    cout << "(4) Quit program" << endl;
    cin >> option;
    return option;
}

void printList(list<int> toPrint) {
    for (list<int>::iterator it = toPrint.begin(); it != toPrint.end(); it++) {
        cout << *it << " " << flush;
    }
    cout << endl;
}

int main() {

    // Lists contain nodes which stores each element and are linked to each other by pointers

    list<int> numbers;
    int option;
    int insertOption = -1;
    int numberToInsert = 0;
    int deleteIndex = 0;

    // Program to interact with lists
    do {
        option = startProgram();

        if (option == 1) {
            if (numbers.size() == 0) {
                cout << "List is empty, insert some numbers first" << endl;
            } else {
                cout << "=== Printing list ===" << endl;
                printList(numbers);
            }

        } else if (option == 2) {
            cout << "Select to insert from the FRONT (0) or the BACK (1):" << endl;
            cin >> insertOption;
            cout << "Enter number to insert" << endl;
            cin >> numberToInsert;
            if (insertOption == 0) {
                numbers.push_front(numberToInsert);
            } else if (insertOption == 1) {
                numbers.push_back(numberToInsert);
            }

        } else if (option == 3) {
            if (numbers.size() == 0) {
                cout << "List is empty, insert some numbers first" << endl;
            } else {
                do {
                    cout << "Enter the index of the element to delete:" << endl;
                    cin >> deleteIndex;
                    if (deleteIndex >= numbers.size()) {
                        cout << "Index out of range of list size, which is: " << numbers.size() << endl;
                        continue;
                    }
                    list<int>::iterator it = numbers.begin();

                    for (int i = 0; i < deleteIndex; i++) {
                        it++;
                    }

                    cout << "Deleting '" << *it << "' from list" << endl;
                    numbers.erase(it);
                    break;

                } while (true);
            }

        } else if (option == 4) {
            cout << "Exiting program..." << endl;
            break;

        } else {
            cout << "Unknown option, exiting program..." << endl;
            break;
        }

    } while (true);

    // Experimentation
    list<int> numbers2;

    numbers2.push_back(1);
    numbers2.push_back(2);
    numbers2.push_back(3);
    numbers2.push_front(0);

    // Inserting a new element to a list
    list<int>::iterator it = numbers2.begin();
    it++;
    numbers2.insert(it, 100);
    cout << "Element: " << *it << endl;

    // Erasing element
    list<int>::iterator eraseIt = numbers2.begin();
    eraseIt++;

    // .erase() returns an iterator to the next element in the list
    eraseIt = numbers2.erase(eraseIt);
    cout << "Element: " << *eraseIt << endl;

    for (list<int>::iterator it = numbers2.begin(); it != numbers2.end();) {
        if (*it == 2) {
            numbers2.insert(it, 1234);
        }
        if (*it == 1) {
            it = numbers2.erase(it);
        } else {
            it++;
        }
    }

    for (list<int>::iterator it = numbers2.begin(); it != numbers2.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}