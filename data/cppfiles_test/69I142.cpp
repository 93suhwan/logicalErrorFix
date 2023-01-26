#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define rc (i<<1)|1
#define lc (i<<1)
#define el "\n"
#define f first
#define s second

typedef long long ll;
const int MM=2e5+5, MOD=1e9+7, LOG=19;
int T;
vector<string> p2;


int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>T;

    ll x=1;
    for(int i=1; i<=50; ++i) {
        p2.pb(to_string(x));
        x*=2LL; }
    while(T--) {
        string in;
        cin>>in;

        int ans=1e9;
        for(auto &e:p2) {

            int idx=0;
            for(int j=0; j<in.size(); ++j) {
                if(idx<e.size()&&in[j]==e[idx]) ++idx;
            }

            ans=min(ans, (int)(in.size()+e.size()-2*idx));
        }

        cout<<ans<<el;
    }
}

// MM