#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
typedef pair<int,int> PII; 
const int N=2010;
int n,m,cnt;
int dist[N][N];
bool st[N][N];
char g[N][N];
PII p[N];

int dfs(int x,int y){
	p[++cnt]={x,y};
	if(x<1||x>n||y<1||y>m||st[x][y]) return dist[x][y];
	st[x][y]=true;
	
	auto &k=dist[x][y];
	if(g[x][y]=='U') k=dfs(x-1,y)+1;
	if(g[x][y]=='D') k=dfs(x+1,y)+1;
	if(g[x][y]=='L') k=dfs(x,y-1)+1;
	if(g[x][y]=='R') k=dfs(x,y+1)+1;
	
	return dist[x][y];
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>g[i][j];
	
	for(int i=0;i<=n+5;i++)
	for(int j=0;j<=m+5;j++)
	st[i][j]=false,dist[i][j]=0;
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		if(!st[i][j]){
			cnt=0;
			dfs(i,j);
			
			PII t=p[cnt];
			for(int k=1;k<=cnt;k++)
			if(t==p[k]){
				for(int h=k;h<=cnt;h++)
				dist[p[h].x][p[h].y]=cnt-k;
			}
		}
	}
	
	int x=0,y=0,res=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		if(dist[i][j]>res)
			x=i,y=j,res=dist[i][j];
			
	cout<<x<<" "<<y<<" "<<res<<endl;		
	
}

main(){
	int T;
	cin>>T;
	while(T--)solve(); 
}
