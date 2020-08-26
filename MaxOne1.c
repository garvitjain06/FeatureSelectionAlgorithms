#include<stdio.h>
#include<stdlib.h>
int printRandoms(int lower, int upper,int count)
{
    int i,num;
    for (i = 1; i <= count; i++) {
         num = (rand() % (upper - lower + 1)) + lower;
    }
    return num;
}
void decToBinaryString(int n[50],int m)
{int i,j,l[50];
int binarynum[50][32]={0};
for(i=1;i<=m;i++)
{ l[i]=n[i];
   j=10;
	while(n[i]>0)
	{  binarynum[i][j]=n[i]%2;
		n[i]=n[i]/2;
		j--;
	}
}
printf("\n");
for(i=m;i>=1;--i){ for(j=1;j<=32;j++){printf("%d",binarynum[i][j]);}  printf("\n");}
}
//-------------------------Mutation---------------------------------------------------------------------
void mutationOperation(int MP[50][32],int arrt[50][33],int n,int h, int gen,int s,int p[50])
{int i,j,r,k,l,w,sum,n1,n2,arr[50][33],count,acct[50],temp[50],maxtemp[50],mutate[50][33],d[50];
float avg;
static int t=1;
    printf("-------------------------------------------MUTATIONOPERATION----------------------------------------------------\n");
for(i=0;i<n;i++){ for(j=0;j<32;j++){ mutate[i][j]=MP[i][j];}}
int v=(16*n*n)/100;
printf("loc1\tloc2\n");
for(j=0;j<v;j++){
       n1=rand()%n;
       n2=rand()%32;
        if(mutate[n1][n2]==1){ mutate[n1][n2]=0;}
        else{ mutate[n1][n2]=1;}
printf("%d\t%d\n",n1,n2);
}
printf("\n");
printf("MutateString\t\t\t       fitnessValue\n");
for(i=0;i<n;i++)
{    int count4=0;
    for(j=0;j<32;j++)
    {    printf("%d",mutate[i][j]);
        if(mutate[i][j]==1) count4++;
    }
    mutate[i][32]=count4;
    d[i]=count4;
    printf("\t%d",d[i]);
    printf("\n");
}
sum=0;
for(i=0;i<n;i++){ sum=sum+mutate[i][32];}
printf("\n--------------------------------------------------------------------------------\n");
printf("sum=%d",sum);
avg=((float)sum/(float)n);
printf("\navg=%0.5f",avg);

 int max=mutate[0][32];
 int loc=0;
 for (i =1; i <n; i++)
    {
        if (mutate[i][32] > max)
        {
           max = mutate[i][32];
           loc = i;

        }

    }

for(i=0;i<n;i++)
{
    if(mutate[i][32]==max)
    {
       printf("\nMaximum fitness binary string is %d:- ",max);
       for(j=0;j<=31;j++)
         {
         printf("%d",mutate[i][j]);
         }
         printf("\n");
    }

}




printf("\n--------------------------------------------------------------------------------\n");
printf("\nmatting pool\t\t\t\tcrossover\t\t\t\tmutation\n");
for(i=0;i<n;i++){for(j=0;j<32;j++){printf("%d",arrt[i][j]);}
printf("\t");
for(k=0;k<32;k++){printf("%d",MP[i][k]);}
printf("\t");
for(l=0;l<32;l++){printf("%d",mutate[i][l]);}
printf("\n");
}
if(t<gen)
{printf("\n------------------------------%dGeneration---------------------------------\n",t+1);
t++;
printf("Individual\t\t\t\tfitnessvalue\n-------------------------------------------------------------\n");
for(i=0;i<n;i++)
{ for(j=0;j<32;j++){ printf("%d",mutate[i][j]);}
    printf("\t%d",mutate[i][32]);
    printf("\n");
}
sum=0;
for(i=0;i<n;i++){ sum=sum+mutate[i][32];}
printf("\n--------------------------------------------------------------------------");
printf("\nsum=%d",sum);
avg=((float)sum/(float)n);
printf("\navg=%0.5f",avg);
printf("\n--------------------------------------------------------------------------------");
printf("\n------------------------------TOURNAMENTSELECTIONMATTINGPOOL--------------------------------- \n");
           tournamentSelection(n,d,s,mutate,h,gen);
}
}
void singleSideCrossover(int n,int p[50],int arrt[50][33],int h,int gen,int s)
{ int i,j,MP[50][32];
    for(i=0;i<n;i++){ for(j=0;j<32;j++){ MP[i][j]=arrt[i][j];}}
for(i=0;i<n;i=i+2){
    for(j=0;j<h;j++){
      int   l=MP[i][j];
        MP[i][j]=MP[i+1][j];
        MP[i+1][j]=l;
    }
}
printf("---------------------------------------CROSSOVEROPERATION--------------------------------------------------------\nCrossOver\n");
for(i=0;i<n;i++){ for(j=0;j<32;j++){ printf("%d",MP[i][j]);} printf("\n");}
mutationOperation(MP,arrt,n,h,gen,s,p);
}
void tournamentSelection(int n,int y[50],int s,int arr[50][33],int h,int gen)
{int a,fittest[50],i,l[50],z,maximum,j,k[50],m,loc[50],p[50],arrt[50][33]={0};
 fittest[0]=0;
    for(j=1;j<=n;j++){fittest[j]=y[j];}
srand(time(NULL));
for(int t=1;t<=n;t++)
{l[0]=0;
    l[1]=printRandoms(0,n-1,1);
    printf("\nloc=%d\t",l[1]);
    m=l[1];
    maximum=fittest[m];
    for(i=2;i<=s;i++)
    {   l[i]=printRandoms(0,n-1,1);
        printf("loc=%d\t",l[i]);
        if(maximum<fittest[l[i]]){ maximum=fittest[l[i]];}
    }
    p[t]=maximum;
printf("\t%d\n",p[t]);
}
   for(i=0;i<n;i++){ arrt[i][32]=p[i+1];}
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        { if(arrt[i][32]==arr[j][32])
            { for(a=0;a<32;a++){arrt[i][a]=arr[j][a];}
                break;
            }
        }
    }
    printf("----------------------------------------------------------\nBinarystring\n");
    for(i=0;i<n;i++){ for(j=0;j<32;j++){ printf("%d",arrt[i][j]);} printf("\n"); }
