#include "pch.h"
#include "BezierPatch.h"


BezierPatch::BezierPatch()
{
}


BezierPatch::~BezierPatch()
{
}

void BezierPatch::set(int i, Vec3f v)
{
	para.push_back(v);
}

void BezierPatch::Paint(ArgParser * args)
{
	curve = new BezierCurve();
	for (int i = 0; i < para.size(); i++) {
		Vec3f v= para[i];
		curve->set(i,v);
	}
	curve->Paint(args);
}

void BezierPatch::OutputBezier(FILE * file)
{

}

void BezierPatch::OutputBSpline(FILE * file)
{
}

Vec3f BezierPatch::getVertex(int i)
{
	return Vec3f();
}

int BezierPatch::getNumVertices()
{
	return 0;
}

TriangleMesh * BezierPatch::OutputTriangles(ArgParser * args)
{
	saveponit(args);
	TriangleNet *temp=new TriangleNet(args->patch_tessellation,args->patch_tessellation);
	for(int i=0;i<args->patch_tessellation+1;i++)
		for (int j = 0; j < args->patch_tessellation+1; j++) {
			temp->SetVertex(i, j, result[i][j]);
		}
	return temp;
}

void BezierPatch::saveponit(ArgParser * args)
{
	for (int i = 0; i < 4; i++) {
		curve = new BezierCurve();
		for (int j = 0; j < 4; j++) {
			curve->set(j, para[i * 4 + j]);
		}
		curve->cmp(args->patch_tessellation,0);
		alix.push_back(curve->re_point());
	}
	for (int i = 0; i < alix[0].size(); i++) {
		curve = new BezierCurve();
		for (int j = 0; j < 4; j++) {
			curve->set(j, alix[j][i]);
		}
		curve->cmp(args->patch_tessellation, 0);
		result.push_back(curve->re_point());
	}
}
