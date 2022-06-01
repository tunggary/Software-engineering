#include "header.h"

void SaleCollection::addSaleProduct(Product* product) {
    printf("2.1.3.1 addSaleProduct\n");

    saleProduct[saleProductNumber] = product;
    this->saleProductNumber += 1;
}

void SaleCollection::getSaleProduct() {

    for (int i = 0; i < saleProductNumber; i++) {
        cout << "판매한 목록 : " << saleProduct[i]->getProductName() << endl;
    }
}

ProductDetail* SaleCollection::getSalePrductStats() {
    printf("1.1.1.1. getSaleProuductStats\n");

    ProductDetail* statsDetails = new ProductDetail[MAX_COUNT];
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

//도은채 판매상품조회
ProductDetail* SaleCollection::getSaleProductDetails() {
    printf("1.1.1.1. getSaleProductDetails\n");

    ProductDetail* saleDetails = new ProductDetail[MAX_COUNT];
    for (int i = 0; i < saleProductNumber; i++) {
        saleDetails[i].productName = saleProduct[i]->getProductName();
        saleDetails[i].productCompanyName = saleProduct[i]->getProductCompanyName();
        saleDetails[i].price = saleProduct[i]->getPrice();
        saleDetails[i].remaining = saleProduct[i]->getRemaining();

    }
    return saleDetails;
}

//도은채 판매완료상품조회
ProductDetail* SaleCollection::getSaleDoneProductDetails() {
    printf("1.1.1.1. getSaleDoneProductDetails\n");

    ProductDetail* saleDoneDetails = new ProductDetail[MAX_COUNT];
    for (int i = 0; i < saleProductNumber; i++) {
        if (saleProduct[i]->getRemaining() == 0) {
            saleDoneDetails[i].productName = saleProduct[i]->getProductName();
            saleDoneDetails[i].productCompanyName = saleProduct[i]->getProductCompanyName();
            saleDoneDetails[i].price = saleProduct[i]->getPrice();
            saleDoneDetails[i].saleing = saleProduct[i]->getSaleing();
            saleDoneDetails[i].average = saleProduct[i]->getEvaluationAvg();
        }
    }

    return saleDoneDetails;
}