//
// Created by Robert Rochlin on 4/19/24.
//

#include "World.h"
#include "../Characters/Enemy.h"
#include "../Characters/Player.h"
#include <iomanip>
#include <random>

World::World() :
m_current_state(traversal), m_current_zone(ForestOfShadows) {
    // randomly generate
    std::unordered_map<CardinalDirections, std::vector<std::unique_ptr<Character>>> forestEnemies;
    std::vector<std::unique_ptr<Character>> southEnemies;

    // Use std::move to avoid copying unique_ptr
    southEnemies.push_back(std::make_unique<Enemy>());
    forestEnemies[south] = std::move(southEnemies);
    m_enemies[ForestOfShadows] = std::move(forestEnemies);

}

void World::RunGame() {
    Player player = Player();
    std::cout << "Welcome to the arena " << player.GetName() << std::endl;
    std::string input;

    auto* enemy = dynamic_cast<Enemy*>(m_enemies.at(m_current_zone).at(south)[0].get());

    SetState(combat);
    std::cout << "\nBegin Combat\n";
    while (player.IsAlive() && enemy->IsAlive())
    {
        std::cout << std::left << std::setw(20) << player.GetName() << std::right << std::setw(20) << enemy->GetName() << std::endl;
        std::cout << std::left << std::setw(20) << player.GetHealth() << std::right << std::setw(20) << enemy->GetHealth() << std::endl;
        std::cout << "\nChoose an Action\n";
        for (const auto& action : player.GetActions(m_current_state)) std::cout << action << " ";
        std::cout << std::endl;
        std::cin >> input;
        std::system("clear");
        player.Attack(*enemy);
        enemy->Attack(player);
    }
}