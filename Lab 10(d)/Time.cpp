#include "Time.h"

Time::Time(int hour = 0, int min = 0, int sec = 0)
{
	if (hour < 0 || hour > 24) this->hour = 0;
	else this->hour = hour;

	if (min < 0 || min > 60) this->minute = 0;
	else this->minute = min;

	if (sec < 0 || sec > 60) this->sec = 0;
	else this->sec = sec;
}

void Time::set_hour(const int &hour) 
{
	if (hour < 0 || hour > 24) this->hour = 0;
	else this->hour = hour;
}
void Time::set_min(const int &min)
{
	if (min < 0 || min > 60) this->minute = 0;
	else this->minute = min;
}
void Time::set_sec(const int &sec)
{
	if (sec < 0 || sec > 24) this->minute = 0;
	else this->minute = sec;
}

int Time::get_hour() const { return this->hour; }
int Time::get_minute() const { return this->minute; }
int Time::get_sec() const { return this->sec; }

void Time::show_time() const
{
	if (minute / 10 < 1 && sec / 10 > 1) cout << hour << ":" << "0" + to_string(minute) << sec;
	else if (minute / 10 < 1 && sec / 10 < 1) cout << hour << ":" << "0" + to_string(minute) << ":" << "0" + to_string(sec);
	else cout << hour << ":" << minute << ":" << sec;
}

Time Time::time_differ(const Time& obj) const
{
	Time temp;
	temp.hour = abs(this->hour - obj.hour);
	temp.minute = abs(this->minute - obj.minute);
	temp.sec = abs(this->sec - obj.sec);
	return temp;
}

int Time::compare_times(const Time& obj) const
{
	//возвращает 0, если принимаемый параметр > объекта, 1, если меньше, 2, если объекты равны
	if (this->hour > obj.hour) return 1;
	else if (this->hour < obj.hour) return 0;
	else if (this->hour == obj.hour && this->minute > obj.minute) return 1;
	else if (this->hour == obj.hour && this->minute < obj.minute) return 0;
	else if (this->hour == obj.hour && this->minute == obj.minute && this->sec > obj.sec) return 1;
	else if (this->hour == obj.hour && this->minute == obj.minute && this->sec == obj.sec) return 2;
	else return 0;

}

int Time::calculate_angle() const
{

	auto ans = int((hour * 30 + minute * 0.5) - (minute * 6));
	return min(360 - ans, ans);
}

























