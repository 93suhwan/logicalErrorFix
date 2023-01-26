#include <bits/stdc++.h>
using namespace std;
long long t, n, k;
vector<pair<int, int>> v;
bool viz[205];
bool check(int a, int b, int a2, int b2) {
  if (a > a2) {
    swap(a, a2);
    swap(b, b2);
  }
  if (b > a2 && b < b2)
    return true;
  else
    return false;
}
long long query(int a, int b) {
  long long ans = 0;
  for (auto it : v)
    if (check(a, b, it.first, it.second)) ans++;
  return ans;
}
long long dist(int a, int b) {
  int st = 0, dr = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (i == a || i == b) continue;
    if (viz[i]) continue;
    if (i > a && i < b)
      st++;
    else
      dr++;
  }
  return min(st, dr);
}
void add(int a, int b) {
  viz[a] = true;
  viz[b] = true;
  v.push_back({a, b});
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t) {
    t--;
    cin >> n >> k;
    long long ans = 0;
    v.clear();
    for (int i = 1; i <= 2 * n; i++) viz[i] = false;
    for (int i = 1; i <= k; i++) {
      int x, y;
      cin >> x >> y;
      if (x > y) swap(x, y);
      ans += query(x, y);
      add(x, y);
    }
    for (auto it : v) ans += dist(it.first, it.second);
    ans += (n - k - 1) * (n - k) / 2;
    cout << ans << '\n';
  }
  return 0;
}
