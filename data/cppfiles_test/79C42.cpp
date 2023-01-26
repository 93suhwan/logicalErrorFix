#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1E9 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int gcd_ex(long long int a, long long int b, long long int& x,
                     long long int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int g = gcd_ex(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}
long long int multi_mod_inv(long long int a, long long int m) {
  long long int x, y;
  long long int g = gcd_ex(a, m, x, y);
  if (g != 1) {
    return -1;
  }
  x = (x % m + m) % m;
  return x;
}
long long int mod_div(long long int a, long long int b, long long int m) {
  if (multi_mod_inv(b, m) != -1) {
    return (a % m * multi_mod_inv(b, m) % m) % m;
  } else {
    return -1;
  }
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
long long int power(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int p = power(a, n / 2);
  p = (p * p) % MOD;
  if (n % 2)
    return (p * a) % MOD;
  else
    return p % MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int test_case = 1;
  for (long long int test = 1; test <= test_case; test++) {
    long long int n;
    cin >> n;
    vector<long long int> a(n + 1), b(n + 1);
    for (long long int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (long long int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    a[0] = b[0] = 0;
    vector<long long int> dist(n + 1, 1E9);
    dist[n] = 0;
    vector<long long int> parent(n + 1, -1);
    vector<long long int> depth(n + 1, -1);
    set<long long int> s;
    for (long long int i = 0; i <= n; i++) {
      s.insert(i);
    }
    queue<long long int> q;
    q.push(n);
    while (!q.empty()) {
      long long int v = q.front();
      q.pop();
      long long int d = dist[v];
      while (true) {
        auto it = s.lower_bound(v - a[v]);
        if (it == s.end() || *it > v) {
          break;
        }
        long long int x = (*it) + b[*it];
        if (dist[x] > d + 1) {
          dist[x] = d + 1;
          parent[x] = v;
          depth[x] = *it;
          q.push(x);
        }
        s.erase(it);
      }
    }
    if (dist[0] != 1E9) {
      cout << dist[0] << '\n';
      long long int cur = 0;
      vector<long long int> ans;
      while (cur != n) {
        ans.push_back(depth[cur]);
        cur = parent[cur];
      }
      reverse(ans.begin(), ans.end());
      for (auto x : ans) {
        cout << x << " ";
      }
      cout << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
