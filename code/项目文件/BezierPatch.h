#include "Surface.h"
#include"pch.h"
#include"BezierCurve.h"
class BezierPatch :
	public Surface
{
public:
	BezierPatch();
	~BezierPatch();
	void set(int i, Vec3f v);
	void Paint(ArgParser *args);


	void OutputBezier(FILE *file);
	void OutputBSpline(FILE *file);

	Vec3f getVertex(int i);
	int  getNumVertices();
	TriangleMesh*  OutputTriangles(ArgParser *args);
	void saveponit(ArgParser *args);
private:
	vector<Vec3f> para;
	vector<vector<Vec3f>> alix;
	vector<vector<Vec3f>> result;
	int number;
	Curve *curve;
};

