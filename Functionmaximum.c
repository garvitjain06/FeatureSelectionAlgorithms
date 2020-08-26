#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int printRandoms(int lower, int upper,int count)
{ int i,num;
    for (i = 1; i <= count; i++) {
         num = (rand() % (upper - lower + 1)) + lower;
    }
    return num;
}
float fitnessFunction(int m){
   int i;
   float f;
  f=((2*(m*m))-m)/8.0;
return f;
}
float calculateSum(float f[50],int n){
    int i;
    float sum=0.0;
    for(i=1;i<=n;i++){ sum=sum+f[i]; }
    printf("\n--------------------------------------------------------------------------------");
    printf("\nsum=%f\n",sum);
    return sum;
}
float calculateAvg(float s,int n){
  float avg=(s/n);
  printf("average=%f\n",avg);
  return avg;
}
void calcuateMaxFitnessFunction(float m[50],int n,int z[50]){
    float maximum;
    int  c, location;
  maximum = m[1];
location=1;
  for (c = 2; c <= n; c++)
  { if (m[c] > maximum)
    { maximum  = m[c];
       location = c;
    }
  }
  printf("Maximum fitness is %f and individual value correspond to it is %d\n", maximum,z[location]);
  printf("---------------------------------------------------------------------------------------------");
}
void decToBinaryString(int n,int m,int o)
{int i,j,l[50];
int binarynum[10][10]={0};
for(i=0;i<m;i++)
{ l[i]=n;
	j=o-1;
	while(n>0)
	{ binarynum[i][j]=n%2;
		n=n/2;
		j--;
	}
}
for(i=0;i<1;i++){ for(j=0;j<5;j++){ printf("%d",binarynum[i][j]); } printf("\n");}
}
void MutationOperation(int CO[50][50],int n,int o,int arr[50][50],int g[50],int s,int p,int gen)
{ int mutate[50][50],i,j,k,l,n1,n2,decnum=0,rem,a[50],z;
float d[50],e[50];
static int t=1;
int ar1[50];
    printf("-------------------------------------------MUTATIONOPERATION----------------------------------------------------\n");
for(i=1;i<=n;i++){ for(j=1;j<=5;j++){ mutate[i][j]=CO[i][j];}}
printf("loc1\tloc2\n");
srand(time(NULL));
for(j=1;j<=n;j++){
       n1=rand()%n;
       n2=rand()%5;
        if(mutate[n1][n2]==1){mutate[n1][n2]=0;}
        else{ mutate[n1][n2]=1;}
printf("%d\t%d\n",n1,n2);
}
printf("\n--------------------------------------------------------------------------------\n");
printf("\nmattingpool   crossover   mutation\n");
for(i=1;i<=n;i++)
{ for(j=1;j<=5;j++){ printf("%d",arr[i][j]);}
  printf("\t\t");
	for(k=1;k<=5;k++){ printf("%d",CO[i][k]); }
	printf("\t  ");
for(l=1;l<=5;l++){printf("%d",mutate[i][l]);}
	printf("\n");
}
for(i=1;i<=n;i++)
{	ar1[i-1]=0;
    for(j=5,k=0;j>=1;j--,k++)
    {
	ar1[i-1]=mutate[i][j]*(pow(2,k))+ar1[i-1];
    }
}
printf("\n--------------------------\nindividualvalue\tFitnessValue\n");
for(i=0;i<n;i++)
{ z=ar1[i];
   e[i]=fitnessFunction(z);
printf("%d\t\t  %f\n",ar1[i],e[i]);
}
float y=calculateSum(e,n);
calculateAvg(y,n);
calcuateMaxFitnessFunction(e,n,ar1);
if(t<gen){
    printf("--------------------------------------%d Generation-------------------------------------------------\n",(t+1));
printf("Sno.\t IndividualValue    FitnessValue\n");
 for(i=0;i<n;i++){
          z=ar1[i];
           d[i]= fitnessFunction(z);
           printf("\n%d\t  %d\t\t\t %f\n",i,ar1[i],d[i]);
           }
        t++;
printf("\n------------------------------TOURNAMENTSELECTIONMATTINGPOOL--------------------------------- \n");
 tournamentSelection(n,o,ar1,d,s,p,gen);
}
}
void singleSideCrossover(int g[50],int n,int o,int k,int s,int gen)
{ int i,j,r,CO[50][50],arr[50][50];
    for(i=1;i<=n;i++)
        { j=5;
             while(g[i]>0){
                arr[i][j]=g[i]%2;;
                g[i]=g[i]/2;
                j--;
            }
        }
for(i=1;i<=n;i++){ for(j=1;j<=5;j++){ CO[i][j]=arr[i][j];}}

for(i=1;i<=n;i=i+2){
    for(j=1;j<=k;j++){
       int   l=CO[i][j];
        CO[i][j]=CO[i+1][j];
        CO[i+1][j]=l;
    }
}
MutationOperation(CO,n,o,arr,g,s,k,gen);
}
void tournamentSelection(int n,int o,int q[50],float y[50],int s,int k,int gen)
{
float fittest[50],maximum,g[50];
int i,l[50],z,j,m,loc[50],p[50],e[50],w;
for(j=1;j<=n;j++){fittest[j]=y[j];}
for(int t=1;t<=n;t++){
l[1]=printRandoms(1,n,1);
printf("\nloc=%d\t",l[1]);
m=l[1];
w=q[m];
maximum=fittest[m];
for(i=2;i<=s;i++)
{l[i]=printRandoms(1,n,1);
printf("loc=%d\t",l[i]);
if(maximum<fittest[l[i]]){
maximum=fittest[l[i]];
w=q[l[i]];
}
}
g[t]=maximum;
e[t]=w;
printf("\t%d\t%f\t",e[t],g[t]);
decToBinaryString(w,n,o);
}
singleSideCrossover(e,n,o,k,s,gen);
}
void main()
{ int n,z,s,l[50],RANGE,i,k,v[50],gen,o;
float y[50],t,u;
 printf("\nEnter Population Size");
scanf("%d",&n);
 printf("\nEnter chromosome  Size");
scanf("%d",&o);
printf("enter the range between 0 to 30");
scanf("%d",&RANGE);
printf("\nEnter number of generation");
scanf("%d",&gen);
printf("Enter the value of crosspoint\n");
scanf("%d",&k);
printf("Sno.\t IndividualValue\tFitnessValue\n");
srand(time(NULL));
 for(i=1;i<=n;i++){
          z=rand()%RANGE;
          l[i]=z;
           y[i]= fitnessFunction(z);
           printf("\n%d\t  %d\t\t\t %f\n",i,z,y[i]);
           }
        t= calculateSum(y,n);
        u=calculateAvg(t,n);
        calcuateMaxFitnessFunction(y,n,l);
           printf("\n------------------------------TOURNAMENTSELECTIONMATTINGPOOL--------------------------------- \n");
           printf("select k random elements for tournament participation");
          scanf("%d",&s);
tournamentSelection(n,o,l,y,s,k,gen);
}
