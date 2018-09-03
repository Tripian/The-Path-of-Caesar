
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

struct Character {

	double HP;
	double maxHP;
	double mana;
	double maxmana;
	double armor;
	double attack_damage;
	int money;
	int experience;
	int level;
	int plus;
	int health_potion[4];
	int mana_potion[4];
	boolean alive;


};

struct Monster {

	double HP;
	double armor;
	double attack_damage;
	int money;
	int experience;
	boolean alive;

};

struct Potions {

    int prices[4];

};

struct Items {

    struct Potions health,mana;

};

int Levels[10] = {50 , 100 , 200 , 400 , 800 , 1600 , 3200 , 6400 , 12800 , 25600};
int Plus[6] = {0 , 1 , 2 , 3 , 4 , 5};


void combat( struct Character *Caesar , struct Monster Monster );
void shop(struct Character *Caesar , struct Items pots);
void info(struct Character *Caesar);
void save(struct Character *Caesar);
void load(struct Character *Caesar);
void altar(struct Character *Caesar);
void experience(struct Character *Caesar);

int main()
{
	struct Character Caesar;
	struct Monster Monster;
	struct Items pots;
	int i;
	char ch;

	Caesar.HP = 100;
	Caesar.maxHP = Caesar.HP;
	Caesar.mana = 100;
	Caesar.maxmana = Caesar.mana;
	Caesar.armor = 10;
	Caesar.attack_damage = 30;
	Caesar.money = 50;
	Caesar.experience = 0;
	Caesar.level = 1;
	Caesar.plus = 0;
	for(i=0;i<4;i++){
        Caesar.health_potion[i]=3;
	}
    for(i=0;i<4;i++){
        Caesar.mana_potion[i]=3;
	}
	Caesar.alive = true;

	Monster.HP = 56;
	Monster.armor = 10;
	Monster.attack_damage = 12;
	Monster.money = 30;
	Monster.experience = 50; //511500000
	Monster.alive = true;

	pots.health.prices[0]=5;
    pots.health.prices[1]=15;
    pots.health.prices[2]=25;
    pots.health.prices[3]=35;

    pots.mana.prices[0]=5;
    pots.mana.prices[1]=15;
    pots.mana.prices[2]=25;
    pots.mana.prices[3]=35;

	while(1){
        printf("1: Combat\n2: Shop\n3: Info\n4: Save\n5: Load\n6: Altar\n\n");
        ch = getch();
        if( ch == '1'){
                if( Caesar.alive == false){
                    printf("You are dead.\nGo to altar for resurrect.\nPress any key for return.\n");
                    ch = getch();
                    goto Clr;
                }
            Combat:combat(&Caesar , Monster);

            if(Caesar.alive == false){
                printf("You are dead...\nGo to altar for resurrect.\nPress any key for return.\n");
                    ch = getch();
                    goto Clr;
            }

            printf("Do you want to continue to combat?\nIf you want press Y.\n\n");
            ch = getch();
            if( ch == 'y' || ch=='Y'){
                goto Combat;
            }

        }
        else if( ch == '2'){
            Shop:shop(&Caesar , pots);
            printf("Do you want to continue to shop?\nIf you want press Y.\n\n");
            ch = getch();
            if( ch == 'y' || ch=='Y'){
                goto Shop;
            }
        }
        else if( ch == '3'){
            info(&Caesar);
            printf("Press any key for return.\n");
            ch = getch();
        }
        else if( ch == '4'){
            save(&Caesar);
            printf("The game has been saved.\nPress any key for return.\n");
            ch = getch();
        }
        else if( ch == '5'){
            load(&Caesar);
            printf("The game has been loaded.\nPress any key for return.\n");
            ch = getch();
        }
        else if( ch == '6'){
                if(Caesar.alive==true){
                    printf("You are alive...\nPress any key for return.\n");
                    ch = getch();
                    goto Cp;
                }
            altar(&Caesar);
            printf("You have been resurrected.\nPress any key for return.\n");
            ch = getch();
        }
        Cp:for(i=0;i<440000000;i++);
        Clr:system("cls");
	}

	system("pause");


	return 0;
}

