#pragma once
#include "DynamicArray.h"
#include <iostream>


// you can add all your filtering classes in this module
class FilteringCriteria
{
public:
	//filter
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);

private:
};


class FilteringPrice : public FilteringCriteria
{
public:
	//getters and setters
	float getPrice()const;
	void setPrice(float price);

	//constructors
	FilteringPrice();

	FilteringPrice(float price);

	//filter
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);



private:
	float price;
};

class FilteringType : public FilteringCriteria
{
public:
	//getters and setters
	OfferType getType()const;
	void setType(int type);

	//constructors
	FilteringType();

	FilteringType(int type);

	//filter
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);



private:
	OfferType type;
};


class FilteringCriteriaTypeAndPrice : public FilteringCriteria
{
public:
	//getters and setters
	OfferType getType()const;
	float getPrice()const;

	void setType(int type);
	void setPrice(float price);

	//constructors
	FilteringCriteriaTypeAndPrice();

	FilteringCriteriaTypeAndPrice(int type, float price);

	//filter
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);


private:
	OfferType type;
	float price;
};



class FilteringCriteriaAnd
{
public:
	virtual DynamicArray<Offer> filter(DynamicArray<Offer>& data) = 0;

private:

};



class FilteringCriteriaDeparture : public FilteringCriteriaAnd
{
public:

	//getters and setters
	string getDeparture()const;
	void setDeparture(string departure);

	//constructors
	FilteringCriteriaDeparture();

	FilteringCriteriaDeparture(string departure);

	//filter
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);



private:
	string departure;


};

class FilteringCriteriaDestination : public FilteringCriteriaAnd
{
public:

	//getters and setters
	string getDestination()const;
	void setDestination(string Destination);

	//constructors
	FilteringCriteriaDestination();

	FilteringCriteriaDestination(string Destination);

	//filter
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);



private:
	string destination;


};