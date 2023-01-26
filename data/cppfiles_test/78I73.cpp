#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

#define FOR(i, l, r, d) for(int i=(l); i<=(r); i+=(d))
#define szof(x) ((int)(x).size())

#define vi vector<int>
#define pii pair<int, int>

#define F first
#define S second

#define pb push_back
#define eb emplace_back
#define mkp make_pair

const int INF = 2147483647;
const int LNF = INF*INF;
const int MOD = 1000000007;
const int mod = 998244353;
const double eps = 1e-12;

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

const int MAX = 200010;

int n;
int arr[MAX];
int cnt[20];
vi res;

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){

        cin>>n;
        FOR(i, 1, n, 1){
            cin>>arr[i];
        }

        FOR(j, 0, 19, 1){
            cnt[j] = 0;
        }
        res.clear();

        FOR(i, 1, n, 1){
            FOR(j, 0, 19, 1){
                if(arr[i] & (1<<j)) cnt[j]++;
            }
        }

        int gcd = INF;
        FOR(j, 0, 19, 1){
            if(cnt[j] == 0) continue;
            if(gcd == INF) gcd = cnt[j];
            else gcd = __gcd(gcd, cnt[j]);
        }

        res.clear();
        if(gcd == INF){
            FOR(i, 1, n, 1){
                res.pb(i);
            }
        }
        else{
            FOR(i, 1, gcd, 1){
                if(gcd % i == 0) res.pb(i);
            }
        }

        for(int i : res){
            cout<<i<<" ";
        }
        cout<<'\n';

    }

    return 0;

}

