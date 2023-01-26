#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> link;
vector<int> h, ser, l;
void f(int n) {
  int ans = 1;
  ser[n] = true;
  for (int i = 0; i < link[n].size(); i++) {
    if (!ser[link[n][i]]) {
      f(link[n][i]);
      ans = max(ans, h[link[n][i]] + 1);
    }
  }
  h[n] = ans;
}
void g(int n, bool b) {
  if (b) l.push_back(h[n]);
  bool found = false;
  ser[n] = false;
  for (int i = 0; i < link[n].size(); i++) {
    if (ser[link[n][i]]) {
      if (found)
        g(link[n][i], true);
      else if (h[link[n][i]] == h[n] - 1) {
        g(link[n][i], false);
        found = true;
      } else
        g(link[n][i], true);
    }
  }
}
int main() {
  long long n, k, a, b, x;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    h.push_back(0);
    ser.push_back(false);
    link.push_back({});
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    link[a - 1].push_back(b - 1);
    link[b - 1].push_back(a - 1);
  }
  f(0);
  g(0, true);
  sort(l.begin(), l.end());
  if (k >= l.size()) {
    if (k >= n / 2)
      cout << (n / 2) * ((n + 1) / 2) << '\n';
    else
      cout << k * (n - k);
  } else {
    x = 0;
    for (int i = 0; i < l.size() - k; i++) x += l[i];
    if (x >= n / 2) x = n / 2;
    cout << (k - x) * (n - k - x) << '\n';
  }
  return 0;
}
