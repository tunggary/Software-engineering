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

ProductDetail* ProductList::getProductList(string inputProductName) {
    cout << "2.1.1. getProductList" << endl;

    ProductDetail* allProductDetails = new ProductDetail[MAX_COUNT];

    int count = 0;
    for (int i = 0; i < productListNumber; i++) {
        cout << "전체 상품 목록" << productList[i]->getProductName() << ' ' << productList[i]->getSaleing() << endl;

    }

    Product* oneProductDetails = getProductDetail(inputProductName);
    allProductDetails[0].sellerId = oneProductDetails->getSellerId();
    allProductDetails[0].productName = oneProductDetails->getProductName();
    allProductDetails[0].productCompanyName = oneProductDetails->getProductCompanyName();
    allProductDetails[0].price = oneProductDetails->getPrice();
    allProductDetails[0].saleing = oneProductDetails->getSaleing();
    allProductDetails[0].average = oneProductDetails->getEvaluationAvg();

    return allProductDetails;
}

Product* ProductList::getProductDetail(string inputProductName) {
    cout << "2.1.1.1 getProductDetail" << endl;

    //inputProductNmae과 같은 상품명 찾기
    for (int i = 0; i < productListNumber; i++) {
        if (productList[i]->getProductName() == inputProductName) {
            //찾아서 해당 상품의 상세정보 리턴
            return productList[i];
        }

    }
}