void combat(struct Character *Caesar , struct Monster Monster)
{
    int  a = 0,rn,turn=1,percentage;
	double get_damage[2];
	char ch;
	srand(time(NULL));



    printf("        -------                    \n");
	printf("     \\  | - - |                    \n");
	printf("      \\ -------                    \n");
	printf("       \\   |                       \n");
	printf("          /|\\    /                \n");
	printf("         / | \\  /                 \n");
	printf("        /  |  \\/                  \n");
	printf("           |  /                   \n");
	printf("          / \\                     \n");
	printf("         /   \\                    \n");
	printf("        /     \\                   \n");

    for(a=0;a<220000000;a++);


    while (Caesar->alive == true && Monster.alive == true) {


        printf("%d. TURN",turn);
        turn++;
        for(a=0;a<220000000;a++);
        printf("\nCaesar is attacking now.");
        rn=rand()%11-5;
        get_damage[1] = Caesar->attack_damage - Monster.armor + rn;
        if(get_damage[1]<=0){
            printf("MONSTER BLOCKED THIS ATTACK");
            get_damage[1] = 0;
        }

        rn=rand()%100+1;

        if(rn>90){
            printf("\nYOU HIT WITH A CRITICAL STRIKE!!!");
            get_damage[1]*=2;
        }

        rn=rand()%100+1;

        if(rn>95){
            printf("\nMONSTER DODGED THIS ATTACK");
            get_damage[1] = 0;
        }


		Monster.HP = Monster.HP - get_damage[1];

        if(Monster.HP<=0){
            Monster.HP=0;
        }

		printf("\nMonster lost %.2lf HP\n", get_damage[1]);
		printf("Monster's HP: %.2lf\n", Monster.HP);


		for(a=0;a<440000000;a++);

		Monster_death:if (Monster.HP <= 0) {
			Monster.alive = false;
			printf("\nCaesar killed the monster... But for this time...\n");
			rn=rand() % 21 - 10;
			Caesar->money = Caesar->money + Monster.money + rn;
			Caesar->experience = Caesar->experience + Monster.experience;
			Caesar->HP += 10;
            if(Caesar->HP> Caesar->maxHP){
                    Caesar->HP = Caesar->maxHP;
                }
			Caesar->mana += 10;
			if(Caesar->mana> Caesar->maxmana){
                    Caesar->mana = Caesar->maxmana;
                }

			printf("Caesar gained some money and experience...\n\n");
			if(Caesar->level!=10 && Caesar->plus!=5){
                experience(Caesar);
			}
			if(Caesar->level==10 && Caesar->plus==5){
                Caesar->experience=0;
			}
			printf("\nCaesar's HP: %.2lf", Caesar->HP);
			printf("\nCaesar's mana: %.2lf\n", Caesar->mana);
			printf("Caesar's money: %d\n", Caesar->money);
			if(Caesar->level==10 && Caesar->plus==5){
                printf("Caesar's experience: %d / %d\n\n", Caesar->experience , 0);
			}
			else{
                printf("Caesar's experience: %d / %d\n\n", Caesar->experience , Levels[Caesar->level-1]+Levels[Caesar->level-1]*Plus[Caesar->plus]);
			}
			for(a=0;a<440000000;a++);
			break;
		}


		printf("\nP: Health Potion\nM: Mana Potion\nX: Special Attack\nZ: Escape\n");

        rn=rand()%100+1;

		ch = getch();

		for(a=0;a<110000000;a++);



		if (ch == 'p' || ch == 'P') {
            printf("\nChoose small,medium,large or super health potion.\n(press 1/2/3/4)\n");
            ch = getch();
			if(ch == '1' && Caesar->health_potion[0]>0){
                percentage = Caesar->maxHP/10;
                Caesar->HP += percentage;
                if(Caesar->HP> Caesar->maxHP){
                    Caesar->HP = Caesar->maxHP;
                }
                Caesar->health_potion[0] -= 1;
                printf("\nCaesar gained %d hp\n",percentage);
                printf("Caesar's HP: %.2lf\n", Caesar->HP);
                printf("You have %d small health potion left\n",Caesar->health_potion[0]);
            }
            else if(ch == '2' && Caesar->health_potion[1]>0){
                percentage = Caesar->maxHP/10*2;
                Caesar->HP += percentage;
                if(Caesar->HP> Caesar->maxHP){
                    Caesar->HP = Caesar->maxHP;
                }
                Caesar->health_potion[1] -= 1;
                printf("\nCaesar gained %d hp\n",percentage);
                printf("Caesar's HP: %.2lf\n", Caesar->HP);
                printf("You have %d medium health potion left\n",Caesar->health_potion[1]);
            }
            else if(ch == '3' && Caesar->health_potion[2]>0){
                percentage = Caesar->maxHP/10*4;
                Caesar->HP += percentage;
                if(Caesar->HP> Caesar->maxHP){
                    Caesar->HP = Caesar->maxHP;
                }
                Caesar->health_potion[2] -= 1;
                printf("\nCaesar gained %d hp\n",percentage);
                printf("Caesar's HP: %.2lf\n", Caesar->HP);
                printf("You have %d large health potion left\n",Caesar->health_potion[2]);
            }
            else if(ch == '4' && Caesar->health_potion[3]>0){
                percentage = Caesar->maxHP/10*6;
                Caesar->HP += percentage;
                if(Caesar->HP> Caesar->maxHP){
                    Caesar->HP = Caesar->maxHP;
                }
                Caesar->health_potion[3] -= 1;
                printf("\nCaesar gained %d hp\n",percentage);
                printf("Caesar's HP: %.2lf\n", Caesar->HP);
                printf("You have %d super health potion left\n",Caesar->health_potion[3]);
            }
            else{
                printf("\nYou don't have that type of potion.\n");
            }

		}

		else if (ch == 'm' || ch == 'M') {
            printf("\nChoose small,medium,large or super mana potion.\n(press 1/2/3/4)\n");
            ch = getch();
			if(ch == '1' && Caesar->mana_potion[0]>0){
                percentage = Caesar->maxmana/10;
                Caesar->mana += percentage;
                if(Caesar->mana> Caesar->maxmana){
                    Caesar->mana = Caesar->maxmana;
                }
                Caesar->mana_potion[0] -= 1;
                printf("\nCaesar gained %d mana\n",percentage);
                printf("Caesar's mana: %.2lf\n", Caesar->mana);
                printf("You have %d small mana potion left\n",Caesar->mana_potion[0]);
            }
            else if(ch == '2' && Caesar->mana_potion[1]>0){
                percentage = Caesar->maxmana/10*2;
                Caesar->mana += percentage;
                if(Caesar->mana> Caesar->maxmana){
                    Caesar->mana = Caesar->maxmana;
                }
                Caesar->mana_potion[1] -= 1;
                printf("\nCaesar gained %d mana\n",percentage);
                printf("Caesar's mana: %.2lf\n", Caesar->mana);
                printf("You have %d medium mana potion left\n",Caesar->mana_potion[1]);
            }
            else if(ch == '3' && Caesar->mana_potion[2]>0){
                percentage = Caesar->maxmana/10*4;
                Caesar->mana += percentage;
                if(Caesar->mana> Caesar->maxmana){
                    Caesar->mana = Caesar->maxmana;
                }
                Caesar->mana_potion[2] -= 1;
                printf("\nCaesar gained %d mana\n",percentage);
                printf("Caesar's mana: %.2lf\n", Caesar->mana);
                printf("You have %d large mana potion left\n",Caesar->mana_potion[2]);
            }
            else if(ch == '4' && Caesar->mana_potion[3]>0){
                percentage = Caesar->maxmana/10*6;
                Caesar->mana += percentage;
                if(Caesar->mana> Caesar->maxmana){
                    Caesar->mana = Caesar->maxmana;
                }
                Caesar->mana_potion[3] -= 1;
                printf("\nCaesar gained %d mana\n",percentage);
                printf("Caesar's mana: %.2lf\n", Caesar->mana);
                printf("You have %d large mana potion left\n",Caesar->mana_potion[3]);
            }
            else{
                printf("\nYou don't have that type of potion.\n");
            }

		}

		else if ((ch == 'z' || ch == 'Z') && rn<=67) {
			printf("\nCaesar runned away from combat like a coward.\n");
			printf("\nCaesar's HP: %.2lf", Caesar->HP);
			printf("\nCaesar's mana: %.2lf\n", Caesar->mana);
			printf("Caesar's money: %d\n", Caesar->money);
			printf("Caesar's experience: %d\n\n", Caesar->experience);
			for(a=0;a<440000000;a++);
            break;
		}

		else if ((ch == 'z' || ch == 'Z') && rn>67){
            printf("\nCaesar's escape attempt is failed.\n");
		}

		else if (ch == 'x' || ch == 'X') {
			printf("\nChoose quick,normal or super special attack.\n(press 1/2/3)\n");
            ch = getch();
            if(ch == '1' && Caesar->mana>=15){
                rn=rand()%11-5;
                Monster.HP -= 30+rn;
                Caesar->mana -= 15;
                if(Monster.HP<=0){
                    Monster.HP=0;
                }
                printf("\nMonster lost %d hp\n",(30+rn));
                printf("Monster's HP: %.2lf\n", Monster.HP);
            }

            else if(ch == '2' && Caesar->mana>=30){
                rn=rand()%21-10;
                Monster.HP -= 60+rn;
                Caesar->mana -= 30;
                if(Monster.HP<=0){
                    Monster.HP=0;
                }
                printf("\nMonster lost %d hp\n",(60+rn));
                printf("Monster's HP: %.2lf\n", Monster.HP);
            }

            else if(ch == '3' && Caesar->mana>=45){
                rn=rand()%31-15;
                Monster.HP -= 90+rn;
                Caesar->mana -= 45;
                if(Monster.HP<=0){
                    Monster.HP=0;
                }
                printf("\nMonster lost %d hp\n",(90+rn));
                printf("Monster's HP: %.2lf\n\n", Monster.HP);
            }
            else{
                printf("\nNot enough mana!");
                printf("\nMana:%.2lf\n",Caesar->mana);
            }

		}

		if (Monster.HP <= 0) {
            for(a=0;a<440000000;a++);
			goto Monster_death;
		}

        for(a=0;a<220000000;a++);

        printf("\nMonster is attacking now.");
        rn=rand()%11-5;
        get_damage[0] = Monster.attack_damage - Caesar->armor + rn;
        if(get_damage[0]<=0){
            printf("\nYOU BLOCKED THIS ATTACK");
            get_damage[0] = 0;
        }

        rn=rand()%100+1;

        if(rn>90){
            printf("\nMONSTER HITS WITH A CRITICAL STRIKE!!!");
            get_damage[0]*=2;
        }

        rn=rand()%100+1;

        if(rn>95){
            printf("\nYOU DODGED THIS ATTACK");
            get_damage[0] = 0;
        }



		Caesar->HP = Caesar->HP - get_damage[0];

		if(Caesar->HP<=0){
            Caesar->HP=0;
        }

		printf("\nCaesar lost %.2lf HP \n", get_damage[0]);
		printf("Caesar's HP: %.2lf\n\n", Caesar->HP);




		for(a=0;a<440000000;a++);


		if (Caesar->HP <= 0) {
			Caesar->alive = false;
			printf("Caesar killed by monster...\n");
			printf("- -- - -- -\n");
			printf("      | - - |\n");
			printf("               -- - -- - -\n");
			printf("			 	|\n");
			printf(" /           |     /\n");
			printf("       /               |    /\n");
			printf(" /        	|   /\n");
			printf("   |   /\n");
			printf(" /                     \\\n");
			printf("       /         \\\n");
			printf("   /	                      \\\n");
			printf("\n\n\n YOU MUST RESURRECT..........\n\n\n");
			break;
		}

	}



}

