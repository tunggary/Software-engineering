#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;

#define MAX_COUNT 1000


void Client::createClient(string name, string id, string password, int identificationNumber) {
    printf("2.1.1 createClient\n");

    EachClient* clientList = this->clientList;
    int clientNumber = this->clientNumber;
    
    //���ο� �����߰�
    clientList[clientNumber].name = name;
    clientList[clientNumber].id = id;
    clientList[clientNumber].password = password;
    clientList[clientNumber].identificationNumber = identificationNumber;
    this->clientNumber += 1;
};

string Client::loginClient(string id, string password) {
    printf("2.1.1 loginClient\n");

    //id�� password�� �´� ���� ã��
    EachClient* clientList = this->clientList;
    for (int i = 0; i <= this->clientNumber; i++) {
        if (clientList[i].id == id && clientList[i].password == password) {
            return clientList[i].id;
        }
    }
    return "None";
}

void Client::deleteClient(string id) {
    printf("2.1.1.1 deleteClient\n");

    //id�� �´� ���� ã�Ƽ� ����
    EachClient* clientList = this->clientList;
    int clientNumber = this->clientNumber;
    int deleteClient = 0;
    for (int i = 0; i <= this->clientNumber; i++) {
        if (clientList[i].id == id) {
            memmove(clientList + i, clientList + i + 1, sizeof(EachClient)*(MAX_COUNT-(i+1)));
            this->clientNumber -= 1;
            break;
        }
    }
}
