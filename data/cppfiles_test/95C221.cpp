#include <bits/stdc++.h>
using namespace std;
int a[20];
vector<int> da;
void dfs(int t, int b) {
  int ls[20];
  int num = 0;
  int x = t;
  int sum = 0;
  while (x) {
    ls[++num] = x % 10;
    sum += x % 10;
    x = x / 10;
  }
  while (1) {
    if (sum >= b) {
      for (int i = 1; i <= num; i++) {
        while (ls[i] >= 1 && b - 1 > 0) {
          da.push_back(a[i]);
          t -= a[i];
          ls[i]--;
          b--;
        }
        if (b == 1) break;
      }
      da.push_back(t);
      return;
    }
    for (int i = 2; i <= num; i++) {
      if (ls[i] > 0) {
        ls[i] -= 1;
        ls[i - 1] += 10;
        sum += 9;
        break;
      }
    }
  }
}
void solve() {
  da.clear();
  int s, n;
  cin >> s >> n;
  dfs(s, n);
  for (int i = 0; i < da.size(); i++) {
    cout << da[i] << ' ';
  }
  cout << endl;
}
int main() {
  a[1] = 1;
  for (int i = 2; i <= 10; i++) a[i] = a[i - 1] * 10;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
