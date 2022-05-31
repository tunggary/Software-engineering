// 헤더 선언
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include "header.h"
using namespace std;


// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void program_exit();

// 변수 선언
ifstream fin;
ofstream fout;
Client client;
string currentLoginClient = "None";

//회원가입 boundary class : inputInfo()
void SignupUI::inputInfo(Signup* signup) {
    printf("2. inputInfo\n");
    
    //회원가입 정보를 입력받음
    string name, id, password;
    int identificationNumber;
    fin >> name >> identificationNumber >> id >> password;

    // 2.1 addNewClient
    signup->addNewClient(&client, name, id, password, identificationNumber);
};


//회원가입 boundary class : printOutput()
void SignupUI::printOutput(Signup* signup) {
    printf("3. printOutput\n\n");

    fout << "1.1. 회원가입" << endl;
    fout << '>' << ' ' << signup -> getName() << ' ' << signup -> getIdentificationNumber() <<  ' ' << signup -> getId() << ' ' << signup -> getPassword() << endl;
};

//로그인 boundary class : inputInfo()
void LoginUI::inputIdPassword(Login* login) {
    printf("2. inputIdPassword\n");

    //로그인 정보를 입력받음
    string id, password;
    fin >>  id >> password;

    // 2.1 loginClient
    currentLoginClient = login->loginClient(&client, id, password);
};

//로그인 boundary class : printOutput()
void LoginUI::printOutput(Login* login) {
    printf("3. printOutput\n\n");

    fout << "2.1. 로그인" << endl;
    fout << '>' << ' ' << login->getId() << ' ' << login->getPassword() << endl;
};

//로그아웃 boundary class : inputInfo()
void LogoutUI::clickLogout(Logout* logout) {
    printf("2. clickLogout\n");

    // 2.1 logoutClient
    currentLoginClient = logout->logoutClient(currentLoginClient);
};

//로그아웃 boundary class : printOutput()
void LogoutUI::printOutput(Logout* logout) {
    printf("3. printOutput\n\n");

    fout << "2.2. 로그아웃" << endl;
    fout << '>' << ' ' << logout->getId()  << endl;
};

//탈퇴하기 boundary class : clickSecessoion()
void SecessionUI::clickSecession(Secession* secession) {
    printf("2.1 clickSecession\n");

    // 2.1.1 deleteClient
    currentLoginClient = secession->deleteClient(&client, currentLoginClient);
}

//탈퇴하기 boundary class : printOutput()
void SecessionUI::printOutput(Secession* secession) {
    printf("3. printOutput\n\n");

    fout << "1.2. 회원탈퇴" << endl;
    fout << '>' << ' ' << secession->getId() << endl;
};

int main()
{
    // 파일 입출력을 위한 초기화
    fin.open(INPUT_FILE_NAME);
    fout.open(OUTPUT_FILE_NAME);

    doTask();

    return 0;
}

void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!fin.eof() || !is_program_exit)
    {
        cout << "현재 로그인 유저 : " << currentLoginClient << endl;

        // 입력파일에서 메뉴 숫자 2개를 읽기
        fin >> menu_level_1 >> menu_level_2;

        switch (menu_level_1) {
        case 1:
            switch (menu_level_2) {
            case 1: {
                printf("회원가입\n");
                Signup signup;
                break; 
            }
            case 2: {
                printf("탈퇴하기\n");
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
                printf("로그인\n");
                Login login;
                break; 
            }
            case 2: {
                printf("로그아웃\n");
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

                fout << "3.1. 판매 의류 등록" << endl;
                break;
            }
            case 2:
                fout << "3.2. 등록 상품 조회" << endl;
                break;
            case 3:
                fout << "3.3. 판매 완료 상품 조회" << endl;
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
                fout << "4.1. 상품 정보 검색" << endl;
                break;
            }
            case 2:
                fout << "4.2. 상품 구매" << endl;
                break;
            case 3:
                fout << "4.3. 상품 구매 내역 조회" << endl;
                break;
            case 4:
                int evaluation;
                fin >> evaluation;
                fout << "4.4. 상품 구매만족도 평가" << endl;
                break;
            default:
                break;
            }
            break;
        case 5:
            switch (menu_level_2) {
            case 1:
                fout << "5.1. 판매 상품 통계" << endl;
                break;
            default:
                break;
            }
            break;
        case 6:
            switch (menu_level_2) {
            case 1:
                fout << "6.1. 종료" << endl;
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