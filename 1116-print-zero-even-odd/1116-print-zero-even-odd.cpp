std::mutex m;
std::condition_variable cv;
class ZeroEvenOdd {
private:
    int n;
    int curr;
    int z;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->curr = 1;
        this->z = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        while(curr <= n) {
            cv.wait(lock, [this]{
                return z < curr;
            });
            if(curr <= n) printNumber(0);
            z++;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        while(curr <= n) {
            cv.wait(lock, [this]{
                return curr == z && !(curr & 1);
            });
            if(curr <= n) printNumber(curr);
            curr++;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        while(curr <= n) {
            cv.wait(lock, [this]{
                return curr == z && curr & 1;
            });
            if(curr <= n) printNumber(curr);
            curr++;
            cv.notify_all();
        }
    }
};