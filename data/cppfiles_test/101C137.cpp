#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return res;
}
bool isprime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0 && s[i] == 'B') {
      cout << "NO" << endl;
      return;
    } else if (a[i] > n && a[i] == 'R') {
      cout << "NO" << endl;
      return;
    }
  }
  vector<long long> blue, red;
  for (int i = 0; i < n; i++)
    if (s[i] == 'B')
      blue.push_back(a[i]);
    else
      red.push_back(a[i]);
  sort(blue.begin(), blue.end());
  sort(red.begin(), red.end());
  long long i = 0, j = 0;
  long long cnt = 1;
  bool ok = 1;
  while (i < blue.size() && j < red.size()) {
    if (blue[i] >= cnt)
      i++;
    else if (red[j] <= cnt)
      j++;
    else {
      ok = 0;
      break;
    }
    cnt++;
  }
  if (ok == 0) {
    cout << "NO" << endl;
    return;
  }
  while (i < blue.size()) {
    if (blue[i] < cnt) {
      ok = 0;
      break;
    }
    cnt++;
    i++;
  }
  if (ok == 0) {
    cout << "NO" << endl;
    return;
  }
  while (j < red.size()) {
    if (red[j] > cnt) {
      ok = 0;
      break;
    }
    cnt++;
    j++;
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
