#include <bits/stdc++.h>
#ifdef DEBUG
#include <dbg.h>
#endif
using namespace std;

#define ll long long

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef pair<int, int> pi;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define ROF(i, a, b) for (int i = (b)-1; i >= a; i--)
#define each(a, x) for (auto &a : x)
#define eachMap(key, val, x) for (const auto &[key, val] : x)

#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()

#define nl cout << endl;
#define YES cout << "YES";
#define NO cout << "NO";

const int MOD = 1000000007;
int n;

struct SegTree
{

    vll tree;
    int treeSize;

    SegTree(vll input)
    {
        int height = log2(sz(input) - 1) + 1;
        treeSize = (int)pow(2, height);
        tree.resize(2 * treeSize, 0LL);

        build(input);
    }

    ll merge(int idx)
    {

        ll left = tree[2 * idx];
        ll right = tree[2 * idx + 1];

        return __gcd(left, right);
    }

    void build(vll input)
    {

        for (int i = 0; i < input.size(); i++)
        {
            tree[treeSize + i] = input[i];
        }

        for (int i = treeSize - 1; i > 0; i--)
        {
            tree[i] = merge(i);
        }
    }

    ll query(int l, int r, int leftbound, int rightbound, int idx)
    {
        // dbg(l, r, leftbound, rightbound, idx);
        if (l > r)
            return 0;
        if (l == leftbound && r == rightbound)
            return tree[idx];

        int mid = (leftbound + rightbound) / 2;
        return __gcd(query(l, min(r, mid), leftbound, mid, 2 * idx), query(max(l, mid + 1), r, mid + 1, rightbound, 2 * idx + 1));
    }

    void update(int idx, int newVal)
    {
        tree[treeSize + idx] = newVal;
        int parentIdx = (treeSize / 2 + idx) / 2;

        while (parentIdx >= 1)
        {
            merge(parentIdx);
            parentIdx /= 2;
        }
    }
};

void solve()
{
    cin >> n;
    vll a(n);
    vll d(n - 1);

    FOR(i, 0, n)
    cin >> a[i];

    FOR(i, 1, n)
    {
        d[i - 1] = abs(a[i] - a[i - 1]);
    }

    int ans = 1;
    if (n == 1)
    {
        ans = 1;
    }
    else if (n == 2)
    {
        if (__gcd(a[0], a[1]) > 1)
            ans = 2;
    }
    else
    {
        FOR(i, 0, d.size()){
            if(d[i] > 1) ans = 2;
        } 
        SegTree seg(d);

        // dbg(d);
        // dbg(seg.query(2, 2, 0, seg.treeSize - 1, 1));
        // dbg(seg.treeSize);
        // each(el, seg.tree) dbg(el);

        int l = 0, r = 0;

        while (r < d.size() && l < d.size())
        {
            // if (l == r)
            // {
            //     if (d[l] != 1)
            //         ans = max(ans, 2);
            //     r++;
            //     continue;
            // }

            ll qans = seg.query(l, r, 0, seg.treeSize - 1, 1);

            // dbg(l, r, qans);

            // return;

            if (qans > 1)
            {
                ans = max(ans, r - l + 2);
                r++;
            }
            else
            {
                if (l == r)
                {
                    r++;
                }

                l++;
            }
        }
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        //cout << "Case #" << tc << ": ";
        solve();

        cout << '\n';
    }
}
