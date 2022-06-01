#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;

/*********************회원가입************************/
//회원가입 control class
Signup::Signup() {
    // 1. startInterface
    printf("1. SignupUl\n");
    SignupUI signupUI;

    // 2. inputinfo
    signupUI.inputInfo(this);

    // 3. printOutput
    signupUI.printOutput();
};

//회원가입 control class : addNewClient()
void Signup::addNewClient(ClientList* client, string name, string id, string password, int identificationNumber) {
    printf("2.1 addNewClient\n");

    // 2.1.1 createClient
    client->createClient(name, id, password, identificationNumber);
};


/*********************로그인************************/
//로그인 control class
Login::Login() {

    // 1. startInterface
    printf("1. LoginUl\n");
    LoginUI loginUI;

    // 2. inputIdPassword
    loginUI.inputIdPassword(this);

    // 3. printOutput
    loginUI.printOutput();
};

//로그인 control class : loginClient()
string Login::loginClient(ClientList* client, string id, string password) {
    printf("2.1 loginClient\n");
    
    // 2.1.1 loginClient
    string currentLoginClient =  client->loginClient(id, password);

    return currentLoginClient;
}


/*********************로그아웃************************/
//로그아웃 control class
Logout::Logout() {
    
    // 1. startInterface
    printf("1. LogoutUl\n");
    LogoutUI logoutUI;

    // 2.clickLogout
    logoutUI.clickLogout(this);

    // 3. printOutput
    logoutUI.printOutput();
}

//로그아웃 control class : logoutClient()
string Logout::logoutClient(string id) {
    printf("2.1 logoutClient\n");

    return "None";
}

/*********************탈퇴하기************************/
//탈퇴하기 control class
Secession::Secession() {
    
    // 1. startInterface
    printf("1. Secession\n");
    SecessionUI secessionUI;

    // 2. clickSecession
    secessionUI.clickSecession(this);

    // 3. printOutput
    secessionUI.printOutput();
};

//탈퇴하기 control class : deleteClient()
string Secession::deleteClient(ClientList* client, string id) {
    printf("2.1.1 deleteClient\n");

    // 2.1.1.1 deleteClient
    client->deleteClient(id);

    return "None";
}


/*********************판매상품등록하기************************/

//판매상품등록하기 control class
RegisterNewSale::RegisterNewSale() {
    
    // 1. startInterface
    printf("1. RegisterNewSale\n");
    RegisterNewSaleUI registerNewSaleUI;

    // 2. inputSaleProductinfo
    registerNewSaleUI.inputSaleProductInfo(this);

    // 3. printOutput
    registerNewSaleUI.printOutput();
}

 //판매상품등록하기 control class : registerSaleProduct()
void RegisterNewSale::registerSaleProduct(ProductList* productList, ClientList* clientList, string sellerId, string productName, string productCompanyName, int price, int remaining) {
    printf("2.1 registerSaleProduct\n");

    // 2.1.1 getClientDetail
    Client* client = clientList->getClientDetail(sellerId);

    //새로운 Product 생성
    Product* product = new Product();
    product->setSellerId(sellerId);
    product->setProductName(productName);
    product->setProductCompanyName(productCompanyName);
    product->setPrice(price);
    product->setRemaining(remaining);


    // 2.1.2 createProduct
    productList->createProduct(product);

    // 2.1.3 addSaleProduct
    client->addSaleProduct(product);
}


/*********************판매통계조회하기************************/
InquireSaleStats::InquireSaleStats(ClientList* clientList, string sellerId) {

    // 1. getSaleProductStats
    printf("1. InquireSaleStats\n");
    ProductDetail* statsDetails = clientList->getSaleProuductStats(sellerId);

    // 2. printOutput()
    InquireSaleStatsUI inquireSaleStatsUI;
    inquireSaleStatsUI.printOutput(statsDetails);

    delete[] statsDetails;

}

/*********************상품 구매하기************************/
BuyProduct::BuyProduct() {
    // 1. startInterface
    printf("1. BuyProduct\n");
    BuyProductUI buyProductUI;

    // 2. clickPurchaseButton
    buyProductUI.clickPurchaseButton(this);

    // 3. printOutput
    buyProductUI.printOutput();
}
string BuyProduct::buyProduct(ProductList* productList, ClientList* clientList, string currentLiginClient, string productName) {
    printf("2.1. buyProduct\n");

    // 2.1.1. getProductDetail
    Product* product = productList->getProductDetail(productName);

    int remaining = product->getRemaining();
    int saleing = product->getSaleing();
    string sellerId = product->getSellerId();
    product->setRemaining(remaining - 1);
    product->setSaleing(saleing + 1);

    // 2.1.2. getClientDetail
    Client* client = clientList->getClientDetail(currentLiginClient);


    // 2.1.3 addPurchaseProduct
    client->addPurchaseProduct(product);

    return sellerId;
}