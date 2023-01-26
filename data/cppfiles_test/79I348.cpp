#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define inf 1000000000000000000
#define iinf -1000000000000000000
#define __   ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define MOD 1000000007
#define uu first
#define vv second
#define en '\n'

pi operator+(pi a, ll x)     {return {a.uu + x, a.vv + x} ;}
pi operator- (pi a, ll x)     {return {a.uu - x, a.vv - x} ;}
pi operator* (pi a, ll x)     {return {a.uu * x, a.vv * x} ;}
pi operator+(pi x, pi y) { return {x.uu + y.uu,x.vv + y.vv} ;}
pi operator-(pi x,pi y) { return {x.uu - y.uu, x.vv - y.vv} ;}
pi operator*(pi x,pi y) { return {x.uu * y.uu , x.vv * y.vv} ;}
pi operator%(pi x,pi y) { return {x.uu % y.uu, x.vv % y.vv} ;}

const pi base = {103,101};

const pi  mod = {1000000021, 1e9 + 9 };

ll Set(ll N,ll pos){ return N=N | (1LL<<pos); }
ll reset(ll N,ll pos){ return N= N & ~(1LL<<pos); }
bool check(ll N,ll pos){ return (bool)(N & (1LL<<pos)); }

ll ar[]={0,0,1,-1};
ll br[]={1,-1,0,0};

///*******GEOMETRY**********///
double PI=acos(-1.0);

double gcd(double a,double b){
    return fabs(b)<1e-4?a:gcd(b,fmod(a,b));
}

///*******GEOMETRY**********///

ll bigmod(ll n,ll pow){
if(pow==0) return 1;
if(pow==1) return n%MOD;

ll ans=bigmod(n,pow/2);
ans=(ans*ans)%MOD;

if(pow%2==1){ans=(ans*n)%MOD;}
return ans%MOD;
}

ll fact[1000005];

ll nCr(ll n,ll r){

ll ans=fact[n];
ans=(ans*bigmod(fact[r],MOD-2))%MOD;
ans=(ans*bigmod(fact[n-r],MOD-2))%MOD;
return ans;
}

string s,s1,s2;
ll n,m;
ll arr[500010];
ll brr[50];
vector<ll>v,v1;

map<ll,ll>mp;
ll vis[500005];

ll fnc(string ss,ll mask){
    ll i,j,sz=ss.size();
    s1="";
    reverse(ss.begin(),ss.end());
    for(i=0;i<5;i++){
        if(check(mask,i)) s1.push_back(ss[i]);
    }
    reverse(s1.begin(),s1.end());
    ll ans=0;
    for(i=0;i<s1.size();i++){
        ans=ans*10+s1[i]-'0';
    }
    if(vis[ans]==1) return 1;
    else return 0;
}

int main()
{__
        ll i,j,a,b,c,d,e,f,g,x,y,z,t,k,l,r;
        fact[0]=1;

      //  for(i=1;i<=1000000;i++) fact[i]=(fact[i-1]*i)%MOD;
        ll ans=0,sum=0,temp;
        vis[0]=0;
        for(i=2;i<=100000;i++){
            if(vis[i]==0){
                for(j=i*i;j<=100000;j+=i) vis[j]=1;
            }
        }

        cin>>t;

        for(ll cz=0;cz<t;cz++){
            cin>>n>>s;
            string ss=s;
            for(i=0;i<n;i++){
                if(s[i]=='1'||s[i]=='4'||s[i]=='6'||s[i]=='8') break;
            }
            if(i<n){cout<<1<<endl<<s[i]<<endl; continue;}
            for(i=1;i<n;i++){
                if(s[i]=='0'||s[i]=='5') break;
            }
            if(i<n){cout<<2<<endl<<s[0]<<s[i]<<endl; continue;}
            if(n<=5){
                for(j=0;j<(1LL<<n);j++){
                    if(fnc(s,j)==1){
                           // cout<<" "<<j<<endl;
                        if(ss.size()>s1.size()) ss=s1;
                    }
                }
                cout<<ss.size()<<endl<<ss<<endl;
            }
            else{
                memset(brr,0,sizeof(brr));
                for(j=0;j<n;j++) {brr[s[j]-'0']++; if(brr[s[j]-'0']!=1) break;}
                cout<<2<<endl<<s[j]<<s[j]<<endl;
            }

        }
}


