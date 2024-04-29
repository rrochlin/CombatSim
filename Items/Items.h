//
// Created by Robert Rochlin on 4/14/24.
//

#ifndef COMBATSIM_ITEMS_H
#define COMBATSIM_ITEMS_H

#include <vector>

// Base class Item
class Item {
public:
    std::string name;
    std::string description;
    float weight;  // Weight attribute as requested
    bool can_equip;

    Item(std::string n, std::string desc, float wt, bool c_e) : name(n), description(desc), weight(wt), can_equip(c_e) {}

    virtual void display() const {
        std::cout << "Name: " << name << ", Description: " << description << ", Weight: " << weight << " kg" << std::endl;
    }

    virtual ~Item() {}
};

enum class ItemSlot {
    hand, neck, chest, head, hands, legs, feet, finger, right_h, left_h, back, ear
};
static std::string ItemSlotToString(ItemSlot item) {
    switch (item) {
        case ItemSlot::head: return "Head";
        case ItemSlot::neck: return "Neck";
        case ItemSlot::chest: return "Chest";
        case ItemSlot::legs: return "Legs";
        case ItemSlot::hand: return "Hand";
        case ItemSlot::feet: return "Feet";
        case ItemSlot::right_h: return "Right Hand";
        case ItemSlot::left_h: return "Left Hand";
        case ItemSlot::hands: return "Hands";
        case ItemSlot::finger: return "Finger";
        case ItemSlot::back: return "Back";
        case ItemSlot::ear: return "ear";
        default: return "Unknown";
    }
}

// Base class for Weapon
class Weapon : public Item {
public:
    float damage;
    float range;
    float speed;

    Weapon(std::string n, std::string desc, float dmg, float rng, float spd, float wt)
            : Item(n, desc, wt, true), damage(dmg), range(rng), speed(spd) {}

    void display() const override {
        Item::display();
        std::cout << "Damage: " << damage << ", Range: " << range << ", Speed: " << speed << std::endl;
    }
};

// Derived classes for each specific weapon
class ShortSword : public Weapon {
public:
    ShortSword() : Weapon("ShortSword", "A shorter, more maneuverable sword", 10, 1, 1.2, 3) {}
};

class Dagger : public Weapon {
public:
    Dagger() : Weapon("Dagger", "A small, quick stabbing weapon", 5, 0.75, 1, 1) {}
};

class Bow : public Weapon {
public:
    Bow() : Weapon("Bow", "A flexible ranged weapon using arrows", 7, 20, 4, 2.5) {}
};

class Crossbow : public Weapon {
public:
    Crossbow() : Weapon("Crossbow", "A mechanical bow that fires bolts", 8, 100, 15, 4) {}
};

class Longbow : public Weapon {
public:
    Longbow() : Weapon("Longbow", "A tall bow with a powerful range", 9, 40, 5, 3) {}
};

class Claymore : public Weapon {
public:
    Claymore() : Weapon("Claymore", "A large, heavy two-handed sword", 10, 2, 2, 5) {}
};


#endif //COMBATSIM_ITEMS_H
