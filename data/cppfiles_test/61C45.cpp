#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int n;
  cin >> n;
  long long int total = (n * 1LL * (n - 1) * (n - 2)) / 6;
  long long int t, d;
  vector<long long int> b(n);
  vector<long long int> a(n);
  vector<long long int> freqT(n + 1, 0);
  vector<long long int> freqD(n + 1, 0);
  for (long long int i = 0; i < n; i++) {
    cin >> t >> d;
    a[i] = t;
    b[i] = d;
    freqT[t]++;
    freqD[d]++;
  }
  for (long long int i = 0; i < n; i++) {
    t = a[i];
    d = b[i];
    long long int countT = freqT[t];
    long long int countD = freqD[d];
    total -= (countT - 1) * 1LL * (countD - 1);
  }
  cout << total << "\n";
}
