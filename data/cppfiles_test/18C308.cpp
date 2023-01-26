#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > lines;
    set<int> s;
    for (int i = 0; i < 2 * n; i++) {
      s.insert(i + 1);
    }
    for (int i = 0; i < k; i++) {
      int a, b;
      cin >> a >> b;
      lines.emplace_back(a, b);
      s.erase(a);
      s.erase(b);
    }
    vector<int> v(s.begin(), s.end());
    for (int i = 0; i < (int)v.size() / 2; i++) {
      lines.emplace_back(v[i], v[i + (int)v.size() / 2]);
    }
    auto comp = [&](pair<int, int> a, pair<int, int> b) {
      if (a.second < a.first) swap(a.first, a.second);
      if (b.second < b.first) swap(b.first, b.second);
      if (a.second < b.first) return false;
      if (a.first > b.second) return false;
      if (a.first < b.first && a.second > b.second) return false;
      if (a.first > b.first && a.second < b.second) return false;
      return true;
    };
    int ans = 0;
    for (int i = 0; i < (int)lines.size(); i++) {
      for (int j = 0; j < i; j++) {
        ans += comp(lines[i], lines[j]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
