#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  long long int mxelem = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    mxelem = max(mxelem, a[i]);
  }
  long long int k = 0;
  int mv = n - 1;
  while (a[mv] != mxelem) {
    long long int z = mv - 1;
    while (a[mv] > a[z]) {
      z--;
    }
    k++;
    mv = z;
  }
  cout << k << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
