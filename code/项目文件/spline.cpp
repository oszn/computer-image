#include "pch.h"
#include"spline.h"

/*virtual void Spline::Paint(ArgParser *args) ;

// 用于实现样条类型转换的FOR CONVERTING BETWEEN SPLINE TYPES
virtual void Spline::OutputBezier(FILE *file);
virtual void Spline::OutputBSpline(FILE *file);

// 用于得到控制点的FOR CONTROL POINT PICKING
virtual int Spline::getNumVertices();
virtual Vec3f Spline::getVertex(int i);

// 用于编辑操作的FOR EDITING OPERATIONS
virtual void Spline::moveControlPoint(int selectedPoint, float x, float y);
virtual void Spline::addControlPoint(int selectedPoint, float x, float y);
virtual void Spline::deleteControlPoint(int selectedPoint);
*/
// 用于产生三角形的FOR GENERATING TRIANGLES
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
