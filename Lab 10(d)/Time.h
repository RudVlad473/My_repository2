#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Time
{
	int hour;
	int minute;
	int sec;

public:
	Time(int = 0, int = 0, int = 0);

	void set_hour(const int&);
	void set_min(const int&);
	void set_sec(const int&);

	int get_hour() const;
	int get_minute() const;
	int get_sec() const;

	void show_time() const;

	Time time_differ(const Time&) const;

	int compare_times(const Time&) const;

	int calculate_angle() const;

};




























