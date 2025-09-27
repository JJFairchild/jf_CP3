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
#include <ctime>
#include <cstdlib>
#include <limits>
#include <string>
using namespace std;

enum MainMenu{
    Explore = 1,
    ViewInventory,
    Battle,
    Exit
};

enum class Type {
    Fire,
    Water,
    Grass,
    Electric,
    Dragon
};

ostream& operator<<(ostream& os, const Type& t) { // Used when displaying what type a Pokemon is
    switch(t) {
        case Type::Fire: os << "Fire"; break;
        case Type::Water: os << "Water"; break;
        case Type::Grass: os << "Grass"; break;
        case Type::Electric: os << "Electric"; break;
        case Type::Dragon: os << "Dragon"; break;
    }
    return os;
}

struct Pokemon{

    string name;
    Type type;
    
    // base_x and x are separated here because all used stats end up being multiplied by level.
    int base_max_hp;
    int base_speed; // Though not required, I included this to make it easier to decide which pokemon attacks first in battle. That's all this is used for.
    vector<pair<string, int>> base_attacks;
    vector<pair<string, double>> base_heals;

    int max_hp;
    int speed;
    vector<pair<string, int>> attacks;
    vector<pair<string, double>> heals;

    double hp;
    int level;

    // Constructor to initialize all fields with the correct values.
    Pokemon(
        const string& name, 
        const Type& type, 
        const int& base_max_hp, 
        const int& base_speed, 
        const vector<pair<string, int>> base_attacks,
        const vector<pair<string, double>> base_heals,
        int level = 1
    )
    : name(name), type(type), base_max_hp(base_max_hp), base_speed(base_speed), base_attacks(base_attacks), base_heals(base_heals), level(level)
    {
        updateStats();
        hp = double(max_hp);
    }

    void printInfo() const {
        cout << name << endl <<
        "\tType: " << type << endl <<
        "\tLevel: " << level << endl <<
        "\tHP: " << hp << "/" << max_hp << endl <<
        "\tSpeed: " << speed << endl <<
        "\tAttacks:" << endl;
        for (const auto& attack : attacks) {
            cout << "\t\t - " << attack.first << " (Damage: " << attack.second << ")" << endl;
        }
        cout << "\tHealing moves:" << endl;
        for (const auto& heal : heals) {
            cout << "\t\t - " << heal.first << " (Health regained: " << heal.second * 100 << " percent of HP)" << endl;
        }
    }

    void updateStats() { // Used to scale all stats with the level after level is incremented.
        double mult = 0.1 * (level - 1) + 1; // Shortens the level multiplier

        attacks.clear();
        heals.clear();

        max_hp = base_max_hp * mult;
        speed = base_speed * mult;
        for(int i = 0; i < base_attacks.size(); i++){
            attacks.push_back({base_attacks[i].first, (base_attacks[i].second * mult)});
        }
        for(int i = 0; i < base_heals.size(); i++){
            heals.push_back({base_heals[i].first, (base_heals[i].second * mult)});
        }

        hp = max_hp;
    }
};

vector<Pokemon> pokedex = { // List of all Pokemon that can exist. Used when generating new Pokemon.
    {"Charizard", Type::Fire, 78, 85,
        {{"Flamethrower", 15}, {"Dragon Claw", 13}, {"Air Slash", 12}},
        {{"Roost", 0.3}}},

    {"Arcanine", Type::Fire, 90, 80,
        {{"Flare Blitz", 18}, {"Extreme Speed", 14}, {"Crunch", 12}},
        {{"Morning Sun", 0.3}}},

    {"Blastoise", Type::Water, 79, 60,
        {{"Hydro Pump", 16}, {"Ice Beam", 14}, {"Flash Cannon", 13}},
        {{"Life Dew", 0.25}}},

    {"Milotic", Type::Water, 95, 65,
        {{"Surf", 17}, {"Dragon Pulse", 15}, {"Ice Beam", 13}},
        {{"Recover", 0.3}}},

    {"Venusaur", Type::Grass, 80, 60,
        {{"Solar Beam", 18}, {"Sludge Bomb", 14}, {"Earthquake", 13}},
        {{"Synthesis", 0.3}}},

    {"Roserade", Type::Grass, 60, 90,
        {{"Energy Ball", 14}, {"Dazzling Gleam", 12}, {"Shadow Ball", 13}},
        {{"Synthesis", 0.3}}},

    {"Jolteon", Type::Electric, 65, 130,
        {{"Thunderbolt", 15}, {"Shadow Ball", 13}, {"Signal Beam", 12}},
        {{"Wish", 0.3}}},

    {"Luxray", Type::Electric, 80, 70,
        {{"Wild Charge", 16}, {"Crunch", 14}, {"Iron Tail", 12}},
        {{"Life Dew", 0.25}}},

    {"Dragonite", Type::Dragon, 91, 80,
        {{"Outrage", 18}, {"Hurricane", 16}, {"Thunder Punch", 14}},
        {{"Roost", 0.3}}},

    {"Haxorus", Type::Dragon, 76, 97,
        {{"Dragon Claw", 14}, {"Earthquake", 16}, {"Poison Jab", 13}},
        {{"Life Dew", 0.25}}}
};

