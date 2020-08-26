#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Assumption code works for only for 10 cities and works for even number of cities
//Assumption those offspring whose fitness will be less will be selected to generate new offspring
int printRandoms(int lower, int upper,int count)
{
    int i,num;
    for (i = 1; i <= count; i++) {
         num = (rand() % (upper - lower + 1)) + lower;
    }
    return num;
}

void tournamentSelection(int n,int y[20],int A[20][20],int u,int r[20][20],int gen)
{
int s,fittest[50],i,l[50],z,maximum,j,k,m,loc[50],p[50],a[20],b[20],c[20],d[20],e[20],f[20],g[20],h[20],o[20],q[20],A1[20][20];
printf("----------------------TournamentSelection------------------------------------------\n");
printf("select k random elements for tournament participation");
          scanf("%d",&s);
for(j=0;j<n;j++){
        //printf("\n\t%d\n",y[j]);
fittest[j]=y[j];
}
for(int t=0;t<n;t++){
l[1]=rand()%n;
printf("\nloc=%d\t",l[1]);
m=l[1];
maximum=fittest[m];
for(i=1;i<s;i++)
{l[i]=rand()%n;
printf("loc=%d\t",l[i]);
if(maximum>fittest[l[i]])
{
    maximum=fittest[l[i]];
}
p[t]=maximum;
}
printf("\t%d\t",p[t]);
}
printf("\n");

//printf("------------------SelectedIndividual-------------------\n");
for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        {
            if(p[i]==y[j])
            {
                for(k=0;k<n;k++)
                {A1[i][k]=A[j][k];
                   // printf("%d ",A1[i][k]);
                }
                break;
            }

        }
for(k=0;k<n;k++){
 switch(i)
          {
            case 0: a[k]=A1[i][k];
                       break;
            case 1: b[k]=A1[i][k];
                       break;
            case 2: c[k]=A1[i][k];
                       break;
            case 3: d[k]=A1[i][k];
                       break;
            case 4: e[k]=A1[i][k];
                       break;
            case 5: f[k]=A1[i][k];
                       break;
            case 6: g[k]=A1[i][k];
                       break;
            case 7: h[k]=A1[i][k];
                       break;
            case 8: o[k]=A1[i][k];
                       break;
            case 9: q[k]=A1[i][k];
                       break;
          }

    }

}
printf("\n");
permutationEncodingCrossover(a,b,c,d,e,f,g,h,o,q,A1,n,u,r,gen);
}


void distanceMatrix(int n,int A[20][20],int u,int gen)
{ int i,j,r[20][20];
srand(time(NULL));
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        if(i==j)
        {
            r[i][j]=0;
        }
        else{

            r[i][j]=r[j][i]=printRandoms(1,n-1,1);
        }
    }

}
fitnessFunction(A,r,n,u,gen);
}
void fitnessFunction(int A[20][20],int r[20][20],int n,int u,int gen)
{ int i,j,sum,fitness[20]={0},a,b,min,loc=0;
//printf("------------------------------------------------------------\nCostCalculatedperIndividual\n");
  //      printf("----------------------------------------------\n");
    for(i=0;i<n;i++)
    {  sum=0;
        for(j=0;j<n;j++)
        {    a=A[i][j];
              b=A[i][j+1];
            sum=sum+r[a][b];
        }
        fitness[i]=sum;
    }
    printf("\n---------------Distance Matrix-----------------------\nIndividual\t\tDistanceMatrix\t\tCostperIndividual\n----------------------------------------------------------\n");
for(i=0;i<n;i++)
{    for(j=0;j<=n;j++)
    {
        printf("%d ",A[i][j]);
    }
    printf("\t");
    for(j=0;j<n;j++)
    {
        printf("%d ",r[i][j]);
    }
    printf("\t");
    printf("\tsum[%d]=%d",i,fitness[i]);
    printf("\n");
}
 min=fitness[0];
loc=0;
   min=fitness[0];
 loc=0;
 for (i =1; i <n; i++)
    {
        if (fitness[i] < min)
        {
           min = fitness[i];
           loc = i;

        }

    }
   printf("------------------------------------------------------------\n");

for(i=0;i<n;i++)
{
    if(fitness[i]==min)
    {
       printf("Minimum cost is %d and path is ",min);
       for(j=0;j<=n;j++)
         {
         printf("%d ",A[i][j]);
         }
         printf("\n");
    }

}



    printf("\n");
printf("------------------------------------------------------------\n");

    tournamentSelection(n,fitness,A,u,r,gen);

}

