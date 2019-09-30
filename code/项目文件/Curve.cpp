#include "pch.h"
#include "Curve.h"


Curve::Curve()
{
}

void Curve::set(int i, Vec3f v)
{
	mxp.push_back(v);
}

void Curve::Paint(ArgParser *args)
{


};

void Curve::OutputBezier(FILE *file) {};
void Curve::OutputBSpline(FILE *file) {}
int Curve::getNumVertices()
{
	return 0;
}
void Curve::moveControlPoint(int selectedPoint, float x, float y)
{
	
}
void Curve::addControlPoint(int selectedPoint, float x, float y)
{
}
void Curve::deleteControlPoint(int selectedPoint)
{
}
void Curve::setpara(int i, float x, float y)
{
}
Vec3f Curve::getVertex(int i)
{
	return Vec3f();
}
;

vector<Vec3f> Curve::cmp(int k,int c)
{
	return vector<Vec3f>();
}

Curve::~Curve()
{
}
