#ifndef COMBATSIM_WORLD_H
#define COMBATSIM_WORLD_H

#include <unordered_map>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include "../Characters/Character.h"
#include "../Items/Items.h"

class Character;

class World {
public:
    enum GameState { combat, traversal, management, last_state };
    enum GameZones { ForestOfShadows, MysticRuins, FrozenTundra, DesertWastes, VolcanicFields, last_zone };
    enum CardinalDirections { north, south, east, west, last_dir};

    World();

    std::vector<std::unique_ptr<Character>>& GetNearEnemies(GameZones zone, CardinalDirections direction) {
        return m_enemies.at(zone).at(direction);
    }

    std::unordered_map<CardinalDirections, std::vector<std::unique_ptr<Character>>>& GetZoneEnemies(GameZones zone) {
        return m_enemies.at(zone);
    }

    std::vector<std::unique_ptr<Item>>& GetNearItems(GameZones zone, CardinalDirections direction) {
        return m_items.at(zone).at(direction);
    }

    std::unordered_map<CardinalDirections, std::vector<std::unique_ptr<Item>>>& GetZoneItems(GameZones zone) {
        return m_items.at(zone);
    }

    void SetZone(GameZones zone) {
        m_current_zone = zone;
    }
    void SetState(GameState state) {
        m_current_state = state;
    }

    void RunGame();

    // Helper functions to convert enums to string
    static std::string GameStateToString(GameState state) {
        switch (state) {
            case combat: return "Combat";
            case traversal: return "Traversal";
            case management: return "Management";
            default: return "Unknown State";
        }
    }

    static std::string GameZoneToString(GameZones zone) {
        switch (zone) {
            case ForestOfShadows: return "Forest of Shadows";
            case MysticRuins: return "Mystic Ruins";
            case FrozenTundra: return "Frozen Tundra";
            case DesertWastes: return "Desert Wastes";
            case VolcanicFields: return "Volcanic Fields";
            default: return "Unknown Zone";
        }
    }

private:
    std::unordered_map<GameZones, std::unordered_map<CardinalDirections, std::vector<std::unique_ptr<Character>>>> m_enemies;
    std::unordered_map<GameZones, std::unordered_map<CardinalDirections, std::vector<std::unique_ptr<Item>>>> m_items;
    GameZones m_current_zone;
    GameState m_current_state;
};

#endif //COMBATSIM_WORLD_H
