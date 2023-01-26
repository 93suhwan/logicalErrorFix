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
    long long score2 = 0;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      dq.push_back(x);
      score2 += x;
    }
    sort(dq.begin(), dq.end());
    long long score = 0;
    long long score1 = 0;
    for (int i = n - 1; i >= (n - 2 * k); i -= 2) {
      score2 = score2 - dq[i] - dq[i - 1];
      if (dq[i] == dq[i - 1]) score2++;
    }
    int ii, ij, op;
    for (ii = 0, ij = ceil(n / 2), op = 0; op < k and ii < n / 2;
         op++, ii++, ij++) {
      if (dq[ij] <= dq[ii]) break;
    }
    for (; ii < n / 2; ij++, ii++) {
      score1 += dq[ii] + dq[ij];
    }
    if (n & 1) score1 += dq[(n / 2) + 1];
    for (int i = 0; i < k; i++) {
      score += dq.front() / dq.back();
      dq.pop_front();
      dq.pop_back();
    }
    for (int i = 0; i < dq.size(); i++) {
      score += dq[i];
    }
    cout << min(score1, min(score2, score)) << endl;
  }
}
