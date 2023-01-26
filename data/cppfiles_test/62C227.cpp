#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
using ll = long long;
const int maxn = 1e6 + 5;
int a[maxn];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int last0 = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      last0 = i;
    }
  }
  if (last0 == -1) {
    cout << n + 1 << " ";
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << "\n";
  } else {
    for (int i = 1; i <= last0; i++) {
      cout << i << " ";
    }
    cout << n + 1 << " ";
    for (int i = last0 + 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
