#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <numeric>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 1e6 + 6;
const long long MOD = 1e9 + 7;
long long fact[N], dp[3 * N];
int n;
long long pow_mod(long long a, int b) {
    if (b == 0)
        return 1;
    else
        return ((b % 2) * (a - 1) + 1) * pow_mod(a * a % MOD, b / 2) % MOD;
}
long long C(int m, int k) {
    if (k < 0 || k > m)
        return 0;
    return fact[m] * pow_mod(fact[m - k] * fact[k] % MOD, MOD - 2) % MOD;
}
long long solve(int x) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans + C(3 * i, x)) % MOD;
    return ans;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> n >> t;
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    for (int i = 1; i < 3; ++i)
        dp[i] = solve(i);
    for (int i = 3; i <= 3 * n; ++i)
        dp[i] = (C(3 * (n + 1), i + 1) - 3 * dp[i - 1] - dp[i - 2] + 5 * MOD) % MOD * (2 * MOD + 1) / 3 % MOD;
    while (t--) {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }
    return 0;
}