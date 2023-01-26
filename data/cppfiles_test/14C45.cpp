#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto i = 0; i < n; i++) cin >> a[i];
    b = a;
    c = a;
    sort(b.begin(), b.end());
    vector<pair<pair<int, int>, int>> v;
    for (int i = 1; i < n; i++) {
      int x = find(a.begin() + (i - 1), a.end(), b[i - 1]) - a.begin();
      if (x == (i - 1)) {
        continue;
      } else {
        v.push_back({{i, x + 1}, (x + 1 - i)});
        a.erase(a.begin() + (x));
        a.insert(a.begin() + (i - 1), b[i - 1]);
      }
    }
    cout << v.size() << endl;
    for (auto itr : v)
      cout << itr.first.first << " " << itr.first.second << " " << itr.second
           << endl;
  }
  return 0;
}
