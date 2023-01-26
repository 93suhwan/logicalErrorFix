#include<bits/stdc++.h>
#define ull signed long long int
#define ll long long int
#define mod 1000000007
#define eb emplace_back
#define pb push_back
#define setull set <ull> 
#define mapull map<ull,ull>
#define pairull pair<ull,ull>
#define vull vector <ull>
#define vecpair vector<pair<ull,ull>>
#define printi(v) for(auto i : v) cout<<i<<" ";
#define printj(v) for(auto j : v) cout<<j<<" ";
#define printk(v) for(auto k : v) cout<<k<<" ";
#define repi(s,e,t) for(ull i=s;i<=e;i+=t)
#define repj(s,e,t) for(ull j=s;j<=e;j+=t)
#define repk(s,e,t) for(ull k=s;k<=e;k+=t)
#define rev_repi(s,e,t) for(ull i=s;i>=e;i-=t)
#define rev_repj(s,e,t) for(ull j=s;j>=e;j-=t)
#define rev_repk(s,e,t) for(ull k=s;k>=e;k-=t)
#define rev_str(s) reverse(s.begin(),s.end())
#define rev_vec(v) reverse(v.begin(),v.end())
#define rev_arr(a,n) reverse(a,a+n)
#define sort_str(s) sort(s.begin(),s.end())
#define sort_vec(v) sort(v.begin(),v.end())
#define sort_arr(a,n) sort(a,a+n)
#define sort_dec_str(s) sort(s.rbegin(),s.rend())
#define sort_dec_vec(v) sort(v.rbegin(),v.rend())
#define nw '\n'
using namespace std;
ull fact[200005];
bool isprime(ull n)
{
    if(n==1)
    {
        return false;
    }
    for(ull i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
vector<ull> allprimebetween(ull l,ull r)
{
    vector<bool> v(1000001,true);
    v[0]=v[1]=false;
    for(ull i=2;i*i<=1000001;i++)
    {
        if(v[i])
        {
            for(ull j=i*i;j<=1000001;j+=i)
            {
                v[j]=false;
            }
        }
    }
    vector<ull> prime;
    for(ull i=l;i<=r;i++)
    {
        if(v[i])
        {
            prime.pb(i);
        }
    }
    return prime;
}
bool samefreq(string a,string b)
{
    map<ull,ull>mpa;
    map<ull,ull>mpb;
    for(ull i=0;i<a.size();i++)
    {
        mpa[a[i]-'a']++;
    }
    for(ull i=0;i<b.size();i++)
    {
        mpb[b[i]-'a']++;
    }
    for(ull i=0;i<26;i++)
    {
        if(mpa[i]!=mpb[i])
        {
            return false;
        }
    }
    return true;
}
map<ull,ull> getfreq(string s)
{
    map<ull,ull> mp;
    for(ull i=0;i<s.size();i++)
    {
        mp[s[i]-'a']++;
    }
    return mp;
}
void YES()
{
    cout<<"YES"<<nw;
}
void NO()
{
    cout<<"NO"<<nw;
}
vector<ull> getfactors(ull n)
{
    vector<ull> v;
    for(ull i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.pb(i);
            if((n/i)!=i)
            {
                v.pb(n/i);
            }
            else
            {
                break;
            }
        }
    }
    sort_vec(v);
    return v;
}
bool ispalindrome(string s)
{
    string t(s.rbegin(),s.rend());
    return s==t;
}
ull ncrmodp(ull n, ull r, ull p)
{
    if(r>(n-r))
    {
        r=n-r;
    }
    ull C[r+1];
    memset(C,0,sizeof(C));
    C[0]=1; 
    repi(1,n,1)
    {
        rev_repj(min(i,r),1,1)    
        {                                    //for (ull j = min(i, r); j > 0; j--)
            C[j]=((C[j]+C[j-1])%p);
        }
    }
    return C[r];
}
ull gethighestoddfactor(ull n)
{
    while(n>0)
    {
        
        if(n%2!=0)
        {
            return n;
        }
        n=n/2;
    }
    return 1;
}
bool issorted(ull a[],ull n)
{
    ull b[n];
    repi(0,n-1,1)
    {
        b[i]=a[i];
    }
    sort_arr(b,n);
    repi(0,n-1,1)
    {
        if(a[i]!=b[i])
        {
            return false;
        }
    }
    return true;
}
ull power(ull x,ull y,ull p)
{
    ull res = 1;   
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
ull getarraygcd(ull a[],ull n)
{
    ull ans=a[0];
    repi(0,n-1,1)
    {
        if(a[i]==0)
        {
            continue;
        }
        ans=__gcd(ans,a[i]);    
    }
    return ans;
}
void calculate_fact()
{
    fact[0]=1;
    repi(1,200000,1)
    {
        fact[i]=((i%mod)*(fact[i-1]%mod))%mod;
    }
}
void goforeven(ull n,ull k)
{
    ull ans=0;
    repi(0,k-1,1)
    {
        ull temp=power(2,i,mod);
        ull t=power(temp,n,mod);
        ans+=t;
        ans%=mod;
    }
    ull temp=(n/2);
    ull ans1=0;
    repi(0,temp-1,1)
    {
        ull r=(2*i);
        ans1+=(fact[n]/(fact[n-r]*fact[r]));
        ans1%=mod;
    }
    ans1=power(ans1,k,mod);
    cout<<((ans%mod)+(ans1%mod))%mod<<nw;
}
void goforodd(ull n,ull k)
{
    ull ans=0;
    ull temp=(n/2);
    repi(0,temp,1)
    {
        ull r=(2*i);
        ans+=(fact[n]/(fact[n-r]*fact[r]));
        ans%=mod;
    }
    ans++;
    ans%=mod;
    cout<<ans<<nw;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calculate_fact();
    ull testcases;
    cin>>testcases;
    while(testcases--)
    {
        ull n,k;
        cin>>n>>k;
        if(k==0)
        {
            cout<<1<<nw;
            continue;
        }
        if(n%2==0)
        {
            goforeven(n,k);
        }
        else
        {
            goforodd(n,k);
        }
    }
    return 0;
}