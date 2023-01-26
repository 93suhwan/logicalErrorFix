#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<typename key>
using ordered_set = tree<key, null_type, less<key>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[]{0, 1, 1, 1, 0, -1, -1, -1};

void run() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#else
#endif
}

template<typename T>
struct sparse_table {
    vector<vector<T>> sparseTable;

    static int LOG2(int x) {
        return 31 - __builtin_clz(x);
    }

    sparse_table(vector<T> &v) {
        int n = v.size();
        int logN = LOG2(n);
        sparseTable = vector<vector<T >>(logN + 1);
        sparseTable[0] = v;
        for (int k = 1, len = 1; k <= logN; k++, len <<= 1) {
            sparseTable[k].resize(n);
            for (int i = 0; i + len < n; i++)
                sparseTable[k][i] = min(sparseTable[k - 1][i],
                                        sparseTable[k - 1][i + len]);
        }
    }

    T query(int l, int r) {
        int k = LOG2(r - l + 1);
        return min(sparseTable[k][l], sparseTable[k][r - (1 << k) + 1]);
    }
};

const int N = 1e6 + 9;
int lpf[N + 1];
vector<int> prime;

void sieve() {
    for (int i = 2; i <= N; i++) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            prime.push_back(i);
        }
        for (int j: prime) {
            if (j > lpf[i] || 1LL * i * j > N)break;
            lpf[i * j] = j;
        }
    }
}

vector<int> lastL;
vector<int> brackets[N];

void add(int val, int idx) {
    while (val > 1) {
        int p = lpf[val];
        while (val % p == 0) {
            brackets[p].push_back(idx);
            val /= p;
        }
    }
}

void remove(int val, int idx) {
    while (val > 1) {
        int p = lpf[val];
        while (val % p == 0) {
            if (brackets[p].empty()) {
                lastL[idx] = 0;
                return;
            }
            lastL[idx] = min(lastL[idx], brackets[p].back());
            brackets[p].pop_back();
        }
    }
}

int main() {
    run();
    sieve();
    int n;
    cin >> n;
    vector<int> v(n + 1);
    string s;
    for (int i = 1; i <= n; i++)cin >> v[i];
    cin >> s;
    s = "$" + s;
    lastL = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)lastL[i] = i;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '*')add(v[i], i);
        else remove(v[i], i);
    }
    sparse_table<int> sp(lastL);
    ll cnt = 0;
    for (int l = 1; l <= n; l++) {
        int st = l, ed = n, r = -1;
        while (st <= ed) {
            int md = st + ed >> 1;
            if (sp.query(l, md) >= l)
                st = md + 1, r = md;
            else ed = md - 1;
        }
        if (r >= l)
            cnt += (r - l + 1);
    }
    cout << cnt << endl;
}