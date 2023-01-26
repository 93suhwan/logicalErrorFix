#include <bits/stdc++.h>
using namespace std;
int n, p;
const int N = 200007;
int a[N], cnt[N];
char t[N];
pair<int, int> ans[N];
deque<int> q[2];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  cin >> (t + 1);
  p = (t[n] == 'R');
  for (int i = n; i >= 1; i--) {
    q[p].push_back(a[i]);
    cnt[p]++;
    p ^= 1;
  }
  for (int i = n; i >= 1; i--) {
    if (cnt[0] != cnt[1]) {
      p = (cnt[0] < cnt[1]);
      if (t[i] != t[i - 1]) {
        ans[i] = make_pair(q[p].front(), p);
        q[p].pop_front();
        cnt[p]--;
      } else {
        ans[i] = make_pair(q[p].back(), p);
        q[p].pop_back();
        cnt[p]--;
      }
    } else {
      p = (q[0].front() < q[1].front());
      if (t[i] != t[i - 1]) {
        ans[i] = make_pair(q[p].front(), p);
        q[p].pop_front();
        cnt[p]--;
      } else {
        ans[i] = make_pair(q[p ^ 1].back(), p ^ 1);
        q[p ^ 1].pop_back();
        cnt[p ^ 1]--;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i].first;
    if (ans[i].second)
      cout << " R" << endl;
    else
      cout << " L" << endl;
  }
}