void permutationEncodingCrossover(int a[20],int b[20],int c[20],int d[20],int e[20],int f[20],int g[20],int h[20],int k[20],int l[20],int A[20][20],int n,int s,int r[20][20],int gen)
{
int i,j,RANGE,temp,temp1,PECO[50],m[50],m1[50],m2[50],m3[50],m4[50],m5[50],m6[50],m7[50],m8[50],m9[50],B[50][50],t[50];
static int p;
srand(time(NULL));
printf("\n---------------------PERMUTATIONENCODINGCROSSOVEROPERATION------------------------------\nSelectedIndividual\tPermutationEncodingCrossOver");
printf("\n----------------------------------------------------------------------------\n");

//crossover opeation
    for(i=0;i<s;i++){
      int o=a[i];
        a[i]=b[i];
        b[i]=o;
        temp=c[i];
        c[i]=d[i];
        d[i]=temp;
     int o1=e[i];
          e[i]=f[i];
          f[i]=o1;
    int o2=g[i];
        g[i]=h[i];
        h[i]=o2;
    int o3=k[i];
    k[i]=l[i];
    l[i]=o3;
}

for(i=0;i<=n-1;i++)
    {
     m[i]=a[i];
    m1[i]=b[i];
    m2[i]=c[i];
    m3[i]=d[i];
    m4[i]=e[i];
    m5[i]=f[i];
    m6[i]=g[i];
    m7[i]=h[i];
    m8[i]=k[i];
    m9[i]=l[i];

    }


for(i=s;i<n;i++){
temp=(rand()%n);
temp1=(rand()%n);
 int temp2=(rand()%n);
int temp3=(rand()%n);
 int temp4=(rand()%n);
int temp5=(rand()%n);



    for(j=0;j<=i-1;j++)
   {
       if(temp==m[j]){
            break;

        }
        if(temp1==m1[j])
        {
            break;
        }
        if(temp2==m2[j])
        {
            break;
        }
        if(temp3==m3[j])
        {
            break;
        }
        if(temp4==m4[j])
        {
            break;
        }
        if(temp5==m5[j])
        {
            break;
        }

   }
             if(i==j)
            {
               m[i]=temp;
       m1[i]=temp1;
       m2[i]=temp2;
     m3[i]=temp3;
      m4[i]=temp4;
      m5[i]=temp5;
            }
            else
            {
                i--;
            }

}


    for(i=s;i<n;i++){

 int temp6=((rand()%n));
int temp7=((rand()%n));
 int temp8=((rand()%n));
int temp9=((rand()%n));

   for(j=0;j<i;j++)
   {
        if(temp6==m6[j])
        {
            break;
        }
        if(temp7==m7[j])
        {
            break;
        }
        if(temp8==m8[j])
        {
            break;
        }
        if(temp9==m9[j])
        {
            break;
        }

   }

    if(i==j)
   {
       m6[i]=temp6;
       m7[i]=temp7;
        m8[i]=temp8;
       m9[i]=temp9;
       }
       else
    {
        i--;
    }
  }

  p=0;
for(j=0;j<n;j++)
      {
          B[p][j]=m[j];

      }
p++;
for(j=0;j<n;j++)
      {
          B[p][j]=m1[j];

      }
p++;
for(j=0;j<n;j++)
      {
          B[p][j]=m2[j];

      }
p++;
for(j=0;j<n;j++)
      {
          B[p][j]=m3[j];

      }
p++;
for(j=0;j<n;j++)
      {
          B[p][j]=m4[j];

      }
p++;
for(j=0;j<n;j++)
      {
          B[p][j]=m5[j];

      }
p++;
for(j=0;j<n;j++)
      {
          B[p][j]=m6[j];

      }
p++;
for(j=0;j<n;j++)
      {
          B[p][j]=m7[j];

      }
p++;
for(j=0;j<n;j++)
      {
          B[p][j]=m8[j];

      }
p++;

for(j=0;j<n;j++)
      {
          B[p][j]=m9[j];

      }


for(i=0;i<n;i++)
{   for(j=0;j<n;j++)
    {
        printf("%d ",A[i][j]);
    }
    printf("\t");
    for(j=0;j<n;j++)
    {
        printf("%d ",B[i][j]);
    }
    printf("\n");
}
tspMutation(B,n,A,s,r,gen);
}
//-----------------------------------------------------------MUTATIONOPERATION-----------------------------------------------------
void tspMutation(int B[50][50],int n,int A[20][20],int s,int r[20][20],int gen)
{
  int i,j,k,l,C[20][20],p;
  int sum,a,b,min,loc,fitness[20],t[20];
  for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            C[i][j]=B[i][j];

        }

    }

    printf("\n------------Mutation Points---------------------\n");
    for(i=0;i<n/2;i++)
    {   l=printRandoms(1,n-1,1);
        k=printRandoms(1,n-1,1);
        j=printRandoms(1,n-1,1);
        printf("row=%d\tindex1=%d\tindex2=%d\n",l,k,j);
        int c=C[l][k];
        C[l][k]=C[l][j];
        C[l][j]=c;
    }
   //calculate fitness and minimum path of it

  for(i=0;i<n;i++)
    {  sum=0;
    C[i][n]=C[i][0];
        for(j=0;j<n;j++)
        {    a=C[i][j];
              b=C[i][j+1];
            sum=sum+r[a][b];
        }

        fitness[i]=sum;
    }
    printf("\n--------------------------GeneticOperation-------------------------\nDistanceMatrix\t\tSelectedIndividual\tCrossover\t\tMutation\t\tmutateCostPerIndividual\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",r[i][j]);
        }
        printf("\t");
        for(j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\t");
        for(j=0;j<n;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\t");
        for(j=0;j<=n;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\t");
        printf("sum[%d]=%d",i,fitness[i]);
        printf("\n");
    }

    min=fitness[0];
 loc=0;
 for (i =1; i <n; i++)
    {
        if (fitness[i] < min)
        {
           min = fitness[i];
           loc = i;

        }

    }
   printf("------------------------------------------------------------\n");

for(i=0;i<n;i++)
{
    if(fitness[i]==min)
    {
       printf("Minimum cost is %d and path is ",min);
       for(j=0;j<=n;j++)
         {
         printf("%d ",C[i][j]);
         }
         printf("\n");
    }

}


    printf("\n");
printf("------------------------------------------------------------\n");

static int v;
if(v<gen)
{
printf("-----------------------%d th generation-------------------------------------\n",v+1);
v++;
    fitnessFunction(C,r,n,s,gen);
 // gen--;
}
//
}

//------------------------------------------------------------------------------------------------------------------------------------------

void permutationEncoding(int s,int city,int gen)
{
int a[20],b[20],c[20],d[20],e[20],f[20],g[20],h[20],k[20],l[20],A[20][20];
int i,j,temp,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,min=0,m;
static int p;

printf("enter starting city");
scanf("%d",&m);
a[0]=m; b[0]=m;c[0]=m; d[0]=m; e[0]=m;
 f[0]=m; g[0]=m; h[0]=m; k[0]=m; l[0]=m;
for(i=0;i<=city;i++)
 {

         if(i==city)
         {
             a[i]=b[i]=c[i]=d[i]=e[i]=f[i]=h[i]=g[i]=k[i]=l[i]=m;
         }

 }
srand(time(NULL));
 for(i=1;i<city;i++)
 {
temp=((rand()%city));
temp1=((rand()%city));
temp2=((rand()%city));
temp3=((rand()%city));
temp4=((rand()%city));
temp5=((rand()%city));

   for(j=0;j<=i-1;j++)
   {
       if(temp==a[j]){
            break;

        }
        if(temp1==b[j]){
            break;

        }
        if(temp2==c[j]){
            break;

        }
        if(temp3==d[j]){
            break;

        }
        if(temp4==e[j]){
            break;

        }
        if(temp5==f[j]){
            break;

        }
        }

   if(i==j)
   {
      a[i]=temp;
       b[i]=temp1;
       c[i]=temp2;
       d[i]=temp3;
       e[i]=temp4;
       f[i]=temp5;
      g[i]=temp6;
       h[i]=temp7;
       k[i]=temp8;
     l[i]=temp9;

   }
   else
    {
        i--;
    }
 }

 for(i=1;i<city;i++)
 {temp6=((rand()%city));
temp7=((rand()%city));
temp8=((rand()%city));
temp9=((rand()%city));
 for(j=0;j<=i-1;j++)
   {
        if(temp6==g[j]){
            break;

        }
        if(temp7==h[j]){
            break;

        }
        if(temp8==k[j]){
            break;

        }
       if(temp9==l[j]){
           break;

        }
   }
    if(i==j)
   {

      g[i]=temp6;
       h[i]=temp7;
       k[i]=temp8;
     l[i]=temp9;

   }
   else
    {
        i--;
    }

 }
     p=0;
for(j=0;j<=city;j++)
      {
          A[p][j]=a[j];

      }
p++;
for(j=0;j<=city;j++)
      {
          A[p][j]=b[j];

      }
p++;
for(j=0;j<=city;j++)
      {
          A[p][j]=c[j];

      }
p++;
for(j=0;j<=city;j++)
      {
          A[p][j]=d[j];

      }
p++;
for(j=0;j<=city;j++)
      {
          A[p][j]=e[j];

      }
p++;
for(j=0;j<=city;j++)
      {
          A[p][j]=f[j];

      }
p++;
for(j=0;j<=city;j++)
      {
          A[p][j]=g[j];

      }
p++;
for(j=0;j<=city;j++)
      {
          A[p][j]=h[j];

      }
p++;
for(j=0;j<=city;j++)
      {
          A[p][j]=k[j];

      }
p++;

for(j=0;j<=city;j++)
      {
          A[p][j]=l[j];

      }
printf("\n");


distanceMatrix(city,A,s,gen);
//permutationEncodingCrossover(a,b,c,d,e,f,g,h,k,l,A,city,s);
}
void main()
{
    int k,city,gen;
    printf("Enter the population size");
scanf("%d",&city);

    printf("Enter a crosspoint");
scanf("%d",&k);
printf("Enter number of generation");
scanf("%d",&gen);
    permutationEncoding(k,city,gen);

}
