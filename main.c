#include <stdio.h>
#include<conio.h>
#include<windows.h>
#include "calendar.h"



//Main function

int main()
{
    struct date d;
    struct Notes note1;

    SetConsoleTitle("Calender Project ");

    int year, month, day;
    int *ptr_m = &month;
    int *ptr_y = &year;
    char b;
    int choice=1, ch;
    printf("Please, select option\n");
    while(1)                                                                //the list in the main window
    {
        printf("\n\n 1 - Find Out the Day on the week \n");
        printf("\n 2 - Print all the day of month\n");
        printf("\n 3 - Show the month of specific date \n");
        printf("\n 4 - Add a note \n");
        printf("\n 5 - Show notes of specific date \n");
        printf("\n 6 - Exit  \n");
        printf("\n  * ENTER YOUR CHOICE : ");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
        case 1:                                                             //switching the choice user enter

            printf("Enter the day");
            int dayno;
            scanf("%d", &dayno);
            printf("%s", get_day(dayno));
            break;

        case 2 :
            printf("Enter month and year (Month Year) : ");
            scanf("%d %d", &month, &year);

            system("cls");
            while(ch!='q')
            {
                calendar(year, month);
                ch = getch();
                if(ch == 'n')
                {
                    if(month<=12 && month>=1)
                    {
                        increase_month(&month, &year);
                        calendar(year, month);
                    }
                    else
                    {
                        year++;
                        month=1;
                    }
                    system("cls");

                }
                else if(ch == 'p')
                {
                    if(month<=12 && month>=1)
                    {
                        decrement_month(&month, &year);
                        calendar(year, month);

                    }

                    else
                    {
                        year--;
                        month=12;
                    }
                    system("cls");
                }
            }
            break;

        case 3:
            printf("Enter the day, month and year: ");
            scanf("%d %d %d", &day, &month, &year);
            d.day_in_date_structure=day;
            d.m=month;
            d.y=year;
            print_date(d, getDay(d));
            break;
        case 4:
        {
            int m, y;
            Aday_in_date_structureNote ( note1);
            break;
        }
        case 5:
            {
                printf("Enter the day, month :  "  " ");
            scanf("  %d %d ", &day, &month);
             showNote(day, month,d);
            }

        case 6:
            exit(0);
        }
    }

    return 0;
}


