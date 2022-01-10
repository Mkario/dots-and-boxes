#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define N 100
#include<time.h>
#define BLK "\e[0;30m"                              //defining colors
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


int winner;
int w;
char ww[N];
int sama;
int StartMenu()                        // The StartMenu fn. contains the first interface and it leads u to the other fns. according to your choice
{
    printf(YEL"\t\t\t\t\t    *Welcome*\n"reset);
    printf(YEL"\t\t\t\t\t    *********\n"reset);
    printf(YEL"\t\t\t\t\t*Dots and Boxes*\n"reset);
    printf(YEL"\t\t\t\t\t****************\n"reset);

    printf(L_BLU"New Game(enter: 1)\n"reset);
    printf(L_BLU"Load Game(enter: 2)\n"reset);
    printf(L_BLU"Hall Of Fame(enter: 3)\n"reset);
    printf(L_BLU"Exit Game(enter: 4)\n\n"reset);
    printf("Enter your choice:");
    scanf("%s",ww);

    while (1)                                                  //checking that the input is valid
    {
        if((ww[0]=='1' || ww[0]=='2' || ww[0]=='3' || ww[0]=='4')&& ww[1]=='\0')
            {
                w=ww[0]-'0';
                break;
            }
        else
        {
            printf("Enter a valid choice:");
            scanf("%s",ww);
        }
    }
    system("cls");

    switch(w)                                               // this statement is the one which lead u to the other fns. according to your choice.
    {
        case 1:
            NewGame();
            break;

        case 4:
            return 0;
            break;
        case 2:
                sama=2;save();LoadGame();
                break;
        case 3:
               printingfam();
               int qs;
               printf("\nreturn to start menu press 0 :");
               scanf("%d",&qs);
               while(1)                                     //checking the validity of the input
               {
                if(qs==0)
                {
                    system("cls");
                    StartMenu();
                    break;
                }
                else
                {
                    printf("return to start menu press 0 :");
                    scanf("%d",&qs);
                }
                }
                break;
    }
}
int z;
char zz[N];
int r;
char rr[N];
int n;
int matrix[N][N];                                       //// the main matrix that will be printed
char xx[N];
int x;
char yy[N];
int y;
int c1[N][N];                                                   //// matrix that contain the moves of player 1
int c2[N][N];                                                   //// matrix that contain the moves of player 2
char Name1[N];
char Name2[N];
char Name3[N]={'C','o','m','p','u','t','e','r','\0'};


int Nov;                                        //// no. of moves
int Nob;                                        //// no. of boxes
int RL;                                         ////remaining lines
int BC;                                         //// boxes co-ordinates

int URA[N][4];                                 //// array that contain the co-ordinates of the inputs + whose turn + the move score
int sc1;                                        //// to modify the score of player 1 inside the redo undo process
int sc2;                                        //// to modify the score of player 2 inside the redo undo process

int turn;
int score1;                                 //// score of player 1
int score2;                                 //// score of player 2
int index1;
int index2;
int counter1;                               //// # of moves for player 1
int counter2;                               //// # of moves for player 2
int totalmoves;                             //// total played moves
clock_t t1,t2,t3;
int seconds=0;minutes=0,hours=0;

int count;                              //// some variables to check the validity of undo redo process
int flagCount;                          //// some variables to check the validity of undo redo process
int playsCount;                         //// some variables to check the validity of undo redo process
int TC1;                                //// variable to check the turn after winning a box for player 1
int TC2;                                //// variable to check the turn after winning a box for player 2
int p , k;                              //// some variables to check the validity of undo redo process
int flag;                               //// some variables to check the validity of undo redo process
int Miki , Tao;                         //// some variables to check the validity of undo redo process

