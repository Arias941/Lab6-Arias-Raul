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

class Stack : public Container {
private:
    int top;

public:
    Stack() : Container() {
        top = -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Error: Stack Overflow." << endl;
            return;
        }
        data[++top] = value;
        count++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow." << endl;
            return -1;
        }
        count--;
        return data[top--];
    }
};

/*
 * NOTA DEl WORD:
 * Al incrementar front/back sin arreglo circular, las posiciones previas a 'front'
 * no se reutilizaran. La cola va ha reportar estar llena aunque haya espacio libre.
 */
class Queue : public Container {
private:
    int front;
    int back;

public:
    Queue() : Container() {
        front = 0;
        back = -1;
    }

    void enqueue(int value) {
        if (isFull() || back == CAPACITY - 1) {
            cout << "Error: Queue Full." << endl;
            return;
        }
        data[++back] = value;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue Empty." << endl;
            return -1;
        }
        count--;
        return data[front++];
    }
};

class Matrix {
private:
    int cells[3][3];

public:
    Matrix() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cells[i][j] = 0;
            }
        }
    }

    void setValue(int row, int col, int value) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3) {
            cells[row][col] = value;
        }
    }

    int sum() {
        int total = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                total += cells[i][j];
            }
        }
        return total;
    }

    int sumRow(int row) {
        if (row < 0 || row >= 3) return 0;
        int total = 0;
        for (int j = 0; j < 3; j++) {
            total += cells[row][j];
        }
        return total;
    }

    void multiply(Matrix& other, Matrix& result) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.cells[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    result.cells[i][j] += this->cells[i][k] * other.cells[k][j];
                }
            }
        }
    }

    void print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << cells[i][j] << "\t";
            }
            cout << endl;
        }
    }
};