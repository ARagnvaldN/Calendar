#include <iostream>
#include "gregorian.hpp"
#include "julian.hpp"

using namespace std;
using namespace lab2;

int main()
{
	
	

	//lab2::Julian j(2140, 8, 9);

	//j.add_year(18);
	//cout << j << endl;
	//for (size_t i = 0; i < 1000; i++)
	//{
	//	cout << j << endl;
	//	j++;
	//}

	

	//lab2::Gregorian g(2015, 10, 25);
	//for (size_t i = 0; i < 20; i++)
	//{
	//	std::cout << g << std::endl;
	//	std::cout << g.week_day_name() << std::endl;
	//	g++;
	//}

	//lab2::Gregorian g2(1965, 3, 25);
	//for (size_t i = 0; i < 20; i++)
	//{
	//	std::cout << g2 << std::endl;
	//	std::cout << g2.week_day_name() << std::endl;
	//	g2++;
	//}

	//std::srand(time(0));
	//cout << "hello calendar" << endl;

	//cout << "======================" << endl;

	//Calendar<Gregorian> c;
	//Calendar<Gregorian> c2;
	//c2.set_date(2015, 2, 28);

	//cout << c << endl;
	//cout << c2 << endl;

	//c.add_event("Julafton", 2015, 12, 24);
	//c.add_event("Födelsedag", 2015, 5, 31);
	//c.add_event("Födelsedag", 2015, 8, 26);
	//c.add_event("May the Fourth be with you!", 2015, 5, 4);

	//cout << c << endl;

	//cout << "======================" << endl;

	//Calendar<Gregorian> cal;
	//cal.set_date(2015, 12, 2);
	//cal.add_event("Basketträning", 4, 12, 2015);
	//cal.add_event("Basketträning", 11, 12, 2015);
	//cal.add_event("Nyårsfrukost", 1, 1, 2016);
	//cal.add_event("Första advent", 1); // år = 2015, månad = 12
	//cal.add_event("Vårdagjämning", 20, 3); // år = 2015
	//cal.add_event("Julafton", 24, 12);
	//cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
	//cal.add_event("Julafton", 24); // En likadan händelse samma datum ska
	//							   // ignoreras och inte sättas in i kalendern
	//cal.add_event("Min första cykel", 20, 12, 2015);
	//cal.remove_event("Basketträning", 4);
	//std::cout << cal; // OBS! Vårdagjämning och första advent är
	//				  // före nuvarande datum och skrivs inte ut
	//std::cout << "----------------------------------------" << std::endl;
	//cal.remove_event("Vårdagjämning", 20, 3, 2015);
	//cal.remove_event("Kalle Anka hälsar god jul", 24, 12, 2015);
	//cal.set_date(2015, 11, 2);
	//if (!cal.remove_event("Julafton", 24)) {
	//	std::cout << " cal.remove_event(\"Julafton\", 24) tar inte" << std::endl
	//		<< " bort något eftersom aktuell månad är november" << std::endl;
	//}
	//std::cout << "----------------------------------------" << std::endl;
	//std::cout << cal;

	/*Gregorian g;
	Julian j;
	Gregorian g2(j);
	Gregorian g3(2015, 10, 28);
	Gregorian g4(2016, 2, 29);
	Gregorian epoch(1970, 1, 1);

	cout << g.timeDiff() << endl;
	cout << g<< endl;
	cout << g.week_day() << " " << g.week_day_name() << endl;
	cout << g.days_this_month() << " " << g.month_name() << endl;
	cout << "======================" << endl;
	cout << g2.timeDiff() << endl;
	cout << g2 << endl;
	cout << g2.week_day() << " " << g2.week_day_name() << endl;
	cout << g2.days_this_month() << " " << g2.month_name() << endl;
	cout << "======================" << endl;
	cout << g3.timeDiff() << endl;
	cout << g3 << endl;
	cout << g3.week_day() << " " << g3.week_day_name() << endl;
	cout << g3.days_this_month() << " " << g3.month_name() << endl;
	cout << "======================" << endl;
	cout << g4.timeDiff() << endl;
	cout << g4 << endl;
	cout << g4 << " " << g4 << endl;
	cout << g4.week_day() << " " << g4.week_day_name() << endl;
	cout << g4.days_this_month() << " " << g4.month_name() << endl;
	cout << g2.daysDiff()%7 << " " << g3.daysDiff()%7 << " " << g4.daysDiff()%7 << endl;

	cout << "======================" << endl;

	cout << g4 << endl;
	g4.add_year(1);
	cout << g4 << endl;
	g4.add_year(2);
	cout << g4 << endl;

	cout << "======================" << endl;

	g4.add_month(3);
	cout << g4 << endl;
	g4.add_month(13);
	cout << g4 << endl;
	g4.add_month(26);
	cout << g4 << endl;

	cout << "======================" << endl;

	Gregorian g5(1858, 11, 17);
	cout << g5.mod_julian_day() << endl;
	g5.add_day(-1);
	cout << g5.mod_julian_day() << endl;

	cout << "======================" << endl;

	cout << g3 << endl;
	for (int i = 0; i < 10; i++)
		cout << ++g3 << endl;
	for (int i = 0; i < 10; i++)
		cout << --g3 << endl;

	cout << "======================" << endl;

	cout << g3 << endl;
	cout << g3++ << endl;
	cout << g3 << endl;
	cout << g3-- << endl;
	cout << g3 << endl;

	cout << "======================" << endl;

	cout << epoch << endl;
	Gregorian ge = epoch;
	cout << epoch << " == " << ge << " : " << (epoch == ge) << endl;
	ge+=15;
	cout << epoch << " != " << ge << " : " << (epoch != ge) << endl;
	cout << epoch << " < " << ge << " : " << (epoch < ge) << endl;
	cout << epoch << " <= " << ge << " : " << (epoch <= ge) << endl;
	cout << epoch << " > " << ge << " : " << (epoch > ge) << endl;
	cout << epoch << " >= " << ge << " : " << (epoch >= ge) << endl;

	cout << ge << endl;
	cout << epoch - ge << endl;

	*/
//
//	Gregorian g(1900, 1, 1);
//	Julian j(1900, 1, 1);
//
//	cout << "Greg: " << g << " Jul: " << Julian(g) << endl;
//	cout << "Jul: " << j << " Greg: " << Gregorian(j) << endl;
//	g = Gregorian(1858, 11, 16);
//	cout << "Greg: " << g << " Jul: " << Julian(g) << " MJD: " << g.mod_julian_day() << endl;
//	g++;
//	cout << "Greg: " << g << " Jul: " << Julian(g) << " MJD: " << g.mod_julian_day() << endl;
//	g++;
//	cout << "Greg: " << g << " Jul: " << Julian(g) << " MJD: " << g.mod_julian_day() << endl;
//
//	cout << "======================" << endl;
//{
//	Gregorian g(1900, 1, 1);
//	Julian j(1899, 12, 19);
//	cout << "false: " << (j == g) << endl; // shall yield false
//	j++; // increment ‘j‘ by one day
//	cout << "true: " << (j == g) << endl; // shall yield true
//}
//{ 
//	Gregorian g(1858, 11, 16);
//	Julian j(g);
//	std::cout << j << " = 1858-11-4" << endl;
//	std::cout << g << " = 1858-11-16" << endl;
//}
//{ 
//	Date * p1 = new Julian();
//	Date * p2 = new Gregorian();
//	cout << *p1 << " " << *p2 << endl;
//	cout << "true: " << (*p1 == *p2) << endl; // shall be true
//	delete p1;
//	delete p2;
//}
	
	//int errs = 0;
	//int y, m, d;
	//for (int i = 0; i < 10000; ++i) {
	//	y = 2000 + rand() % 400 - 200;
	//	m = rand() % 12 + 1;
	//	d = rand() % 31 + 1;
	//	bool valid = true;

	//	Gregorian * gp = nullptr;
	//	try {
	//		gp = new Gregorian(y, m, d);
	//	}
	//	catch (invalid_argument) {
	//		valid = false;
	//	}
	//	if (valid && !(gp->year() == y &&
	//		gp->month() == m && gp->day() == d)) {
	//		cout << y << " " << m << " " << d << endl;
	//		cout << gp->date() << endl;
	//		cout << "ERROR!" << endl;
	//		++errs;
	//	}
	//	else
	//		cout << i << " complete" << endl;
	//	delete gp;
	//}
	//cout << "No of errors: " << errs << endl;

	return EXIT_SUCCESS;
}