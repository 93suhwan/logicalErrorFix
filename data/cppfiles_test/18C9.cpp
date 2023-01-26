#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;
int n, d;
bool p[maxn];
bool used[maxn];
int solve(int i) {
  vector<bool> vec;
  while (!used[i]) vec.push_back(p[i]), used[i] = 1, i = (i + d) % n;
  vector<int> cnt;
  int count = 0;
  bool flag = 0;
  for (auto it : vec) {
    if (!it) {
      flag = 1;
      if (count) cnt.push_back(count), count = 0;
    } else
      count++;
  }
  if (!flag) return -1;
  if (count) cnt.push_back(count);
  if (vec[0] && *(vec.end() - 1) && cnt.size() > 1) {
    cnt.push_back(cnt[0] + *(cnt.end() - 1));
  }
  sort(cnt.begin(), cnt.end());
  if (cnt.empty()) return 0;
  return *(cnt.end() - 1);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
      used[i] = 0;
      scanf("%d", &p[i]);
    }
    bool flag = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        int res = solve(i);
        if (res == -1) {
          flag = 1;
          break;
        } else
          ans = max(res, ans);
      }
    }
    if (flag)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
}
