#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  int max = 0;
  int pos = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (max < a[i]) {
      max = a[i];
      pos = i;
    }
  }
  cout << max - pos - 1 << "\n";
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  int tests = 1;
  cin >> tests;
  while (tests--) solve();
  return 0;
}
