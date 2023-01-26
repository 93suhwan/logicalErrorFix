#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

const ll mod=1e9+7;
ll bin(ll a, ll b){
    if(b==0)
        return 1;
    if(b&1)
        return (a*bin((a*a)%mod, b/2))%mod;
    return (1*bin((a*a)%mod, b/2))%mod;
}

pair<ll,ll> simplify(pair<ll,ll>p1){
    ll com=__gcd(p1.first,p1.second);
    p1.first/=com;
    p1.second/=com;
    return p1;
}
pair<ll,ll>add(pair<ll,ll>p1,pair<ll,ll>p2){
    ll denom = (p1.second*p2.second)/__gcd(p1.second,p2.second);
    ll numer = ((denom/p1.second)*p1.first) + ((denom/p2.second)*p2.first);
    return simplify({numer,denom});
}


void I_m_Beast()
{    
    ll n,m,a,b,x,y,p;
    cin>>n>>m>>a>>b>>x>>y>>p;
    ll q;
    ll oa=a,ob=b;
    ll time=0;
    ll dr=1,dc=1;
    vector<int>timer;
    while(1){   
        if(a==oa and b==ob and timer.size()>0){
            break;
        }
        if(a==x || b==y){
            timer.push_back(time);
        }
        int na=a+dr;
        int nb=b+dc;
        if(na<1 || na>n){
            dr=-dr;
        }
        if(nb<1 || nb>m){
            dc=-dc;
        }
        na=a+dr;
        nb=b+dc;
        a=na;
        b=nb;
        time++;
    }
    ll sizeTimer=timer.size();
    ll d=time;
    q=100-p;
    ll sumTimes=0;
    for(int i=0;i<timer.size();i++){
        ll denom1 = (bin(100,sizeTimer)-bin(q,sizeTimer)+mod)%mod;
        ll numer1 = (((denom1*timer[i])%mod)*bin(100,sizeTimer))%mod; 
        ll numer2 = (((d*bin(q,sizeTimer))%mod)*bin(100,sizeTimer)%mod)%mod;
        ll numer = ((numer1+numer2)%mod);
        ll denom= (bin(denom1,2));
        ll val=(numer*bin(denom,mod-2))%mod;
        val=(val*bin(q,i))%mod*bin(bin(100,i),mod-2)%mod;
        sumTimes+=val;
        sumTimes%=mod;
    }
    sumTimes*=p;
    sumTimes%=mod;
    sumTimes=(sumTimes*bin(100,mod-2))%mod;    
    cout<<sumTimes<<endl;
}

int main()
{    
    fastio;
    int t=1;
    cin>>t;
    while(t--)
    {
        I_m_Beast();
    }    
    return 0;    
}