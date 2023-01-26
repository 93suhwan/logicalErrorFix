#include<bits/stdc++.h>
#include<sstream>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const long long INF=1e18;
const int inf = 1e9;
const long long mod = 1e9+7;
const int N = 1e6+8;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define T() int tt; cin>>tt; while(tt--)
#define ll long long
#define prec cout<<fixed<<setprecision(15);
#define ld long double  
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pipi pair<int, pair<int, int>>
#define vii vector<int>
#define F first
#define S second
#define fill(v,p) memset(v, p, sizeof(v))
#define print(v) for(auto &z : v)cout<<z<<" ";cout<<'\n';
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793
#define rank asdf
int main()
{
    T(){
        ll n;
        cin>>n;
        int t1 = 1;
        int t2 = n-1;
        if(t2 % 2 != 0){
            int p1 = t2/2, p2 = t2 - p1;
            cout<<p1<<" "<<p2<<" "<<1<<'\n';continue;
        }
        else{
            t2--;
            int p1 = t2/2 + 1, p2 = t2-p1;
            cout<<p1<<" "<<p2<<" "<<2<<'\n';
            continue;
        }
        bool f = 0;
            for(int i = 2; i*i <= n; i++){
                if(n % i == 0 ){
                    int v = n/i - 1, a1, a2;
                    if(v % 2 == 0){
                        a1 = v/2+1, a2 = v - a1;
                    }
                    else{
                        a1 = v/2, a2 = v - a1;
                    }
                    a1*=i, a2*=i;
                    int a3 = i;
                    if(a1 == a2 || a2 == a3 || a3 == a1)continue;
                    if(__gcd(a1, a2) != i)continue;
                    cout<<a1<<" "<<a2<<" "<<i<<'\n';
                    f = 1;
                    break;
                }
            }
        if(f)continue;
        int a1 = 1;
        int a2 = (n-1)/2 -1, a3 = (n-1)/2 + 1;
        cout<<a2<<" "<<a3<<" "<<a1<<'\n';
    }
}