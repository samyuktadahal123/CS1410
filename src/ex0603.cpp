#include <iostream>
using namespace std;

enum class BillKind {
    ONE, FIVE, TEN, TWENTY
};

struct CashInOneBillKind {
    BillKind kind;
    int count;
};

struct Cash {
    CashInOneBillKind ones;
    CashInOneBillKind fives;
    CashInOneBillKind tens;
    CashInOneBillKind twenties;
};

// Version 1: Using a Reference (&)
int totalCash(Cash& c) {
    return (
        (c.ones.count * 1) +
        (c.fives.count * 5) +
        (c.tens.count * 10) +
        (c.twenties.count * 20)
    );
}

// Version 2: Using a Pointer (*) and Arrow Operator (->)
int totalCash2(Cash* c) {
    return (
        (c->ones.count * 1) +
        (c->fives.count * 5) +
        (c->tens.count * 10) +
        (c->twenties.count * 20)
    );
}

int main() {

    // Stack object
    Cash inWallet {
        {BillKind::ONE, 2},
        {BillKind::FIVE, 3},
        {BillKind::TEN, 1},
        {BillKind::TWENTY, 3},
    };

    cout << "Total cash in wallet: "
         << totalCash(inWallet) << endl;

    cout << "Total cash in wallet: "
         << totalCash2(&inWallet) << endl;

    // Heap object (dynamic allocation)
    Cash* dWallet = new Cash {
        {BillKind::ONE, 2},
        {BillKind::FIVE, 3},
        {BillKind::TEN, 1},
        {BillKind::TWENTY, 3},
    };

    cout << "Total cash in wallet: "
         << totalCash(*dWallet) << endl;   // dereferenced

    cout << "Total cash in wallet: "
         << totalCash2(dWallet) << endl;

    delete dWallet;  // clean up heap memory

    return 0;
}
