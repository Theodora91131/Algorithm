#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>

using namespace std;

atomic<int> totalSum(0);
mutex mtx;

void threadJob(int id, int n, int x)
{
    int start = (id - 1) * (n / x) + 1;
    int end = id * (n / x);
    int sum = 0;

    cout << "Thread " << id << " started" << endl;

    for (int i = start; i <= end; ++i)
    {
        sum += i;
    }

    // 使用互斥量鎖定計算結果的存取
    {
        lock_guard<mutex> lock(mtx);
        totalSum += sum;
    }

    cout << "Thread " << id << " finished" << endl;
}

int main()
{
    int x, n;
    cout << "Enter the number of threads: ";
    cin >> x;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<thread> threads;

    for (int i = 1; i <= x; ++i)
    {
        threads.emplace_back(thread(threadJob, i, n, x));
    }

    for (auto& t : threads)
    {
        t.join();
    }

    cout << "Sum: " << totalSum << endl;

    return 0;
}

