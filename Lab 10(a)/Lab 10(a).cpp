#include <iostream>
#include <string>
using namespace std;

class Train
{
private:
	string point_of_dist;
	int train_num;
	float start_time;

public:
	Train()
	{
		
		point_of_dist = "";
		train_num = 0;
		start_time = 0.0;
	}
	Train(string point_of_dist, int train_num, float start_time)
	{
		
		this->point_of_dist = point_of_dist;	
		this->train_num = train_num;

		if ((int(start_time) > 24)) { start_time = 0.00; }
		else if (start_time - int(start_time) > 0.59) { start_time = int(start_time) + 1; }	
		else { this->start_time = start_time; }
		
	}

	void show()
	{
		cout << point_of_dist << endl << train_num << endl;
		if (this->start_time - int(this->start_time) > 0.1)
		{
			cout << this->start_time << "0" << endl;
		}
	}
	

	int get_train_num() { return this->train_num; }
	string get_point_of_dist() { return this->point_of_dist; }
	float get_start_time() { return this->start_time; }
	

	void show_by_num(int train_num, Train *arr, int size)
	{
		for (int i = 0; i < size; ++i)
		{
			if (arr[i].get_train_num() == train_num) { arr[i].show(); }
			break;
		}
	}

	


};

void sortby_trainnum(Train* arr, int size)
{
	Train temp;
	for (int i = 0; i < (size - 1); i++)
	{
		for (int j = 0; j < (size - i - 1); j++)
		{
			if (arr[j].get_train_num() > arr[j + 1].get_train_num())
			{
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void sortby_pointofdist(Train* arr, int size)
{
	Train temp;
	for (int i = 0; i < (size - 1); i++)
	{
		for (int j = 0; j < (size - i - 1); j++)
		{
			if (arr[j].get_point_of_dist().length() > arr[j + 1].get_point_of_dist().length())
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			else if (arr[j].get_start_time() == arr[j + 1].get_start_time())
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	Train a("Харьков", 1111, 13.30), b("Львов", 4444, 14.55), c("Киев", 4312, 19.45), d("Луганск", 3211, 20.00), e("Одесса", 6666, 1.30);
	const int size = 5;
	Train trains[size]{ a,b,c,d,e };

	for (int i = 0; i < size; ++i) 
	{ 
		trains[i].show(); 
		cout << endl;
	}
	
	sortby_trainnum(trains, size);

	cout << "\nПосле сортировки по номеру поезда:\n";
	for (int i = 0; i < size; ++i) { trains[i].show(); cout << endl; }


	sortby_pointofdist(trains, size);

	cout << "\nПосле сортировки по месту назначения:\n";
	for (int i = 0; i < size; ++i) { trains[i].show(); cout << endl;
	}

	
    
}


