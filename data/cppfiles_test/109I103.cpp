#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<stack>
#include<cmath>
#include<numeric>
#include<cassert>
#include<limits>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>


using namespace __gnu_pbds; 
using namespace std;
 
#ifndef POJ
    #define Cpp11
#endif
 
#ifdef Cpp11
    #define _for(i,a,b) for(auto i = (a);i<(b);++i)
    #define _rep(i,a,b) for(auto i = (a);i<=(b);++i)
    #define _dep(i,a,b) for(auto i = (a);i>=(b);--i)
    #define mt(a,b,c) make_tuple(a,b,c) 
    #include<ctime>
    #include<random>
    #include<chrono>
    #include<limits>
    #include<complex>
    #include<unordered_set>
    #include<unordered_map>
    #include<cassert>
    #include<functional>
    #include<bitset>
    #define IO ios::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr);
#endif
 
#ifndef Cpp11
    #define _for(i,a,b) for(int i = (a);i<(b);++i)
    #define _rep(i,a,b) for(int i = (a);i<=(b);++i)
    #define _dep(i,a,b) for(int i = (a);i>=(b);--i)
    #define IO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#endif
 
 
using namespace std;


 
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define sci(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
#define debugline fprintf(stderr,"-----------------------\n");
#define szint(x) ((int)(x).size())


 
#ifdef I128IO
typedef __int128 SPLL;
char buff[200];
template<typename T>
void read(T& o)
{
    o = 0;
    scanf("%s",buff);
    //printf("%s\n",buff);
    T f = 1;
    int i = 0;
 
    if(buff[0]=='-')i++,f = -1;
    for(;buff[i];++i)
    {
        o*=10,o+=buff[i]-'0';
    }
    o*=f;
}
 
template<typename T>
void write(T o)
{
    int len = 0;
    buff[0] = '0';
    if(o==0)
    {
        putchar('0');
        return;
    }
    int f = 1;
    if(o<0) f = -1;
    o*=f;
    for(;o;o/=10) buff[len++] = o%10+'0';
    if(f==-1) buff[len++] = '-';
    reverse(buff,buff+len);
    buff[len++] ='\0';
    printf("%s",buff);
}
#endif
 
#ifdef FIO
char buff[100];
template<typename T>
void read(T& o)
{
    o = 0;
    scanf("%s",buff);
    //printf("%s\n",buff);
    T f = 1;
    int i = 0;
    if(buff[0]=='-')i++,f = -1;
    for(;buff[i];++i)
    {
        o*=10,o+=buff[i]-'0';
    }
    o*=f;
}
template<typename T>
void write(T o)
{
    int len = 0;
    buff[0] = '0';
    if(o==0)
    {
        putchar('0');
        return;
    }
    int f = 1;
    if(o<0) f = -1;
    o*=f;
    for(;o;o/=10) buff[len++] = o%10+'0';
    if(f==-1) buff[len++] = '-';
    reverse(buff,buff+len);
    buff[len++] ='\0';
    printf("%s",buff);
}
#endif

#define OIreader


#ifdef OIreader
inline int read(){
    char ch; bool sign=0; int res=0;
    while(!isdigit(ch=getchar()))if(ch=='-')sign=1;
    while(isdigit(ch))res=res*10+(ch^48),ch=getchar();
    if(sign)return -res; else return res;
}
#endif

#ifdef _Random_
    mt19937 __MT(chrono::system_clock::now().time_since_epoch().count());
#endif
 
#ifndef BigNumber
    typedef unsigned long long uLL;
    typedef long long LL;
    typedef long long ll;
    typedef pair<LL,LL> pLL;
    typedef vector<LL> vL;
    typedef vector<vL> vLL;
#endif

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<int,int> pii;


// Do anything to the best and be faced with the unchangeable reality with smiles.
// Sorry Falcon__


const int maxn = 200000+10;
const int mod = 998244353;
const LL inf =1e18;
const int maxm = 23;
const double eps = 1e-8;
const int apsz = 26;
const int maxe = 200000+10;


int fac[maxn],invfac[maxn];


inline int mul(int x,int y)
{
    return 1LL*x*y%mod;
}

inline int add(int x,int y)
{
    x+=y;
    if(x>=mod) x-=mod;
    else if(x<0)x+=mod;
    return x;
}


inline int fpow(int x,int y)
{
    int ans = 1;
    for(;y;y>>=1,x = mul(x,x))
        if(y&1) ans = mul(ans,x);
    return ans;
}


inline int C(int n,int m)
{
    if(n<0||m<0||n<m)
        return 0;
    return mul(fac[n],mul(invfac[m],invfac[n-m]));
}


inline void init()
{
    fac[0]++;
    _for(i,1,maxn) fac[i] = mul(fac[i-1],i);
    int now = fpow(fac[maxn-1],mod-2);
    _dep(i,maxn-1,1)
    {
        invfac[i] = mul(now,fac[i-1]);
        now = mul(now,i);
        assert(mul(i,invfac[i])==1);
    }
    invfac[0]++;
    _for(i,1,maxn) invfac[i] = mul(invfac[i-1],invfac[i]);
}

int cb,cw;
int qq,q,n;
string co[maxn];

inline int solve()
{
    if(cb>n||cw>n) return 0;
    int ans = C(q,n-cw);
    int cnt01 = 0;
    int cnt10 = 0;
    _for(i,0,n)
    {
        if(co[i][0]==co[i][1]&&co[i][0]!='?')
            return ans;
        if(co[i]=="??")
            continue;
        if(co[i][0]=='W'||co[i][1]=='B')
        {
            cnt01++;
        }
        if(co[i][0]=='B'||co[i][1]=='W')
        {
            cnt10++;
        }
    }
    if(cnt10&&cnt01)
    {
        ans = add(ans,mod-fpow(2,qq));
    }
    else
    {
        ans = add(ans,mod-add(fpow(2,qq),mod-1));
    }
    return ans;
}


int main(void)
{
    init();
    sci(n);
    _for(i,0,n)
    {
        char s[10];
        scanf("%s",s);
        if(s[0]=='?'&&s[1]=='?')
            qq++;
        co[i] = s;
        _for(j,0,2)
        {
            if(s[j]=='W')
                cw++;
            else if(s[j]=='B')
                cb++;
            else
            {
                q++;
            }
        }
        
    }
    printf("%d\n",solve());
    return 0;
}