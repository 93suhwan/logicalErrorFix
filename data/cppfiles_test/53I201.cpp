//GODLEON'S CODE
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type , less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ff                first
#define ss                second
#define ll                long long
#define ddouble           long double  
#define pb 		  push_back
#define mp 		  make_pair
#define pii               pair<ll , ll>
#define vi                vector<ll>
#define mii               map<ll,ll>
#define gsort             greater<ll>
#define pqb               priority_queue<ll>
#define pqs               priority_queue<ll , vi , greater<ll>>
#define setbits(x)        __builtin_popcountll(x)
#define zrobits(x)        __builtin_ctzll(x)
#define mod               1000000007
#define mod1              mod
#define mod2              1000000009
#define inf               1e18
#define ps(x,y)           fixed<<setprecision(y)<<x
#define fbo(k)		  find_by_order(k)
#define ook(k)		  order_of_key(k)
#define mk(arr,n,type)    type *arr = new type[n] ;
#define test(t)           ll t ; cin >> t ; while(t--)
#define all(a)		  a.begin() , a.end()
#define ifor(a,b)	  for(ll i = a ;i < n ; i++)
#define PI 		  3.1415926535
#define readi(x) 	  scanf("%d",&x)
#define reads(x)  	  scanf("%s", x)
#define readl(x) 	  scanf("%I64d",&x)
#define fio               ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
mt19937                   rng(chrono::steady_clock::now().time_since_epoch().count());


// check odd even : n & 1
// check power of 2 : n & n - 1 == 0
//flip xor
//set or
//unset and
//for -ve no.s mod ( a % mod + mod ) % mod ; 

ll toint(const string &s) {stringstream ss; ss << s; ll x; ss >> x; return x;}
string tostring ( ll number ){stringstream ss; ss<< number; return ss.str();}
ll power(ll x, ll y, ll p) 
{ 
	if(x==0 && y==0)
	{
		return 1;
	}
	ll res = 1;	 
	x = x % p;  

	if (x == 0) return 0; 

	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res*x) % p; 
		y = y>>1;
		x = (x*x) % p; 
	} 
	return res; 
} 

//segment trees
/*
void update(ll* arr , ll* tree , ll start , ll end , ll index , ll value , ll position)
{
    if(start == end)
    {
        arr[position] = value;
        tree[index] = value;
        return;
    }

    ll mid = start + (end - start) / 2  ;
    if(position > mid)
    {
    update(arr , tree , mid+1 , end , index*2  + 1, value , position);
    }
    else 
    {
    update(arr , tree , start , mid , index*2 , value , position);
    }

    tree[index] = tree[index*2] + tree[index*2 + 1] ;
}

ll query(ll* tree , ll start , ll end , ll index , ll left , ll right)
{
    if(start > right || end < left)
    {
        return 0;
    }

    if(start >= left && end <= right)
    {
        return tree[index];
    }

    ll mid = start + (end - start)/2 ;
    
    ll ans1 = query(tree , start , mid , index*2 , left , right);
    ll ans2 = query(tree , mid+1 , end , index*2 + 1 , left , right);

    return ans1 + ans2 ;
}

void buildTree(ll* arr , ll* tree , ll start , ll end , ll index)
{
    if(start == end)
    {
        tree[index] = arr[start];
        return ;
    }

    ll mid = (start + end) / 2 ;
    buildTree(arr , tree , start , mid , 2*index);
    buildTree(arr , tree , mid + 1 , end , 2*index + 1);

    tree[index] = tree[2*index] + tree[2*index + 1]; 
}
*/

int main()
{
    fio;
    test(t)
    {
        ll n ;
        cin >> n;
        ll k ;
        cin >> k ;
        vi v(n , 0);
        ifor(0 , n)
        {
            cin >> v[i];
        }
        vector<ll> w = v ;
        sort(all(w));
        int count = 0;
        for(int i = 0 ; i < n-1 ; i++)
        {
            if(v[i] > v[i+1])
            {
                count++;
            }
        } 

        for(int i = 0 ;i < n ; i++)
        {
            auto itr = lower_bound(w.begin() , w.end() , v[i]) ;
            count = max(int(itr - w.begin()) - i , count) ;
        }
        if(count > k)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}