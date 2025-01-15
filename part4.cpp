#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
// BIG5漢字類別 
class character {
public:
    signed char data[2];
	//初始化BIG5 
    character(signed char c1, signed char c2) {
        data[0] = c1;
        data[1] = c2;
    }
	//比較兩個BIG5漢字是否相等 
    bool operator==(const character& other) const {
        return data[0] == other.data[0] && data[1] == other.data[1];
    }

    friend ostream& operator<<(ostream& os, const character& c);
};

ostream& operator<<(ostream& os, const character& c) {
    os << c.data[0] << c.data[1];
    return os;
}

template <typename T> //實作堆疊 
class counter_ptr {
private:
    vector<T*> stack;

public:
    void push(T* item) {
        stack.push_back(item);
    }

    T* pop() {
        if (stack.empty()) {
            return nullptr;
        }
        T* item = stack.back();
        stack.pop_back();
        return item;
    }
	//判斷堆疊是否包含指定元素 
    bool contains(const T& item) const {
        for (const T* ptr : stack) {
            if (*ptr == item) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        for (T* ptr : stack) {
            delete ptr;
        }
        stack.clear();
    }
	//列印堆疊中的資料 
    void printData() const {
        for (const T* ptr : stack) {
            cout << *ptr << ' ';
        }
        cout << endl;
    }
	
    void printCode() const {
        for (const T* ptr : stack) {
            cout << "(" << static_cast<int>(ptr->data[0]) << " " << static_cast<int>(ptr->data[1]) << ") ";
        }
        cout << endl;
    }
	//解構子，清空堆疊 
    ~counter_ptr() {
        clear();
    }
};

int main() {
    counter_ptr<character> stack;
    string input;

    while (true) {
        getline(cin, input);
        if (input.empty()) {
            continue;
        }
        char command = input[0];

        if (command == 'I') { //輸入資料 
            string str = input.substr(2);
            const char* str_cstr = str.c_str();
            size_t str_length = strlen(str_cstr);
            if (str_length % 2 == 0) {
                for (size_t i = 0; i < str_length; i += 2) {
                    signed char c1 = static_cast<signed char>(str_cstr[i]);
                    signed char c2 = static_cast<signed char>(str_cstr[i + 1]);
                    character* item = new character(c1, c2);
                    stack.push(item);
                }
            }
        }
        else if (command == 'P') { // 列印堆疊資料 
            stack.printData();
        }
        else if (command == 'B') { //列印堆疊內碼 
            stack.printCode();
        }
        else if (command == 'R') {  //拿最後一個資料 
            character* item = stack.pop();
            if (item != nullptr) {
                delete item;
            }
        }
        else if (command == 'C') { //清空資料 
            stack.clear();
        }
        else if (command == '?') {//查詢資料是否存在 
            signed char c1 = static_cast<signed char>(input[2]);
            signed char c2 = static_cast<signed char>(input[3]);
            character searchItem(c1, c2);
            if (stack.contains(searchItem)) {
                cout <<"是" << endl;
        	}
        	else {
            	cout << "否" << endl;
        	}	
    	}
	}

	return 0;
}

