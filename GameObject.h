#pragma once

#include <Windows.h>
#include <vector>
#include <d3dx9.h>
#include "Sprites.h"
#include "Animations.h"


using namespace std;

#define ID_TEX_BBOX -100		// special texture to draw object bounding box

class CGameObject;
typedef CGameObject* LPGAMEOBJECT;

struct CCollisionEvent;
typedef CCollisionEvent* LPCOLLISIONEVENT;
struct CCollisionEvent
{
	LPGAMEOBJECT obj;
	float t, nx, ny;

	float dx, dy;		// *RELATIVE* movement distance between this object and obj

	CCollisionEvent(float t, float nx, float ny, float dx = 0, float dy = 0, LPGAMEOBJECT obj = NULL)
	{
		this->t = t;
		this->nx = nx;
		this->ny = ny;
		this->dx = dx;
		this->dy = dy;
		this->obj = obj;
	}

	static bool compare(const LPCOLLISIONEVENT& a, LPCOLLISIONEVENT& b)
	{
		return a->t < b->t;
	}
};


class CGameObject
{
public:
	int type = -1;
	int isFinish = 0;
	float x = 0;
	float y = 0;

	float initialX = 0;
	float initialY = 0;

	float dx = 0;	// dx = vx*dt
	float dy = 0;	// dy = vy*dt

	float vx = 0;
	float vy = 0;

	int level = 0;
	int nx = 0;

	int state = -1;

	int id = 0;

	DWORD dt = NULL;

	LPANIMATION_SET animation_set = NULL;

public:
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }
	void GetPosition(float& x, float& y) { x = this->x; y = this->y; }
	void GetSpeed(float& vx, float& vy) { vx = this->vx; vy = this->vy; }

	bool CheckAABB(CGameObject* object);
	int GetState() { return this->state; }

	void RenderBoundingBox();

	void SetAnimationSet(LPANIMATION_SET ani_set) { animation_set = ani_set; }

	LPCOLLISIONEVENT SweptAABBEx(LPGAMEOBJECT coO);
	void CalcPotentialCollisions(vector<LPGAMEOBJECT>* coObjects, vector<LPCOLLISIONEVENT>& coEvents);
	void FilterCollision(
		vector<LPCOLLISIONEVENT>& coEvents,
		vector<LPCOLLISIONEVENT>& coEventsResult,
		float& min_tx,
		float& min_ty,
		float& nx,
		float& ny,
		float& rdx,
		float& rdy);

	CGameObject();

	float GetInitialX() { return this->initialX; };
	float GetInitialY() { return this->initialY; };
	void SetInitialX(float x) { this->initialX = x; };
	void SetInitialY(float y) { this->initialY = y; };

	float GetVx() { return vx; };
	float GetVy() { return vy; };
	void SetVx(float vx) { this->vx = vx; };
	void SetVy(float vy) { this->vy = vy; };

	int GetId() { return id; };
	void SetId(int id) { this->id = id; };

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) = 0;
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void Render() = 0;
	virtual void SetState(int state) { this->state = state; }


	~CGameObject();
};


