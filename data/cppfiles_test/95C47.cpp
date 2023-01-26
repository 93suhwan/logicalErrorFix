#include <bits/stdc++.h>
using namespace std;
int o1[4] = {-1, 1, 0, 0};
int o2[4] = {0, 0, 1, -1};
string yno[2] = {"NO\n", "YES\n"};
void print(vector<int>& a) {
  for (int i : a) cout << i << ' ';
  cout << endl;
}
void print(pair<int, int> a) { cout << a.first << ' ' << a.second << endl; }
void print(int a[], int n) {
  for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << endl;
}
void solve() {
  int s, n;
  cin >> s >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int t = 1000000000;
    while (s - t < (n - i)) {
      t /= 10;
    }
    cout << t << ' ';
    s -= t;
  }
  cout << s << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
