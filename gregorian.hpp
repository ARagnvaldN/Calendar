#ifndef GREGORIAN_HPP
#define GREGORIAN_HPP

#include "date.hpp"
#include <vector>

namespace lab2 {

	class Gregorian : public Date
	{
	public:
		Gregorian();
		Gregorian(const Date &);
		Gregorian(int, int, int);
		explicit Gregorian(time_t);

		virtual ~Gregorian();
		
		inline virtual unsigned int days_per_week() const;

		virtual std::string week_day_name() const;
		virtual std::string month_name() const;

		using Date::operator++;			//Prefix
		using Date::operator--;			//Prefix
		Gregorian operator++(int);		//Postfix
		Gregorian operator--(int);		//Postfix
		virtual Gregorian & operator+=(int);
		virtual Gregorian & operator-=(int);
		
	protected:
		virtual std::string to_date_string() const;
		virtual bool is_valid_date(int, int, int) const;
		virtual unsigned int days_of_month(int, int) const;
		virtual unsigned int days_of_year(int) const;
		virtual void set_date(int, int, int);

		virtual void representation_to_time(int, int, int,time_t&) const;
		virtual void time_to_representation(int&,int&,int&) const;
		time_t days_between(int, int, int, int, int, int) const;
	
		virtual bool is_leap_year(int) const;
		
		virtual inline int epoch_year() const;
		virtual inline int epoch_month() const;
		virtual inline int epoch_day() const;

	private:
		//Constants
		static const int NUM_DAYS_WEEK = 7;
		static const std::vector<std::string> WEEK_DAY_NAMES;
		static const std::vector<std::string> MONTH_NAMES;
	};



}

#endif