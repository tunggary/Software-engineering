#include "header.h"

ProductList::ProductList() {
    this->productListNumber = 0;
}

ProductList::~ProductList() {
    for (int i = 0; i < productListNumber; i++) {
        delete productList[i];
    }
}

void ProductList::createProduct(Product* product) {
    printf("2.1.2. createProduct\n");

    productList[productListNumber] = product;
    this->productListNumber += 1;
}

//나예림 추가

ProductDetail* ProductList::getProductList(string inputProductName) {
    cout << "2.1.1. getProductList" << endl;

    ProductDetail* allProductDetails = new ProductDetail;


    Product* oneProductDetails = getProductDetail(inputProductName);

    allProductDetails->sellerId = oneProductDetails->getSellerId();
    allProductDetails->productName = oneProductDetails->getProductName();
    allProductDetails->productCompanyName = oneProductDetails->getProductCompanyName();
    allProductDetails->price = oneProductDetails->getPrice();
    allProductDetails->remaining = oneProductDetails->getRemaining();
    allProductDetails->average = oneProductDetails->getEvaluationAvg();

    return allProductDetails;
}

Product* ProductList::getProductDetail(string productName) {
    for (int i = 0; i < productListNumber; i++) {
        if (productList[i]->getProductName() == productName) {
            return productList[i];

       }
    }
}