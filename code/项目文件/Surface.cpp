#include "pch.h"
#include "Surface.h"


Surface::Surface()
{
}


void Surface::set(int i,Vec3f v) {

}

void Surface::Paint(ArgParser * args)
{

}

void Surface::OutputBezier(FILE * file)
{
}

void Surface::OutputBSpline(FILE * file)
{
}

void Surface::moveControlPoint(int selectedPoint, float x, float y)
{
	cout << "?";
}

void Surface::addControlPoint(int selectedPoint, float x, float y)
{
}

void Surface::deleteControlPoint(int selectedPoint)
{
}

Vec3f Surface::getVertex(int i)
{
	return Vec3f();
}

int Surface::getNumVertices()
{
	return 0;
}

TriangleMesh * Surface::OutputTriangles(ArgParser * args)
{
	return nullptr;
}

Surface::~Surface()
{
}
