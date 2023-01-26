//*******************************************♥BISMILLAHIR RAHMANIR RAHIM♥******* ************************************//
/*
                            Asif Uddin Ahmed Hemel || CSE,IUBAT || hemel18103112@gmail.com
                                                                                  .--------------.
                                                                                  | Try First One|
                                                hemel18681                        '--------------'
                                                                                          |     .--------------.
                                                                                          |     |              |
                                                                                          V     V              |
                                                                                        .--------------.       |
        ▀                               ▀      ▀    ▀▀▀▀▀▀▀ ▀       ▀▀▀▀▀▀▀    ▀        |  *ACCEPTED*  |<---.  |
        ▀                               ▀     ▀▀    ▀     ▀ ▀       ▀     ▀   ▀▀        '--------------'    |  |
        ▀                               ▀    ▀ ▀    ▀     ▀ ▀       ▀     ▀  ▀ ▀        (True)|  |(False)   |  |
        ▀                               ▀   ▀  ▀    ▀     ▀ ▀       ▀     ▀ ▀  ▀     .--------'  |          |  |
        ▀▀▀▀▀▀▀ ▀▀▀▀▀▀▀ ▀       ▀▀▀▀▀▀▀ ▀      ▀    ▀▀▀▀▀▀▀ ▀▀▀▀▀▀▀ ▀▀▀▀▀▀▀    ▀     |           V          |  |
        ▀     ▀ ▀     ▀ ▀▀▀▀▀▀▀ ▀     ▀ ▀      ▀    ▀     ▀ ▀     ▀ ▀     ▀    ▀     |  .--------------.    |  |
        ▀     ▀ ▀▀▀▀▀▀▀ ▀  ▀  ▀ ▀▀▀▀▀▀▀ ▀      ▀    ▀     ▀ ▀     ▀ ▀     ▀    ▀     |  |   Try Again  |----'  |
        ▀     ▀ ▀       ▀  ▀  ▀ ▀       ▀      ▀    ▀     ▀ ▀     ▀ ▀     ▀    ▀     |  '--------------'       |
        ▀     ▀ ▀▀▀▀▀▀▀ ▀  ▀  ▀ ▀▀▀▀▀▀▀ ▀▀▀ ▀▀▀▀▀▀▀ ▀▀▀▀▀▀▀ ▀▀▀▀▀▀▀ ▀▀▀▀▀▀▀ ▀▀▀▀▀▀▀  |                         |
                                                                                     |  .--------------.       |
                                                                                     '->| Try Next One |-------'
                                                                                        '--------------'
                                    ♥ ঘরে থাকুন , সুস্থ থাকুন - STAY HOME , STAY SAFE ♥
*/
#include<bits/stdc++.h>
#include<vector>
#include<bitset>
#ifndef ONLINE_JUDGE
    #include "hemel18681.h"
#endif
#define start_hemel int main() {
#define end_hemel return 0; }
#define ll long long
#define ull unsigned long long
#define ld long double
#define pi 2*acos(0.0)
#define eb emplace_back
#define endl "\n";
#define line cout<<endl;
#define sp    <<" "<<
#define pb push_back
#define stdebug ifndef ONLINE_JUDGE
#define endebug endif
#define ppb pop_back
#define mp make_pair
#define vc vector
#define setp(a,b) cout<<fixed<<setprecision(a)<<b<<endl;
#define co(x) cout<<x<<nl
#define coo(x) cout<<x<<" ";
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define ff first
#define ss second
#define ui unsigned  
#define all(x) x.begin(),x.end()
#define sortn(v) v.begin(),v.end()
#define sortr(v) v.rbegin(),v.rend()
#define loop(i,a,b)   for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0);
using namespace std;

typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef tuple<int, int, int> tpl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;


const int maxn = 100000007;
const double eps = 1e-6;
const ll Inf = 1LL << 62;
const ll mod = 1000000007;
const ll pnum = 5761460;



void solve_with_case(int cas){
    
}



void solve_without_case(){
    ll x; cin>>x;
    ll arr[2][x];
    for(int i=0;i<2;i++){
        for(int j=0;j<x;j++){
            cin>>arr[i][j];
        }
    }
    ll c1[x]={0}, c2[x]={0}, c3[x]={0}, mx = -1, p = -1;
    c1[0] = arr[0][0];
    c2[0] = arr[1][0];
    loop(i,1,x-1) c1[i]=arr[0][i]+c1[i-1];
    loop(i,1,x-1) c2[i]=arr[1][i]+c2[i-1];
    for(int i=0;i<x;i++){
        c3[i] = c1[i]+c2[x-1];
        if(i-1>0){
            c3[i]-=c2[i-1];
        }
        if(c3[i]>mx){
            mx = c3[i];
            p = i;
        }
    }
    for(int i=0;i<=p;i++){
        arr[0][i] = 0;
    }
    for(int i=p;i<x;i++){
        arr[1][i] = 0;
    }
    c1[0] = arr[0][0];
    c2[0] = arr[1][0];
    loop(i,1,x-1) c1[i]=arr[0][i]+c1[i-1];
    loop(i,1,x-1) c2[i]=arr[1][i]+c2[i-1];
    mem(c3,0);
    mx = -1;
    for(int i=0;i<x;i++){
        c3[i] = c1[i]+c2[x-1];
        if(i-1>0){
            c3[i]-=c2[i-1];
        }
        if(c3[i]>mx){
            mx = c3[i];
        }
    }
    cout<<mx<<endl;
}



//before start coding goto windows security and turn off Cloud-delivered protection 
//else you will get 10 second delay after every compile and it will take more time

start_hemel

fastIO

#ifndef ONLINE_JUDGE
    double start_time = clock();
    freopen("error.txt","w",stderr);
#endif

    int t,cas=0; cin>>t;

    while(t--){
        solve_without_case();
        //solve_with_case(cas);
        //cas++;
    }

#ifndef ONLINE_JUDGE
    double end_time = clock();
    cout<<"Time = "<<((end_time-start_time)/CLOCKS_PER_SEC)<<"\n";
#endif

end_hemel


//***♥ALHAMDULILLAH♥***//
