#include<bits/stdc++.h>
#include <limits>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ins insert
#define sb substr
#define con continue
#define ub upper_bound
#define lb lower_bound
#define pll pair<ll,ll>
#define pld pair<ld,ld>

ll modexp(ll x, ll n);
ll getFractionModulo(ll a, ll b);
ll power(ll x, ll y);
ll mpower(ll x, ll y, ll p);
bool isPrime(ll n);
ll const N=(ll)(4e5+4);
ll const mod=(ll)(1e9+7);
vector<ll>g[N];
vector<ll>g1[N];
ll visited[N]={0};
ll parent[N]={0};
ll a[N]={0};
ll flag=0;
vector<ll>no;
ll sum=0;

void dfs(ll v,ll n)
{
   // cout<<v<<endl;
   no.pb(v);
    if(visited[v])
        return;

    visited[v]=1;

    for(auto x:g[v])
    {
        if(!visited[x])
        {
            dfs(x,n);
            if(no.size()==n+1) return;
            else
            {
                no.pop_back();
                visited[x]=0;
            }
        }
    }

    return;
}

ll gcd(ll a,ll b)
{
    if(a==0)
        return b;

    return gcd(b%a,a);
}


ll binomialCoeff(ll n, ll r)
{
    // Optimization for the cases when r is large
    if (r > n - r)
        r = n - r;

    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    ll C[r + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // Top row of Pascal Triangle

    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (ll i = 1; i <= n; i++) {

        // Fill entries of current row using previous
        // row values
        for (ll j = min(i, r); j > 0; j--)

            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j - 1]) % mod;
    }
    return C[r];
}
bool isPerfect(ll N)
    {
        if ((sqrt(N) - floor(sqrt(N))) != 0)
            return false;
        return true;
    }


ll setBitNumber(ll n)
{
    n |= n >> 1;

    n |= n >> 2;

    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    n = n + 1;

    return (n >> 1);
}

ll myXOR(ll x, ll y)
{
    ll res = 0; // Initialize result

    // Assuming 32-bit Integer
    for (int i = 31; i >= 0; i--)
    {
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);

        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);

        // Update result
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}

long double squareRoot(ll number, ll precision)
{
    ll start = 0, end = number;
    ll mid;

    // variable to store the answer
    long double ans;

    // for computing integral part
    // of square root of number
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == number) {
            ans = mid;
            break;
        }

        // incrementing start if integral
        // part lies on right side of the mid
        if (mid * mid < number) {
            start = mid + 1;
            ans = mid;
        }

        // decrementing end if integral part
        // lies on the left side of the mid
        else {
            end = mid - 1;
        }
    }

    // For computing the fractional part
    // of square root upto given precision
    long double increment = 0.1;
    for (int i = 0; i < precision; i++) {
        while (ans * ans <= number) {
            ans += increment;
        }

        // loop terminates when ans * ans > number
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}

bool sortbyfirstdesc(const pair<ll,ll> &a,
                   const pair<ll,ll> &b)
{
       return a.second<b.second;
}

bool sortbyfun(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    if(a.first==b.first)
    {
        return a.ss<b.ss;
    }

    return a.ff<b.ff;
}

bool sortbyfunc1(const vector<ll>&a,const vector<ll>&b)
{
    if(a[0]==b[0])
    {
        if(a[1]==b[1])
            return a[2]<b[2];

        return a[1]<b[1];
    }
    return a[0]<b[0];
}

ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}

bool sortbyfunc2(const vector<ll>&a,const vector<ll>&b)
{
    ll sum=0;
    for(ll i=0;i<5;i++)
    {
        if(a[i]<b[i])
        {
            sum++;
        }
    }
    return sum>=3;
}

ll getp(ll index,ll i,unordered_map<ll,unordered_map<ll,ll>>&data)
{
    if(data[index][i]==i) return i;

    return data[index][i]=getp(index,data[index][i],data);

}

int main()
{
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            ll  t,i,l,h,r,x,y,z,d,f,s,u,v,k1,k2,c,a,w,b,m,n1,M=(ll)(1e9+7);

            ll  n,K;
            ll  p,q,j,k;

           // cout<<perfe.size()<<endl;
           // cout<<gp<<endl;

          cin>>t;

       //   t=1;

            while(t--)
            {
                        cin>>n;

                        ll arr[n];

                        for(i=0;i<n;i++)
                        {
                            cin>>arr[i];
                        }

                        ll pref[n],suf[n];

                        for(i=0;i<n;i++)
                        {
                            if(!i)
                            {
                                pref[i]=arr[i];
                            }
                            else
                            {
                                pref[i]=pref[i-1]+arr[i];
                            }
                        }

                        for(i=n-1;i>=0;i--)
                        {
                            if(i==n-1)
                            {
                                suf[i]=arr[i];
                            }
                            else
                            {
                                suf[i]=suf[i+1]+arr[i];
                            }
                        }

                        double ans=(double)(INT_MIN);

                        for(i=0;i<n-1;i++)
                        {
                            double a=(double)(pref[i])/(double)(i+1);

                            double b=(double)(suf[i+1])/(double)(n-(i+1));

                            double k=a+b;

                            ans=max(ans,k);


                        }

                        cout<<setprecision(9)<<ans<<endl;





            }




}


ll mpower(ll x, ll y, ll p){
    ll res = 1;
    x = x % p;
    while(y > 0){
        if(y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

ll getFractionModulo(ll a, ll b)
{
	ll c = gcd(a, b);

	a = a / c;
	b = b / c;

	// (b ^ m-2) % m
	ll d = modexp(b, mod - 2);

	// Final answer
	ll ans = ((a % mod) * (d % mod)) % mod;

	return ans;
}

ll modexp(ll x, ll n)
{
	if (n == 0) {
		return 1;
	}
	else if (n % 2 == 0) {
		return modexp((x * x) % mod, n / 2);
	}
	else {
		return (x * modexp((x * x) % mod, (n - 1) / 2) % mod);
	}
}

ll power(ll x, ll y){
    ll res = 1;
    while (y > 0){
        if (y & 1) res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}
bool isPrime(ll n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    ll p=sqrt(n);
    for(ll i=5;i<=p;i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}
