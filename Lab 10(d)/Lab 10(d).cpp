#include "Time.h"



int main()
{
	setlocale(LC_ALL, "ru");
	Time mytime(13, 55, 43);
	cout << "Время 1: ";
	mytime.show_time();

	Time time2(14, 214, 123);
	cout << "\nВремя 2: ";
	time2.show_time();

	cout << endl;
	if (mytime.compare_times(time2) == 0) cout << "Время 1 < Времени 2";
	else if (mytime.compare_times(time2) == 1) cout << "Время 1 > Времени 2";
	else cout << "Времена равны";

	cout << "\nУгол между часовой и минутной стрелками Mytime (в градусах): " << mytime.calculate_angle();
}


