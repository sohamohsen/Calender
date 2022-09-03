#ifndef CALENDAR_H_INCLUDED
#define CALENDAR_H_INCLUDED
//the date struct to enter in the date info
struct date {
    int day_in_date_structure;
    int m;
    int y;
} d;

// Days of the week enum
COORD xy = {0, 0};
enum days_of_the_week {
    sunday=1,monday,tuesday,wednesday,thursday,friday,sutrday
};
//Note struct

struct Notes {
    int  d;
    int m;
    int year;
    char note[100];
};


int check_leapYear( int year ) // True if leap year
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int leapYears( int y ) // The number of leap year from year 0 tell the entered date
{
    return y/4 - y/100 + y/400;
}

int todayOf( int y, int m, int d) /* The number of days_of_the_week since the beginning of the year */
{
    int DayOfMonth[13] =
    { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
    return DayOfMonth[m] + d + ((m>2 && check_leapYear(y))? 1 : 0);
}

long days_of_the_week( int y, int m, int d) // Total number of days
{
    int lastYear;

    lastYear = y - 1;

    return 365L * lastYear + leapYears(lastYear) + todayOf(y,m,d);
}

void calendar(int y, int m) /* display the monthly calendar  */
{
    const char *NameOfMonth[] = { NULL/*dummp*/,
                                  "January", "February", "March", "April", "May", "June",
                                  "July", "August", "September", "October", "November", "December"
                                };
    char Week[] = "      Su Mo Tu We Th Fr Sa";
    int DayOfMonth[13] =
    { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;

    weekOfTopDay = days_of_the_week(y, m, 1) % 7;
    if(check_leapYear(y))
        DayOfMonth[2] = 29;
    printf("\n                %d\n",y);
    printf("     ---------------------------------");
    printf("\n                 %s\n\n%s\n", NameOfMonth[m], Week);
    printf("     ---------------------------------\n");

    for(i=0; i<weekOfTopDay; i++)
        printf("   ");
    printf("      ");
    for(i=weekOfTopDay,day=1; day <= DayOfMonth[m]; i++,day++) {
        printf("%2d ",day);
        if(i % 7 == 6)
            printf("\n      ");
    }
    printf("\n");
    printf("     ---------------------------------\n");
        printf("Enter q ---> exit \nEnter p ---> show Previous month\nEnter n ---> show next month   \n");

}
void increase_month(int *m, int* y)    //increase the month by 1 if user press n
{



    ++*m;
    if (*m==13) {
        ++*y;
        *m=1;
    }



}



void decrement_month(int *m, int* y)                 //decrease the month by 1 if user press p
{



    --*m;
    if (*m==0) {
        --*y;
        *m=12;
    }



}
char *getDay(struct date d)                   //check if the date enterd valid or not
{
    char *pointer[]= {"invalid","valid"};
    int DayOfMonth[] =
    { -1/*dummy*/,31,28,31,30,31,30,31,31,30,31,30,31 };
    if(check_leapYear(d.y)) {
        DayOfMonth[2] = 29;
    }

    if (d.day_in_date_structure>DayOfMonth[d.m]) {
        return pointer[0];

    }

    else {
        return pointer[1];
    }



}
void print_date(struct date d,char* getDay())        //print the name of month of date enterd
{

    if(getDay=="valid") {
        switch(d.m) {
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
        printf("Undefined date");
}

enum days_of_the_week* get_day(enum days_of_the_week dayno)      //print the day namme
{
    char* day[]= {"0","sunday","monday","tuesday","wednesday","thursday","friday","sutrday"};
    enum days_of_the_week *pointer=&dayno;
    return day[(dayno)];
}
char *the_days_of_the_week_in_year[365] = {};            //global array to store notes
int day, month;
void Aday_in_date_structureNote(struct Notes note1)
{
    static int DayOfMonth[] =
    { -1/*dummy*/,0,31,59,90,120,151,181,212,243,273,304,334};
    note1.note[100]=0;
    day = note1.d;
    month = d.m;
    printf("Enter thedate(DD/Month): ");
    scanf("%d%d",&note1.d, &note1.m);
    printf("Enter theNote(100 character max): ");
    fflush(stdin);
    gets(note1.note);
    int x = DayOfMonth[note1.m]+note1.d;

    // scanf(" %c",&note1.note);
    if(note1.note[100]==0) {
        puts("Note is saved sucessfully");

        the_days_of_the_week_in_year[x]=note1.note  ;
    } else {
        puts("\aFail to save!!\a");
        note1.note[0] = '\0';
    }
}
int checkNote(struct date d)
{

    printf ("please enter date of note");
    scanf (" %d %d",&d.day_in_date_structure ,&d.m);
    struct Notes  note1;
    if ((d.day_in_date_structure == day) && (d.m == month))
    {

        return 1;
    }
    else
        return 0;
}
void showNote(int d, int m,struct date d1)    //display all notes in specific month
{
    static int DayOfMonth[] =
    { -1/*dummy*/,0,31,59,90,120,151,181,212,243,273,304,334};
    d1.day_in_date_structure = d;
    d1.m = m ;
    printf ("This is all notes in that month: \n");
    for (int i=DayOfMonth[m] ; i<DayOfMonth[m+1] ; i++ ) {
        if ( the_days_of_the_week_in_year[i]== 0)
            continue;
        printf("your note is: ");
        printf ("%s",the_days_of_the_week_in_year[i]);
    }
}





#endif // CALENDAR_H_INCLUDED
