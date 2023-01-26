#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  long long int mxelem = INT_MIN;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mxelem = max(mxelem, a[i]);
  }
  long long int k = 0, f = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == mxelem) {
      break;
    }
    k++;
    long long int mv = i - 1;
    while (mv >= 0 and a[i] > a[mv]) {
      mv--;
    }
    if (a[mv] == mxelem) break;
  }
  cout << k << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
