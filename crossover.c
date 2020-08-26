#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void singleSideCrossover(int row,int col,int k)
{int i,j,r,CO[50][50],arr[50][50];
        for(i=0;i<row;i++){for(j=0;j<col;j++){r=rand()%2; arr[i][j]=r;}}
        printf("---------------------Display the Array--------------------------\nIndividual\n");
        for(i=0;i<row;i++){ for(j=0;j<col;j++){ printf("%d",arr[i][j]);} printf("\n");}
      for(i=0;i<row;i++){ for(j=0;j<col;j++){CO[i][j]=arr[i][j];}}
   for(i=0;i<row;i=i+2){
    for(j=0;j<k;j++){ int   l=CO[i][j];
        CO[i][j]=CO[i+1][j];
        CO[i+1][j]=l;
    }
}
printf("---------------------------------------SINGLESIDECROSSOVEROPERATION--------------------------------------------------------\nSingleSideCrossOver\n");
for(i=0;i<row;i++){ for(j=0;j<col;j++){ printf("%d",CO[i][j]);} printf("\n");}}
//-----------------------------------------------PERMUTATIONENCODING------------------------------------------------------------
void changeValues (int *a, int *b)
{  int temp = *a; *a = *b; *b = temp;
}
void permutationEncodingCrossover(int row,int col,int k)
{
int a[50],i,j,RANGE,temp,min=0,max,arr[50],b[50],PECO[50],c[50];
printf("Enter the range between 1 to 500:-");
 scanf("%d",&RANGE);
max=min+RANGE-1;
 for(i=0;i<=RANGE-1;i++)
 {   temp=((rand()%RANGE)+min);
for(j=0;j<=i-1;j++){if(temp==a[j]){break;}}
   if(i==j){a[i]=temp;}
   else{i--;}
 }
printf("\n");
printf("----------------------------display array-----------------\nIndividual\n");
for(i=0;i<=RANGE-1;i++){ c[i]=a[i]; printf("%d  ",c[i]);}
srand ( time(NULL) );
    for (int i = RANGE-1; i >=0; i--)
    {   int j = rand() % (i+1);
        changeValues(&a[i], &a[j]);
    }
    printf("\n");
    for (int i = 0; i <= RANGE-1; i++){ arr[i]=a[i]; printf("%d  ", arr[i]);}
    for(i=0;i<k;i++){
      int   l=arr[i];
        arr[i]=c[i];
        c[i]=l;
}
for(i=0;i<=RANGE-1;i++){ PECO[i]=c[i]; b[i]=arr[i];}
printf("\n---------------------PERMUTATIONENCODINGCROSSOVEROPERATION------------------------------\nPermutationEncodingCrossOver");
printf("\n----------------------------------------------------------------------------\n");
    for(i=k;i<=RANGE-1;i++){
    temp=((rand()%RANGE)+min);
int temp1=((rand()%RANGE)+min);
   for(j=0;j<=i-1;j++)
   {if(temp==PECO[j]){break;}
        if(temp1==b[j]){break;}
   }
   if(i==j){ PECO[i]=temp; b[i]=temp1;}
   else{ i--;}
  }
 for(i=0;i<=RANGE-1;i++){printf("%d  ",PECO[i]);}
printf("\n");
for(i=0;i<=RANGE-1;i++){printf("%d  ",b[i]);}
printf("\n");
}
//-----------------------------------TWOPOINTCROSSOVER-------------------------------------------------------------------------
void TwoPointCrossover(int row,int col )
{int i,j,k,k1,r,CO[50][50],arr[50][50];
printf("enter the  first crossover point");
        scanf("%d",&k);
printf("enter the  second crossover point");
        scanf("%d",&k1);
        for(i=0;i<row;i++){ for(j=0;j<col;j++){  r=rand()%2; arr[i][j]=r;}}
        printf("---------------------------------Display the Array--------------------------------\nIndividual\n");
        for(i=0;i<row;i++){ for(j=0;j<col;j++){printf("%d",arr[i][j]);} printf("\n");}
for(i=0;i<row;i++){for(j=0;j<col;j++){CO[i][j]=arr[i][j];}}
for(i=0;i<row;i=i+2){
    for(j=k;j<=k1;j++){
      int   l=CO[i][j];
        CO[i][j]=CO[i+1][j];
        CO[i+1][j]=l;
    }
}
printf("---------------------------------------TWOPOINTCROSSOVEROPERATION--------------------------------------------------------\nTwoPointCrossOver\n");
for(i=0;i<row;i++){for(j=0;j<col;j++){printf("%d",CO[i][j]);} printf("\n");}}
//---------------------------------------------MULTIPOINTCROSSOVER-------------------------------------------------------------------
void MultiPointCrossover(int row,int col)
{int i,j,k,k1,k2,r,CO[50][50],arr[50][50];
printf("enter the  first crossover point");
        scanf("%d",&k);
printf("enter the  second crossover point");
        scanf("%d",&k1);
printf("enter the  third crossover point");
        scanf("%d",&k2);
        for(i=0;i<row;i++){ for(j=0;j<col;j++){r=rand()%2; arr[i][j]=r;}}
        printf("---------------------------------Display the Array--------------------------------\nIndividual\n");
        for(i=0;i<row;i++){ for(j=0;j<col;j++){ CO[i][j]=arr[i][j]; printf("%d",arr[i][j]);} printf("\n");}
if((k1>k2 && k2>k)||(k1<k2 && k2<k)){ printf("No operation\n");}
else{
 if(k<k1)
 {for(i=0;i<row;i=i+2)
      {for(j=k;j<=k1;j++)
         {     int   l=CO[i][j];
                CO[i][j]=CO[i+1][j];
                CO[i+1][j]=l;
         }
     if(k<k2 && k1<k2)
        { for(j=k2;j<col;j++){
            int l=CO[i][j];
            CO[i][j]=CO[i+1][j];
            CO[i+1][j]=l;
           }
        }
        else{
        for(j=0;j<k2;j++)
           { int l=CO[i][j];
            CO[i][j]=CO[i+1][j];
            CO[i+1][j]=l;
           }
        }
      }
 }
 else{
for(i=0;i<row;i=i+2)
    { for(j=k;j>=k1;j--)
            { int   l=CO[i][j];
                CO[i][j]=CO[i+1][j];
                CO[i+1][j]=l;
            }
        if(k<k2 && k1<k2)
        {  for(j=k2;j<col;j++)
            {   int l=CO[i][j];
                CO[i][j]=CO[i+1][j];
                CO[i+1][j]=l;
            }
        }
        else{
            for(j=0;j<k2;j++)
            {  int   l=CO[i][j];
                CO[i][j]=CO[i+1][j];
                CO[i+1][j]=l;
            }
        }
    }
 }
}
printf("---------------------------------------MULTIPOINTCROSSOVEROPERATION--------------------------------------------------------\nMultiPointCrossOver\n");
for(i=0;i<row;i++){ for(j=0;j<col;j++){printf("%d",CO[i][j]);} printf("\n");}}
//---------------------------UniformCrossover--------------------------------------------------------------------------
void UniformCrossover(int row,int col)
{ int i,j,r,CO[50][50],arr[50][50];
//Assumption is that whenever coin tosses to 0 swap the bits and when it is 1 dont swap.
for(i=0;i<row;i++){for(j=0;j<col;j++){r=rand()%2; arr[i][j]=r;}}
printf("-----------------------Display the Array------------------------\nIndividual\n");
        for(i=0;i<row;i++){ for(j=0;j<col;j++){printf("%d",arr[i][j]);} printf("\n");}
for(i=0;i<row;i++){ for(j=0;j<col;j++){CO[i][j]=arr[i][j];}}
for(i=0;i<row;i=i+2){
    for(j=0;j<col;j++)
    { if(CO[i][j]==0 &&(CO[i][j]!=CO[i+1][j]))
       {int   l=CO[i][j];
            CO[i][j]=CO[i+1][j];
            CO[i+1][j]=l;
       }
    }
}
printf("---------------------------------------UNIFORMCROSSOVEROPERATION--------------------------------------------------------\nUniformCrossOver\n");
for(i=0;i<row;i++){ for(j=0;j<col;j++){printf("%d",CO[i][j]);} printf("\n");}}
void main()
{ int row,col,ch,k,k1,k2,i,j,r,arr[50][50];
int g,RANGE;
printf("Enter the  population size:-\n");
scanf("%d",&row);
printf("Enter the chromosome size:-\n");
scanf("%d",&col);
do{
printf("1)SingleSideCrossover\n2TwoPointCrossover\n3)MultiPointCrossover\n4)UniformCrossover\n5)Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{case 1:printf("enter the crossover point");
        scanf("%d",&k);
        while(g!=3){
        printf("\n1)BinaryEncoding\n2)PermutationEncoding\n3)exit\n");
        printf("Enter the choice\n");
        scanf("%d",&g);
        switch(g)
        {case 1: singleSideCrossover(row,col,k); break;
         case 2:   permutationEncodingCrossover(row,col,k); break;
         case 3: exit(0);
        }
        } break;
case 2: TwoPointCrossover(row,col); break;
case 3: MultiPointCrossover(row,col); break;
case 4: UniformCrossover(row,col); break;
case 5: exit(0);
}
}while(ch!=5);
}
