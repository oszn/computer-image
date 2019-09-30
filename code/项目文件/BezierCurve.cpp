#include "pch.h"
#include "BezierCurve.h"


BezierCurve::BezierCurve()
{
}

BezierCurve::BezierCurve(int num)
{
	number = num;
}
vector<Vec3f> BezierCurve::cmp(int k, int c)
{
	vector<Vec3f> point;
	float t = 0;
	float add = 1.0 / k;
	cout << add << endl;
	//cout << number;
	for (int i = 0; i <= k; i++) {
		if (i == k)
			t = 1;
		float x = powf((1 - t), 3)*para[c + 0].x() + 3 * t*powf((1 - t), 2)*para[c + 1].x() + 3 * pow(t, 2)*(1 - t)*para[c + 2].x() + pow(t, 3)*para[c + 3].x();
		float y = powf((1 - t), 3)*para[c + 0].y() + 3 * t*powf((1 - t), 2)*para[c + 1].y() + 3 * pow(t, 2)*(1 - t)*para[c + 2].y() + pow(t, 3)*para[c + 3].y();
		float z = powf((1 - t), 3)*para[c + 0].z() + 3 * t*powf((1 - t), 2)*para[c + 1].z() + 3 * pow(t, 2)*(1 - t)*para[c + 2].z() + pow(t, 3)*para[c + 3].z();
		//cout << x << " " << y << " " << z << endl;
		//v.Get(x, y, z);
		Vec3f v(x, y, z);
		point.push_back(v);
		temp_point.push_back(v);
		t = t + add;
		//cout << t; 
		if (i == 29)
			int a = 0;
	}

	return point;
}
vector<Vec3f> BezierCurve::compu(ArgParser *args,int c) {
	vector<Vec3f> point;
	float t=0;
	float add = 1.0/args->curve_tessellation;
	cout << add<<endl;
	//cout << number;
	for (int i = 0; i <=args->curve_tessellation; i++) {
		if (i == args->curve_tessellation)
			t = 1;
		float x = powf((1 - t), 3)*para[c+0].x() + 3 * t*powf((1 - t), 2)*para[c+1].x() + 3 * pow(t, 2)*(1 - t)*para[c+2].x() + pow(t, 3)*para[c+3].x();
		float y = powf((1 - t), 3)*para[c+0].y() + 3 * t*powf((1 - t), 2)*para[c+1].y() + 3 * pow(t, 2)*(1 - t)*para[c+2].y() + pow(t, 3)*para[c+3].y();
		float z = powf((1 - t), 3)*para[c+0].z() + 3 * t*powf((1 - t), 2)*para[c+1].z() + 3 * pow(t, 2)*(1 - t)*para[c+2].z() + pow(t, 3)*para[c+3].z();
		//cout << x << " " << y << " " << z << endl;
		//v.Get(x, y, z);
		Vec3f v(x,y,z);
		point.push_back(v);
		temp_point.push_back(v);
		t = t + add;
		//cout << t; 
		if (i == 29)
			int a = 0;
	}
	
	return point;
}
void BezierCurve::set(int i, Vec3f v) {
	para.push_back(v);
}
void BezierCurve::Paint(ArgParser *args) {
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
		for (int j = 0; j < number / 3; j++) {
			vector<Vec3f> temp = compu(args,j*3);
			for (int i = 0; i <= args->curve_tessellation; i++) {
				//cout << temp[i].x() << " " << temp[i].y() << " " << temp[i].z() << endl;
				glVertex2f(temp[i].x(), temp[i].y());
			}
		}
		glEnd();

	}
}
void BezierCurve::OutputBezier(FILE * file)
{
	fprintf(file, "\n");
	fprintf(file, "bezier\n");
	fprintf(file, "num_vertices %d\n", number);
	for (int i = 0; i < para.size(); i++) {
		cout << para[i].x() << para[i].y() << para[i].z() << endl;
		fprintf(file, "%f %f %f\n", para[i].x(), para[i].y(), para[i].z());
	}
}
vector<Vec3f> ttdx(vector<Vec3f> p) {

	return p;
}
void BezierCurve::OutputBSpline(FILE * file)
{
	init();
	int count = tempsp.Inverse();
	Matrix result = para_martrix * tempb*tempsp*(1.0/6);
	vector<Vec3f> gcx;
	for (int i = 0; i < 4; i++) {
		Vec3f v(result.Get(i,0),result.Get(i,1),result.Get(i,2));
		gcx.push_back(v);
	}
	fprintf(file, "\n");
	fprintf(file, "bspline\n");
	fprintf(file, "num_vertices %d\n", number);
	for (int i = 0; i < para.size(); i++) {
		//cout << para[i].x() << para[i].y() << para[i].z() << endl;
		fprintf(file, "%f %f %f\n", gcx[i].x(), gcx[i].y(), gcx[i].z());
	}
}
void BezierCurve::init()
{
	FILE *fpx;
	fpx=fopen("parament.txt","r");
	for (int i = 0; i < 8; i++) {
		if (i < 4)
		{
			float a[4];
			int count = fscanf(fpx, "%f %f %f %f", &a[0], &a[1], &a[2], &a[3]);
			for(int j=0;j<4;j++)
			{
				tempb.Set(j, i, a[j]);
			}
		}
		else {
			float a[4];
			int count = fscanf(fpx, "%f %f %f %f", &a[0], &a[1], &a[2], &a[3]);
			for (int j = 0; j < 4; j++)
			{
				tempsp.Set(j, i-4, a[j]);
			}
		}
	}
	for (int i = 0; i < para.size(); i++) {
		para_martrix.Set(i, 0, para[i].x());
		para_martrix.Set(i, 1, para[i].y());
		para_martrix.Set(i, 2, para[i].z());
	}
	 //int const count = tempb.Inverse(tempb, 0);
	 //Matrix temps = tempb *(1.0/6);
}
void BezierCurve::setpara(int i, float x, float y)
{
}
Vec3f BezierCurve::getVertex(int i)
{
	return para[i];
}
int BezierCurve::getNumVertices()
{
	return para.size();
}
void BezierCurve::moveControlPoint(int selectedPoint, float x, float y)
{
	para[selectedPoint] = Vec3f(x, y, 0);
}
void BezierCurve::addControlPoint(int selectedPoint, float x, float y)
{
}
void BezierCurve::deleteControlPoint(int selectedPoint)
{
}
BezierCurve::~BezierCurve()
{

}
