#include "pch.h"
#include "PlayerMoveScript.h"
#include "GameObject.h"
#include "Input.h"
#include "Transform.h"
#include "RigidBody.h"

PlayerMoveScript::PlayerMoveScript()
	: mMoveSpeed(3.f)
{
}

void PlayerMoveScript::FixedUpdate()
{
	if (IS_PRESS(KeyType::UP))
	{
		GetRigidBody()->SetVelocity(AXIS_Z, mMoveSpeed);
	}

	if (IS_PRESS(KeyType::DOWN))
	{
		GetRigidBody()->SetVelocity(AXIS_Z, -mMoveSpeed);
	}

	if (IS_PRESS(KeyType::LEFT))
	{
		GetRigidBody()->SetVelocity(AXIS_X, -mMoveSpeed);
	}

	if (IS_PRESS(KeyType::RIGHT))
	{
		GetRigidBody()->SetVelocity(AXIS_X, mMoveSpeed);
	}

	if (IS_DOWN(KeyType::SPACE))
	{
		GetRigidBody()->SetVelocity(AXIS_Y, mMoveSpeed);
	}
}

Component* PlayerMoveScript::Clone(GameObject* _pGameObject)
{
	return _pGameObject->AddComponent(new PlayerMoveScript);
}
