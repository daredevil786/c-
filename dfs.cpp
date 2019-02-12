#include<stdio.h>
int a[20][20],reach[20],n;
void dfs(int v)
{
int i;
reach[v]=1;
for(i=1;i<=n;i++)
if(a[v][i]&&!reach[i])
{
printf("\n %d->%d",v,i);
dfs(i);
}
}
int main()
{
  int l,j,count=0;
  char scr(); 
  printf("\n Enter number of vertices:");
  scanf("%d",&n);
  for(l=1;l<=n;l++)
  {
   reach[l]=0;
   for(j=1;j<=n;j++)
   a[l][j]=0;
  }
printf("\n Enter the adjacency matrix:\n");
for(l=1;l<=n;l++)
for(j=1;j<=n;j++)
scanf("%d",&a[l][j]);
dfs(1);
printf("\n");
for(l=1;l<=n;l++)
{
if(reach[l])
count++;
}
if(count==n)
printf("\n Graph is connected");
else
printf("\n Graph is not connected");
}
