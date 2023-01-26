#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

#define pr pair<int,int>
#define ll long long
#define all(v) v.begin(),v.end()
#define loop(i, n) for(int (i)=0 ; (i)<(n) ; (i)++)
#define rep(i, x, y) for(int (i)=(x) ; (i)<=(y) ; (i)++)
typedef tree<
        int,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        os;
const int N = 5e5 + 5, MOD = 1e9 + 7, INF = 1e9;
vector<pr > goTo[N];

int binary(int x, int i) {
    int st = 0, en = (int) goTo[x].size() - 1;
    while (st <= en) {
        int mid = (st + en) / 2;
        if (goTo[x][mid].second > i) {
            en = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return en + 1;
}

int getNumber(int x, int i) {
    int ind = binary(x, i);
    if (ind >= goTo[x].size() or goTo[x][ind].first == x)return x;
    return goTo[x][ind].first = getNumber(goTo[x][ind].first, goTo[x][ind].second);
}

void solve() {
    vector<pr> nums;
    int q;
    cin >> q;
    loop(i, q) {
        int qt, x, y;
        cin >> qt;
        if (qt == 1) {
            cin >> x;
            nums.emplace_back(x,i);
        } else {
            cin >> x >> y;
            goTo[x].emplace_back(y,i);
        }
    }
    for (auto & num : nums) {
        cout << getNumber(num.first, num.second) << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //  freopen("out.csv", "w", stdout);
#endif
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}