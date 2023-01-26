#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
bool is_prime[N];
vector<int> primes;
bool vp[N];
bool g(int p, int n) {
  int ans = 0;
  int u = p;
  while (u <= n) {
    ans += n / u;
    u *= p;
  }
  return ans & 1;
}
bool f(int p, int n) {
  if (!n) return 0;
  if (n & 1) return g(p, n) ^ f(p, n - 1);
  int ans = 0;
  int u = (p == 2 ? p : 2 * p);
  while (u <= n) {
    ans += n / u;
    u *= p;
  }
  return ans & 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < N; i++) {
    is_prime[i] = 1;
  }
  for (int i = 2; i < N; i++) {
    if (is_prime[i]) primes.push_back(i);
    for (int j = 2 * i; j < N; j += i) {
      is_prime[j] = 0;
    }
  }
  int n;
  cin >> n;
  if (n < 4) {
    cout << "1\n1\n";
    return 0;
  }
  int m = 4 * (n / 4);
  if (n == m) {
    cout << m - 1 << endl;
    for (int i = 1; i <= m; i++) {
      if (i != m / 2) cout << i << ' ';
    }
    cout << endl;
    return 0;
  }
  if (n == m + 1) {
    for (int i = 1; i < n; i++) {
      if (i == m / 2) continue;
      bool good = 1;
      for (int p : primes) {
        if (g(p, i) != (g(p, m / 2) != g(p, n))) {
          good = 0;
          break;
        }
      }
      if (good) {
        cout << n - 1 << endl;
        for (int j = 1; j <= n; j++) {
          if (j != i) cout << j << ' ';
        }
        cout << endl;
        return 0;
      }
    }
    cout << m - 1 << endl;
    for (int i = 1; i <= m; i++) {
      if (i != m / 2) cout << i << ' ';
    }
    cout << endl;
    return 0;
  }
  if (n == m + 2) {
    for (int i = 1; i <= n; i++) {
      if (i == 2 || i == n / 2) continue;
      bool good = 1;
      for (int p : primes) {
        if (g(p, i) != (g(p, 2) != g(p, n / 2))) {
          good = 0;
          break;
        }
      }
      if (good) {
        cout << n - 1 << endl;
        for (int j = 1; j <= n; j++) {
          if (j != i) cout << j << ' ';
        }
        cout << endl;
        return 0;
      }
    }
    cout << m << endl;
    for (int i = 1; i <= n; i++) {
      if (i != 2 && i != n / 2) cout << i << ' ';
    }
    cout << endl;
    return 0;
  }
  if (n == m + 3) {
    for (int i = 1; i <= n; i++) {
      bool good = 1;
      for (int p : primes) {
        if (g(p, i) != f(p, n)) {
          good = 0;
          break;
        }
      }
      if (good) {
        cout << n - 1 << endl;
        for (int j = 1; j <= n; j++) {
          if (j != i) cout << j << ' ';
        }
        cout << endl;
        return 0;
      }
    }
    vector<int> extras = {2, n / 2, n};
    for (int x : extras) {
      for (int y : extras) {
        if (x >= y) continue;
        for (int i = 1; i <= n; i++) {
          if (i == x || i == y) continue;
          bool good = 1;
          for (int p : primes) {
            if (g(p, i) != (g(p, x) != g(p, y))) {
              good = 0;
              break;
            }
          }
          if (good) {
            int z;
            for (int t : extras) {
              if (t != x && t != y) t = z;
            }
            cout << n - 2 << endl;
            for (int j = 1; j <= n; j++) {
              if (j != i && j != z) cout << j << ' ';
            }
            cout << endl;
            return 0;
          }
        }
      }
    }
    vector<int> P(primes.begin(), primes.begin() + 32);
    unordered_map<int, vector<int>> m;
    int tot = 0;
    for (int j = 0; j < 32; j++) {
      if (f(P[j], n)) tot ^= (1 << j);
    }
    for (int x = 1; x <= n; x++) {
      int h = 0;
      for (int j = 0; j < 32; j++) {
        if (g(P[j], x)) h ^= (1 << j);
      }
      if (m.count(h ^ tot)) {
        for (int y : m[h ^ tot]) {
          bool good = 1;
          for (int p : primes) {
            if (f(p, n) != (g(p, x) != g(p, y))) {
              good = 0;
              break;
            }
          }
          if (good) {
            cout << n - 2 << endl;
            for (int j = 1; j <= n; j++) {
              if (j != x && j != y) cout << j << ' ';
            }
            cout << endl;
            return 0;
          }
        }
      }
      m[h].push_back(x);
    }
    cout << n - 3 << endl;
    for (int i = 1; i < n; i++) {
      if (i != 2 && i != n / 2) cout << i << ' ';
    }
    cout << endl;
    return 0;
  }
  assert(0);
}
