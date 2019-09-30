#include "pch.h"
#include "BSplineCurve.h"
#define t1 (pow((1-t),3)/6)
#define t2 ((3*pow(t,3)-6*pow(t,2)+4)/6)
#define t3 ((1+3*t+3*pow(t,2)-3*pow(t,3))/6)
#define t4 (pow(t,3)/6)

BSplineCurve::BSplineCurve()
{
}
BSplineCurve::BSplineCurve(int num) {
		number = num;
}


Vec3f BSplineCurve::getVertex(int i)
{
	return para[i];
}

int BSplineCurve::getNumVertices()
{
	return para.size();
}

vector<Vec3f> BSplineCurve::compu(ArgParser *args,int c) {
	vector<Vec3f> point;
	float t = 0;
	float add = 1.0 / args->curve_tessellation;
	cout << add << endl;
	//cout << number;
	
	for (int i = 0; i <= args->curve_tessellation; i++) {
		float x = t1*para[0+c].x() + t2*para[1+c].x() + t3*para[2+c].x() + t4*para[3+c].x();
		float y = t1*para[0+c].y() + t2*para[1+c].y() + t3*para[2+c].y() + t4*para[3+c].y();
		float z = t1*para[0+c].z() + t2*para[1+c].z() + t3*para[2+c].z() + t4*para[3+c].z();
		//cout << x << " " << y << " " << z << endl;
		//v.Get(x, y, z);
		Vec3f v(x, y, z);
		point.push_back(v);
		temp_point.push_back(v);
		t = t + add;
		//cout << t;
	}
	return point;
}

void BSplineCurve::setpara(int i, float x, float y)
{
	para[i] = Vec3f(x, y, 0);
}


void BSplineCurve::set(int i, Vec3f v)
{ 
	para.push_back(v);
};
void BSplineCurve::Paint(ArgParser *args)
{
	if (number == 4) {
		glColor3f(0.0, 0.0, 1.0);
		glPointSize(10);
		glBegin(GL_POINTS);
		for (int i = 0; i < para.size(); i++) {
			glVertex3f(para[i].x(), para[i].y(), para[i].z());
		}
		glEnd();
		glBegin(GL_LINE_STRIP);

		for (int i = 0; i < para.size(); i++) {
			glVertex3f(para[i].x(), para[i].y(), para[i].z());
		}
		glEnd();

		vector<Vec3f> temp = compu(args,0);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i <= args->curve_tessellation; i++) {
			//cout << temp[i].x() << " " << temp[i].y() << " " << temp[i].z() << endl;
			glVertex2f(temp[i].x(), temp[i].y());
		}
		glEnd();
	}
	else {
		glColor3f(0.0, 0.0, 1.0);
		glPointSize(10);
		glBegin(GL_POINTS);
		for (int i = 0; i < para.size(); i++) {
			glVertex3f(para[i].x(), para[i].y(), para[i].z());
		}
		glEnd();
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < para.size(); i++) {
			glVertex3f(para[i].x(), para[i].y(), para[i].z());
		}
		glEnd();
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0, 1.0, 0.0);
		for (int j = 0; j < para.size() -3; j++) {
			vector<Vec3f> temp = compu(args, j);
			for (int i = 0; i <= args->curve_tessellation; i++) {
				//cout << temp[i].x() << " " << temp[i].y() << " " << temp[i].z() << endl;
				glVertex2f(temp[i].x(), temp[i].y());
			}
		}
		glEnd();

	}
}
void BSplineCurve::OutputBezier(FILE * file)
{
	init();
	int count = tempb.Inverse();
	Matrix result = para_martrix * tempsp*tempb*(1.0/6);
	vector<Vec3f> gcx;
	for (int i = 0; i < 4; i++) {
		Vec3f v(result.Get(i, 0), result.Get(i, 1), result.Get(i, 2));
		gcx.push_back(v);
	}
	cout << "suc";
	fprintf(file, "\n");
	fprintf(file, "bezier\n");
	fprintf(file, "num_vertices %d\n", number);
	for (int i = 0; i < para.size(); i++) {
		//cout << para[i].x() << para[i].y() << para[i].z() << endl;
		fprintf(file, "%f %f %f\n", gcx[i].x(), gcx[i].y(), gcx[i].z());
	}
	cout << "suc2";
}
void BSplineCurve::OutputBSpline(FILE * file)
{
	cout << "suc";
	fprintf(file, "\n");
	fprintf(file, "bspline\n");
	fprintf(file, "num_vertices %d\n", number);
	for (int i = 0; i < para.size(); i++) {
		cout << para[i].x() << para[i].y() << para[i].z() << endl;
		fprintf(file, "%f %f %f\n", para[i].x(), para[i].y(), para[i].z());
	}
	cout << "suc";
}
void BSplineCurve::init()
{
	FILE *fpx;
	fpx = fopen("parament.txt", "r");
	for (int i = 0; i < 8; i++) {
		if (i < 4)
		{
			float a[4];
			int count = fscanf(fpx, "%f %f %f %f", &a[0], &a[1], &a[2], &a[3]);
			for (int j = 0; j < 4; j++)
			{
				tempb.Set(j, i, a[j]);
			}
		}
		else {
			float a[4];
			int count = fscanf(fpx, "%f %f %f %f", &a[0], &a[1], &a[2], &a[3]);
			for (int j = 0; j < 4; j++)
			{
				tempsp.Set(j, i - 4, a[j]);
			}
		}
	}
	for (int i = 0; i < para.size(); i++) {
		para_martrix.Set(i, 0, para[i].x());
		para_martrix.Set(i, 1, para[i].y());
		para_martrix.Set(i, 2, para[i].z());
	}
}
void BSplineCurve::moveControlPoint(int selectedPoint, float x, float y)
{
	cout << x;
	para[selectedPoint] = Vec3f(x, y, 0);
}
void BSplineCurve::addControlPoint(int selectedPoint, float x, float y)
{
	para.insert(para.begin() + selectedPoint, Vec3f(x, y, 0));
}
void BSplineCurve::deleteControlPoint(int selectedPoint)
{
	para.erase(para.begin() + selectedPoint);
}
;
BSplineCurve::~BSplineCurve()
{
}
