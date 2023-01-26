#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int n, c1 = 1, z = 0, o = 0;
    cin >> n;
    int a[n], b[n], c[200002];
    memset(c, 1, sizeof(c));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
      if (s[i] == '0')
        z++;
      else
        o++;
    if (z != n && o != n) {
      pair<int, int> a1[z], b1[o];
      int k1 = 0, k2 = 0;
      for (int i = 0; i < n; i++)
        if (s[i] == '0') {
          a1[k1].first = a[i];
          a1[k1++].second = i;
        } else {
          b1[k2].first = a[i];
          b1[k2++].second = i;
        }
      sort(a1, a1 + k1);
      sort(b1, b1 + k2);
      reverse(b1, b1 + k2);
      int c1 = 1;
      for (int i = 0; i < z; i++) a1[i].first = c1++;
      for (int i = 0; i < o; i++) b1[i].first = c1++;
      sort(a1, a1 + k1, comp);
      sort(b1, b1 + k2, comp);
      int k3 = 0, k4 = 0;
      for (int i = 0; i < n; i++)
        if (s[i] == '0')
          cout << a1[k3++].first << " ";
        else
          cout << b1[k4++].first << " ";
      cout << '\n';
    } else {
      for (int i = 0; i < n; i++) cout << b[i] << " ";
      cout << '\n';
    }
  }
  return 0;
}
