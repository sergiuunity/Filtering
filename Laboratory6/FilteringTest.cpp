#include "FilteringTest.h"
#include <cassert>

void FilteringTest::runAllTests()
{
	test_getPrice();
	test_getType();
	test_setPrice();
	test_setType();
	test_filterPrice();
	test_filterType();
	test_filterDeparture();
	test_filterDestination();
}

void FilteringTest::test_getPrice()
{
	FilteringCriteriaPrice my_filter(3);
	assert(my_filter.getPrice() == 3);
	FilteringCriteriaPrice my_filter2;
	assert(my_filter2.getPrice() == 0);

}

void FilteringTest::test_getType()
{
	FilteringCriteriaType my_filter(3);
	assert(my_filter.getType() == OfferType(3));
	FilteringCriteriaType my_filter2;
	assert(my_filter2.getType() == OfferType(0));
}

void FilteringTest::test_setPrice()
{
	FilteringCriteriaPrice my_filter;
	my_filter.setPrice(77);
	assert(my_filter.getPrice() == 77);
}

void FilteringTest::test_setType()
{
	FilteringCriteriaType my_filter;
	my_filter.setType(1);
	assert(my_filter.getType() == OfferType(1));

}


void FilteringTest::test_filterPrice()
{	
	DynamicArray<Offer> allOffers;
	DynamicArray<Offer> o;
	FilteringCriteriaPrice my_filter(100);
	FilteringCriteriaPrice my_filter2(1000);
	assert(my_filter.filter(o) == DynamicArray<Offer>());

	Offer e1("1", 397, "Cluj-Napoca", "Rome", "10.07.2022", "14.07.2022", 2);
	Offer e2("2", 997, "Bucharest", "New York", "05.09.2022", "10.09.2022", 2);
	Offer e3("3", 1297, "Bucharest", "Maldives", "13.06.2022", "20.06.2022", 4);
	Offer e4("4", 1097, "Bucharest", "Seychelles", "14.07.2022", "21.07.2022", 4);
	Offer e5("5", 1150, "Budapest", "Port of Spain", "20.07.2022", "27.07.2022", 3);
	Offer e6("6", 850, "Cluj-Napoca", "Alexandria-Cairo-Luxor", "10.06.2022", "15.06.2022", 1);

	allOffers.append(e1);
	allOffers.append(e2);
	allOffers.append(e3);
	allOffers.append(e4);
	allOffers.append(e5);
	allOffers.append(e6);

	DynamicArray<Offer> wantedResult;
	wantedResult.append(e1);
	wantedResult.append(e2);
	wantedResult.append(e6);
	assert(my_filter2.filter(allOffers) == wantedResult);

}

void FilteringTest::test_filterType()
{
	DynamicArray<Offer> allOffers;
	DynamicArray<Offer> o;
	FilteringCriteriaType my_filter(4);
	FilteringCriteriaType my_filter2(2);
	FilteringCriteriaType my_filter3;
	assert(my_filter.filter(o) == DynamicArray<Offer>());

	Offer e1("1", 397, "Cluj-Napoca", "Rome", "10.07.2022", "14.07.2022", 2);
	Offer e2("2", 997, "Bucharest", "New York", "05.09.2022", "10.09.2022", 2);
	Offer e3("3", 1297, "Bucharest", "Maldives", "13.06.2022", "20.06.2022", 4);
	Offer e4("4", 1097, "Bucharest", "Seychelles", "14.07.2022", "21.07.2022", 4);
	Offer e5("5", 1150, "Budapest", "Port of Spain", "20.07.2022", "27.07.2022", 3);
	Offer e6("6", 850, "Cluj-Napoca", "Alexandria-Cairo-Luxor", "10.06.2022", "15.06.2022", 1);

	allOffers.append(e1);
	allOffers.append(e2);
	allOffers.append(e3);
	allOffers.append(e4);
	allOffers.append(e5);
	allOffers.append(e6);

	DynamicArray<Offer> wantedResult;
	wantedResult.append(e1);
	wantedResult.append(e2);

	assert(my_filter2.filter(allOffers) == wantedResult);
	assert(my_filter3.filter(allOffers) == DynamicArray<Offer>());
}

