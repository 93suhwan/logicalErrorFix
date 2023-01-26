#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tcase;
  cin >> tcase;
  while (tcase--) {
    int n;
    cin >> n;
    int a[n], sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    cout << (sum % n) / 2 << "\n";
  }
}
