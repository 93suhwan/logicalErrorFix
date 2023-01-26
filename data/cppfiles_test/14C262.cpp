#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
long long be(long long a, long long b, long long c) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a;
      res = res % c;
    }
    a = a * a;
    a = a % c;
    b >>= 1;
  }
  return res;
}
vector<int> sieve(int n) {
  vector<int> primes;
  vector<bool> check(n + 1, true);
  for (int i = 2; i <= n; i++) {
    if (check[i]) {
      primes.push_back(i);
      for (int j = (i * i); j <= n; j += i) {
        check[j] = false;
      }
    }
  }
  return primes;
}
long long fact(int n) {
  long long res = 1;
  for (int i = 2; i <= n; i++) {
    res = res * i;
  }
  return res;
}
long long nCr(int n, int r) {
  long long res;
  res = fact(n) / (fact(n - r) * fact(r));
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<pair<int, int> > a;
  for (int &x : v) {
    cin >> x;
  }
  for (int i = 0; i < n - 1; i++) {
    int min_pos = i;
    for (int j = i + 1; j < n; j++) {
      if (v[j] < v[min_pos]) {
        min_pos = j;
      }
    }
    if (min_pos > i) {
      a.push_back({i, min_pos});
      int opt = v[min_pos];
      for (int k = min_pos; k > i; k--) {
        v[k] = v[k - 1];
      }
      v[i] = opt;
    }
  }
  cout << a.size() << "\n";
  for (auto &l : a) {
    cout << l.first + 1 << " " << l.second + 1 << " " << l.second - l.first
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
