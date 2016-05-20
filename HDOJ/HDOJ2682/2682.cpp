#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define INF 0x3f3f3f
#define max 600+50
int map[max][max],visit[max],low[max];
int judge[1000000+1];
int city;
void prime()
{
    int i,j,next;
    int min,mincost=0;
    for(i=1;i<=city;i++)
    {
        visit[i]=0;
        low[i]=map[1][i];
    }
    visit[1]=1;
    for(i=2;i<=city;i++)
    {
        min=INF;
        next=1;
        for(j=1;j<=city;j++)
        {
            if(!visit[j]&&min>low[j])
            {
                min=low[j];
                next=j;
            }
        }
        if(min==INF)
        {
            printf("-1\n");
            return ;
        }
        visit[next]=1;
        mincost+=min;
        for(j=1;j<=city;j++)
        {
            if(!visit[j]&&map[next][j]<low[j])
            low[j]=map[next][j];
        }
    }
    printf("%d\n",mincost);
}
void dabiao()
{
    int i,j;
    memset(judge,0,sizeof(judge));
    for(i=2;i<1000000+1;i++)
    {
    	if(!judge[i])
    	{
    		for(j=2*i;j<1000000+1;j+=i)
    		judge[j]=1;
    	}
    }
    judge[1]=1;
}
int M(int x,int y)
{
    if(x>y)
    return y;
    else
    return x;
}
int main()
{
    int t,i,j,x,y,c;
    int n[max];
    dabiao();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&city);
        for(i=1;i<=city;i++)
        {
            scanf("%d",&n[i]);
            for(j=1;j<=city;j++)
            {
                if(i==j)
                map[i][j]=0;
                else
                map[i][j]=INF;
            }
        }
        for(i=1;i<=city;i++)
        {
            for(j=i+1;j<=city;j++)
            {
                if(!judge[n[i]]||!judge[n[j]]||!judge[n[i]+n[j]])
                {
                    map[i][j]=map[j][i]=M(M(n[i],n[j]),abs(n[i]-n[j]));
                }
            }
        }
        prime();
    }
    return 0;
}
