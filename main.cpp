#include <iostream>
#include <stdlib.h>
#include "Environments/World.h"
#include "Characters/Player.h"
#include "Characters/Enemy.h"

int main() {
    // initialize player and opponent
    srand(time(0));
    World world = World();
    world.RunGame();
}
