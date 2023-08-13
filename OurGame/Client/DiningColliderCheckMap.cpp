#include "pch.h"
#include "DiningColliderCheckMap.h"
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
#include "WallObject.h"

/* Component */
#include "Collider.h"
#include "RigidBody.h"
#include "MeshRenderer.h"
#include "Transform.h"
#include "Camera.h"
#include "Light.h"
#include "ParticleSystem.h"

/* Script */
#include "PlayerMoveScript.h"

/* Event */
#include "SceneChangeEvent.h"


namespace hm
{
	DiningColliderCheckMap::DiningColliderCheckMap()
		: Map(MapType::DiningColliderCheckMap)
	{
	}

	DiningColliderCheckMap::~DiningColliderCheckMap()
	{
	}

	void DiningColliderCheckMap::Initialize()
	{
		Map::Initialize();
	}

	void DiningColliderCheckMap::Update()
	{
		Map::Update();
	}

	void DiningColliderCheckMap::FixedUpdate()
	{
		Map::FixedUpdate();
	}

	void DiningColliderCheckMap::FinalUpdate()
	{
		Map::FinalUpdate();
	}

	void DiningColliderCheckMap::Render()
	{
		Map::Render();
	}

	void DiningColliderCheckMap::Enter()
	{
		GET_SINGLE(CollisionManager)->SetCollisionGroup(LayerType::Player, LayerType::Ground);
		GET_SINGLE(CollisionManager)->SetCollisionGroup(LayerType::Player, LayerType::WallObject);


		//���� �Ͼ������ ������ִ� �ڵ�
		gpEngine->SetSwapChainRTVClearColor(Vec4(255.f, 255.f, 255.f, 255.f));
		
		//DecoObject == �ݶ��̴� ���� ������Ʈ
		//WallObject == �ݶ��̴� �ִ� ������Ʈ

		//Forward == �� ����� ���� ���ɾ�
		//Deferred == �� ����� �ִ� ���ɾ�
		
		//->GetTransform()->SetPositionExcludingColliders == �ݶ��̴��� �����ϰ� ������Ʈ�� [�̵�] ��Ű�� �Լ�
		//->GetTransform()->SetRotationExcludingColliders == �ݶ��̴��� �����ϰ� ������Ʈ�� [ȸ��] ��Ű�� �Լ�
		


		// ��ü�� ���̵���� ��
		{
			DecoObject* pNormalBase = Factory::CreateObject<DecoObject>(Vec3(0.f, 0.f, 0.f), L"Forward", L"..\\Resources\\FBX\\Map\\Dungeon\\DiningColliderCheckMap\\Diningroom.fbx");

			pNormalBase->GetTransform()->SetScale(Vec3(50.f, 50.f, 50.f));

			AddGameObject(pNormalBase);
		}

		//�ܰ� �����ִ� ������ -wallPanel_Merged
		{
			DecoObject* pWallPanel_Merged = Factory::CreateObject<DecoObject>(Vec3(0.2f, -5.2f, 0.f), L"Forward", L"..\\Resources\\FBX\\Map\\Dungeon\\DiningColliderCheckMap\\wallPanel_Merged.fbx");

			pWallPanel_Merged->GetTransform()->SetScale(Vec3(50.f, 50.f, 50.f));

			AddGameObject(pWallPanel_Merged);
		}
		
		// ��ũ�� ��� ���� �� -POT_Door_4_Variant
		{
			PhysicsInfo info = {};
			info.eActorType = ActorType::Static;
			info.size = Vec3(4.f, 6.f, 0.4f);

			WallObject* pPOT_Door = Factory::CreateObjectHasPhysical<WallObject>(Vec3(8.75f, -6.0f, -6.0f), info, L"Forward", L"..\\Resources\\FBX\\Map\\Dungeon\\DiningColliderCheckMap\\POT_Door_4_Variant.fbx");
			pPOT_Door->GetTransform()->SetScale(Vec3(10.f, 10.f, 10.f));
			pPOT_Door->GetTransform()->SetPositionExcludingColliders(Vec3(0.f, 0.f, 4.7f));

			AddGameObject(pPOT_Door);
		}

		//������ -fireplace
		{
			DecoObject* pfireplace = Factory::CreateObject<DecoObject>(Vec3(-0.4f, -5.f, -1.2f), L"Forward", L"..\\Resources\\FBX\\Map\\Dungeon\\DiningColliderCheckMap\\fireplace.fbx");

			pfireplace->GetTransform()->SetScale(Vec3(10.f, 10.f, 10.f));
			

			AddGameObject(pfireplace);
		}


		
		// Toy
		{
			PhysicsInfo physicsInfo;
			physicsInfo.eActorType = ActorType::Dynamic;
			physicsInfo.eGeometryType = GeometryType::Box;
			physicsInfo.size = Vec3(2.f, 2.f, 2.f);

			Player* pPlayer = Factory::CreateObjectHasPhysical<Player>(Vec3(0.f, 0.f, 0.f), physicsInfo, L"Forward", L"..\\Resources\\FBX\\Player\\Crow2.fbx");
			pPlayer->AddComponent(new PlayerMoveScript);
			pPlayer->GetTransform()->SetScale(Vec3(3.f, 3.f, 3.f));

			AddGameObject(pPlayer);
		}






		// Wall
		/*for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 12; ++x)
			{
				DecoObject* pDecoObject = Factory::CreateObject<DecoObject>(Vec3(0.f, 0.f, 0.f), L"Deferred", L"..\\Resources\\FBX\\Map\\Dungeon\\GrandmaBossWall1.fbx");
				pDecoObject->GetRigidBody()->RemoveGravity();

				float radian = (225.f + (x * 16.f)) * XM_PI / 180.f;
				float radius = 13.f;

				pDecoObject->GetTransform()->SetScale(Vec3(10.f, 10.f, 10.f));
				pDecoObject->GetTransform()->SetRotation(Vec3(0.f, 50.f + x * 16.f, 0.f));

				pDecoObject->GetTransform()->SetPosition(
					Vec3(radius * cosf(radian) + radius * sinf(radian),
						-20.f + y * 10.f,
						(radius * cosf(radian) - radius * sinf(radian)) + 10.f));
				AddGameObject(pDecoObject);
			}
		}*/

		// Create Desk
		/*{
			PhysicsInfo info = {};
			info.eActorType = ActorType::Dynamic;
			info.size = Vec3(10.f, 3.f, 1.f);

			Player* pGameObject = Factory::CreateObjectHasPhysical<Player>(Vec3(0.f, 0.f, 0.f), info, L"Deferred", L"..\\Resources\\FBX\\Map\\Hall\\Desk.fbx");
			pGameObject->GetTransform()->SetScale(Vec3(10.f, 10.f, 10.f));
			pGameObject->GetTransform()->SetRotationExcludingColliders(Vec3(0.f, -45.f, 0.f));
			pGameObject->GetTransform()->SetPositionExcludingColliders(Vec3(0.f, 0.f, -1.f));

			AddGameObject(pGameObject);
			GET_SINGLE(PrefabManager)->AddPrefab(L"Test2", pGameObject);
		}*/
	}

	void DiningColliderCheckMap::Exit()
	{
	}
}