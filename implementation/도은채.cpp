#include <iostream>
#include <string>

#define MAX_STRING 32
#define TOTAL_PRO 10

using namespace std;

class Product{};
class SaleProduct{};
class SaleProductCollection{};
class RegisterNewSales{};
class RegisterNewSalesUI{};
class InquireSales{};
class InquireSalesUI{};
class InquireSalesDone{};
class InquireSalesDoneUI{};
class InquireSalesStats{};
class InquireSalesStatsUI{};


//Product 클래스 정의
class Product{
    protected:
                char sellerID[MAX_STRING];
                char productName[MAX_STRING];
                char productCompanyName[MAX_STRING];
                int productPrice;
                int productRemaining;
                double productSatisfactionAvg = 0;
    public:
                Product(char* name, char* companyName, int price, int remaining) : productName(name), productCompanyName(companyName), productPrice(price), productRemaining(remaining);
                void getProductDetails(char* productName);
                void setSatisfaction(int satisfaction);
}

//SaleProduct 클래스 정의
class SaleProduct : protected Product{
    public:          
               void getSaleProductName();
               void getSaleProductCompanyName();
               void getSaleProductPrice();
               void getSaleProductRemaining();
               void getSaleProductSatisfactionAvg();
}
//getSaleProductDetails
void SaleProduct::getSaleProductName(){
    return productName;
}
void SaleProduct::getSaleProductCompanyName(){
    return productCompanyName;
}
void SaleProduct::getSaleProductPrice(){
    return productPrice;
}
void SaleProduct::getSaleProductRemaining(){
    return productRemaining;
}
void SaleProduct::getSaleProductSatisfactionAvg(){
    return productSatisfactionAvg;
}

//SaleProductCollection 정의
class SaleProductCollection{
    private:
                char sellerID[MAX_STRING];
                ownedSaleProduct = SaleProduct[saleProductNum];
    public:
                SaleProductCollection(char* ID):sellerID(ID);
                void findFirst();
                void getNext();
                void addSaleProduct(Product pro);
                void getDetailsforStats();
}
//SaleProductCollection 리스트 관리
int saleProductNum = 1;
int saleProductCurNum = 0;
void SaleProductCollection::findFirst(){
    return ownedSaleProduct[0]
}
void SaleProductCollection::getNext(){
    return ownedSaleProduct[saleProductCurNum++];
}
void SaleProductCollection::addSaleProduct(Product pro){
    ownedSaleProduct[saleProductNum++]=pro;
}

//판매상품통계계산 - {상품명 판매총액 평균구매만족도}* 로 출력해야하는데 어떻게 바운더리에 전달하지?
void SaleProductCollection::getDetailsforStats(){
    int i = 0;
    for(i=0;i<saleProductNum;i++){
        ownedSaleProduct[i].getSaleProductName();
        //판매총액 계산 : price * 판매수량(이거 어떻게?)
        ownedSaleProduct[i].getSaleProductSatisfactionAvg();
    }
}

//판매상품등록하기
class RegisterNewSalesUI{
    public:
                void startInterface();
                //void inputSaleProductInfo();
}
class RegisterNewSales{
    public:
                void registerSaleProduct(char* name, char* companyName, int price, int remaining);
}
// 3 1 > main에서 fscanf로 [상품명][제작회사명][가격][수량] 입력 > RegisterNewSales 생성 > registerSaleProduct 호출
//registerSaleProduct > Client.addSaleProduct, new Product, startInterface
Product* productArr[TOTAL_PRO]
int productNum = 0;
void RegisterNewSales::registerSaleProduct(char* name, char* companyName, int price, int remaining){
    productArr[productNum++] = new Product(name, companyName, price, remaining);
    Client.addSaleProduct(productArr[productNum]);
    registerNewSalesUI.startInterface(name, companyName, price, remaining);
}

//client public addSaleProduct
int clientNum = 0;
void Client::addSaleProduct(Product newSaleProduct){
    clientSaleProducts.addSaleProduct(newSaleProduct);
}


//판매상품조회하기
class InquireSalesUI{
    public:
                void startInterface();
}
class InquireSales{}


//판매완료상품조회하기
class InqurieSalesDoneUI{
    public:
                void startInterface();
}
class InquireSalesDone{}

//판매통계조회하기
class InquireSalesStatsUI{
    public:
                void startInterface();
}
class InquireSalesStats{}