float findDmg(Type p1_type, Type p2_type){ // Given that some Pokemon are more effective or resistant to others, this function calculates how much damage will be done based on the initial damage of the attack.
    switch(p1_type) {
        case Type::Fire:
            if (p2_type == Type::Grass) return 2.0f;
            if (p2_type == Type::Water || p2_type == Type::Fire || p2_type == Type::Dragon) return 0.5f;
            return 1.0f;
        case Type::Water:
            if (p2_type == Type::Fire) return 2.0f;
            if (p2_type == Type::Water || p2_type == Type::Grass || p2_type == Type::Dragon) return 0.5f;
            return 1.0f;
        case Type::Grass:
            if (p2_type == Type::Water) return 2.0f;
            if (p2_type == Type::Fire || p2_type == Type::Grass || p2_type == Type::Dragon) return 0.5f;
            return 1.0f;
        case Type::Electric:
            if (p2_type == Type::Water) return 2.0f;
            if (p2_type == Type::Grass || p2_type == Type::Electric || p2_type == Type::Dragon) return 0.5f;
            return 1.0f;
        case Type::Dragon:
            if (p2_type == Type::Dragon) return 2.0f;
            return 1.0f;
    }
    return 1.0f;
}

pair<string, double> getMove(Pokemon self){ // Gets the move the user wants to play
    while (true){
        cout << "Select a move: " << endl;

        cout << "Attacks:" << endl;
        for (const auto& attack : self.attacks) {
            cout << " - " << attack.first << " (Damage: " << attack.second << ")" << endl;
        }
        cout << "Healing moves:" << endl;
        for (const auto& heal : self.heals) {
            cout << " - " << heal.first << " (Health regained: " << heal.second * self.hp << "{scales with current HP})" << endl;
        }

        string move;
        getline(cin, move);

        for (const auto& attack : self.attacks){
            if (move == attack.first){
                return attack;
            }
        }
        for (const auto& heal : self.heals){
            if (move == heal.first){
                return heal;
            }
        }

        cout << "You can't play that move! Try again." << endl;
    }
}

Pokemon battle(Pokemon self, Pokemon opp){
    int turn = 1;

    Pokemon p1 = self;
    Pokemon p2 = opp;

    if (p1.speed < p2.speed){ // Makes sure that the faster Pokemon plays first.
        turn = 2;
        cout << p2.name << " attacks first thanks to its superior Speed!" << endl;
    } else cout << p1.name << " attacks first thanks to its superior Speed!" << endl;
    
    cout << endl;
    while (p1.hp > 0 && p2.hp > 0){
        if (turn == 1){
            pair<string, double> p1_move = getMove(p1);
            
            if (p1_move.second > 1){
                cout << p1.name << " used " << p1_move.first << "!" << endl;
                double p1_att = p1_move.second * ((rand() % 16 + 85) / 100.0f) * findDmg(p1.type, p2.type); // Applies random variation and type-specific damage
                p2.hp -= p1_att;
                cout << p2.name << " took " << p1_att << " damage!" << endl;
                if (p2.hp < 0) p2.hp = 0;
                cout << p2.name << " is now at " << p2.hp << " HP." << endl;
            } else {
                double p1_heal = p1_move.second * ((rand() % 16 + 85) / 100.0f) * p1.hp; // Applies random variation and the healing factor for the move, which multiply to a number that scales proportionally with health.
                p1.hp += p1_heal;
                cout << p1.name << " used " << p1_move.first << " and restored " << p1_heal << " HP!" << endl;
                if (p1.hp > p1.max_hp) p1.hp = p1.max_hp;
                cout << p1.name << " is now at " << p1.hp << " HP." << endl;
            }
            turn = 3 - turn; // Since turn is either 1 or 2, this changes whose turn it is. (2=3-1, 1=3-2)
            cout << endl;
        }
        
        if (p2.hp < 0){ // Mid-round check to see if player 2 is dead.
            break;
        }

        if (turn == 2){
            if (rand() % 3 <= 2){
                int p2_index = rand() % 3;
                cout << p2.name << " used " << p2.attacks[p2_index].first << "!" << endl;
                double p2_att = p2.attacks[p2_index].second * ((rand() % 16 + 85) / 100.0f) * findDmg(p2.type, p1.type);
                p1.hp -= p2_att;
                cout << p1.name << " took " << p2_att << " damage!" << endl;
                if (p1.hp < 0) p1.hp = 0;
                cout << p1.name << " is now at " << p1.hp << " HP." << endl;
            } else {
                double p2_heal = p2.heals[0].second * ((rand() % 16 + 85) / 100.0f) * p2.hp;
                p2.hp += p2_heal;
                cout << p2.name << " used " << p2.heals[0].first << " and restored " << p2_heal << " HP!" << endl;
                if (p2.hp > p2.max_hp) p2.hp = p2.max_hp;
                cout << p2.name << " is now at " << p2.hp << " HP." << endl;
            }
            turn = 3 - turn;
            cout << endl;
        }
    }    
    
    if (p2.hp <= 0){
        cout << self.name << " won the battle!" << endl;
        self.level++;
        self.updateStats();
    } else cout << opp.name << " won the battle!" << endl;
    
    return self;
}

