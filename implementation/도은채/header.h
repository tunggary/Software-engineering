#pragma once
#include <iostream>
#define MAX_COUNT 100

using namespace std;

typedef struct {
	string sellerId="";
	string productName="";
	string productCompanyName="";
	int price=0;
	int remaining=0;
	int saleing=0;
	int total = 0;
	float average = 0.0;
}ProductDetail;

class Product {
private:
	string sellerId;
	string productName;
	string productCompanyName;
	int price;
	int remaining;
	int saleing;
	float evaluationAvg;
public:
	Product();
	string getSellerId();
	string getProductName();
	string getProductCompanyName();
	int getPrice();
	int getRemaining();
	int getSaleing();
	float getEvaluationAvg();
	void setSellerId(string);
	void setProductName(string);
	void setProductCompanyName(string);
	void setPrice(int);
	void setRemaining(int);
	void setSaleing(int);
};

class ProductList {
private:
	Product* productList[MAX_COUNT];
	int productListNumber;
public:
	ProductList();
	~ProductList();
	void createProduct(Product*);
	void getProductList();
	Product* getProductDetail(string);
};

class PurchaseCollection {
private:
	int purchaseProductNumber;
	Product* purchaseProduct[MAX_COUNT];
public:
	void addPurchaseProduct(Product*);
	void getPurchaseProduct();
};

class SaleCollection {
private:
	int saleProductNumber;
	Product* saleProduct[MAX_COUNT];
public:
	void addSaleProduct(Product*);
	void getSaleProduct();
	//도은채 판매상품조회
	ProductDetail* getSaleProductDetails();
	//도은채 판매완료상푸무조회
	ProductDetail* getSaleDoneProductDetails();
	ProductDetail* getSalePrductStats();
};


class Client {
private:
	string name;
	string id;
	string password;
	int identificationNumber;
	PurchaseCollection purchaseCollection;
	SaleCollection saleCollection;
public:
	string getName();
	string getId();
	string getPassword();
	int getIdentificationNumber();
	void setName(string);
	void setId(string);
	void setPassword(string);
	void setIdentificationNumber(int);
	void addSaleProduct(Product*);
	void addPurchaseProduct(Product*);
	void getSaleProduct();
	void getPurchaseProduct();
	//도은채 판매상품조회
	ProductDetail* getSaleProductList();
	//도은채 판매완료상품조회
	ProductDetail* getSaleDoneProductList();
	ProductDetail* getSalePrductStats();
};

class ClientList {
private:
	Client clientList[MAX_COUNT];
	int clientNumber;
public:
	void createClient(string, string, string, int);
	string loginClient(string, string);
	void deleteClient(string);
	Client* getClientDetail(string);
	//도은채 판매상품조회
	ProductDetail* getSaleProducts(string);
	//도은채 판매완료상품조회
	ProductDetail* getSaleDoneProducts(string);
	ProductDetail* getSaleProuductStats(string);
};


class Signup {
public:
	Signup();
	void addNewClient(ClientList*, string, string, string, int);
};

class SignupUI {
private:
	int identificationNumber;
	string name;
	string id;
	string password;
public:
	void inputInfo(Signup*);
	void printOutput();
};

class Secession {
public:
	Secession();
	string deleteClient(ClientList*, string);
};

class SecessionUI {
private:
	string id;
public:
	void clickSecession(Secession*);
	void printOutput();
};

class Login {
public:
	Login();
	string loginClient(ClientList*, string, string);
};

class LoginUI {
private:
	string id;
	string password;
public:
	void inputIdPassword(Login*);
	void printOutput();
};

class Logout {
public:
	Logout();
	string logoutClient(string);
};

class LogoutUI {
private:
	string id;
public:
	void printOutput();
	void clickLogout(Logout*);
};

class RegisterNewSale {
public:
	RegisterNewSale();
	void registerSaleProduct(ProductList*, ClientList*, string, string, string, int, int);
};

class RegisterNewSaleUI {
private:
	string productName;
	string productCompanyName;
	int price;
	int remaining;
public:
	void inputSaleProductInfo(RegisterNewSale*);
	void printOutput();

};

//도은채 시작
class InquireSales {
public:
	InquireSales(ClientList*, string);
};

class InquireSalesUI {
public:
	void printOutput(ProductDetail*);
};

class InquireSalesDone {
public:
	InquireSalesDone(ClientList*, string);
};

class InquireSalesDoneUI {
public:
	void printOutput(ProductDetail*);
};
//도은채 끝

class InquireSaleStats {
public:
	InquireSaleStats(ClientList*, string);
};

class InquireSaleStatsUI {
public:
	void printOutput(ProductDetail*);
};

class BuyProduct {
public:
	BuyProduct();
	string buyProduct(ProductList*, ClientList*, string, string);
};

class BuyProductUI {
private:
	string sellerId;
	string productName;
public:
	void clickPurchaseButton(BuyProduct*);
	void printOutput();
};