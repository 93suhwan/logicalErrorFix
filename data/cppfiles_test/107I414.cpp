// write spf function->pf[i]=i
//if using dp in seive iterate till n, not i*i=n
// check for boundary values of a vector and string ->that pos is available or not
//always keep a back up if the loop doesn't iterate then cout<<-1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")
#pragma gcc optimize("unroll-loops")
using namespace std;
using namespace __gnu_pbds;
// const int INF = 1e18;
const int TMX = 1 << 18;
const long long llINF = 2e18+5;
const long long mod = 1e8;
const long long hashmod = 100003;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <ll> vecl;
typedef vector <pi> vecpi;
typedef long long ll;
typedef unsigned long long ull;
typedef std::numeric_limits< double > dbl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define setbits(x) __builtin_popcountll(x)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(dbl::max_digits10);
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define ln cout<<"\n"
#define print2d(dp,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++)cerr<<dp[i][j]<<" ";cerr<<"\n";}
#define fill(dp,x) memset(dp,x,sizeof(dp))
int32_t main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        if(n==2){
            cout<<-1<<endl;
            continue;
        }
        if(n==3){
            if(a==1&&b==0){
                cout<<2<<" "<<3<<" "<<1<<endl;
            }
            else if(a==0&&b==1){
                cout<<2<<" "<<1<< " "<<3<<endl;
            }
            else{
                cout<<-1<<endl;
            }
            continue;
        }
        if(abs(a-b)>1LL){
            if(n%2==1){
                if(abs(a-b)==0LL){
                    cout<<-1;
                    continue;
                }
            }
            cout<<-1<<endl;
            continue;
        }
        vector<ll> v(n);
        rep(i,1,n+1){
            v[i-1]=i;
        }
        if(a==b){
            int mx=a,mn=b;
            for(int i=1;i<n-2;i+=2){
                if(a==0||b==0){
                    break;
                }
                swap(v[i],v[i+1]);
                a--;
                b--;
            }
            if(a>0||b>0){
                cout<<-1<<endl;
                continue;
            }
        }
        if(b>a){
            for(int i=n-2;i>2;i-=2){
                if(a<=0||b<=1){
                    break;
                }
                swap(v[i],v[i-1]);
                a--;
                b--;
            }
            if(a>0||b>1){
                cout<<-1<<endl;
                continue;
            }
            swap(v[0],v[1]);
        }
        if(a>b){
            for(int i=1;i<n-3;i+=2){
                if(a<=1 || b<=0){
                    break;
                }
                swap(v[i],v[i+1]);
                a--;
                b--;
            }
            if(b>0||a>1){
                cout<<-1<<endl;
                continue;
            }
            swap(v[n-2],v[n-1]);
        }
        rep(i,0,n){
            cout<<v[i]<<" ";
        }
        ln;
    }
    return 0;
}