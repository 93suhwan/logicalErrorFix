#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
using namespace std;
#define ll long long
#define pb push_back
#define vl vector<ll>
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

int n, m;
char mat[2002][2002];
int vis[2002][2002];
int vis1[2002][2002];
ll dfs(int i,int j){
    if(i<0|| i>=n|| j<0 || j>=m||vis1[i][j]==1)return 0;
    if(vis[i][j]!=0)return vis[i][j];
    ll ans=1;
    vis1[i][j]=1;
    if(mat[i][j]=='L'){
        ans+=dfs(i-1,j);
    }
    else if(mat[i][j]=='R'){
        ans+=dfs(i+1,j);
    }
    else if(mat[i][j]=='U'){
        ans+=dfs(i,j-1);
    }
    else{
        ans+=dfs(i,j+1);
    }
    vis[i][j]=ans;
    vis1[i][j]=0;
    return ans;
}
void hnbhai(int tc){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            vis[i][j]=0;
            vis1[i][j]=0;
        }
    }
    vector<ll>ans;
    ll tot=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0){
                ll temp=dfs(i,j);
                //cout<<temp<<endl;
                if(tot<temp){
                    tot=temp;
                    ans={i+1,j+1,tot};
                    //swap(ans,temp);
                }
            }
        }
    }
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
    return;
}
int main()
{   //freopen("collectingofficer.in","r",stdin);
    /*ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
	ll t=1;
	cin>>t;
    int tot=1;
	while(t--)
	{
		hnbhai(tot);
		tot++;
	}
	return 0;
}
/*
7 10
1 1 1 1 1 1 1
1 2
1 3
1 4
3 5
3 6
3 7
1 3 2
2 1
1 4 3
2 1
1 2 5
2 1
1 6 4
2 1
2 2
2 3
1
9
EFDAABCBD
4
1 9 6
6 8 1
4 7 3
1 2 1
7 14
1 6 3
1 4 1
1 5 2
1 2 7
1 3 5
3 2
3 4
3 6
2 3 5
2 4 1
1 1 5
3 2
*/
