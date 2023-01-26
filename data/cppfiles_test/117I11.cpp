#include<bits/stdc++.h>
#define lson rt<<1
#define rson rt<<1|1
#define pb push_back
#define x first 
#define y second
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
inline ll read()
{
	char ch=getchar();ll ret=0,f=1;
	while(ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	for(;ch>='0' && ch<='9';ch=getchar()) ret=ret*10ll+ch-'0';
	return ret*f;
}
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n,m;
vector<bool>g[1000010];
string s[1000010];
int main()
{
	IOS
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int x,y;
		for(int i=1;i<=n;i++)cin>>s[i],s[i]='#'+s[i];
		for(int i=1;i<=n;i++){
		    g[i].pb(0);
			for(int j=1;j<=m;j++){
			    g[i].pb(0);
				if(s[i][j]=='L'){
					x=i,y=j;
				}
			}
		}
		queue<pii>q;
		q.push({x,y});
		while(q.size()){
	        int x1=q.front().x,y1=q.front().y;
	        q.pop();
	        g[x1][y1]=1;
	        for(int i=0;i<4;i++){
	            int xx=x1+dx[i],yy=y1+dy[i];
	            if(xx>n||xx<1||yy<1||yy>m||g[xx][yy]||s[xx][yy]=='#')continue;
	            int cnt=0;
	            for(int j=0;j<4;j++){
	                int x2=xx+dx[j],y2=yy+dy[j];
	                 if(x2>n||x2<1||y2<1||y2>m||s[x2][y2]=='#')continue;
	                 cnt++;
	            }
	            if(cnt<=2){
                    s[xx][yy]='+';
	                q.push({xx,yy});
	            }
	        }
		}
		
		for(int i=1;i<=n;i++){
		    g[i].clear();
		    for(int j=1;j<=m;j++){
		        cout<<s[i][j];
		    }
		    cout<<endl;
		}
	}
    return 0;
}
           