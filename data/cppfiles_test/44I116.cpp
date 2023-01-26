#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define pb push_back
#define pob pop_back()
#define ms0(s) memset(s,0,sizeof s)
#define ff first
#define ss second
typedef long long int ll;
#define vl vector<ll>
#define vpll vector<pair<ll,ll>>
#define vpss vector<pair<string,string>>
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define prq priority_queue<ll> 
#define psq priority_queue<ll,vector<ll>,greater<ll>>  
#define mp make_pair
#define vc vector<char>
#define vs vector<string>
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define rep(i,n) for(ll i=0;i<n;i++)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define ln cout<<"\n"
#define rep(i,n) for(ll i=0;i<n;i++)
#define setbit(n) __builtin_popcountll(n)
const ll mxn = 1e5 + 5;

//ll dp[mxn];

void init_code(){
    
    #ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE

}

ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return (a/__gcd(a,b))*b;
}

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.ss > b.ss);
} 

int main(){
    init_code();

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll q=1;
    // cin>>q;
    
    while(q--)
    {
        
        ll b,a,n,r,x,d,k,w=0,count=0,z,mx,f=0,f2,sum=0,ans=0,avr;
        cin>>a>>b;
        n=abs(a-b);
        if(n&1)
            cout<<-1;
        else
        {
            if(a==0 && b==0)
                cout<<0;
            else if(a==b)
                cout<<1;
            else
                cout<<2;
        }
        ln;
        
    }
    
    return 0;
}
