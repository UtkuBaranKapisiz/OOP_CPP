#include "CSS.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
///
CSS::CSS(double a, double b, double c, double d, double e, double f, int x)
{
	setCs1_item1(a);
	setCs1_item2(b);
	setCs1_item3(c);
	setCs2_item1(d);
	setCs2_item2(e);
	setCs2_item3(f);
	setChoice(x);	
}
///
void CSS::setCs1_item1(double a){
	cs1_item1=a;
}
///
void CSS::setCs1_item2(double a){
	cs1_item2=a;
}
///
void CSS::setCs1_item3(double a){
	cs1_item3=a;
}
///
void CSS::setCs2_item1(double a){
	cs2_item1=a;
}
///
void CSS::setCs2_item2(double a){
	cs2_item2=a;
}
///
void CSS::setCs2_item3(double a){
	cs2_item3=a;
}
///
void CSS::setChoice(int a)
{
	choice = a;
}
///

double CSS::getCs1_item1(void){
	return cs1_item1;
}
///
double CSS::getCs1_item2(void){
	return cs1_item2;
}
///
double CSS::getCs1_item3(void){
	return cs1_item3;
}
///
double CSS::getCs2_item1(void){
	return cs2_item1;
}
///
double CSS::getCs2_item2(void){
	return cs2_item2;
}
///
double CSS::getCs2_item3(void)
{
	return cs2_item3;
}
///
int CSS::getChoice(void)
{
	return choice;
}
///
void CSS::printMenu(){
	bool isSelected = false;
	while(isSelected == false)
	{
	
		cout<<"************************************\n1.Cartesian to Spherical\n"
		<<"2.Cartesian to Cylindrical\n3.Sphrerical to Cartesian\n"
		<<"4.Cylindrical to Cartesian\n5.Exit\n************************************\n";
		int x=0;
		cin>>x;
		if (1<=x && x<=5)
		{
			setChoice(x);	
			isSelected = true;
		}
		else
		{
			cout<<"Wrong selection, enter proper values\n";
		}
		
	}
}
///
void CSS::setCoordinates(void)
{
	int a,b,c;
	if (getChoice() == 1 || getChoice() == 2)
	{
		cout << "Enter x, y and z values\n";
	}
	if (getChoice() == 3)
	{
		cout << "Enter radius, theta and phi values\n";	
	}
	if (getChoice() == 4)
	{
		cout << "Enter rho, phi and z values\n";
	}
	if (getChoice() == 5)
	{
		cout << "Program will close\n";
		exit(1);
	}
	cin >> a >> b >> c;
	setCs1_item1(a);
	setCs1_item2(b);
	setCs1_item3(c);
}
///
void CSS::printCoordinates(void)
{
	switch(getChoice())
	{
		case 1:
			carToSph();
			cout << getConversionType() <<" ===>\tx:" << getCs2_item1() << "\ty:" << getCs2_item2() << "\tz:" << getCs2_item3();
			break;
		case 2:
			carToCyl();
			cout << getConversionType() <<" ===>\tx:" << getCs2_item1() << "\ty:" << getCs2_item2() << "\tz:" << getCs2_item3();
			break;
		case 3:
			sphToCar();
			cout << getConversionType() <<" ===>\tRadius:" << getCs2_item1() << "\tTheta:" << getCs2_item2() << "\tPhi:" << getCs2_item3();
			break;
		case 4:
			cylToCar();
			cout << getConversionType() <<" ===>\tRho:" << getCs2_item1() << "\tPhi:" << getCs2_item2() << "\tZ:" << getCs2_item3();
			break;
		default:
			cout << "Error from switch-case";
	}
}
///
double CSS::getRadianFromDegree(double a)
{
	return (a*M_PI/180);
}
///
double CSS::getDegreeFromRadian(double a)
{
	return (a*180/M_PI);
}
///
void CSS::carToSph(void)
{
	setCs2_item1(sqrt(pow(getCs1_item1(),2)+pow(getCs1_item2(),2)+pow(getCs1_item3(),2))); // sqrt(x^2+y^2+z^2)
	setCs2_item2(getDegreeFromRadian(atan(getCs1_item2()/getCs1_item1()))); // atan y/x
	setCs2_item3(getDegreeFromRadian(atan(sqrt(pow(getCs1_item1(),2)+pow(getCs1_item2(),2))/getCs1_item3())));
}
///
void CSS::carToCyl(void)
{
	setCs2_item1(sqrt(pow(getCs1_item1(),2) + pow(getCs1_item2(),2))); //sqrt(x^2+y^2)
	setCs2_item2(getDegreeFromRadian(atan(getCs1_item2()/getCs1_item1()))); // atan y/x
	setCs2_item3(getCs1_item3()); // z
}
///
void CSS::sphToCar(void)
{
	setCs2_item1(getCs1_item1() * cos(getRadianFromDegree(getCs1_item2())) * sin(getRadianFromDegree(getCs1_item3()))); // x*cos(y)*sin(z)
	setCs2_item2(getCs1_item1() * sin(sin(getRadianFromDegree(getCs1_item2())) * sin(getRadianFromDegree(getCs1_item3())))); // x*sin(y)*sin(z)
	setCs2_item3(getCs1_item1() * cos(getRadianFromDegree(getCs1_item3()))); // x*cos(z)
}
///
void CSS::cylToCar(void)
{
	setCs2_item1(getCs1_item1()*cos(getRadianFromDegree(getCs1_item2()))); // x*cos(y)
	setCs2_item2(getCs1_item1()*sin(getRadianFromDegree(getCs1_item2()))); // x*sin(y)
	setCs2_item3(getCs1_item3()); // z
	
}
///
string CSS::getConversionType(void)
{
	switch (getChoice()){
		case 1:
			return "Cartesian to Spherical";
		case 2:
			return "Cartesian to Cylindrical";
		case 3:
			return "Spherical to Cartesian";
		case 4:
			return "Cylindrical to Cartesian";
	}
}
