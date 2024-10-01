// Minor Project: Player Management System - 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Player {
	
	int jersey_no;
	char name[20];
	char skill[20];
	int matches;
	int runs;
	int wickets;
	int best;
	float avg;
	
} Player;

void storeData(Player*, int);
void removeData(Player*, int, int*);
void searchData(Player*, int, int);
void updateData(Player*, int, int);
void maxRuns(Player*, int);
void displayData(Player*, int);
void maxWickets(Player*, int);

int main() {
	
	int size = 2;
	Player* sportsman= (Player*)malloc(size * sizeof(Player));
	int ch, count = 0, jersey;
	
	printf("\n\4 PLAYER MANAGEMENT SYSTEM \4\n");
	
	do{
	
		printf("\n1.ADD NEW PLAYER DATA. \n2.REMOVE EXISTING PLAYER. \n3.SEARCH PLAYER BY JERSEY No. \n4.UPDATE PREV PLAYER DATA. \n5.DISPLAY ALL PLAYERS."
				"\n6.DISPLAY SORTED PLAYERS. \n7.EXIT APPLICATION...\n");
				
		printf("\nEnter operation you have to perform: ");
		scanf("%d", &ch);
		
		printf("\n---------------------------------------\n");	
			
		switch(ch) {
			
					case 1: 
							if(count < size) {
							
								storeData(sportsman, count);
								count++;
							}
							else{
								
								char choice;
								printf("\nINSUFFICIENT MEMORY!\n");
								printf("\nDo you want to increase memory(y/n): ");
								scanf(" %c", &ch);
								
								if(ch == 'y' || ch == 'Y') {
			
									size = size+5;
									sportsman = (Player*)realloc(sportsman, size * sizeof(Player));
									printf("\nMemory Increased Successfully!\n");
								}
							}
							//printf("%d", count);
							break;
							
					case 2:
							printf("\nEnter Jersey Number of player which you have to remove: ");
							scanf("%d", &jersey);
							
							removeData(sportsman, jersey, &count);
							//printf("%d", count);
							break;
							
					case 3: 
							printf("\nEnter jersey number of player to get details: ");
							scanf("%d", &jersey);
							
							searchData(sportsman, count, jersey);
							break;
							
					case 4:
							printf("\nEnter jersey number to update player data: ");
							scanf("%d", &jersey);
							updateData(sportsman, count, jersey);
							break;
							
					case 5:
							displayData(sportsman, count);
							break;
								
					case 6:
							printf("\n1.Top Players by Runs. \n2.Top Players by Wickets.\n");
							printf("Enter choice: ");
							scanf("%d", &ch);
							
							if(ch == 1) 
								maxRuns(sportsman, count);
							else if(ch==2)
								maxWickets(sportsman, count);
							else
								printf("\nINVALID INPUT!\n");
								
							break;
							
					case 7:
							printf("\nThank You for Using! Exiting...\n");
							return 0;
							
					default: 
							printf("\nInvalid Input!\n");
		}		
		
	} while(1);	
	
	return 0;
}

void storeData(Player* sportsman, int count) {
	
	printf("\nEnter Jersey Number: ");
	scanf("%d", &sportsman[count].jersey_no);
	printf("Enter Player Name: ");
	fflush(stdin);
	gets(sportsman[count].name);
	printf("Enter Player Speciality: ");
	scanf("%s", sportsman[count].skill);
	printf("Enter Matches Played: ");
	scanf("%d", &sportsman[count].matches);
	printf("Enter Total Runs: ");
	scanf("%d", &sportsman[count].runs);
	printf("Enter Total Wickets: ");
	scanf("%d", &sportsman[count].wickets);
	printf("Enter Best Score: ");
	scanf("%d", &sportsman[count].best);
	sportsman[count].avg = (float)(sportsman[count].runs) / sportsman[count].matches;
	
	printf("\nPlayer Added Successfully!");
	
	printf("\n---------------------------------------\n");
	
}

void removeData(Player* sportsman, int remId, int* count) {
	
	int found = 0;
	
	for(int i = 0; i < (*count); i++) {
		
		if(sportsman[i].jersey_no == remId) {
			
			found = 1;
			
			int j;
			for(j = i; j < (*count) - 1; j++) {
				
				sportsman[j] = sportsman[j+1];
			}
			(*count)--;
			
			printf("\nPlayer Removed Successfully!");
			break;	
		}	
	}
	
	if(!found)
		printf("\nPlayer not Found!");
		
	printf("\n---------------------------------------\n");
}

