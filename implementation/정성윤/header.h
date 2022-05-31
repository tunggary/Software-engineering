#pragma once
#include <iostream>
#define MAX_COUNT 1000

using namespace std;


class PurchaseProductCollector {};

class SaleProductCollector {};

class Client {
private:

	typedef struct {
		string name;
		string id;
		string password;
		int identificationNumber;
		PurchaseProductCollector purchaseProduct[MAX_COUNT];
		SaleProductCollector saleProduct[MAX_COUNT];
	} EachClient;

	EachClient clientList[MAX_COUNT];
	int clientNumber;

public:
	void createClient(string, string, string, int);
	string loginClient(string, string);
	void deleteClient(string);
};

class Signup {
	int identificationNumber;
	string name;
	string id;
	string password;
public:
	Signup();
	void addNewClient(Client*, string, string, string, int);
	string getName();
	string getId();
	string getPassword();
	int getIdentificationNumber();
};

class SignupUI {
public:
	void inputInfo(Signup*);
	void printOutput(Signup*);
};

class Secession {
private:
	string id;
public:
	Secession();
	string deleteClient(Client*, string);
	string getId();
};

class SecessionUI {
public:
	void clickSecession(Secession*);
	void printOutput(Secession*);
};

class Login {
private:
	string id;
	string password;
public:
	Login();
	string loginClient(Client*, string, string);
	string getId();
	string getPassword();
};

class LoginUI {
public:
	void inputIdPassword(Login*);
	void printOutput(Login*);
};

class Logout {
private:
	string id;
public:
	Logout();
	string logoutClient(string);
	string getId();
};

class LogoutUI {
public:
	void printOutput(Logout*);
	void clickLogout(Logout*);
};