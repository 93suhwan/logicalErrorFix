#include <bits/stdc++.h>
using namespace std;
int log(int x) { return 32 - __builtin_clz(x) - 1; }
long long mod(long long a, long long m) { return ((a % m) + m) % m; }
long long gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
bool find_any_solution(long long a, long long b, long long c, long long &x0,
                       long long &y0, long long &g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g) {
    return false;
  }
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}
void shift_solution(long long &x, long long &y, long long a, long long b,
                    long long cnt) {
  x += cnt * b;
  y -= cnt * a;
}
long long find_all_solutions(long long a, long long b, long long c,
                             long long minx) {
  long long x, y, g;
  if (!find_any_solution(a, b, c, x, y, g)) return 0;
  a /= g;
  b /= g;
  long long sign_a = a > 0 ? +1 : -1;
  long long sign_b = b > 0 ? +1 : -1;
  shift_solution(x, y, a, b, (minx - x) / b);
  if (x < minx) shift_solution(x, y, a, b, sign_b);
  long long lx1 = x;
  return lx1;
}
long long dfs(long long u, long long p, vector<long long> graph[],
              long long lvs[]) {
  if ((long long)graph[u].size() == 1 && u != 1) {
    return 1;
  }
  for (auto v : graph[u]) {
    if (v != p) {
      lvs[u] += dfs(v, u, graph, lvs);
    }
  }
  return 0;
}
long long modpwr(long long a, long long b, const long long m) {
  long long ans = 1;
  a %= m;
  if (a == 0) {
    return 0;
  }
  while (b) {
    if (b % 2) {
      ans = (ans * a) % m;
    }
    a = (a * a) % m;
    b /= 2;
  }
  return ans % m;
}
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, m, i, j, k, tes, l, r, flag, x, val, num, ans;
  t = 1;
  cin >> t;
  for (tes = 1; tes <= t; tes++) {
    string s;
    cin >> n >> s;
    ans = s[n - 1] - '0';
    for (i = n - 2; i >= 0; i--) {
      if (s[i] >= '1') {
        ans += 1 + (s[i] - '0');
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
