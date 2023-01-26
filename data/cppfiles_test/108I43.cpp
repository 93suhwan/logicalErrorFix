#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int z = 1; z <= t; z++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    string s;
    for (int i = 1; i <= n; i++) s += '0';
    int maxVal = 0, idx = 0;
    for (int i = 1; i <= n; i++) {
      if (maxVal < a[i]) {
        maxVal = a[i];
        idx = i;
      }
    }
    s[idx - 1] = '1';
    int maxVal2 = 0, idx2 = 0;
    for (int i = 1; i <= n; i++) {
      if (maxVal2 < b[i]) {
        maxVal2 = b[i];
        idx2 = i;
      }
    }
    s[idx2 - 1] = '1';
    for (int i = 1; i <= n; i++) {
      if (b[i] > b[idx] || a[i] > a[idx2]) {
        s[i - 1] = '1';
      }
    }
    cout << s << "\n";
  }
  return 0;
}
