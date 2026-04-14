#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Calculator {
private:
    T a, b;
public:
    Calculator(T a, T b): a(a), b(b){}

    T add() const { return a + b; }
    T subtract() const { return a - b; }
    T multiply() const { return a * b; }
    T divide() const {
        if(b == 0){
            throw runtime_error("Division by zero");
        }
        return a / b;
    }
};

int main(){
    try {
        Calculator<double> c(10.0, 2.0);
        cout << c.add() << endl
             << c.subtract() << endl
             << c.multiply() << endl
             << c.divide() << endl;

        Calculator c1(4, 0);
        cout << c1.add() << endl
             << c1.subtract() << endl
             << c1.multiply() << endl
             << c1.divide() << endl;
    }
    catch (const runtime_error& e){
        cerr << "An exception happened: " << e.what() << endl;
    }

    return 0;
}