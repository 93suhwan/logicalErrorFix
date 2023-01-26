#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const long long int int_max = 1e18;
const long long int int_min = -1e18;
const long double PI = acos(-1);
using namespace std;
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else {
    if (y > 0)
      return x * temp * temp;
    else
      return (temp * temp) / x;
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int>> v;
  vector<long long int> ckc(n, 0);
  long long int a1[n + 2];
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> a1[i];
    v.push_back({a1[i], i});
  }
  if (n % 2 == 0) {
    vector<long long int> finalans;
    for (long long int i = 1; i <= n; i++) {
      finalans.push_back(-v[i].first);
      finalans.push_back(v[i - 1].first);
      i++;
    }
    for (long long int i : finalans) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  }
  long long int flg = 0;
  long long int idx = -1;
  for (long long int i = 0; i <= n - 1; i++) {
    if (a1[i] == 1) {
      idx = i;
      flg = 1;
      break;
    }
  }
  long long int sum = 0;
  sort(v.begin(), v.end());
  long long int b[n + 2], a[n + 2];
  for (int i = 0; i <= n - 1; i++) {
    b[i] = v[i].first;
  }
  for (int i = 0; i < n; i++) {
    a[i] = v[i].second;
  }
  if ((b[0] + b[1]) != 0) {
    ckc[a[0]] = -b[2];
    ckc[a[1]] = -b[2];
    ckc[a[2]] = b[0] + b[1];
  } else if ((b[1] + b[2]) != 0) {
    ckc[a[1]] = -b[0];
    ckc[a[0]] = b[2] + b[1];
    ckc[a[2]] = -b[0];
  } else if ((b[2] + b[0]) != 0) {
    ckc[a[2]] = -b[1];
    ckc[a[1]] = b[0] + b[2];
    ckc[a[0]] = -b[1];
  }
  for (long long int i = 4; i <= n - 1; i++) {
    ckc[a[i]] = b[i - 1];
    ckc[a[i - 1]] = -b[i];
    i++;
  }
  for (long long int i = 0; i <= n - 1; i++) {
    cout << ckc[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
