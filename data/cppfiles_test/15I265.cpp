#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

void solve() {
  int i, j, n, m, k;
  cin>>n>>m>>k;
  map<pair<int,int>,int> ma;
  vector<string> s(n);
  fo(i,n)
  cin>>s[i];
  vector<pair<int,int>> ans;


  for(i=n-1;i>=0;i--)
  {
      for(j=0;j<m;j++)
      {
          if(s[i][j]=='*')
          ans.pb(mp(i,j));
      }
  }


i=0;
int r,p,q;
int c=0;
while(i<ans.size())
{
    r=0;
   if(!ma[{ans[i].F,ans[i].S}])
   {
   c++;    
   }   
   p=ans[i].F-1;
   q=1;

if(p<0 || ans[i].S-q<0 || ans[i].S+q>=m ||  s[p][ans[i].S-q]!='*' || s[p][ans[i].S+q]!='*')
{
    if(!ma[{ans[i].F,ans[i].S}])
    {
        cout<<"NO"<<"\n";
        return;
    }
    else{
        i++; 
        continue;
    }
}

   while(p>=0 && ans[i].S-q>=0 && ans[i].S+q<m)
   {
      if(s[p][ans[i].S-q]=='*' && s[p][ans[i].S+q]=='*')       
        {

         if(!ma[{p,ans[i].S-q}]) 
         c++; 
         if(!ma[{p,ans[i].S+q}])
         c++;  
         ma[{p,ans[i].S-q}]=1;
         ma[{p,ans[i].S+q}]=1;

         r++;
         p--;
         q++;
        }
        else 
        {

            break;
        }   
   }

if(r<k && !ma[{ans[i].F,ans[i].S}])
{
    cout<<"NO"<<"\n";
    return;
}
i++;

}

if(ans.size()==c)
cout<<"YES"<<"\n";
else
cout<<"NO"<<"\n";

}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}