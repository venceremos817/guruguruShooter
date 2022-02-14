#include "BulletManager.h"


BulletManager::BulletManager()
	: m_pBulletList(nullptr)
{

}


BulletManager::~BulletManager()
{

}


HRESULT BulletManager::Init()
{
	HRESULT hr;
	m_pBulletList = new List<Bullet>;

	hr = Bullet::Init();

	return hr;
}


void BulletManager::Uninit()
{
	Bullet::Uninit();
	m_pBulletList->ClearAll();
	delete m_pBulletList;
}


void BulletManager::Update()
{
	Node<Bullet>* pBullet = m_pBulletList->GetHead();
	List<Bullet> deleteList;

	while (pBullet!=nullptr)
	{
		pBullet->GetObj()->Update();
		if (pBullet->GetObj()->IsExist() == false)
			deleteList.AddObject(pBullet->GetObj());
		pBullet = pBullet->GetNext();
	}

	pBullet = deleteList.GetHead();
	while (pBullet != nullptr)
	{
		m_pBulletList->DestryoObj(pBullet->GetObj());
		pBullet = pBullet->GetNext();
	}
}


void BulletManager::Draw()
{
	Node<Bullet>* pBullet = m_pBulletList->GetHead();

	while (pBullet!=nullptr)
	{
		pBullet->GetObj()->Draw();
		pBullet = pBullet->GetNext();
	}
}


void BulletManager::CreateBullet(DirectX::XMFLOAT3 pos, float directionRad, float speed)
{
	Bullet* pBullet = m_pBulletList->CreateNewObj();
	pBullet->Create(pos, directionRad, speed);
}


List<Bullet>* BulletManager::GetList()
{
	return m_pBulletList;
}