//
// Created by Robert Rochlin on 4/14/24.
//

#include "Character.h"

bool Character::TakeDamage(float damage) {
    m_health -= damage;
    if (m_health<=0) m_is_alive = false;
    return m_is_alive;
}


void Character::Attack(Character &opponent) {
    auto damage = ((Weapon*)m_equipped.at(ItemSlot::right_h))->damage;
    std::cout << m_name << " attacks for " << damage << std::endl;
    opponent.TakeDamage(damage);
}

bool Character::TryEquip(Item item) {

}

Character::Character() {
}

