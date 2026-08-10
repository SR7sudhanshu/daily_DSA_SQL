condition_variable cv;
mutex m;

class FooBar {
private:
    int n;
    int parity;
public:
    FooBar(int n) {
        this->n = n;
        parity = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(m);
            cv.wait(lock, [this](){
                return parity == 0;
            });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            parity = 1 - parity;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(m);
            cv.wait(lock, [this](){
                return parity == 1;
            });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printBar();
            parity = 1 - parity;
            cv.notify_one();
        	// printBar() outputs "bar". Do not change or remove this line.
        }
    }
};