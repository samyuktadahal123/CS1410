#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string findQuardant (double deg);

string findQuardant (double deg){
    double rad = 3.14 * deg/ 180;
    if(sin(rad) >= 0 && cos(rad) >= 0){
        return "Quardant I";
    } else if(sin(rad) >= 0 && cos(rad) < 0) {
        return "Quardant II";
    } else if(sin(rad) < 0 && cos(rad) < 0){
        return "Quardant III";
    } else {
        return "Quardant IV";
    }
}

int main() {
    cout << findQuardant(23) << endl;
    cout << findQuardant(123) << endl;
    cout << findQuardant(223) << endl;
    cout << findQuardant(323) << endl;

    return 0;
}