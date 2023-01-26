#include <bits/stdc++.h>
using namespace std;
int main() {
  queue<long long> q;
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long h;
    cin >> n >> h;
    vector<int> v(n);
    long long sum = 0;
    cin >> v[0];
    int maxm = 0;
    for (int i = 1; i < n; i++) {
      cin >> v[i];
      v[i - 1] = v[i] - v[i - 1];
      maxm = max(maxm, v[i - 1]);
      sum += v[i - 1];
    }
    v[n - 1] = maxm;
    sum += v[n - 1];
    if (sum < h) {
      q.push(h - sum + v[n - 1]);
      continue;
    }
    sort(v.begin(), v.end());
    int l = 0, u, m;
    for (int i = 0; i < n; i++) {
      h = h - ((n - i) * (v[i] - l));
      if (h <= 0) {
        h = h + ((n - i) * (v[i] - l));
        m = n - i;
        u = v[i];
        break;
      }
      l = v[i];
    }
    long long mid;
    int lm = l;
    while (l <= u) {
      mid = (l + u) / 2;
      if (((mid - lm) * m) == h)
        break;
      else if (((mid - lm) * m) > h) {
        u = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    q.push(mid);
  }
  while (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }
}
