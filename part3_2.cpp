#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class int_array_cell {
public:
    T* data;
    int counter;

    int_array_cell(T* arr) : data(arr), counter(1) {}

    ~int_array_cell() {
        delete[] data;
    }
};

template <typename T>
class counter_ptr {
private:
    char* _name;
    int_array_cell<T>* cell_ptr;

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

    T& operator[](int index) {
        return cell_ptr->data[index];
    }

    const T& operator[](int index) const {
        return cell_ptr->data[index];
    }

    void release() {
    if (cell_ptr != nullptr) {
        cell_ptr->counter--;
        cout << "int_array_cell counter is decreased: counter " << cell_ptr->counter << endl;
           if (cell_ptr->counter == 0) {
                delete cell_ptr;
                cout << "int_array_cell is deallocated" << endl;
            }
            cell_ptr = nullptr;  
            cout << "counter_ptr " << _name << " is not assigned to an int_array_cell" << endl;
        }
    }
};

int main() {
    counter_ptr<int> b("b", new int[10]);
    for (int i = 0; i < 10; i++)
        b[i] = i;

    for (int i = 0; i < 10; i++)
        cout << b[i] << ' ';
    cout << endl;

    counter_ptr<int> c("c");
    c = b;

    b.release();

    return 0;
}
