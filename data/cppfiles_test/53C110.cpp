#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
vector<bool> prime(MX, true);
void SieveOfEratosthenes() {
  for (int p = 2; p * p <= MX; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= MX; i += p) prime[i] = false;
    }
  }
  prime[1] = false;
}
void solve() {
  int n;
  char a;
  cin >> n >> a;
  string second;
  cin >> second;
  vector<int> v;
  bool flag = 1;
  for (int i = 0; i < n; i++) {
    if (second[i] != a) {
      flag = 0;
    }
  }
  if (flag) {
    cout << 0 << nl;
    return;
  }
  vector<int> p;
  for (int i = n / 2; i < n; i++) {
    if (second[i] == a) p.push_back(i);
  }
  if (!p.empty()) {
    cout << 1 << nl;
    cout << p[0] + 1 << nl;
  } else {
    cout << 2 << nl;
    cout << n - 1 << " " << n << nl;
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  SieveOfEratosthenes();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
