#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define F(i,L,R) for (int i = L; i < R; i++) 
#define FI(i,L,R) int i; for(i = L;i<R;i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FEI(i,L,R) int i;for(i = L;i <= R;i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFI(i,L,R) int i;for (i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define FFEI(i,L,R) int i;for (i = L; i >=R; i--)
 
#define getI(a) cin>>a 
#define getII(a,b) cin>>a>>b
#define getIII(a,b,c) cin>>a>>b>>c
#define wez(n) int (n); cin>>n //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); cin>>n>>m
#define wez3(n,m,k) int (n),(m),(k); cin>>n>>m>>k
#define TESTS wez(testow);while(testow--) //for multilple cases problems
#define arrayIn(a,L,R) FE(i,L,R) cin>>a[i]
#define VectorIn(V,n) FE(i,0,n-1){wez(xscd);V.pb(xscd);}  // remember to not use ;
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define fi first
#define se second
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
#define pb push_back
#define google(cnt) cout<<"Case #"<<cnt<<": ";cnt++;

#define MOD (int)(1000000007)
#define MOD1 (int)(998244353)
#define pi pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define pq priority_queue<int>

#define pcout(x) cout<<setprecision(15)<<x<<'\n';

ll GCD(ll x,ll y){ if(x == 0) return y;if(y == 0) return x; if(x>y) return GCD(y,x%y); return GCD(x,y%x);}
ll LCM(ll x,ll y){ return (x/GCD(x,y))*y;}
ll MPOW(ll a,ll b,ll m = LLONG_MAX){if(b == 0) return 1; if(b&1)return ((a%m)*(MPOW(a,b-1,m)%m))%m; a = (a*a)%m; return (MPOW(a,b/2,m));}
ll MINV(ll a,ll m){return MPOW(a,m-2,m);}
inline bool max3(ll a,ll b,ll c) {return max(a,max(b,c));}
inline bool min3(ll a,ll b,ll c){return min(a,min(b,c));}
inline bool sortbythis(pi a,pi b){return ((a.fi==b.fi && a.se<b.se)|| (a.fi<b.fi));}
inline bool sortbythat(pi a,pi b){return ((a.se == b.se && a.fi<b.fi)||(a.se<b.se));}

typedef tree< pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
class pnc
{
  ll FACTMAX,MODU;
  vll fact;
public:
	pnc(ll n,ll m){FACTMAX = n;MODU = m;fact.resize(n+1);MFACT_INIT(MODU);}
	void MFACT_INIT(ll m){fact[0] = 1; FE(i,1,FACTMAX) fact[i] = (i*fact[i-1])%MODU;}
	ll MFACT(ll n){return fact[n];}
	ll PERM(ll n,ll r){return (fact[n]*MINV(fact[n-r],MODU))%MODU;}
	ll COMB(ll n,ll r){return (PERM(n,r)*MINV(fact[r],MODU))%MODU;}
};

// don't use uninitalised variables
// correctness costs U more
//const int MAXN  // change this 

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // let T be the total time needed to comeback
    //  a1,a2,a3,a4 be times at which it can sweep
    // E(x) = a1*p + a2*p*(1-p) + a3*p*(1-p)^2 + a4*p*(1-p)^3 = val
    // g = (p+p*(1-p)+..)
    //      = (T*g+val)(1-p)^4
    //      = (2*T*g+val)(1-p)^8
    // E(x) = (x+2x^2+3x^3+..)*T*g + val(1+x+x^2+..+)

    // E(x) = x+2x^2+3x3+...nx^n 
    // xE(x) =  + x^2+2x^3+ ....
    // (1-x)E(x) = x+x^2+....
    // E(x) = x/(1-x)^2*T*g + val(1/(1-x));
    // T is total cycle time , x = (1-p)^cnt , val = initial round count

    TESTS
    {
       wez2(n,m);
       wez2(rb,cb);
       wez2(rd,cd);
       pi init = {rb,cb};
       ll p;
       cin>>p;
       int dr = 1,dc = 1;
       vi V;
       int steps = 0;
       bool b = false;
       while(1)
       {   
            if(steps>(4*m*n))
              break;
            if((dr == 1 && dc == 1 && rb == init.fi && cb == init.se)&&b)
	    	   break;
	    	b = true;
	        if((rb+dr)<1 || (rb+dr)> n)
	    	{
	    		dr *= (-1);
	    		continue;
	    	}
	    	if((cb+dc)<1 || (cb+dc)> m)
	    	{
	    		dc *= (-1);
	    		continue;
	    	}
	    	if(rb == rd || cb == cd)
       	      V.pb(steps);
	    	rb += dr;
            cb += dc;
            steps++;
	    }
    
        ll negp = ((100-p)*MINV(100,MOD))%MOD; 
        p = (p*MINV(100,MOD))%MOD;
        
        
        ll val = 0;
        ll x = 1;
        ll g = 0;
        
        for(auto it : V)
        {   
        	ll temp = (p*x)%MOD;
            g = (g+temp)%MOD;
        	temp = (temp*it)%MOD;
        	val = (val + temp)%MOD;
        	x = (x*negp)%MOD;
        }
       
        ll temp = (1-x+MOD)%MOD;
        
        ll ans = (x*MINV(temp,MOD))%MOD;
        ans = (ans*MINV(temp,MOD))%MOD;
        ans = (ans*steps)%MOD;
        ans = (ans*g)%MOD;
        ans = (ans + (val*MINV(temp,MOD))%MOD)%MOD;

        cout<<ans<<"\n";

    }

    

       
    
    
	return 0;
}