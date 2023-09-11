#pragma once
#include "State_Grandma.h"

class SpinningState_Gm :
    public State_Grandma
{
public:
	SpinningState_Gm();
	virtual ~SpinningState_Gm() = default;

	virtual void Initialize() override;
	virtual void Update() override;

	virtual void Enter()  override;
	virtual void Exit()  override;
	virtual void PlayAnimation() override;

};

