#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 100

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

void StartMenu()
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

    switch(w)
    {
        case 1:
            NewGame();
            break;

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


int Nov;                                        //// no. of moves
int Dir;                                        //// dots in a row
char Length;

void NewGame()
{
        printf(RED"Choose the difficulty:\n**********************"reset);                           //difficulty
        printf(L_MAG"\nBeginner(enter: 1)\n"reset);
        printf(L_MAG"Semi pro(enter: 2)\n"reset);
        printf(L_MAG"Professional(enter: 3)\n"reset);
        printf(L_MAG"Expert(enter: 4)\n\n"reset);
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
            printf(L_YEL"Choose mode:\n************\n"reset);                                             //#of players
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
                switch(z)
                {
                    case 1:
                        n=5;
                        Nov=12;
                        Dir=3;
                        Length='5';
                        break;
                    case 2:
                        n=7;
                        Nov=24;
                        Dir=4;
                        Length='7';
                        break;
                    case 3:
                        n=9;
                        Nov=40;
                        Dir=5;
                        Length='9';
                        break;
                    case 4:
                        n=11;
                        Nov=60;
                        Dir=6;
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
            }                                                                                   ///
            int turn=1;                                                                         ////
            int score1=0;
            int score2=0;
            int TC1=1;
            int TC2=1;
            int p , k;
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
                if(matrix[x][y]==32 && ((x%2==0 && y%2!=0) || (x%2!=0 && y%2==0)))
                {
                    Nov--;
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

                        for(p=1;p<=Dir;p+=2)
                        {
                            for(k=1;k<=Dir;k+=2)
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
                                            }

                                       }
                                       else if(turn==2)
                                       {
                                           if(matrix[p][k]!=219)
                                            {
                                                score2++;
                                                matrix[p][k]=219;
                                                c2[p][k]=219;
                                            }
                                       }
                                    }
                                }
                        }

                    if (turn==1)
                        turn=2;
                    else if(turn==2)
                        turn=1;
                }
                system("cls");
                int i,j;
                for( i=0;i<n;i++)
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
            }
        }
}




int main()
{
    system("COLOR");
    StartMenu();


    return 0;
}
