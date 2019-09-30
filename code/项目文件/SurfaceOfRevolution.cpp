#include "pch.h"
#include "SurfaceOfRevolution.h"
#define pi 3.14159265

SurfaceOfRevolution::SurfaceOfRevolution()
{
}
SurfaceOfRevolution::SurfaceOfRevolution(Curve*a) {
	curve = a;
}

SurfaceOfRevolution::~SurfaceOfRevolution()
{
}

void SurfaceOfRevolution::Paint(ArgParser * args)
{
	curve->Paint(args);
}

void SurfaceOfRevolution::OutputBezier(FILE * file)
{
}

void SurfaceOfRevolution::OutputBSpline(FILE * file)
{
	fprintf(file, "\nsurface_of_revolution");
	curve->OutputBSpline(file);
}

Vec3f SurfaceOfRevolution::getVertex(int i)
{
	return curve->getpara()[i];
}
void SurfaceOfRevolution::resultset(vector<Vec3f> p, int n) {
	for (float j = 0; j < n; j++) {
		vector<Vec3f> temp;
		for (int i = 0; i < p.size(); i++) {
			float y = p[i].y();
			float x = p[i].x()*cos(pi*2*(j)/n);
			float z = p[i].x()*sin(pi*2*(j)/n);
			Vec3f v(x,y,z);
			temp.push_back(v);
		}
		result.push_back(temp);
	}
}
void SurfaceOfRevolution::moveControlPoint(int selectedPoint, float x, float y)
{
	cout << "!";
	curve->moveControlPoint(selectedPoint, x, y);
}
void SurfaceOfRevolution::addControlPoint(int selectedPoint, float x, float y)
{
	curve->addControlPoint(selectedPoint, x, y);
}
void SurfaceOfRevolution::deleteControlPoint(int selectedPoint)
{
	curve->deleteControlPoint(selectedPoint);
}
vector<Vec3f> pick_diff(vector<Vec3f> p) {
	int k = 0;
	for(int i=0;i<p.size()-k;i++)
		for (int j = i+1; j < p.size()-k; j++) {
			k = 0;
			if (p[i] == p[j]) {
				p.erase(p.begin() + j);
				k = 1;
			}
		}
	return p;
}
TriangleMesh * SurfaceOfRevolution::OutputTriangles(ArgParser * args)
{
	int vnum = (curve->getpara().size() + 1)/4*5;
	if (curve->curve_type() == "bezier")
		for (int i = 0; i < vnum / 5; i++)
		{
			vector<Vec3f>temp = curve->compu(args, i * 3);
		}
	else {
		for (int i = 0; i < curve->getpara().size() - 4; i++)
		{
			vector<Vec3f>temp = curve->compu(args, i);
		}
	}

	vector<Vec3f> ruby = pick_diff(curve->re_point());

	resultset(ruby,args->revolution_tessellation);
	int n = args->revolution_tessellation*ruby.size();
	TriangleMesh *temp=new TriangleMesh(n,2*n);
	int r_t = args->revolution_tessellation;

	for (int i = 0; i < args->revolution_tessellation; i++) {
		for (int j = 0; j < result[0].size(); j++) {
			temp->SetVertex(ruby.size()*i + j,result[i][j]);
		}
	}
	for (int i = 0; i < args->revolution_tessellation; i++) {


		for (int j = 0; j < result[0].size(); j++) {
			if (i + 1 == args->revolution_tessellation)
			{
				int a = i * (result[0].size()) + j;
				cout << a;
				temp->SetTriangle(a, a, i * (result[0].size()) + (j + 1) % ruby.size(), j);
			}
			else {
				int a = i * (result[0].size()) + j;
				temp->SetTriangle(a, a, i * (result[0].size()) + (j + 1) % ruby.size(), a + ruby.size());
			}
		}
	}
	for (int i = 0; i < args->revolution_tessellation; i++) {
		for (int j = 0; j < result[0].size(); j++) {
			if (i == 0) {
				int a = i * (result[0].size()) + j;
				temp->SetTriangle(a + n, a, i * (result[0].size()) + (j + 1) % ruby.size(), n - ruby.size() + i * (result[0].size()) + (j + 1) % ruby.size());
			}
			else {
				int a = i * (result[0].size()) + j;
				temp->SetTriangle(a + n, a, i * (result[0].size()) + (j + 1) % ruby.size(), i * (result[0].size()) + (j + 1) % ruby.size() - ruby.size());
			}
		}
	}
	return temp;
}

int SurfaceOfRevolution::getNumVertices()
{
	return curve->getpara().size();
}