vector<Pokemon> pokemons; // Unordered map (functions like a dict) of each Pokemon the user can find.

int main() {
    srand(time(nullptr));

    while (true){
        cout << endl << "What do you want to do?" << endl <<
        "1: Explore" << endl <<
        "2: View Inventory" << endl <<
        "3: Battle" << endl <<
        "4: Exit" << endl;
        string input;
        getline(cin, input);
        int choice;
        try {
            choice = stoi(input);
        } catch (exception& e) {
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        if (choice == MainMenu::Explore){
            while(true){
                Pokemon find = pokedex[rand() % (pokedex.size())];
                cout << "You found a wild " << find.name << "! Do you want to catch it? (Y/N): ";
                string choice;
                getline(cin, choice);
                if (choice == "Y"){
                    bool can_catch = true;
                    for(const auto& pokemon : pokemons){
                        if (find.name == pokemon.name){
                            cout << "Looks like you already have a Pokemon of this type. While you were considering whether to keep it or not, it ran away." << endl;
                            can_catch = false;
                        }
                    }
                    if (can_catch){
                        pokemons.push_back(find);
                        cout << "Caught " << find.name << "!" << endl;
                    }
                    break;
                }
                else if (choice == "N") break;
                else cout << "Invalid input. The Pokemon ran away." << endl;
            }
        } else if (choice == MainMenu::ViewInventory){
            if (pokemons.empty()){
                cout << "You have no Pokemon! Explore to find one!" << endl;
            } else {
                for(const auto& pokemon : pokemons){
                    pokemon.printInfo();
                }
            }
        } else if (choice == MainMenu::Battle){
            if (!pokemons.empty()){
                Pokemon *self = nullptr;

                while (true){
                    cout << "Choose a pokemon for battle: " << endl;
                    for(const auto& pokemon : pokemons){
                        cout << " - " << pokemon.name << endl;
                    }
                    string choice;
                    getline(cin, choice);

                    for(auto& pokemon : pokemons){
                        if (pokemon.name == choice){
                            self = &pokemon;
                        }
                    }
                    if (self){
                        break;
                    } else {
                        cout << "You don't have that Pokemon. Try again." << endl;
                    }
                }

                Pokemon opp = pokedex[rand() % (pokedex.size())];
                cout << "You found a wild " << opp.name << " to battle!" << endl;
                opp.level = self->level; // Makes sure the match is balanced
                opp.updateStats();
                *self = battle(*self, opp);
            } else {
                cout << "You can't battle because you have no Pokemon!" << endl;
            }
        } else if (choice == MainMenu::Exit){
            break;
        } else {
            cout << "That isn't an option. Try again." << endl;
        }
    }



    return 0;
}


/*
Type Interaction	    Damage Multiplier	Meaning
✅ Strong Against	   2×	               Super effective – deal double damage
🚫 Weak Against	        0.5×	            Not very effective – deal half damage
🛡️ Resists	             0.5×	             Take half damage from this type
🔻 Vulnerable To	    2×	                Take double damage from this type
❌ Neutral	           1×	               No change in damage
*/