void FilteringTest::test_filterDeparture()
{
	FilteringCriteriaDeparture my_filter;
	assert(my_filter.getDeparture() == "");
	my_filter = FilteringCriteriaDeparture("Bucharest");
	assert(my_filter.getDeparture() == "Bucharest");
	my_filter.setDeparture("Here");
	assert(my_filter.getDeparture() == "Here");

	Offer e1("1", 397, "Cluj-Napoca", "Rome", "10.07.2022", "14.07.2022", 2);
	Offer e2("2", 997, "Bucharest", "New York", "05.09.2022", "10.09.2022", 2);
	Offer e3("3", 1297, "Bucharest", "Maldives", "13.06.2022", "20.06.2022", 4);
	Offer e4("4", 1097, "Bucharest", "Seychelles", "14.07.2022", "21.07.2022", 4);
	Offer e5("5", 1150, "Budapest", "Port of Spain", "20.07.2022", "27.07.2022", 3);
	Offer e6("6", 850, "Cluj-Napoca", "Alexandria-Cairo-Luxor", "10.06.2022", "15.06.2022", 1);
	
	DynamicArray<Offer> allOffers;
	DynamicArray<Offer> WANTED;
	allOffers.append(e1);
	allOffers.append(e2);
	allOffers.append(e3);
	allOffers.append(e4);
	allOffers.append(e5);
	allOffers.append(e6);
	WANTED.append(e1);
	WANTED.append(e6);
	my_filter = FilteringCriteriaDeparture("Cluj-Napoca");
	assert(my_filter.filter(allOffers) == WANTED);

}

void FilteringTest::test_filterDestination()
{
	FilteringCriteriaDestination my_filter;
	assert(my_filter.getDestination() == "");
	my_filter = FilteringCriteriaDestination("Bucharest");
	assert(my_filter.getDestination() == "Bucharest");
	my_filter.setDestination("Here");
	assert(my_filter.getDestination() == "Here");

	Offer e1("1", 397, "Cluj-Napoca", "Rome", "10.07.2022", "14.07.2022", 2);
	Offer e2("2", 997, "Bucharest", "New York", "05.09.2022", "10.09.2022", 2);
	Offer e3("3", 1297, "Bucharest", "Rome", "13.06.2022", "20.06.2022", 2);
	Offer e4("4", 1097, "Bucharest", "Seychelles", "14.07.2022", "21.07.2022", 4);
	Offer e5("5", 1150, "Budapest", "Port of Spain", "20.07.2022", "27.07.2022", 3);
	Offer e6("6", 850, "Cluj-Napoca", "Alexandria-Cairo-Luxor", "10.06.2022", "15.06.2022", 1);

	DynamicArray<Offer> allOffers;
	DynamicArray<Offer> WANTED;
	allOffers.append(e1);
	allOffers.append(e2);
	allOffers.append(e3);
	allOffers.append(e4);
	allOffers.append(e5);
	allOffers.append(e6);
	WANTED.append(e1);
	WANTED.append(e3);
	my_filter = FilteringCriteriaDestination("Rome");
	assert(my_filter.filter(allOffers) == WANTED);

}

//void FilteringTest::test_filterTypeAndPrice()
//{
//	DynamicArray<Offer> allOffers;
//	DynamicArray<Offer> o;
//	FilteringCriteriaTypeAndPrice my_filter;
//	FilteringCriteriaTypeAndPrice my_filter2(2, 500);
//	FilteringCriteriaTypeAndPrice my_filter3(100, 4);
//	FilteringCriteriaTypeAndPrice my_filter4(2000, 0);
//	FilteringCriteriaTypeAndPrice my_filter5(2, 397);
//	assert(my_filter.filter(o) == DynamicArray<Offer>());
//
//	Offer e1("1", 397, "Cluj-Napoca", "Rome", "10.07.2022", "14.07.2022", 2);
//	Offer e2("2", 997, "Bucharest", "New York", "05.09.2022", "10.09.2022", 2);
//	Offer e3("3", 1297, "Bucharest", "Maldives", "13.06.2022", "20.06.2022", 4);
//	Offer e4("4", 1097, "Bucharest", "Seychelles", "14.07.2022", "21.07.2022", 4);
//	Offer e5("5", 1150, "Budapest", "Port of Spain", "20.07.2022", "27.07.2022", 3);
//	Offer e6("6", 850, "Cluj-Napoca", "Alexandria-Cairo-Luxor", "10.06.2022", "15.06.2022", 1);
//
//	allOffers.append(e1);
//	allOffers.append(e2);
//	allOffers.append(e3);
//	allOffers.append(e4);
//	allOffers.append(e5);
//	allOffers.append(e6);
//
//	DynamicArray<Offer> wantedResult;
//	wantedResult.append(e1);
//
//	assert(my_filter2.filter(allOffers) == wantedResult);
//	assert(my_filter3.filter(allOffers) == DynamicArray<Offer>());
//	assert(my_filter4.filter(allOffers) == DynamicArray<Offer>());
//	assert(my_filter5.filter(allOffers) == DynamicArray<Offer>());
//}
