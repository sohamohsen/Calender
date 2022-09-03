#include <stdio.h>
#include "calendar.h"
                                                //the struct of date

struct date
{
    int dd;
    int m;
    int y;
} d;

                                        // Days of the week enum (we should use it

enum days
{
    sunday=1,monday,tuesday,wednesday,thursday,friday,sutrday
};
//Note struct

struct Notes
{
    int  d;
    int m;
    int year;
    char note[100];
} note1;


 int check_leapYear( int year ) /* True if leap year */
        {
            return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
        }

        int leapYears( int y ) /* The number of leap year */
        {
            return y/4 - y/100 + y/400;
        }

        int todayOf( int y, int m, int d) /* The number of days since the beginning of the year */
        {
            static int DayOfMonth[] =
            { -1/*dummy*/,0,31,59,90,120,151,181,212,243,273,304,334};

            return DayOfMonth[m] + d + ((m>2 && check_leapYear(y))? 1 : 0);
        }

        long days( int y, int m, int d) /* Total number of days */
        {
            int lastYear;

            lastYear = y - 1;

            return 365L * lastYear + leapYears(lastYear) + todayOf(y,m,d);
        }

        void calendar(int y, int m) /* display calendar at m y */
        {
            const char *NameOfMonth[] = { NULL/*dummp*/,
                                          "January", "February", "March", "April", "May", "June",
                                          "July", "August", "September", "October", "November", "December"
                                        };
            char Week[] = "      Su Mo Tu We Th Fr Sa";
            int DayOfMonth[13] =
            { -1/*dummy*/,31,28,31,30,31,30,31,31,30,31,30,31 };
            int weekOfTopDay;
            int i,day;

            weekOfTopDay = days(y, m, 1) % 7;
            if(check_leapYear(y))
                DayOfMonth[2] = 29;
            printf("\n                %d\n",y);
            printf("     ---------------------------------");
            printf("\n                 %s\n\n%s\n", NameOfMonth[m], Week);
            printf("     ---------------------------------\n");

            for(i=0; i<weekOfTopDay; i++)
                printf("   ");
            printf("      ");
            for(i=weekOfTopDay,day=1; day <= DayOfMonth[m]; i++,day++)
            {
                printf("%2d ",day);
                if(i % 7 == 6)
                    printf("\n      ");
            }
            printf("\n");
            printf("     ---------------------------------\n");
        }
       void increase_month(int *m, int* y)
{



    ++*m;
    if (*m==13)
    {
        ++*y;
        *m=1;
    }



}



void decrement_month(int *m, int* y)
{



    --*m;
    if (*m==0)
    {
        --*y;
        *m=12;
    }



}
        char *getDay(struct date d)
        {
            char *pointer[]= {"invalid","valid"};
            int DayOfMonth[] =
            { -1/*dummy*/,31,28,31,30,31,30,31,31,30,31,30,31 };
            if(check_leapYear(d.y))
            {
                DayOfMonth[2] = 29;
            }

            if (d.dd>DayOfMonth[d.m])
            {
                return pointer[0];

            }

            else
            {
                return pointer[1];
            }



        }
        void print_date(struct date d,char* getDay())
        {

            if(getDay=="valid")
            {
                switch(d.m)
                {
                case 1:
                    printf ("January");
                    break;
                case 2:
                    printf ("February");
                    break;
                case 3:
                    printf ("March");
                    break;
                case 4:
                    printf ("April");
                    break;
                case 5:
                    printf ("May");
                    break;
                case 6:
                    printf ("June");
                    break;
                case 7:
                    printf ("July");
                    break;
                case 8:
                    printf ("August");
                    break;
                case 9:
                    printf ("September");
                    break;
                case 10:
                    printf ("October");
                    break;
                case 11:
                    printf ("November");
                    break;
                case 12:
                    printf ("December");
                    break;

                }
            }

            else
                printf("Wrong date");
        }

        enum days* get_day(enum days dayno){
    char* day[]={"0","sunday","monday","tuesday","wednesday","thursday","friday","sutrday"};
  enum days *pointer=&dayno;
    return day[(dayno)];
}
void AddNote(struct Notes bee)
{
    bee.note[100]=0;
    printf("Enter thedate(DD/MM): ");
    scanf("%d%d",&bee.d, &bee.m);
    printf("Enter theNote(100 character max): ");
    fflush(stdin);
    gets(bee.note);
    // scanf(" %c",&bee.note);
    if(bee.note[100]==0)
    {
        puts("Note is saved sucessfully");
    }
    else
    {
        puts("\aFail to save!!\a");
        bee.note[0] = '\0';
    }
    printf("Press any key............");
}
