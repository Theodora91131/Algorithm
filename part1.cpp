#include <iostream>
#include <cstring>
using namespace std;

class int_array_cell {
public:
    int* data;
    int counter;

    int_array_cell(int* arr) : data(arr), counter(1) {    // �غc�禡�G��l�� int_array_cell ����A�]�w�p�ƾ��� 1
      //  cout << "int_array_cell is allocated" << endl; // data ���V�ǤJ����ư}�C
    }

    ~int_array_cell() {  // �Ѻc�禡�G���� int_array_cell ����ҫ�������ư}�C�귽
        delete[] data;
      //  cout << "int_array_cell counter " << counter << ": deleted" << endl;
    }
};

class counter_ptr { 
private:
    char* _name;
    int_array_cell* cell_ptr;

public:
    counter_ptr(const char* name, int* arr) {  // ��l�� counter_ptr ����A�]�w�p�ƾ��� 1�A���V�ǤJ����ư}�C
        _name = new char[strlen(name) + 1]; 
        strcpy(_name, name);
        cell_ptr = new int_array_cell(arr);
        cout << "int_array_cell is allocated" << endl;
        cout << "counter_ptr " << _name << " is assigned to an int_array_cell: counter " << cell_ptr->counter << endl;
    }

    counter_ptr(const char* name) {
        _name = new char[strlen(name) + 1]; // ��l�� counter_ptr ����A�����V���� int_array_cell ����
        strcpy(_name, name);
        cell_ptr = nullptr;
        cout << "counter_ptr " << _name << " is not assigned to an int_array_cell" << endl;
    }

    ~counter_ptr() {
        if (cell_ptr != nullptr) {  // �Ѻc�禡�G����귽�A����p�ƾ��A�æb�p�ƾ��� 0 �ɧR�� int_array_cell ����
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
	counter_ptr& operator=(const counter_ptr& other) {   // �����B��l�����G�B�z�p�ƾ������W�M����A�����W�٩M���V�� int_array_cell ����
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
    counter_ptr& operator=(int* arr) { // �����B��l�����G�B�z�p�ƾ�������M���W�A�����W�٩M���V�� int_array_cell ����
        if (cell_ptr != nullptr) {
            cell_ptr->counter--;
            cout << "int_array_cell counter is decreased: counter " << cell_ptr->counter << endl;
            if (cell_ptr->counter == 0) {
                delete cell_ptr;
                cout << "int_array_cell is deallocated" << endl;
            }
        }

        cell_ptr = new int_array_cell(arr);
        cout << "counter_ptr " << _name << " is assigned to an int_array_cell: counter " << cell_ptr->counter << endl;

        return *this;
    }

    
};

int main() {
    counter_ptr b("b", new int[10]);
    // stdout ��X: int_array_cell is allocated
    // stdout ��X: counter_ptr b is assigned to an int_array_cell: counter 1
    b = new int[100];
    // stdout ��X: int_array_cell counter is decreased: counter 0
    // stdout ��X: int_array_cell is allocated
    // stdout ��X: counter_ptr b is assigned to an int_array_cell: counter 1

    counter_ptr a("a");
    // stdout ��X: counter_ptr a is not assigned to an int_array_cell

    a = b;
    // stdout ��X: int_array_cell counter is increased: counter 2
    // stdout ��X: counter_ptr a is assigned to an int_array_cell: counter 2

    // a leaves its scope:
    // stdout ��X: counter_ptr a is deleted
    // stdout ��X: int_array_cell counter is decreased: counter 1

    return 0;
}
