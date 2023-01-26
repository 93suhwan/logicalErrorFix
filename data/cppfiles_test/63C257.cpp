#include <bits/stdc++.h>
using namespace std;
long long rr[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long cc[] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long mod = 1e9 + 7;
const long long N = 300050;
long long PAR[2][N], SIZE[2][N];
void pre(long long idx) {
  for (long long i = 0; i < N; i++) {
    PAR[idx][i] = i, SIZE[idx][i] = 1;
  }
}
long long find(long long idx, long long a) {
  if (a == PAR[idx][a]) {
    return a;
  }
  return PAR[idx][a] = find(idx, PAR[idx][a]);
}
void join(long long idx, long long a, long long b) {
  a = find(idx, a);
  b = find(idx, b);
  if (a == b) return;
  if (SIZE[idx][a] < SIZE[idx][b]) {
    swap(a, b);
  }
  PAR[idx][b] = a;
  SIZE[idx][a] += SIZE[idx][b];
}
bool check(long long idx, long long a, long long b) {
  a = find(idx, a);
  b = find(idx, b);
  return (a != b);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long test = 1;
  pre(0);
  pre(1);
  while (test--) {
    long long n, m1, m2;
    cin >> n >> m1 >> m2;
    for (long long i = 0; i < m1; i++) {
      long long a, b;
      cin >> a >> b;
      join(0, a, b);
    }
    for (long long i = 0; i < m2; i++) {
      long long a, b;
      cin >> a >> b;
      join(1, a, b);
    }
    vector<pair<long long, long long> > ans;
    for (long long i = 1; i <= n; i++) {
      if (check(0, 1, i) && check(1, 1, i)) {
        join(0, 1, i);
        join(1, 1, i);
        ans.push_back({1, i});
      }
    }
    long long l = 1, r = 1;
    while (true) {
      while (l <= n && !check(0, 1, l)) {
        l++;
      }
      while (r <= n && !check(1, 1, r)) {
        r++;
      }
      if (l > n || r > n) break;
      join(0, l, r);
      join(1, l, r);
      ans.push_back({l, r});
    }
    cout << ans.size() << '\n';
    for (auto it : ans) {
      cout << it.first << ' ' << it.second << '\n';
    }
  }
  return 0;
}
