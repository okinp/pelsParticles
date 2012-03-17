#pragma once
#include "cinder/Vector.h"
class ParticleBase
{
public:
    ParticleBase(void);
    ParticleBase( ci::Vec2f& pos, ci::Vec2f& acc );
    virtual ~ParticleBase(void);
    virtual void setArrayIndex( const int &idx );
    virtual void setPositionArrayReference( float* const posVbo );
    //virtual void setColorArrayReference(  );
    virtual void startMoving();
    virtual void update();
    ci::Vec2f& getPos();
    virtual void addAcceleration(const ci::Vec2f &accel );
    virtual void resetParticle( ci::Vec2f &pos, ci::Vec2f &acc );
    bool m_hasStarted;
private:
    void setPositionArrayAtParticleIndex( int &pIdx, const ci::Vec2f &pos);
    ci::Vec2f m_Pos;
    ci::Vec2f m_Vel;
    ci::Vec2f m_Acc;
    
    int m_ArrayIndex;
    float *m_positionsVBO;
    
};

