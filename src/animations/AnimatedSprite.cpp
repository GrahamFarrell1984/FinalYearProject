#include "AnimatedSprite.h"
#include "EntityData.h"

AnimatedSprite::AnimatedSprite(sf::Vector2f pos,
                               const sf::Texture* texture,
                               const FrameData& frameData,
                               const AnimData& animData)
        : m_finishedPlaying{ false }
        , m_tick{ 0 }
        , m_frameIndex{ 0 }
        , m_frame{}
        , m_animFrame{}
        , m_state{ Anim::State::NONE }
        , m_sprite{}
        , m_frameData{ frameData }
        , m_animData{ animData }
{
    m_sprite.setPosition(pos);
    m_sprite.setTexture(*texture);
}

void AnimatedSprite::changeState(const Anim::State state, bool resetCurrentData)
{
    if (state != m_state) {
        if (auto animState = m_animData.find(state); animState != m_animData.end()) {
            if (resetCurrentData) {
                m_finishedPlaying = false;
                m_tick            = 0;
                m_frameIndex      = 0;
                m_animFrame       = animState->second.frames[m_frameIndex];
                m_frame           = m_frameData[m_animFrame.index];
            }
            m_state = state;
        }
    }
}

void AnimatedSprite::updatePosition(sf::Vector2f pos)
{
    m_sprite.setPosition(pos);
}

void AnimatedSprite::checkForFrameUpdate()
{
    ++m_tick;
    if (auto animState = m_animData.find(m_state); animState != m_animData.end()) {
        const uint8_t tick = animState->second.frames[m_frameIndex].tick;
        if (tick != 0 && m_tick >= tick) {  // No need to check animation.
            ++m_frameIndex;
            if (m_frameIndex >= animState->second.frames.size()) {
                if (animState->second.looping) {
                    m_frameIndex = animState->second.loopFrameIndex;
                } else {
                    m_finishedPlaying = true;
                    return;
                }
            }
            m_animFrame = animState->second.frames[m_frameIndex];
            m_frame     = m_frameData[m_animFrame.index];
            m_tick      = 0;
        }
    }
}

bool AnimatedSprite::isAnimFinishedPlaying() const
{
    return m_finishedPlaying;
}

void AnimatedSprite::render(sf::RenderWindow& window)
{
    if (!m_finishedPlaying) {
        m_sprite.move(m_animFrame.origin.x, m_animFrame.origin.y);
        m_sprite.setTextureRect(sf::IntRect(m_frame.src.x, m_frame.src.y, m_frame.src.w, m_frame.src.h));
        window.draw(m_sprite);
    }
}
Rect AnimatedSprite::getBounds() const
{
    return Rect{ static_cast<sf::Int32>(m_sprite.getPosition().x + m_animFrame.origin.x),
                 static_cast<sf::Int32>(m_sprite.getPosition().y + m_animFrame.origin.y),
                 static_cast<sf::Int32>(m_frame.src.w),
                 static_cast<sf::Int32>(m_frame.src.h) };
}
