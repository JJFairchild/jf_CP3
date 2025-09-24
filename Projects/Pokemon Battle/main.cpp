// Jonas Fairchild, Pokemon Battle

/*
Write a program that creates a Pokémon battle game using structures for Pokémon and enumeration for the menu in C++. The game should allow users to explore (find Pokémon), battle, heal Pokémon, and exit the game. Implement structures for Pokémon that include names, max HP, attacks, and level. Use enumeration for the main menu options.

The game must include the following features:
- A main menu with options to explore, battle, heal, and exit.
- Exploration feature to find and catch Pokémon.
- Battle system where users can fight against wild Pokémon or other trainers.
- Healing option to restore Pokémon HP.
- Multiple attack options for each Pokémon during battles.
- Different Pokémon types with associated weaknesses and strengths.
- Type-based damage bonuses during battles.

OUTPUT EXAMPLE:
    Pokémon Battle Game Menu:
    1: Explore
    2: Battle
    3: Heal Pokémon
    4: Exit
    Enter your choice (1-4): 1
    You found a wild Pikachu! Do you want to catch it? (Y/N): Y
    Pikachu has been added to your team!

KEY REMINDERS:
- Use structures to define Pokémon with properties like name, max HP, current HP, attacks, level, and type.
- Implement enumeration for the main menu options.
- Create multiple attack options for each Pokémon.
- Implement a type system with weaknesses and strengths (e.g., Water is strong against Fire).
- Use appropriate variable types and error handling.
- Ensure the game continues running until the user chooses to exit.
- Implement proper input validation and error handling.

BONUS (Rubber Duck Prize):
- To earn a rubber duck prize, include multiple attack options that users can select during battle, and implement a comprehensive type system with proper weaknesses and strengths that provide damage bonuses.

CLARIFICATIONS:
- You should have 5 different Pokemon types.
- Each type needs at least 1-2 Pokemon in it. 
- Pokemon should have at least 3 attacks to choose from.

HOW TO SUBMIT:
- Submit the link to your project on Github
*/

#include <iostream>
#include <vector>
using namespace std;

struct Pokemon{

    const string name;
    const string type;
    
    // base_x and x are separated here because all used stats end up being multiplied by level.
    const int base_max_hp;
    const int base_speed; // Though not required, I included this to make it easier to decide which pokemon attacks first in battle. That's all this is used for.
    const vector<pair<string, int>> base_attacks;

    int max_hp;
    int speed;
    vector<pair<string, int>> attacks;

    int hp;
    int level;

    // Constructor to initialize all fields with the correct values.
    Pokemon(
        const string& name, 
        const string& type, 
        const int& base_max_hp, 
        const int& base_speed, 
        const vector<pair<string, int>>& base_attacks,
        int level = 1
        )
        : name(name), type(type), base_max_hp(base_max_hp), base_speed(base_speed), base_attacks(attacks), level(level)
    {
        max_hp = base_max_hp * (0.1 * (level - 1) + 1); // The level multiplier here is not used except for playtesting, since level is 1 when it is initialized.
        speed = base_speed * (0.1 * (level - 1) + 1);
        for(int i = 0; i < base_attacks.size(); i++){
            attacks.push_back({base_attacks[i].first, static_cast<int>(base_attacks[i].second * (0.1 * (level - 1) + 1))});
        }

        hp = max_hp;
    }

    void printInfo() const {
        cout << "Name: " << name << '\n';
        cout << "Type: " << type << '\n';
        cout << "Level: " << level << '\n';
        cout << "HP: " << hp << "/" << max_hp << '\n';
        cout << "Speed: " << speed << '\n';
        cout << "Attacks:\n";
        for (const auto& attack : attacks) {
            cout << " - " << attack.first << " (Damage: " << attack.second << ")\n";
        }
    }

    int battle(Pokemon opp){ // Opp being short for opponent

        while (hp != 0 && opp.hp != 0){

        }

        hp = base_max_hp;
        return 0;
    }
};

int main() {
    Pokemon lol = {
        "Pikachu",
        "Electric",
        144,
        144,
        {{"Thunder Shock", 40}, {"Quick Attack", 30}, {"Electro Ball", 50}},
        5
    };

    lol.printInfo();  // <-- This is inside main() and works fine

    return 0;
}
/*
🔥 Fire Type
1. Charizard

HP: 78

Speed: 85

Attacks:

Flamethrower – 90 damage

Dragon Claw – 80 damage

Heal:

Roost – Restores 50% of max HP

2. Arcanine

HP: 90

Speed: 80

Attacks:

Flare Blitz – 120 damage (with recoil)

Extreme Speed – 80 damage, always goes first

Heal:

Morning Sun – Heals 50% of max HP

🌊 Water Type
3. Blastoise

HP: 79

Speed: 60

Attacks:

Hydro Pump – 110 damage

Ice Beam – 90 damage

Heal:

Life Dew – Heals 25% of max HP instantly

4. Milotic

HP: 95

Speed: 65

Attacks:

Surf – 90 damage

Dragon Pulse – 85 damage

Heal:

Recover – Heals 50% of max HP

🌿 Grass Type
5. Venusaur

HP: 80

Speed: 60

Attacks:

Solar Beam – 120 damage (can be charged or instant in sun)

Sludge Bomb – 90 damage

Heal:

Synthesis – Heals 50% of max HP

6. Roserade

HP: 60

Speed: 90

Attacks:

Energy Ball – 90 damage

Toxic Spikes – (Non-damaging; sets poison hazard)

Heal:

Synthesis – Heals 50% of max HP

⚡ Electric Type
7. Jolteon

HP: 65

Speed: 130 ⚡ (Extremely fast — highest in list)

Attacks:

Thunderbolt – 90 damage

Shadow Ball – 80 damage

Heal:

Wish – Heals 50% of max HP on next turn (not gradual)

8. Luxray

HP: 80

Speed: 70

Attacks:

Wild Charge – 90 damage (with recoil)

Crunch – 80 damage

Heal:

Life Dew – Heals 25% of max HP instantly

🐉 Dragon Type
9. Dragonite

HP: 91

Speed: 80

Attacks:

Outrage – 120 damage

Hurricane – 110 damage

Heal:

Roost – Heals 50% of max HP

10. Haxorus

HP: 76

Speed: 97

Attacks:

Dragon Claw – 80 damage

Earthquake – 100 damage

Heal:

Life Dew – Heals 25% of max HP instantly
*/

/*
Type Interaction	Damage Multiplier	Meaning
✅ Strong Against	2×	Super effective – deal double damage
🚫 Weak Against	0.5×	Not very effective – deal half damage
🛡️ Resists	0.5×	Take half damage from this type
🔻 Vulnerable To	2×	Take double damage from this type
❌ Neutral	1×	No change in damage
*/