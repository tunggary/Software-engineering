#include "header.h"

Product::Product() {
	this->evaluationSum = 0;
	this->evaluationAvg = 0.0;
	this->saleing = 0;
}
string Product::getSellerId() { return this->sellerId; }
string Product::getProductName() { return this->productName; }
string Product::getProductCompanyName() { return this->productCompanyName; }
int Product::getPrice() { return this->price; }
int Product::getRemaining() { return this->remaining; }
int Product::getSaleing() { return this->saleing; }
int Product::getEvaluationSum() {return this->evaluationSum;}
float Product::getEvaluationAvg() { return this->evaluationAvg; }
void Product::setSellerId(string sellerId) { this->sellerId = sellerId; }
void Product::setProductName(string productName) { this->productName = productName; }
void Product::setProductCompanyName(string productCompanyName) { this->productCompanyName = productCompanyName; }
void Product::setPrice(int price) { this->price = price; }
void Product::setRemaining(int remaining) { this->remaining = remaining; }
void Product::setSaleing(int saleing) { this->saleing = saleing; }
void Product::setEvaluationSum(int evaluation) { this->evaluationSum += evaluation; }
void Product::setEvaluationAvg(float evaluationAvg) { this->evaluationAvg = evaluationAvg; }



