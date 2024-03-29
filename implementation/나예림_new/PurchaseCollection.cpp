﻿#include "header.h"

void PurchaseCollection::addPurchaseProduct(Product* product) {
    printf("2.1.3.1 addPurchaseProduct\n");
    purchaseProduct[purchaseProductNumber] = product;
    this->purchaseProductNumber += 1;
}

void PurchaseCollection::getPurchaseProduct() {

    for (int i = 0; i < purchaseProductNumber; i++) {
        cout << "구매한 목록 : " << purchaseProduct[i]->getProductName() << ' ' << purchaseProduct[i]->getEvaluationAvg()  << endl;
    }
}

void PurchaseCollection::setEvaluation(string productName, int evaluation) {
    printf("2.1.2.1. setEvaluation\n");

    for (int i = 0; i < purchaseProductNumber; i++) {
        if (purchaseProduct[i]->getProductName() == productName) {
            printf("2.1.2.1.1 setEvaluationAvg\n");

            int saleing = purchaseProduct[i]->getSaleing();
            int evaluationSum = purchaseProduct[i]->getEvaluationSum();
            evaluationSum += evaluation;
            float evaluationAvg = (float)evaluationSum / saleing;

            // 2.1.2.1.1. setEvaluation
            purchaseProduct[i]->setEvaluationSum(evaluationSum);
            purchaseProduct[i]->setEvaluationAvg(evaluationAvg);
            break;
        }
    }
}

//나예림 추가
ProductDetail* PurchaseCollection::getPurchaseProductDetails() {
    printf("1.1.1.1. getSaleProductDetails\n");


    ProductDetail* purchaseDetails = new ProductDetail[MAX_COUNT];
    for (int i = 0; i < purchaseProductNumber; i++) {
        purchaseDetails[i].sellerId = purchaseProduct[i]->getSellerId();
        purchaseDetails[i].productName = purchaseProduct[i]->getProductName();
        purchaseDetails[i].productCompanyName = purchaseProduct[i]->getProductCompanyName();
        purchaseDetails[i].price = purchaseProduct[i]->getPrice();
        purchaseDetails[i].remaining = purchaseProduct[i]->getRemaining();
        purchaseDetails[i].average = purchaseProduct[i]->getEvaluationAvg();
        cout << purchaseDetails[i].sellerId << " " << purchaseDetails[i].productName << endl;
    }
    return purchaseDetails;
}