void shop(struct Character *Caesar , struct Items pots)
{
    char ch;
    int i,number;

    printf("Welcome to the shop\nP: Potions\n\n");
    ch = getch();
    if( ch == 'p' || ch == 'P'){
        printf("H: Health Potions\nM: Mana Potions\n\n");
        ch = getch();
        if( ch == 'h' || ch == 'H'){
            printf("S: Small Health Potion : %d gold\nM: Medium Health Potion : %d gold\nL: Large Health Potion : %d gold\nU: Super Health Potion : %d gold\n\n",pots.health.prices[0],pots.health.prices[1],pots.health.prices[2],pots.health.prices[3]);
            ch= getch();
            if( (ch == 's' || ch == 'S') && Caesar->money>=pots.health.prices[0]){
                printf("How many do you want?\n");
                scanf("%d",&number);
                for(i=0;i<number;i++){
                    Caesar->health_potion[0]++;
                    Caesar->money -= pots.health.prices[0];
                    if(Caesar->money<pots.health.prices[0]){
                        break;
                    }
                }
                printf("You have %d small health potion\n",Caesar->health_potion[0]);
                printf("You have %d gold.\n\n",Caesar->money);
            }
            else if( (ch == 'm' || ch == 'M') && Caesar->money>=pots.health.prices[1]){
                printf("How many do you want?\n");
                scanf("%d",&number);
                for(i=0;i<number;i++){
                    Caesar->health_potion[1]++;
                    Caesar->money -= pots.health.prices[1];
                    if(Caesar->money<pots.health.prices[1]){
                        break;
                    }
                }
                printf("You have %d medium health potion\n",Caesar->health_potion[1]);
                printf("You have %d gold.\n\n",Caesar->money);
            }
            else if( (ch == 'l' || ch == 'L') && Caesar->money>=pots.health.prices[2]){
                printf("How many do you want?\n");
                scanf("%d",&number);
                for(i=0;i<number;i++){
                    Caesar->health_potion[2]++;
                    Caesar->money -= pots.health.prices[2];
                    if(Caesar->money<pots.health.prices[2]){
                        break;
                    }
                }
                printf("You have %d large health potion\n",Caesar->health_potion[2]);
                printf("You have %d gold.\n\n",Caesar->money);
            }
            else if( (ch == 'u' || ch == 'U') && Caesar->money>=pots.health.prices[3]){
                printf("How many do you want?\n");
                scanf("%d",&number);
                for(i=0;i<number;i++){
                    Caesar->health_potion[3]++;
                    Caesar->money -= pots.health.prices[3];
                    if(Caesar->money<pots.health.prices[3]){
                        break;
                    }
                }
                printf("You have %d super health potion\n",Caesar->health_potion[3]);
                printf("You have %d gold.\n\n",Caesar->money);
            }
            else{
                printf("You don't have enough money.\n\n");
            }

        }
        else if( ch == 'm' || ch == 'M'){
                printf("S: Small Mana Potion : %d gold\nM: Medium Mana Potion : %d gold\nL: Large Mana Potion : %d gold\nU: Super Mana Potion : %d gold\n\n",pots.mana.prices[0],pots.mana.prices[1],pots.mana.prices[2],pots.mana.prices[3]);
            ch= getch();
            if( (ch == 's' || ch == 'S') && Caesar->money>=pots.mana.prices[0]){
                printf("How many do you want?\n");
                scanf("%d",&number);
                for(i=0;i<number;i++){
                    Caesar->mana_potion[0]++;
                    Caesar->money -= pots.mana.prices[0];
                    if(Caesar->money<pots.mana.prices[0]){
                        break;
                    }
                }
                printf("You have %d small mana potion\n",Caesar->mana_potion[0]);
                printf("You have %d gold.\n\n",Caesar->money);
            }
            else if( (ch == 'm' || ch == 'M') && Caesar->money>=pots.mana.prices[1]){
                printf("How many do you want?\n");
                scanf("%d",&number);
                for(i=0;i<number;i++){
                    Caesar->mana_potion[1]++;
                    Caesar->money -= pots.mana.prices[1];
                    if(Caesar->money<pots.mana.prices[1]){
                        break;
                    }
                }
                printf("You have %d medium mana potion\n",Caesar->mana_potion[1]);
                printf("You have %d gold.\n\n",Caesar->money);
            }
            else if( (ch == 'l' || ch == 'L') && Caesar->money>=pots.mana.prices[2]){
                printf("How many do you want?\n");
                scanf("%d",&number);
                for(i=0;i<number;i++){
                    Caesar->mana_potion[2]++;
                    Caesar->money -= pots.mana.prices[2];
                    if(Caesar->money<pots.mana.prices[2]){
                        break;
                    }
                }
                printf("You have %d large mana potion\n",Caesar->mana_potion[2]);
                printf("You have %d gold.\n\n",Caesar->money);
            }
            else if( (ch == 'u' || ch == 'U') && Caesar->money>=pots.mana.prices[3]){
                printf("How many do you want?\n");
                scanf("%d",&number);
                for(i=0;i<number;i++){
                    Caesar->mana_potion[3]++;
                    Caesar->money -= pots.mana.prices[3];
                    if(Caesar->money<pots.mana.prices[3]){
                        break;
                    }
                }
                printf("You have %d super mana potion\n",Caesar->mana_potion[3]);
                printf("You have %d gold.\n\n",Caesar->money);
            }
            else{
                printf("You don't have enough money.\n\n");
            }

        }
    }



}

