#include "MyOctant.h"
using namespace Simplex;



/*Simplex::MyOctant::MyOctant()
{
}

*/
Simplex::MyOctant::MyOctant(uint a_nMaxLevel, uint a_nIdealEntityCount)
{
	m_uOctantCount = a_nMaxLevel;
	m_uIdealEntityCount = a_nIdealEntityCount;
	Init();
}
/*MyOctant::MyOctant()
{
}
*/

Simplex::MyOctant::MyOctant(vector3 a_v3Center, float a_fSize)
{
	m_v3Center = a_v3Center;
	m_v3Min = a_v3Center - (a_fSize / 2);
	m_v3Max = a_v3Center + (a_fSize / 2);
	m_uOctantCount++;
	Init();
}

Simplex::MyOctant::MyOctant(MyOctant const & other)
{
	//m_v3Center = other.GetCenterGlobal;
	//m_v3Min = other.GetMinGlobal;
	//m_v3Max = other.GetMaxGlobal;
}

MyOctant & Simplex::MyOctant::operator=(MyOctant const & other)
{
	//m_v3Center = other.GetCenterGlobal;
	//m_v3Min = other.GetMinGlobal;
	//m_v3Max = other.GetMaxGlobal;
	return *this;
}

MyOctant::~MyOctant()
{
}

void Simplex::MyOctant::Swap(MyOctant & other)
{
}

float Simplex::MyOctant::GetSize(void)
{
	return m_fSize;
}

vector3 Simplex::MyOctant::GetCenterGlobal(void)
{
	return vector3();
}

vector3 Simplex::MyOctant::GetMinGlobal(void)
{
	return vector3();
}

vector3 Simplex::MyOctant::GetMaxGlobal(void)
{
	return vector3();
}

bool Simplex::MyOctant::IsColliding(uint a_uRBIndex)
{
	return false;
}

void Simplex::MyOctant::Display(uint a_nIndex, vector3 a_v3Color)
{
}

void Simplex::MyOctant::Display(vector3 a_v3Color)
{
	m_pMeshMngr->AddWireCubeToRenderList(glm::translate(m_v3Center) * glm::scale(vector3(1.0f, 1.0f, 1.0f) * m_fSize), a_v3Color);
}

void Simplex::MyOctant::DisplayLeafs(vector3 a_v3Color)
{
}

void Simplex::MyOctant::ClearEntityList(void)
{
}

void Simplex::MyOctant::Subdivide(void)
{
	float tempCenterDistance = m_fSize / 4.0f;
	m_pChild[0] = new MyOctant(vector3(m_v3Center - tempCenterDistance), m_fSize / 2);
	m_pChild[1] = new MyOctant(vector3(m_v3Center.x + tempCenterDistance, m_v3Center.y - tempCenterDistance, m_v3Center.z - tempCenterDistance), m_fSize / 2);
	m_pChild[2] = new MyOctant(vector3(m_v3Center.x - tempCenterDistance, m_v3Center.y - tempCenterDistance, m_v3Center.z + tempCenterDistance), m_fSize / 2);
	m_pChild[3] = new MyOctant(vector3(m_v3Center.x + tempCenterDistance, m_v3Center.y - tempCenterDistance, m_v3Center.z + tempCenterDistance), m_fSize / 2);
	m_pChild[4] = new MyOctant(vector3(m_v3Center.x - tempCenterDistance, m_v3Center.y + tempCenterDistance, m_v3Center.z - tempCenterDistance), m_fSize / 2);
	m_pChild[5] = new MyOctant(vector3(m_v3Center.x + tempCenterDistance, m_v3Center.y + tempCenterDistance, m_v3Center.z - tempCenterDistance), m_fSize / 2);
	m_pChild[6] = new MyOctant(vector3(m_v3Center.x - tempCenterDistance, m_v3Center.y + tempCenterDistance, m_v3Center.z + tempCenterDistance), m_fSize / 2);
	m_pChild[7] = new MyOctant(vector3(m_v3Center + tempCenterDistance), m_fSize / 2);
}

MyOctant * Simplex::MyOctant::GetChild(uint a_nChild)
{
	return nullptr;
}

MyOctant * Simplex::MyOctant::GetParent(void)
{
	return nullptr;
}

bool Simplex::MyOctant::IsLeaf(void)
{
	if (m_uChildren = 0)
		return true;
	return false;
}

bool Simplex::MyOctant::ContainsMoreThan(uint a_nEntities)
{
	return false;
}

void Simplex::MyOctant::KillBranches(void)
{
}

void Simplex::MyOctant::ConstructTree(uint a_nMaxLevel)
{
}

void Simplex::MyOctant::AssignIDtoEntity(void)
{
}

uint Simplex::MyOctant::GetOctantCount(void)
{
	return m_uOctantCount;
}

void Simplex::MyOctant::Release(void)
{
}

void Simplex::MyOctant::Init(void)
{
	if(m_fSize == 0.0f)
		m_fSize = 68.0f;
	m_pEntityMngr = MyEntityManager::GetInstance();
}

void Simplex::MyOctant::ConstructList(void)
{
}
