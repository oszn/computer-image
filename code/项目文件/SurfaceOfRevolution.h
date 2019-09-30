#include "Surface.h"
#include"Curve.h"
#include"BezierCurve.h"
#include"BSplineCurve.h"
class SurfaceOfRevolution :
	public Surface
{
public:
	SurfaceOfRevolution();
	SurfaceOfRevolution(Curve*a);
	~SurfaceOfRevolution();
	void Paint(ArgParser *args);
	void OutputBezier(FILE *file);
	void OutputBSpline(FILE *file);
	void  resultset( vector<Vec3f> p, int n);

	void moveControlPoint(int selectedPoint, float x, float y);
	void addControlPoint(int selectedPoint, float x, float y);
	void deleteControlPoint(int selectedPoint);



	Vec3f getVertex(int i);
	TriangleMesh*  OutputTriangles(ArgParser *args);
	int  getNumVertices();
private:
	vector<Vec3f> para;
	vector<vector<Vec3f>> result;
	int number;
	Curve *curve;
};

