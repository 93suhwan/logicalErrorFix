#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;
int n;
int a[N];
char s[N];
pair<int, char> ans[N];
void solv() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cin >> (s + 1);
  sort(a + 1, a + n + 1);
  deque<int> l, r;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == n % 2)
      r.push_back(a[i]);
    else
      l.push_back(a[i]);
  }
  if (s[n] == 'L') swap(l, r);
  for (int i = n; i > 1; --i) {
    if (s[i] == 'R') {
      if (s[i - 1] == 'R') {
        if (i % 2 == 0) {
          ans[i] = make_pair(l.front(), 'L');
          l.pop_front();
        } else {
          ans[i] = make_pair(r.front(), 'R');
          r.pop_front();
        }
      } else {
        ans[i] = make_pair(r.back(), 'R');
        r.pop_back();
      }
    } else {
      if (s[i - 1] == 'L') {
        if (i % 2 == 0) {
          ans[i] = make_pair(r.front(), 'R');
          r.pop_front();
        } else {
          ans[i] = make_pair(l.front(), 'L');
          l.pop_front();
        }
      } else {
        ans[i] = make_pair(l.back(), 'L');
        l.pop_back();
      }
    }
  }
  if (!r.empty())
    ans[1] = make_pair(r.back(), 'R');
  else if (!l.empty())
    ans[1] = make_pair(l.back(), 'L');
  else
    assert(false);
  for (int i = 1; i <= n; ++i)
    cout << ans[i].first << ' ' << ans[i].second << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  while (tt--) solv();
  return 0;
}
