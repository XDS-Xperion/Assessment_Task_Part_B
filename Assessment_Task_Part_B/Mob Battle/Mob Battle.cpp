#include <iostream>
#include <string>

using namespace std;

// Returns A Value Between A & B Based On The Value Of T (0-1).
float Lerp(float a, float b, float t)
{
	return a + t * (b - a);
}

// Enum For The Race Of The Mobs.
enum Mob_Race
{
	Orc = 0,
	Elf = 1,
	Human = 2
};

// Array Containing The Race Options For Mobs.
const string Mob_Race_Option_Array[] = { "Orc", "Elf", "Human" };

// Enum For The Class Of The Mobs.
enum Mob_Class
{
	Mage = 0,
	Warrior = 1,
	Archer = 2
};

// Array Containing The Class Options For Mobs.
const string Mob_Class_Option_Array[] = { "Mage", "Warrior", "Archer" };

struct Mob
{
	// Name Of The Mob.
	string name = "";

	// Attack Skill Of The Mob.
	string attack_skill = "";

	// Min & Max Damage Rating For The Mob.
	int min_damage_rating;
	int max_damage_rating;

	// Health Of The Mob.
	int health;

	// Keeps Track Of The Damage Taken.
	int total_damage_taken = 0;
	int round_damage_taken = 0;

	// Keeps Track Of The Damage Given.
	int total_damage_given = 0;
	int round_damage_given = 0;

	Mob()
	{
		// Get & Set The Random Race Of The Mob.
		int race_options = sizeof(Mob_Race_Option_Array) / sizeof(Mob_Race_Option_Array[0]);
		int random_race_option = rand() % race_options;

		// Set mob_race By Casting random_race_option.
		mob_race = static_cast<Mob_Race>(random_race_option);

		// Get & Set The Random Class Of The Mob.
		int class_options = sizeof(Mob_Class_Option_Array) / sizeof(Mob_Class_Option_Array[0]);
		int random_class_option = rand() % class_options;

		// Set mob_class By Casting random_class_option.
		mob_class = static_cast<Mob_Class>(random_class_option);

		// Set The Name Of The Mob.
		name.append(Mob_Race_Option_Array[random_race_option]);
		name.append(" ");
		name.append(Mob_Class_Option_Array[random_class_option]);

		// Switch Used To Set The Attack Skill Based On The Mobs Class.
		switch (mob_class)
		{
		case Mage:
			attack_skill = "Shadow Bolt";
			break;
		case Warrior:
			attack_skill = "Cripling Strike";
			break;
		case Archer:
			attack_skill = "Multi Shot";
			break;
		default:
			break;
		}

		// Set The Health Of The Mob.
		health = 125;

		// Set The Min & Max Damage Rating For The Mob.
		min_damage_rating = 14;
		max_damage_rating = 22;
	}

	~Mob()
	{

	}

	void Attack(Mob& mob_to_attack)
	{
		// Calculate The Random Damage.
		int random_damage = Calculate_Random_Damage();

		// Print The Attack Message To The Console.
		cout << name << " Used " << attack_skill << " On " << mob_to_attack.name << " For " << random_damage << " Damage!\n";
		
		// Update The Damage Given This Round.
		round_damage_given = random_damage;

		// Update The Damage Given In Total.
		total_damage_given += random_damage;

		// Damage The mob_to_attack.
		mob_to_attack.Take_Damage(random_damage);
	}

	void Take_Damage(int damage)
	{
		// Negate The Damage From The Mobs Health.
		health -= damage;

		// Update The Damage Taken This Round.
		round_damage_taken = damage;

		// Update The Damage Taken In Total.
		total_damage_taken += damage;
	}

	// Returns True If The Mob Is Dead.
	bool Is_Dead()
	{
		return health <= 0;
	}

	// Prints The Statistics For The Current Round.
	void Print_Round_Statistics()
	{
		cout << "Name: " << name << '\n';
		cout << "Health: " << health << '\n';
		cout << "Damage Taken This Round: " << round_damage_taken << '\n';
		cout << "Damage Taken In Total: " << total_damage_taken << '\n';
		cout << "Damage Given This Round: " << round_damage_given << '\n';
		cout << "Damage Given In Total: " << total_damage_given << '\n';
	}

private:
	
