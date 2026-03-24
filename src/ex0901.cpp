#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class Color {
private:
    double r, g, b;

public:
    Color() : r(0.0), g(0.0), b(0.0) {}
    Color(double r, double g, double b) : r(r), g(g), b(b) {}

    string toRGB() const {
        stringstream sout;
        sout << "rgb(" << static_cast<int>(r * 255) << ","
             << static_cast<int>(g * 255) << ","
             << static_cast<int>(b * 255) << ")";
        return sout.str();
    }

    string toHEX() const {
        stringstream sout;
        sout << "#" << setfill('0') << uppercase << hex
             << setw(2) << static_cast<int>(r * 255)
             << setw(2) << static_cast<int>(g * 255)
             << setw(2) << static_cast<int>(b * 255);
        return sout.str();
    }

    double operator[](int index) const {
        if (index == 0) return r;
        if (index == 1) return g;
        return b;
    }

    friend ostream& operator<<(ostream& out, const Color& c);
    friend istream& operator>>(istream& in, Color& c);
};

ostream& operator<<(ostream& out, const Color& c) {
    out << c.toRGB() << " --- " << c.toHEX();
    return out;
}

istream& operator>>(istream& in, Color& c) {
    in >> c.r >> c.g >> c.b;
    return in;
}

int main() {
    Color c; // Black
    Color c1(1.0, 0.25, .5);

    cout << c << endl;
    cout << c1 << endl;

    Color c2;
    cout << "Enter a color (three values between 0.0 and 1.0):";
    cin >> c2;

    cout << "\nC1 red: " << c1[0] << endl;
    cout << "C1 green: " << c1[1] << endl;
    cout << "C2 blue: " << c2[2] << endl;

    return 0;
}