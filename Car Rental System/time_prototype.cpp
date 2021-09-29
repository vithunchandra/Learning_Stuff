#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

int future_hour=0;
int future_day=0;

void future_date()
{
    int year,month,day,hour,minute,second;
    struct tm* time_data;
    time_t raw_time;

    time(&raw_time);
    time_data=localtime(&raw_time);

    year=time_data->tm_year;
    month=time_data->tm_mon;
    day=time_data->tm_mday;
    hour=time_data->tm_hour;
    minute=time_data->tm_min;
    second=time_data->tm_sec;

    hour+=future_hour;
    day+=future_day;

    if(hour>24)
    {
        hour=hour-24;
        day+=1;
    }
    if(month%2!=0)
    {
        if(day>31)
        {
            day=day-31;
            month+=1;
        }
    }
    if(month%2==0)
    {
        if(day>30)
        {
            day=day-30;
            month+=1;
        }
    }
    if(month>12)
    {
        month=month-12;
        year+=1;
    }

    std::cout<<second<<":"<<minute<<":"<<hour<<", "<<day<<"-"<<month<<"-"<<year<<std::endl;

}

int main ()
{
    std::cin>>future_hour;
    std::cin>>future_day;

    future_date();
}