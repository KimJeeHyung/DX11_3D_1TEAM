#pragma once
#include "Map.h"
class Right2Map :
    public Map
{
public:
	Right2Map();
	virtual ~Right2Map();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void FinalUpdate();
	virtual void Render();

	virtual void Enter();
	virtual void Exit();
};
