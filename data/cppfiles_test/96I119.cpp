//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("vpt")
//#pragma GCC optimize("rename-registers")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("function-sections")
//#pragma GCC optimize("data-sections")
//#pragma GCC optimize("branch-target-load-optimize")
//#pragma GCC optimize("branch-target-load-optimize2")
//#pragma GCC optimize("btr-bb-exclusive")
//#pragma GCC optimize("inline")
//#pragma GCC optimize("-fgcse")
//#pragma GCC optimize("-fgcse-lm")
//#pragma GCC optimize("-fipa-sra")
//#pragma GCC optimize("-ftree-pre")
//#pragma GCC optimize("-ftree-vrp")
//#pragma GCC optimize("-fpeephole2")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("-fsched-spec")
//#pragma GCC optimize("-falign-jumps")
//#pragma GCC optimize("-falign-loops")
//#pragma GCC optimize("-falign-labels")
//#pragma GCC optimize("-fdevirtualize")
//#pragma GCC optimize("-fcaller-saves")
//#pragma GCC optimize("-fcrossjumping")
//#pragma GCC optimize("-fthread-jumps")
//#pragma GCC optimize("-freorder-blocks")
//#pragma GCC optimize("-fschedule-insns")
//#pragma GCC optimize("inline-functions")
//#pragma GCC optimize("-ftree-tail-merge")
//#pragma GCC optimize("-fschedule-insns2")
//#pragma GCC optimize("-fstrict-aliasing")
//#pragma GCC optimize("-falign-functions")
//#pragma GCC optimize("-fcse-follow-jumps")
//#pragma GCC optimize("-fsched-interblock")
//#pragma GCC optimize("-fpartial-inlining")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("-freorder-functions")
//#pragma GCC optimize("-findirect-inlining")
//#pragma GCC optimize("-fhoist-adjacent-loads")
//#pragma GCC optimize("-frerun-cse-after-loop")
//#pragma GCC optimize("inline-small-functions")
//#pragma GCC optimize("-finline-small-functions")
//#pragma GCC optimize("-ftree-switch-conversion")
//#pragma GCC optimize("-foptimize-sibling-calls")
//#pragma GCC optimize("-fexpensive-optimizations")
//#pragma GCC optimize("inline-functions-called-once")
//#pragma GCC optimize("-fdelete-null-pointer-checks")
//#define INTER

#include <bits/stdc++.h>
// Common file
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>

//using namespace __gnu_pbds;

//----------------------------------------------------------------
typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

std::random_device rd;
std::mt19937 randomizer(rd());
const int kInf = 0x3f3f3f3f;
const ll kInfLl = 0x3f3f3f3f3f3f3f3f;

//----------------------------------------------------------------
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fast_io std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0), std::cerr.tie(0);
#define debug(x) std::cerr << #x << ": " << (x) << '\n'
#define PROBLEM "el problema"
#define mp std::make_pair

template<typename T, typename T1>
inline bool mx(T &a, T1 b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T, typename T1>
inline bool mn(T &a, T1 b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
//----------------------------------------------------------------

const int kMaxN = 2e5;
//const int kMaxN = 5;

struct node {
    int l, r;
    int leftElement, rightElement;
    int maxPref, maxSuf;
    ll ans;

    node() : l(-1), r(-1), leftElement(-kInf), rightElement(kInf), maxPref(0), maxSuf(0) {}

    node(int l, int r) : l(l), r(r), leftElement(-kInf), rightElement(kInf), maxPref(0), maxSuf(0), ans(0) {}

    node(int l, int r, int le, int re, int mp1, int ms) : l(l), r(r), leftElement(le), rightElement(re), maxPref(mp1),
                                                          maxSuf(ms), ans(0) {}

    node operator+(const node &n) const {
        if (n.l == n.r && n.l == -1) return *this;
        if (l == r && l == -1) return n;
        node res;
        res.l = l, res.r = n.r;
        res.ans = ans + n.ans;
        res.leftElement = leftElement, res.rightElement = n.rightElement;
        if (rightElement <= n.leftElement) {
            res.ans += maxSuf * n.maxPref;
            res.maxPref = maxPref, res.maxSuf = n.maxSuf;
            if (maxPref == r - l + 1) res.maxPref += n.maxPref, res.maxSuf += maxSuf;
        } else { // rightElement > n.leftElement
            res.maxPref = maxPref, res.maxSuf = n.maxSuf;
        }
        return res;
    }
};

node tree[4 * kMaxN];

void build(int v, int l, int r, int *a) {
    if (l == r) {
        tree[v] = node(l, l, a[l], a[l], 1, 1);
        tree[v].ans = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid, a);
    build(2 * v + 1, mid + 1, r, a);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

void upd(int v, int x, int val) {
    if (tree[v].l == tree[v].r) {
        tree[v].leftElement = tree[v].rightElement = val;
        return;
    }
    if (x <= tree[2 * v].r) upd(2 * v, x, val);
    else upd(2 * v + 1, x, val);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

node get(int v, int l, int r) {
    if (tree[v].r < l || r < tree[v].l) {
        return {};
    }
    if (l <= tree[v].l && tree[v].r <= r) {
        return tree[v];
    }
    return get(2 * v, l, r) + get(2 * v + 1, l, r);
}

int32_t main() {
#ifndef DEBUG
#ifndef INTER
    // fast_io;
#endif
#endif

    std::cout << std::setprecision(15) << std::fixed;
    std::cerr << std::setprecision(15) << std::fixed;
    ld START_TIME = clock();

    int n, q;
    std::cin >> n >> q;
    int a[n];
    for (auto &i: a) std::cin >> i;
    build(1, 0, n - 1, a);
    while (q--) {
        int type, l, r;
        std::cin >> type >> l >> r;
        if (type == 1) {
            l--;
            upd(1, l, r);
        } else {
            l--, r--;
            std::cout << get(1, l, r).ans << '\n';
        }
    }

#ifdef DEBUG
    std::cerr << '\n';
    ld TIME = (clock() - START_TIME) / CLOCKS_PER_SEC;
    debug(TIME);
#endif
}
