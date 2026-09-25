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

int main() {
    Stack stack;
    Queue queue;
    Matrix mat1, mat2, matResult;

    int option = 0;
    while (option != 12) {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Push to Stack" << endl;
        cout << "2. Pop from Stack" << endl;
        cout << "3. Enqueue to Queue" << endl;
        cout << "4. Dequeue from Queue" << endl;
        cout << "5. Search value in Stack" << endl;
        cout << "6. Count occurrences in Stack" << endl;
        cout << "7. Sort copy of Stack (keeps original)" << endl;
        cout << "8. Print Stack and Queue" << endl;
        cout << "9. Fill and display Matrices" << endl;
        cout << "10. Multiply Matrices" << endl;
        cout << "11. Display total Containers created" << endl;
        cout << "12. Exit" << endl;
        cout << "Option: ";
        cin >> option;

        if (option == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            stack.push(val);
        }
        else if (option == 2) {
            int val = stack.pop();
            if (val != -1) cout << "Extracted value from Stack: " << val << endl;
        }
        else if (option == 3) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            queue.enqueue(val);
        }
        else if (option == 4) {
            int val = queue.dequeue();
            if (val != -1) cout << "Extracted value from Queue: " << val << endl;
        }
        else if (option == 5) {
            int val;
            cout << "Value to search in Stack: ";
            cin >> val;
            int idx = stack.search(val);
            if (idx != -1) cout << "Found at index: " << idx << endl;
            else cout << "Not found." << endl;
        }
        else if (option == 6) {
            int val;
            cout << "Value to count: ";
            cin >> val;
            cout << "Occurrences: " << stack.countOccurrences(val) << endl;
        }
        else if (option == 7) {
            Container sortedStack = stack;
            sortedStack.sort();
            cout << "Original Stack: ";
            stack.print();
            cout << "Sorted Copy: ";
            sortedStack.print();
        }
        else if (option == 8) {
            cout << "Current Stack: ";
            stack.print();
            cout << "Current Queue: ";
            queue.print();
        }
        else if (option == 9) {
            cout << "Initializing Matrix 1..." << endl;
            mat1.setValue(0, 0, 1); mat1.setValue(0, 1, 2); mat1.setValue(0, 2, 3);
            mat1.setValue(1, 0, 4); mat1.setValue(1, 1, 5); mat1.setValue(1, 2, 6);
            mat1.setValue(2, 0, 7); mat1.setValue(2, 1, 8); mat1.setValue(2, 2, 9);

            cout << "Initializing Matrix 2 (Identity)..." << endl;
            mat2.setValue(0, 0, 1); mat2.setValue(0, 1, 0); mat2.setValue(0, 2, 0);
            mat2.setValue(1, 0, 0); mat2.setValue(1, 1, 1); mat2.setValue(1, 2, 0);
            mat2.setValue(2, 0, 0); mat2.setValue(2, 1, 0); mat2.setValue(2, 2, 1);

            cout << "Matrix 1:" << endl; mat1.print();
            cout << "Matrix 1 Sum: " << mat1.sum() << endl;
            cout << "Matrix 1 Row 0 Sum: " << mat1.sumRow(0) << endl;
        }
        else if (option == 10) {
            mat1.multiply(mat2, matResult);
            cout << "Result of Matrix 1 x Matrix 2:" << endl;
            matResult.print();
        }
        else if (option == 11) {
            cout << "Total containers instantiated: " << Container::getContainerCount() << endl;
        }
    }

    return 0;
}