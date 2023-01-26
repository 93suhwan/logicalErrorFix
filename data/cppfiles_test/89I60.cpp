#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  bool check = true;
  while (check) {
    check = false;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] % (i + 2) != 0) {
        a.erase(a.begin() + i);
        n--;
        check = true;
      }
    }
  }
  if (n == 0)
    cout << "YES";
  else
    cout << "NO";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
