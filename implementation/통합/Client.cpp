#include "header.h"

string Client::getName() { return this->name; }
string Client::getId() { return this->id; }
string Client::getPassword() { return this->password; }
int Client::getIdentificationNumber() { return this->identificationNumber; }
void Client::setName(string name) { this->name = name; }
void Client::setId(string id) { this->id = id; }
void Client::setPassword(string password) { this->password = password; }
void Client::setIdentificationNumber(int identificationNumber) { this->identificationNumber = identificationNumber; }

void Client::getSaleProduct() {
    saleCollection.getSaleProduct();
}
void Client::getPurchaseProduct() {
    purchaseCollection.getPurchaseProduct();
}


void Client::addSaleProduct(Product* product) {
    printf("2.1.3. addSaleProduct\n");

    // 2.1.3. addSaleProduct
    this->saleCollection.addSaleProduct(product);
};

ProductDetail* Client::getSalePrductStats() {
    printf("1.1.1. getSaleProuductStats\n");
    
    // 1.1.1.1. getSaleProductStats
    return this->saleCollection.getSalePrductStats();
}

void Client::addPurchaseProduct(Product* product) {
    printf("2.1.3. addPurchaseProduct\n");

    // addPurchseProduct
    this->purchaseCollection.addPurchaseProduct(product);
};

string Client::setEvaluation(string productName, int evalution) {
    printf("2.1.2. setEvaluation\n");

    // 2.1.2.1. setEvaluation
    string sellerId = purchaseCollection.setEvaluation(productName, evalution);
    return sellerId;
}

//도은채 시작
ProductDetail* Client::getSaleProductList() {
    printf("1.1.1. getSaleProductList\n");

    //1.1.1.1. getSaleProductDetails
    return this->saleCollection.getSaleProductDetails();
}

ProductDetail* Client::getSaleDoneProductList() {
    printf("1.1.1. getSaleDoneProductList\n");

    //1.1.1.1. getSaleDoneProductDetails
    return this->saleCollection.getSaleDoneProductDetails();
}

//도은채 끝


//나예림 구매상품조회 추가
ProductDetail* Client::getPurchaseProductList() {
    printf("1.1.1 getPurchaseProductList\n");

    //1.1.1.1. getPurchaseProductDetails
    return this->purchaseCollection.getPurchaseProductDetails();

    //1.1.1.1 get
}
//나예림 구매상품조회 추가