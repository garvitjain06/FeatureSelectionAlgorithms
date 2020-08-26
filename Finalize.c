#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define RAND_MAX 10000
int printRandoms(int lower, int upper,int count)
{  int i,num;
    for (i = 1; i <= count; i++) {
         num = (rand() % (upper - lower + 1)) + lower;
    }
    return num;
}
int fitnessFunction(int m){
   int i,f;
        f=2*m;
        printf("\nfitness value=%d\n",f);
return f;
}
void decToBinaryString(int n[50],int m)
{int i,j,l[50];
int binarynum[11][11]={0};
for(i=1;i<=m;i++)
{ l[i]=n[i];
	j=10;
	while(n[i]>0)
	{ binarynum[i][j]=n[i]%2;
		n[i]=n[i]/2;
		j--;
	}
}
printf("\n");
for(i=m;i>=1;--i){ for(j=1;j<=10;j++){ printf("%d",binarynum[i][j]);} printf("\n");}
}
void decToBin(int f1)
{int i;
int c, k;
  for (c =11; c >= 0; c--)
  {   k = f1 >> c;
    if (k & 1) printf("1");
    else printf("0");
  }
printf("\t");
}
int displaySelection(int f1,int n,int a[50]){
int k;
printf("\t%d\t",f1);
       printf("\t");
       decToBin(f1);
        printf("\n");
return f1;
}
void tournamentSelection(int n,int y[50],int s)
{
int fittest[50],i,l[50],z,maximum,j,k[50],m,loc[50],p[50];
for(j=1;j<=n;j++){ fittest[j]=y[j];}
for(int t=1;t<=n;t++){
l[1]=printRandoms(1,n,1);
printf("\nloc=%d\t",l[1]);
m=l[1];
maximum=fittest[m];
for(i=2;i<=s;i++)
{l[i]=printRandoms(1,n,1);
printf("loc=%d\t",l[i]);
if(maximum>fittest[l[i]]){maximum=fittest[l[i]];}
}
p[i]=displaySelection(maximum,n,y);
}
}
//---------------------------------------------------------CanonicalSelection-------------------------------------------------------------
float calculateSum(int f[50],int n){
    int i;
    float sum=0.0;
    for(i=1;i<=n;i++){sum=sum+f[i];}
    printf("\n----------------------------------------------------------------------------------------------------------");
    printf("\nsum=%f\n",sum);
    return sum;
}
int calculateAvg(float s,int n){
  float avg=(s/n);
  printf("average=%f\n",avg);
  return avg;
}
void display(int s[50],float act_cnt[50],int n[50],int p[50],int d[50],float exp_cnt[50],int k){
printf("\n|---------------------------------------CANONICALSELECTION-------------------------------------------------------|\nBinaryString\t\tIndividual  fitnessValue  ExpectedCount  ActualCount\n");
      int m,t[50],l,i,cnt=0;
       for( i=1;i<=k;i++){
                   m=s[i];
              decToBin(m);
       printf("   \t %d\t \t %d \t   %f     %f\n",n[i],s[i],exp_cnt[i],act_cnt[i]);
       }
       printf("\n|----------------------------------CANONICALSELECTION MattingPool-----------------------------------------|");
      for(int j=1;j<=k;j++){
             if(act_cnt[j]>=1){
                for(i=1;i<=act_cnt[j];i++){
                   printf("\nindividual=%d\t",j);
                   l=++cnt;
                  t[j]=s[j];
                  m=t[j];
              printf("MattingPoolfitnessValue=%d\t",t[j]);
               decToBin(m);
                }cnt=0;
                printf("count= %d\t",l);
             }
         }
}
void calculateNewMattingPool(float actcnt[50],int n[50],int p[50],int s[50],float exp_cnt[50],int t){
int m,j,l[50],k[50],cnt=0;
for(int i=1;i<=t;i++){
if(actcnt[i]>0){
   if(actcnt[i]>=1){
     for(j=1;j<=actcnt[i];j++){ m=n[i];}
   }
      else{ m=n[i]; decToBin(m);}
}
}
display(s,actcnt,n,p,k,exp_cnt,t);
}
void canonicalSelection(float s1[50],int a[50],int k[50],int exp_cnt[50],int n){
int i;
double partialnumber = 0.0;
int pick[50] ;
partialnumber=0.0;
 for(i=1;i<=n;i++){ if (s1[i] > partialnumber) { pick[i] = i;} }
calculateNewMattingPool(s1,a,pick,k,exp_cnt,n);
}
void calculateExpectedCount(int b[50],float z,int j[50],int n){
    float exp_cnt[50];
    float actualcnt[50];
    int i;
    for(i=1;i<=n;i++){ exp_cnt[i]=b[i]/z;}
        for(i=1;i<=n;i++){ actualcnt[i]=round(exp_cnt[i]);}
    canonicalSelection(actualcnt,j,b,exp_cnt,n);
}
//--------------------------------------------greedyoverselection--------------------------------------------------------------------
void greedyOverSelectionDisplay(int a[50],int b[50],int n){
int fittest[50],fittest1[50],i,temp,z,s;
int v,l;
printf("\n");
printf("\n------------------------------GREEDYOVERSELECTIONMATTINGPOOL--------------------------------- \n");
printf("fitnessvalue\tBinaryString\n");
    v= (n*80/100);
    l=ceil((double)n*20/100.0);
    for(i=1;i<=n;i++){ if(i<=v){ fittest[i]=a[i];}}
    for(i=1;i<=l;i++){ fittest1[i]=b[i]; }
    printf("select k random elements for tournament participation");
          scanf("%d",&s);
 tournamentSelection(v,fittest,s);
        tournamentSelection(l,fittest1,s);
 }
