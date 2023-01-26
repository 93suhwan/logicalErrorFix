#include <bits/stdc++.h>
using namespace std;
const long long lim = 205, inf = 1e18;
bool isect(pair<long long, long long> a, pair<long long, long long> b) {
  bool x = (a.first > b.first) && (a.first < b.second);
  bool y = (a.second > b.first) && (a.second < b.second);
  return x ^ y;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, ans = 0;
    bool arr[lim];
    long long ps[lim];
    fill(arr, arr + lim, 1);
    fill(ps, ps + lim, 0);
    cin >> n >> k;
    long long num2 = ((n - k) * (n - k - 1)) / 2, num1 = 0, num3 = 0;
    vector<pair<long long, long long> > v;
    for (int i = 0; i < k; i++) {
      long long a, b;
      cin >> a >> b;
      if (a > b) swap(a, b);
      v.emplace_back(a, b);
      arr[a] = arr[b] = 0;
    }
    for (auto x : v) {
      for (auto y : v) {
        num1 += isect(x, y);
      }
    }
    num1 /= 2;
    for (int i = 1; i <= 2 * n; i++) {
      ps[i] = ps[i - 1] + arr[i];
    }
    for (auto x : v) {
      long long a = ps[x.second] - ps[x.first];
      long long b = ps[2 * n] - a;
      if (a < 0) {
      }
      num3 += min(a, b);
    }
    cout << num1 + num2 + num3 << "\n";
  }
  return 0;
}
