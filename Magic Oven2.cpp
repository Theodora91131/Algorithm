#include <iostream>
#include <string>
#include <queue>
using namespace std;

priority_queue <int> max_bakery;
priority_queue <int, vector<int>, greater<int>> min_bakery;

int main() {
 int num, input_data, count = 1, total_count = 0;
 cin >> num;

 for (int i = 0; i < num; i++) {
  string operation;
  cin >> operation;

  if (operation == "DIOU") {
   cin >> input_data;
   total_count += 1;
   if (min_bakery.empty() || min_bakery.top() > input_data) {
    max_bakery.push(input_data);
   } else {
    min_bakery.push(input_data);
   }
  }
  else if (operation == "MUMIMUMI") {
   if (count <= 0 || count > total_count) {
    cout << "BAONU" << endl;
   }
   else if (min_bakery.size() == count - 1) { cout << max_bakery.top() << endl; }
   else {
    while (min_bakery.size() < count - 1) {
     min_bakery.push(max_bakery.top());
     max_bakery.pop();
    }
    while (min_bakery.size() > count - 1) {
     max_bakery.push(min_bakery.top());
     min_bakery.pop();
    }
    cout << max_bakery.top() << endl;
   }
   count++;
  }
  else if (operation == "<3DONGDONG") {
   if (count <= 0 || count > total_count) { cout << "BAONU" << endl; }
   else if (min_bakery.size() == count - 1) { cout << max_bakery.top() << endl; }
   else {
    while (min_bakery.size() < count - 1) {
     min_bakery.push(max_bakery.top());
     max_bakery.pop();
    }
    while (min_bakery.size() > count - 1) {
     max_bakery.push(min_bakery.top());
     min_bakery.pop();
    }
    cout << max_bakery.top() << endl;
   }
   count--;
  }
 }
 return 0;
}
