#pragma once

#include <stddef.h>

class __declspec(dllexport) CoilCalculator
{
private:
	double Length; // m
	double Width;  // m
	double Thickness; // m
	double Density;  // kg/cm3

public:
	CoilCalculator();

	void SetLength(double value); // m
	void SetWidth(double value); // m
	void SetThickness(double value); // m
	void SetDensity(double value); // kg/cm3

	double DensityByWeght(double weight);  // kg/ccm3
	double Length2Weight(double value);
	double Weight2Length(double value);
	double Length2Diameter(double value, double inner);
	double Diameter2Length(double value, double inner);
	double Devide(double value, double max_val, double min_val, int* count = NULL);
	double DevideByLength(double length, double max_len, double min_len, int* count = NULL);
	double DevideByWeight(double length, double max_wt, double min_wt, int* count = NULL);
};