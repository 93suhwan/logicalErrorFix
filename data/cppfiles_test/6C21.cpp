#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _do(vector<T> x) {
  for (auto i : x) cerr << i << ' ';
  cerr << "\n";
}
template <typename T>
void _do(set<T> x) {
  for (auto i : x) cerr << i << ' ';
  cerr << "\n";
}
template <typename T>
void _do(unordered_set<T> x) {
  for (auto i : x) cerr << i << ' ';
  cerr << "\n";
}
template <typename T>
void _do(T&& x) {
  cerr << x << endl;
}
template <typename T, typename... S>
void _do(T&& x, S&&... y) {
  cerr << x << ", ";
  _do(y...);
}
template <typename T>
void print(T&& x) {
  cout << x << "\n";
}
template <typename T, typename... S>
void print(T&& x, S&&... y) {
  cout << x << ' ';
  print(y...);
}
void solve() {
  const int M = 1e5 + 1, MOD = 1e9 + 7;
  vector<int> phi(M);
  vector<int> primes;
  phi[1] = 1;
  for (int i = 2; i < M; i++) {
    if (phi[i] == 0) {
      primes.push_back(i);
      phi[i] = i - 1;
    }
    for (int p : primes) {
      if (i * p >= M) break;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        break;
      }
      phi[i * p] = 1LL * phi[i] * (p - 1) % MOD;
    }
  }
  vector<vector<int>> factors(M);
  for (int i = 1; i < M; i++)
    for (int j = i; j < M; j += i) factors[j].push_back(i);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> cnt(M);
  int ans = 0;
  for (int T = 1; T <= n; T++) {
    int G = 0;
    vector<int> vec;
    for (int i = T; i <= n; i += T)
      for (int p : factors[a[i]])
        if (cnt[p]++ == 0) vec.push_back(p);
    for (int p : vec) G = (G + 1LL * phi[p] * cnt[p] % MOD * cnt[p]) % MOD;
    for (int i = T; i <= n; i += T)
      for (int p : factors[a[i]]) cnt[p]--;
    ans = (ans + 1LL * G * phi[T]) % MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << endl;
}
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
