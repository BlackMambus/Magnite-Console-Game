#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
class Character {
public:
    string name;
    int attack;  
    int health;  
    int defense; 

    Character(string n, int h, int a, int d) : name(n), health(h), attack(a), defense(d) {}

    void takeDamage(int damage) {
        health -= (damage - defense);
        if (health < 0) health = 0;
    }

    bool isAlive() {
        return health > 0;
    }
};

void printStats(Character& character) {
    cout << "Name: " << character.name << endl;
    cout << "Health: " << character.health << endl;
    cout << "Attack: " << character.attack << endl;
    cout << "Defense: " << character.defense << endl;
}

void playerAttack(Character& player, Character& monster) {
    int damage = player.attack + (rand() % 5);  // Randomized attack within a range
    cout << player.name << " attacks " << monster.name << " for " << damage << " damage!" << endl;
    monster.takeDamage(damage);
}

void monsterAttack(Character& player, Character& monster) {
    int damage = monster.attack + (rand() % 5);  // Randomized attack
    cout << monster.name << " attacks " << player.name << " for " << damage << " damage!" << endl;
    player.takeDamage(damage);
}

int main() {
    srand(time(0));  // Initialize random seed

    // Create player and monster
    string playerName;
    cout << "Enter your character's name: ";
    cin >> playerName;
    Character player(playerName, 100, 15, 5);

    Character monster("Goblin", 50, 10, 3);

    cout << "\nA wild " << monster.name << " appears!" << endl;
    
    while (player.isAlive() && monster.isAlive()) {
        cout << "\n--- Battle ---" << endl;
        printStats(player);
        printStats(monster);

        // Player's turn
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Attack\n2. Run\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            playerAttack(player, monster);
        } else if (choice == 2) {
            cout << player.name << " tries to run away!" << endl;
            if (rand() % 2 == 0) {
                cout << "You successfully escaped!" << endl;
                break;
            } else {
                cout << "You couldn't escape!" << endl;
            }
        }

        // Monster's turn
        if (monster.isAlive()) {
            monsterAttack(player, monster);
        }
    }

    // End of battle
    if (player.isAlive()) {
        cout << "\nYou defeated the " << monster.name << "!" << endl;
    } else {
        cout << "\nYou were defeated by the " << monster.name << "!" << endl;
    }

    return 0;
}



