#ifndef __cur__
#define __cur__
#include "spline.h"

class Curve :
	public Spline
{
public:
	Curve();
	virtual void set(int i, Vec3f v);
	virtual void Paint(ArgParser *args);
	virtual void OutputBezier(FILE *file);
	virtual void OutputBSpline(FILE *file);
	virtual int  getNumVertices();


	virtual void moveControlPoint(int selectedPoint, float x, float y);
	virtual void addControlPoint(int selectedPoint, float x, float y);
	virtual void deleteControlPoint(int selectedPoint);

	virtual void setpara(int i, float x, float y);

	virtual Vec3f getVertex(int i);
	virtual vector<Vec3f> getpara() { return mxp;}
	virtual vector<Vec3f> re_point() { return temp_point; }
	virtual vector<Vec3f> compu(ArgParser *args, int c) { return mxp; }
	virtual string curve_type(){return "curve";}
	virtual vector<Vec3f> cmp(int k,int c);
	~Curve();
private:
	vector<Vec3f> mxp;
	vector<Vec3f> temp_point;
};

#endif // !1