singleSideCrossover(n,p,arrt,h,gen,s);
}
int main()
{
int i,j,r,k,l,s,n,sum,n1,gen,n2,h,arr[50][33],count,acct[50],temp[50],maxtemp[50],max,b[50],mattingpool[50][32],MP[50][32],mutate[50][33];
float avg,expct[10];
printf("\nEnter value of population size");
scanf("%d",&n);
printf("\nEnter the crossover point:-");
scanf("%d",&h);
printf("\nEnter the number of generation:-");
scanf("%d",&gen);
sum=0;
for(i=0;i<n;i++)
{ count=0;
	for(j=0;j<32;j++)
	{
	r=rand()%2;
	arr[i][j]=r;
	}
for(k=0;k<32;k++)
    { if(arr[i][k]==1) ++count;
    }
    arr[i][32]=count;
}
printf("Individual\t\t\t\tfitnessvalue\n------------------------------------------------------------------------\n");
for(i=0;i<n;i++)
{ for(j=0;j<31;j++){ printf("%d",arr[i][j]);}
    printf("\t\t\t%d",arr[i][32]);
    printf("\n");
}
for(i=0;i<n;i++){sum=sum+arr[i][32];}
printf("\n--------------------------------------------------------------------------");
printf("\nsum=%d",sum);
avg=((float)sum/(float)n);
printf("\navg=%0.5f",avg);
for(i=0;i<n;i++){ temp[i]=arr[i][32]; }
//-------------------------------------------------------------------------------------------------------------------------------------------
//Tournament Selection Logic
printf("\n------------------------------TOURNAMENTSELECTIONMATTINGPOOL--------------------------------- \n");
           printf("select k random elements for tournament participation");
          scanf("%d",&s);
  tournamentSelection(n,temp,s,arr,h,gen);
}

