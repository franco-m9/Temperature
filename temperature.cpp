#include <iostream>
#include <iomanip>
#include <string>
#include "temperature.h"

using namespace std;

Temperature::Temperature()
{
degree=0;														// sets to default format,scale, and degree
formsoftemp='C';
format='D';
}
Temperature::Temperature(double degr, char temptype)
{
	if(temptype!='F'&&temptype!='f'&&temptype!='C'&&temptype!='c'&&temptype!='K'&&temptype!='k')			// sets to default if not correct parameters
	{
	degree=0;
	formsoftemp='C';
	format='D';
	}

	else if(temptype=='C' || temptype=='c')										// sets to either default or correct parameters
	{
		if(degr<-273.15)
		{
		degree=0;
		formsoftemp='C';
		format='D';
		}
		else
		{
		degree=degr;
		formsoftemp='C';
		format='D';
		}
	}

	else if(temptype=='F' || temptype=='f')										// sets to either default or correct parameters based off scale/degree
	{
		if(degr<-459.56)
		{
		degree=0;
		formsoftemp='C';
		format='D';
		}
		else
		{
		degree=degr;
		formsoftemp='F';
		format='D';
		}
	}

	else if(temptype=='K' || temptype=='k')										// sets to either default or correct parameters based off scale/degree
	{
		if(degr<0)
		{
		degree=0;
		formsoftemp='C';
		format='D';
		}
		else
		{
		degree=degr;
		formsoftemp='K';
		format='D';
		}
	}
}
void Temperature::Input()
{
int errorcheck;																// counter for loop
double tempdeg;																// temporary degrees and scale
char tempform;
	do																// do while loop to run while incorrect input
	{
	cout << "Enter a temperature: ";
	cin >> tempdeg >> tempform;

		if(tempform!='F' && tempform!='f' && tempform!='C' && tempform!='c' && tempform!='K' && tempform!='k')
		{
		cout << "Invalid form of temperature, try again: " << endl;
		errorcheck=0;
		}

		else
		{
			if(tempform=='F' || tempform=='f')
			{
				if(tempdeg<-459.67)
				{
				cout << "Invalid temperature degree, try again: " << endl;
				errorcheck=0;
				}
				else
				{
				formsoftemp=tempform;
				degree=tempdeg;
				errorcheck=1;
				}
			}
				else if(tempform=='C' || tempform=='c')
				{
					if(tempdeg<-273.15)
					{
					cout << "Invalid temperature degree, try again: " << endl;
					errorcheck=0;
					}
					else
					{
					formsoftemp=tempform;
					degree=tempdeg;
					errorcheck=1;
					}
				}
				else if(tempform=='K' || tempform=='k')
				{
					if(tempdeg<0)
					{
					cout << "Invalid temperature degree, try again: " << endl;
					errorcheck=0;
					}
					else
					{
					formsoftemp=tempform;
					degree=tempdeg;
					errorcheck=1;
					}
				}
		}
	}
	while(errorcheck==0);
}
void Temperature::Show() const
{
char CelA[]="Celsius";														// arrays to store scale words
char FahA[]="Fahrenheit";
char KelA[]="Kelvin";
int oldprecision=cout.precision();												// to reset precision for future runs

	if(format=='D')
	cout << degree << " " << formsoftemp << endl;

	else if(format=='P')
	{
	cout << fixed << setprecision(1) << degree << " " << formsoftemp << endl;						// 1 decimal place
	}
	else if(format=='L')
	{
		if(formsoftemp=='C'||formsoftemp=='c')
		cout << degree << " " <<  CelA << endl;
		else if(formsoftemp=='F'||formsoftemp=='f')
		cout << degree << " " << FahA << endl;
		else if(formsoftemp=='K' || formsoftemp=='k')
		cout << degree << " " <<  KelA << endl;
	}
	cout.precision(oldprecision);												// resets set precision and fixed
	cout << resetiosflags(ios::fixed);
}
bool Temperature::Set(double deg, char s)											// same as void input but bool with error checking
{
	if(s!='F'&&s!='f'&&s!='C'&&s!='c'&&s!='K'&&s!='k')
	return false;

	else if(s=='C' || s=='c')
	{
		if(deg<-273.15)
		return false;
		else
		{
		degree=deg;
		formsoftemp='C';
		return true;
		}
	}

	else if(s=='F' || s=='f')
	{
		if(deg<-459.67)
		return false;
		else
		{
		degree=deg;
		formsoftemp='F';
		return true;
		}
	}

	else if(s=='K' || s=='k')
	{
		if(deg<0)
		return false;
		else
		{
		degree=deg;
		formsoftemp='K';
		return true;
		}
	}
}
double Temperature::GetDegrees() const													// returns degrees
{
return degree;
}
char Temperature::GetScale() const													// returns scale
{
return formsoftemp;
}
bool Temperature::SetFormat(char f)													// sets format of void Show()
{
	if(f=='D' || f=='P' || f=='L')
	{
	format=f;
	return true;
	}
	else
	return false;
}
bool Temperature::Convert(char sc)													// converts temperatures C,F,K with various formulas
{
	if(sc!='F'&&sc!='f'&&sc!='C'&&sc!='c'&&sc!='K'&&sc!='k')
	return false;

	else if(sc=='C' || sc=='c')
	{
		if(formsoftemp=='F' || formsoftemp=='f')
		{
		degree=(degree-32)*(5/9.0);
		formsoftemp='C';
		return true;
		}

		else if(formsoftemp=='K'||formsoftemp=='k')
		{
		degree=degree-273.15;
		formsoftemp='C';
		return true;
		}
	}

	else if(sc=='F' || sc=='f')
	{
		if(formsoftemp=='C' || formsoftemp=='c')
		{
		degree=degree*1.8+32;
		formsoftemp='F';
		return true;
		}
		else if(formsoftemp=='K' || formsoftemp=='k')
		{
		degree=1.8*(degree-273.15)+32;
		formsoftemp='F';
		return true;
		}
	}

	else if(sc=='K' || sc=='k')
	{
		if(formsoftemp=='C' || formsoftemp=='c')
		{
		degree=degree+273.15;
		formsoftemp='K';
		return true;
		}
		else if(formsoftemp=='F' || formsoftemp=='f')
		{
		degree=(degree-32)/1.8+273.15;
		formsoftemp='K';
		return true;
		}
	}
}
int Temperature::Compare(const Temperature& d) const										// compares which temperature object is a lower temperature,same,greater
{
if(CompareUtility()<d.CompareUtility())
return -1;
else if(CompareUtility()==d.CompareUtility())
return 0;
else if(d.CompareUtility()<CompareUtility())
return 1;
}
void Temperature::Increment(int deg, char sc)											// converts temperature to current stored degree and then adds
{
	if(formsoftemp=='F'||formsoftemp=='f')
	{
		if(sc=='C'||sc=='c')
		degree=degree+(deg*1.8+32);
		else if(sc=='K'||sc=='k')
		degree=degree+(1.8*(deg-273.15)+32);
		else if(sc=='F'||sc=='f')
		degree=degree+deg;
	}
	else if(formsoftemp=='C'||formsoftemp=='c')
	{
		if(sc=='F'||sc=='f')
		degree=degree+((deg-32)*(5/9.0));
		else if(sc=='K'||sc=='k')
		degree=degree+(deg-273.15);
		else if(sc=='C'||sc=='c')
		degree=degree+deg;
	}
	else if(formsoftemp=='K'||formsoftemp=='k')
	{
		if(sc=='C'||sc=='c')
		degree=degree+(deg+273.15);
		else if(sc=='F'||sc=='f')
		degree=degree+((deg-32)/1.8+273.15);
		else if(sc=='K'||sc=='k')
		degree=degree+deg;
	}
}
double Temperature::CompareUtility() const											// personal function which turns every degree to kevlin for compare function
{
double utility=degree;
	if(formsoftemp=='C' || formsoftemp=='c')
	utility=degree+273.15;
	else if(formsoftemp=='F' || formsoftemp=='f')
	utility=(degree-32)*1.8+273.15;
return utility;
}
