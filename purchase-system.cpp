#include <iostream>
using namespace std;

class VoucherCode {
public: 
    string carnival = "CARNIVAL";
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
            discount = itemCost * 0.05; 
        }
    } else if (voucher == myVoucher.autumn) {
        if (itemCost >= 150.0) {
            discount = itemCost * 0.10; 
        }
    } else if (voucher == myVoucher.freeShipping) {
        // no discount,
    }

    return discount;
}

double applyInsurance(double itemCost) {
    return itemCost * 0.01;
}

int main() {
    char choice;
    int size = 5;
    double sumOfTransactions[size] = {};
    int counter = 0; 
    double total = 0.0;

    do {
        double itemCost;
        double sum = 0.0;
        double insuranceTotal = 0.0;
        cout << "Enter the price of the item: (Enter -1 to stop) ";

        while (true) {
            cin >> itemCost;
            if (itemCost == -1)
                break;

            sum += itemCost;

            if (itemCost >= 250) {
                char insuranceAnswer;
                cout << "Would you like to add damage protection insurance (y/n): ";
                cin >> insuranceAnswer;
                if (insuranceAnswer == 'y' || insuranceAnswer == 'Y') {
                    double insurance = applyInsurance(itemCost);
                    sum += insurance;
                    insuranceTotal += insurance;  
                }
            }
        }

        string shippingType;
        cout << "Enter shipping type (Saver / Standard / Courier): ";
        cin >> shippingType;

        string voucher;
        cout << "Enter the voucher code: ";
        cin >> voucher;

        double discount = applyVoucher(voucher, sum);
        double finalCost = sum - discount;

        double fee = 0.0;
        if (voucher != "FREESHIPPING") {
            fee = shippingFee(shippingType);
        }

        finalCost += fee;
        sumOfTransactions[counter] = finalCost;
        counter++;

        cout << "Discount applied: RM " << discount << endl;
        cout << "Shipping fee: RM " << fee << endl;
        cout << "Insurance added: RM " << insuranceTotal << endl; 
        cout << "Final price: RM " << finalCost << endl;

        cout << "Total cost of Transactions ";
        for (int i = 0; i < counter; i++)
            cout << sumOfTransactions[i] << ",";
        cout << endl;

        cout << "You are allowed to make up to 5 transactions " << endl;
        cout << "Do you want to make another transaction? (y/n): ";
        cin >> choice;

        if (counter == 5) {  
            cout << "Number of Transactions exceeded the limit! " << endl;
            break;
        }

    } while (choice == 'y' || choice == 'Y');

    for (int i = 0; i < counter; i++)
        total += sumOfTransactions[i];

    double average = total / counter;
    cout << "Average amount to pay for " << counter << " transactions is " << average;  

    return 0;
}