void info(struct Character *Caesar)
{
    int i;

    printf("\nCaesar's HP: %.2lf / %.2lf", Caesar->HP , Caesar->maxHP );
    printf("\nCaesar's mana: %.2lf / %.2lf\n", Caesar->mana , Caesar->maxmana);
    printf("Caesar's attack damage: %.2lf\n", Caesar->attack_damage);
    printf("Caesar's armor: %.2lf\n", Caesar->armor);
    printf("Caesar's money: %d\n", Caesar->money);
    if(Caesar->level==10 && Caesar->plus==5){
    printf("Caesar's experience: %d / %d\n\n", Caesar->experience , 0);
    }
    else{
    printf("Caesar's experience: %d / %d\n\n", Caesar->experience , Levels[Caesar->level-1]+Levels[Caesar->level-1]*Plus[Caesar->plus]);
    }
    printf("Caesar's level: %d", Caesar->level);
    for(i=0;i<Caesar->plus;i++){
        printf("+");
    }

    if(Caesar->health_potion[0]>0)
    printf("\n\nCaesar's small health potion: %d\n", Caesar->health_potion[0]);
    if(Caesar->health_potion[1]>0)
    printf("Caesar's medium health potion: %d\n", Caesar->health_potion[1]);
    if(Caesar->health_potion[2]>0)
    printf("Caesar's large health potion: %d\n", Caesar->health_potion[2]);
    if(Caesar->health_potion[3]>0)
    printf("Caesar's super health potion: %d\n\n", Caesar->health_potion[3]);

    if(Caesar->mana_potion[0]>0)
    printf("Caesar's small mana potion: %d\n", Caesar->mana_potion[0]);
    if(Caesar->mana_potion[1]>0)
    printf("Caesar's medium mana potion: %d\n", Caesar->mana_potion[1]);
    if(Caesar->mana_potion[2]>0)
    printf("Caesar's large mana potion: %d\n", Caesar->mana_potion[2]);
    if(Caesar->mana_potion[3]>0)
    printf("Caesar's super mana potion: %d\n\n", Caesar->mana_potion[3]);

}

