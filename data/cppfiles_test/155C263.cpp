#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[200005];
pair<int, int> p[200005];
int res[200005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      p[i] = {a[i], i};
    }
    sort(p, p + n);
    string s;
    cin >> s;
    int sum = n;
    for (int i = n - 1; i >= 0; i--) {
      if (s[p[i].second] == '1') res[p[i].second] = sum--;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[p[i].second] == '0') res[p[i].second] = sum--;
    }
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
