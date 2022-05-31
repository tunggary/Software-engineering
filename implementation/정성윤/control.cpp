#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;

/*********************회원가입************************/
//회원가입 control class
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

//회원가입 control class : addNewClient()
void Signup::addNewClient(Client* client, string name, string id, string password, int identificationNumber) {
    printf("2.1 addNewClient\n");

    //정보저장
    this->name = name;
    this->id = id;
    this->password = password;
    this->identificationNumber = identificationNumber;

    // 2.1.1 addNewClient
    client->createClient(name, id, password, identificationNumber);
};

//회원가입 control class : getName()
string Signup::getName() { return this->name; }

//회원가입 control class : getId()
string Signup::getId() { return this->id; }

//회원가입 control class : getPassword()
string Signup::getPassword() { return this->password; }

//회원가입 control class : getIdentificationNumber()
int Signup::getIdentificationNumber() { return this->identificationNumber; }


/*********************로그인************************/
//로그인 control class
Login::Login() {

    // 1. startInterface
    printf("1. LoginUl\n");
    LoginUI loginUI;

    // 2. inputIdPassword
    loginUI.inputIdPassword(this);

    // 3. printOutput
    loginUI.printOutput(this);
};

//로그인 control class : loginClient()
string Login::loginClient(Client* client, string id, string password) {
    printf("2.1 loginClient\n");

    //정보 저장
    this->id = id;
    this->password = password;
    
    // 2.1.1 loginClient
    string currentLoginClient =  client->loginClient(id, password);

    return currentLoginClient;
}

//로그인 control class : getId()
string Login::getId() { return this->id; }

//로그인 control class : getPassword()
string Login::getPassword() { return this->password; }


/*********************로그아웃************************/
//로그아웃 control class
Logout::Logout() {
    
    // 1. startInterface
    printf("1. LogoutUl\n");
    LogoutUI logoutUI;

    // 2.clickLogout
    logoutUI.clickLogout(this);

    // 3. printOutput
    logoutUI.printOutput(this);
}

//로그아웃 control class : logoutClient()
string Logout::logoutClient(string id) {
    printf("2.1 logoutClient\n");

    this->id = id;
    return "None";
}

//로그아웃 control class : getId()
string Logout::getId() {
    return this->id;
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
    secessionUI.printOutput(this);
};

//탈퇴하기 control class : deleteClient()
string Secession::deleteClient(Client* client, string id) {
    printf("2.1.1 deleteClient\n");

    //정보저장
    this->id = id;

    // 2.1.1.1 deleteClient
    client->deleteClient(id);

    return "None";
}

//탈퇴하기 control class : getId()
string Secession::getId() { return this->id; }
