#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define INF 922337203
#define endl '\n'
#define nl cout << '\n'
#define fout fflush(stdout)
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ld long double
#define um unordered_map
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpil vector<pil>
#define vpli vector<pli>
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define fok(i, k, n) for (ll i = k; i < n; i++)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, n) for (ll i = n; i >= 0; i--)
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

ll binpow(ll a, ll b) {     //power of big numbers (binary exponentiation)
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll binpow_mod(ll a, ll b, ll m) {      //power of big numbers mod m (binary exponentiation)
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll bsearch(ll arr[], ll l, ll r, ll x)     //binary search
{
    if (r >= l) {
        ll mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid]> x)
            return bsearch(arr, l, mid - 1, x);
        return bsearch(arr, mid + 1, r, x);
    }
    return -1;
}

ll first(ll arr[], ll low, ll high, ll x, ll n)     //first occurance of a number eg. first(a,0,n-1,x,n)
{
    if (high >= low) {
        ll mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid]== x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}

void swap(ll &a , ll &b)      //swapping two numbers
{
	a=a+b;
	b=a-b;
	a=a-b;
}

void reverse(ll a[] , ll i , ll j)     //reversing array
{
	for(ll x=i ; x<i+(ll)ceil((j-i)/(float)2) ; x++)
	{
		swap(a[x],a[j+i-x]);
	}
}

ll modFact(ll n, ll p)      //factorial with mod
{
    if (n >= p)
        return 0;

    ll result = 1;
    for (ll i = 1; i <= n; i++)
        result = (result * i) % p;

    return result;
}

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)    //for sorting vector of pair by second element {eg. sort(v.begin(),v.end(),sortbysec)}
{
    return (a.ss < b.ss);
}

ll printNcR(ll n, ll r)      //Ncr
{
    ll p = 1, k = 1;
    if (n - r < r)  r=n-r;

    if (r != 0) {
        while (r) {
            p *= n; k *= r;
            long long m = __gcd(p, k);
            p /= m; k /= m;
            n--; r--;
        }
    }
    else p = 1;
    return p;
}

bool isprime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

ll isPalindrome(string str)
{
    ll l = 0,h = str.size() - 1;
    while (h > l)
	 if (str[l++] != str[h--]) return 0;
    return 1;
}


int main()
{
	fastio();
    
    ll t=1;
    cin>>t;
    while(t--)
    {
		ll W,H,a,b,c,d,w,h,l,r,ds=M;
		cin>>W>>H>>a>>b>>c>>d>>w>>h;
		if(a>=W-c) l=0;
		else l=W;
		if(b>=H-d) r=0;
		else r=H;
		
		if(w+c-a>W && h+d-b>H) cout<<-1;
		else
		{
			if(w+c-a<=W)
			{
				if(l==0)
			    {
				    ds=min(ds,max((ll)0,w-a));
			    }
			    else
			    {
				    ds=min(ds,max((ll)0,w-W+c));
			    }
			}
			else
			{
				if(r==0)
			    {
				    ds=min(ds,max((ll)0,h-b));
			    }
			    else
			    {
				    ds=min(ds,max((ll)0,h-H+d));
			    }
			}
			cout<<ds;
		}
		
		nl;
    }
}
