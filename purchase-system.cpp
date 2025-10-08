#include <iostream>
using namespace std;

class VoucherCode {
public:
    string carnival = "0909CARNIVAL";
    string autumn = "AUTUMNISHERE";
    string freeShipping = "FREESHIPPING";
};

double shippingFee(string type) {
    if (type == "Saver")
        return 4.90;
    else if (type == "Standard")
        return 6.90;
    else if (type == "Courier")
        return 10.50;
    else
        return 0.0;
}

double applyVoucher(string voucher, double itemCost) {
    VoucherCode myVoucher;
    double discount = 0;

    if (voucher == myVoucher.carnival) {
        if (itemCost > 50.0) {
            discount = itemCost * 0.05; // 5% discount
        }
    } else if (voucher == myVoucher.autumn) {
        if (itemCost >= 150.0) {
            discount = 15.0; // Fixed RM15 discount
        }
    } else if (voucher == myVoucher.freeShipping) {
        // Discount is handled in shipping section
        discount = 0;
    }

    return discount;
}

double applyInsurance(double itemCost) {
    return itemCost * 0.01; // 1% of item cost
}

int main() {
    const int MAX_TRANSACTIONS = 5;
    double sumOfTransactions[MAX_TRANSACTIONS] = {};
    int counter = 0;
    char choice;

    cout << "=== ONLINE SHOPPING COST CALCULATOR ===" << endl;

    do {
        double itemCost;
        double sum = 0.0;

        cout << "\nEnter item prices (enter -1 to stop): ";
        while (true) {
            cin >> itemCost;
            if (itemCost == -1)
                break;
            sum += itemCost;

            if (itemCost >= 250) {
                char insuranceAnswer;
                cout << "Would you like to add damage protection insurance (y/n)? ";
                cin >> insuranceAnswer;
                if (insuranceAnswer == 'y' || insuranceAnswer == 'Y') {
                    double insuranceCost = applyInsurance(itemCost);
                    sum += insuranceCost;
                    cout << "Insurance added: RM " << insuranceCost << endl;
                }
            }
        }

        double subtotal = sum;
        cout << "\nSubtotal (before discount & shipping): RM " << subtotal << endl;

        string shippingType;
        cout << "Enter shipping type (Saver / Standard / Courier): ";
        cin >> shippingType;

        string voucher;
        cout << "Enter voucher code (if any): ";
        cin >> voucher;

        double discount = applyVoucher(voucher, subtotal);

        double fee = 0.0;
        if (voucher == "FREESHIPPING" && subtotal >= 300.0) {
            cout << "Free shipping applied!" << endl;
            fee = 0.0;
        } else {
            fee = shippingFee(shippingType);
        }

        double finalCost = subtotal - discount + fee;
        sumOfTransactions[counter] = finalCost;
        counter++;

        cout << "\n--- Transaction Summary ---" << endl;
        cout << "Subtotal: RM " << subtotal << endl;
        cout << "Discount: RM " << discount << endl;
        cout << "Shipping fee: RM " << fee << endl;
        cout << "Final price to pay: RM " << finalCost << endl;

        cout << "\nTransactions so far: ";
        for (int i = 0; i < counter; i++)
            cout << sumOfTransactions[i] << "  ";
        cout << endl;

        if (counter == MAX_TRANSACTIONS) {
            cout << "\nTransaction limit (5) reached!" << endl;
            break;
        }

        cout << "\nDo you want to make another transaction? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Compute average
    double total = 0.0;
    for (int i = 0; i < counter; i++)
        total += sumOfTransactions[i];

    double average = total / counter;

    cout << "\n=======================================" << endl;
    cout << "Average total cost for " << counter << " transactions: RM " << average << endl;

    cout << "Transactions below average: ";
    for (int i = 0; i < counter; i++) {
        if (sumOfTransactions[i] < average)
            cout << sumOfTransactions[i] << "  ";
    }
    cout << "\n=======================================" << endl;

    return 0;
}
