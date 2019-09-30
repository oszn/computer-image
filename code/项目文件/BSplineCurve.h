#ifndef __bspline__
#define __bspline__




#include "Curve.h"
class BSplineCurve :
	public Curve
{
public:
	BSplineCurve();
	BSplineCurve(int num);
	void set(int i, Vec3f v);
	void Paint(ArgParser *args);
	void OutputBezier(FILE *file);
	void OutputBSpline(FILE *file);
	void init();


	virtual void moveControlPoint(int selectedPoint, float x, float y);
	virtual void addControlPoint(int selectedPoint, float x, float y);
	virtual void deleteControlPoint(int selectedPoint);


	vector<Vec3f> getpara() {
		return para;
	}
	Vec3f getVertex(int i);
	int  getNumVertices();
	vector<Vec3f> re_point() { return temp_point; };
	vector<Vec3f> compu(ArgParser *args,int c);

	void setpara(int i, float x, float y);
	string curve_type() { return "bspline"; }
	~BSplineCurve();
private:
	vector<Vec3f> para;
	vector<Vec3f> temp_point;
	int number;
	float Bezier_data[4][4];
	float Bspline_data[4][4];
	Matrix tempb;
	Matrix tempsp;
	Matrix para_martrix;
};


#endif // !__bspline__