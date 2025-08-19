#pragma once
#include "HitShape.h"
#include "ObjCommon.h"
#include "Collision.h"
#include <vector>
#include <utility>

class HitChecker {
private:
    struct Entry {
        ObjCommon* object;
        HitShape* shape;
    };
    std::vector<Entry> m_Entries;

public:
    void Register(ObjCommon* obj, HitShape* shape);
    void Unregister(ObjCommon* obj);

    // 衝突判定。ヒットしているオブジェクトペアを返す
    std::vector<std::pair<ObjCommon*, ObjCommon*>> CheckHits();
};
