#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a;
  for (long long i = 0; i < n; i++) {
    long long p;
    cin >> p;
    a.push_back(p);
  }
  sort(a.begin(), a.end());
  long long score = 0;
  long long i = n - 1;
  long long j = n - 1 - k;
  while (j >= 0 && i > n - 1 - k) {
    long long x = a[j];
    long long y = a[i];
    score += (x / y);
    j--;
    i--;
  }
  for (i = 0; i <= j; i++) {
    score += a[i];
  }
  cout << score << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
