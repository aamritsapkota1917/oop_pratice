//WAP to define a class Time that has 3 data members for hours,
// minutes and second. Include member functions :       
//1. void getTime() - To input time
//2. void sum(time, time) - To add 2 different time
//3. void display() - To display the resultant time

#include<iostream>
using namespace std;
class Time
{
    public:
        double hours,minutes,seconds;
    void getTime()
    {
        cout<<"Enter time:"
            <<"\n Hours:"<<endl;
        cin>>hours;
        cout<<"Minutes:"<<endl;
        cin>>minutes;
        cout<<"Seconds:"<<endl;
        cin>>seconds;
    } 
    Time sum(Time t1,Time t2)
    {
        Time sum;
        double total1,total2;
        total1=t1.seconds+(t1.minutes)*60+(t1.hours)*3600;
        total2=t2.seconds+(t2.minutes)*60+(t2.hours)*3600;
        cout<<"total1:"<<total1;
        cout<<"total2:"<<total2;
        int sum_in_seconds=total1+total2;
        cout<<"total seconds:"<<sum_in_seconds;
        int hrs=0;
        int min=0;
        if (sum_in_seconds>=3600)
        {
            hrs=sum_in_seconds/3600;
            sum_in_seconds=sum_in_seconds%3600;
        }
        if (sum_in_seconds>=60)
        {
            min=sum_in_seconds/60;
            sum_in_seconds=sum_in_seconds%60;
        }
            
        
        sum.hours=hrs;
        sum.minutes=min;
        sum.seconds=sum_in_seconds;
        return sum;
    }
    void display()
    {
        cout<<"Total time:"
            <<"\n "<<hours<<" hrs "<<minutes<<" min "<<seconds<<" sec "<<endl;
    }
};

int main()
{
    Time t1,t2,sum;
    t1.getTime();
    t2.getTime();
    sum=sum.sum(t1,t2);
    sum.display();
    return 0;
}