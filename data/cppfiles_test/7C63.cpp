#include <bits/stdc++.h>
using namespace std;
vector<long long> v, d;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
struct RMQ {
  vector<vector<long long>> rmq;
  vector<int> logb2;
  RMQ() {}
  RMQ(vector<long long>& v) {
    int n = (int)v.size();
    logb2.resize(n + 1, 0);
    rmq.resize(1, vector<long long>(n));
    for (int i = 0; i < n; i++) {
      rmq[0][i] = v[i];
    }
    for (int i = 0; (1 << i) <= n; i++) {
      logb2[1 << i] = i;
    }
    for (int i = 1; i <= n; i++) {
      logb2[i] = max(logb2[i], logb2[i - 1]);
    }
    rmq.resize(logb2.back() + 1);
    for (int t = 1; t < (int)rmq.size(); t++) {
      rmq[t].resize(n - (1 << t) + 1);
      for (int i = 0; i <= n - (1 << t); i++)
        rmq[t][i] = gcd(rmq[t - 1][i], rmq[t - 1][i + (1 << (t - 1))]);
    }
  }
  long long query(int i, int j) {
    if (i > j) {
      swap(i, j);
    }
    int k = logb2[j - i + 1];
    return gcd(rmq[k][i], rmq[k][j - (1 << k) + 1]);
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    v.resize(n);
    d.resize(n - 1);
    for (auto& x : v) {
      cin >> x;
    }
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    if (n == 2) {
      cout << 1 + (abs(v[0] - v[1]) > 1) << '\n';
      continue;
    }
    for (int i = 0; i < n - 1; i++) d[i] = abs(v[i] - v[i + 1]);
    if (count(d.begin(), d.end(), 1) == n - 1) {
      cout << 1 << '\n';
      continue;
    }
    int res = 0;
    RMQ rmq(d);
    for (int i = 0; i < n - 1; i++) {
      long long cur = d[i];
      int j = i;
      while (j < n - 1) {
        if (cur == 1) {
          break;
        }
        int l = j + 1, r = n - 1;
        while (l != r) {
          int mid = (l + r) >> 1;
          long long g = rmq.query(i, mid);
          g == cur ? l = mid + 1 : r = mid;
        }
        if (l == n - 1) {
          j = l;
          break;
        }
        j = l;
        cur = rmq.query(i, l);
      }
      res = max(res, j - i);
    }
    cout << res + 1 << '\n';
  }
  cin.ignore(2);
  return 0;
}
