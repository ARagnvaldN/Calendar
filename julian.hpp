#ifndef JULIAN_HPP
#define JULIAN_HPP

#include "gregorian.hpp"

namespace lab2 {

	

	class Julian : public Gregorian
	{
	public:
		Julian();
		Julian(const Date &);
		Julian(int, int, int);
		explicit Julian(time_t);

		virtual ~Julian();

		using Date::operator++;			//Prefix
		using Date::operator--;			//Prefix
		Julian operator++(int);			//Postfix
		Julian operator--(int);			//Postfix
		virtual Julian & operator+=(int);
		virtual Julian & operator-=(int);

		virtual inline unsigned int days_per_week() const;

	protected:
		virtual inline int epoch_year() const;
		virtual inline int epoch_month() const;
		virtual inline int epoch_day() const;

		virtual bool is_leap_year(int) const;
	
	private:
		//JULIAN CONSTANTS
		static const int EPOCH_YEAR_JULIAN = 1969;
		static const int EPOCH_MONTH_JULIAN = 12;
		static const int EPOCH_DAY_JULIAN = 19;
		static const unsigned int NUM_DAYS_PER_WEEK = 7;
	};


}



#endif
