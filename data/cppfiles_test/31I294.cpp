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

int gcd(int a, int b, int &x, int &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1-y1*(a/b);
    return g;
}

void solve(void)
{
    int i,j,k,l,m,n,p,q,x,y,u,v,w,r,tc,t;

    cin>>n; int a[n+9];
    for(i=1; i<=n; i++) cin>>a[i];

    if(n%2==0)
    {
        for(i=1; i<=n; i+=2)
        {
            x = a[i], y = a[i+1];
            cout<<-y<<" "<<x<<" ";
        }
        cout<<endl;
    }
    else{
        u = abs(a[1]), v = abs(a[2]), w = abs(a[3]);
        int g = __gcd(u, v);
        if(w%g!=0) w*=g;
        gcd(u, v, x, y);
        //cout<<x<<" "<<y<<endl;
        x*=w/g; y*=w/g;
        if(x==0 || y==0){
            if(u==v)
            {
                if(u==w) w*=2;
                p = w/u;
                x = 1, y = p-1;
            }else{
            x+=v/g;
            y-=u/g;
            }
        }
        int z = w/abs(a[3]);

        if(a[1]<0) x = -x;
        if(a[2]<0) y = -y;
        if(a[3]<0) z = -z;
        cout<<x<<" "<<y<<" "<<-z<<" ";
        for(i=4; i<=n; i+=2)
        {
            cout<<-a[i+1]<<" "<<a[i]<<" ";
        }
        cout<<endl;
    }

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
