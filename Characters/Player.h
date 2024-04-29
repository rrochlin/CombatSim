//
// Created by Robert Rochlin on 4/15/24.
//

#ifndef COMBATSIM_PLAYER_H
#define COMBATSIM_PLAYER_H

#include "Character.h"
#include <random>
#include <time.h>

class Player : public Character {
public:
    Player() : Character() {
        m_name = "Player";
        m_health = 100;
        m_equipped = std::unordered_map<ItemSlot, Item*> {{ ItemSlot::right_h, new ShortSword()}};
    }
    std::vector<std::string> GetActions(World::GameState state) { return m_actions.at(state); }
private:
    std::unordered_map<World::GameState, std::vector<std::string>> m_actions = std::unordered_map<World::GameState, std::vector<std::string>> {
            {World::GameState::combat, std::vector<std::string> {{"attack", "move", "jump"}} },
            {World::GameState::traversal, std::vector<std::string> {{"move", "jump", "climb", "swim"}} },
            {World::GameState::management, std::vector<std::string> {{"inventory", "equip", "unequip", "equipped", "rest"}} }
    };;
};


#endif //COMBATSIM_PLAYER_H
