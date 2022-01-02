#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 100
#include<time.h>
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define L_BLK "\e[1;30m"
#define L_RED "\e[1;31m"
#define L_GRN "\e[1;32m"
#define L_YEL "\e[1;33m"
#define L_BLU "\e[1;34m"
#define L_MAG "\e[1;35m"
#define L_CYN "\e[1;36m"
#define L_WHT "\e[1;37m"
#define reset "\e[0m"

int w;
char ww[N];

void StartMenu()                        // The StartMenu fn. contains the first interface and it leads u to the other fns. according to your choice
{
    printf(YEL"\t\t\t\t\t    *Welcome*\n"reset);
    printf(YEL"\t\t\t\t\t    *********\n"reset);
    printf(YEL"\t\t\t\t\t*Dots and Boxes*\n"reset);
    printf(YEL"\t\t\t\t\t****************\n"reset);

    printf(L_BLU"New Game(enter: 1)\n"reset);
    printf(L_BLU"Load Game(enter: 2)\n"reset);
    printf(L_BLU"Hall Of Fame(enter: 3)\n"reset);
    printf(L_BLU"Credits(enter: 4)\n"reset);
    printf(L_BLU"Exit Game(enter: 5)\n\n"reset);
    printf("Enter your choice:");
    scanf("%s",&ww);

    while (1)                                                  //checking that the input is valid
    {
        if((ww[0]=='1' || ww[0]=='2' || ww[0]=='3' || ww[0]=='4' || ww[0]=='5')&& ww[1]=='\0')
            {
                w=ww[0]-'0';
                break;
            }
        else
        {
            printf("Enter a valid choice:");
            scanf("%s",&ww);
        }
    }
    system("cls");

    switch(w)                                               // this statement is the one which lead u to the other fns. according to your choice.
    {
        case 1:
            NewGame();
            break;
        case 5:
            return 0;

    }
}
int z;
char zz[N];
int r;
char rr[N];
int n;
int matrix[N][N];
char xx[N];
int x;
char yy[N];
int y;
int c1[N][N];
int c2[N][N];
char Name1[N];
char Name2[N];
char Name3[N]={'C','o','m','p','u','t','e','r','\0'};


int Nov;                                    //// no. of moves
int RL;                                      ////remaining lines
int BC;                                        //// boxes co-ordinates
char Length;                                   //// refers to the max row and col place that the user could use < it

