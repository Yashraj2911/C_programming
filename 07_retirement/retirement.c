#include<stdio.h>
struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double calculate(retire_info r,int startAge,double initial)
{
  int age_years=startAge/12;
  int age_months=startAge%12;
  double current=initial;
  double rate=r.rate_of_return/100/12;
  int i=0;
  while(i<r.months)
    {
      printf("Age %3d month %2d you have $%.2lf\n",age_years,age_months,current);
      current+=current*rate+r.contribution;
      if(++age_months>11)
	{
	  age_months=0;
	  age_years++;
	}
      i++;
    }
  return current;
}
void retirement(int startAge,double initial,retire_info working,retire_info retired)
{
  calculate(retired,startAge+working.months,calculate(working,startAge,initial));
}
int main()
{
  retire_info Working;
  Working.months=489;
  Working.contribution=1000;
  Working.rate_of_return=4.5;

  retire_info Retired;
  Retired.months=384;
  Retired.contribution=-4000;
  Retired.rate_of_return=1;

  retirement(327,21345,Working,Retired);
}
