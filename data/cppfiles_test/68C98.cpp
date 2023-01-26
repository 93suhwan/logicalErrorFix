#include <bits/stdc++.h>
using namespace std;
void fr() {
  freopen("test_input.txt", "r", stdin);
  freopen("a.out", "w", stdout);
}
const int N = 5e5 + 5;
const int MAX = 100 * int(1e3) + 5;
const int INF = 2e9;
const int mod = 1e9 + 7;
const double pi = 3.1415926536;
double eps = 1e-10;
void solve() {
  int k;
  cin >> k;
  int j = 1;
  while (j * j - (2 * j - 2) <= k) {
    j++;
  }
  j--;
  int cnt = j;
  int i = 1, x = j * j - (2 * j - 2);
  while (x < k) {
    x++;
    if (i < cnt) {
      i++;
    } else {
      j--;
    }
  }
  cout << i << " " << j << endl;
}
int t;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
