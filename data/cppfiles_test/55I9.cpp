#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
#define null NULL
#define umap unordered_map
#define len(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define inrange(val, start, end) (val >= start && val <= end)
const double PI = 2 * acos(0.0);

const int iinf = 0x3f3f3f3f;
const ll inf = 1e18;
const ll mod = 1e9 + 7;

#define var(args...)                           \
    {                                          \
        string _s = #args;                     \
        stringstream _ss;                      \
        string ccurr = "";                     \
        for (int zz = 0; zz < len(_s); zz++) { \
            if (_s[zz] == ' ') continue;       \
            if (_s[zz] == ',') {               \
                _ss << ' ' + ccurr;            \
                ccurr = "";                    \
            } else                             \
                ccurr += _s[zz];               \
        }                                      \
        _ss << ' ' + ccurr;                    \
        istream_iterator<string> _it(_ss);     \
        vars(_it, args);                       \
    }
#define debugDecimal(d) cerr << setprecision(d) << fixed

void vars(istream_iterator<string> it) { cerr << '\n'; }
template <typename T, typename... Args>
void vars(istream_iterator<string> it, T a, Args... args) {
    cerr << " [" << *it << ": " << a << "] ";
    vars(++it, args...);
}

#define printVerdict(verdict) \
    cout << (verdict ? "YES" : "NO") << '\n'
#define printDecimal(d) \
    cout << setprecision(d) << fixed
#define printCase(_) \
    cout << "Case #" << (_) << ": "

template <class T1, class T2, class T3>
void printTuple(const tuple<T1, T2, T3> &t) { cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n'; }
template <class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) { return out << p.first << " " << p.second; }
template <class T>
ostream &operator<<(ostream &out, const vector<T> &arr) {
    for (const T &a : arr) out << a << " ";
    return out;
}
template <class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &grid) {
    for (const vector<T> &row : grid) out << row << '\n';
    return out;
}
template <class T>
istream &operator>>(istream &in, vector<T> &arr) {
    for (T &a : arr) in >> a;
    return in;
}
template <class T>
void readIdx(vector<pair<T, int>> &a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
}
template <class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
    in >> a.first >> a.second;
    return in;
}

const bool PRINT_EXEC_TIME = true;
const bool EXTERNAL_INPUT = false;
const bool EXTERNAL_OUTPUT = false;

const char *INPUT_FILE = "input.txt";
const char *OUTPUT_FILE = "output.txt";

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) std::begin(x), std::end(x)

struct SegmentTree {
    static constexpr pair<ll, ll> base = {0, -1};

    int arr_size;
    vector<pair<ll, ll>> tree, lazy;
    SegmentTree(int n) {
        arr_size = n;
        int tree_size = 1;
        while (tree_size < n) tree_size *= 2;
        tree.assign(2 * tree_size + 1, base);
        lazy.assign(2 * tree_size + 1, base);
    }

    void propagate(int idx, int curr_l, int curr_r) {
        if (lazy[idx] != base) {
            tree[idx] = max(tree[idx], lazy[idx]);
            if (curr_l != curr_r) {
                lazy[idx * 2 + 1] = max(lazy[2 * idx + 1], lazy[idx]);
                lazy[idx * 2 + 2] = max(lazy[2 * idx + 2], lazy[idx]);
            }
            lazy[idx] = base;
        }
    }

    void update(int idx, int curr_l, int curr_r, int l, int r, pair<ll, ll> p) {
        if (curr_l > curr_r) return;
        propagate(idx, curr_l, curr_r);
        if (r < curr_l || curr_r < l) return;
        if (inrange(curr_l, l, r) && inrange(curr_r, l, r)) {
            lazy[idx] = max(lazy[idx], p);
            propagate(idx, curr_l, curr_r);
            return;
        }
        int mid = curr_l + (curr_r - curr_l) / 2;
        update(idx * 2 + 1, curr_l, mid, l, r, p);
        update(idx * 2 + 2, mid + 1, curr_r, l, r, p);
        tree[idx] = max(tree[idx * 2 + 2], tree[idx * 2 + 1]);
    }

    pair<ll, ll> query(int idx, int curr_l, int curr_r, int l, int r) {
        if (curr_l > curr_r) return base;
        propagate(idx, curr_l, curr_r);
        if (r < curr_l || curr_r < l) return base;
        if (inrange(curr_l, l, r) && inrange(curr_r, l, r)) {
            return tree[idx];
        }
        int mid = curr_l + (curr_r - curr_l) / 2;
        pair<ll, ll> left = query(idx * 2 + 1, curr_l, mid, l, r);
        pair<ll, ll> right = query(idx * 2 + 2, mid + 1, curr_r, l, r);
        return max(left, right);
    }

    void update(int l, int r, pair<ll, ll> p) {
        update(0, 0, arr_size - 1, l, r, p);
    }

    pair<ll, ll> query(int l, int r) {
        return query(0, 0, arr_size - 1, l, r);
    }
};

void prayGod() {
    int n, m;
    cin >> n >> m;

    set<int> seen;
    map<int, int> f;

    vector<vector<pair<int, int>>> rows(n);

    for (int i = 0; i < m; i++) {
        int curr_row, l, r;
        cin >> curr_row >> l >> r;
        seen.insert(l);
        seen.insert(r);
        rows[--curr_row].push_back(make_pair(l, r));
    }

    function<int()> create_mapping = [&]() {
        int idx = 0;
        for (int val : seen) {
            f[val] = idx++;
        }
        return idx;
    };

    int mapping_sz = create_mapping();

    SegmentTree tree(mapping_sz);

    vector<int> dp(n, 0);
    vector<int> backtrack(n, -1);

    for (int i = 0; i < n; i++) {
        sort(rows[i].begin(), rows[i].end());
        vector<pair<int, int>> merged;

        for (pair<int, int> p : rows[i]) {
            p.first = f[p.first];
            p.second = f[p.second];
            if (merged.empty() || p.first > merged.back().second) {
                merged.push_back(p);
            } else {
                merged.back().second = max(merged.back().second, p.second);
            }
        }

        rows[i] = merged;
    }

    for (pair<int, int> p : rows[0]) {
        tree.update(p.first, p.second, make_pair(0, 0));
    }

    for (int i = 1; i < n; i++) {
        for (pair<int, int> p : rows[i]) {
            pair<ll, ll> ret = tree.query(p.first, p.second);
            if (dp[i] < ret.first + 1) {
                dp[i] = ret.first + 1;
                backtrack[i] = ret.second;
            }
        }

        for (pair<int, int> p : rows[i]) {
            tree.update(p.first, p.second, make_pair(dp[i], i));
        }
    }

    int best_idx = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<bool> used(n, false);

    function<void(int)> construct = [&](int idx) {
        if (backtrack[idx] != -1) construct(backtrack[idx]);
        used[idx] = true;
    };

    construct(best_idx);

    vector<int> ret;
    for (int i = 0; i < n; i++) {
        if (!used[i]) ret.push_back(i + 1);
    }

    cout << len(ret) << '\n'
         << ret << '\n';
}

int main() {
    clock_t start = clock();

    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    if (EXTERNAL_INPUT)
        freopen(INPUT_FILE, "r", stdin);
    if (EXTERNAL_OUTPUT)
        freopen(OUTPUT_FILE, "w", stdout);

    prayGod();

    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    if (PRINT_EXEC_TIME)
        debugDecimal(5) << time_taken << " s" << '\n';
}