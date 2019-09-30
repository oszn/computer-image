#ifndef __berziercure__
#define __berziercure__

#include "Curve.h"
class BezierCurve :
	public Curve
{
public:
	BezierCurve();
	BezierCurve(int num);
	void set(int i, Vec3f v);
	void Paint(ArgParser *args);
	void OutputBezier(FILE *file);
	void OutputBSpline(FILE *file);
	void init();
    void setpara(int i, float x, float y);

	Vec3f getVertex(int i);
	int  getNumVertices();
	vector<Vec3f> getpara() {
		return para;
	}

	virtual void moveControlPoint(int selectedPoint, float x, float y);
	virtual void addControlPoint(int selectedPoint, float x, float y);
	virtual void deleteControlPoint(int selectedPoint);


	vector<Vec3f> cmp(int k,int c);
	vector<Vec3f> compu(ArgParser *args, int i);
	vector<Vec3f> re_point() { return temp_point; };
	string curve_type() { return "bezier"; }
	~BezierCurve();
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

#endif // !__berziercure__
