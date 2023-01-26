#include <bits/stdc++.h>
using namespace std;
const int N = 50000 + 100;
int n;
int a[N][10];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> a[i][j];
    }
  }
  int id = 1;
  for (int i = 2; i <= n; i++) {
    int c = 0;
    for (int j = 1; j <= 5; j++) {
      if (a[i][j] < a[id][j]) c++;
    }
    if (c >= 3) {
      id = i;
    }
  }
  bool f = false;
  for (int i = 1; i <= n; i++) {
    int c = 0;
    for (int j = 1; j <= 5; j++) {
      if (a[i][j] < a[id][j]) c++;
    }
    if (c >= 3) {
      f = true;
      break;
    }
  }
  if (f)
    cout << "-1"
         << "\n";
  else
    cout << id << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