	// Used To Store The Mobs Race.
	Mob_Race mob_race;

	// Used To Store The Mobs Class.
	Mob_Class mob_class;

	// Calculates A Random Damage Based On The Mobs Min & Max Attack Rating Using A Simulated Dice Roll.
	int Calculate_Random_Damage()
	{
		// Calculate The Dice Roll (1-12).
		int dice_roll = rand() % 12 + 1;

		// Normalize The Dice Roll (0-1).
		float normalized_dice_roll = (float)(dice_roll - 1) / (12 - 1);

		// Lerp From Min to Max Damage Rating Based On The Normalized Dice Roll.
		float result = Lerp(min_damage_rating, max_damage_rating, normalized_dice_roll);

		// Return The Random Damage.
		return (int)result;
	}
};

// Used To Store The Result Of A Mob Battle.
enum Mob_Battle_Result
{
	A_Defeated,
	B_Defeated,
	Both_Defeated,
	None_Defeated
};

// Returns The Result Of A Battle Between 2 Mobs.
Mob_Battle_Result Mob_Battle(Mob& mob_a, Mob& mob_b)
{
	mob_a.Attack(mob_b);

	if (mob_a.Is_Dead() && mob_b.Is_Dead())
	{
		return Both_Defeated;
	}

	if (mob_b.Is_Dead())
	{
		return B_Defeated;
	}

	mob_b.Attack(mob_a);

	if (mob_b.Is_Dead() && mob_a.Is_Dead())
	{
		return Both_Defeated;
	}

	if (mob_a.Is_Dead())
	{
		return A_Defeated;
	}

	return None_Defeated;
}

int main()
{
	// Initialize The rand() Function.
	srand((unsigned)time(NULL));

	// Initialize mob_a.
	Mob mob_a = Mob();

	// Initialize mob_b.
	Mob mob_b = Mob();

	// Set The Loop Flag.
	bool should_loop = true;

	// Set The Round to 0.
	int mob_battle_round = 0;

	// Loop Until One Or Both Mobs Are Defeated.
	while (should_loop)
	{
		// Increment The Round.
		mob_battle_round++;

		cout << "<---------- Round " << mob_battle_round << " ---------->\n";

		// Execute The MobBattle() Function And Store The Result.
		Mob_Battle_Result mob_battle_result = Mob_Battle(mob_a, mob_b);

		// Switch Used To Check The Mob Battle Result.
		switch (mob_battle_result)
		{
		case A_Defeated: // B Wins, Break The Loop & Log The Result.
			should_loop = false;
			cout << "<---------- Round " << mob_battle_round << " Result ---------->\n";
			cout << mob_b.name << " Defeated " << mob_a.name << " In " << mob_battle_round << " Rounds!\n\n";
			break;

		case B_Defeated: // A Wins, Break The Loop & Log The Result.
			should_loop = false;
			cout << "<---------- Round " << mob_battle_round << " Result ---------->\n";
			cout << mob_a.name << " Defeated " << mob_b.name << " In " << mob_battle_round << " Rounds!\n\n";
			break;

		case Both_Defeated: // Draw, Break The Loop & Log The Result.
			should_loop = false;
			cout << "<---------- Round " << mob_battle_round << " Result ---------->\n";
			cout << "The Mobs Traded Attacks! Both Of Them Have Been Defeated!";
			break;

		case None_Defeated: // No Mobs Defeated, Continue The Loop & Log The Result.
			cout << "<---------- Mob A Stats ---------->\n";
			mob_a.Print_Round_Statistics();
			cout << "<---------- Mob B Stats ---------->\n";
			mob_b.Print_Round_Statistics();
			cout << "<---------- Round " << mob_battle_round << " Result ---------->\n";
			cout << "No Mobs Defeated!\n";
			break;

		default:
			break;
		}
	}

	return 0;
}