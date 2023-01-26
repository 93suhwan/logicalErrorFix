#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct sut {
  int num, id;
} a[200010];
bool cmp(sut a, sut b) { return a.num < b.num; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].num, a[i].id = i;
    vector<pair<int, int>> v;
    int r = n, l = 1;
    int cnt1 = 0, cnt2 = 0;
    while (l < r) {
      int minn = min(a[l].num, a[r].num);
      a[l].num -= minn;
      a[r].num -= minn;
      for (int i = 0; i < minn; i++) v.push_back({a[l].id, a[r].id});
      if (a[l].num == 0) l++;
      if (a[r].num == 0) r--;
    }
    if (a[l].num >= 2) {
      int k = a[l].num / 2;
      vector<pair<int, int>> v1;
      for (int i = 0; i < v.size(); i++) {
        int vf = v[i].first;
        if (v[i].first != a[l].id && v[i].second != a[l].id && k)
          v1.push_back({vf, a[l].id}), v1.push_back({a[l].id, v[i].second}),
              k--;
        else
          v1.push_back(v[i]);
      }
      cout << v1.size() << endl;
      for (int i = 0; i < v1.size(); i++) {
        cout << v1[i].first << " " << v1[i].second << endl;
      }
    } else if (a[r].num >= 2) {
      int k = a[r].num / 2;
      vector<pair<int, int>> v1;
      for (int i = 0; i < v.size(); i++) {
        if (v[i].first != a[r].id && v[i].second != a[r].id && k)
          v1.push_back({v[i].first, a[r].id}),
              v1.push_back({a[r].id, v[i].second}), k--;
        else
          v1.push_back(v[i]);
      }
      cout << v1.size() << endl;
      for (int i = 0; i < v1.size(); i++) {
        cout << v1[i].first << " " << v1[i].second << endl;
      }
    } else {
      cout << v.size() << endl;
      for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
      }
    }
  }
  return 0;
}
