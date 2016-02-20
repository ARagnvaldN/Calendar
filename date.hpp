#ifndef DATE_HPP
#define DATE_HPP

	#include "kattistime.h"

#include <cstdlib>		//abs
#include <stdexcept>		//invalid_argument
#include <string>		//string

namespace lab2 {

	class Date
	{

	friend std::ostream & operator<<(std::ostream &, const Date &);

	private:
		time_t _timeDiff;

		int days_between(const Date &, const Date &) const;

	protected: 
		//INTERVAL
		static const int ALPHA = 1500;
		static const int BETA = 2700;

		//EPOCH CONSTANTS (in gregorian)
		static const int EPOCH_YEAR = 1970;
		static const int EPOCH_MONTH = 1;
		static const int EPOCH_DAY = 1;
		static const int EPOCH_WEEK_DAY = 4;

		static const int NUM_MONTHS = 12;

		//DIFFERENCE BETWEEN EPOCH AND MJD=0 IN DAYS
		static const int MJD_EPOCH_DIFF = -40587;

		//TIME CONSTANTS
		static const int MINUTE = 60;
		static const int HOUR = 60 * MINUTE;
		static const int DAY = 24 * HOUR;
		
		time_t today() const;
		void copy(const Date &);

		virtual bool is_valid_date(int, int, int) const = 0;

		virtual void representation_to_time(int, int, int, time_t&) const = 0;
		virtual void time_to_representation(int&, int&, int&) const = 0;

		virtual std::string to_date_string() const = 0;
		virtual unsigned int days_of_month(int, int) const = 0;
		virtual unsigned int days_of_year(int) const = 0;
		
		virtual void set_date(int, int, int) = 0;

		//This MUST be protected in release
		time_t timeDiff() const;
		time_t daysDiff() const;
		void timeDiff(time_t);

	public:
		virtual ~Date() = 0;

		//Required functions
		int year() const;
		unsigned int month() const;
		unsigned int day() const;	
		virtual unsigned int days_per_week() const = 0;
		
		virtual std::string week_day_name() const = 0;
		virtual std::string month_name() const = 0;


		virtual int mod_julian_day() const;

		//Other public		
		unsigned int week_day() const;
		unsigned int days_this_month() const;

		//Non-const members
		void add_day(time_t);
		void add_year(int);
		void add_month(int);

		//Operators
		Date & operator++(); //Prefix
		Date & operator--(); //Prefix
		virtual Date & operator+=(int) = 0;
		virtual Date & operator-=(int) = 0;

		void operator=(const Date &);

		int operator-(const Date &) const;
		bool operator==(const Date &) const;
		bool operator!=(const Date &) const;
		bool operator<(const Date &) const;
		bool operator<=(const Date &) const;
		bool operator>(const Date &) const;
		bool operator>=(const Date &) const;	

	};

}



#endif