void save(struct Character *Caesar)
{

    FILE *fptr;

    fptr = fopen("first_save.bin" , "wb+");

    if(fptr == NULL){
        printf("Save Error!");
        exit(1);
    }

    fprintf( fptr , "%.2lf\n" , Caesar->HP );
    fprintf( fptr , "%.2lf\n" , Caesar->maxHP );
    fprintf( fptr , "%.2lf\n" , Caesar->mana );
    fprintf( fptr , "%.2lf\n" , Caesar->maxmana );
    fprintf( fptr , "%.2lf\n" , Caesar->attack_damage );
    fprintf( fptr , "%.2lf\n" , Caesar->armor );
    fprintf( fptr , "%d\n" , Caesar->money );
    fprintf( fptr , "%d\n" , Caesar->experience );
    fprintf( fptr , "%d\n" , Caesar->level);
    fprintf( fptr , "%d\n" , Caesar->plus);
    fprintf( fptr , "%d\n" , Caesar->alive );

    fprintf( fptr , "%d\n" , Caesar->health_potion[0] );
    fprintf( fptr , "%d\n" , Caesar->health_potion[1] );
    fprintf( fptr , "%d\n" , Caesar->health_potion[2] );
    fprintf( fptr , "%d\n" , Caesar->health_potion[3] );

    fprintf( fptr , "%d\n" , Caesar->mana_potion[0] );
    fprintf( fptr , "%d\n" , Caesar->mana_potion[1] );
    fprintf( fptr , "%d\n" , Caesar->mana_potion[2] );
    fprintf( fptr , "%d\n" , Caesar->mana_potion[3] );





    fclose(fptr);

}

