#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
struct node {
  int data, vis, flag;
};
bool cmp(node a, node b) {
  if (a.flag != b.flag)
    return a.flag < b.flag;
  else
    return a.data < b.data;
}
void solve() {
  int n;
  cin >> n;
  vector<node> a(n + 1);
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].data;
    a[i].vis = i;
  }
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      a[i + 1].flag = 1;
    }
  }
  sort(a.begin(), a.end(), cmp);
  for (int i = n; i > 0; i--) {
    b[a[i].vis] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
