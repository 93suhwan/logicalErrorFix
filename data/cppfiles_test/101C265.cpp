#include <bits/stdc++.h>
using namespace std;
long long n;
pair<long long, long long> get_fs(long long id) {
  return {id + 1, n - (id + 1)};
}
void test() {
  cin >> n;
  vector<long long> a(n);
  long long lower = 0, higher = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= n / 2)
      lower++;
    else
      higher++;
  }
  string s;
  cin >> s;
  vector<long long> R, B;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'R')
      R.push_back(a[i]);
    else
      B.push_back(a[i]);
  }
  bool res = true;
  long long b = B.size(), r = R.size();
  sort(B.begin(), B.end());
  for (long long i = 0; i < b; i++) {
    if (B[i] <= i) res = false;
  }
  sort(R.begin(), R.end(), greater<long long>());
  for (long long i = 0; i < r; i++) {
    if (R[i] > n - i) res = false;
  }
  if (res)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    test();
  }
}
