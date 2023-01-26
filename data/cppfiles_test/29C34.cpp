#include <bits/stdc++.h>
using namespace std;
const long long mx = 300009;
struct bit {
  long long n;
  long long tree[mx];
  void update(long long ind, long long value) {
    for (long long i = ind; i <= n; i += (i & -i)) {
      tree[i] += value;
    }
  }
  long long query(long long ind) {
    long long sum = 0;
    for (long long i = ind; i > 0; i -= (i & -i)) {
      sum += tree[i];
    }
    return sum;
  }
} a, b;
long long s[mx], t[mx];
long long pre[mx];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  vector<long long> v(n + 5);
  long long maxi = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> v[i];
    maxi = max(maxi, v[i]);
    pre[i] = pre[i - 1] + v[i];
  }
  a.n = b.n = maxi;
  for (long long i = 1; i <= n; i++) {
    s[i] = s[i - 1] + (i - 1) * v[i] - a.query(v[i]);
    for (long long j = 1; j <= maxi / v[i]; j++) {
      long long suru = v[i] * j;
      long long ses = v[i] * (j + 1) - 1;
      ses = min(ses, maxi);
      a.update(suru, v[i]);
      ;
    }
  }
  for (long long i = 1; i <= n; i++) {
    t[i] = t[i - 1] + pre[i - 1];
    for (long long j = 1; j <= maxi / v[i]; j++) {
      long long suru = v[i] * j;
      long long ses = v[i] * (j + 1) - 1;
      ses = min(ses, maxi);
      t[i] -= (b.query(ses) - b.query(suru - 1)) * (v[i] * j);
    }
    b.update(v[i], 1);
  }
  for (long long i = 1; i <= n; i++) cout << s[i] + t[i] << ' ';
}
