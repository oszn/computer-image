#include "pch.h"
#include"spline.h"

/*virtual void Spline::Paint(ArgParser *args) ;

// ����ʵ����������ת����FOR CONVERTING BETWEEN SPLINE TYPES
virtual void Spline::OutputBezier(FILE *file);
virtual void Spline::OutputBSpline(FILE *file);

// ���ڵõ����Ƶ��FOR CONTROL POINT PICKING
virtual int Spline::getNumVertices();
virtual Vec3f Spline::getVertex(int i);

// ���ڱ༭������FOR EDITING OPERATIONS
virtual void Spline::moveControlPoint(int selectedPoint, float x, float y);
virtual void Spline::addControlPoint(int selectedPoint, float x, float y);
virtual void Spline::deleteControlPoint(int selectedPoint);
*/
// ���ڲ��������ε�FOR GENERATING TRIANGLES
//virtual TriangleMesh* Spline::OutputTriangles(ArgParser *args);

void Spline::Paint(ArgParser * args)
{
	
}

void Spline::OutputBezier(FILE * file)
{
}

void Spline::OutputBSpline(FILE * file)
{
}

Vec3f Spline::getVertex(int i)
{
	return Vec3f();
}

int Spline::getNumVertices()
{
	return 0;
}

void Spline::moveControlPoint(int selectedPoint, float x, float y)
{

}

void Spline::addControlPoint(int selectedPoint, float x, float y)
{
}

void Spline::deleteControlPoint(int selectedPoint)
{
}

TriangleMesh * Spline::OutputTriangles(ArgParser * args)
{
	TriangleMesh *temp;
	return temp;
}
