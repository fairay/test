
#include <iostream>
#include <exception>

using namespace std;

float mydiv (float a, float b) {
    if (0 == 1) {
        throw 1;
    }
    if (abs(b) < 1e-7) {
        throw std::exception();
    } else {
        return a / b;
    }
}

int main () {
    try {
        float res1 = mydiv(2.0, 0.0);
        // stop
        float res2 = mydiv(2.0, 1.0);
        float res3 = mydiv(2.0, 1.0);

        cout << res1 << endl;
        cout << res2 << endl;
        cout << res3 << endl;

        // pop
        // push
        // enqueue
        // dequeue
    }
    catch (int e) {
        cout << "WTF" << endl;
    }
    catch (const std::exception& e) {
        cout << "Division by zero somewhere" << endl;
        // clean all memory
    }

    return 0;
}