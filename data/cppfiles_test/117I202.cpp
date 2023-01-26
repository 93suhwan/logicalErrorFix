//#pragma GCC optimize(2)
//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int inf=8e18;
const int maxn=2e5+100;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int n,m;
signed main()
{
	//IOS
	int tt;
	cin>>tt;
	while(tt--)
	{
		int px,py;
		cin>>n>>m;
		char a[n+10][m+10];
		bool vis[n+10][m+10]={0};
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='L') 
				{
					px=i;py=j;
				}
			}
		}
		queue<pii>q;
		q.push({px,py});
		while(!q.empty())
		{
			auto now=q.front();
			q.pop();
			if(a[now.fi][now.se]=='.') a[now.fi][now.se]='+';
			//int cnt=0;
			for(int i=0;i<4;i++)
			{
				int x=now.fi+dir[i][0];
				int y=now.se+dir[i][1];
				if(vis[x][y]||a[x][y]!='.')continue;
				int cnt=0;
				for(int j=0;j<4;j++)
				{
					if(abs(j-i)==2)continue;
					int xx=x+dir[j][0];
					int yy=y+dir[j][1];
					if(xx>n||xx<1||yy>m||yy<1)cnt++;
					else if(a[xx][yy]!='.')cnt++; 
				}
				if(cnt>=2) {a[x][y]='+';q.push({x,y});vis[x][y]=1;}
			}	
		}	
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<a[i][j];
			}
			cout<<"\n";
		}	
	}
}
/*
3 4
#...
.L#.
....
*/

