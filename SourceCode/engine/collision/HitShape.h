#pragma once

class HitShape {
public:
    enum class Type
    { 
      Sphere, 
      AABB 
    };

private:
    Type m_Type;

public:
    HitShape(Type type = Type::Sphere) : m_Type(type) {}
    Type GetType() const { return m_Type; }
    void SetType(Type type) { m_Type = type; }
};
