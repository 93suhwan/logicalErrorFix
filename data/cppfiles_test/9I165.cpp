#include<bits/stdc++.h>
using namespace std;
#define forOneToN(i, n)         for(int i = 1; i <= n; i++)
#define forZeroToNminus(i, n)   for(int i = 0; i < n; i++)
#define forNToOne(i, n)         for(int i = n; i >= 1; i--)
#define forNminusToZero(i, n)   for(int i = n-1; i >= 0; i--)


//Test Code
#define test                    cout <<"I am here" << endl;


void fastInputOutput(){ios_base::sync_with_stdio(false);cin.tie(NULL);}

typedef long long ll;
typedef double db;
typedef vector<int>                                                           	vi;
typedef vector<long long>                                                       vl;
typedef vector< pair<int, int> >                                                vpii;
typedef vector< pair<long long, long long> >                                    vpll;
typedef vector< pair<long long, int> >                                          vpli;
typedef pair<int, int>                                                          pii;
typedef pair<long long, long long>                                              pll;
typedef pair<long long, int>                                                    pli;
typedef map<int, int>                                                           mii;
typedef map<long long, long long>                                               mll;
typedef map<long long, int>                                                     mli;
typedef multimap<int, int>                                                      mmii;
typedef multimap<long long, int>                                                mmli;
typedef multimap<long long, long long>                                          mmll;
typedef set<int>                                                                si;
typedef set<long long>                                                          sll;
typedef multiset<int>                                                           msi;
typedef multiset<long long>                                                     msll;
typedef set<int, greater<int> >                                                 sid;
typedef set<long long, greater<long long> >                                     slld;
typedef multiset<int, greater<int> >                                            msid;
typedef multiset<long long, greater<long long> >                                mslld;
typedef stack<int>                                                              sti;
typedef stack<long long>                                                        stll;
typedef queue<int>                                                              qi;
typedef queue<long long>                                                        qll;
typedef priority_queue<int>                                                     maxpqi;
typedef priority_queue<long long>                                               maxpqll;
typedef priority_queue<int, vector<int>, greater<int> >                         minmpqi;
typedef priority_queue<long long, vector<long long>, greater<long long> >       minpqll;

typedef priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Minpairpq;



ll extended_gcd(ll a, ll b, ll *x, ll *y){if(a == 0){*x = 0;*y = 1;return b;}ll x1, y1;ll d = extended_gcd(b%a, a, &x1, &y1);*x = y1-(b/a)*x1;*y = x1;return d;}
ll LCM(ll a, ll b){ll gcd, g;g = __gcd(a, b);return (a/g)*b;}

ll Set(ll n, ll pos){return n = n|(1<<pos);}
ll Reset(ll n, ll pos){return n = n& ~(1<<pos);}
bool Check(ll n, ll pos){return (bool)(n&(1<<pos));}

const long long inf_long = LONG_MAX;
const int inf_int = INT_MAX;
const ll mod = 1e9+7;

double phi = acos(-1);


//custom compare function structure for set
struct cmp_for_set_and_Semilar
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return (a.first > b.first);
    }
};
//custom compare function structure for vector pair
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first != b.first)
    {
        return a.first > b.first;
    }
    return a.second > b.second;
}
//Binary Exponentiation
long long BigMod(long long a, long long b)
{
    long long ans = 1;
    while(b)
    {
        if(b%2 == 0)
        {
            a = (a*a);
            b /= 2;
        }
        else
        {
            ans = (ans*a);
            b--;
        }
    }
    return ans;
}
// Binary Exponentiation for modular inverse
long long BinaryEx(long long a, long long b)
{
    long long ans = 1;
    while(b)
    {
        if(b%2 == 0)
        {
            a = (a*a)%mod;
            b /= 2;
        }
        else
        {
            ans = (ans*a)%mod;
            b--;
        }
    }
    return ans;
}
long long mod_inverse(long long a)
{
    return BinaryEx(a, mod-2);
}
bool isKthBitSet(long long n, int k)
{
    if (n & (1 << (k)))
        return true;
    else
        return false;
}
void solve()
{
    string str; cin >> str;
    int n = str.size();
    int ans = 0;
    int i = 1;
    char c = str[0];
    int x = 1;
    while(i < n)
    {
        if(str[i] == c)
        {
            x++;
        }
        else
        {
            if(x > 2)
            {
                ans += 2;
            }
            else
            {
                ans++;
            }
            c = str[i];
            x = 1;
        }
        i++;
    }
    if(x > 2)
    {
        ans += 2;
    }
    else
    {
        ans++;
    }
    cout << ans/2 << endl;
}
int main()
{
	fastInputOutput();
    int t; cin >> t;while(t--) solve();
    //int t; scanf("%d", &t); while(t--) solve();
    //solve();
    return 0;
}
