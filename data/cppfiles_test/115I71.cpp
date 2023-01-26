#include <bits/stdc++.h>
using namespace std;
int a[105];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    pq;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, H;
    cin >> n >> H;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) pq.push(make_pair(a[i + 1] - a[i], i));
    pq.push(make_pair(2147483647, n));
    int sum = 0, lst = 0, ans = 0;
    while (sum < H && pq.size() > 1) {
      if (sum + (pq.top().first - lst) * pq.size() < H)
        sum += (pq.top().first - lst) * pq.size(), ans = pq.top().first;
      else {
        ans += ceil((H - sum) / (double)(pq.size()));
        break;
      }
      lst = pq.top().first;
      pq.pop();
    }
    if (pq.size() == 1)
      cout << ans + (H - sum) << endl;
    else
      cout << ans << endl;
    while (pq.size()) pq.pop();
  }
  return 0;
}
