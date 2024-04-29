//
// Created by Robert Rochlin on 4/14/24.
//

#ifndef COMBATSIM_CHARACTER_H
#define COMBATSIM_CHARACTER_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include "../Items/Items.h"
#include "../Environments/World.h"

class Character {
public:
    Character();
    float GetHealth() const { return m_health; }
    bool TakeDamage(float damage);
    [[nodiscard]] bool IsAlive() const { return m_is_alive; }
    void Attack(Character &opponent);
    void SetName(std::string name) { m_name = std::move(name); }
    std::string GetName() {return m_name; }
    std::vector<Item*> GetInventory() { return m_inventory; }
    std::unordered_map<ItemSlot, Item*> GetEquipped() { return  m_equipped; }
    bool TryEquip(Item item);
    bool TryUnequip(Item item);
    virtual ~Character() {}

protected:
    float m_health;
    bool m_is_alive = true;
    std::string m_name;
    std::vector<Item*> m_inventory;
    std::unordered_map<ItemSlot, Item*> m_equipped;
};

#endif //COMBATSIM_CHARACTER_H
