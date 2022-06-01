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
ClientList clientList;
ProductList productList;
string currentLoginClient = "None";
string searchProductName = "hat";

/*********************회원가입************************/
//회원가입 boundary class : inputInfo()
void SignupUI::inputInfo(Signup* signup) {
    printf("2. inputInfo\n");
    
    //회원가입 정보를 입력받음
    string name, id, password;
    int identificationNumber;
    fin >> name >> identificationNumber >> id >> password;

    //정보저장
    this->name = name;
    this->id = id;
    this->password = password;
    this->identificationNumber = identificationNumber;

    // 2.1 addNewClient
    signup->addNewClient(&clientList, name, id, password, identificationNumber);
};


//회원가입 boundary class : printOutput()
void SignupUI::printOutput() {
    printf("3. printOutput\n\n");

    fout << "1.1. 회원가입" << endl;
    fout << '>' << ' ' << name << ' ' << identificationNumber <<  ' ' << id << ' ' << password << endl;
};

/*********************로그인************************/
//로그인 boundary class : inputInfo()
void LoginUI::inputIdPassword(Login* login) {
    printf("2. inputIdPassword\n");

    //로그인 정보를 입력받음
    string id, password;
    fin >>  id >> password;

    //정보 저장
    this->id = id;
    this->password = password;

    // 2.1 loginClient
    currentLoginClient = login->loginClient(&clientList, id, password);
};

//로그인 boundary class : printOutput()
void LoginUI::printOutput() {
    printf("3. printOutput\n\n");

    fout << "2.1. 로그인" << endl;
    fout << '>' << ' ' << id << ' ' << password << endl;
};

/*********************로그아웃************************/
//로그아웃 boundary class : inputInfo()
void LogoutUI::clickLogout(Logout* logout) {
    printf("2. clickLogout\n");

    this->id = currentLoginClient;

    // 2.1 logoutClient
    currentLoginClient = logout->logoutClient(currentLoginClient);
};

//로그아웃 boundary class : printOutput()
void LogoutUI::printOutput() {
    printf("3. printOutput\n\n");

    fout << "2.2. 로그아웃" << endl;
    fout << '>' << ' ' << id  << endl;
};

/*********************탈퇴하기************************/
//탈퇴하기 boundary class : clickSecessoion()
void SecessionUI::clickSecession(Secession* secession) {
    printf("2.1 clickSecession\n");

    //정보저장
    this->id = currentLoginClient;

    // 2.1.1 deleteClient
    currentLoginClient = secession->deleteClient(&clientList, currentLoginClient);
}

//탈퇴하기 boundary class : printOutput()
void SecessionUI::printOutput() {
    printf("3. printOutput\n\n");

    fout << "1.2. 회원탈퇴" << endl;
    fout << '>' << ' ' << id << endl;
};

/*********************판매상품 등록하기************************/
//판매상품 등록하기 boundary class : inputSaleProductInfo()
void RegisterNewSaleUI::inputSaleProductInfo(RegisterNewSale* registerNewSale){
    printf("2. inputSaleProductInfo\n");

    //판매상품 정보 입력받음
    string productName, productCompanyName;
    int price, remaining;
    fin >> productName >> productCompanyName >> price >> remaining;

    //정보저장
    this->productName = productName;
    this->productCompanyName = productCompanyName;
    this->price = price;
    this->remaining = remaining;

    // 2.1 registerSaleProduct 
    registerNewSale->registerSaleProduct(&productList, &clientList, currentLoginClient, productName, productCompanyName, price, remaining);
}

//판매상품 등록하기 boundary class : printOutput()
void RegisterNewSaleUI::printOutput(){
    printf("3. printOutput\n\n");

    fout << "3.1. 판매 의류 등록" << endl;
    fout << '>' << ' ' << productName << ' ' << productCompanyName << ' ' << price << ' ' << remaining  << endl;
}

/*********************판매통계 조회하기************************/
//판매통계 조회하기 boundary class : printOutput()
void InquireSaleStatsUI::printOutput(ProductDetail* statsDetails) {
    printf("2. printOutput\n\n");

    fout << "5.1. 판매 상품 통계" << endl;
    for (int i = 0; i < MAX_COUNT; i++) {
        string productName = statsDetails[i].productName;
        int total = statsDetails[i].total;
        float average = statsDetails[i].average;
        if (total == 0) break;
        fout << '>' << ' ' << productName << ' ' <<  total << ' ' << average << endl;
    }
}

/*********************상품 구매하기************************/
//판매통계 조회하기 boundary class : printOutput()
void BuyProductUI::clickPurchaseButton(BuyProduct* buyProduct) {
    printf("2. clickPurchaseButton\n");

    // 2.1. buyProduct
    string sellerId = buyProduct->buyProduct(&productList, &clientList, currentLoginClient, searchProductName);
    this->sellerId = sellerId;
    this->productName = searchProductName;
}

void BuyProductUI::printOutput() {
    printf("3. printOutput\n\n");

    fout << "4.2. 상품 구매" << endl;
    fout << '>' << ' ' << sellerId << ' ' << productName << endl;
}

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
                printf("판매하기\n");
                RegisterNewSale registerNewSale;
                break;
            }
            case 2:
                printf("판매상품조회\n");
                fout << "3.2. 등록 상품 조회" << endl;
                break;
            case 3:
                printf("판매완료상품조회\n");
                fout << "3.3. 판매 완료 상품 조회" << endl;
                break;
            default:
                break;
            }
            break;
        case 4:
            switch (menu_level_2) {
            case 1: {
                printf("검색하기\n");
                string productName;
                fin >> productName;

                fout << "4.1. 상품 정보 검색" << endl;
                break;
            }
            case 2: {
                printf("구매하기\n");
                BuyProduct buyProduct;
                break;
            }
            case 3:
                printf("구매내역조회하기\n");
                fout << "4.3. 상품 구매 내역 조회" << endl;
                break;
            case 4:
                printf("만족도평가\n");
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
            case 1: {
                printf("판매통계\n");
                InquireSaleStats inquireSaleStats(&clientList, currentLoginClient);
                break;
            }
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