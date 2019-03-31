#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>


char catagories[][15]={"NOVEL","SCIENCE","MATH","ARCHITECTURE","ADVENTURE"};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void viewbooks(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
//void show_mouse(void);
void Password();
void tryagain();




FILE *fp,*ft,*fs;


COORD coord = {0, 0};

int s;
char findbook;


void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


struct books
{
int id;
char stname[20];
char name[20];
char Author[20];
int quantity;
float Price;
int count;
int rackno;
char *cat;

};
struct books a;
int main()
{

Password();

return 0;

}
void mainmenu()
{

system("cls");

int i;
system("cls");

    gotoxy(28,0);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    printf("\xDB");gotoxy(28,1);

    printf("\xDB***************************");gotoxy(28,2);
    printf("\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");gotoxy(28,3);
    printf("\xDB***************************");gotoxy(28,4);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");gotoxy(28,5);
    printf("\xDB");gotoxy(28,6);
    printf("\xDB 1.ADD BOOK");gotoxy(28,7);
    printf("\xDB");gotoxy(28,8);
    printf("\xDB 2.DELETE BOOK");gotoxy(28,9);
    printf("\xDB");gotoxy(28,10);
    printf("\xDB 3.SEARCH BOOK");gotoxy(28,11);
    printf("\xDB");gotoxy(28,12);
    printf("\xDB 4.VIEW BOOK LIST");gotoxy(28,13);
    printf("\xDB");gotoxy(28,13);
    printf("\xDB");gotoxy(28,14);
    printf("\xDB");gotoxy(28,15);
    printf("\xDB PRESS 5 TO QUIT APP");gotoxy(28,15);
    printf("\xDB");gotoxy(28,16);
    printf("\xDB");gotoxy(28,17);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");



    printf("");gotoxy(56,1);
    printf("\xDB");gotoxy(56,2);
    printf("\xDB");gotoxy(56,3);
    printf("\xDB");gotoxy(56,4);
    printf("\xDB");gotoxy(56,5);
    printf("\xDB");gotoxy(56,6);
    printf("\xDB");gotoxy(56,7);
    printf("\xDB");gotoxy(56,8);
    printf("\xDB");gotoxy(56,9);
    printf("\xDB");gotoxy(56,10);
    printf("\xDB");gotoxy(56,11);
    printf("\xDB");gotoxy(56,12);
    printf("\xDB");gotoxy(56,13);
    printf("\xDB");gotoxy(56,14);
    printf("\xDB");gotoxy(56,15);
    printf("\xDB");gotoxy(56,16);
    printf("\xDB");gotoxy(56,17);
    printf("\xDB");gotoxy(56,18);


    gotoxy(32,19);
    printf("ENTER YOUR CHOICE:");

switch(getch())
{
case '1':
addbooks();
break;
case '2':
deletebooks();
break;
case '3':
searchbooks();
break;
case '4':
viewbooks();
break;
case '5':
{
system("cls");
gotoxy(20,3);
printf("LIBRARY MANAGEMENT SYSTEM");
gotoxy(20,4);
printf("PROJECT IN C\n");
gotoxy(20,5);
printf("THIS BROUGHT TO YOU BY \n\n\t\t    ********* TRIPLE-S ********");
gotoxy(20,6);
Sleep(3000);
exit(0);
getch();
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option");
if(getch())
mainmenu();
}

}
}
void addbooks(void)
{
system("cls");
int i;
gotoxy(20,5);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGOIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 1. NOVEL");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 2. SCIENCE");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 3. MATH ");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 4. ARCHITECTURE");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 5. ADVENTURE");
gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB2 6. BACK TO MAIN MENU");
gotoxy(20,19);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,21);
printf("ENTER YOUR CHOICE:");
scanf("%d",&s);
if(s==6)

