#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int maxn = 1e5 + 5;
void solve() {
  int n;
  char c;
  string str;
  cin >> n >> c;
  cin >> str;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] != c) {
      cnt++;
    }
  }
  if (cnt == 0) {
    cout << 0 << endl;
    return;
  }
  cnt = 0;
  int pos = 0, flag = 0;
  for (int i = 2; i <= n; i++) {
    cnt = 0;
    for (int j = i; j <= n; j += i) {
      if (str[j - 1] != c) {
        cnt++;
        break;
      }
    }
    if (cnt == 0) {
      flag = 1;
      pos = i;
      break;
    }
  }
  if (flag == 1) {
    cout << 1 << endl;
    cout << pos << endl;
    return;
  }
  cout << 2 << endl;
  cout << n - 1 << " " << n << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
