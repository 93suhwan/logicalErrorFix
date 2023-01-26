#include <bits/stdc++.h>
using namespace std;
#define f(i,a,n) for(int i=a;i<n;i++)
#define int long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mem(x) memset(x, 0, sizeof(x))
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>    pii;
typedef vector<int>       vi;
typedef vector<vi>        vvi;
typedef map<int,int>      mii;
int logs[200005];
int st[200005][30];
void findl(int n )
{
    logs[1]=0;
    for(int i =2;i<=n;i++)
    logs[i] = logs[i/2]+ 1;
}
void sparse(vector<int>a,int n)
{
    int k = logs[n]+1;

    for(int i =0;i<n;i++)
    st[i][0] = a[i];

    for(int j =1;j<=k;j++)
    {
        for(int i =0; i + (1<<j)<=n;i++)
        st[i][j] = __gcd(st[i][j-1],st[i +(1<<(j-1))][j-1]);
    }

}
int query(int l,int r)
{
    int k = r-l+1;
    k = logs[k];

    int ans;
    ans = __gcd(st[l][k],st[r-(1<<k)+1][k]);
    return ans;
}
void solve(vector<int>v){

    int n = v.size();

    vector<int>diff;

    for(int i =0;i<n-1;i++)
    {
        int x= abs(v[i]-v[i+1]);
        diff.push_back(x);
    }
    int m = diff.size();
    //memset(st,0,sizeof(st));
    findl(m);
    sparse(diff,m);
    //cout<<"hello"<<endl;
    int cnt = 1;
		int j = 0;
		for(int i=0;i <m;i++){
			while (j < m - 1 && query(i, j + 1) > 1) {
                ++j;
            }
            cnt = max(j - i + 2,cnt);
            j = max(i, j);
		}
		cout << cnt <<"\n";;


}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t=1;
    cin>>t;

    while (t--) 
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i =0;i<n;i++)
        cin>>v[i];
        if(n==1)
        {
            cout<<v[0]<<"\n";
            continue;
        }
        solve(v);
    }

 return 0;
}