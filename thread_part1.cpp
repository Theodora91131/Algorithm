#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>

using namespace std;
using namespace std::chrono;

void threadJob(int id, int n, int x, atomic<int>& threadSum)
{
    int start = (id - 1) * (n / x) + 1;
    int end = id * (n / x);
    int sum = 0;

    cout << "Thread " << id << " started" << endl;

    for (int i = start; i <= end; ++i)
    {
        sum += i;
    }

    threadSum = sum;

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
    vector<atomic<int>> threadSums(x);

    auto startTime = high_resolution_clock::now();

    for (int i = 1; i <= x; ++i)
    {
        threads.emplace_back(thread(threadJob, i, n, x, ref(threadSums[i - 1])));
    }

    for (auto& t : threads)
    {
        t.join();
    }

    int totalSum = 0;
    for (const auto& sum : threadSums)
    {
        totalSum += sum;
    }

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime);
    double threadTime = duration.count() / 1000.0;

    cout << "Sum: " << totalSum << endl;
    cout << "Threaded Time: " << threadTime << " seconds" << endl;

    startTime = high_resolution_clock::now();

    int traditionalSum = 0;
    for (int i = 1; i <= n; ++i)
    {
        traditionalSum += i;
    }

    endTime = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(endTime - startTime);
    double traditionalTime = duration.count() / 1000.0;

    cout << "Traditional Sum: " << traditionalSum << endl;
    cout << "Traditional Time: " << traditionalTime << " seconds" << endl;

    double speedup = traditionalTime / threadTime;
    cout << "Speedup: " << speedup << "x" << endl;

    return 0;
}

