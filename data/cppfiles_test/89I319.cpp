/*

    author : s@if

*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define 		NIL 			-1
#define			INF 			1e9
#define         EPS             1e-9
#define         SAIF            main
#define		 	fi	 		    first
#define 		sec 			second
#define 		MAX 			INT_MAX
#define 		ll 			    long long
#define 		PI 			    acos(-1.0)
#define			MOD 			1000000007
#define 		PLL 			pair<ll,ll>
#define 		PII			    pair<int,int>
#define 		ull 			unsigned long long
#define 		For(i,a,b) 		for(int i=a;i<=(int)b;i++)
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> new_data_set;

//*find_by_order(k)  gives the kth element;
//order_of_key(item)   gives the index(number of element strictly less than item) of item;

inline int in() {int x; scanf("%d", &x); return x; }
bool Check(int N , int pos)	{	return (bool) (N & (1<<pos));}
int Set(int N, int pos) {	return N = N | (1<<pos);}

int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};    // King's move
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int hx[]={-2,-2,-1,+1,+2,+2,-1,+1};    // Knight's move
int hy[]={+1,-1,+2,+2,-1,+1,-2,-2};
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};

const int MAXN = (int)2e5+9;

ll LCM(ll a, ll b)
{
    ll gcd = __gcd(a, b);
    return (a*b)/gcd;
}

void solve(void)
{
    ll i,j,k,l,m,n,p,q,x,y,u,v,w,r,tc,t;

    cin>>n; vector<ll>vv(n);
    for(i=0; i<n; i++) cin>>vv[i];

    int cnt = 0;
    while(!vv.empty() && cnt<=200)
    {
        n = vv.size();
        for(i=n-1; i>=0; i--){
            if(vv[i]%(i+2)!=0) break;
        }
        if(i<0) break;

        vector<ll>tmp;
        for(j=0; j<i; j++) tmp.push_back(vv[j]);
        for(j=i+1; j<n; j++) tmp.push_back(vv[j]);
        vv.clear(); vv = tmp;
        cnt++;
    }

    if(vv.empty()) cout<<"YES\n";
    else cout<<"NO\n";

    return;
}

int SAIF()
{
    int tc = 1, t = 0;

    cin>>tc;

    while(tc--) solve();

    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
