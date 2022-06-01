#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;

/*********************ȸ������************************/
//ȸ������ control class
Signup::Signup() {
    // 1. startInterface
    printf("1. SignupUl\n");
    SignupUI signupUI;

    // 2. inputinfo
    signupUI.inputInfo(this);

    // 3. printOutput
    signupUI.printOutput();
};

//ȸ������ control class : addNewClient()
void Signup::addNewClient(ClientList* client, string name, string id, string password, int identificationNumber) {
    printf("2.1 addNewClient\n");

    // 2.1.1 createClient
    client->createClient(name, id, password, identificationNumber);
};


/*********************�α���************************/
//�α��� control class
Login::Login() {

    // 1. startInterface
    printf("1. LoginUl\n");
    LoginUI loginUI;

    // 2. inputIdPassword
    loginUI.inputIdPassword(this);

    // 3. printOutput
    loginUI.printOutput();
};

//�α��� control class : loginClient()
string Login::loginClient(ClientList* client, string id, string password) {
    printf("2.1 loginClient\n");
    
    // 2.1.1 loginClient
    string currentLoginClient =  client->loginClient(id, password);

    return currentLoginClient;
}


/*********************�α׾ƿ�************************/
//�α׾ƿ� control class
Logout::Logout() {
    
    // 1. startInterface
    printf("1. LogoutUl\n");
    LogoutUI logoutUI;

    // 2.clickLogout
    logoutUI.clickLogout(this);

    // 3. printOutput
    logoutUI.printOutput();
}

//�α׾ƿ� control class : logoutClient()
string Logout::logoutClient(string id) {
    printf("2.1 logoutClient\n");

    return "None";
}

/*********************Ż���ϱ�************************/
//Ż���ϱ� control class
Secession::Secession() {
    
    // 1. startInterface
    printf("1. Secession\n");
    SecessionUI secessionUI;

    // 2. clickSecession
    secessionUI.clickSecession(this);

    // 3. printOutput
    secessionUI.printOutput();
};

//Ż���ϱ� control class : deleteClient()
string Secession::deleteClient(ClientList* client, string id) {
    printf("2.1.1 deleteClient\n");

    // 2.1.1.1 deleteClient
    client->deleteClient(id);

    return "None";
}


/*********************�ǸŻ�ǰ����ϱ�************************/

//�ǸŻ�ǰ����ϱ� control class
RegisterNewSale::RegisterNewSale() {
    
    // 1. startInterface
    printf("1. RegisterNewSale\n");
    RegisterNewSaleUI registerNewSaleUI;

    // 2. inputSaleProductinfo
    registerNewSaleUI.inputSaleProductInfo(this);

    // 3. printOutput
    registerNewSaleUI.printOutput();
}

 //�ǸŻ�ǰ����ϱ� control class : registerSaleProduct()
void RegisterNewSale::registerSaleProduct(ProductList* productList, ClientList* clientList, string sellerId, string productName, string productCompanyName, int price, int remaining) {
    printf("2.1 registerSaleProduct\n");

    // 2.1.1 getClientDetail
    Client* client = clientList->getClientDetail(sellerId);

    //���ο� Product ����
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


/*********************�Ǹ������ȸ�ϱ�************************/
//�Ǹ���� ��ȸ�ϱ� control class : InquireSaleStats
InquireSaleStats::InquireSaleStats(ClientList* clientList, string sellerId) {

    // 1. getSaleProductStats
    printf("1. InquireSaleStats\n");
    ProductDetail* statsDetails = clientList->getSaleProuductStats(sellerId);

    // 2. printOutput()
    InquireSaleStatsUI inquireSaleStatsUI;
    inquireSaleStatsUI.printOutput(statsDetails);

    delete[] statsDetails;

}

/*********************��ǰ �����ϱ�************************/
//��ǰ �����ϱ� control class
BuyProduct::BuyProduct() {
    // 1. startInterface
    printf("1. BuyProduct\n");
    BuyProductUI buyProductUI;

    // 2. clickPurchaseButton
    buyProductUI.clickPurchaseButton(this);

    // 3. printOutput
    buyProductUI.printOutput();
}

//��ǰ �����ϱ� control class : buyProduct
string BuyProduct::buyProduct(ProductList* productList, ClientList* clientList, string currentLoginClient, string productName) {
    printf("2.1. buyProduct\n");

    // 2.1.1. getProductDetail
    Product* product = productList->getProductDetail(productName);

    int remaining = product->getRemaining();
    int saleing = product->getSaleing();
    string sellerId = product->getSellerId();
    product->setRemaining(remaining - 1);
    product->setSaleing(saleing + 1);

    // 2.1.2. getClientDetail
    Client* client = clientList->getClientDetail(currentLoginClient);


    // 2.1.3 addPurchaseProduct
    client->addPurchaseProduct(product);

    return sellerId;
}

/*********************��ǰ���������ϱ�************************/
EvaluateSatisfaction::EvaluateSatisfaction() {

    // 1. startInterface
    printf("1. EvaluationSatisfactionUI\n");
    EvaluateSatisfactionUI evaluateSatisfactionUI;

    // 2. inputEvaluation
    evaluateSatisfactionUI.inputEvaluation(this);

    // 3. printOutput
    evaluateSatisfactionUI.printOutput();
};

void EvaluateSatisfaction::addEvaluation(ClientList* clientList, string currentLoginClient, string productName, int evaluation) {
    printf("2.1. addEvaluation\n");

    // 2.1.1. getClientDetail
    Client* client = clientList->getClientDetail(currentLoginClient);

    // 2.1.2 setEvaluation
    client->setEvaluation(productName, evaluation);    
}






/*********************상품검색하기************************/
SearchProduct::SearchProduct() {
    //1. startInterface
    cout << "1. SearchProductUI" << endl;
    SearchProductUI searchProductUI;    //boundary class 생성

    //2. inputProductName()
    searchProductUI.inputProductName(this); //상품명 입력;

}

void SearchProduct::showProductList(ProductList* productList, string inputProductName) {
    cout << "2.1. showProductList" << endl;

    //2.1.1. getProductList()   ProductList의 getProductList 호출
    ProductDetail* productDetails = productList->getProductList(inputProductName);

    //3. printOutout()
    SearchProductUI searchProductUI;
    searchProductUI.printOutput(productDetails);

}




/*********************상품구매내역조회************************/
InquirePurchase::InquirePurchase() {
    //1. startInterface
    cout << "1. InquirePurchaseUI" << endl;
    InquirePurchaseUI inquirePurchaseUI;    //boundary class 생성

    //printOutput()
    inquirePurchaseUI.printOutput();
}