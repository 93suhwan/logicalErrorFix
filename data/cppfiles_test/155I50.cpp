#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int p[maxn];
int n, cnt;
struct Node {
  int first, second, pos;
} q[maxn];
bool cmp(Node lhs, Node rhs) {
  if (lhs.second != rhs.second)
    return lhs.second > rhs.second ? true : false;
  else
    return lhs.first > rhs.first ? true : false;
}
bool cmp1(Node lhs, Node rhs) { return lhs.pos > rhs.pos ? false : true; }
void solve() {
  sort(q, q + n, cmp);
  int anocnt = cnt;
  for (int i = cnt; i > 0; i--) {
    if (q[n - cnt - i].first >= cnt + 1)
      continue;
    else {
      swap(q[n - cnt - i].first, q[n - anocnt].first);
      anocnt--;
    }
  }
  sort(q, q + n, cmp1);
  for (int i = 0; i < n; i++) {
    if (i != n - 1)
      cout << q[i].first << " ";
    else
      cout << q[i].first << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> q[i].first;
      q[i].pos = i;
    }
    getchar();
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        q[i].second = 1;
      else {
        q[i].second = 0;
        cnt++;
      }
    }
    solve();
  }
  return 0;
}
