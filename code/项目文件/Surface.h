#ifndef _aa_
#define _aa_

#include "spline.h"
class Surface :public Spline
{
public:
	Surface();
	void set(int i, Vec3f v);
virtual	void Paint(ArgParser *args);

virtual    void OutputBezier(FILE *file);
virtual	void OutputBSpline(FILE *file);

virtual void moveControlPoint(int selectedPoint, float x, float y);
virtual void addControlPoint(int selectedPoint, float x, float y);
virtual void deleteControlPoint(int selectedPoint);



virtual	Vec3f getVertex(int i);
virtual	int  getNumVertices();
	virtual TriangleMesh*  OutputTriangles(ArgParser *args);
	~Surface();
};
#endif // DEBUG



