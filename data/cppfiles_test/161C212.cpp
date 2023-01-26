#include <bits/stdc++.h>
using namespace std;
long long fnc(vector<long long> v, long long r, long long l) {
  for (long long i = l; i <= r; i++) {
    if (count(v.begin(), v.end(), i))
      ;
    else
      return i;
  }
}
void solve() {
  long long n;
  cin >> n;
  long long l[n], r[n];
  for (long long i = 0; i < n; i++) cin >> l[i] >> r[i];
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (r[j] - l[j] < r[i] - l[i]) {
        long long temp = r[j];
        r[j] = r[i];
        r[i] = temp;
        temp = l[j];
        l[j] = l[i];
        l[i] = temp;
      }
    }
  }
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    if (r[i] == l[i]) {
      cout << r[i] << " " << r[i] << " " << r[i] << "\n";
      v.push_back(r[i]);
    } else {
      long long x = fnc(v, r[i], l[i]);
      cout << l[i] << " " << r[i] << " " << x << "\n";
      v.push_back(x);
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
