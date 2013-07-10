#pragma once

#include "Globals.h"
#include <SDL.h>
#include "Object.h"


struct Rect
{
	int x, y, w, h;
	Rect() : x(0), y(0), w(0), h(0) { }
	Rect(int X, int Y, int W, int H) : x(X), y(Y), w(W), h(H) { }
	Rect(SDL_Rect& R) : x(R.x), y(R.y), w(R.w), h(R.h) { }

	inline bool Contains(Vector2D * pvVector2D) {return (pvVector2D->x >= x && pvVector2D->y >= y && pvVector2D->x < x + w && pvVector2D->y < y + h);}
	inline bool Intersects(Rect& r) {return !(r.x > (x + w) || (r.x + r.w) < x || r.y > (y + h) || (r.y + r.h) < y);}
	inline SDL_Rect ToSDL() {SDL_Rect r = {x, y, w, h}; return r;}
};

//A single layer of a quad tree
class QuadTree
{
private:
	// Arbitrary constant to indicate how many elements can be stored in this quad tree node
	static const int QT_NODE_CAPACITY = 4;

	// Axis-aligned bounding box stored as a center with half-dimensions
	// to represent the boundaries of this quad tree
	Rect rQuadTreeBounds;

	//data inside
	Vector2D * pvNodes[QT_NODE_CAPACITY];
	int ObjectsInNode;

	QuadTree * nw;
	QuadTree * ne;
	QuadTree * sw;
	QuadTree * se;

public:
	QuadTree(Rect rBounds) : ObjectsInNode(0)
	{
		rQuadTreeBounds = rBounds;

		for(int i = 0; i < QT_NODE_CAPACITY; i++)
			pvNodes[i] = new Vector2D(0.0, 0.0);

		ne = NULL;
		se = NULL;
		nw = NULL;
		sw = NULL;

		cout << "Constructor Quadtree called" << endl;
	}

	~QuadTree()
	{
		for (int i = 0; i < QT_NODE_CAPACITY; i++)
		{
			pvNodes[i] = NULL;
		}

		cout << "Destructor Quadtree called" << endl;
	}
	
	bool Insert(Vector2D * pvVector2D);
	bool Subdivide();
	void DeleteChildren();
	void Generate(Object * Objects[], int nID);
};