#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;

/*********************ȸ������************************/
//ȸ������ control class
Signup::Signup() {
    this->identificationNumber = 0;

    // 1. startInterface
    printf("1. SignupUl\n");
    SignupUI signupUI;

    // 2. inputinfo
    signupUI.inputInfo(this);

    // 3. printOutput
    signupUI.printOutput(this);
};

//ȸ������ control class : addNewClient()
void Signup::addNewClient(Client* client, string name, string id, string password, int identificationNumber) {
    printf("2.1 addNewClient\n");

    //��������
    this->name = name;
    this->id = id;
    this->password = password;
    this->identificationNumber = identificationNumber;

    // 2.1.1 addNewClient
    client->createClient(name, id, password, identificationNumber);
};

//ȸ������ control class : getName()
string Signup::getName() { return this->name; }

//ȸ������ control class : getId()
string Signup::getId() { return this->id; }

//ȸ������ control class : getPassword()
string Signup::getPassword() { return this->password; }

//ȸ������ control class : getIdentificationNumber()
int Signup::getIdentificationNumber() { return this->identificationNumber; }


/*********************�α���************************/
//�α��� control class
Login::Login() {

    // 1. startInterface
    printf("1. LoginUl\n");
    LoginUI loginUI;

    // 2. inputIdPassword
    loginUI.inputIdPassword(this);

    // 3. printOutput
    loginUI.printOutput(this);
};

//�α��� control class : loginClient()
string Login::loginClient(Client* client, string id, string password) {
    printf("2.1 loginClient\n");

    //���� ����
    this->id = id;
    this->password = password;
    
    // 2.1.1 loginClient
    string currentLoginClient =  client->loginClient(id, password);

    return currentLoginClient;
}

//�α��� control class : getId()
string Login::getId() { return this->id; }

//�α��� control class : getPassword()
string Login::getPassword() { return this->password; }


/*********************�α׾ƿ�************************/
//�α׾ƿ� control class
Logout::Logout() {
    
    // 1. startInterface
    printf("1. LogoutUl\n");
    LogoutUI logoutUI;

    // 2.clickLogout
    logoutUI.clickLogout(this);

    // 3. printOutput
    logoutUI.printOutput(this);
}

//�α׾ƿ� control class : logoutClient()
string Logout::logoutClient(string id) {
    printf("2.1 logoutClient\n");

    this->id = id;
    return "None";
}

//�α׾ƿ� control class : getId()
string Logout::getId() {
    return this->id;
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
    secessionUI.printOutput(this);
};

//Ż���ϱ� control class : deleteClient()
string Secession::deleteClient(Client* client, string id) {
    printf("2.1.1 deleteClient\n");

    //��������
    this->id = id;

    // 2.1.1.1 deleteClient
    client->deleteClient(id);

    return "None";
}

//Ż���ϱ� control class : getId()
string Secession::getId() { return this->id; }
