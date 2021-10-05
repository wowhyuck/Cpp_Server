#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>

void HelloThread()
{
    cout << "Hello Thread" << endl;
}

void HelloThread2(int32 num)
{
    cout << num << endl;
}

int main()
{

    // HelloThread

    //std::thread t(HelloThread);
    std::thread t;

    auto id1 = t.get_id();

    t = std::thread(HelloThread);

    int32 count = t.hardware_concurrency();     // CPU 코어 개수?
    auto id2 = t.get_id();     // 쓰레드마다 id

    //t.detach();     // std::thread 객체에서 실제 쓰레드를 분리

    if(t.joinable())
        t.join();

    std::thread t2(HelloThread2, 10);

    t2.join();

    vector<std::thread> v;

    for (int32 i = 0; i < 10; i++)
    {
        v.push_back(std::thread(HelloThread2, i));
    }

    for (int32 i = 0; i < 10; i++)
    {
        if (v[i].joinable())
            v[i].join();
    }


    cout << "Hello Main" << endl;


}