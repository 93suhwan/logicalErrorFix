#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n;
int tree[N];
int a1[N], a2[N];
int lowbit(int x) { return x & -x; }
void add(int pos) {
  while (pos <= n) {
    tree[pos]++;
    pos += lowbit(pos);
  }
}
int cal(int pos) {
  int res = 0;
  while (pos >= 1) {
    res += tree[pos];
    pos -= lowbit(pos);
  }
  return res;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) tree[i] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a1[i];
      a2[i] = a1[i];
    }
    sort(a1 + 1, a1 + 1 + n);
    int len = unique(a1 + 1, a1 + 1 + n) - a1;
    for (int i = 1; i <= n; i++) {
      a2[i] = lower_bound(a1 + 1, a1 + 1 + len, a2[i]) - a1;
    }
    int cnt = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
      int tmp = a2[i];
      add(tmp);
      int check1 = cal(n) - cal(tmp);
      int check2 = cal(tmp - 1);
      res += min(check1, check2);
    }
    cout << res << endl;
  }
  return 0;
}
