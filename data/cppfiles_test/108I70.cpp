#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template<class myType>
auto ordered_set() {
    return tree<myType, null_type, std::less<myType>, rb_tree_tag, tree_order_statistics_node_update>();
}


#define ll long long
#define ld long double
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
using namespace std;
const int N = 5e5 + 9, mod = 998244353;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int> x(n), y(n), x2(n), y2(n);
        vector<pair<int, int> > a, b;
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            a.push_back({v, i});
        }
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            b.push_back({v, i});
        }
        sort(all(a));
        sort(all(b));
        for (int i = 0; i < n; ++i) {
            x[i] = a[i].second;
            y2[a[i].second] = i;
            x2[i] = b[i].second;
            y[b[i].second] = i;
        }
        vector<int> mn(n), mn2(n);
        mn.back() = y[x.back()];
        for (int i = n - 2; i >= 0; --i) {
            mn[i] = min(mn[i + 1], y[x[i]]);
        }
        mn2.back() = y2[x2.back()];
        for (int i = n - 2; i >= 0; --i) {
            mn2[i] = min(mn2[i + 1], y2[x2[i]]);
        }
        int mx = n - 1, my = n - 1, pvx = -1, pvy = -1;
        while (mx != pvx || my != pvy) {
            pvx = mx;
            pvy = my;
            mx = mn2[my];
            my = mn[mx];
        }
        while (x.size() > mx)x.pop_back();
        while (y.size() > my)y.pop_back();
        set<int> st;
        string s(n, '1');
        for (int i = 0; i < x.size(); ++i) {
            st.insert(x[i]);
        }
        for (int i = 0; i < y.size(); ++i) {
            if (st.count(y[i]))s[y[i]] = '0';
        }
        cout << s << "\n";

    }

    return 0;
}