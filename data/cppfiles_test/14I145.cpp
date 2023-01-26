#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
int main(int argc, const char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pii> b(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
      b[i] = {x, i};
    }
    sort(b.begin(), b.end());
    int k = 0;
    vector<pii> ans;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i].first) continue;
      k++;
      int x = b[i].second;
      ans.push_back({i + 1, x + 1});
      for (int j = x; j > i; j--) swap(a[j], a[j - 1]);
    }
    cout << k << '\n';
    for (auto x : ans)
      cout << x.first << " " << x.second << " " << x.second - x.first << '\n';
  }
  return 0;
}
