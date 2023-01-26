#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  long long c = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
void no() { cout << "no" << endl; }
void yes() { cout << "yes" << endl; }
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cout << "()";
  }
  cout << "\n";
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < i; j++) {
      cout << "(";
    }
    long long l = n - i;
    for (long long j = 0; j < l; j++) {
      cout << "()";
    }
    for (long long j = 0; j < i; j++) {
      cout << ")";
    }
    cout << "\n";
  }
}
