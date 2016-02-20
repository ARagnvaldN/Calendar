#include "gregorian.hpp"
#include <sstream>

using namespace std;

namespace lab2 {

	const vector<string> Gregorian::WEEK_DAY_NAMES = {
		"Monday", 
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday" };

	const vector<string> Gregorian::MONTH_NAMES = { 
		"January",	"February",		"March",
		"April",	"May",			"June",
		"July",		"August",		"September",
		"October",	"November",		"December" };

	//Constructors
	Gregorian::Gregorian(time_t diff) 
	{
		timeDiff(diff);
	}

	Gregorian::Gregorian()
	{
		timeDiff(today());
	}

	Gregorian::Gregorian(const Date & source)
	{
		copy(source);
	}

	Gregorian::Gregorian(int year, int month, int day)
	{
		if (!is_valid_date(year, month, day))
			throw invalid_argument("Dates should be on format YYYY, MM, DD!");
		
		set_date(year, month, day);
	}

	//Destructor
	Gregorian::~Gregorian()
	{
	}

	unsigned int Gregorian::days_per_week() const
	{
		return NUM_DAYS_WEEK;
	}

	std::string Gregorian::week_day_name() const
	{
		return WEEK_DAY_NAMES [ week_day() -1];
	}

	std::string Gregorian::month_name() const
	{
		return MONTH_NAMES[ month() - 1 ];
	}

	Gregorian Gregorian::operator++(int unused)
	{
		Gregorian g = *this;
		add_day(1);

		return g;
	}

	Gregorian Gregorian::operator--(int unused)
	{
		Gregorian g = *this;
		add_day(-1);

		return g;
	}

	Gregorian & Gregorian::operator+=(int n)
	{
		add_day(n);
		return *this;
	}

	Gregorian & Gregorian::operator-=(int n)
	{
		add_day(-n);
		return *this;
	}

	string Gregorian::to_date_string() const
	{
		int y, m, d;
		time_to_representation(y, m, d);
		stringstream ss;
		ss << y << "-" << m << "-" << d;
		return ss.str();
	}

	bool Gregorian::is_valid_date(int year, int month, int day) const
	{
		if (year < ALPHA || year > BETA)
			throw std::out_of_range("The calendar is only tested between 1500-2700");

		if(month < 1 || month > NUM_MONTHS)
			return false;
		if (day < 1 || day > days_of_month(month, year))
			return false;

		return true;
	}

	void Gregorian::representation_to_time(int year, int month, int day, time_t & time) const
	{
		time = 0;

		time += days_between(epoch_year(), epoch_month(), epoch_day(),
		//time += days_between(EPOCH_YEAR, EPOCH_MONTH, EPOCH_DAY,
			year, month, day);

		time *= DAY;

	}

	void Gregorian::time_to_representation(int & year, int & month, int & day) const
	{

		year = epoch_year();
		month = epoch_month();
		day = epoch_day();

		time_t days = 0;

		days = daysDiff();

		while (days > 0) {
			day++;
			if (day > days_of_month(month, year)) {
				month++;
				day = 1;
			}
			if (month > NUM_MONTHS) {
				year++;
				month = 1;
			}
			days--;
		}

		while (days < 0) {
			day--;
			if (day < 1) {
				month--;
				if (month < 1) {
					year--;
					month = NUM_MONTHS;
				}
				day = days_of_month(month, year);
			}
			
			days++;
		}
		
	}

	unsigned int Gregorian::days_of_year(int year) const
	{
		/*Number of days for a given year is 365
		except for leap years.*/

		if (is_leap_year(year))
			return time_t(366);

		return time_t(365);
	}

	void Gregorian::set_date(int y, int m, int d)
	{
		time_t t;
		representation_to_time(y, m, d, t);
		timeDiff(t);
	}

	unsigned int Gregorian::days_of_month(int month, int year) const
	{
		//0 and 13 represent december and january of adjacent years

		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 2:
			if (is_leap_year(year))
				return 29;
			return 28;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		default:
			return -1;
		}

		return time_t();
	}

	time_t Gregorian::days_between(int y1, int m1, int d1,
									int y2, int m2, int d2) const
	{
		//Days between two date1 and date2 (date2 - date1)
		//Returns the number of days from date1 to date2

		time_t days = 0;

		//If date2 is later than date1 count the days
		if (y2 > y1 || 
			(y2 == y1 && m2 > m1) ||
			(y2==y1 && m2 == m1 && d2 >= d1 )) {

			while (y1 != y2 || m1 != m2 || d1 != d2) {
				d1++;
				if (d1 > days_of_month(m1, y1)) {
					m1++;
					d1 = 1;
				}
				if (m1 > NUM_MONTHS) {
					y1++;
					m1 = 1;
				}
				days++;
			}
		}
		//Else swap
		else {

			days = days_between(y2, m2, d2, y1, m1, d1) * -1;

		}

		return days;
	}

	bool Gregorian::is_leap_year(int year) const
	{
		//Every forth year
		if (year % 4 == 0) {

			//Except every hundredth
			if (year % 100 == 0) {

				//Except except every thousandth
				if (year % 1000 == 0)
					return true;

				return false;
			}

			return true;
		}
		return false;
	}

	int Gregorian::epoch_year() const
	{
		return EPOCH_YEAR;
	}

	int Gregorian::epoch_month() const
	{
		return EPOCH_MONTH;
	}

	int Gregorian::epoch_day() const
	{
		return EPOCH_DAY;
	}




}
