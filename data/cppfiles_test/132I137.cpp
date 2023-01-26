#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n = 7;
  int ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar, ar + n);
  cout << ar[0] << " " << ar[1] << " " << ar[2] << '\n';
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
