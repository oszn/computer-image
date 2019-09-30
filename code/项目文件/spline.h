#ifndef __spile__
#define __spile__
#include"triangle_mesh.h"
#include <stdio.h>
#include <stdlib.h>
#include"arg_parser.h"
#include<GL/glut.h>
#include<vector>
#include"matrix.h"
#include<corecrt_wstdio.h>
#include<math.h>
#include<algorithm>
#include<set>

using namespace std;
class Spline {
public:

	virtual void Paint(ArgParser *args);

	virtual void OutputBezier(FILE *file);
	virtual void OutputBSpline(FILE *file);

	virtual Vec3f getVertex(int i);
	virtual int  getNumVertices();

	// 用于编辑操作的FOR EDITING OPERATIONS
	virtual void moveControlPoint(int selectedPoint, float x, float y);
	virtual void addControlPoint(int selectedPoint, float x, float y);
	virtual void deleteControlPoint(int selectedPoint);

	// 用于产生三角形的FOR GENERATING TRIANGLES
	virtual TriangleMesh*  OutputTriangles(ArgParser *args);
};

#endif // !1

