#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define rep(i, a, b) for(int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve(){

    int n;

    cin >> n;

    vector<int> a(n);
    set<int> st;
    st.insert(0);

    rep(i, 0, n){
        cin >> a[i];
    }

    rep(i, 0, n){
        rep(j, 0, 505){
            if(st.find(j) != st.end()) continue;
            int num = a[i] ^ j;
            if(num < a[i] && st.find(num) != st.end()){
                st.insert(j);
            }
        }
        st.insert(a[i]);
    }

    cout << st.size() << endl;
    for(auto x : st) cout << x << " ";
    cout << endl;
}

int32_t main(){

    IOS;

    int t;

	t = 1;

    rep(i, 1, t+1) solve();
}