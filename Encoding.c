#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void decToBinaryString(int n[50],int m)
{ int i,j,l[50];
int binarynum[10][10]={0};
for(i=0;i<m;i++){ l[i]=n[i]; j=10-1;
	while(n[i]>0){ binarynum[i][j]=n[i]%2;
		n[i]=n[i]/2;
		j--;
	}
}
for(i=0;i<n;i++){ for(j=0;j<m;j++){printf("%d",binarynum[i][j]);} printf("\n");}
}
void binaryEncoding(int n,int m)
{int i,j,r,arr[50][50];
 for(i=0;i<n;i++)
{for(j=0;j<m;j++){r=rand()%2; arr[i][j]=r;}
}
printf("Individual\n------------------------------------------------------------------------\n");
for(i=0;i<n;i++){  for(j=0;j<m;j++){printf("%d",arr[i][j]);} printf("\n"); }
}
//-------------------------Permutation Encoding-----------------------------------------------------------------------
void permutationEncoding(int city)
{int a[20],b[20],c[20],d[20],e[20],f[20],g[20],h[20],k[20],l[20],A[20][20];
int i,j,temp,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,min=0,m;
static int p;
srand(time(NULL));
 for(i=0;i<city;i++){
temp=((rand()%city));
temp1=((rand()%city));
temp2=((rand()%city));
temp3=((rand()%city));
temp4=((rand()%city));
temp5=((rand()%city));
 for(j=0;j<=i-1;j++)
   {    if(temp==a[j]){break;}
        if(temp1==b[j]){break;}
        if(temp2==c[j]){break;}
        if(temp3==d[j]){break;}
        if(temp4==e[j]){break;}
        if(temp5==f[j]){break;}
        }
if(i==j){a[i]=temp; b[i]=temp1; c[i]=temp2; d[i]=temp3; e[i]=temp4;
       f[i]=temp5; g[i]=temp6; h[i]=temp7; k[i]=temp8; l[i]=temp9;}
else{i--;}
 }
 for(i=0;i<city;i++)
 {temp6=((rand()%city));
 temp7=((rand()%city));
 temp8=((rand()%city));
 temp9=((rand()%city));
 for(j=0;j<=i-1;j++)
   {     if(temp6==g[j]){break;}
        if(temp7==h[j]){break;}
        if(temp8==k[j]){break;}
       if(temp9==l[j]){break;}
   }
    if(i==j){g[i]=temp6; h[i]=temp7; k[i]=temp8; l[i]=temp9;}
   else{i--;}
 }
     p=0;
for(j=0;j<city;j++){ A[p][j]=a[j];}
p++;
for(j=0;j<city;j++){ A[p][j]=b[j];}
p++;
for(j=0;j<city;j++){ A[p][j]=c[j];}
p++;
for(j=0;j<city;j++){A[p][j]=d[j];}
p++;
for(j=0;j<city;j++){A[p][j]=e[j];}
p++;
for(j=0;j<city;j++){A[p][j]=f[j];}
p++;
for(j=0;j<city;j++){A[p][j]=g[j];}
p++;
for(j=0;j<city;j++){A[p][j]=h[j];}
p++;
for(j=0;j<city;j++){A[p][j]=k[j];}
p++;
for(j=0;j<city;j++){A[p][j]=l[j];}
printf("\n");
for(i=0;i<city;i++){for(j=0;j<city;j++){printf("%d ",A[i][j]);} printf("\n");}
}
//-----------------------------------------VALUEENCODING-----------------------------------------------------------------------------
void valueEncoding(int n,int RANGE,int m)
{ int i ,a[50][50],j,g;
float d[50][50],k;
char f[30][30],w[30][30];
 char b[30][26]={{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'},
 };
 char e[50][50]={{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'}
 };
 char c[30][30];
 int h[30][30];
 srand(time(NULL));
 for(i=0;i<n;i++)
 {for(j=0;j<m;j++){
        k=rand()%RANGE;
   a[i][j]=rand()%n;
    d[i][j]=k/RAND_MAX;
    h[i][j]=rand()%2;
  }
 }
srand(time(NULL));
for(i=0;i<n;i++){
     for(j=0;j<m;j++){
       int k=rand()%26;
       g=rand()%26;
     c[i][j]=b[i][k];
     f[i][j]=e[i][g];
}
 }
for(i=0;i<(n/5);i++)
 {for(j=0;j<m;j++){printf("%d\t",a[i][j]);}
     printf("\n");
     for(j=0;j<m;j++){printf("%0.3f\t",d[i][j]);}
     printf("\n");
     for(j=0;j<m;j++){printf("%c\t",c[i][j]);}
printf("\n");
for(j=0;j<m;j++){printf("%c\t",f[i][j]);}
printf("\n");
for(j=0;j<m;j++){printf("%d\t",h[i][j]);}
printf("\n");}
}
//---------------------------------------------TREEENCODING-------------------------------------------------------------------------------
void treeEncoding(int n,int m)
{ int a[30][30];
 char b[30][30]={{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},
 {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'}
 };
 char c[30][30]={{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'}
, {'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'}
,{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'}
,{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'},{'+','-','*','/','^'}};
 char d[30][30];
 int k,j,i,h,s,l;
srand(time(NULL));
for(i=0;i<n;i++){
if(m%2==0){
 for(j=0;j<=m;j++){
     a[i][j]=rand()%n;
    s=rand()%15;
    k=rand()%5;
 if(j%2==0){d[i][j]=b[i][s];}
 else{d[i][j]=c[i][k];}
 }
}
 else{
    for(j=0;j<=m-1;j++){
     a[i][j]=rand()%n;
    s=rand()%15;
    k=rand()%5;
 if(j%2==0){d[i][j]=b[i][s];}
 else{d[i][j]=c[i][k];}
 }
 }
}
printf("\n");
if(n%2==0){
d[i][n]=b[i][j];
for(i=0;i<n;i++){ for(j=0;j<=m;j++){printf("%c",d[i][j]);} printf("\n");}
}
else{
for(i=0;i<n;i++){ for(j=0;j<=m;j++){printf("%c",d[i][j]);} printf("\n"); }
}
}
//---------------------------------------------------------------------------------------------------------------------------------
void main()
{ int ch,n,RANGE=500,m;
printf("\nEnter the number of population size:-");
scanf("%d",&n);
printf("\nEnter the number of chromosome size:-");
scanf("%d",&m);
do{
printf("\n1)Binary Encoding\n2)Permutation Encoding\n3)Value Encoding\n4)Tree Encoding\n 5)Exit");
printf("\nEnter your choice:-");
scanf("%d",&ch);
switch(ch){ case 1: binaryEncoding(n,m); break;
case 2: permutationEncoding(n); break;
case 3:valueEncoding(n,RANGE,m); break;
case 4: treeEncoding(n,m); break;
case 5: exit(0);
}
}while(ch!=5);
}
