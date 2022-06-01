#pragma once
#include <iostream>
#define MAX_COUNT 100

using namespace std;

typedef struct {
	string productName = "";
	int total = 0;
	float average = 0.0;
}StatsDetails;

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
};

//class Purchase {
//private:
//	int purchaseProductNumber;
//	Product* purchaseProduct[MAX_COUNT];
//public:
//	void addP
//};

class SaleCollection {
private:
	int saleProductNumber;
	Product* saleProduct[MAX_COUNT];
public:
	void addSaleProduct(Product*);
	void getSaleProduct();
	StatsDetails* getSalePrductStats();
};


class Client {
private:
	string name;
	string id;
	string password;
	int identificationNumber;
	//Purchase purchaseProductCollection;
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
	void getSaleProduct();
	StatsDetails* getSalePrductStats();
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
	StatsDetails* getSaleProuductStats(string);
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

class InquireSaleStats {
public:
	InquireSaleStats(ClientList*, string);
};

class InquireSaleStatsUI {
public:
	void printOutput(StatsDetails*);
};