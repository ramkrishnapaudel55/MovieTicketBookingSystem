#include<stdio.h>
#include<stdlib.h>
#include"moviedetails.c"
#include"decleration.c"
#include<strings.h>
struct moviedetails person[300];
int count=0;
int id2=1000;

int main()
{
	system("color A");
	int **seat,choice,price=500,slection,i;
	seat=(int **)calloc(101,sizeof(int *));
	for (i=0;i<3;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int ));
	int x;
	while(x!=3)
	{
		choice=choice1();
		switch(choice)
		{
			case 1:
				slection=movie();
				reservation(seat[slection-1],price,slection);
				count++;
				break;
			case 2:
				slection=cmovie();
				cancel(seat[slection-1]);
				break;
			case 3:
				x=3;
				break;
			default:
				printf("Choice not available\n");
				break;
		}
	}
}


void reservation(int *array,int price,int slection)
{
		int i,j;
		printf("\n                                SCREEN\n\n\n");
		for (i=1;i<=100;i++)
		{
			if (array[i]==0)
				printf("%d\t",i);
			else
				printf("*\t",i);
			if(i%10==0)
				printf("\n\n");
		}
		printf("Please enter your name: ");
		scanf(" %19[^\n]%*[^\n]",&person[count].name);
		printf("Please enter your phone number: ");
		scanf("%u",&person[count].phone);
		printf("Which seat number you want? ");
		scanf("%d",&j);
		if (j>100||j<1)
			{
				printf("seat1 number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;
		person[count].seat=j;
		if (slection==1)
			ticket1(j,person[count].name,id2,price);
		else if (slection==2)
			ticket2(j,person[count].name,id2,price);
		else
			ticket3(j,person[count].name,id2,price);
		id2++;
}
int choice1(void)
{
	int choice;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                 Simple Movie Ticket Booking System\n");
	printf(" ==================================================================\n");
	printf("||             1- To puchase ticket:                              ||\n");
	printf("||             2- To cancel the seat:                             ||\n");
	printf("||             3- Exit system:                                    ||\n");
	printf("||================================================================||\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}
void cancel(int *array)
{
      int Cseat,i,stop;
	  printf("Please enter ID number of ticket: ");
	  scanf("%d",&Cseat);
	  for (i=0;i<300;i++)
	  {
	  		if(Cseat==person[i].id)
	  		{
					 stop=5;
					 system("cls");
					 printf("%s your seat is %d cancelled",person[i].name,person[i].seat);
					 array[person[i].seat]=0;
					 i=300;
	  		}
	  }
	  if (stop!=5)
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
}
void ticket1(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Avengers: EndGame\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 29-04-2019\n");
        printf("\t                                              Time      : 08:00pm\n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		person[count].id=id2;
        printf("\t============================================================\n");
        return;
}

int movie(void)
{
	int i;
	system("cls");
        printf("===================================================  Screen  ==========================================\n");
        printf("||                                      1.   Avengers: EndGame                                       ||\n");
        printf("||                                      2.   Captain Marvel                                          ||\n");
        printf("||                                      3.   Spider Man: Far From Home                               ||\n");
        printf("||                                      4.   Murbious                                                ||\n");
        printf("||                                      5.   Avatar-1   (2009)                                       ||\n");
        printf("||                                      6.   Avatar-2: The way of water                              ||\n");
        printf("||                                      7.   The Lion King                                           ||\n");
        printf("||                                      8.   The Jungle Book                                         ||\n");
        printf("=======================================================================================================\n");
        printf("Enter the movie you want to book:");
	scanf("%d",&i);

	return i;
}
void ticket2(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Captain Marvel\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 15-04-2019\n");
        printf("\t                                              Time      : 09:00pm\n");
        printf("\t                                              Hall      : 03\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}
int cmovie(void)
{
	int i;
        printf("===================================================  Screen  ==========================================\n");
        printf("||                                      1.   Avengers: EndGame                                       ||\n");
        printf("||                                      2.   Captain Marvel                                          ||\n");
        printf("||                                      3.   Spider Man: Far From Home                               ||\n");
        printf("||                                      4.   Murbious                                                ||\n");
        printf("||                                      5.   Avatar-1   (2009)                                       ||\n");
        printf("||                                      6.   Avatar-2: The way of water                              ||\n");
        printf("||                                      7.   The Lion King                                           ||\n");
        printf("||                                      8.   The Jungle Book                                         ||\n");
        printf("=======================================================================================================\n");
	scanf("%d",&i);
	return i;
}
void ticket3(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Spider-Man: Far From Home \n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 5-07-2019\n");
        printf("\t                                              Time      : 10:00pm\n");
        printf("\t                                              Hall      : 04\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}
