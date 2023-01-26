#include <bits/stdc++.h>
using namespace std;
long long n, v, m, h, w;
string s;
vector<pair<int, int>> dx = {{-1, 0},  {0, -1}, {1, 0},  {0, 1},
                             {-1, -1}, {1, 1},  {1, -1}, {-1, 1}};
void solve() {
  cin >> n;
  int a[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sol = 0;
  int ti = 0;
  for (int i = 1; i <= n; i++) {
    int r = 0;
    for (int j = 0; j < n - 1; j++) {
      if (a[j] < a[j + 1]) {
        r++;
      }
    }
    if (r == n - 1) break;
    int j = 0, until = n - 3;
    if (i % 2 == 0) {
      j = 1;
      until = n - 2;
    }
    for (; j <= until; j += 2) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
      }
    }
    sol++;
  }
  cout << sol << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
