
#include <iostream>
#include <string>
#include <cmath>
#include "TransRot.h"

using namespace std;
///
TransRot::TransRot()
{
	setXYZ(0.0,0.0,0.0);
	newX = 0.0;
	newY = 0.0;
	newZ = 0.0;
}
///
void TransRot::setXYZ(double X, double Y, double Z)
{
	setX(X);
	setY(Y);
	setZ(Z);
}
///
void TransRot::setX(double X)
{
	x = X;
}
///
void TransRot::setY(double Y)
{
	y = Y;
}
///

void TransRot::setZ(double Z)
{
	z = Z;
}
///

double TransRot::getX(void)
{
	return x;
}
///

double TransRot::getY(void)
{
	return y;
}
///

double TransRot::getZ(void)
{
	return z;
}
///
void TransRot::translateAlongX(double value)
{
	newX = x + value;
	newY = y;
	newZ = z;
	opType.assign("Translate X");
}
///
void TransRot::translateAlongY(double value)
{
	newX = x;
	newY = y + value;
	newZ = z;
	opType.assign("Translate Y");
}
///
void TransRot::translateAlongZ(double value)
{
	newX = x;
	newY = y;
	newZ = z + value;
	opType.assign("Translate Z");
}
///
void TransRot::rotateAroundX(double value)
{
	newX = x;
	newY = y*cos(getRadianFromDegree(value) - z*sin(getRadianFromDegree(value)));
	newZ = y*sin(getRadianFromDegree(value)) + z*cos(getRadianFromDegree(value));
	opType = "Rotate X";
}
///
void TransRot::rotateAroundY(double value)
{
	newX = x*cos(getRadianFromDegree(value)) + z*sin(getRadianFromDegree(value));
	newY = y;
	newZ = x*sin(getRadianFromDegree(value)) + z*cos(getRadianFromDegree(value));
	opType = "Rotate Y";
}
///
void TransRot::rotateAroundZ(double value)
{
	newX = x*cos(getRadianFromDegree(value)) - y*sin(getRadianFromDegree(value));;
	newY = x*sin(getRadianFromDegree(value) + y*cos(getRadianFromDegree(value)));
	newZ = z;
	opType = "Rotate Z";
	
}
///
std::string TransRot::getOperationType(void)
{
	return opType;
}
///
void TransRot::printResult(void)
{
	cout << getX() <<","<< getY()<<","<< getZ()<<"=>" << getOperationType()
	<<"=>"<<newX<<","<<newY<<","<<newZ<<"\n";
}
///
void TransRot::updateCoordinates(void)
{
	x = newX;
	y = newY;
	z = newZ;
}
///
double TransRot::getRadianFromDegree(double degree)
{
	return (degree*M_PI)/180;
}

