#include "header.h"

void PurchaseCollection::addPurchaseProduct(Product* product) {
    printf("2.1.3.1 addPurchaseProduct\n");
    purchaseProduct[purchaseProductNumber] = product;
    this->purchaseProductNumber += 1;
}

void PurchaseCollection::getPurchaseProduct() {

    for (int i = 0; i < purchaseProductNumber; i++) {
        cout << "구매한 목록 : " << purchaseProduct[i]->getProductName() << ' ' << purchaseProduct[i]->getSaleing()  << endl;
    }
}
