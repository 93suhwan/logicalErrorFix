#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <deque>
#include <array>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("avx512f,avx512dq,avx512cd,avx512bw,avx512vl")

using ll = long long;
constexpr int INF = 1001001001;
// constexpr int mod = 1000000007;
constexpr int mod = 998244353;

template<class T>
inline bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)  cin >> a[i];
    sort(rbegin(a), rend(a));
    double ans = a[0];
    ans += accumulate(begin(a) + 1, end(a), 0LL) / (double)(n - 1);
    cout << fixed << setprecision(15);
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--)  solve();

    return 0;
}