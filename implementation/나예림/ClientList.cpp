#include "header.h"

// ȸ������ entity class : createClient()
void ClientList::createClient(string name, string id, string password, int identificationNumber) {
    printf("2.1.1 createClient\n");

    Client* clientList = this->clientList;
    int clientNumber = this->clientNumber;

    //���ο� �����߰�
    clientList[clientNumber].setName(name);
    clientList[clientNumber].setId(id);
    clientList[clientNumber].setPassword(password);
    clientList[clientNumber].setIdentificationNumber(identificationNumber);
    this->clientNumber += 1;
};

// �α��� entity class : loginClient()
string ClientList::loginClient(string id, string password) {
    printf("2.1.1 loginClient\n");

    //id�� password�� �´� ���� ã��
    Client* clientList = this->clientList;
    for (int i = 0; i < this->clientNumber; i++) {
        if (clientList[i].getId() == id && clientList[i].getPassword() == password) {
            return clientList[i].getId();
        }
    }
    return "None";
}

// Ż���ϱ� entity class : deleteClient()
void ClientList::deleteClient(string id) {
    printf("2.1.1.1 deleteClient\n");

    //id�� �´� ���� ã�Ƽ� ����
    Client* clientList = this->clientList;
    int clientNumber = this->clientNumber;
    int deleteClient = 0;
    for (int i = 0; i < this->clientNumber; i++) {
        if (clientList[i].getId() == id) {
            memmove(clientList + i, clientList + i + 1, sizeof(Client) * (MAX_COUNT - (i + 1)));
            this->clientNumber -= 1;
            break;
        }
    }
}

Client* ClientList::getClientDetail(string id) {
    printf("2.1.1. getClientDetail\n");

    for (int i = 0; i < this->clientNumber; i++) {
        if (clientList[i].getId() == id) {
            return &clientList[i];
        }
    }
}

ProductDetail* ClientList::getSaleProuductStats(string sellerId) {
    printf("1.1. getSaleProuductStats\n");

    for (int i = 0; i < this->clientNumber; i++) {
        if (clientList[i].getId() == sellerId) {
            // 1.1.1 getSaleProductStats
            return clientList[i].getSalePrductStats();
        }
    }
}