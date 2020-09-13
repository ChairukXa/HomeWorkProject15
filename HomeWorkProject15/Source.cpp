#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int monthDay[12] = {
		31, // JAN
		29, // Feb
		31, // Mar
		30, // Apr
		31, // May
		30, // Jun
		31, // Jul
		31, // Aug
		30, // Sep
		31, // Oct
		30, // Nov
		31, // Dec
	};
	int suncount = 0;
	int month;
	int year;
	int dayofweek = 1;
	for (month = 1; month <= 12; month++)
	{
		dayofweek += (monthDay[month - 1] % 7);
		if (dayofweek > 7)
		{
			dayofweek = (0 + dayofweek % 7);
		}
	}
	for (year = 1901; year <= 2000; year++)
	{
		if (((year % 100 == 0) && (year % 400 == 0)) || (year % 100 == 0))
		{
			monthDay[1] = 29;
		}
		else
		{
			monthDay[1] = 28;
		}
		for (month = 1; month <= 12; month++)
		{
			dayofweek += (monthDay[month - 1] % 7);
			if (dayofweek > 7)
			{
				dayofweek = (0 + dayofweek % 7);
			}
			else if (dayofweek == 7)
			{
				suncount++;
			}
		}
	}
	printf("SunCount = %d", suncount);
}