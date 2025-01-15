#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class int_array_cell {
public:
    T* data; //�x�s�}�C���Ъ���Ʀ��� 
    int counter; //�p�ƾ������A�Ω�l�ܫ��V�o�Ӱ}�C�����мƶq 

    int_array_cell(T* arr) : data(arr), counter(1) {} //�غc�l�A��l�ƨó]�w�p�ƾ���1 

    ~int_array_cell() { //�Ѻc�l�A�M�Ÿ귽 
        delete[] data;
    }
};

template <typename T>
class counter_ptr {
private:
    char* _name;	//���V�p�ƫ��Ъ��W�٦r�� 
    int_array_cell<T>* cell_ptr;//���Vint_array_cell������ 

public:
    counter_ptr(const char* name, T* arr) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
        cell_ptr = new int_array_cell<T>(arr);
        cout << "int_array_cell is allocated" << endl;
        cout << "counter_ptr " << _name << " is assigned to an int_array_cell: counter " << cell_ptr->counter << endl;
    }

    counter_ptr(const char* name) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
        cell_ptr = nullptr;
        cout << "counter_ptr " << _name << " is not assigned to an int_array_cell" << endl;
    }

    ~counter_ptr() {
        if (cell_ptr != nullptr) {
            cell_ptr->counter--;
            cout << "int_array_cell counter is decreased: counter " << cell_ptr->counter << endl;
            if (cell_ptr->counter == 0) {
                delete cell_ptr;
                cout << "int_array_cell is deallocated" << endl;
            }
        }
        delete[] _name;
        cout << "counter_ptr " << _name << " is deleted" << endl;
    }

    counter_ptr& operator=(const counter_ptr& other) {
        if (this == &other) {
            return *this;
        }

        if (cell_ptr != nullptr) {
            cell_ptr->counter--;
            cout << "int_array_cell counter is decreased: counter " << cell_ptr->counter << endl;
            if (cell_ptr->counter == 0) {
                delete cell_ptr;
                cout << "int_array_cell is deallocated" << endl;
            }
        }

        delete[] _name;
        _name = new char[strlen(other._name) + 1];
        strcpy(_name, other._name);
        cell_ptr = other.cell_ptr;
        cell_ptr->counter++;
        cout << "int_array_cell counter is increased: counter " << cell_ptr->counter << endl;
        cout << "counter_ptr " << _name << " is assigned to an int_array_cell: counter " << cell_ptr->counter << endl;

        return *this;
    }

    counter_ptr& operator=(T* arr) {
        if (cell_ptr != nullptr) {
            cell_ptr->counter--;
            cout << "int_array_cell counter is decreased: counter " << cell_ptr->counter << endl;
            if (cell_ptr->counter == 0) {
                delete cell_ptr;
                cout << "int_array_cell is deallocated" << endl;
            }
        }

        cell_ptr = new int_array_cell<T>(arr);
        cout << "counter_ptr " << _name << " is assigned to an int_array_cell: counter " << cell_ptr->counter << endl;

        return *this;
    }
};

int main() {
    counter_ptr<int> b("b", new int[10]);
    // stdout output: int_array_cell is allocated
    // stdout output: counter_ptr b is assigned to an int_array_cell: counter 1
    b = new int[100];
    // stdout output: int_array_cell counter is decreased: counter 0
    // stdout output: int_array_cell is allocated
    // stdout output: counter_ptr b is assigned to an int_array_cell: counter 1

    counter_ptr<int> a("a");
    // stdout output: counter_ptr a is not assigned to an int_array_cell

    a = b;
    // stdout output: int_array_cell counter is increased: counter 2
    // stdout output: counter_ptr a is assigned to an int_array_cell: counter 2

    // 'a' leaves its scope:
    // stdout output: counter_ptr a is deleted
    // stdout output: int_array_cell counter is decreased: counter 1

    return 0;
}

