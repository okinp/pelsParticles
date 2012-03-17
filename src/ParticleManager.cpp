#include "ParticleManager.h"


ParticleManager::ParticleManager(void)
   :m_TotalParticles( NUM_PARTICLES*( NUM_SUB_PARTICLES + 1) ),
    m_EmissionRate(20),
    m_EmitterPos( ci::Vec2f::zero() ),
    m_EmitterAcc( ci::Vec2f(2.f, 2.f) )
{

}

ParticleManager::~ParticleManager(void)
{

}

void ParticleManager::setup()
{
    initializeData();
    initializeVbos();
}

void ParticleManager::update()
{
    for ( m_Iter = m_Particles.begin(); m_Iter!= m_Particles.end(); ++m_Iter )
    {
        if ( m_Iter->isOutside() )
        {
            m_Iter->resetParticle( m_EmitterPos, m_EmitterAcc );
        }
        (*m_Iter).update();
    }                  
}

void ParticleManager::draw()
{

    glEnable(GL_TEXTURE_2D);
    //Texture
    glEnableClientState(GL_TEXTURE_COORD_ARRAY); 
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, m_ParticleVboIds[0]); 
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, (m_TotalParticles*4)*2*sizeof(float), mVboTextureCoords, GL_STATIC_DRAW_ARB);
    glTexCoordPointer(2, GL_FLOAT, 0, 0); // Tell OpenGL that we have 2 coordinates and the coordinates in the array are floats
    //Color
    glEnableClientState(GL_COLOR_ARRAY);
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, m_ParticleVboIds[1]);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, (m_TotalParticles*4)*4*sizeof(float), mVboColors, GL_DYNAMIC_DRAW_ARB);	// Copy data into VBO 0: 
    glColorPointer(4, GL_FLOAT, 0, 0);
    //Positions ( quads ) 
    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, m_ParticleVboIds[2]);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, (m_TotalParticles*4)*2*sizeof(float), mVboPositions, GL_STREAM_DRAW_ARB);
    glVertexPointer(2, GL_FLOAT, 0, 0); 
    // Tell OpenGL that we have 3 coordinates (x, y, z) and the coordinates are stored as floats in the array

    // Draw
    //glDisable(GL_DEPTH_TEST);
    //ofEnableArbTex();	

    //ofEnableAlphaBlending();

    //texture.getTextureReference().bind();

    glDrawArrays(GL_QUADS, 0, m_TotalParticles*4);

    //texture.getTextureReference().unbind();

    //ofDisableAlphaBlending();

    //ofDisableArbTex();

    //glEnable(GL_DEPTH_TEST);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D);
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
}

void ParticleManager::initializeData()
{
    for ( int idxA = 0; idxA < NUM_PARTICLES; ++idxA )
    {
        Particle p( 0, m_EmitterPos, m_EmitterAcc );
        int pIndex = idxA*(NUM_SUB_PARTICLES + 1 );
        p.setArrayIndex( pIndex );
        //p.setAddress( );
        m_Particles.push_back( p );
        int halfWidth = 20;
        int particleIndex =  idxA*( NUM_SUB_PARTICLES + 1 );

        for ( int idxB = 0; idxB < NUM_SUB_PARTICLES; ++idxB )
        {
            SubParticle subP( m_EmitterPos, m_EmitterAcc );
            int pSubIndex = pIndex +  
            subP.setArrayIndex( );
        }

//         mVboPositions[(NUM_SUB_PARTICLES+1)*idx*4 + 0] = 0.f;
//         mVboPositions[idx*2 + 1] = 0.f;
    }
}

void ParticleManager::initializeVbos()
{
    m_TotalParticles = NUM_PARTICLES*NUM_SUB_PARTICLES;
    // Setup 3 vertex buffer objects ( texture, color, pos )
    glGenBuffersARB(3, &m_ParticleVboIds[0]);
    // Texture
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, m_ParticleVboIds[0]);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, (m_TotalParticles*4)*2*sizeof(float), mVboTextureCoords, GL_STATIC_DRAW_ARB);
    // Color
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, m_ParticleVboIds[1]);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, (m_TotalParticles*4)*4*sizeof(float), mVboColors, GL_DYNAMIC_DRAW_ARB);	// Copy data into VBO 0: 
    // Position
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, m_ParticleVboIds[2]);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, (m_TotalParticles*4)*3*sizeof(float), mVboPositions, GL_STREAM_DRAW_ARB);
}

void ParticleManager::addAffector( ci::Vec2f pos, float minRadius, float maxRadius, float mass, bool isRepeller )
{
    m_Affectors.push_back( Affector( ) );
}