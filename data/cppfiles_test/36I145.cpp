#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define MOD2 998244353
#define test         \
    int t;           \
    scanf("%d", &t); \
    while (t--)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, a, b) for (int i = a; i < b; ++i)
#define loope(i, a, b) for (int i = a; i <= b; ++i)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define loops(i, a, b, step) for (int i = a; i < b; i += step)
#define loopes(i, a, b, step) for (int i = a; i <= b; i += step)
#define looprs(i, a, b, step) for (int i = a; i >= b; i -= step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
#define FILE_READ_IN freopen("input.txt", "r", stdin);
#define FILE_READ_OUT freopen("output.txt", "w", stdout);
#define all(a) a.begin(), a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
    os << "[ ";
    for (auto v : V) os << v << " ";
    return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> S) {
    os << "{ ";
    for (auto s : S) os << s << " ";
    return os << "}";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
    os << "{ ";
    for (auto m : M) os << "(" << m.F << ":" << m.S << ") ";
    return os << "}";
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

template <typename T>
T lcm(T a, T b) {
    return (a * (b / gcd(a, b)));
}

long long powModM(long long a, long long b, long long m = MOD) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

vector<int> sieve(int n) {
    vector<int> prime;
    vector<bool> isComposite(n + 1, false);
    for (int i = 2; i < n; ++i) {
        if (!isComposite[i]) {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= n; ++j) {
            isComposite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return prime;
}

vector<int> mobius(int n) {
    vector<int> prime;
    vector<int> mu(n + 1);
    vector<bool> isComposite(n + 1, false);
    mu[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!isComposite[i]) {
            prime.push_back(i);
            mu[i] = -1;
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= n; ++j) {
            isComposite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = mu[i] * mu[prime[j]];
            }
        }
    }
    return mu;
}

vector<int> totient(int n) {
    vector<int> prime;
    vector<int> phi(n + 1);
    vector<bool> isComposite(n + 1, false);
    phi[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!isComposite[i]) {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= n; ++j) {
            isComposite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    return phi;
}

signed main() {
    test {
        int n;
        scanf("%d", &n);
        if (n < 27) {
            loop(i, 0, n) {
                printf("%c", 'a' + i);
            }
            printf("\n");
        } else {
            int r = n / 2;
            int l = r - 1;
            int m = n - l - r;
            loop(i, 0, l) {
                printf("a");
            }
            loop(i, 0, m) {
                printf("%c", 'b' + i);
            }
            loop(i, 0, r) {
                printf("%c", 'a' + i);
            }
            printf("\n");
        }
    }
    return 0;
}