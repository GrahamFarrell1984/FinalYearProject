#include "Keyboard.h"

void Keyboard::update()
{
    prevState = currState;
}

void Keyboard::setKey(const sf::Keyboard::Key key, const bool keyDown)
{
    currState[key] = keyDown;
}

bool Keyboard::checkKeyAndState(const sf::Keyboard::Key key, const State state) const
{
    State currentState = State::NONE;
    if (prevState[key]) {
        currentState = !currState[key] ? State::RELEASE : State::HOLD;
    } else if (currState[key]) {
        currentState = State::PRESS;
    }
    return currentState == state;
}
