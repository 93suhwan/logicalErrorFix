#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long pow2(long long a, long long b, long long m) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a) % m;
    }
    a = (a * a) % m;
    b >>= 1;
  }
  ans = (ans + m) % m;
  return ans;
}
long long pow2(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a);
    }
    a = (a * a);
    b >>= 1;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> pos(1024, INT_MAX);
  pos[0] = 0;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    for (long long j = 0; j < 1024; j++) {
      if (pos[j] < a) pos[j ^ a] = min(pos[j ^ a], a);
    }
  }
  vector<long long> v;
  for (long long i = 0; i < 1024; i++) {
    if (pos[i] != INT_MAX) v.push_back(i);
  }
  cout << v.size() << "\n";
  for (auto x : v) cout << x << " ";
  cout << "\n";
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
