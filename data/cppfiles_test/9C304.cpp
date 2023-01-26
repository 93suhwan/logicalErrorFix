#include <bits/stdc++.h>
using namespace std;
constexpr int Inf = 2000000000;
constexpr long long INF = 2000000000000000000;
template <typename T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T, typename U>
T modpow(T N, U P, T M = -1) {
  if (P < 0) return 0;
  T ret = 1;
  if (M != -1) ret %= M;
  while (P) {
    if (P & 1) {
      if (M == -1)
        ret *= N;
      else
        ret = ret * N % M;
    }
    P /= 2;
    if (M == -1)
      N *= N;
    else
      N = N * N % M;
  }
  return ret;
}
long long MOD = 998244353;
int main() {
  int T;
  cin >> T;
  for (int tmp = 0; tmp < T; tmp++) {
    string S;
    cin >> S;
    vector<int> count(26);
    for (auto& x : S) {
      count[x - 'a']++;
    }
    int ret = 0;
    for (auto& x : count) {
      if (x == 1)
        ret++;
      else if (x >= 2)
        ret += 2;
    }
    cout << ret / 2 << endl;
  }
}
