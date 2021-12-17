//
//  main.cpp
//  TerminalDungeon
//
//  
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

//GLOBAL SCOPE

//Attributes
int CurrentEnemyHealth;
std::string CurrentEnemyName;
int CurrentEnemyDamage;
int PlayerHealth;
int PlayerDamage;
char PlayerInput;
char PlayerInputSearch;
int SwordMultiplier = 3;
int DaggerMultiplier = 2;
std::string ItemName;


class Enemy
{
public:
    int EnemyHealth;
    int EnemyDamage;
    std::string EnemyName;
};

void SearchForItems()
{
    std::cout << '-' << std::flush;
    for (;;) {
        Sleep(100);
        std::cout << "\b\\" << std::flush;
        Sleep(100);
        std::cout << "\b|" << std::flush;
        Sleep(100);
        std::cout << "\b/" << std::flush;
        Sleep(100);
        std::cout << "\b-" << std::flush;
        Sleep(100);
        std::cout << "\b\\" << std::flush;
        Sleep(100);
        std::cout << "\b|" << std::flush;
        Sleep(100);
        std::cout << "\b/" << std::flush;
        Sleep(100);
        std::cout << "\b-" << std::flush;
        Sleep(100);
        std::cout << "\b\\" << std::flush;
        Sleep(100);
        std::cout << "\b|" << std::flush;
        Sleep(100);
        std::cout << "\b/" << std::flush;
        Sleep(100);
        std::cout << "\b-" << std::flush;
        break;
    }
    std::string ItemFound;
    std::string Items[2] = { "Dagger", "Sword" };

    srand((int)time(0));
    int itemcalc = (rand() % 10) + 1;

    if (itemcalc <= 5)
    {
        ItemFound = Items[0];
        std::cout << "You found an item!! It looks like a " << Items[0] << "!" << std::endl;
        PlayerDamage = PlayerDamage + DaggerMultiplier;
        ItemName = Items[0];
    }
    else
    {
        ItemFound = Items[1];
        std::cout << "You found an item!! It looks like a " << Items[1] << "!" << std::endl;
        PlayerDamage = PlayerDamage + SwordMultiplier;
        ItemName = Items[1];
    }
};


void BeginPlay()
{
    
    char str1[] = { "Whoa! It's pretty dark in here!"};
    int len = strlen(str1);
    int i;
    for (i = 0; i < len; i++)
    {
        putchar(str1[i]);
        if (str1[i] != ' ' && str1[i] != '\n')
            Beep(15, 75);
        Sleep(1);
    }

    Sleep(2500);

    char str2[] = { "\nWhy don't you look around? ... you may find something interesting." };
    int len1 = strlen(str2);
    int x;
    for (x = 0; x < len1; x++)
    {
        putchar(str2[x]);
        if (str2[x] != ' ' && str2[x] != '\n')
            Beep(15, 50);
        Sleep(1);
    }

    Sleep(1500);
    

    PlayerHealth = 20;
    PlayerDamage = 3;

    //system("Color 08");
    //Sleep(2000);
    std::cout << "\n" << "" << std::endl;
    //Sleep(2000);
    std::cout << "Press 'S' To Search for an Item \n" << std::flush;
    std::cin >> PlayerInputSearch;
    if (PlayerInputSearch == 'S')
    {
        system("CLS");
        SearchForItems();
    }
    
    std::cout << "\n";
    std::cout << "\n";
    //system("Color ");
    

    while (PlayerHealth >= 1)
    {
        srand((int)time(0));
        int damagecalc = (rand() % 3) + 1;

        //Enemy Logic
        Enemy Enemy_TROLL;
        Enemy_TROLL.EnemyName = "Troll";
        Enemy_TROLL.EnemyHealth = 10;
        Enemy_TROLL.EnemyDamage = damagecalc + 3;

        Enemy Enemy_BAT;
        Enemy_BAT.EnemyName = "Bat";
        Enemy_BAT.EnemyHealth = 5;
        Enemy_BAT.EnemyDamage = damagecalc + 1;

        Enemy Enemy_RAT;
        Enemy_RAT.EnemyName = "Rat";
        Enemy_RAT.EnemyHealth = 1;
        Enemy_RAT.EnemyDamage = damagecalc;

        //Random Num
        srand((int)time(0));
        int seed_num = (rand() % 5) + 1;


        if (seed_num == 1)
        {
            CurrentEnemyName = Enemy_TROLL.EnemyName;
            CurrentEnemyHealth = Enemy_TROLL.EnemyHealth;
            CurrentEnemyDamage = Enemy_TROLL.EnemyDamage;
        }
        else if (seed_num == 2)
        {
            CurrentEnemyName = Enemy_BAT.EnemyName;
            CurrentEnemyHealth = Enemy_BAT.EnemyHealth;
            CurrentEnemyDamage = Enemy_BAT.EnemyDamage;
        }
        else if (seed_num >= 3)
        {
            CurrentEnemyName = Enemy_RAT.EnemyName;
            CurrentEnemyHealth = Enemy_RAT.EnemyHealth;
            CurrentEnemyDamage = Enemy_RAT.EnemyDamage;
        }

        std::cout << "=- " << PlayerHealth << "HP -=" << std::endl;
        std::cout << "=- " << PlayerDamage << " BASE DAMAGE -=" << " (+) " << ItemName << std::endl;
        std::cout << "\n";
        Sleep(3500);
        std::cout << "WATCH OUT! There's a " << CurrentEnemyName << " " "infront of you with " << CurrentEnemyHealth << " HP. Press 'A' to perform a light attack" << std::endl;

        std::cin >> PlayerInput;
        if (PlayerInput == 'A')
        {
            CurrentEnemyHealth -= PlayerDamage;
            if (CurrentEnemyHealth <= 0)
            {
                std::cout << "You have slain the creature! " << std::endl;

            }
            else if (CurrentEnemyHealth > 0)
            {
                PlayerHealth = PlayerHealth - CurrentEnemyDamage;
                std::cout << "The Enemy has " << CurrentEnemyHealth << "HP Left.." << std::endl;
                std::cout << "UGH! The enemy launched an attack on you.";
                std::cout << "The enemy dealt " << CurrentEnemyDamage << "DMG!" << std::endl;
                std::cout << "Press 'A' once more to launch an attack on the monster!" << std::endl;
            }
            
        }
        //else
          // std::cin >> PlayerInput;
          //  PlayerHealth = PlayerHealth - CurrentEnemyDamage;        
    };
    std::cin >> PlayerInput;
    if (PlayerInput == 1)
    {
        std::cout << "Wohoo!! You killed the enemy! Press 2 to progress further into the dungeon." << std::endl;
    }
    std::cin >> PlayerInput;
    if (PlayerInput == 2)
    {
        std::cout << "Whoa .. it's dark in here! Be careful!";

    }
};

int main(int argc, const char* argv[])
{
    BeginPlay();
    return 0;
}

