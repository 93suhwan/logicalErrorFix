#include <bits/stdc++.h>

#define     boost            ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
#define     pb               push_back	
#define     pf               push_front
#define     pob              pop_back
#define     pof              pop_front	
#define     mp               make_pair
#define     ff               first
#define     ss               second
#define     IN               insert
#define     endl             "\n"

#define     rep(i,a,b)       for(ll i=a; i<b; i++)
#define     rev(i,a,b)       for(ll i=a; i>=b; i--)

#define     decimal(n)       fixed << setprecision(n) 
#define     all(v)           v.begin(), v.end() 
#define     rall(v)          v.rbegin(), v.rend()
#define     sz(v)            v.size()
#define     total_sum(v)     accumulate(all(v),0LL)
#define		mem0(v)			 memset(v,0,sizeof(v))
#define		mem1(v)			 memset(v,-1,sizeof(v))

#define     make_unique(v)   v.erase(unique(all(v)),v.end())
#define     n_p(v)           next_permutation(all(v))
#define     p_p(v)           prev_permutation(all(v))
	

#define     for_each(it, X)  for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

#define     printv(a)        rep( i, 0, sz(a) )    cout<<a[i]<<" ";     cout<<endl;

#define		prints(a)		 for_each(it, a)  cout<<*it<<" ";   cout<<endl;

#define		printvll(a)		 rep(i,0,sz(a))  cout<<a[i].ff<<" "<<a[i].ss<<endl; 

#define     re               return

using namespace std;

typedef     long long              ll;
typedef     unsigned long long     ull;
typedef     pair < int, int >      pii;
typedef     pair < ll, ll >        pll;
typedef     vector < pii >         vii;
typedef     vector < pll >         vll;
typedef     vector < int >         vi;
typedef     vector < ll >          vl;
typedef     vector < vl >          vvl;
typedef     vector < string >      vs;
typedef     vector < vs >          vvs;
typedef     set< ll >              sl;
typedef     set< pll >             sll;
typedef     multiset< ll >         msl;
typedef     map< ll, ll >          ml;


ll gcd ( ll , ll );

ll lcm ( ll  , ll );

bool isPrime( ll );

ll power( ll , ll );

ll fact( ll );

void sieve_of_eratosthenes (  ll , vl &  );

ll roof(ll , ll);

bool isPalindrome( string );

//---------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------
const ll 	  INF  =  1e18;
const ll      MOD  =  1e9 + 7;
const ll      MOO  =  998244353;
const double  pi   =  3.14159265358979323846;
const ll      M    =  1e6+7;


ll check(vl a, vl b) {
	if(sz(a)!=sz(b)) re MOD;

	ll ans=0;

	rep(i,0,sz(a)) {
		ans+=abs(a[i]-b[i]);
	}

	re ans;

}


void solve() {
	ll n;
	cin>>n;

	vl v(n);
	vl o;

	rep(i,0,n) {
		cin>>v[i];
		if(v[i]%2) o.pb(i);
	}

	if(abs(sz(o)-(n-sz(o)))>1) {
		cout<<-1<<endl;re;
	}

	vl l, r;

	rep(i,0,n) {
		l.pb(i);
		if(i+1<n) r.pb(i+1);
		i++;
	}

	// printv(o);
	// printv(l);
	// printv(r);
	


	cout<<min(check(l,o),check(r,o))<<endl;

}

int main()
{
    boost;
    ll t=1;
	cin>>t;

	rep(i,1,t+1)
    {
   		// cout<<"Case #"<<i<<": ";
    	solve();
	   	// cout<<endl;
    }
  
}

//---------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------

// HCF

ll gcd ( ll a , ll b )  {
	
	return __gcd ( a , b ) ;
	
	/*
	
	if ( a==0 )
	return b ;
	
	return gcd ( b%a , a ) ;	
	
	*/
}

// LCM

ll lcm ( ll a , ll b )  {
	
	return ( a * b ) / ( __gcd ( a , b ) ) ;

}

// PRIME 

bool isPrime( ll n )
{
    for( ll i=2 ; i*i<=n ; i++) 
	{
        if( n % i == 0)
        return false;
    }
    
    return true;
}

// POWER

ll power( ll a , ll b) {
	ll c=MOD;
	ll ans=1;

	while(b) {
		if(b%2) {
			ans=(ans*(a%c))%c;
			// ans = a*ans;
		}

		a=((a%c)*(a%c))%c;
		// a=a*a;
		b>>=1;
		//  b/=2;
	}
	
	return ans;
}

// FACTORIAL

ll fact(ll n) {	
	ll h = 1;

	rep(i,2,n+1) {
		h=(h*i);
	}
	
	return h;	
	
}

// SIEVE of ERATOSTHENES

void sieve_of_eratosthenes (ll n, vl &a) {
	
	a[0]=a[1]=0;
	
	for(ll i=2; i*i<=10000007 ; i++) {
		if(a[i]) {
			for(ll j=i+i; j<=10000007 ; j+=i) {
				a[j]=0;
			}
		}
	}
	
}

// CEILING FUNCTION

ll roof(ll a, ll b) {
	
	return (a + b - 1) / (b) ;

} 

// PALINDROME

bool isPalindrome(string s) {
	rep(i,0,sz(s)/2) {
		if(s[i]!=s[sz(s)-i-1]) re 0;
	}

	re 1;
}

