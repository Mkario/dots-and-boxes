#ifndef SAVE1_H_INCLUDED
#define SAVE1_H_INCLUDED
void saveing1(){
    if(w!=2){
FILE *SAVE1=SAVE1;
SAVE1=fopen("SAVE1.txt","w");
fprintf(SAVE1,"%d\n",name1);
fprintf(SAVE1,"%d\n",name2);
fprintf(SAVE1,"%d\n",score1);
fprintf(SAVE1,"%d\n",score2);
fprintf(SAVE1,"%d\n",counter1);
fprintf(SAVE1,"%d\n",counter2);
fprintf(SAVE1,"%d\n",RL);
fprintf(SAVE1,"%d\n",hours);
fprintf(SAVE1,"%d\n",minutes);
fprintf(SAVE1,"%d\n",seconds);
fprintf(SAVE1,"%d\n",turn);
fprintf(SAVE1,"%d\n",n);
for(int i=0;i<n;i++){
    for(int i=0;i<n;i++)
{
   fprintf(SAVE1,"%d\n",C1[i][j]);
}
}
for(int i=0;i<n;i++){
    for(int i=0;i<n;i++)
{
   fprintf(SAVE1,"%d\n",C2[i][j]);
}
}

}
else if (loadgame==1){
fscanf(SAVE1,"%d",&n)

fgets()

}

}


#endif // SAVE1_H_INCLUDED
