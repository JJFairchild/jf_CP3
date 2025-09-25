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
#include <unordered_map>
using namespace std;

float findDmg(int attack_dmg, Pokemon self, Pokemon opp){ // Given that some Pokemon are more effective or resistant to others, this function calculates how much damage will be done based on the initial damage of the attack.
        if(self.type == "Fire"){
            if (opp.type == "Fire") return .5;
            if (opp.type == "Water") return .5;
            if (opp.type == "Grass") return 2;
            if (opp.type == "Electric") return 1;
            if (opp.type == "Dragon") return .5;

        } else if (self.type == "Water"){
            if (opp.type == "Fire") return 2;
            if (opp.type == "Water") return .5;
            if (opp.type == "Grass") return .5;
            if (opp.type == "Electric") return 1;
            if (opp.type == "Dragon") return .5;

        } else if (self.type == "Grass"){
            if (opp.type == "Fire") return .5;
            if (opp.type == "Water") return 2;
            if (opp.type == "Grass") return .5;
            if (opp.type == "Electric") return 1;
            if (opp.type == "Dragon") return .5;

        } else if (self.type == "Electric"){
            if (opp.type == "Fire") return 1;
            if (opp.type == "Water") return 2;
            if (opp.type == "Grass") return .5;
            if (opp.type == "Electric") return .5;
            if (opp.type == "Dragon") return .5;

        } else if (self.type == "Dragon"){
            if (opp.type == "Fire") return 1;
            if (opp.type == "Water") return 1;
            if (opp.type == "Grass") return 1;
            if (opp.type == "Electric") return 1;
            if (opp.type == "Dragon") return 2;
        }
    }

struct Pokemon{

    const string name;
    const string type;
    
    // base_x and x are separated here because all used stats end up being multiplied by level.
    const int base_max_hp;
    const int base_speed; // Though not required, I included this to make it easier to decide which pokemon attacks first in battle. That's all this is used for.
    const vector<pair<string, int>> base_attacks;
    const vector<pair<string, int>> base_heals;

    int max_hp;
    int speed;
    vector<pair<string, int>> attacks;
    vector<pair<string, int>> heals;

    int hp;
    int level;

    // Constructor to initialize all fields with the correct values.
    Pokemon(
        const string& name, 
        const string& type, 
        const int& base_max_hp, 
        const int& base_speed, 
        const vector<pair<string, int>>& base_attacks,
        const vector<pair<string, int>>& base_heals,
        int level = 1
        )
        : name(name), type(type), base_max_hp(base_max_hp), base_speed(base_speed), base_attacks(base_attacks), base_heals(base_heals), level(level)
    {
        max_hp = base_max_hp * (0.1 * (level - 1) + 1); // The level multiplier here is not used except for playtesting, since level is 1 when it is initialized.
        speed = base_speed * (0.1 * (level - 1) + 1);
        for(int i = 0; i < base_attacks.size(); i++){
            attacks.push_back({base_attacks[i].first, static_cast<int>(base_attacks[i].second * (0.1 * (level - 1) + 1))});
        }
        for(int i = 0; i < base_heals.size(); i++){
            heals.push_back({base_heals[i].first, static_cast<int>(base_heals[i].second * (0.1 * (level - 1) + 1))});
        }

        hp = max_hp;
    }

    void printInfo() const {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Level: " << level << endl;
        cout << "HP: " << hp << "/" << max_hp << endl;
        cout << "Speed: " << speed << endl;
        cout << "Attacks:" << endl;
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

unordered_map<string, Pokemon> pokedex = { // Unordered map (functions like a dict) of each Pokemon the user can find.
    {"Charizard", {"Charizard", "Fire", 78, 85, 
        {{"Flamethrower", 90}, {"Dragon Claw", 80}}, 
        {{"Roost", 0.5}}}},
        
    {"Arcanine", {"Arcanine", "Fire", 90, 80, 
        {{"Flare Blitz", 120}, {"Extreme Speed", 80}}, 
        {{"Morning Sun", 0.5}}}},
        
    {"Blastoise", {"Blastoise", "Water", 79, 60, 
        {{"Hydro Pump", 110}, {"Ice Beam", 90}}, 
        {{"Life Dew", 0.25f}}}},
        
    {"Milotic", {"Milotic", "Water", 95, 65, 
        {{"Surf", 90}, {"Dragon Pulse", 85}}, 
        {{"Recover", 0.5}}}},
        
    {"Venusaur", {"Venusaur", "Grass", 80, 60, 
        {{"Solar Beam", 120}, {"Sludge Bomb", 90}}, 
        {{"Synthesis", 0.5}}}},
        
    {"Roserade", {"Roserade", "Grass", 60, 90, 
        {{"Energy Ball", 90}, {"Toxic Spikes", 0}}, 
        {{"Synthesis", 0.5}}}},
        
    {"Jolteon", {"Jolteon", "Electric", 65, 130, 
        {{"Thunderbolt", 90}, {"Shadow Ball", 80}}, 
        {{"Wish", 0.5}}}},
        
    {"Luxray", {"Luxray", "Electric", 80, 70, 
        {{"Wild Charge", 90}, {"Crunch", 80}}, 
        {{"Life Dew", 0.25f}}}},
        
    {"Dragonite", {"Dragonite", "Dragon", 91, 80, 
        {{"Outrage", 120}, {"Hurricane", 110}}, 
        {{"Roost", 0.5}}}},
        
    {"Haxorus", {"Haxorus", "Dragon", 76, 97, 
        {{"Dragon Claw", 80}, {"Earthquake", 100}}, 
        {{"Life Dew", 0.25f}}}}
};

int main() {

}


/*
Type Interaction	    Damage Multiplier	Meaning
✅ Strong Against	   2×	               Super effective – deal double damage
🚫 Weak Against	        0.5×	            Not very effective – deal half damage
🛡️ Resists	             0.5×	             Take half damage from this type
🔻 Vulnerable To	    2×	                Take double damage from this type
❌ Neutral	           1×	               No change in damage
*/