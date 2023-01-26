#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];
bool vis[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int c = 0, d = 0, j = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      d = max(d, a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == d) break;
      if (a[i] >= d - j) {
        c++;
        break;
      }
      j++;
      c++;
    }
    cout << c << endl;
  }
}
