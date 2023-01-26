#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long moD = 998244353;
const long long INF = 1e18;
const long long inf = 1e9;
long double pi = 2 * acos(0.0);
long long expo_mania(long long y, long long x) {
  if (x == 0) return 1;
  if (x == 1)
    return y;
  else if (!(x & 1))
    return expo_mania(y * y, x / 2);
  else
    return expo_mania(y * y, x / 2) * y;
}
int tarr[1];
void vuid() {
  tarr[1] = 1;
  for (int i = 2; i * 2 <= 1000080; i++) {
    tarr[i * 2] = 1;
  }
  for (int i = 3; i <= 1001; i += 2) {
    for (int j = 2; j * i <= 1000080; j++) {
      tarr[j * i] = 1;
    }
  }
}
double radian(double x) {
  double ans = x * pi;
  ans = ans / (double)180;
  return ans;
}
string ss;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end(), greater<int>());
    long long sum = accumulate(v.begin(), v.end(), 0ll);
    for (int i = 0; i < k; i++) {
      sum -= (v[i] + v[i + k]);
      if (v[i] == v[i + k]) sum++;
    }
    cout << sum << endl;
  }
}
