#include<iostream>
#include <math.h>
#include<bits/stdtr1c++.h>
#include<vector>
#define mod 998244353
#define pqll priority_queue<ll,vector<ll>,greater<ll>>
#define ll long long
#ifndef ONLINE_JUDGE
#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#else
#define trace1(x)
#define trace2(x,y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

#define ll long long
#define fr(i,a,b) for(ll i = a;i<b;i++)
#define pie 3.14159265358979
#define pb push_back
// #define mp make_pair
#define fri(i,a,b) for(ll i = a;i>=b;i--)
#define pqll priority_queue<ll,vector<ll>,greater<ll>>
// #define pq priority_queue<ll>
#define pr pair<ll,ll>
#define prr pair<ll,pr>
#define pqr priority_queue<pair<ll,ll>>
#define ld long double
#define precise(a) cout << fixed << setprecision(a);
#define sumvec(v,c) for(int i = 0;i<v.size();i++){c += v[i];}
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define zn(a,b,c) for(ll a=b;a<c;a++)
#define nz(a,b,c) for(ll a=b;a>c;a--)
#define MAX 1000000007
#define st stack
#define out(a) cout<<a<<"\n"
#define in(a) cin>>a
#define loop() for(;;)
#define frx(x,s) for(auto x: s)
#define read(v,n) for(int i = 0; i<n ; i++){ll t;cin>>t;v.pb(t);}
#define read1(v,n) for(int i = 1; i<n ; i++){cin>>v[i];}
#define sortv(ouas) sort(ouas.begin(),ouas.end())
#define outvec(v) for(int i = 0;i<v.size();i++){cout<<v[i]<<" ";}
#define sumvec(v,c) for(int i = 0;i<v.size();i++){c += v[i];}
#define outpair(v) for(auto i: v){cout<<i.first<<" "<<i.second<<endl;}
#define ump unordered_map
using namespace std;
vector<string> a;
bool cmp(pair<ll,ll> a,pair<ll,ll> b ){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

bool isPal(string s1){
    return s1 == string(s1.rbegin(), s1.rend());
}

bool check(vector<ll> v,ll d,ll c){
    ll last=-1e9;
    ll cnt=0;
    zn(i,0,v.size()){
        if(v[i]-last >= d){
            cnt++;
            last=v[i];
            if(cnt>=c) return true;

        }
    }
    return false;
}
bool bange(vector<ll> v,ll m,ll n){
    ll kinibangi=0;
    ll time=0;
    int k=1;
    zn(i,0,v.size()){
        k=2;
        time=v[i];
        
        while(time<=m){
            time+=v[i]*(k++);
            kinibangi++;
        }
        if(kinibangi>=n) return true;
    }
    return false;
}

ll power(ll base, ll exp){
    ll ans = 1;
    while(exp > 0){
        if(exp%2){
            ans *= base;
            ans%=mod;
            
        }
        base *= base;
        base %= mod;
        exp /= 2;
        
        // ans = base;
    }
    return ans%mod;
}
void bact(string s,ll currl,ll tar,vector<string>& ans){
    if(currl<=0){
        return;
    }
    if(s.empty()){
        return;
    }
    if(currl>2*tar){
        return;
    }
    if(currl==tar){
        cout<<s<<endl;
        ans.push_back(s);
    }
    string temp=s;
    temp.pop_back();
    bact(temp,currl-1,tar,ans);
    bact(s+s,2*currl,tar,ans);
}
bool win11(ll kinne,ll n,vector<ll> a,vector<ll> b){
    ll n1=n+kinne;
    ll un=n1-(n1/4);
    ll bakaya=0;
    ll l=un-kinne;
    zn(i,0,l){
        bakaya+=a[i];
    }
    ll mera1=kinne*100+bakaya;
    ll ohde1=0;
    ll m=min(un,n);
    zn(i,0,m){
        ohde1+=b[i];
    }
    return mera1>=ohde1;
}

struct Pair{
    ll node;
    vector<ll> temp;
};
vector<ll> ans;

bool help(stack<ll>& s,ump<ll,list<ll>>& mp,vector<ll>&v,ll src,vector<ll>&c){
    
    // c[src]=1;
    s.push(src);
  
        v[src]=1;
        if(v[src]==2){
            return true;
        }
        for(auto i:mp[src]){
            trace2(i,src);
            if(v[i]==1) {
                //cycle
                trace1(i);
                ans.pb(i);
                // cout<<s.size()<<endl;
                while(not s.empty()){
                    ans.pb(s.top());
                    if(s.top()==i) break;
                    s.pop();
                }

                return true;
            }
            if(v[i]==0 && help(s,mp,v,i,c)){
                // trace1(i);
                return true;
            }
        }
    
    v[src]=2;
    s.pop();
    return false;
}

void printg(ump<ll,list<ll>> mp){
        for(auto i:mp){
            // cout<<i.first<<"--->";
            for(auto j:i.second){
                cout<<j;
            }
            cout<<endl;
        }
    }

void solve(){
    ll n;
    cin>>n;
    ll s[n];
    ll t[n];
    string st,st1;
    cin>>st>>st1;
    zn(i,0,n){
        s[i]=st[i]-'0';
    }
    zn(i,0,n){
        t[i]=st1[i]-'0';
    
    }
    // zn(i,0,n){
    //     cout<<s[i];
    // }
    ll ans=0;
    // cin>>s>>t;
    if(t[0]==1 && s[1]==1){
        s[1]=0;
        ans++;
    }
    if(t[n-1]==1 && s[n-2]==1){
        s[n-2]=0;
        ans++;
    }
    fr(i, 0, n) {
        if (s[i] == t[i] && s[i] == 1) {
            if (i > 0 && s[i - 1] == 1) {
                ans++;
                s[i - 1] = 0;
                t[i] = 0;
            }
            else if (i < n - 1 && s[i + 1] == 1) {
                ans++;
                s[i + 1] = 0;
                t[i] = 0;
            }
        }
        else if (s[i] == 0 && t[i] == 1) {
            ans++;
            t[i] = 0;
        }
    }
    cout << ans << "\n";

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE      
    // code
    
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