void greedyOverSelection(int a[50],int m){
    int w[50],n,b[50],l=1,k=1,z,y;
 for(int i=1; i<=m; ++i){
    for(int j=1; j<=m-i; ++j){
  if (a[j]<a[j+1]){
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
printf("\n--------------------------------GREEDYOVERSELECTION-------------------------------------------------------------\nfitnessValue\t BinaryString\n");
  for(n=1;n<=m;n++){
int v=((m*80)/100);
if(n<=v){
    b[l]=a[n];
    z=b[l];
    printf("\n%d\t\t",b[l]);
    decToBin(z);
    l++;
}else{
w[k]=a[n];
y=w[k];
printf("\n%d\t\t",w[k]);
decToBin(y);
k++;
}
  }
greedyOverSelectionDisplay(b,w,m);
}
//---------------------------------ROULLETEWHEELSELECTION-----------------------------------------------------
int calculateIndividualWeight(int b[50],float totalsum,int k[50],int n){
    int i;float weight[50],m[50];
    float probability[50],s[50],a[50],c[50],d[50],e[50];
    int t;
float r;
     printf("------------------probability rate for each Individual----------------\n");
    for(i=1;i<=n;i++){
        weight[i]=(b[i]/(totalsum));
       m[i]=round(weight[i]);
       printf("weight of each fitness=%f \n",weight[i]);
    }
probability[0]=0.0;
printf("----------------------------------CUMMULATIVEPROBABILITY---------------------------------------\n");
    for(i=1;i<=n;i++)
        {  probability[i]=probability[i-1]+weight[i];
           printf("%d\tcummulativeprobability=%f\n",i,probability[i]);
        }
    printf("\n");
    printf("-----------------------------------GENERATINGRANDOMNUMBER-----------------------------------\nsno\tfitness\tprobability\tcummulativeProbability(J)\trandomnumber(I)\t\n");
srand(time(NULL));
int j;
for (j=1;j<=n;j++){
   r=printRandoms(1,10000,1);
        s[j]=r/RAND_MAX;
       printf("\n%d\t%d\t%f\t%f\t\t\t%f\t",j,b[j],weight[j],probability[j],s[j]);
}
printf("\n--------------------------------------SELECTIONMATTINGPOOL-----------------------------------------\njth\tith\tSelectedCummulativeprobability(J)\tSelectedrandomnumber(I)\t      Tally\n");
    for(int j=1;j<=n;j++)
    { int   cnt=0;
        for(i=1;i<=n;i++)
            {if(probability[j-1]<=s[i] && s[i]<=probability[j])
        {c[i]=s[i];
                 d[j]=probability[j];
                 cnt++;
              a[j]=cnt;
           printf("\n%d\t%d\t\t\t%f\t\t\t%f\t",j,i,d[j],c[i]);
        }
    }
if(cnt>=1 && cnt<=5) printf("\t%f",a[j]);
  }
}
float calculateTotalSum(int f[50],int k[50],int n){
    int i;
    float sum=0.0;
    for(i=1;i<=n;i++){ sum=sum+f[i]; }
    printf("\n----------------------------------------------------------------------------------------------------------");
    printf("\nsum=%f\n",sum);
    calculateIndividualWeight(f,sum,k,n);
    return sum;
}
int calIndividualWeight(int b[50],float totalsum,int k[50],int n){
    int i;float weight[50],m[50];
    float probability[50],s[50],a[50],c[50],d[50],e[50];
    int t;
float r;
    for(i=1;i<=n;i++){ weight[i]=(b[i]/(totalsum)); m[i]=round(weight[i]);}
probability[0]=0.0;
    for(i=1;i<=n;i++){  probability[i]=probability[i-1]+weight[i];}
    printf("\n");
    printf("-----------------------------------RANKSELECTION-----------------------------------\nsno\tfitness\tprobability\tcummulativeProbability(J)\trandomnumber(I)\t\n");
srand(time(NULL));
int j;
for (j=1;j<=n;j++){
   r=printRandoms(1,10000,1);
        s[j]=r/RAND_MAX;
       printf("\n%d\t%d\t%f\t%f\t\t\t%f\t",j,b[j],weight[j],probability[j],s[j]);
}
printf("\n--------------------------------------SELECTIONMATTINGPOOL-----------------------------------------\njth\tith\tSelectedCummulativeprobability(J)\tSelectedrandomnumber(I)\t      Tally\n");
    for(int j=1;j<=n;j++)
    {int   cnt=0;
   for(i=1;i<=n;i++)
    { if(probability[j-1]<=s[i] && s[i]<=probability[j])
        {       c[i]=s[i];
                 d[j]=probability[j];
                 cnt++;
              a[j]=cnt;
           printf("\n%d\t%d\t\t\t%f\t\t\t%f\t",j,i,d[j],c[i]);
        }
    }
if(cnt>=1 && cnt<=5) printf("\t%f",a[j]);
  }
}
float calTotalSum(int f[50],int k[50],int n){
    int i;
    float sum=0.0;
    for(i=n;i>=1;i--){ sum=sum+f[i];}
    printf("\n----------------------------------------------------------------------------------------------------------");
    printf("\nsum=%f\n",sum);
    calIndividualWeight(f,sum,k,n);
    return sum;
}
void sortFitness(int k[50],int s[50],int n )
{ int i,j,a,b,l[50];
    float m[50];
    float sum=0.0;
    for (i = 1; i <=n; ++i)
        { for (j = i + 1; j <=n; ++j)
            { if (k[i] > k[j])
                { a = k[i];
                    k[i] = k[j];
                    k[j] = a;
                    b= s[i];
                    s[i]=s[j];
                    s[j]=b;
                }
            }
        }
 printf("\n---------------------------------------------------------\nRank\tfitnessvalue\tvalue\tProbability\n");
        for (i = n; i >= 1; --i){ l[i]=i; sum=sum+k[i]; }
        for(i=n;i>=1;i--){  m[i]=(k[i]/sum)*100; printf("\n %d\t%d\t\t%d\t%f",l[i],k[i],s[i],m[i]);}
        calTotalSum(k,s,n);
}

//-------------------------------------------------------------------------------------------------------------------------
void main()
{ int n,k,ch,RANGE,z,i,y[50],l[50],t,s;
printf("\nEnter Population Size");
scanf("%d",&n);
printf("enter the range");
scanf("%d",&RANGE);
srand(time(NULL));
           for(i=1;i<=n;i++){
          z=rand()%RANGE;
          l[i]=z;
          printf("\nindividual=%d\n value= %d\n",i,z);
           y[i]= fitnessFunction(z);
           }
do{
printf("\nEnter the selection Mechanism you want to perform\n1)TournamentSelection\n2)CanonicalSelection\n3)roulleteWheelSelection\n4)RankSelection\n5)greedyOverSelection\n6)Exit");
printf("\nEnter your choice");
scanf("%d",&ch);
switch(ch)
{case 1: printf("\n------------------------------TOURNAMENTSELECTIONMATTINGPOOL--------------------------------- \n");
           printf("select k random elements for tournament participation");
          scanf("%d",&s);
        tournamentSelection(n,y,s);
        break;
 case 2:t=calculateSum(y,n);
            s=calculateAvg(t,n);
           calculateExpectedCount(y,s,l,n);
          break;
 case 3: calculateTotalSum(y,l,n); break;
 case 4:  sortFitness(y,l,n); break;
 case 5:  greedyOverSelection(y,n); break;
 case 6: exit(0);
}
}while(ch!=6);
}
