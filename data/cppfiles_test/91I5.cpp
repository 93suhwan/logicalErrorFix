#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
using namespace std;
template <typename T>
using matrix = vector<vector<T>>;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INFL = (1LL<<62)-1;
const int INF = (1<<30)-1;
const double EPS = 1e-7;
const int MOD = 998244353;
const int MAXN = 1e6+1;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

struct chash{
    int operator() (int id) const{
        return id^RANDOM;
    }
};
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        

        ll resp = 0;
        vector<ll> dp ={0};
        vector<int> val={1};
        for(int i = 0; i < n-1; i++){
            
            vector<int> div, div2;
            div.reserve(sqrt(v[i])*2),div2.reserve(sqrt(v[i]));
            for(int j = 1; j <= sqrt(v[i+1]); j++){
                div.push_back(j), div2.push_back(v[i+1]/j);
            }
            for(int j = ssize(div2)-1; j >= 0; j--)
                div.push_back(div2[j]);
            div.erase(unique(all(div)),div.end());

            vector<ll> newdp(div.size());
            int ptr = 0;
            int check = ssize(dp)-1;
            for(int j = 0; j < div.size(); j++){
                ll group = (v[i]+div[j]-1)/(div[j]);
                int x = v[i]/group;
                while(ptr < ssize(val)-1 && val[ptr+1] <= x){
                    ptr++;
                }
                
                newdp[j] = (group-1)*(i+1)+dp[ptr];
            }


            
            resp+=dp[check];
            swap(dp,newdp);
            swap(val,div);
        }
        int ptr = 0;
        while(ptr < ssize(val)-1 && val[ptr] <= v[n-1])
            ptr++;
        //cout << n-1 << ' ' << val[ptr] << ' ' << dp[ptr] << '\n';
        resp+=dp[ptr];
        cout << resp << '\n';
    }

    return 0;

}