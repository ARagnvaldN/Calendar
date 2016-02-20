#include "julian.hpp"

namespace lab2 {

	Julian::Julian():Gregorian()
	{
	}

	Julian::Julian(time_t new_t):Gregorian(new_t)
	{
	}

	Julian::Julian(const Date & source)
	{
		copy(source);
	}
	
	Julian::Julian(int year, int month, int day)
	{
		if (!is_valid_date(year, month, day))
			throw std::invalid_argument("Dates should be on format YYYY, MM, DD!");

		set_date(year, month, day);
	}

	Julian::~Julian()
	{
	}

	Julian Julian::operator++(int unused)
	{
		Julian j = *this;
		this->add_day(1);

		return j;
	}

	Julian Julian::operator--(int unused)
	{
		Julian j = *this;
		this->add_day(-1);

		return j;
	}

	Julian & Julian::operator+=(int n)
	{
		add_day(n);
		return *this;
	}

	Julian & Julian::operator-=(int n)
	{
		add_day(-n);
		return *this;
	}

	inline unsigned int Julian::days_per_week() const
	{
		return NUM_DAYS_PER_WEEK;
	}

	inline int Julian::epoch_year() const
	{
		return EPOCH_YEAR_JULIAN;
	}

	inline int Julian::epoch_month() const
	{
		return EPOCH_MONTH_JULIAN;
	}

	inline int Julian::epoch_day() const
	{
		return EPOCH_DAY_JULIAN;
	}

	bool Julian::is_leap_year(int year) const
	{
		if (year % 4 == 0)
			return true;
		
		return false;
	}



}