int turn;
int score1;
int score2;
int counter1;
int counter2;
clock_t t1,t2,t3;
int seconds=0;minutes=0,hours=0;
void NewGame()
{
        printf(RED"Choose the difficulty:\n**********************"reset);                           //difficulty
        printf(L_CYN"\nBeginner(enter: 1)\n"reset);
        printf(L_CYN"Semi pro(enter: 2)\n"reset);
        printf(L_CYN"Professional(enter: 3)\n"reset);
        printf(L_CYN"Expert(enter: 4)\n\n"reset);
        printf("Enter 0 to return to the main menu\n\n");
        printf("Enter your choice:");
        scanf("%s",&zz);
        while(1)
        {
            if ((zz[0]=='1' || zz[0]=='2' || zz[0]=='3' || zz[0]=='4' || zz[0]=='0')&& zz[1]=='\0')
                {
                    z=zz[0]-'0';
                    break;
                }
            else
            {
                printf("Enter a valid choice");
                scanf("%s",&zz);
            }
        }
        if(z==0)
        {
            system("cls");
            StartMenu();
        }
        else
        {
            system("cls");
            printf(YEL"Choose mode:\n************\n"reset);                                             //#of players
            printf(L_GRN"One player mode(enter: 1)\n"reset);
            printf(L_GRN"Two player mode(enter: 2)\n\n"reset);
            printf("Enter 0 to return to the main menu\n\n");
            printf("Enter your choice:");
            scanf("%s",&rr);
            while (1)                                               //checking
            {
                if ((rr[0]=='1' || rr[0]=='2' || rr[0]=='0')&&rr[1]=='\0')
                {
                        r=rr[0]-'0';
                        break;
                }
                else
                {
                    printf("Enter a valid choice:");
                    scanf("%s",&rr);
                }
            }
            if(r==0)
            {
                system("cls");
                StartMenu();
            }
            else
            {
                system("cls");
                if(r==1)                                                                            //taking names
                {
                    fflush(stdin);
                    printf(L_RED"Enter your Name:"reset);
                    gets(Name1);
                    while(1)                                                                        //checking them
                    {
                        if(Name1[0]=='\0')
                           {
                                printf(L_RED"Enter your Name:"reset);
                                gets(Name1);
                           }
                        else
                            break;
                    }

                }
                else if (r==2)                                                                          //taking names
                {
                    fflush(stdin);
                    printf(L_RED"Enter player one Name:"reset);
                    gets(Name1);
                    while(1)                                                                            //checking them
                    {
                        if(Name1[0]=='\0')
                           {
                                printf(L_RED"Enter your Name:"reset);
                                gets(Name1);
                           }
                        else
                            break;
                    }
                    printf(L_RED"Enter player two Name:"reset);
                    gets(Name2);
                    while(1)
                    {
                        if(Name2[0]=='\0')
                           {
                                printf(L_RED"Enter your Name:"reset);
                                gets(Name2);
                           }
                        else
                            break;
                    }
                }






                a:                          //// the redo point
                turn=1;
                score1=0;
                score2=0;
                counter1=0;
                counter2=0;
                system("cls");
                switch(z)
                {
                    case 1:
                        n=5;
                        Nov=12;
                        RL=12;
                        BC=3;
                        Length='5';
                        break;
                    case 2:
                        n=7;
                        Nov=24;
                        RL=24;
                        BC=5;
                        Length='7';
                        break;
                    case 3:
                        n=9;
                        Nov=40;
                        RL=40;
                        BC=7;
                        Length='9';
                        break;
                    case 4:
                        n=11;
                        Nov=60;
                        RL=60;
                        BC=9;
                        Length='11';
                        break;
                }
                matrix[n][n];

                int i , j;
                for( i=0;i<n;i++)
                {
                   printf("%d ",i);
                }
                printf("\n");

                for (i=0;i <n;i++)
                {
                    for ( j=0;j <n;j++)
                    {
                        if((i%2==0)&&(j%2==0))
                        {
                            //(even,even)
                            matrix[i][j]=254;
                            printf("%c",matrix[i][j]);
                        }
                        else if((i%2!=0)&&(j%2!=0))
                        {
                            matrix[i][j]=32;
                            printf(" %c ",matrix[i][j]);
                        }
                        else if((i%2==0)&&(j%2!=0))
                        {
                            matrix[i][j]=32;
                            printf("%c%c%c",matrix[i][j],matrix[i][j],matrix[i][j]);
                        }
                        else if((i%2!=0)&&(j%2==0))
                        {
                            matrix[i][j]=32;
                            printf("%c",matrix[i][j]);
                        }
                        c1[i][j]=-1;
                        c2[i][j]=-1;
                    }
                printf(" %d",i);
                printf("\n");
                }
                printf("\n\n");
                printf(RED);
                printf("Player 1 Name: %s",Name1);
                printf(reset);
                printf(L_GRN);
                if (r==1)
                    printf("\t\t\tPlayer 2 Name: %s",Name3);
                else if(r==2)
                    printf("\t\t\tPlayer 2 Name: %s",Name2);
                printf(reset);
                printf(RED);
                printf("\n\nPlayer 1 Score: %d",score1);
                printf(reset);
                printf(L_GRN);
                printf("\t\t\tPlayer 2 Score: %d",score2);
                printf(reset);
                printf(RED);
                printf("\n\nPlayer 1 # of moves: %d",counter1);
                printf(reset);
                printf(L_GRN);
                printf("\t\t\tPlayer 2 # of moves: %d",counter2);
                printf(reset);
                printf(L_BLU);
                printf("\n\n# of remaining lines: %d",RL);
                printf("\t\tTime passed : 0:0:0);

                printf(reset);
                printf(L_BLU);
                printf("\n\nPlayer Turn: %d",turn);
                printf(reset);
                printf(L_YEL);
                printf("\n\nEnter (0,0) for Start Menu");
                printf("\nEnter (1,1) for EXIT");
                printf("\nEnter (2,2) for REDO");
                printf(reset);


            }

            int TC1=0;
            int TC2=0;
            int p , k;
            clock_t t1=clock();
            while(Nov)
            {
                printf("\n\n\nEnter Row no. :");
                scanf("%s",&xx);
                while(1)
                {
                    if(xx[0]>='0' && xx[0]<Length &&xx[1]=='\0')           //////////// under exec.
                    {
                        x=xx[0]-'0';
                        break;
                    }
                    scanf("%s",&xx);
                }
                printf("Enter col no. :");
                scanf("%s",&yy);
                while(1)
                {
                    if(yy[0]>='0' && yy[0]<Length &&yy[1]=='\0')
                    {
                        y=yy[0]-'0';
                        break;
                    }
                    scanf("%s",&yy);
                }
               clock_t t2=clock();

                if(x==0 && y==0)        //for StartMenu
                {
                    system("cls");
                    StartMenu();
                }
                else if(x==1 && y==1)        // for exit
                {
                        system("cls");
                        return 0;
                }
                else if(x==2 && y==2)     //for redo
                    goto a;
               // else if(x==3 && y==3)  for undo



                else if(matrix[x][y]==32 && ((x%2==0 && y%2!=0) || (x%2!=0 && y%2==0)))
                {
                    Nov--;
                    RL=Nov;
                    if((x%2==0) && (y%2!=0))
                    {
                        if(turn==1)
                            c1[x][y]=205;
                        if(turn==2)
                            c2[x][y]=205;

                        matrix[x][y]=205;
                    }
                    else if((x%2!=0) && (y%2==0))
                    {
                        if(turn==1)
                            c1[x][y]=186;
                        if(turn==2)
                            c2[x][y]=186;

                        matrix[x][y]=186;
                    }


                        for(p=1;p<=BC;p+=2)
                        {
                            for(k=1;k<=BC;k+=2)
                                {
                                    if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                    {
                                       if(turn==1)
                                       {
                                           if(matrix[p][k]!=219)
                                            {
                                                score1++;
                                                matrix[p][k]=219;
                                                c1[p][k]=219;
                                                TC1++;
                                            }

                                       }
                                       else if(turn==2)
                                       {
                                           if(matrix[p][k]!=219)
                                            {
                                                score2++;
                                                matrix[p][k]=219;
                                                c2[p][k]=219;
                                                TC2++;
                                            }
                                        }
                                    }
                                }
                        }


                    if(TC1==1 || TC1==2)
                        {
                            turn=2;
                            counter2--;
                            counter1++;
                        }
                    else if(TC2==1 || TC2==2)
                        {
                            turn=1;
                            counter1--;
                            counter2++;
                        }

                    TC1=0;
                    TC2=0;

                    if (turn==1)
                    {
                        counter1++;
                        turn=2;
                    }

                    else if(turn==2)
                    {
                        counter2++;
                        turn=1;
                    }

                }
                system("cls");
                int i,j;
                for(i=0;i<n;i++)
                {
                   printf("%d ",i);
                }
                printf("\n");

                for (i=0;i <n;i++)
                {
                    for ( j=0;j <n;j++)            //////////////////
                    {
                        if((i%2==0)&&(j%2==0))
                        {
                            //(even,even)
                            printf("%c",matrix[i][j]);
                        }
                        else if((i%2!=0)&&(j%2!=0))
                        {
                            if(matrix[i][j]==c1[i][j])
                            {
                                printf(RED);
                                printf("%c%c%c",matrix[i][j],matrix[i][j],matrix[i][j]);
                                printf(reset);
                            }
                            else if (matrix[i][j]==c2[i][j])
                            {
                                printf(GRN);
                                printf("%c%c%c",matrix[i][j],matrix[i][j],matrix[i][j]);
                                printf(reset);
                            }
                            else
                                printf(" %c ",matrix[i][j]);
                        }

                        else if((i%2==0)&&(j%2!=0))
                        {
                            if(matrix[i][j]==c1[i][j])
                            {
                                printf(RED);
                                printf("%c%c%c",matrix[i][j],matrix[i][j],matrix[i][j]);
                                printf(reset);
                            }
                            else if(matrix[i][j]==c2[i][j])
                            {
                                printf(GRN);
                                printf("%c%c%c",matrix[i][j],matrix[i][j],matrix[i][j]);
                                printf(reset);
                            }
                            else
                            {
                                printf("%c%c%c",matrix[i][j],matrix[i][j],matrix[i][j]);
                            }
                        }
                        else if((i%2!=0)&&(j%2==0))
                        {
                            if(matrix[i][j]==c1[i][j])
                            {
                                printf(RED);
                                printf("%c",matrix[i][j]);
                                printf(reset);
                            }
                            else if(matrix[i][j]==c2[i][j])
                            {
                                printf(GRN);
                                printf("%c",matrix[i][j]);
                                printf(reset);
                            }
                            else
                            {
                                printf("%c",matrix[i][j]);
                            }
                        }
                    }
                printf(" %d",i);
                printf("\n");
                }
                printf("\n\n");
                printf(RED);
                printf("Player 1 Name: %s",Name1);
                printf(reset);
                printf(L_GRN);
                if (r==1)
                    printf("\t\t\tPlayer 2 Name: %s",Name3);
                else if(r==2)
                    printf("\t\t\tPlayer 2 Name: %s",Name2);
                printf(reset);
                printf(RED);
                printf("\n\nPlayer 1 Score: %d",score1);
                printf(reset);
                printf(L_GRN);
                printf("\t\t\tPlayer 2 Score: %d",score2);
                printf(reset);
                printf(RED);
                printf("\n\nPlayer 1 # of moves: %d",counter1);
                printf(reset);
                printf(L_GRN);
                printf("\t\t\tPlayer 2 # of moves: %d",counter2);
                printf(reset);
                printf(L_BLU);
                printf("\n\n# of remaining lines: %d",RL);
                printf(reset);
                printf(L_BLU);
                clock_t t3=(t2-t1)/CLOCKS_PER_SEC;
                minutes=t3/60;
                seconds=t3%60;
                if (minutes >= 60)
                 {
                 hours = minutes / 60;
                 minutes = minutes % 60;
                 }
                printf("\t\tTime passed : %d:%d:%d",hours,minutes,seconds);

                printf("\n\nEnter (0,0) for Start Menu");
                printf("\nEnter (1,1) for EXIT");
                printf("\nEnter (2,2) for REDO");
                printf(reset);

                printf(L_BLU);
                printf("\n\nPlayer Turn: %d",turn);
                printf(reset);
                printf(L_YEL);



            }
            printf(L_MAG);
            if(score1>score2)
                printf("\n\nThe Winner is: %s",Name1);
            else if(score1<score2)
                {
                if(r==1)
                    printf("\n\nThe Winner is: %s",Name3);
                else if(r==2)
                    printf("\n\nThe Winner is: %s",Name2);
                }
            else if(score1==score2)
                printf("\n\nDraw");
            printf(reset);
        }


}


int main()
{
    system("COLOR");
    StartMenu();
    return 0;
}
