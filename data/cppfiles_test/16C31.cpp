#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int count = 0;
    priority_queue<pair<int, int>> p;
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; ++i) {
      cin >> k;
      if (k != 0) p.push({k, i});
    }
    while (p.size() >= 2) {
      auto it1 = p.top();
      p.pop();
      auto it2 = p.top();
      p.pop();
      a.push_back({it1.second, it2.second});
      it1.first--;
      it2.first--;
      if (it1.first != 0) p.push(it1);
      if (it2.first != 0) p.push(it2);
    }
    cout << a.size() << endl;
    for (auto &x : a) cout << x.first << " " << x.second << endl;
  }
  return 0;
}
