/**
*   author : GDA
*   created : 11/02/2021
*
**/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define distinct(x) sort((x).begin(),(x).end()); x.resize(unique((x).begin(),(x).end())-x.begin());
#define sz(x)  (long long)(x).size()
#define resz resize
#define Vec vector
#define lowerB lower_bound
#define upperB upper_bound
#define mkp make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define ms(dp,a) memset(dp,(ll)a,sof(dp))
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PRECISION(n) std::cout.unsetf ( std::ios::floatfield );std::cout.precision((long long)n)
#define getsm(v) accumulate(all(v),0ll)
#define getmx(v) max_element(all(v))
#define getmn(v) min_element(all(v))
#define ws1(a) cout<<(a)<<" "
#define wr1(a) cout<<(a)<<endl
#define wr2(a,b) cout<<(a)<<" "<<(b)<<endl
#define wr3(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
#define wr4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define ww1(a) cout<<(a)<<"\n"
#define ww2(a,b) cout<<(a)<<" "<<(b)<<"\n"
#define ww3(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<"\n"
#define ww4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<"\n"
#define FileIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define PI 3.14159265358979323846264338327950288419716939937510
#define fi first
#define se second
#define here cout<<"RSSB"<<endl
#define dbg cout<<"Krishna"<<endl
#define showzero cout<<std::showpoint
#define bitcount( x ) (int)__builtin_popcountll( x )
#define ls(i) (1ll<<(i))
using namespace __gnu_pbds; //required
using namespace  std ;
#define int long long
typedef vector<int>vi ;
typedef vector<int>vll ;
typedef vector<vector<int> >vvl ;
typedef pair<int,int> pll ;
typedef vector<pll>vpll ;
typedef vector<string>vstr;
typedef vector<bool>vbool ;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T = int>
void readArray(vector<T> &v, int n){T a ;for(int i=0 ; i<n ; i=i+1){cin>>a ;v.push_back(a);}}
template <class T = int>
void printArray(vector<T> &v , int a = 0){for(int i=a ; i<v.size() ; i=i+1){/*v[i] = max((int)0,v[i]);*/cout<<v[i]<<"\n" ;}cout<<"\n" ;}

// const int mod  = 1000000007;//Area of mod
const int mod = 998244353;

