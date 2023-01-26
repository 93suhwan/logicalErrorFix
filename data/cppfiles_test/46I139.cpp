#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
using ld = long double;
using pll = pair<ll,ll>;
using vl = vector<ll>;
using vll = vector<pll>;//vector of pair
using vvl = vector<vl>;//vector of vector
using vs = vector<string>;
#define ri register int
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define in insert
#define uq unique
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mem(a,v)  memset(a,v,sizeof(a))
#define LOOP1(i,m,n)for(ll i=m;i<(ll)n;i++)
#define loop1(i,n)LOOP1(i,0,n)
#define LOOP2(j,m,n)for(ll j=m;j<=(ll)n;j++)
#define loop2(j,n)LOOP2(j,1,n)
#define max3(a,b,c)   max(a,max(b,c))
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
constexpr long double PI = 3.141592653589793238462643383279;
/*************** #Template FUNCTIONS# **************/
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD);}
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2);}
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b));}
ll cdiv(ll a, ll b) {ll ret = a / b; if (a % b) ret++; return ret;}
string rev(string s1){reverse(s1.begin(),s1.end());return s1;}
bool palindrome(string s1){return s1==rev(s1);}
ll lcm(ll a, ll b){return ((a/__gcd(a,b))*b);}
ll CountDivisor(ll n){ll divisor=0;for(ll i=1;i*i<=n;i++){if(i*i==n)divisor++;else if(n%i==0)divisor+=2;}return divisor;}
ll power(ll base,ll expo){ll cnt=1;for(ll i=0;i<expo;i++){cnt=cnt*base;}return cnt;}
bool isPowerOfTwo (ll x){return x && (!(x&(x-1)));}
bool isPerfectSquare(ll n){ll divisor=0;for(ll i=1;i*i<=n;i++){if(i*i==n)return 1;}return 0;}
void setPrecision(ll digit){cout<<fixed<<setprecision(digit);}
int stoi(string &s){
    int ans=0;
    int base=10;///it's base in decimal , in binary , octal , hexadecimal the base will be change
    for(int i=0;i<s.size();i++){
        ans=ans*base+s[i]-'0';
    }
    return ans;
}
ll nCr(ll n,ll r)
{
  ll p = 1;
  for(ll i = 1; i <= r; ++i) p *= i;
  ll ans = 1;
  for(ll i = n-r+1; i<= n; ++i){
  	ans *= (ll) (i/__gcd(i,p));
  	p /=__gcd(i,p);
  }
  return ans;
}
///*================ actual code starts here ============*/
ll i,j,a,b,c,d,p,q,r,n,m,t,x,y,z,sum,mx,mn;


void solution()
{
    cin>>n;
    vector<ll>v,v2;
    loop1(i,n)
    {
        cin>>x;
        v.pb(x);
    }
    mx=*max_element(v.begin(),v.end());
    m=*min_element(v.begin(),v.end());
    if(mx==m)
    cout<<0<<endl;
    else
    {

    ll flag;
    loop1(i,n)
    {
        if(v[i]==mx)
        {
            flag=i+1;break;
        }
    }
    //cout<<flag<<endl;
    //mn=max_element(v.begin()+flag,v.end());
    mn=LLONG_MIN;
    for(i=flag;i<n;i++)
    {
        if(v[i]>mn)
        {
             mn=v[i];
             z=i;
        }
    }

    //cout<<mn<<endl;
    //cout<<z<<endl;
    // ri cnt=0;
    /*

    while(mn!=mx)
    {
        for(auto u:v)
        {
            if(u>mn)
            {
                 v2.pb(u);
            }
        }
        v.clear();
        v=v2;
        mn=v.back();
        cnt++;
        if(mn==mx)
        {
           break;
        }
    }
    cout<<cnt<<endl;
    */
    cout<<(n-z)<<endl;


    }

}
int main()
{
        optimize();
        ll tt;
        cin>>tt;
        while(tt--)
        {
          solution();
        }
        return 0;
}
///@author Tasin Mahmud
/*****************  ALHAMDULILLAH *****************/
