#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T>
void print(vector<T> &arr) {
//    cout << sz(arr) << '\n';
    for (T x : arr) cout << x << ' ';
//    cout << '\n';
}

void ask(vi &arr) {
    cout << '?';
    for (int i = 0; i < sz(arr); ++i) {
        cout << ' ' << arr[i];
    }
    cout << endl;
}

void run() {
    int n; cin >> n;
    vi arr(n, n);
    vi p(n);
    for (int i = 1; i <= n; ++i) {
        arr.back() = i;
        ask(arr);
        int k; cin >> k;
        if (k != 0) {
            p.back() = n + 1 - i;
            p[k - 1] = 1;
            break;
        }
    }
    if (p.back() == 0) {
        p.back() = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i <= p.back()) arr[j] = n;
            else arr[j] = 1;
        }
        if (i == p.back()) continue;
        arr.back() = n + i - p.back();
        ask(arr);
        int k; cin >> k;
        p[k - 1] = i;
    }
    cout << '!';
    for (int i = 0; i < n; ++i) {
        cout << ' ' << p[i];
    }
    cout << '\n';
}


int main() {
#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    //    freopen("points.in", "r", stdin);
    //    freopen("outofplace.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int T = 1;
//    cin >> T;
    for (int t = 1; t <= T; ++t) {
//        cout << "Case #" << t << ": ";
        run();
//        if (t < T) cout << '\n';
    }

    return 0;
}