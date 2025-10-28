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
    double discount = 0.0;

    if (voucher == myVoucher.carnival) {
        if (itemCost > 50.0 && itemCost < 150.0) {
            discount = itemCost * 0.05; 
        }
    } else if (voucher == myVoucher.autumn) {
        if (itemCost >= 150.0) {
            discount = itemCost * 0.10; 
        }
    } else if (voucher == myVoucher.freeShipping) {
       
    }

    return discount;
}

int main() {
    double itemCost;
    cout << "Enter the price of the item: ";
    cin >> itemCost;

    string shippingType;
    cout << "Enter shipping type (Saver / Standard / Courier): ";
    cin >> shippingType;

    string voucher;
    cout << "Enter the voucher code: ";
    cin >> voucher;

    double discount = applyVoucher(voucher, itemCost);
    double finalCost = itemCost - discount;

    double fee = 0.0;
    if (voucher != "FREESHIPPING") {
        fee = shippingFee(shippingType);
    }

    finalCost += fee;

    cout << "Discount applied: RM " << discount << endl;
    cout << "Shipping fee: RM " << fee << endl;
    cout << "Final price: RM " << finalCost << endl;

    return 0;
}
