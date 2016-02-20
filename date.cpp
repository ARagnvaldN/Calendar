#include "date.hpp"

namespace lab2 {
	int Date::days_between(const Date & d1, const Date & d2) const
	{
		return d2.daysDiff() - d1.daysDiff();
	}

	Date::~Date() {}

	int Date::year() const
	{
		int y, m, d;
		time_to_representation(y, m, d);
		return y;
	}
	unsigned int Date::month() const
	{
		int y, m, d;
		time_to_representation(y, m, d);
		return m;
	}
	unsigned int Date::day() const
	{
		int y, m, d;
		time_to_representation(y, m, d);
		return d;
	}
	time_t Date::today() const
	{

		time_t now;
		k_time(&now);

		return now;
	}

	void Date::copy(const Date & source)
	{
		timeDiff(source.timeDiff());
	}

	time_t Date::timeDiff() const
	{
		return _timeDiff;
	}

	time_t Date::daysDiff() const
	{
		return timeDiff() / DAY;
	}

	void Date::timeDiff(time_t t)
	{
		_timeDiff = t;
	}
	void Date::add_day(time_t n)
	{
		//Adds n days to the date
		timeDiff(timeDiff() + n * DAY);
	}

	int Date::mod_julian_day() const
	{
		return daysDiff() - MJD_EPOCH_DIFF;
	}

	unsigned int Date::week_day() const
	{

		time_t days = daysDiff();
		int weekday = (daysDiff() % days_per_week());
		if (days >= 0) {
			weekday += EPOCH_WEEK_DAY;
			if (weekday > days_per_week())
				weekday -= days_per_week();
		}			
		else
		{ 
			if (weekday <= -4) {
				//y = x + 11
				weekday = weekday + (EPOCH_WEEK_DAY+days_per_week());
			}		
			else
				weekday = EPOCH_WEEK_DAY + weekday;
		}

		return std::abs(weekday);
	}

	unsigned int Date::days_this_month() const
	{
		return days_of_month(month(), year());
	}

	void Date::add_year(int n)
	{

		int y = year() + n,
			m = month(),
			d = day();

		if (is_valid_date(y, m, d))
			set_date(y, m, d);

		else
			set_date(y, m, days_of_month(m, y));

	}

	void Date::add_month(int n)
	{

		int n_months = n % NUM_MONTHS,
			n_years = n / NUM_MONTHS;

		int y = year() + n_years,
			m = month() + n_months,
			d = day();

		if (m > NUM_MONTHS) {
			m = 1;
			y++;
		}			

		if (is_valid_date(y, m, d))
			set_date(y, m, d);

		else
			set_date(y, m, days_of_month(m, y));
	}

	Date & Date::operator++()	
	{
		add_day(1);
		return *this;
	}

	Date & Date::operator--()
	{
		add_day(-1);
		return *this;
	}

	void Date::operator=(const Date & source)
	{
		copy(source);
	}

	int Date::operator-(const Date & other) const
	{
		return days_between(*this, other);
	}

	bool Date::operator==(const Date & other) const
	{
		//Two dates are equal if they are the same y, m, d.
		return daysDiff() == other.daysDiff();
	}

	bool Date::operator!=(const Date & other) const
	{
		return daysDiff() != other.daysDiff();
	}

	bool Date::operator<(const Date & other) const
	{
		return daysDiff() < other.daysDiff();
	}

	bool Date::operator<=(const Date & other) const
	{
		return daysDiff() <= other.daysDiff();
	}

	bool Date::operator>(const Date & other) const
	{
		return daysDiff() > other.daysDiff();
	}

	bool Date::operator>=(const Date & other) const
	{
		return daysDiff() >= other.daysDiff();
	}

	std::ostream & operator<<(std::ostream & ostream,
								const Date & d)
	{
		ostream << d.to_date_string();
		return ostream;
	}

}