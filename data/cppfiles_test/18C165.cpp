#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int kq = 0;
    vector<pair<int, int> > res;
    int n, k;
    cin >> n >> k;
    vector<bool> used(2 * n + 1, false);
    for (int i = 1; i <= k; i++) {
      int u, v;
      cin >> u >> v;
      res.push_back({min(u, v), max(u, v)});
      used[u] = true;
      used[v] = true;
    }
    vector<int> conlai;
    for (int i = 1; i <= 2 * n; i++) {
      if (!used[i]) conlai.push_back(i);
    }
    int len = n - k;
    for (int i = 0; i < len; i++) {
      res.push_back({conlai[i], conlai[i + len]});
    }
    for (int i = 0; i < res.size(); i++) {
      for (int j = i + 1; j < res.size(); j++) {
        int a = (res[j].first - res[i].first) * (res[j].second - res[i].first);
        int b =
            (res[j].first - res[i].second) * (res[j].second - res[i].second);
        if (a * b < 0) {
          kq++;
        }
      }
    }
    cout << kq << endl;
  }
}
