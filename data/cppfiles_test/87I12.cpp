#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve() {
  long n;
  cin >> n;
  long a[n];
  long max = 0;
  long pos = 0;
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
