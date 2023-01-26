#include <bits/stdc++.h>

#define IO  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define endl '\n'
#define f first
#define s second
#define ll long long
#define ld long double
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<pair < int , int > , null_type,less<pair < int , int > >, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;
const int M = 2e5 + 5, C = 1e5 + 5;

int main() {
    IO
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<pair<int,int>> dq;
        int x;
        ll ans = 0;
        ordered_set st;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (dq.empty()) {
                dq.push_back({x,i});
            } else {
                if (x <= dq.front().f) {
                    dq.push_front({x,i});
                } else {
                    if (x >= dq.back().f) {
                        dq.push_back({x,i});
                    } else {
                        int small, big;
                        small = st.order_of_key({x, -1});
                        big = st.size() - small;
                        if (small <= big) dq.push_front({x,i});
                        else dq.push_back({x,i});
                    }
                }
            }
            st.insert({x, i});
        }
        while (!dq.empty()) {
            st.erase(st.find({dq.front().f, dq.front().s}));
            ans += st.order_of_key({dq.front().f, -1});
            dq.pop_front();
        }
        cout << ans << endl;
    }
    return 0;
}