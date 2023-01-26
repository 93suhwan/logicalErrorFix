#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define in insert
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define sqr(x) ((x) * (x))
#define pb push_back
#define fi first
#define se second
#define fr(i, l, r) for (int i = l; i <= r; ++i)
#define rf(i, r, l) for (int i = r; i >= l; --i)
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);
#define stop system("pause");
#define x1 fdffgahj
#define y1 fdffgga

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using sset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 2e5 + 10;
const int MXN = 6;
const int M = 1e3 + 10;
const int inf = 1e9 + 1;
const ll INF = 1e18 + 1e2;

template <typename T>
void vout(T x){
    cout << x << endl;
    exit(0);
}

class StringHashs {
public:
    StringHashs(string &s) {
        str = s;
        len = sz(s);
        hashs.resize(len, 0);
        powers.resize(len, 0);

        InitPowers();
        InitHashs();
    }

    void InitPowers() {
        powers[0] = 1;
        fr(i, 1, len - 1)
            powers[i] = Mul(powers[i - 1], p);
    }

    void InitHashs() {
        fr(i, 0, len - 1) {
            hashs[i] = Mul(to_int(str[i]), powers[i]);
            if (i)
                hashs[i] = Add(hashs[i], hashs[i - 1]);
        }
    }

    int to_int(char c) {
        return (c - 'a' + 1);
    }

    int Combine(int i, int j) {
        if (!CompareSuff(i, j))
            return 0;

        return (len - j) - GetLcp(i, j);
    }

    bool CompareSuff(int i, int j) {
        int lcp = GetLcp(i, j);
        int len1 = len - i;
        int len2 = len - j;

        if (lcp == len1 || lcp == len2)
            return (len1 < len2);

        return (str[i + lcp] < str[j + lcp]);
    }

    int GetLcp(int i, int j) {
        auto check = [&](int mid) -> bool {
            int l1 = i, r1 = i + mid - 1;
            int l2 = j, r2 = j + mid - 1;
            int deltaP = powers[abs(l1 - l2)];
            int hash1 = GetHash(l1, r1);
            int hash2 = GetHash(l2, r2);

            if (l1 < l2) hash1 = Mul(hash1, deltaP);
            else hash2 = Mul(hash2, deltaP);

            return (hash1 == hash2);
        };

        int l = 0;
        int r = min(len - i, len - j);
        while(abs(r - l) > 1) {
            int mid = (l + r) >> 1;

            if (check(mid)) l = mid;
            else r = mid;
        }

        int res = 0;
        if (check(r)) res = r;
        else res = l;

        return res;
    }

    int GetHash(int l, int r) {
        if (l > r) return 0;
        return Sub(hashs[r], (l? hashs[l - 1] : 0));
    }

    int Add(int a, int b) {
        return (a + b) % mod;
    }

    int Mul(int a, int b) {
        return 1LL * a * b;
    }

    int Sub(int a, int b) {
        int res = a - b;
        while(res < 0) res += mod;
        return res % mod;
    }
private:
    string str;
    vector<int> hashs;
    vector<int> powers;
    int len;
    const int p = 31;
    const int mod = 1e9 + 7;
};

int main() {
    fast_io

    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        StringHashs sh(s);

        vector<int> dp(n);
        vector<int> p(n, -1);

        // dp
        fr(i, 0, n - 1) {
            dp[i] = n - i;
            fr(j, 0, i - 1) {
                int add = sh.Combine(j, i);
                if (add > 0 && dp[i] < dp[j] + add) {
                    dp[i] = dp[j] + add;
                    p[i] = j;
                }
            }
        }

        // find ans
        int mxi = 0;
        fr(i, 0, n - 1) {
            if (dp[mxi] < dp[i])
                mxi = i;
        }

        cout << dp[mxi] << "\n";
    }

    return 0;
}
