#include "QuadTree.h"

bool QuadTree::Insert(Vector2D * pvVector2D)
{
	//Ignore objects which are outside
	if(!this->rQuadTreeBounds.Contains(pvVector2D))
		return false;

	//If there is space in this quad tree, add the object here
	if(this->ObjectsInNode < this->QT_NODE_CAPACITY)
	{
		this->pvNodes[this->ObjectsInNode] = pvVector2D;
		this->ObjectsInNode++;
		return true;
	}

	//Otherwise, we need to subdivide then add the point to whichever node will accept it
	if(this->nw == NULL)
		Subdivide();

	if(this->nw->Insert(pvVector2D) || this->ne->Insert(pvVector2D) || this->sw->Insert(pvVector2D) || this->se->Insert(pvVector2D))
		return true;

	//Otherwise, the point cannot be inserted for some unknown reason (which should never happen)
	return false;
}

bool QuadTree::Subdivide()
{
	if(this->ne != 0 || this->nw != 0 || this->sw != 0 || this->se != 0)
		return false;

	this->ne = new QuadTree(Rect(this->rQuadTreeBounds.x + (this->rQuadTreeBounds.w >> 1), this->rQuadTreeBounds.y, this->rQuadTreeBounds.w >> 1, this->rQuadTreeBounds.h >> 1));
	this->se = new QuadTree(Rect(this->rQuadTreeBounds.x + (this->rQuadTreeBounds.w >> 1), this->rQuadTreeBounds.y + (this->rQuadTreeBounds.h >> 1), this->rQuadTreeBounds.w >> 1, this->rQuadTreeBounds.h >> 1));
	this->nw = new QuadTree(Rect(this->rQuadTreeBounds.x, this->rQuadTreeBounds.y, this->rQuadTreeBounds.w >> 1, this->rQuadTreeBounds.h >> 1));
	this->sw = new QuadTree(Rect(this->rQuadTreeBounds.x, this->rQuadTreeBounds.y + (this->rQuadTreeBounds.h >> 1), this->rQuadTreeBounds.w >> 1, this->rQuadTreeBounds.h >> 1));
	
	return true;
}

void QuadTree::DeleteChildren()
{
	if(this->nw != NULL)
	{
		this->nw->DeleteChildren();
		delete this->nw;
		this->nw = NULL;
	}
	if(this->ne != NULL)
	{
		this->ne->DeleteChildren();
		delete this->ne;
		ne = NULL;
	}
	if(sw != NULL)
	{
		this->sw->DeleteChildren();
		delete this->sw;
		this->sw = NULL;
	}
	if(this->se != NULL)
	{
		this->se->DeleteChildren();
		delete this->se;
		this->se = NULL;
	}
}

void QuadTree::Generate(Object * Objects[], int nID)
{
	DeleteChildren();
	
	if(nID > 0)
	{
		for(int i = 0; i < nID; i++)
			Insert(Objects[i]->GetPosition());
	}
}