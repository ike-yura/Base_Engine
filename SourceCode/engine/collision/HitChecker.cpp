#include "HitChecker.h"
#include <algorithm>
#include <DirectXMath.h>
#include "Helper.h"
using namespace DirectX;

void HitChecker::Register(ObjCommon* obj, HitShape* shape) {
    m_Entries.push_back({ obj, shape });
}

void HitChecker::Unregister(ObjCommon* obj) {
    auto it = std::remove_if(m_Entries.begin(), m_Entries.end(),
        [obj](const Entry& e) { return e.object == obj; });
    m_Entries.erase(it, m_Entries.end());
}

//当たり判定のチェック
std::vector<std::pair<ObjCommon*, ObjCommon*>> HitChecker::CheckHits() {
    std::vector<std::pair<ObjCommon*, ObjCommon*>> hits;

    for (size_t i = 0; i < m_Entries.size(); ++i) {
        for (size_t j = i + 1; j < m_Entries.size(); ++j) {
            ObjCommon* aObj = m_Entries[i].object;
            ObjCommon* bObj = m_Entries[j].object;
            HitShape* aShape = m_Entries[i].shape;
            HitShape* bShape = m_Entries[j].shape;

            bool hit = false;

            // Sphere-Sphere
            if (aShape->GetType() == HitShape::Type::Sphere &&
                bShape->GetType() == HitShape::Type::Sphere) {
                hit = Collision::SphereCollision(
                    aObj->GetPosition(), aObj->GetColScale().x,
                    bObj->GetPosition(), bObj->GetColScale().x);
            }
            // Sphere-AABB
            else if ((aShape->GetType() == HitShape::Type::Sphere && bShape->GetType() == HitShape::Type::AABB) ||
                (aShape->GetType() == HitShape::Type::AABB && bShape->GetType() == HitShape::Type::Sphere)) {

                ObjCommon* sphereObj = (aShape->GetType() == HitShape::Type::Sphere) ? aObj : bObj;
                ObjCommon* aabbObj = (aShape->GetType() == HitShape::Type::AABB) ? aObj : bObj;

                XMFLOAT3 aabbMin = Helper::GetInstance()->GetAABBMin(aabbObj->GetPosition(), aabbObj->GetColScale());
                XMFLOAT3 aabbMax = Helper::GetInstance()->GetAABBMax(aabbObj->GetPosition(), aabbObj->GetColScale());

                hit = Collision::SphereAABBCollision(
                    sphereObj->GetPosition(), sphereObj->GetColScale().x,
                    aabbMin, aabbMax);
            }
            // AABB-AABB
            else if (aShape->GetType() == HitShape::Type::AABB &&
                bShape->GetType() == HitShape::Type::AABB) {

                XMFLOAT3 aMin = Helper::GetInstance()->GetAABBMin(aObj->GetPosition(), aObj->GetColScale());
                XMFLOAT3 aMax = Helper::GetInstance()->GetAABBMax(aObj->GetPosition(), aObj->GetColScale());

                XMFLOAT3 bMin = Helper::GetInstance()->GetAABBMin(bObj->GetPosition(), bObj->GetColScale());
                XMFLOAT3 bMax = Helper::GetInstance()->GetAABBMax(bObj->GetPosition(), bObj->GetColScale());

                hit = Collision::AABBCollision(aMin, aMax, bMin, bMax);
            }

            if (hit) {
                hits.push_back({ aObj, bObj });
            }
        }
    }

    return hits;
}

