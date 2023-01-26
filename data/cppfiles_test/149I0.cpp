#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
const int mod = 1e9+7;
const int maxN = 2e5+1;
#define endl '\n'
 
inline void debugMode() {

#ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
 
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE
}

// #define int long long

int mul(int a , int b) {
    return (ll)a*b%mod;
}

int pow(int a , int p) {
    int ans = 1;
    while(p) {
        if(p&1) {
            ans = mul(a , ans);
        }
        a = mul(a , a);
        p/=2;
    }
    return ans%mod;
}

int inv(int a , int m) {
    return pow(a , m-2);
}

int add(int a , int b) {
    int ans= ((ll)a+b)%mod;
    if(ans < 0) {
        ans += mod;
    }
    return ans;
}

void test_case() {
    int q;
    cin >> q;
    vector<vector<int>> query;
    for(int i = 0 ; i < q ; i++) {
        int type, x;
        cin >> type >> x;
        if(type == 1) {
            query.push_back({type, x});
        }
        else {
            int y;
            cin >> y;
            query.push_back({type,x, y});
        }
    }
    reverse(query.begin(), query.end());
    vector<int> ans;
    map<int, int> m;
    for(int i = 0 ; i < q ; i++) {
        vector<int> que = query[i];
        if(que.size() == 2) {
            if(m.find(que[1]) == m.end())
                ans.push_back(que[1]);
            else
                ans.push_back(m[que[1]]);
        }
        else {
            if(que[1] == que[2]) {
                continue;
            }
            int to = que[2];
            while(m.find(to) != m.end())
                to = m[to];
            m[que[1]] = to;
        }
    }
    reverse(ans.begin(), ans.end());
    for(int x: ans) {
        cout << x << " ";
    }
}

// #undef int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    debugMode();
    int t;
    t = 1;
    // cin >> t;
    while(t--) {
        test_case();
    }
    // for(int i = 1 ; i <= t ; i++) {
    //  cout << "Case #" << i << ": ";
    //  test_case();
    // }
    return 0;
}