void load(struct Character *Caesar)
{

    FILE *fptr;

    fptr = fopen("first_save.bin" , "rb+");

    if(fptr == NULL){
        printf("Load Error!");
        exit(1);
    }

    fscanf( fptr , "%lf" ,  &Caesar->HP );
    fscanf( fptr , "%lf" ,  &Caesar->maxHP );
    fscanf( fptr , "%lf" ,  &Caesar->mana );
    fscanf( fptr , "%lf" ,  &Caesar->maxmana );
    fscanf( fptr , "%lf" ,  &Caesar->attack_damage );
    fscanf( fptr , "%lf" ,  &Caesar->armor );
    fscanf( fptr , "%d"  ,  &Caesar->money );
    fscanf( fptr , "%d"  ,  &Caesar->experience );
    fscanf( fptr , "%d"  ,  &Caesar->level);
    fscanf( fptr , "%d"  ,  &Caesar->plus);
    fscanf( fptr , "%d"  ,  &Caesar->alive );

    fscanf( fptr , "%d" ,  &Caesar->health_potion[0] );
    fscanf( fptr , "%d" ,  &Caesar->health_potion[1] );
    fscanf( fptr , "%d" ,  &Caesar->health_potion[2] );
    fscanf( fptr , "%d" ,  &Caesar->health_potion[3] );

    fscanf( fptr , "%d" ,  &Caesar->mana_potion[0] );
    fscanf( fptr , "%d" ,  &Caesar->mana_potion[1] );
    fscanf( fptr , "%d" ,  &Caesar->mana_potion[2] );
    fscanf( fptr , "%d" ,  &Caesar->mana_potion[3] );





    fclose(fptr);



}

void altar(struct Character *Caesar)
{
    Caesar->alive = true;
    Caesar->HP = Caesar->maxHP;
    Caesar->mana = Caesar->maxmana;


}

void experience(struct Character *Caesar)
{
    int i;

    while(Caesar->experience >= Levels[Caesar->level-1]+Levels[Caesar->level-1]*Plus[Caesar->plus] && Caesar->plus<=5){
    if(Caesar->experience >= Levels[Caesar->level-1]+Levels[Caesar->level-1]*Plus[Caesar->plus]){
        Caesar->experience -= Levels[Caesar->level-1]+Levels[Caesar->level-1]*Plus[Caesar->plus];
        Caesar->level++;
        Caesar->HP+=30;
        Caesar->maxHP+=30;
        Caesar->mana+=15;
        Caesar->maxmana+=15;
        Caesar->attack_damage+=4;
        Caesar->armor+=2;
        if(Caesar->level>10 && Caesar->plus<5){
            Caesar->level=1;
            Caesar->plus++;

        }

        printf("Caesar advanced to level %d", Caesar->level);
        for(i=0;i<Caesar->plus;i++){
        printf("+");
        }
        printf("\n");
        if(Caesar->level==10 && Caesar->plus==5){
            break;
        }

    }
    }


}
