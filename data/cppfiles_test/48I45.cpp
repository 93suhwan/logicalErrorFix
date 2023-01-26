#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long M = 998244353;
const long long inf = 1e18 + 1;
void mistakes() {}
void change(long long i, long long j, long long k, vector<long long> &temp) {
  long long ele1 = temp[i];
  long long ele2 = temp[j];
  long long ele3 = temp[k];
  temp[i] = ele3;
  temp[j] = ele1;
  temp[k] = ele2;
}
void purple() {
  long long n;
  cin >> n;
  vector<long long> a, b;
  a.push_back(0);
  b.push_back(0);
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(x);
    b.push_back(x);
  }
  long long cnt = 0;
  sort(b.begin(), b.end());
  for (long long i = 0; i < n + 1; i++) {
    if (a[i] != b[i]) cnt++;
  }
  if (cnt == 0) {
    cout << "YES\n";
    return;
  }
  if ((cnt <= 2 and n < 4) or cnt > 9) {
    cout << "NO\n";
    return;
  }
  vector<long long> v;
  map<long long, long long> m;
  for (long long i = 1; i <= n; i++) {
    if (a[i] != i && !m[i]) {
      long long cnt = 0;
      long long ele = i;
      while (!m[ele]) {
        cnt++;
        m[ele] = 1;
        ele = a[ele];
      }
      v.push_back(cnt);
    }
  }
  n = ((long long)(v).size());
  if (n > 3) {
    cout << "NO\n";
    return;
  }
  long long have = 3;
  for (long long i = 0; i < n; i++) {
    long long need = (v[i] + 2) / 3;
    if (have < need) {
      cout << "NO\n";
      return;
    }
    have -= need;
  }
  cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    purple();
  }
}
