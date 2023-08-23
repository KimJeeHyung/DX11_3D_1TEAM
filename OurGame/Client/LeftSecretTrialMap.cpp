#include "pch.h"
#include "LeftSecretTrialMap.h"
#include "Engine.h"

/* Resource */
#include "MeshData.h"
#include "Material.h"
#include "Mesh.h"

/* Manager */
#include "PrefabManager.h"
#include "EventManager.h"
#include "Factory.h"
#include "CollisionManager.h"
#include "Input.h"
#include "SceneManager.h"
#include "Resources.h"

/* GameObject */
#include "GameObject.h"
#include "Player.h"
#include "Ground.h"
#include "DecoObject.h"
#include "Monster.h"

/* Component */
#include "Collider.h"
#include "RigidBody.h"
#include "MeshRenderer.h"
#include "Transform.h"
#include "Camera.h"
#include "Light.h"
#include "ParticleSystem.h"
#include "UIText.h"

/* Script */
#include "PaperBurnScript.h"
#include "CameraMoveScript.h"
#include "PlayerMoveScript.h"
#include "PlayerSlashScript.h"
#include "PlacementScript.h"
#include "TestAnimationScript.h"

/* Event */
#include "SceneChangeEvent.h"

LeftSecretTrialMap::LeftSecretTrialMap()
	: Map(MapType::LeftSecretTrialMap)
{
}

LeftSecretTrialMap::~LeftSecretTrialMap()
{
}

void LeftSecretTrialMap::Initialize()
{
	Map::Initialize();
}

void LeftSecretTrialMap::Update()
{
	Map::Update();
}

void LeftSecretTrialMap::FixedUpdate()
{
	Map::FixedUpdate();
}

void LeftSecretTrialMap::FinalUpdate()
{
	Map::FinalUpdate();
}

void LeftSecretTrialMap::Render()
{
	Map::Render();
}

