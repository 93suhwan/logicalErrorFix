#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <stack>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

// Rust is good
using i64 = int64_t;
using u64 = uint64_t;
using pi64 = pair<i64, i64>;

constexpr array<string_view, 2> YN{"NO", "YES"};
constexpr i64 MAXN = 3 * 100 * 1000 + 5LL;
constexpr i64 MOD = 1000000007LL;
constexpr i64 INF64 = MOD * MOD;

#define vec vector
#define let const
// declare and read
#define DRi64(var) i64 var; cin >> var;
#define DRS(var) string var; cin >> var;
#define DRVi64(v, n) vec<i64> v(n); { for (i64 i = 0; i < n; ++i) { cin >> v[i]; }}
#define DRpi64(p) pi64 p; cin >> p.first >> p.second;
// don't even think about it
#define double doublee
#define float floatt

using adj_t = vec<vec<i64>>;
using grid_t = vec<string>;

#ifdef DEBUG
#define P(x) cerr << x << "\n"
#else
#define P(x)
#endif

ostream& operator<<(ostream& os, const pi64 p)
{ os << p.first << " " << p.second; return os; }
ostream& operator<<(ostream& os, const vec<i64>& v)
{ for (i64 i = 0; i < v.size(); ++i) { os << v[i] << " \n"[i + 1 == v.size()]; } return os; }

inline i64
ceildiv(const i64 a, const i64 b) { return (a + b - 1) / b; }

inline i64
sgn(const i64 x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }

bool
valid(const i64 N, const vec<i64>& A, const vec<i64>& B)
{
    i64 acc = 0;
    for (i64 i = 0; i < N; ++i)
    {
        acc += A[i] * B[i];
    }
    return acc == 0;
}

struct cmp_t
{
    bool operator()(const pi64 lhs, const pi64 rhs) const
    {
        let auto alhs = abs(lhs.first);
        let auto arhs = abs(rhs.first);
        if (alhs != arhs)
        {
            return alhs < arhs;
        }
        return lhs.second < rhs.second;
    }
};

vec<i64>
solve(const i64 N, const vec<i64>& A)
{
    vec<pi64> a_ix(N);
    for (i64 i = 0; i < N; ++i)
    {
        a_ix[i] = {A[i], i};
    }
    // sort by abs desc
    sort(a_ix.rbegin(), a_ix.rend(), cmp_t());

    vec<i64> B(N);
    i64 acc = 0;
    for (i64 i = 0; i + 1 < N; ++i)
    {
        // find the one that minimizes the resulting abs acc
        let vec<i64> possibilities = {
            abs(acc) / abs(a_ix[i].first),
            ceildiv(abs(acc), abs(a_ix[i].first)),
            -abs(acc) / abs(a_ix[i].first),
            -ceildiv(abs(acc), abs(a_ix[i].first)),
        };
        P("acc: " << acc);
        P(a_ix[i].first << ": " << possibilities);
        i64 best_j = -1;
        i64 best_abs = INF64;
        for (i64 j = 0; j < possibilities.size(); ++j)
        {
            if (possibilities[j] == 0)
            {
                continue;
            }
            let i64 cand = abs(acc + possibilities[j] * a_ix[i].first);
            if (cand == 0)
            {
                continue;
            }
            if (best_j < 0 || abs(acc + possibilities[best_j] * a_ix[i].first) > cand)
            {
                best_j = j;
            }
        }
        if (best_j < 0 || B[a_ix[i].second] == 0)
        {
            // be sure that acc != 0 here!!!
            B[a_ix[i].second] = acc + a_ix[i].first == 0 ? -1 : 1;
        }
        else if (best_j >= 0)
        {
            B[a_ix[i].second] = possibilities[best_j];
        }
        acc += B[a_ix[i].second] * a_ix[i].first;
        assert(acc != 0);
    }
    // handle last element
    let i64 L = lcm(abs(acc), abs(a_ix.back().first));
    let i64 mult_existing = L / acc;
    for (i64& b : B)
    {
        b *= mult_existing;
    }
    B[a_ix.back().second] = -(acc * mult_existing) / a_ix.back().first;

    assert(count(B.begin(), B.end(), 0) == 0);
    return B;
}

void
test()
{
    for (i64 t = 0; t < 10000; ++t)
    {
        let i64 N = (rand() % 2) + 2;
        vec<i64> A(N);
        for (i64& a : A)
        {
            a = (rand() % 10) - 21;
        }
        let vec<i64> ans(move(solve(N, A)));
        if (!valid(N, A, ans))
        {
            cout << N << "\n";
            cout << A;
            cout << "invalid! dot product != 0\n";
            cout << ans;
            return;
        }
        cout << "Test " << t + 1 << " passed\n";
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const unsigned seed =
        chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
#ifdef DEBUG
    test();
#endif

    DRi64(T);
    for (; T-->0;)
    {
        DRi64(N);
        DRVi64(A, N);
        cout << solve(N, A);
    }
    return 0;
}
