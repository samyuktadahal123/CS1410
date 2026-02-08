#include <iostream>
#include <string>
using namespace std;

struct Date {
    int year;
    string month;
    int date;
};

struct Point {
    int x, y;
};

void printDate(const Date& d){
    cout << "DOB: " << d.month << " " << d.date << ", " << d.year << endl;
}

void printPoint(const Point& p) {
    cout << "(" << p.x << "," << p.y << ")" << endl;
}

int main(){
    Date dob{2026, "February", 21};
    Date weddingDay{2000, "May", 31};

    Point p, q, h;

    char trash;
    cout << "Enter point p: ";
    cin >> trash >> p.x >> trash >> p.y >> trash;

    cout << "Enter point q: ";
    cin >> trash >> q.x >> trash >> q.y >> trash;

    printDate(dob);
    printDate(weddingDay);

    printPoint(p);
    printPoint(q);

    h.x = (p.x + q.x) / 2;
    h.y = (p.y + q.y) / 2;

    printPoint(h);

    return 0;
}