int stringToInteger(string str1 , int x = 0){int a,b;b = sz(str1);a = 0;int c = 1;reverse(all(str1));for(int i=0 ; i<b ; i++){a+=(str1[i]-'0')*c;c*=10;if(x){c%=mod;a%=mod;}}return(a);}
string integerToString(int x){string str1 = "";while(x){int c = x%10;str1+=(c+'0');x/=10;}reverse(all(str1));return(str1);}
double logy(int n , int b){if(b==0){return(-1);}if(n==1){return(0);}return((double)log10(n)/(double)log10(b));}
long long power(long long k , long long n , long long m=mod){long long res = 1;while(n){if(n%2!=0){res = (res*k)%m ;}k = (k*k)%m ;n = n/2 ;}return(res) ;}
double powerD(double k , long long n ){double res = 1;while(n){if(n%2!=0){res = (res*k) ;}k = (k*k) ;n = n/2 ;}return(res) ;}
int gcdExtend(int a , int b , int &x , int &y){if(a==0){x = 0;y = 1;return(b);}int x1,y1;int g = gcdExtend(b%a,a,x1,y1);x = y1 - (b/a)*x1;y = x1;return(g);}
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) {return((a/gcd(a,b))*b);}
void coordinateCompress(vll &v){vll v1 = v;distinct(v1);for(auto &j : v){j = upperB(all(v1),j) - v1.begin();}}
double distance(pair<double,double> a , pair<double,double> b){return((double)(sqrt( ((a.first-b.first)*(a.first-b.first)) + ((a.second-b.second)*(a.second-b.second)))));}
const int ddx[8] = {-1,1,0,0,-1,1,-1,1};
const int ddy[8] = {0,0,-1,1,-1,-1,1,1};
const int N = 500003;  //N idhar hai
const int M = 300003;  //M idhar hai
const int inf = 1e15;
const int minf = -1e17;
int n,m,k,a1,a2,a3,h,t;
//double prob;
string str,str1,str2;
bool ok = true;
vstr v;
void check()
{
    int i,j;
    //aabbd.
    //bbaad.
    //aacdc.
    //bbcdc.
    //k left
    int a = 0;
    for(j=0 ; j<m ; j+=2)
    {
        for(i=0 ; i<n ; i+=2)
        {
            if(!k)
            {
                break;
            }
            k-=2;
            v[i][j] = v[i][j+1] = (a+'a');
            v[i+1][j] = v[i+1][j+1] = ((!a) + 'a');
        }
        a^=1;
        if(!k)
        {
            break;
        }
    }
    a = 0;
    for(j=0 ; j<m ; j++)
    {
        int b = a;
        for(i=n-1 ; i>=0 ; i-=2)
        {
            if(v[i][j]!='?')
            {
                break;
            }
            v[i][j] = v[i-1][j] = ((a+2) + 'a');
            a^=1;
        }
        a = b^1;
    }
}
void solveIt()
{
    //* Check for N <---> Given Constraints(1)
    //* Check For int <---> long long
    int a,b,c,d,i,j,x,y,z,tt;
    int p,q,r,w;
    // string str2;
    char ch;
    // memset(dp,-1,sizeof(dp));
    //* Batman has no limits.
    //* Glorious Purpose
    cin>>tt;
    while(tt--)
    {
        v.clear();
        cin>>n>>m>>k;
        x = 0;
        v.assign(n,string(m,'?'));
        if(n%2)
        {
            //n = 5
            //m = 6
            //aabbaa
            //bbaadc
            //aabbdc
            //bbcdcd
            //aacdcd
            x = m/2;
            if((x%2)==(k%2) && x<=k)
            {
                ww1("YES");
                a = 0;
                i = 0;
                for(j=0 ; j<m ; j+=2)
                {
                    k--;
                    v[i][j] = v[i][j+1] = (a + 'a');
                    a^=1;
                }
                a = 1;
                for(j=0 ; j<m ; j+=2)
                {
                    for(i=1 ; i<n ; i+=2)
                    {
                        if(!k)
                        {
                            break;
                        }
                        k-=2;
                        v[i][j] = v[i][j+1] = (a+'a');
                        v[i+1][j] = v[i+1][j+1] = ((!a) + 'a');
                    }
                    a^=1;
                    if(!k)
                    {
                        break;
                    }
                }
                a = 0;
                for(j=0 ; j<m ; j++)
                {
                    b = a;
                    for(i=n-1 ; i>=0 ; i-=2)
                    {
                        if(v[i][j]!='?')
                        {
                            break;
                        }
                        v[i][j] = v[i-1][j] = ((a+2) + 'a');
                        a^=1;
                    }
                    a = b^1;
                }
                printArray<string>(v);
            }
            else
            {
                ww1("NO");
            }
            continue;
        }
        else
        {
            //n = 4
            x = 0;
            if(m%2)
            {
                //m = 5
                //....x
                //....x
                //....x
                //....x
                y = n/2;
                x = (n*m)/2 - y;
                if(k%2 || k>x)
                {
                    ww1("NO");
                }
                else
                {
                    ww1("YES");
                    j = m-1;
                    for(i=0 ; i<n ; i++)
                    {
                        v[i][j] = 'x';
                    }
                    m--;
                    //n = 4
                    //m = 4;
                    check();
                    printArray<string>(v);
                }
                continue;
            }
            else
            {
                //m = 4
                if(k%2)
                {
                    ww1("NO");
                }
                else
                {
                    ww1("YES");
                    //n = 4;
                    //m = 4;
                    check();
                    printArray<string>(v);
                }
            }
        }
    }
}
int32_t main()
{
#ifndef ONLINE_JUDGE
       freopen("Rinput.txt", "r", stdin);
       freopen("Routput.txt", "w", stdout);
#endif
    //* SpeakOutLoudWhatYouAreThinkingWhileSolvingQuestion
    //* WhyDoWeFallBruce?
    //* I Don't Ever Give Up-ElonMusk
    //* Zero-ImagineDragons
    //* WorkHardAndSolveProblemAboveYourLevel
    FastIO;
    PRECISION(12);
    //FileIO;
    //Inverse Modulo(for division under mod) = phi(m) - 1 ===> if m is prime then = m-2
    // dr.pb(mkp(0,1));dr.pb(mkp(1,0));dr.pb(mkp(0,-1));dr.pb(mkp(-1,0));
    //For a Graph Problem Sometimes BFS instead of DFS is much helpful
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solveIt();
    }
    // const ll ddx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    // const ll ddy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    //WhateverItTakes
    //FOCUS
    //BeABelieverWarrior
    //DO IT UNTIL YOU RUN OUT OF IDEAS ~ YOU KNOW WHO
    //See The Editorial Almost Never ~ YOU KNOW WHO

}