#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

using namespace std;

std::mutex s_m;

class Task {
public:
    virtual void run()
    {
        //this_thread::sleep_for(chrono::seconds(1));
        unique_lock<mutex> ulock(s_m); 
        cout << "Hello World" << endl;
    }

private:

};

class ThreadPool{
public:
    ThreadPool(int count)
    :running_flag_(false)
    ,m_count(count)
    {
    }
    ~ThreadPool(){
        stop();
    }

    void start() {
        running_flag_ = true;
        for(int i = 0; i < m_count; ++i) {
            threads_.emplace_back(&ThreadPool::work, this);
        }
    }
    void stop() {
        running_flag_ = false;
        cv_.notify_all();
        for(auto& th : threads_) {
            if(th.joinable()) {
                th.join();
            }
        }

    }

    void push_task(Task* task)
    {
        unique_lock<mutex> ulock(this->mtx_);
        tasks_.push(task);
        ulock.unlock();
        cv_.notify_one();
    }

private:
    void work()
    {
        while(running_flag_) {
            Task* task = nullptr;
            {
                unique_lock<mutex> ulock(this->mtx_);
                while(tasks_.empty()) {
                    cv_.wait(ulock);
                }
                if(running_flag_) {
                    task = tasks_.front();
                    tasks_.pop();
                }
            }
            if(nullptr != task) {
                task->run();
            }
        }
    }

private:
    atomic_bool running_flag_;
    int m_count;
    vector<thread> threads_;
    queue<Task*> tasks_;
    condition_variable cv_;
    mutex mtx_;
};

int main()
{
    ThreadPool pool(6);
    pool.start();
    Task t[6];
    for(auto &task : t) {
        pool.push_task(&task);
    }
    getchar();
    return 0;
}