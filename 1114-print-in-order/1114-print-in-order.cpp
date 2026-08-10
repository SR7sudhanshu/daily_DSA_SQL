std::mutex m;
std::condition_variable cv;

class Foo {
public:
int pcount;
    Foo() {
        pcount = 0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        std::unique_lock<mutex>lock(m);
        cv.wait(lock, [this](){
            return pcount == 0;
        });
        printFirst();
        pcount += 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        std::unique_lock<mutex>lock(m);
        cv.wait(lock, [this]() {
            return pcount == 1;
        });
        printSecond();
        pcount += 1;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        std::unique_lock<mutex>lock(m);
        cv.wait(lock, [this]() {
            return pcount == 2;
        });
        printThird();
        pcount += 1;
        cv.notify_all();
    }
};