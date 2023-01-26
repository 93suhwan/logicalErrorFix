#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  map<char, int> m;
  int k = 2;
  int n = s.length();
  int arr[n];
  bool flag = false;
  for (int i = 0; i < n; i++) {
    char x = s[i];
    m[x]++;
    if (m[x] > k) {
      arr[i] = 0;
      flag = true;
    } else
      arr[i] = m[x];
  }
  int R = 0, G = 0, Z = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1)
      R++;
    else if (arr[i] == 2)
      G++;
    else if (arr[i] == 0)
      Z++;
  }
  if (R == G)
    cout << R << "\n";
  else if (R > G) {
    for (int i = 0; i < n; i++) {
      if (m[s[i]] == 1) {
        if (n % 2 == 1 && Z == 0) {
          Z++;
          R--;
        } else {
          R--;
          G++;
        }
      }
      if (R == G) {
        cout << R << "\n";
        return;
      }
    }
  } else if (G > R) {
    for (int i = 0; i < n; i++) {
      if (m[s[i]] == 1) {
        if (n % 2 == 1 && Z == 0) {
          Z++;
          G--;
        } else {
          G--;
          R++;
        }
      }
      if (R == G) {
        cout << R << "\n";
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
