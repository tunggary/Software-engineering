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

void Client::addSaleProduct(Product* product) {
    printf("2.1.3. addSaleProduct\n");

    // addSaleProduct
    this->saleCollection.addSaleProduct(product);
};

StatsDetails* Client::getSalePrductStats() {
    printf("1.1.1. getSaleProuductStats\n");
    
    // 1.1.1.1. getSaleProductStats
    return this->saleCollection.getSalePrductStats();
}