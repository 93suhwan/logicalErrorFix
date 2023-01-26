#include <bits/stdc++.h>
using namespace std;
long long int Mod = 1e9 + 1;
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int a[n];
  long long int b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  long long int check = 0;
  sort(b, b + n);
  bool status = true;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] <= a[i + 1]) {
      continue;
    } else {
      check++;
    }
    if (b[i] != a[i]) {
      status = false;
    }
  }
  if (status) {
    if (b[n - 1] != a[n - 1]) {
      status = false;
    }
    if (status) {
      cout << "YES"
           << "\n";
      return;
    }
  }
  if (check + 1 == k) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
