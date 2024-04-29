//
// Created by Robert Rochlin on 4/15/24.
//

#ifndef COMBATSIM_ENEMY_H
#define COMBATSIM_ENEMY_H

#include "Character.h"

class Enemy : public Character {
public:
    Enemy() : Character() {
        m_name = "Enemy";
        m_health = 30;
        m_equipped = std::unordered_map<ItemSlot, Item*> {{ ItemSlot::right_h, new ShortSword()}};
    }
};


#endif //COMBATSIM_ENEMY_H
