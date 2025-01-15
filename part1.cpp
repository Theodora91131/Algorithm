#include <iostream>
#include <cstring>
using namespace std;

class int_array_cell {
public:
    int* data;
    int counter;

    int_array_cell(int* arr) : data(arr), counter(1) {    // 建構函式：初始化 int_array_cell 物件，設定計數器為 1
      //  cout << "int_array_cell is allocated" << endl; // data 指向傳入的整數陣列
    }

    ~int_array_cell() {  // 解構函式：釋放 int_array_cell 物件所持有的整數陣列資源
        delete[] data;
      //  cout << "int_array_cell counter " << counter << ": deleted" << endl;
    }
};

class counter_ptr { 
private:
    char* _name;
    int_array_cell* cell_ptr;

public:
    counter_ptr(const char* name, int* arr) {  // 初始化 counter_ptr 物件，設定計數器為 1，指向傳入的整數陣列
        _name = new char[strlen(name) + 1]; 
        strcpy(_name, name);
        cell_ptr = new int_array_cell(arr);
        cout << "int_array_cell is allocated" << endl;
        cout << "counter_ptr " << _name << " is assigned to an int_array_cell: counter " << cell_ptr->counter << endl;
    }

    counter_ptr(const char* name) {
        _name = new char[strlen(name) + 1]; // 初始化 counter_ptr 物件，不指向任何 int_array_cell 物件
        strcpy(_name, name);
        cell_ptr = nullptr;
        cout << "counter_ptr " << _name << " is not assigned to an int_array_cell" << endl;
    }

    ~counter_ptr() {
        if (cell_ptr != nullptr) {  // 解構函式：釋放資源，遞減計數器，並在計數器為 0 時刪除 int_array_cell 物件
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
	counter_ptr& operator=(const counter_ptr& other) {   // 指派運算子重載：處理計數器的遞增和遞減，指派名稱和指向的 int_array_cell 物件
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
    counter_ptr& operator=(int* arr) { // 指派運算子重載：處理計數器的遞減和遞增，指派名稱和指向的 int_array_cell 物件
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
    // stdout 輸出: int_array_cell is allocated
    // stdout 輸出: counter_ptr b is assigned to an int_array_cell: counter 1
    b = new int[100];
    // stdout 輸出: int_array_cell counter is decreased: counter 0
    // stdout 輸出: int_array_cell is allocated
    // stdout 輸出: counter_ptr b is assigned to an int_array_cell: counter 1

    counter_ptr a("a");
    // stdout 輸出: counter_ptr a is not assigned to an int_array_cell

    a = b;
    // stdout 輸出: int_array_cell counter is increased: counter 2
    // stdout 輸出: counter_ptr a is assigned to an int_array_cell: counter 2

    // a leaves its scope:
    // stdout 輸出: counter_ptr a is deleted
    // stdout 輸出: int_array_cell counter is decreased: counter 1

    return 0;
}
