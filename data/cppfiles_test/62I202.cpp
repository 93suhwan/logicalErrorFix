#include <bits/stdc++.h>
using namespace std;
int64_t mod;
void Rahul() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  if (a.back() == 0) {
    for (int i = 1; i <= n + 1; i++) cout << i << " ";
    cout << endl;
    return;
  } else if (a[0] == 1) {
    cout << n + 1 << " ";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == 0 && a[i + 1] == 1) {
      for (int j = 1; j <= i; j++) cout << j << " ";
      cout << n + 1 << " ";
      for (int j = i + 1; j <= n; j++) cout << j << " ";
      cout << endl;
      return;
    }
  }
  cout << -1 << endl;
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) Rahul();
  return 0;
}
