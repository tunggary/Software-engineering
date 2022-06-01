#include "header.h"

void SaleCollection::addSaleProduct(Product* product) {
    printf("2.1.3.1 addSaleProduct\n");

    saleProduct[saleProductNumber] = product;
    this->saleProductNumber += 1;
}

void SaleCollection::getSaleProduct() {

    for (int i = 0; i < saleProductNumber; i++) {
        cout << "구매한 목록 : " << saleProduct[i]->getProductName() << endl;
    }
}

StatsDetails* SaleCollection::getSalePrductStats() {
    printf("1.1.1.1. getSaleProuductStats\n");

    saleProduct[0]->setSaleing(1);

    StatsDetails* statsDetails = new StatsDetails[MAX_COUNT];
    for (int i = 0; i < saleProductNumber; i++) {
        if (saleProduct[i]->getSaleing() > 0) {
            int price = saleProduct[i]->getPrice();
            int saleing = saleProduct[i]->getSaleing();
            statsDetails[i].total = price * saleing;
            statsDetails[i].productName = saleProduct[i]->getProductName();
            statsDetails[i].average = saleProduct[i]->getEvaluationAvg();
        }
    }
    return statsDetails;
}
