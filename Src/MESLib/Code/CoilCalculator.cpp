#include "CoilCalculator.h"

#define _USE_MATH_DEFINES
#include <math.h>

CoilCalculator::CoilCalculator()
{
	this->Length = 0.0;
	this->Width - 0.0;
	this->Thickness = 0.0;
	this->Density = 7800;
}

void CoilCalculator::SetLength(double value)
{
	this->Length = value;
}

void CoilCalculator::SetWidth(double value)
{
	this->Width = value / 1000.0;
}

void CoilCalculator::SetThickness(double value)
{
	this->Thickness = value / 1000.0;
}

void CoilCalculator::SetDensity(double value)
{
	this->Density = value * 1000.0;
}

double CoilCalculator::DensityByWeght(double weight)
{
	double v = this->Width * this->Length * this->Thickness;
	if(v > 0)
	{
		this->Density = weight / v;
	}
	else
	{
		this->Density = 0;
	}

	//if(Result > 7 && Result < 9)
	//{
	//	this->Density = Result;
	//}
	//else
	//{
	//	this->Density = 7.78;
	//}

	return this->Density / 1000.0;
}

double CoilCalculator::Length2Weight(double value)
{
	return value * this->Width * this->Thickness * this->Density;
}

double CoilCalculator::Weight2Length(double value)
{
	return value / (this->Width * this->Thickness * this->Density);
}

double CoilCalculator::Length2Diameter(double value, double inner)
{
	return sqrt((this->Thickness * this->Length) / M_PI_4 + inner * inner);
}

double CoilCalculator::Diameter2Length(double value, double inner)
{
	return (value * value - inner * inner) * M_PI_4 / this->Thickness;
}

double CoilCalculator::Devide(double value, double max_val, double min_val, int* count)
{
	double Result = 0;
	int c;

	int count_max = (int)(value / min_val);
	int count_min = (int)(value / max_val);

	if(count_max == 0)
	{
		Result = value;
		c = 1;
	}
	else if(count_min == count_max)
	{
		Result = max_val;
		c = count_min;
	}
	else
	{
		c = count_min + 1;
		Result = value / c;
	}

	/*
	else if(count_min + 1 == count_max)
	{
		if((value - count_max * min_val) < (value - count_min * max_val))
		{
			Result = min_val;
			c = count_max;
		}
		else
		{
			Result = max_val;
			c = count_min;
		}
	}
	else if(count_min + 2 <= count_max)
	{
		c = (count_min + count_max + 1) / 2;
		Result = value / c;
	}
	*/

	if(count)
	{
		*count = c;
	}

	return Result;
}

double CoilCalculator::DevideByLength(double length, double max_len, double min_len, int* count)
{
	return this->Devide(length, max_len, min_len, count);
}

double CoilCalculator::DevideByWeight(double weight, double max_wt, double min_wt, int* count)
{
	return this->Devide(weight, max_wt, min_wt, count);
}