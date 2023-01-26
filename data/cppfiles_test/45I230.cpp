#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 9;
const int INF = 1e9;
void prereq() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
bool compare(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
signed main() {
  prereq();
  int t, n, k, ans, z, s1, s2;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
      a[i] = a[i] % 2;
      a[i] ? x.push_back(i) : y.push_back(i);
    }
    s1 = x.size();
    s2 = y.size();
    if (abs(s1 - s2) < 2) {
      vector<int> temp;
      if (s1 == s2) {
        if (*x.begin())
          temp = y;
        else
          temp = x;
      } else {
        temp = s1 > s2 ? x : y;
      }
      ans = 0;
      z = 0;
      for (auto i : temp) {
        ans += abs(i - z);
        z += 2;
      }
      printf("%d\n", ans);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
