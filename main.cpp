#include<iostream>

using namespace std;

int main(void)
{
	unsigned long long int time = 0;
	unsigned long long int hours = 0, minutes = 0, seconds = 0, tmp = 0;

	while (!cin.eof())
	{
		cin >> time;
		if (time >= 3600)
		{
			hours = time / 3600;
			time = time % 3600;
			minutes = time / 60;
			seconds = time % 60;
		}
		else if(time < 3600 && time >= 60)
		{
			minutes = time / 60;
			seconds = time % 60;
		}
		else
		{
			seconds = time;
		}
		cout << hours << " hours " << minutes << " minutes" << " and " << seconds << " seconds" << "\n";
		tmp = 0;
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	return 0;
}