void NewGame()
{
        printf(RED"Choose the difficulty:\n**********************"reset);                           //difficulty
        printf(L_CYN"\nBeginner(enter: 1)\n"reset);
        printf(L_CYN"Semi pro(enter: 2)\n"reset);
        printf(L_CYN"Professional(enter: 3)\n"reset);
        printf(L_CYN"Expert(enter: 4)\n\n"reset);
        printf("Enter 0 to return to the main menu\n\n");
        printf("Enter your choice:");
        scanf("%s",zz);
        while(1)                                                                    //// checking the validity of the input
        {
            if ((zz[0]=='1' || zz[0]=='2' || zz[0]=='3' || zz[0]=='4' || zz[0]=='0')&& zz[1]=='\0')
                {
                    z=zz[0]-'0';
                    break;
                }
            else
            {
                printf("Enter a valid choice");
                scanf("%s",zz);
            }
        }
        if(z==0)
        {
            system("cls");
            int xxx=StartMenu();
            if(xxx==0)
                return 0;
        }
        else
        {
            system("cls");
            printf(YEL"Choose mode:\n************\n"reset);                                             //#of players
            printf(L_GRN"One player mode(enter: 1)\n"reset);
            printf(L_GRN"Two player mode(enter: 2)\n\n"reset);
            printf("Enter your choice:");
            scanf("%s",rr);
            while (1)                                               //checking
            {
                if ((rr[0]=='1' || rr[0]=='2' )&&rr[1]=='\0')
                {
                        r=rr[0]-'0';
                        break;
                }
                else
                {
                    printf("Enter a valid choice:");
                    scanf("%s",rr);
                }
            }

            if((r==1)||(r==2))
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


                turn=1;
                score1=0;
                score2=0;
                sc1=0;
                sc2=0;
                counter1=0;
                counter2=0;
                totalmoves=0;
                system("cls");
                switch(z)           // initializing some important stuff for the game depending on the difficulty
                {
                    case 1:
                        n=5;
                        Nov=12;
                        RL=12;
                        BC=3;
                        break;
                    case 2:
                        n=7;
                        Nov=24;
                        RL=24;
                        BC=5;
                        break;
                    case 3:
                        n=9;
                        Nov=40;
                        RL=40;
                        BC=7;
                        break;
                    case 4:
                        n=11;
                        Nov=60;
                        RL=60;
                        BC=9;
                        break;
                }
                matrix[n][n];               //this part for initializing the grid

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
                        if((i%2==0)&&(j%2==0))      //(even,even) the dots
                        {
                            matrix[i][j]=254;
                            printf("%c",matrix[i][j]);
                        }
                        else if((i%2!=0)&&(j%2!=0))         //(odd,odd) the boxes place
                        {
                            matrix[i][j]=32;
                            printf(" %c ",matrix[i][j]);
                        }
                        else if((i%2==0)&&(j%2!=0))         //(even,odd) the horizontal line place
                        {
                            matrix[i][j]=32;
                            printf("%c%c%c",matrix[i][j],matrix[i][j],matrix[i][j]);
                        }
                        else if((i%2!=0)&&(j%2==0))         //(odd,even) the vertical line place
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
                printf(reset);
                printf(L_BLU);
                printf("\n\nPlayer Turn: %d",turn);
                printf(reset);
                printf(L_BLU);
                printf("\n\nTime passed : %d:%d:%d",hours,minutes,seconds);
                printf(reset);
                printf(L_YEL);
                printf("\n\nEnter (0,0) for Start Menu");
                printf("\tEnter (1,1) for Undo");
                printf("\tEnter (2,2) for Redo");
                printf("\tEnter (3,3) for Save");
                printf(reset);

            }
            count=0;
            flagCount=0;
            playsCount=0;
            TC1=0;
            TC2=0;
            flag=0;

            clock_t t1=clock();

            while(RL)           /////the game loop
            {
                if(r==1)                   // one player mode.
                {
                    if(turn==1)
                    {
                        printf("\n\n\nEnter Row no. :");                //taking the inputs from the user for the coordinates of the line

                        fgets(xx,99,stdin);
                        while(1)
                        {
                            if(z==4 && xx[0]=='1' && xx[1]=='0')
                            {
                               if(xx[3]!='\0')
                                    fgets(xx,99,stdin);
                                else
                                    break;
                            }
                            else
                            {
                                if(xx[2]!='\0')
                                    fgets(xx,99,stdin);
                                else
                                    break;
                            }

                        }
                        if(z==4 && xx[0]=='1' && xx[1]=='0')
                            x=10;
                        else
                            x=xx[0]-'0';


                        printf("Enter col no. :");

                        fgets(yy,99,stdin);
                         while(1)
                        {
                            if(z==4 && yy[0]=='1' && yy[1]=='0')
                            {
                               if(yy[3]!='\0')
                                    fgets(yy,99,stdin);
                                else
                                    break;
                            }
                            else
                            {
                                if(yy[2]!='\0')
                                    fgets(yy,99,stdin);
                                else
                                    break;
                            }

                        }
                        if(z==4 && yy[0]=='1' && yy[1]=='0')
                            y=10;
                        else
                            y=yy[0]-'0';


                    }
                    else if(turn==2)                //computer turn
                    {

                        x=-1;
                        y=-1;
                        for(index1=0;index1<n;index1++)
                        {
                            for(index2=0;index2<n;index2++)
                            {
                                if( matrix[index1][index2]==32 && ((index1%2==0 && index2%2!=0) || (index1%2!=0 && index2%2==0)))
                                {
                                    x=index1;
                                    y=index2;
                                    break;
                                }
                            }
                        }
                    }
                }
                else if(r==2)                   // 2 players mode
                {
                        printf("\n\n\nEnter Row no. :");            //taking the inputs from the user for the coordinates of the line

                        fgets(xx,99,stdin);
                        while(1)
                        {
                            if(z==4 && xx[0]=='1' && xx[1]=='0')
                            {
                               if(xx[3]!='\0')
                                    fgets(xx,99,stdin);
                                else
                                    break;
                            }
                            else
                            {
                                if(xx[2]!='\0')
                                    fgets(xx,99,stdin);
                                else
                                    break;
                            }

                        }
                        if(z==4 && xx[0]=='1' && xx[1]=='0')
                            x=10;
                        else
                            x=xx[0]-'0';


                        printf("Enter col no. :");

                        fgets(yy,99,stdin);
                         while(1)
                        {
                            if(z==4 && yy[0]=='1' && yy[1]=='0')
                            {
                               if(yy[3]!='\0')
                                    fgets(yy,99,stdin);
                                else
                                    break;
                            }
                            else
                            {
                                if(yy[2]!='\0')
                                    fgets(yy,99,stdin);
                                else
                                    break;
                            }

                        }
                        if(z==4 && yy[0]=='1' && yy[1]=='0')
                            y=10;
                        else
                            y=yy[0]-'0';


                }
               clock_t t2=clock();
                if(x==3 && y==3)
                {
                    sama=1;
                    save();
                }
                else if(x==0 && y==0)            //start menu
                {
                    system("cls");
                    int xxxxxx=StartMenu();
                        if(xxxxxx==0)
                            return 0;
                }
                else if(r==2)                    // 2 players mode
                {
                    if(x==1 && y==1)               //undo
                    {
                        if((flagCount>0 || flag==1)&& playsCount>0 && totalmoves>=0)
                        {

                            playsCount--;            //checking the moves that that undo could have
                            totalmoves--;           // the index counter of the array of moves
                            flag=0;                 // to check the undo process is right or not



                                    RL++;
                                    turn=URA[totalmoves][2];
                                    Miki=URA[totalmoves][0];
                                    Tao=URA[totalmoves][1];

                                    if(URA[totalmoves][2]==1)
                                    {
                                        c1[Miki][Tao]=32;
                                        matrix[Miki][Tao]=32;
                                        counter1--;
                                    }
                                    else if(URA[totalmoves][2]==2)
                                    {
                                        c2[Miki][Tao]=32;
                                        matrix[Miki][Tao]=32;
                                        counter2--;
                                    }

                                    count++;
                                    flagCount= count;

                                    for(p=1;p<=BC;p+=2)
                                        for(k=1;k<=BC;k+=2)
                                            {
                                                matrix[p][k]=32;
                                                score1=0;
                                                score2=0;
                                            }

                                    for(p=1;p<=BC;p+=2)
                                    {
                                        for(k=1;k<=BC;k+=2)
                                        {
                                                if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                                {
                                                    if(matrix[p][k]!=219)
                                                    {
                                                        matrix[p][k]=219;
                                                        if(matrix[p][k]==c1[p][k])
                                                        {
                                                            score1++;
                                                        }
                                                        else if(matrix[p][k]==c2[p][k])
                                                        {
                                                            score2++;
                                                        }
                                                    }
                                                }
                                        }
                                    }
                        }
                    }


                    else if(x==2 && y==2)               //redo
                    {
                        if(count!=0)
                        {
                            playsCount++;
                            flag=1;
                            RL--;
                            flagCount=0;
                            turn=URA[totalmoves][2];
                            Miki=URA[totalmoves][0];
                            Tao=URA[totalmoves][1];
                            if(Miki%2==0 && Tao%2!=0)               //// horizontal
                            {
                                if(URA[totalmoves][2]==1)
                                {
                                    c1[Miki][Tao]=205;
                                    matrix[Miki][Tao]=205;
                                    counter1++;
                                    turn=2;
                                    if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                        turn=1;
                                }
                                else if(URA[totalmoves][2]==2)
                                {
                                    c2[Miki][Tao]=205;
                                    matrix[Miki][Tao]=205;
                                    counter2++;
                                    turn=1;
                                    if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                        turn=2;
                                }

                            }
                            else if(Miki%2!=0 && Tao%2==0)          ////vertical
                            {
                                if(URA[totalmoves][2]==1)
                                {
                                    c1[Miki][Tao]=186;
                                    matrix[Miki][Tao]=186;
                                    counter1++;
                                    turn=2;
                                    if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                        turn=1;
                                }
                                else if(URA[totalmoves][2]==2)
                                {
                                    c2[Miki][Tao]=186;
                                    matrix[Miki][Tao]=186;
                                    counter2++;
                                    turn=1;
                                    if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                        turn=2;
                                }

                            }
                            for(p=1;p<=BC;p+=2)
                                {
                                    for(k=1;k<=BC;k+=2)
                                        {
                                            if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                            {
                                               if(URA[totalmoves][2]==1)
                                               {
                                                   if(matrix[p][k]!=219)
                                                    {
                                                        score1++;
                                                        matrix[p][k]=219;
                                                        c1[p][k]=219;
                                                    }

                                               }
                                               else if(URA[totalmoves][2]==2)
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
                                count--;
                                totalmoves++;
                       }
                    }


                    else if(matrix[x][y]==32 && ((x%2==0 && y%2!=0) || (x%2!=0 && y%2==0)))     // a play was played
                    {
                        count=0;
                        flagCount=0;
                        playsCount++;
                        flag=1;
                        RL--;
                        if((x%2==0) && (y%2!=0))                    ////horizontal
                        {
                            if(turn==1)
                                c1[x][y]=205;
                            if(turn==2)
                                c2[x][y]=205;

                            matrix[x][y]=205;
                        }
                        else if((x%2!=0) && (y%2==0))               ////vertical
                        {
                            if(turn==1)
                                c1[x][y]=186;
                            if(turn==2)
                                c2[x][y]=186;

                            matrix[x][y]=186;
                        }

                            TC1=0;
                            TC2=0;
                            for(p=1;p<=BC;p+=2)                                 ////checking completed boxes
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
                                URA[totalmoves][0]=x;
                                URA[totalmoves][1]=y;
                                URA[totalmoves][2]=turn;
                                if(turn==1)
                                {
                                    if(sc1+1==score1)
                                        {
                                            URA[totalmoves][3]=1;
                                            sc1=score1;
                                        }
                                    else if(sc1+2==score1)
                                        {
                                            URA[totalmoves][3]=2;
                                            sc1=score1;
                                        }
                                    else if (sc1==score1)
                                        {
                                            URA[totalmoves][3]=0;
                                            sc1=score1;
                                        }
                                }
                                else if(turn==2)
                                {
                                    if(sc2+1==score2)
                                        {
                                            URA[totalmoves][3]=1;
                                            sc2=score2;
                                        }
                                    else if(sc2+2==score2)
                                        {
                                            URA[totalmoves][3]=2;
                                            sc2=score2;
                                        }
                                    else if (sc2==score2)
                                        {
                                            URA[totalmoves][3]=0;
                                            sc2=score2;
                                        }
                                }
                                totalmoves++;



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
                }
                else if(r==1)                       //// one player mode
                {
                    if(x==1 && y==1)            ////undo
                    {
                        if((flagCount>0 || flag==1)&& playsCount>0 && totalmoves>=0)
                        {
                            if(URA[totalmoves-1][2]==1)             ////undo the move of the player
                               {
                                playsCount--;
                                totalmoves--;
                                flag=0;
                                RL++;
                                turn=URA[totalmoves][2];
                                Miki=URA[totalmoves][0];
                                Tao=URA[totalmoves][1];
                                c1[Miki][Tao]=32;
                                matrix[Miki][Tao]=32;
                                counter1--;
                                count++;
                                flagCount= count;

                                    for(p=1;p<=BC;p+=2)
                                        for(k=1;k<=BC;k+=2)
                                            {
                                                matrix[p][k]=32;
                                                score1=0;
                                                score2=0;
                                            }

                                    for(p=1;p<=BC;p+=2)
                                    {
                                        for(k=1;k<=BC;k+=2)
                                        {
                                                if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                                {
                                                    if(matrix[p][k]!=219)
                                                    {
                                                        matrix[p][k]=219;
                                                        if(matrix[p][k]==c1[p][k])
                                                        {
                                                            score1++;
                                                        }
                                                        else if(matrix[p][k]==c2[p][k])
                                                        {
                                                            score2++;
                                                        }
                                                    }
                                                }
                                        }
                                    }
                                }
                                else if(URA[totalmoves-1][2]==2)        ////undo the move of the computer and the player move
                                {
                                    while(1)
                                    {
                                        playsCount--;
                                        totalmoves--;
                                        flag=0;
                                        RL++;
                                        turn=URA[totalmoves][2];
                                        Miki=URA[totalmoves][0];
                                        Tao=URA[totalmoves][1];
                                        c2[Miki][Tao]=32;
                                        matrix[Miki][Tao]=32;
                                        counter2--;
                                        count++;
                                        flagCount= count;

                                            for(p=1;p<=BC;p+=2)
                                                for(k=1;k<=BC;k+=2)
                                                    {
                                                        matrix[p][k]=32;
                                                        score1=0;
                                                        score2=0;
                                                    }

                                            for(p=1;p<=BC;p+=2)
                                            {
                                                for(k=1;k<=BC;k+=2)
                                                {
                                                        if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                                        {
                                                            if(matrix[p][k]!=219)
                                                            {
                                                                matrix[p][k]=219;
                                                                if(matrix[p][k]==c1[p][k])
                                                                {
                                                                    score1++;
                                                                }
                                                                else if(matrix[p][k]==c2[p][k])
                                                                {
                                                                    score2++;
                                                                }
                                                            }
                                                        }
                                                }
                                            }
                                            if(URA[totalmoves-1][2]==1)
                                            {
                                                playsCount--;
                                                totalmoves--;
                                                flag=0;
                                                RL++;
                                                turn=URA[totalmoves][2];
                                                Miki=URA[totalmoves][0];
                                                Tao=URA[totalmoves][1];
                                                c1[Miki][Tao]=32;
                                                matrix[Miki][Tao]=32;
                                                counter1--;
                                                count++;
                                                flagCount= count;

                                                    for(p=1;p<=BC;p+=2)
                                                        for(k=1;k<=BC;k+=2)
                                                            {
                                                                matrix[p][k]=32;
                                                                score1=0;
                                                                score2=0;
                                                            }

                                                    for(p=1;p<=BC;p+=2)
                                                    {
                                                        for(k=1;k<=BC;k+=2)
                                                        {
                                                                if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                                                {
                                                                    if(matrix[p][k]!=219)
                                                                    {
                                                                        matrix[p][k]=219;
                                                                        if(matrix[p][k]==c1[p][k])
                                                                        {
                                                                            score1++;
                                                                        }
                                                                        else if(matrix[p][k]==c2[p][k])
                                                                        {
                                                                            score2++;
                                                                        }
                                                                    }
                                                                }
                                                        }
                                                    }
                                                    break;
                                            }
                                    }
                                }
                        }
                    }

                    else if(x==2 && y==2)               ////redo
                    {
                        if(URA[totalmoves][2]==1)       ////redo the moves
                        {
                            if(count!=0)
                            {
                                playsCount++;
                                flag=1;
                                RL--;
                                flagCount=0;
                                turn=URA[totalmoves][2];    //////
                                Miki=URA[totalmoves][0];
                                Tao=URA[totalmoves][1];
                                if(Miki%2==0 && Tao%2!=0)               //// horizontal
                                {
                                        c1[Miki][Tao]=205;
                                        matrix[Miki][Tao]=205;
                                        counter1++;
                                        turn=2;
                                        if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                            turn=1;
                                }
                                else if(Miki%2!=0 && Tao%2==0)
                                {

                                        c1[Miki][Tao]=186;
                                        matrix[Miki][Tao]=186;
                                        counter1++;
                                        turn=2;
                                        if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                            turn=1;
                                }
                                for(p=1;p<=BC;p+=2)
                                    {
                                        for(k=1;k<=BC;k+=2)
                                            {
                                                if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                                {
                                                   if(URA[totalmoves][2]==1)
                                                   {
                                                       if(matrix[p][k]!=219)
                                                        {
                                                            score1++;
                                                            matrix[p][k]=219;
                                                            c1[p][k]=219;
                                                        }
                                                   }
                                                }
                                            }
                                    }
                                    count--;
                                    totalmoves++;



                            }
                        }
                    }


                    else if(matrix[x][y]==32 && ((x%2==0 && y%2!=0) || (x%2!=0 && y%2==0)))         //playing actual play
                    {
                        count=0;
                        count+=2;
                        flagCount=0;
                        playsCount++;
                        flag=1;
                        RL--;
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

                            TC1=0;
                            TC2=0;
                            for(p=1;p<=BC;p+=2)         // checking completed boxes
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
                                URA[totalmoves][0]=x;
                                URA[totalmoves][1]=y;
                                URA[totalmoves][2]=turn;
                                if(turn==1)
                                {
                                    if(sc1+1==score1)
                                        {
                                            URA[totalmoves][3]=1;
                                            sc1=score1;
                                        }
                                    else if(sc1+2==score1)
                                        {
                                            URA[totalmoves][3]=2;
                                            sc1=score1;
                                        }
                                    else if (sc1==score1)
                                        {
                                            URA[totalmoves][3]=0;
                                            sc1=score1;
                                        }
                                }
                                else if(turn==2)
                                {
                                    if(sc2+1==score2)
                                        {
                                            URA[totalmoves][3]=1;
                                            sc2=score2;
                                        }
                                    else if(sc2+2==score2)
                                        {
                                            URA[totalmoves][3]=2;
                                            sc2=score2;
                                        }
                                    else if (sc2==score2)
                                        {
                                            URA[totalmoves][3]=0;
                                            sc2=score2;
                                        }
                                }
                                totalmoves++;



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
                }
                system("cls");          //// printing the new screen
                int i,j;
                for(i=0;i<n;i++)
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
                printf("\n\nPlayer Turn: %d",turn);
                printf(reset);

                clock_t t3=(t2-t1)/CLOCKS_PER_SEC;                                          //time fn
                minutes=t3/60;
                seconds=t3%60;
                if (minutes >= 60)
                {
                    hours = minutes / 60;
                    minutes = minutes % 60;
                }

                printf(L_BLU);
                printf("\n\nTime passed : %d:%d:%d",hours,minutes,seconds);
                printf(reset);
                printf(L_YEL);
                printf("\n\nEnter (0,0) for Start Menu");
                printf("\tEnter (1,1) for Undo");
                printf("\tEnter (2,2) for Redo");
                printf("\tEnter (3,3) for Save");
                printf(reset);

            }
            printf(L_MAG);
            if(score1>score2)
                {printf("\n\nThe Winner is: %s",Name1);winner=1;}
            else if(score1<score2)
                {
                if(r==1)
                    {printf("\n\nThe Winner is: %s",Name3);winner=1;}
                else if(r==2)
                    {printf("\n\nThe Winner is: %s",Name2);winner=2;}
                }
            else if(score1==score2)
                printf("\n\nDraw");
            printf(reset);
            intialize();            // storing the data in the leaderboard
            winning();              // storing the data in the leaderboard
            char lmao[N];
            printf("\n\nEnter 0 to return to Main menu");
            scanf("%s",lmao);

            if(lmao[0]=='0')
            {
                system("cls");
                int txyx=StartMenu();
                if(txyx==0)
                    return 0;
            }
        }



}

//////////////save and load process
FILE*SAVE1;
FILE*SAVE2;
FILE*SAVE3;
int ff;
int ll;
void save()
{
   int info[33]={Nov,Nob,RL,BC,sc1,sc2,turn,score1,score2,index1,index2,counter1,counter2,totalmoves,t1,t2,t3,seconds,minutes,hours,count,flagCount,playsCount,TC1,TC2,p,k,flag,Miki,Tao,z,r,n};
 if(sama==1)
 {
   printf("choose file 1 or 2 or 3");
   scanf("%d",&ff);
   if(ff==1)
   {
    SAVE1=fopen("1.txt","a");
    for(int i=0;i<33;i++)
      {
       fprintf(SAVE1,"%d\n",info[i]);
      }

    for (int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        fprintf(SAVE1,"%d\n",c1[i][j]);
        }
    for (int i=0;i<n;i++)
     {
    for(int j=0;j<n;j++)
        fprintf(SAVE1,"%d\n",c2[i][j]);
      }
    for(int i=0 ; i<n ;i++){
        for(int j=0 ; j<n ; j++)
        fprintf(SAVE1,"%d\n",matrix[i][j]);
    }
    for(int i=0;i<totalmoves;i++)
    {
        for(int j=0;j<4;j++)
            fprintf(SAVE1,"%d\n",URA[i][j]);
    }
    if(r==2)
        fprintf(SAVE1,"Name1:%s,Name2:%s,\n",Name1,Name2);
    else if(r==1)
        fprintf(SAVE1,"Name1:%s,Name2:%s,\n",Name1,Name3);

    fclose(SAVE1);
   }
   else if(ff==2)
   {
    SAVE2=fopen("2.txt","w");
    for(int i=0;i<33;i++)
      {
       fprintf(SAVE2,"%d\n",info[i]);
      }

    for (int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        fprintf(SAVE2,"%d\n",c1[i][j]);
        }
    for (int i=0;i<n;i++)
     {
    for(int j=0;j<n;j++)
        fprintf(SAVE2,"%d\n",c2[i][j]);
      }
    for(int i=0 ; i<n ;i++){
    for(int j=0 ; j<n ;j++)
      fprintf(SAVE2,"%d\n",matrix[i][j]);
    }
    for(int i=0;i<totalmoves;i++)
    {
        for(int j=0;j<4;j++)
            fprintf(SAVE2,"%d\n",URA[i][j]);
    }
    if(r==2)
        fprintf(SAVE2,"Name1:%s,Name2:%s,\n",Name1,Name2);
    else if(r==1)
        fprintf(SAVE2,"Name1:%s,Name2:%s,\n",Name1,Name3);


    fclose(SAVE2);
   }
   else if (ff==3)
   {
      SAVE3=fopen("3.txt","w");
    for(int i=0;i<33;i++)
      {
       fprintf(SAVE3,"%d\n",info[i]);
      }

    for (int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        fprintf(SAVE3,"%d\n",c1[i][j]);
        }
    for (int i=0;i<n;i++)
     {
    for(int j=0;j<n;j++)
        fprintf(SAVE3,"%d\n",c2[i][j]);
      }
    for(int i=0 ; i<n ;i++){
    for(int j=0 ; j<n ;j++)
      fprintf(SAVE3,"%d\n",matrix[i][j]);
    }
    for(int i=0;i<totalmoves;i++)
    {
        for(int j=0;j<4;j++)
            fprintf(SAVE3,"%d\n",URA[i][j]);
    }

    if(r==2)
        fprintf(SAVE3,"Name1:%s,Name2:%s,\n",Name1,Name2);
    else if(r==1)
        fprintf(SAVE3,"Name1:%s,Name2:%s,\n",Name1,Name3);

      fclose(SAVE3);
   }

 }

else if(sama==2)
{

   printf("choose file 1 or 2 or 3");
   scanf("%d",&ll);
   if(ll==1)
   {
    SAVE1=fopen("1.txt","r");
    fscanf(SAVE1,"%d",&Nov);
    fscanf(SAVE1,"%d",&Nob);
    fscanf(SAVE1,"%d",&RL);
    fscanf(SAVE1,"%d",&BC);
    fscanf(SAVE1,"%d",&sc1);
    fscanf(SAVE1,"%d",&sc2);
    fscanf(SAVE1,"%d",&turn);
    fscanf(SAVE1,"%d",&score1);
    fscanf(SAVE1,"%d",&score2);
    fscanf(SAVE1,"%d",&index1);
    fscanf(SAVE1,"%d",&index2);
    fscanf(SAVE1,"%d",&counter1);
    fscanf(SAVE1,"%d",&counter2);
    fscanf(SAVE1,"%d",&totalmoves);
    fscanf(SAVE1,"%d",&t1);
    fscanf(SAVE1,"%d",&t2);
    fscanf(SAVE1,"%d",&t3);
    fscanf(SAVE1,"%d",&seconds);
    fscanf(SAVE1,"%d",&minutes);
    fscanf(SAVE1,"%d",&hours);
    fscanf(SAVE1,"%d",&count);
    fscanf(SAVE1,"%d",&flagCount);
    fscanf(SAVE1,"%d",&playsCount);
    fscanf(SAVE1,"%d",&TC1);
    fscanf(SAVE1,"%d",&TC2);
    fscanf(SAVE1,"%d",&p);
    fscanf(SAVE1,"%d",&k);
    fscanf(SAVE1,"%d",&flag);
    fscanf(SAVE1,"%d",&Miki);
    fscanf(SAVE1,"%d",&Tao);
    fscanf(SAVE1,"%d",&z);
    fscanf(SAVE1,"%d",&r);
    fscanf(SAVE1,"%d",&n);

    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
            fscanf(SAVE1,"\n%d",&c1[i][j]);
    }
    for (int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        fscanf(SAVE1,"%d\n",&c2[i][j]);
        }
    for (int i=0;i<n;i++)
     {
    for(int j=0;j<n;j++)
        fscanf(SAVE1,"%d\n",&matrix[i][j]);
      }
     for (int i=0;i<totalmoves;i++)
     {
    for(int j=0;j<4;j++)
        fscanf(SAVE1,"%d\n",&URA[i][j]);
      }
        if(r==2)
        fscanf(SAVE1,"Name1:%[^,],Name2:%[^,],\n",Name1,Name2);
    else if(r==1)
        fscanf(SAVE1,"Name1:%[^,],Name2:%[^,],\n",Name1,Name3);

    fclose(SAVE1);

   }
   else if(ll==2)
   {
    SAVE2=fopen("2.txt","r");
    fscanf(SAVE2,"%d",&Nov);
    fscanf(SAVE2,"%d",&Nob);
    fscanf(SAVE2,"%d",&RL);
    fscanf(SAVE2,"%d",&BC);
    fscanf(SAVE2,"%d",&sc1);
    fscanf(SAVE2,"%d",&sc2);
    fscanf(SAVE2,"%d",&turn);
    fscanf(SAVE2,"%d",&score1);
    fscanf(SAVE2,"%d",&score2);
    fscanf(SAVE2,"%d",&index1);
    fscanf(SAVE2,"%d",&index2);
    fscanf(SAVE2,"%d",&counter1);
    fscanf(SAVE2,"%d",&counter2);
    fscanf(SAVE2,"%d",&totalmoves);
    fscanf(SAVE2,"%d",&t1);
    fscanf(SAVE2,"%d",&t2);
    fscanf(SAVE2,"%d",&t3);
    fscanf(SAVE2,"%d",&seconds);
    fscanf(SAVE2,"%d",&minutes);
    fscanf(SAVE2,"%d",&hours);
    fscanf(SAVE2,"%d",&count);
    fscanf(SAVE2,"%d",&flagCount);
    fscanf(SAVE2,"%d",&playsCount);
    fscanf(SAVE2,"%d",&TC1);
    fscanf(SAVE2,"%d",&TC2);
    fscanf(SAVE2,"%d",&p);
    fscanf(SAVE2,"%d",&k);
    fscanf(SAVE2,"%d",&flag);
    fscanf(SAVE2,"%d",&Miki);
    fscanf(SAVE2,"%d",&Tao);
    fscanf(SAVE2,"%d",&z);
    fscanf(SAVE2,"%d",&r);
    fscanf(SAVE2,"%d",&n);

    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
            fscanf(SAVE2,"%d",&c1[i][j]);
    }
    for (int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        fscanf(SAVE2,"%d\n",&c2[i][j]);
        }
    for (int i=0;i<n;i++)
     {
    for(int j=0;j<n;j++)
        fscanf(SAVE2,"%d\n",&matrix[i][j]);
      }
     for (int i=0;i<totalmoves;i++)
     {
    for(int j=0;j<4;j++)
        fscanf(SAVE2,"%d\n",&URA[i][j]);
      }
      if(r==2)
        fscanf(SAVE2,"Name1:%[^,],Name2:%[^,],\n",Name1,Name2);
    else if(r==1)
        fscanf(SAVE2,"Name1:%[^,],Name2:%[^,],\n",Name1,Name3);


    fclose(SAVE2);

   }
   else if (ll==3)
   {
   SAVE3=fopen("3.txt","r");
    fscanf(SAVE3,"%d",&Nov);
    fscanf(SAVE3,"%d",&Nob);
    fscanf(SAVE3,"%d",&RL);
    fscanf(SAVE3,"%d",&BC);
    fscanf(SAVE3,"%d",&sc1);
    fscanf(SAVE3,"%d",&sc2);
    fscanf(SAVE3,"%d",&turn);
    fscanf(SAVE3,"%d",&score1);
    fscanf(SAVE3,"%d",&score2);
    fscanf(SAVE3,"%d",&index1);
    fscanf(SAVE3,"%d",&index2);
    fscanf(SAVE3,"%d",&counter1);
    fscanf(SAVE3,"%d",&counter2);
    fscanf(SAVE3,"%d",&totalmoves);
    fscanf(SAVE3,"%d",&t1);
    fscanf(SAVE3,"%d",&t2);
    fscanf(SAVE3,"%d",&t3);
    fscanf(SAVE3,"%d",&seconds);
    fscanf(SAVE3,"%d",&minutes);
    fscanf(SAVE3,"%d",&hours);
    fscanf(SAVE3,"%d",&count);
    fscanf(SAVE3,"%d",&flagCount);
    fscanf(SAVE3,"%d",&playsCount);
    fscanf(SAVE3,"%d",&TC1);
    fscanf(SAVE3,"%d",&TC2);
    fscanf(SAVE3,"%d",&p);
    fscanf(SAVE3,"%d",&k);
    fscanf(SAVE3,"%d",&flag);
    fscanf(SAVE3,"%d",&Miki);
    fscanf(SAVE3,"%d",&Tao);
    fscanf(SAVE3,"%d",&z);
    fscanf(SAVE3,"%d",&r);
    fscanf(SAVE3,"%d",&n);

    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
            fscanf(SAVE3,"%d",&c1[i][j]);
    }
    for (int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        fscanf(SAVE3,"%d\n",&c2[i][j]);
        }
    for (int i=0;i<n;i++)
     {
    for(int j=0;j<n;j++)
        fscanf(SAVE3,"%d\n",&matrix[i][j]);
      }
     for (int i=0;i<totalmoves;i++)
     {
    for(int j=0;j<4;j++)
        fscanf(SAVE3,"%d\n",&URA[i][j]);
      }
        if(r==2)
        fscanf(SAVE3,"Name1:%[^,],Name2:%[^,],\n",Name1,Name2);
    else if(r==1)
        fscanf(SAVE3,"Name1:%[^,],Name2:%[^,],\n",Name1,Name3);

    fclose(SAVE3);
   }
}
}


void LoadGame()             //// loading function
{
     system("cls");
                int i,j;
                for(i=0;i<n;i++)
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
                printf("\n\nPlayer Turn: %d",turn);
                printf(reset);

                clock_t t3=(t2-t1)/CLOCKS_PER_SEC;                                          //time fn
                minutes=t3/60;
                seconds=t3%60;
                if (minutes >= 60)
                {
                    hours = minutes / 60;
                    minutes = minutes % 60;
                }

                printf(L_BLU);
                printf("\n\nTime passed : %d:%d:%d",hours,minutes,seconds);
                printf(reset);
                printf(L_YEL);
                printf("\n\nEnter (0,0) for Start Menu");
                printf("\tEnter (1,1) for Undo");
                printf("\tEnter (2,2) for Redo");
                printf("\tEnter (3,3) for Save");
                printf(reset);

                while(RL)                   /////the game loop which is nearly the same
            {
                if(r==1)                    // one player mode
                {
                    if(turn==1)
                    {
                        printf("\n\n\nEnter Row no. :");

                        fgets(xx,99,stdin);
                        while(1)
                        {
                            if(z==4 && xx[0]=='1' && xx[1]=='0')
                            {
                               if(xx[3]!='\0')
                                    fgets(xx,99,stdin);
                                else
                                    break;
                            }
                            else
                            {
                                if(xx[2]!='\0')
                                    fgets(xx,99,stdin);
                                else
                                    break;
                            }

                        }
                        if(z==4 && xx[0]=='1' && xx[1]=='0')
                            x=10;
                        else
                            x=xx[0]-'0';


                        printf("Enter col no. :");

                        fgets(yy,99,stdin);
                         while(1)
                        {
                            if(z==4 && yy[0]=='1' && yy[1]=='0')
                            {
                               if(yy[3]!='\0')
                                    fgets(yy,99,stdin);
                                else
                                    break;
                            }
                            else
                            {
                                if(yy[2]!='\0')
                                    fgets(yy,99,stdin);
                                else
                                    break;
                            }

                        }
                        if(z==4 && yy[0]=='1' && yy[1]=='0')
                            y=10;
                        else
                            y=yy[0]-'0';


                    }
                    else if(turn==2)                //computer turn
                    {

                        x=-1;
                        y=-1;
                        for(index1=0;index1<n;index1++)
                        {
                            for(index2=0;index2<n;index2++)
                            {
                                if( matrix[index1][index2]==32 && ((index1%2==0 && index2%2!=0) || (index1%2!=0 && index2%2==0)))
                                {
                                    x=index1;
                                    y=index2;
                                    break;
                                }
                            }
                        }
                    }
                }
                else if(r==2)                   // 2 players mode
                {
                        printf("\n\n\nEnter Row no. :");

                        fgets(xx,99,stdin);
                        while(1)
                        {
                            if(z==4 && xx[0]=='1' && xx[1]=='0')
                            {
                               if(xx[3]!='\0')
                                    fgets(xx,99,stdin);
                                else
                                    break;
                            }
                            else
                            {
                                if(xx[2]!='\0')
                                    fgets(xx,99,stdin);
                                else
                                    break;
                            }

                        }
                        if(z==4 && xx[0]=='1' && xx[1]=='0')
                            x=10;
                        else
                            x=xx[0]-'0';


                        printf("Enter col no. :");

                        fgets(yy,99,stdin);
                         while(1)
                        {
                            if(z==4 && yy[0]=='1' && yy[1]=='0')
                            {
                               if(yy[3]!='\0')
                                    fgets(yy,99,stdin);
                                else
                                    break;
                            }
                            else
                            {
                                if(yy[2]!='\0')
                                    fgets(yy,99,stdin);
                                else
                                    break;
                            }

                        }
                        if(z==4 && yy[0]=='1' && yy[1]=='0')
                            y=10;
                        else
                            y=yy[0]-'0';


                }
               clock_t t2=clock();

                if(x==0 && y==0)            //start menu
                {
                    system("cls");
                    StartMenu();
                }
                else if(r==2)                    //2 players mode
                {
                    if(x==1 && y==1)            // undo
                    {
                        if((flagCount>0 || flag==1)&& playsCount>0 && totalmoves>=0)
                        {

                            playsCount--;            //checking the moves that that undo could have
                            totalmoves--;           // the index counter of the array of moves
                            flag=0;                 // to check the undo process is right or not



                                    RL++;
                                    turn=URA[totalmoves][2];
                                    Miki=URA[totalmoves][0];
                                    Tao=URA[totalmoves][1];

                                    if(URA[totalmoves][2]==1)
                                    {
                                        c1[Miki][Tao]=32;
                                        matrix[Miki][Tao]=32;
                                        counter1--;
                                    }
                                    else if(URA[totalmoves][2]==2)
                                    {
                                        c2[Miki][Tao]=32;
                                        matrix[Miki][Tao]=32;
                                        counter2--;
                                    }

                                    count++;
                                    flagCount= count;

                                    for(p=1;p<=BC;p+=2)
                                        for(k=1;k<=BC;k+=2)
                                            {
                                                matrix[p][k]=32;
                                                score1=0;
                                                score2=0;
                                            }

                                    for(p=1;p<=BC;p+=2)
                                    {
                                        for(k=1;k<=BC;k+=2)
                                        {
                                                if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                                {
                                                    if(matrix[p][k]!=219)
                                                    {
                                                        matrix[p][k]=219;
                                                        if(matrix[p][k]==c1[p][k])
                                                        {
                                                            score1++;
                                                        }
                                                        else if(matrix[p][k]==c2[p][k])
                                                        {
                                                            score2++;
                                                        }
                                                    }
                                                }
                                        }
                                    }
                        }
                    }


                    else if(x==2 && y==2)               ////redo
                    {
                        if(count!=0)
                        {
                            playsCount++;
                            flag=1;
                            RL--;
                            flagCount=0;
                            turn=URA[totalmoves][2];
                            Miki=URA[totalmoves][0];
                            Tao=URA[totalmoves][1];
                            if(Miki%2==0 && Tao%2!=0)               //// horizontal
                            {
                                if(URA[totalmoves][2]==1)
                                {
                                    c1[Miki][Tao]=205;
                                    matrix[Miki][Tao]=205;
                                    counter1++;
                                    turn=2;
                                    if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                        turn=1;
                                }
                                else if(URA[totalmoves][2]==2)
                                {
                                    c2[Miki][Tao]=205;
                                    matrix[Miki][Tao]=205;
                                    counter2++;
                                    turn=1;
                                    if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                        turn=2;
                                }

                            }
                            else if(Miki%2!=0 && Tao%2==0)      //// vertical
                            {
                                if(URA[totalmoves][2]==1)
                                {
                                    c1[Miki][Tao]=186;
                                    matrix[Miki][Tao]=186;
                                    counter1++;
                                    turn=2;
                                    if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                        turn=1;
                                }
                                else if(URA[totalmoves][2]==2)
                                {
                                    c2[Miki][Tao]=186;
                                    matrix[Miki][Tao]=186;
                                    counter2++;
                                    turn=1;
                                    if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                        turn=2;
                                }

                            }
                            for(p=1;p<=BC;p+=2)             ////checking boxes
                                {
                                    for(k=1;k<=BC;k+=2)
                                        {
                                            if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                            {
                                               if(URA[totalmoves][2]==1)
                                               {
                                                   if(matrix[p][k]!=219)
                                                    {
                                                        score1++;
                                                        matrix[p][k]=219;
                                                        c1[p][k]=219;
                                                    }

                                               }
                                               else if(URA[totalmoves][2]==2)
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
                                count--;
                                totalmoves++;
                       }
                    }


                    else if(matrix[x][y]==32 && ((x%2==0 && y%2!=0) || (x%2!=0 && y%2==0)))  // plays
                    {
                        count=0;
                        flagCount=0;
                        playsCount++;
                        flag=1;
                        RL--;
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

                            TC1=0;
                            TC2=0;
                            for(p=1;p<=BC;p+=2)             // checking boxes
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
                                URA[totalmoves][0]=x;
                                URA[totalmoves][1]=y;
                                URA[totalmoves][2]=turn;
                                if(turn==1)
                                {
                                    if(sc1+1==score1)
                                        {
                                            URA[totalmoves][3]=1;
                                            sc1=score1;
                                        }
                                    else if(sc1+2==score1)
                                        {
                                            URA[totalmoves][3]=2;
                                            sc1=score1;
                                        }
                                    else if (sc1==score1)
                                        {
                                            URA[totalmoves][3]=0;
                                            sc1=score1;
                                        }
                                }
                                else if(turn==2)
                                {
                                    if(sc2+1==score2)
                                        {
                                            URA[totalmoves][3]=1;
                                            sc2=score2;
                                        }
                                    else if(sc2+2==score2)
                                        {
                                            URA[totalmoves][3]=2;
                                            sc2=score2;
                                        }
                                    else if (sc2==score2)
                                        {
                                            URA[totalmoves][3]=0;
                                            sc2=score2;
                                        }
                                }
                                totalmoves++;



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
                }
                else if(r==1)               // one player mode
                {
                    if(x==1 && y==1)
                    {
                        if((flagCount>0 || flag==1)&& playsCount>0 && totalmoves>=0)
                        {
                            if(URA[totalmoves-1][2]==1)
                               {
                                playsCount--;
                                totalmoves--;
                                flag=0;
                                RL++;
                                turn=URA[totalmoves][2];
                                Miki=URA[totalmoves][0];
                                Tao=URA[totalmoves][1];
                                c1[Miki][Tao]=32;
                                matrix[Miki][Tao]=32;
                                counter1--;
                                count++;
                                flagCount= count;

                                    for(p=1;p<=BC;p+=2)
                                        for(k=1;k<=BC;k+=2)
                                            {
                                                matrix[p][k]=32;
                                                score1=0;
                                                score2=0;
                                            }

                                    for(p=1;p<=BC;p+=2)
                                    {
                                        for(k=1;k<=BC;k+=2)
                                        {
                                                if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                                {
                                                    if(matrix[p][k]!=219)
                                                    {
                                                        matrix[p][k]=219;
                                                        if(matrix[p][k]==c1[p][k])
                                                        {
                                                            score1++;
                                                        }
                                                        else if(matrix[p][k]==c2[p][k])
                                                        {
                                                            score2++;
                                                        }
                                                    }
                                                }
                                        }
                                    }
                                }
                                else if(URA[totalmoves-1][2]==2)
                                {
                                    while(1)
                                    {
                                        playsCount--;
                                        totalmoves--;
                                        flag=0;
                                        RL++;
                                        turn=URA[totalmoves][2];
                                        Miki=URA[totalmoves][0];
                                        Tao=URA[totalmoves][1];
                                        c2[Miki][Tao]=32;
                                        matrix[Miki][Tao]=32;
                                        counter2--;
                                        count++;
                                        flagCount= count;

                                            for(p=1;p<=BC;p+=2)
                                                for(k=1;k<=BC;k+=2)
                                                    {
                                                        matrix[p][k]=32;
                                                        score1=0;
                                                        score2=0;
                                                    }

                                            for(p=1;p<=BC;p+=2)
                                            {
                                                for(k=1;k<=BC;k+=2)
                                                {
                                                        if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                                        {
                                                            if(matrix[p][k]!=219)
                                                            {
                                                                matrix[p][k]=219;
                                                                if(matrix[p][k]==c1[p][k])
                                                                {
                                                                    score1++;
                                                                }
                                                                else if(matrix[p][k]==c2[p][k])
                                                                {
                                                                    score2++;
                                                                }
                                                            }
                                                        }
                                                }
                                            }
                                            if(URA[totalmoves-1][2]==1)
                                            {
                                                playsCount--;
                                                totalmoves--;
                                                flag=0;
                                                RL++;
                                                turn=URA[totalmoves][2];
                                                Miki=URA[totalmoves][0];
                                                Tao=URA[totalmoves][1];
                                                c1[Miki][Tao]=32;
                                                matrix[Miki][Tao]=32;
                                                counter1--;
                                                count++;
                                                flagCount= count;

                                                    for(p=1;p<=BC;p+=2)
                                                        for(k=1;k<=BC;k+=2)
                                                            {
                                                                matrix[p][k]=32;
                                                                score1=0;
                                                                score2=0;
                                                            }

                                                    for(p=1;p<=BC;p+=2)
                                                    {
                                                        for(k=1;k<=BC;k+=2)
                                                        {
                                                                if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                                                {
                                                                    if(matrix[p][k]!=219)
                                                                    {
                                                                        matrix[p][k]=219;
                                                                        if(matrix[p][k]==c1[p][k])
                                                                        {
                                                                            score1++;
                                                                        }
                                                                        else if(matrix[p][k]==c2[p][k])
                                                                        {
                                                                            score2++;
                                                                        }
                                                                    }
                                                                }
                                                        }
                                                    }
                                                    break;
                                            }
                                    }
                                }
                        }
                    }

                    else if(x==2 && y==2)
                    {
                        if(URA[totalmoves][2]==1)
                        {
                            if(count!=0)
                            {
                                playsCount++;
                                flag=1;
                                RL--;
                                flagCount=0;
                                turn=URA[totalmoves][2];    //////
                                Miki=URA[totalmoves][0];
                                Tao=URA[totalmoves][1];
                                if(Miki%2==0 && Tao%2!=0)               //// horizontal
                                {
                                        c1[Miki][Tao]=205;
                                        matrix[Miki][Tao]=205;
                                        counter1++;
                                        turn=2;
                                        if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                            turn=1;
                                }
                                else if(Miki%2!=0 && Tao%2==0)
                                {

                                        c1[Miki][Tao]=186;
                                        matrix[Miki][Tao]=186;
                                        counter1++;
                                        turn=2;
                                        if((URA[totalmoves][3]==1) || (URA[totalmoves][3]==2))
                                            turn=1;
                                }
                                for(p=1;p<=BC;p+=2)
                                    {
                                        for(k=1;k<=BC;k+=2)
                                            {
                                                if((matrix[p+1][k]!=32)&&(matrix[p-1][k]!=32)&&(matrix[p][k+1]!=32)&&(matrix[p][k-1]!=32))
                                                {
                                                   if(URA[totalmoves][2]==1)
                                                   {
                                                       if(matrix[p][k]!=219)
                                                        {
                                                            score1++;
                                                            matrix[p][k]=219;
                                                            c1[p][k]=219;
                                                        }
                                                   }
                                                }
                                            }
                                    }
                                    count--;
                                    totalmoves++;



                            }
                        }
                    }


                    else if(matrix[x][y]==32 && ((x%2==0 && y%2!=0) || (x%2!=0 && y%2==0)))
                    {
                        count=0;
                        count+=2;
                        flagCount=0;
                        playsCount++;
                        flag=1;
                        RL--;
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

                            TC1=0;
                            TC2=0;
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
                                URA[totalmoves][0]=x;
                                URA[totalmoves][1]=y;
                                URA[totalmoves][2]=turn;
                                if(turn==1)
                                {
                                    if(sc1+1==score1)
                                        {
                                            URA[totalmoves][3]=1;
                                            sc1=score1;
                                        }
                                    else if(sc1+2==score1)
                                        {
                                            URA[totalmoves][3]=2;
                                            sc1=score1;
                                        }
                                    else if (sc1==score1)
                                        {
                                            URA[totalmoves][3]=0;
                                            sc1=score1;
                                        }
                                }
                                else if(turn==2)
                                {
                                    if(sc2+1==score2)
                                        {
                                            URA[totalmoves][3]=1;
                                            sc2=score2;
                                        }
                                    else if(sc2+2==score2)
                                        {
                                            URA[totalmoves][3]=2;
                                            sc2=score2;
                                        }
                                    else if (sc2==score2)
                                        {
                                            URA[totalmoves][3]=0;
                                            sc2=score2;
                                        }
                                }
                                totalmoves++;



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
                    for ( j=0;j <n;j++)
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
                printf("\n\nPlayer Turn: %d",turn);
                printf(reset);

                clock_t t3=(t2-t1)/CLOCKS_PER_SEC;                                          //time fn
                minutes=t3/60;
                seconds=t3%60;
                if (minutes >= 60)
                {
                    hours = minutes / 60;
                    minutes = minutes % 60;
                }

                printf(L_BLU);
                printf("\n\nTime passed : %d:%d:%d",hours,minutes,seconds);
                printf(reset);
                printf(L_YEL);
                printf("\n\nEnter (0,0) for Start Menu");
                printf("\tEnter (1,1) for Undo");
                printf("\tEnter (2,2) for Redo");
                printf("\tEnter (3,3) for Save");
                printf(reset);

            }
            printf(L_MAG);
            if(score1>score2)
                {printf("\n\nThe Winner is: %s",Name1);winner=1;}
            else if(score1<score2)
                {
                if(r==1)
                    {printf("\n\nThe Winner is: %s",Name3);winner=1;}
                else if(r==2)
                    {printf("\n\nThe Winner is: %s",Name2);winner=2;}
                }
            else if(score1==score2)
                printf("\n\nDraw");
            printf(reset);
            intialize();            // storing the data in the leaderboard
            winning();              // storing the data in the leaderboard
            char lmfao[N];
            printf("\n\nEnter 0 to return to Main menu");
            scanf("%s",lmfao);

            if(lmfao[0]=='0')
            {
                system("cls");
                int yxyx=StartMenu();
                if(yxyx==0)
                    return 0;

            }

}

struct leaderboard{                //structure to contain winners name and scores where array of structure ranks will contain names and scores
char player_name[N];
int player_score;
}ranks[11];
FILE*LEADER;

void intialize()
{
FILE*LEADER=fopen("LEADER.txt","r");              //we fill the file with zeros as intial values by this function ranks will be assigned with
for(int i=0;i<10;i++)                             //scores of players and their name if it exists and zeros if it doesnt exist
 {
  fscanf(LEADER,"%s ",ranks[i].player_name);
  fscanf(LEADER,"%d ",&ranks[i].player_score);
 }
}


void winning(){                          //this function to put the winner is his place in j if he has score more than the jth player
FILE*LEADER=fopen("LEADER.txt","w");

switch(winner)
{
    case 1:

      for(int j=0;j<10;j++)
      {
        if(score1>ranks[j].player_score)
        {
            for(int k=9;k>j;k--)
          {
              ranks[k]=ranks[k-1];
          }
          for (int l=0;l<20;l++)
          {
              ranks[j].player_name[l]=Name1[l];
          }

          ranks[j].player_score=score1;
          break;
        }
      }
      break;

    case 2:

      for(int j=0;j<10;j++)
      {
        if(score1>ranks[j].player_score)
        {
            for(int k=9;k>j;k--)
          {
              ranks[k]=ranks[k-1];
          }
          for (int l=0;l<20;l++)
          {
              ranks[j].player_name[l]=Name2[l];
          }

          ranks[j].player_score=score1;
          break;
        }
      }
      break;

    case 3:

      for(int j=0;j<10;j++)
      {
        if(score1>ranks[j].player_score)
        {
            for(int k=9;k>j;k--)
          {
              ranks[k]=ranks[k-1];
          }
          for (int l=0;l<20;l++)
          {
              ranks[j].player_name[l]=Name1[l];
          }

          ranks[j].player_score=score1;
          break;
        }
      }
      break;

}

for(int o=0;o<10;o++)        //printing the values of ranks again to the file
{

fprintf(LEADER,"%s ",ranks[o].player_name);
fprintf(LEADER,"%d ",ranks[o].player_score);
}
fclose(LEADER);
}
void printingwinners()
{
   FILE*LEADER=fopen("LEADER.txt","r");
   for(int e=0;e<10;e++)
   {
    fscanf(LEADER,"%s ",ranks[e].player_name);
    fscanf(LEADER,"%d ",&ranks[e].player_score);
   }
   fclose(LEADER);
   for (int i =0;i<10;i++)
   {
       printf (" %d\n",ranks[i].player_score);
   }
}


void printingfam()         //function to print the leader board
{
    printf(L_RED);
    printf("Rank");
    printf("\t\t");
    printf("Score");
    printf("\t\t");
    printf("Name");
    printf("\n");
    printf(reset);

               FILE*LEADER=fopen("LEADER.txt","r");
for(int i=0;i<10;i++)
 {
  fscanf(LEADER,"%s ",ranks[i].player_name);
  fscanf(LEADER,"%d ",&ranks[i].player_score);
 }
 for (int i =0 ;i<10;i++)
 {
        printf(L_BLU);
        printf("%d",i+1);
        printf("\t\t");
        printf("%d",ranks[i].player_score);
        printf("\t\t");
        printf("%s",ranks[i].player_name);
        printf("\n");
        printf(reset);
 }

}

int main()
{

    system("COLOR");
    int xxxx=StartMenu();
    if(xxxx==0)
        return 0;

    return 0;
}





                
