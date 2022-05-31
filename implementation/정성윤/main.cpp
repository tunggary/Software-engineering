// ��� ����
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include "header.h"
using namespace std;


// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask();
void program_exit();

// ���� ����
ifstream fin;
ofstream fout;
Client client;
string currentLoginClient = "None";

//ȸ������ boundary class : inputInfo()
void SignupUI::inputInfo(Signup* signup) {
    printf("2. inputInfo\n");
    
    //ȸ������ ������ �Է¹���
    string name, id, password;
    int identificationNumber;
    fin >> name >> identificationNumber >> id >> password;

    // 2.1 addNewClient
    signup->addNewClient(&client, name, id, password, identificationNumber);
};


//ȸ������ boundary class : printOutput()
void SignupUI::printOutput(Signup* signup) {
    printf("3. printOutput\n\n");

    fout << "1.1. ȸ������" << endl;
    fout << '>' << ' ' << signup -> getName() << ' ' << signup -> getIdentificationNumber() <<  ' ' << signup -> getId() << ' ' << signup -> getPassword() << endl;
};

//�α��� boundary class : inputInfo()
void LoginUI::inputIdPassword(Login* login) {
    printf("2. inputIdPassword\n");

    //�α��� ������ �Է¹���
    string id, password;
    fin >>  id >> password;

    // 2.1 loginClient
    currentLoginClient = login->loginClient(&client, id, password);
};

//�α��� boundary class : printOutput()
void LoginUI::printOutput(Login* login) {
    printf("3. printOutput\n\n");

    fout << "2.1. �α���" << endl;
    fout << '>' << ' ' << login->getId() << ' ' << login->getPassword() << endl;
};

//�α׾ƿ� boundary class : inputInfo()
void LogoutUI::clickLogout(Logout* logout) {
    printf("2. clickLogout\n");

    // 2.1 logoutClient
    currentLoginClient = logout->logoutClient(currentLoginClient);
};

//�α׾ƿ� boundary class : printOutput()
void LogoutUI::printOutput(Logout* logout) {
    printf("3. printOutput\n\n");

    fout << "2.2. �α׾ƿ�" << endl;
    fout << '>' << ' ' << logout->getId()  << endl;
};

//Ż���ϱ� boundary class : clickSecessoion()
void SecessionUI::clickSecession(Secession* secession) {
    printf("2.1 clickSecession\n");

    // 2.1.1 deleteClient
    currentLoginClient = secession->deleteClient(&client, currentLoginClient);
}

//Ż���ϱ� boundary class : printOutput()
void SecessionUI::printOutput(Secession* secession) {
    printf("3. printOutput\n\n");

    fout << "1.2. ȸ��Ż��" << endl;
    fout << '>' << ' ' << secession->getId() << endl;
};

int main()
{
    // ���� ������� ���� �ʱ�ȭ
    fin.open(INPUT_FILE_NAME);
    fout.open(OUTPUT_FILE_NAME);

    doTask();

    return 0;
}

void doTask()
{
    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!fin.eof() || !is_program_exit)
    {
        cout << "���� �α��� ���� : " << currentLoginClient << endl;

        // �Է����Ͽ��� �޴� ���� 2���� �б�
        fin >> menu_level_1 >> menu_level_2;

        switch (menu_level_1) {
        case 1:
            switch (menu_level_2) {
            case 1: {
                printf("ȸ������\n");
                Signup signup;
                break; 
            }
            case 2: {
                printf("Ż���ϱ�\n");
                Secession secessoion;
                break; 
            }
            default:
                break;
            }
            break;
        case 2:
            switch (menu_level_2) {
            case 1: {
                printf("�α���\n");
                Login login;
                break; 
            }
            case 2: {
                printf("�α׾ƿ�\n");
                Logout logout;
                break;
            }
            default:
                break;
            }
            break;
        case 3:
            switch (menu_level_2) {
            case 1: {
                string productName, productCompanyName;
                int price, remaining;
                fin >> productName >> productCompanyName >> price >> remaining;

                fout << "3.1. �Ǹ� �Ƿ� ���" << endl;
                break;
            }
            case 2:
                fout << "3.2. ��� ��ǰ ��ȸ" << endl;
                break;
            case 3:
                fout << "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ" << endl;
                break;
            default:
                break;
            }
            break;
        case 4:
            switch (menu_level_2) {
            case 1: {
                string productName;
                fin >> productName;
                fout << "4.1. ��ǰ ���� �˻�" << endl;
                break;
            }
            case 2:
                fout << "4.2. ��ǰ ����" << endl;
                break;
            case 3:
                fout << "4.3. ��ǰ ���� ���� ��ȸ" << endl;
                break;
            case 4:
                int evaluation;
                fin >> evaluation;
                fout << "4.4. ��ǰ ���Ÿ����� ��" << endl;
                break;
            default:
                break;
            }
            break;
        case 5:
            switch (menu_level_2) {
            case 1:
                fout << "5.1. �Ǹ� ��ǰ ���" << endl;
                break;
            default:
                break;
            }
            break;
        case 6:
            switch (menu_level_2) {
            case 1:
                fout << "6.1. ����" << endl;
                program_exit();
                is_program_exit = 1;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    return;
}

void program_exit()    
{
    fin.close();
    fout.close();

    return;
}