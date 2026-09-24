/*
 * Investigacion - Tarea 8: Peso de los algoritmos
 * 1. La notacion Big O mide la complejidad temporal en el peor de los casos (crecimiento segun N).
 * 2. Container::search: Complejidad O(N) porque recorre el arreglo elemento por elemento.
 * 3. Container::sort: Complejidad O(N^2) porque usa Bubble Sort con ciclos anidados.
 * Fuente: GeeksforGeeks / Introduction to Algorithms (CLRS).
 */

#include <iostream>

using namespace std;

const int CAPACITY = 100;

class Container {
protected:
    int data[CAPACITY];
    int count;
    static int containerCount;

public:
    Container() {
        count = 0;
        containerCount++;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == CAPACITY;
    }

    int getCount() {
        return count;
    }

    void print() {
        cout << "[ ";
        for (int i = 0; i < count; i++) {
            cout << data[i] << " ";
        }
        cout << "]" << endl;
    }

    int search(int value) {
        for (int i = 0; i < count; i++) {
            if (data[i] == value) return i;
        }
        return -1;
    }

    int countOccurrences(int value) {
        int occurrences = 0;
        for (int i = 0; i < count; i++) {
            if (data[i] == value) {
                occurrences++;
            }
        }
        return occurrences;
    }

    void sort() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - 1 - i; j++) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    static int getContainerCount() {
        return containerCount;
    }
};

int Container::containerCount = 0;