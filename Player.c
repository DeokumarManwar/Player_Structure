#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct scorecard {
	char name[100];
	int age;
	char country[100];
	char category[100];
	int odi;
	int t20;
	float avg_bat;
	int wickets;
};
void sortplayers(struct scorecard arr[]);
void ncountry(struct scorecard arr[]);
void havg(struct scorecard arr[]);
void bowlcountry(struct scorecard arr[]);
void maxwickets(struct scorecard arr[]);
void data(struct scorecard arr[]);

int n;

int main(void) {
	printf("Enter no of players ");
	scanf("%d", &n);
	struct scorecard arr[n];
	for (int i = 0; i < n; i++) {
		printf("Enter Name of Player %d  ", i + 1);
		scanf("%s", arr[i].name);
		printf("Enter his age ");
		scanf("%d", &arr[i].age);
		printf("Enter his country ");
		scanf("%s", arr[i].country);
		printf("Enter his style of play, 'batsman','bowler','wk','ar'");
		scanf("%s", arr[i].category);
		printf("Enter no of odis played  ");
		scanf("%d", &arr[i].odi);
		printf("Enter no of T20Is played ");
		scanf("%d", &arr[i].t20);
		printf("Enter batting average ");
		scanf("%f", &arr[i].avg_bat);
		printf("Enter no of wickets taken ");
		scanf("%d", &arr[i].wickets);
	}
   
	printf("\n\n");
	int choice = 0;
	for (;;) {
		printf("1.Find players from a particular country\n");
		printf("2.Find player with highest batting avg\n");
		printf("3.Find Bowlers from a particular country\n");
		printf("4.Find player with Maximum Wickets\n");
    printf("5.Display entire information of a particular player\n");
		printf("6.To close the software\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			ncountry(arr);
			break;
		case 2:
			havg(arr);
			break;
		case 3:
			bowlcountry(arr);
			break;
		case 4:
			maxwickets(arr);
			break;
      case 5:
      sortplayers(arr);
      break;
		case 6:
			goto label;
			break;
		default:
			printf("Invalid input try again\n");
		}
	}

label:
	return 0;
  
}
void ncountry(struct scorecard arr[]) {
	char ch[100];
	printf("Enter the country Name to display its players\n");
	scanf("%s", ch);
	printf("Players playing for %s country are\n", ch);
	for (int i = 0; i < n; i++) {
		if (strcmp(ch, arr[i].country) == 0)
			printf("%s\n", arr[i].name);
	}
}
void havg(struct scorecard arr[]) {
	float cont = arr[0].avg_bat;
	int c;
	for (int i = 0; i < n; i++) {
		if (arr[i].avg_bat > cont) {
			cont = arr[i].avg_bat;
			c = i;
		}
	}
	printf("Player with highest batting avg is %s with avg %.2f\n",
		arr[c].name,
		cont);
}
void bowlcountry(struct scorecard arr[]) {
	char ch[100];
	printf("Enter Country\n");
	scanf("%s", ch);
	printf("Bowlers from %s are\n", ch);
	for (int i = 0; i < n; i++) {
		if ((strcmp(ch, arr[i].country) == 0) &&
			strcmp(arr[i].category, "bowler") == 0)
			printf("%s\n", arr[i].name);
	}
}
void maxwickets(struct scorecard arr[]) {
	int cont = arr[0].wickets;
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].wickets > cont) {
			cont = arr[i].wickets;
			c = i;
		}
	}
	printf("Players with most wickets is %s with wickets %d\n", arr[c].name, cont);
}
void sortplayers(struct scorecard arr[])
{
 int  max_idx;
 
   char temp[100];
   float tem=0;
   int t=0;
    for (int i = 0; i < n-1; i++)
    {
    
        max_idx = i;
        for (int j = i+1; j < n; j++)
          if (arr[j].avg_bat > arr[max_idx].avg_bat)
            max_idx = j;

tem=arr[max_idx].avg_bat;
arr[max_idx].avg_bat=arr[i].avg_bat;
arr[i].avg_bat=tem;
  strcpy(temp, arr[max_idx].name);
  strcpy(arr[max_idx].name,arr[i].name);
  strcpy(arr[i].name,temp);
t=arr[max_idx].age;
arr[max_idx].age=arr[i].age;
arr[i].age=t;
  strcpy(temp, arr[max_idx].country);
  strcpy(arr[max_idx].country,arr[i].country);
  strcpy(arr[i].country,temp);
    strcpy(temp, arr[max_idx].category);
  strcpy(arr[max_idx].category,arr[i].category);
  strcpy(arr[i].category,temp);
  t=arr[max_idx].odi;
arr[max_idx].odi=arr[i].odi;
arr[i].odi=t;
    t=arr[max_idx].t20;
arr[max_idx].t20=arr[i].t20;
arr[i].t20=t;
t=arr[max_idx].wickets;
arr[max_idx].wickets=arr[i].wickets;
arr[i].wickets=t;
    }
    printf("Name\t  Avg\tage\tcountry\tcategory\tOdis\tT20Is\tWickets\n");
    for(int i=0;i<n;i++)
    {
printf("%s\t%.2f\t%d\t%s\t%s\t%d\t%d\t%d\n",arr[i].name,arr[i].avg_bat,arr[i].age,arr[i].country,arr[i].category,arr[i].odi,arr[i].t20,arr[i].wickets);
    }
}

