#include <bits/stdc++.h>
const double E = exp(1.0);
const double pi = 3.1415926;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;
using namespace std;
pair<int, int> pa[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > >
    q;
int ans1[N], ans2[N], idx;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(ans1, 0, sizeof ans1);
    memset(ans2, 0, sizeof ans2);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &pa[i].first);
      pa[i].second = i;
      q.push(pa[i]);
    }
    idx = 1;
    int ans = 0;
    while (1) {
      pair<int, int> temp1 = q.top();
      q.pop();
      pair<int, int> temp2 = q.top();
      q.pop();
      if (temp2.first == 0 || temp1.first == 0) break;
      ans++;
      ans1[idx] = temp1.second;
      ans2[idx] = temp2.second;
      temp1.first--;
      temp2.first--;
      idx++;
      q.push(temp1);
      q.push(temp2);
    }
    printf("%d\n", ans);
    for (int i = 1; i < idx; i++) printf("%d %d\n", ans2[i], ans1[i]);
    while (!q.empty()) q.pop();
  }
  return 0;
}
