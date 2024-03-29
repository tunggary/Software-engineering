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

void ProductList::getProductList() {
    for (int i = 0; i < productListNumber; i++) {
        cout << "전체 상품 목록 : " << productList[i]->getProductName() << ' ' << productList[i]->getEvaluationAvg() << endl;
    }
}

Product* ProductList::getProductDetail(string productName) {
    for (int i = 0; i < productListNumber; i++) {
        if (productList[i]->getProductName() == productName) {
            return productList[i];

       }
    }
}