#include "OfferTest.h"
#include "FilteringTest.h"
#include "DynamicArrayTest.h"
#include "FilteringCriteria.h"

#include <iostream>
#include <string>
using namespace std;

#include "DynamicArray.h"

void displayMenu() {
	cout << "M|m     Display the menu" << endl;
	cout << "I|i     Show available types" << endl;
	cout << "A|a     Add an offer" << endl;
	cout << "S|s     Show all offers" << endl;
	cout << "P|p     Filters offers by price" << endl;
	cout << "T|t     Filters offers by type" << endl;
	cout << "B|b     Filter offer by type and price" << endl;
	cout << "Q|q     Quit" << endl << endl;
}


int main() {

	OfferTest::runAllTests();
	FilteringTest::runAllTests();
	DynamicArrayTest::runAllTests();

	DynamicArray<Offer> allOffers;


	//EXAMPLES
	Offer e1("1", 397, "Cluj-Napoca", "Rome", "10.07.2022", "14.07.2022", 2);
	Offer e2("2", 997, "Bucharest", "New York", "05.09.2022", "10.09.2022", 2);
	Offer e3("3", 1297, "Bucharest", "Maldives", "13.06.2022", "20.06.2022", 4);
	Offer e4("4", 1097, "Bucharest", "Seychelles", "14.07.2022", "21.07.2022", 4);
	Offer e5("5", 1150, "Budapest", "Port of Spain", "20.07.2022", "27.07.2022", 3);
	Offer e6("6", 850, "Cluj-Napoca", "Alexandria-Cairo-Luxor", "10.06.2022", "15.06.2022", 1);
	Offer e7("7", 997, "Here", "New York", "05.09.2022", "10.09.2022", 2);
	
	allOffers.append(e1);
	allOffers.append(e2);
	allOffers.append(e3);
	allOffers.append(e4);
	allOffers.append(e5);
	allOffers.append(e6);
	allOffers.append(e7);


	//FilteringCriteriaAnd* filter = new FilteringCriteriaDeparture("Cluj-Napoca");

	FilteringCriteriaAnd* filter = new FilteringCriteriaDestination("New York");

	
	cout<< filter->filter(allOffers);

	return 0;
}