#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], k[N], sum;
vector<int> v[N];
char s[N];
struct cmp1 {
  bool operator()(pair<int, int> &x, pair<int, int> &y) {
    if (x.second == y.second)
      return x.first > y.first;
    else
      return x.second > y.second;
  }
};
int main() {
  int n, m, _, x;
  scanf("%d", &_);
  while (_--) {
    scanf("%d", &n);
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp1> q;
    sum = 0;
    for (int i = 1; i <= n; i++) v[i].clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &k[i]);
      if (!k[i]) {
        q.push({i, 1});
        sum++;
      }
      for (int j = 1; j <= k[i]; j++) {
        scanf("%d", &x);
        v[x].push_back(i);
      }
    }
    int ans = -1;
    while (!q.empty()) {
      pair<int, int> tem = q.top();
      q.pop();
      x = tem.first;
      ans = max(ans, tem.second);
      for (auto it : v[x]) {
        k[it]--;
        if (!k[it]) {
          if (it > x)
            q.push({it, tem.second});
          else
            q.push({it, tem.second + 1});
          sum++;
        }
      }
    }
    if (sum == n)
      printf("%d\n", ans);
    else
      printf("-1\n");
  }
  return 0;
}