void LeftSecretTrialMap::Enter()
{
	GET_SINGLE(CollisionManager)->SetCollisionGroup(LayerType::Player, LayerType::Ground);
	GET_SINGLE(CollisionManager)->SetCollisionGroup(LayerType::Player, LayerType::WallObject);

	//배경맵 하얀색으로 만들어주는 코드
	//gpEngine->SetSwapChainRTVClearColor(Vec4(255.f, 255.f, 255.f, 255.f));


#pragma region "어드민"
#pragma endregion

	//DecoObject == 콜라이더 없는 오브젝트
	//WallObject == 콜라이더 있는 오브젝트

	//Forward == 빛 계산이 없는 명령어
	//Deferred == 빛 계산이 있는 명령어

	//->GetTransform()->SetPositionExcludingColliders == 콜라이더를 제외하고 오브젝트만 [이동] 시키는 함수
	//->GetTransform()->SetRotationExcludingColliders == 콜라이더를 제외하고 오브젝트만 [회전] 시키는 함수
	
	//Deferred_CullNone == 머테리얼 카메라 시점 짤림 없애는 버전 _원본 그대로
		




	//전체적인 가이드 라인 - Cube
	{
		DecoObject* pCube = Factory::CreateObject<DecoObject>(Vec3(0.0f, 0.0f, 0.0f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\Cube.fbx");
		pCube->GetTransform()->SetScale(Vec3(50.f, 50.f, 50.f));

		AddGameObject(pCube);
	}

	//위층 바닥 - RoughUpperFloor
	{
		DecoObject* pRoughUpperFloor = Factory::CreateObject<DecoObject>(Vec3(-1.95f, -3.6f, -0.9f), L"Deferred_CullNone", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\RoughUpperFloor.fbx");
		pRoughUpperFloor->GetTransform()->SetScale(Vec3(52.f, 52.f, 52.f));
		AddGameObject(pRoughUpperFloor);
	}

	//아래층 바닥 - RoughLowerFloor
	{
		DecoObject* pRoughLowerFloor = Factory::CreateObject<DecoObject>(Vec3(-4.35f, -4.f, 3.4f), L"Deferred_CullNone", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\RoughLowerFloor.fbx");
		pRoughLowerFloor->GetTransform()->SetScale(Vec3(43.f, 43.f, 43.2f));
		
		AddGameObject(pRoughLowerFloor);
	}
#pragma region "기둥"
	{
		//기둥 모음집 - ColumnFull

		{
			//위에층 맨왼쪽 기둥
			DecoObject* pColumnFull = Factory::CreateObject<DecoObject>(Vec3(-10.2f, 1.4f, 6.2f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\ColumnFull.fbx");
			pColumnFull->GetTransform()->SetRotation(Vec3(0.f, -90.f, 0.f));
			pColumnFull->GetTransform()->SetScale(Vec3(32.f, 32.f, 32.f));
			
			AddGameObject(pColumnFull);
		}

		{
			//위에층 맨왼쪽 부터 두번째 기둥
			DecoObject* pColumnFull = Factory::CreateObject<DecoObject>(Vec3(-10.2f, 1.4f, -13.4f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\ColumnFull.fbx");
			pColumnFull->GetTransform()->SetRotation(Vec3(0.f, -90.f, 0.f));
			pColumnFull->GetTransform()->SetScale(Vec3(32.f, 32.f, 32.f));
			
			AddGameObject(pColumnFull);
		}

		{
			//위에층 맨왼쪽 부터 세번째 기둥
			DecoObject* pColumnFull = Factory::CreateObject<DecoObject>(Vec3(-19.7f, 1.4f, -22.8f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\ColumnFull.fbx");
			pColumnFull->GetTransform()->SetRotation(Vec3(0.f, -90.f, 0.f));
			pColumnFull->GetTransform()->SetScale(Vec3(32.f, 32.f, 32.f));

			AddGameObject(pColumnFull);
		}

		{
			//위에층 맨왼쪽 부터 네번째 기둥
			DecoObject* pColumnFull = Factory::CreateObject<DecoObject>(Vec3(-25.f, 1.4f, -22.8f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\ColumnFull.fbx");
			pColumnFull->GetTransform()->SetRotation(Vec3(0.f, -90.f, 0.f));
			pColumnFull->GetTransform()->SetScale(Vec3(32.f, 32.f, 32.f));
		
			AddGameObject(pColumnFull);
		}

		{
			//아래층 맨오른쪽 부터 작은기둥 _ 첫번째 기둥
			DecoObject* pColumnFull = Factory::CreateObject<DecoObject>(Vec3(-9.2f, -1.8f, -2.7f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\ColumnFull.fbx");
			pColumnFull->GetTransform()->SetRotation(Vec3(0.f, 0.f, 0.f));
			pColumnFull->GetTransform()->SetScale(Vec3(32.f, 23.f, 32.f));
			
			AddGameObject(pColumnFull);
		}

		{
			//아래층 맨오른쪽 부터 작은기둥 _ 두번째 기둥
			DecoObject* pColumnFull = Factory::CreateObject<DecoObject>(Vec3(-9.2f, -1.8f, 17.4f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\ColumnFull.fbx");
			pColumnFull->GetTransform()->SetRotation(Vec3(0.f, 0.f, 0.f));
			pColumnFull->GetTransform()->SetScale(Vec3(32.f, 23.f, 32.f));
			
			AddGameObject(pColumnFull);
		}

		{
			//아래층 맨오른쪽 부터 작은기둥 _ 세번째 기둥
			DecoObject* pColumnFull = Factory::CreateObject<DecoObject>(Vec3(0.7f, -1.8f, 17.4f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\ColumnFull.fbx");
			pColumnFull->GetTransform()->SetRotation(Vec3(0.f, 0.f, 0.f));
			pColumnFull->GetTransform()->SetScale(Vec3(32.f, 23.f, 32.f));
			
			AddGameObject(pColumnFull);
		}

		{
			//아래층 맨오른쪽 부터 큰기둥 _ 첫번째 기둥
			DecoObject* pColumnFull = Factory::CreateObject<DecoObject>(Vec3(-4.1f, 0.2f, -2.6f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\ColumnFull.fbx");
			pColumnFull->GetTransform()->SetRotation(Vec3(0.f, 0.f, 0.f));
			pColumnFull->GetTransform()->SetScale(Vec3(32.f, 45.f, 32.f));
			
			AddGameObject(pColumnFull);
		}

		{
			//아래층 맨오른쪽 부터 큰기둥 _ 두번째 기둥
			DecoObject* pColumnFull = Factory::CreateObject<DecoObject>(Vec3(0.65f, 0.2f, -2.6f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\ColumnFull.fbx");
			pColumnFull->GetTransform()->SetRotation(Vec3(0.f, 0.f, 0.f));
			pColumnFull->GetTransform()->SetScale(Vec3(32.f, 45.f, 32.f));
			
			AddGameObject(pColumnFull);
		}

		{
			//아래층 맨오른쪽 부터 큰기둥 _ 세번째 기둥
			DecoObject* pColumnFull = Factory::CreateObject<DecoObject>(Vec3(0.65f, 0.2f, 2.2f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\ColumnFull.fbx");
			pColumnFull->GetTransform()->SetRotation(Vec3(0.f, 0.f, 0.f));
			pColumnFull->GetTransform()->SetScale(Vec3(32.f, 45.f, 32.f));
			AddGameObject(pColumnFull);
		}
	}
#pragma endregion

#pragma region "가로줄"
	{
		//가로줄 기둥 천장 1 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(5.4f, 4.1f, 11.8f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 50.f));
			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 천장 2 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(6.5f, 4.1f, -13.4f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 12.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 90.f, 0.f));
			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 천장 3 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(0.7f, 4.1f, -11.9f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 12.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 0.f, 0.f));
			
			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 천장 4 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(2.f, 4.1f, -18.2f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 12.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 90.f, 0.f));

			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 천장 5 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(-4.f, 4.1f, -17.f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 12.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 0.f, 0.f));

			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 천장 6 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(-3.2f, 4.1f, -22.8f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 12.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 90.f, 0.f));

			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 오른쪽 바닥7 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(-9.3f, -1.6f, -17.3f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 12.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 0.f, 0.f));

			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 오른쪽 바닥 8 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(-4.1f, -1.6f, -17.1f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 12.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 0.f, 0.f));

			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 오른쪽 바닥 8_1 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(3.48f, -3.9f, -18.2f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 25.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 90.f, 0.f));
			
			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 오른쪽 바닥 9 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(-3.2f, -1.6f, -18.3f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 12.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 90.f, 0.f));

			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 중간 바닥 10 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(-9.2f, -3.9f, 6.9f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 50.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 00.f, 0.f));

			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 중간 바닥 10_1 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(0.7f, -3.9f, 6.9f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 50.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 00.f, 0.f));
			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 중간 바닥 11 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(0.7f, -1.6f, 6.2f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 40.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 00.f, 0.f));

			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 위 바닥 12 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(-9.22f, -1.6f, 7.9f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 12.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 00.f, 0.f));

			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 위 바닥 13 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(3.48f, -1.6f, 1.8f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 25.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 90.f, 0.f));

			AddGameObject(pbannisterTop);
		}

		//가로줄 기둥 위 바닥 14 - bannisterTop
		{
			DecoObject* pbannisterTop = Factory::CreateObject<DecoObject>(Vec3(3.48f, -0.5f, 1.8f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\bannisterTop.fbx");
			pbannisterTop->GetTransform()->SetScale(Vec3(50.f, 50.f, 25.f));
			pbannisterTop->GetTransform()->SetRotation(Vec3(0.f, 90.f, 0.f));

			AddGameObject(pbannisterTop);
		}
	}
#pragma endregion

#pragma region "벽패널"
	{
		//벽패널
		{
			//벽 패널 1
			{
				DecoObject* pWallPanel = Factory::CreateObject<DecoObject>(Vec3(5.35f, -0.67f, 7.06f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\WallPanel.fbx");
				pWallPanel->GetTransform()->SetScale(Vec3(27.f, 27.f, 27.f));
				
				AddGameObject(pWallPanel);
			}

			//벽 패널 2
			{
				DecoObject* pWallPanel = Factory::CreateObject<DecoObject>(Vec3(5.35f, -0.67f, 10.96f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\WallPanel.fbx");
				pWallPanel->GetTransform()->SetScale(Vec3(27.f, 27.f, 27.f));
				
				AddGameObject(pWallPanel);
			}

			//벽 패널 3
			{
				DecoObject* pWallPanel = Factory::CreateObject<DecoObject>(Vec3(5.35f, -0.67f, 16.46f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\WallPanel.fbx");
				pWallPanel->GetTransform()->SetScale(Vec3(27.f, 27.f, 30.f));
				
				AddGameObject(pWallPanel);
			}

			//벽 패널 4
			{
				DecoObject* pWallPanel = Factory::CreateObject<DecoObject>(Vec3(5.35f, -0.67f, 3.39f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\WallPanel.fbx");
				pWallPanel->GetTransform()->SetScale(Vec3(27.f, 27.f, 33.f));
				
				AddGameObject(pWallPanel);
			}

			//벽 패널 5
			{
				DecoObject* pWallPanel = Factory::CreateObject<DecoObject>(Vec3(15.25f, -0.67f, -13.31f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\WallPanel.fbx");
				pWallPanel->GetTransform()->SetScale(Vec3(27.f, 27.f, 29.f));
				pWallPanel->GetTransform()->SetRotation(Vec3(0.f, 90.f, 0.f));
				
				AddGameObject(pWallPanel);
			}
		}
	}
#pragma endregion

	// 커튼 - CurtainHorizontal
	{
		DecoObject* pCurtainHorizontal = Factory::CreateObject<DecoObject>(Vec3(0.3f, 3.5f, 3.2f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\CurtainHorizontal.fbx");
		pCurtainHorizontal->GetTransform()->SetScale(Vec3(42.f, 42.f, 42.f));
		
		AddGameObject(pCurtainHorizontal);
	}

	//커튼 아랫줄 - CurtainVertical
	{
		DecoObject* pCurtainVertical = Factory::CreateObject<DecoObject>(Vec3(0.6f, -0.2f, 4.5f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\CurtainVertical.fbx");
		pCurtainVertical->GetTransform()->SetScale(Vec3(42.f, 42.f, 42.f));
		
		AddGameObject(pCurtainVertical);
	}

	// 커튼 2 - CurtainHorizontal
	{
		DecoObject* pCurtainHorizontal = Factory::CreateObject<DecoObject>(Vec3(17.2f, 3.5f, -17.7f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\CurtainHorizontal.fbx");
		pCurtainHorizontal->GetTransform()->SetScale(Vec3(42.f, 42.f, 42.f));
		pCurtainHorizontal->GetTransform()->SetRotation(Vec3(0.f, 90.f, 0.f));
		AddGameObject(pCurtainHorizontal);
	}

	//커튼 2 아랫줄 - CurtainVertical
	{
		DecoObject* pCurtainVertical = Factory::CreateObject<DecoObject>(Vec3(18.5f, -0.2f, -17.9f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\LeftSecretTrialMap\\CurtainVertical.fbx");
		pCurtainVertical->GetTransform()->SetScale(Vec3(42.f, 42.f, 42.f));
		pCurtainVertical->GetTransform()->SetRotation(Vec3(0.f, 90.f, 0.f));
		
		AddGameObject(pCurtainVertical);
	}

}

void LeftSecretTrialMap::Exit()
{
	GET_SINGLE(EventManager)->PushDeleteGameObjectsEvent(meSceneType, LayerType::Unknown);
	GET_SINGLE(EventManager)->PushDeleteGameObjectsEvent(meSceneType, LayerType::Ground);
	GET_SINGLE(EventManager)->PushDeleteGameObjectsEvent(meSceneType, LayerType::Monster);
	GET_SINGLE(EventManager)->PushDeleteGameObjectsEvent(meSceneType, LayerType::DecoObject);
	GET_SINGLE(EventManager)->PushDeleteGameObjectsEvent(meSceneType, LayerType::WallObject);
	GET_SINGLE(EventManager)->PushDeleteGameObjectsEvent(meSceneType, LayerType::Player);
}