#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <array>

#include "InputType.h"

class Keyboard
{
public:
    void update();
    void setKey(sf::Keyboard::Key key, bool keyDown);
    bool checkKeyAndState(sf::Keyboard::Key key, State state) const;

private:
    std::array<bool, sf::Keyboard::KeyCount> currState{};
    std::array<bool, sf::Keyboard::KeyCount> prevState{};
};