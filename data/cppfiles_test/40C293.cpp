#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, b, c, d, m, n, p, q, r, x, y, z, aa, bb, cc, dd;
  double pp, qq, rr, xx, yy, zz;
  char ch1, ch2, ch3, ch4, ch5;
  long long int i, j, k, l;
  long long int cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, sum = 0, sum2 = 0,
                mx = LLONG_MIN, mn = LLONG_MAX;
  long long int flag = 0, flag2 = 0;
  vector<long long int> vec1, vec2, vec3;
  string s1, s2, s3;
  cin >> n;
  for (long long int i = (long long int)(0); i < (long long int)(n); ++i) {
    cin >> x;
    vec1.push_back(x);
  }
  for (long long int i = (long long int)(0); i < (long long int)(n); ++i) {
    cin >> x;
    vec2.push_back(x);
  }
  if (n == 1) {
    cout << "0\n";
    return;
  }
  for (long long int i = (long long int)(n - 1); i >= (long long int)(0); --i) {
    sum += vec1[i];
    vec1[i] = sum;
  }
  sum = 0;
  for (long long int i = (long long int)(0); i < (long long int)(n); ++i) {
    sum += vec2[i];
    vec2[i] = sum;
  }
  for (long long int i = (long long int)(0); i < (long long int)(n - 2); ++i) {
    mx = max(vec2[i], vec1[i + 2]);
    mn = min(mn, mx);
  }
  mn = min(mn, vec1[1]);
  mn = min(mn, vec2[n - 2]);
  cout << mn << endl;
}
int main() {
  ios::sync_with_stdio(false);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