mainmenu() ;
system("cls");
fp=fopen("a.c","ab+");
if(getdata()==1)
{
a.cat=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
gotoxy(21,14);
printf("The record is sucessfully saved");
gotoxy(21,15);
printf("Save any more?(Y / N):");
if(getch()=='n')
mainmenu();
else
system("cls");
addbooks();
}
}
void deletebooks()
{
system("cls");
int d;
char another='y';
while(another=='y')
{
system("cls");
gotoxy(10,5);
printf("Enter the Book ID to  delete:");
scanf("%d",&d);
fp=fopen("a.c","rb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{

gotoxy(10,7);
printf("The book record is available");
gotoxy(10,8);
printf("Book name is %s",a.name);
gotoxy(10,9);
printf("Rack No. is %d",a.rackno);
findbook='t';
}
}
if(findbook!='t')
{
gotoxy(10,10);
printf("No record is found modify the search");
if(getch())
mainmenu();
}
if(findbook=='t' )
{
gotoxy(10,9);
printf("Do you want to delete it?(Y/N):");
if(getch()=='y')
{
ft=fopen("test.dat","wb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,ft);
}
}
fclose(ft);
fclose(fp);
remove("a.c");
rename("test.dat","a.c");
fp=fopen("a.c","rb+");
if(findbook=='t')
{
gotoxy(10,10);
printf("The record is sucessfully deleted");
gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else
mainmenu();

}
}
gotoxy(10,15);
mainmenu();
}
void searchbooks()
{
system("cls");
int d;
gotoxy(23,6);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCH BOOKS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(25,8);
printf("\xDB\xDB\xDB\xB2 1. Search By ID  \xB2\xDB\xDB\xDB");
gotoxy(25,10);
printf("\xDB\xDB\xDB\xB2 2. Search By Name\xB2\xDB\xDB\xDB");
gotoxy( 25,12);
printf("Enter Your Choice:");
fp=fopen("a.c","rb+");
rewind(fp);
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("****Search Books By Id****");
gotoxy(20,5);
printf("Enter the book id:");
scanf("%d",&d);
gotoxy(20,7);
printf("Searching........");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
Sleep(2);
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Author:%s ",a.Author);gotoxy(47,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2 Qantity:%d ",a.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2");
gotoxy(20,15);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
findbook='t';
}

}
if(findbook!='t')
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooks();
else
mainmenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("****Search Books By Name****");
gotoxy(20,5);
printf("Enter Book Name:");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0)
{
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Author:%s",a.Author);gotoxy(47,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2 Qantity:%d",a.quantity);gotoxy(47,12);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2");
gotoxy(20,14);
printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2");
gotoxy(20,15);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
d++;
}

}
if(d==0)
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooks();
else
mainmenu();
break;
}
default :
getch();
searchbooks();
}
fclose(fp);
}

void viewbooks(void)
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("*********************************Book List*****************************");
gotoxy(1,3);
printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
j=4;
fp=fopen("a.c","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(3,j);
printf("%s",a.cat);
gotoxy(16,j);
printf("%d",a.id);
gotoxy(22,j);
printf("%s",a.name);
gotoxy(36,j);
printf("%s",a.Author);
gotoxy(50,j);
printf("%d",a.quantity);
gotoxy(57,j);
printf("%.2f",a.Price);
gotoxy(69,j);
printf("%d",a.rackno);
printf("\n\n");
j++;
i=i+a.quantity;
}
gotoxy(3,25);
printf("Total Books =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
}


void returnfunc(void)
{
{
printf(" Press ENTER to return to main menu");
}
a:
if(getch()==13)
mainmenu();
else
goto a;
}
int getdata()
{
int t;
gotoxy(20,3);printf("Enter the Information Below");
gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,5);
printf("\xB2");gotoxy(46,5);printf("\xB2");
gotoxy(20,6);
printf("\xB2");gotoxy(46,6);printf("\xB2");
gotoxy(20,7);
printf("\xB2");gotoxy(46,7);printf("\xB2");
gotoxy(20,8);
printf("\xB2");gotoxy(46,8);printf("\xB2");
gotoxy(20,9);
printf("\xB2");gotoxy(46,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2");gotoxy(46,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2");gotoxy(46,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,5);
printf("Category:");
gotoxy(31,5);
printf("%s",catagories[s-1]);
gotoxy(21,6);
printf("Book ID:\t");
gotoxy(30,6);
scanf("%d",&t);
if(checkid(t) == 0)
{
gotoxy(21,13);
printf("\aThe book id already exists\a");
getch();
mainmenu();
return 0;
}
a.id=t;
gotoxy(21,7);
printf("Book Name:");gotoxy(33,7);
scanf("%s",a.name);
gotoxy(21,8);
printf("Author:");gotoxy(30,8);
scanf("%s",a.Author);
gotoxy(21,9);
printf("Quantity:");gotoxy(31,9);
scanf("%d",&a.quantity);
gotoxy(21,10);
printf("Price:");gotoxy(28,10);
scanf("%f",&a.Price);
gotoxy(21,11);
printf("Rack No:");gotoxy(30,11);
scanf("%d",&a.rackno);
return 1;
}
int checkid(int t)
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;
return 1;
}

void Password()


{

    gotoxy(30,10);
    printf("ENTER YOUR PASSWORD:");

    int jack;
    scanf("%d", &jack);
    if(jack==989898)
    {
     mainmenu();
    }
   else
   {

     tryagain();


   }
}

void tryagain()

{

  system("cls");
  gotoxy(28,10);
  Password();

}