void searchData(Player* sportsman, int count, int jersey) {
	
	int found = 0;
	
	for(int i = 0; i < count; i++) {
		
		if(sportsman[i].jersey_no == jersey) {
			
			found = 1;
			
			printf("\nJersey  : %d", sportsman[i].jersey_no);
			printf("\nName    : %s", sportsman[i].name);
			printf("\nSkill   : %s", sportsman[i].skill);
			printf("\nMatches : %d", sportsman[i].matches);
			printf("\nRuns    : %d", sportsman[i].runs);
			printf("\nWickets : %d", sportsman[i].wickets);
			printf("\nBest    : %d", sportsman[i].best);
			printf("\nAverage : %.2f", sportsman[i].avg);
			
			break;
		}
	}
	
	if(!found) 
		printf("\nPlayer Not Found!");
		
	printf("\n---------------------------------------\n");	
}

void updateData(Player* sportsman, int count, int jersey) {
	
	int found = 0;
	
	for(int i = 0; i < count; i++) {
		
		if(sportsman[i].jersey_no == jersey) {
			
			found = 1;
			
			printf("Enter Player Name: ");
			fflush(stdin);
			gets(sportsman[i].name);
			printf("Enter Player Speciality: ");
			scanf("%s", sportsman[i].skill);
			printf("Enter Matches Played: ");
			scanf("%d", &sportsman[i].matches);
			printf("Enter Total Runs: ");
			scanf("%d", &sportsman[i].runs);
			printf("Enter Total Wickets: ");
			scanf("%d", &sportsman[i].wickets);
			printf("Enter Best Score: ");
			scanf("%d", &sportsman[i].best);
			sportsman[i].avg = (float)(sportsman[i].runs) / sportsman[i].matches;
			
			printf("\nPlayer Data Updated Successfully!");
			
			break;
		}
	}
	
	if(!found) 
		printf("\nPlayer Not Found!");
		
	printf("\n---------------------------------------\n");
	
}

void displayData(Player* sportsman, int count) {
	
	for(int i = 0; i < count; i++) {
		
		printf("\nJersey  : %d", sportsman[i].jersey_no);
		printf("\nName    : %s", sportsman[i].name);
		printf("\nSkill   : %s", sportsman[i].skill);
		printf("\nMatches : %d", sportsman[i].matches);
		printf("\nRuns    : %d", sportsman[i].runs);
		printf("\nWickets : %d", sportsman[i].wickets);
		printf("\nBest    : %d", sportsman[i].best);
		printf("\nAverage : %.2f", sportsman[i].avg);
		printf("\n---------------------------------------\n");
	}
}

void maxRuns(Player* sportsman, int count) {
	
	Player temp[count];
	
	for(int i = 0; i < count; i++) {
		
		temp[i] = sportsman[i];
	}
	
	Player temp2;
	
	for(int i = 0; i < count; i++) {
		
		for(int j = i + 1; j < count; j++){
			
			if(temp[i].runs < temp[j].runs) {
				
				temp2 = temp[j];
				temp[j] = temp[i];
				temp[i] = temp2;
			}
		}
	}
	
	for(int i = 0; i < count; i++) {
		
		printf("\nJersey  : %d", temp[i].jersey_no);
		printf("\nName    : %s", temp[i].name);
		printf("\nSkill   : %s", temp[i].skill);
		printf("\nMatches : %d", temp[i].matches);
		printf("\nRuns    : %d", temp[i].runs);
		printf("\nWickets : %d", temp[i].wickets);
		printf("\nBest    : %d", temp[i].best);
		printf("\nAverage : %.2f", temp[i].avg);
		printf("\n---------------------------------------\n");
	}
	
		
}

void maxWickets(Player* sportsman, int count) {
	
	Player temp[count];
	
	for(int i = 0; i < count; i++) {
		
		temp[i] = sportsman[i];
	}
	
	Player temp2;
	
	for(int i = 0; i < count; i++) {
		
		for(int j = i + 1; j < count; j++){
			
			if(temp[i].wickets < temp[j].wickets) {
				
				temp2 = temp[j];
				temp[j] = temp[i];
				temp[i] = temp2;
			}
		}
	}
	
	for(int i = 0; i < count; i++) {
		
		printf("\nJersey  : %d", temp[i].jersey_no);
		printf("\nName    : %s", temp[i].name);
		printf("\nSkill   : %s", temp[i].skill);
		printf("\nMatches : %d", temp[i].matches);
		printf("\nRuns    : %d", temp[i].runs);
		printf("\nWickets : %d", temp[i].wickets);
		printf("\nBest    : %d", temp[i].best);
		printf("\nAverage : %.2f", temp[i].avg);
		printf("\n---------------------------------------\n");
	}
}
