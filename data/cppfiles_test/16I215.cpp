#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define inarr(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define outarr(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define maxa(a,n) *max_element(a,a+n)
#define mina(a,n) *min_element(a,a+n)
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(ll i=s;i<e;i++)
#define rf(i,s,e) for(ll i=s-1;i>=e;i--)
#define deb1(x) cout<<#x<<" : "<<x<<endl;
#define deb2(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define sz size()
#define all(v) v.begin(),v.end()
#define gcd(a,b) __gcd(a,b)
#define len length()
#define permute next_permutation
 
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
 
bool isPrime(ll n) {    if(n==1 || n==0)    return false;    for (ll i = 2; i * i <= n; ++i) {    if (n % i == 0) {    return false;}    }    return true;    }
 
ll lcd(ll a,ll b) {return (a*b)/gcd(a,b);}
 
#define PI 3.141592653589793
#define MOD 1000000007
 
bool flag=0,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;


void solve()
{
    ll n;cin>>n;
    vll a(n),b;inarr(a,n);
    ll cnt=0;
    b=a;
    sort(all(b));
    fr(i,0,n)
    if(a[i]>0) cnt++;
    if(cnt<2){
        cout<<0<<endl;
    }
    else{
        vector<vll> res;
        vll tst(2);
        fr(i,0,n){
            ll l=find(all(a),b[n-2])-a.begin();
            ll r=find(all(a),b[n-1])-a.begin();
            ll mn=min(a[r],a[l]);
            if(mn==0)
                break;
            else{
                if(l==r) r=find(a.begin()+l+1,a.end(),b[n-1])-a.begin();
                tst[0]=l+1;
                tst[1]=r+1;
                fr(k,0,mn)
                    res.pb(tst);
                a[l]-=mn;b[n-1]-=mn;
                a[r]-=mn;b[n-2]-=mn;
            }
            sort(all(b));
        }
        cout<<res.size()<<endl;
        fr(i,0,res.size()){
            cout<<res[i][0]<<" "<<res[i][1]<<endl;
        }
    }
}

int main()
{
    IOS
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}