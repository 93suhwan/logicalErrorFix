#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long maxu = 200005;
void google(long long t) { cout << "Case #" << t << ": "; }
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long fun(long long a, long long b) {
  if (b == 0)
    return 1;
  else if (a == 1)
    return 1;
  long long temp = fun(a, b / 2) % 1000000007;
  temp = (temp * temp) % 1000000007;
  if (b % 2 == 1) temp = (temp * a) % 1000000007;
  return temp % 1000000007;
}
long long inv(long long a, long long b) {
  return (a * fun(b, 1000000007 - 2)) % 1000000007;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, k = 0, n, m, l = 0;
  long long t = 1;
  long long T = 1;
  cin >> T;
  for (t = 1; t <= T; t++) {
    cin >> n;
    vector<long long> v(n + 1, -1);
    vector<long long> a((n / 3) + 1, -1);
    long long r0 = -1;
    long long r1 = -1;
    long long imp = -1;
    long long not_imp = -1;
    for (i = 1; i <= n; i += 3) {
      cout << "? " << i << " " << i + 1 << " " << i + 2 << endl;
      long long r;
      cin >> r;
      a[(i + 2) / 3] = r;
      if (r == 0) {
        r0 = i;
      }
      if (r == 1) {
        r1 = i;
      }
    }
    vector<long long> b(3, -1);
    cout << "? " << r1 << " " << r1 + 1 << " " << r0 << endl;
    cin >> b[0];
    cout << "? " << r1 << " " << r1 + 1 << " " << r0 + 1 << endl;
    cin >> b[1];
    cout << "? " << r1 << " " << r1 + 1 << " " << r0 + 2 << endl;
    cin >> b[2];
    long long cnt0 = 0;
    for (i = 0; i < 3; i++) {
      if (b[i] == 0) cnt0++;
    }
    if (cnt0 == 0) {
      not_imp = r1;
    } else {
      not_imp = r1 + 2;
    }
    long long cnt1 = 0;
    vector<long long> c(3, -1);
    cout << "? " << not_imp << " " << r0 << " " << r0 + 1 << endl;
    cin >> c[0];
    cout << "? " << not_imp << " " << r0 << " " << r0 + 2 << endl;
    cin >> c[1];
    cout << "? " << not_imp << " " << r0 + 2 << " " << r0 + 1 << endl;
    cin >> c[2];
    for (i = 0; i < 3; i++) {
      if (c[i] == 1) cnt1++;
    }
    if (cnt1 == 0) {
      imp = r0;
    } else {
      if (c[0] == 1)
        imp = r0 + 2;
      else if (c[1] == 1)
        imp = r0 + 1;
      else
        imp = r0;
    }
    v[not_imp] = 1;
    v[imp] = 0;
    vector<long long> ans;
    for (i = 1; i <= n; i += 3) {
      if (i == imp || i + 1 == imp || i + 2 == imp) {
        for (j = i; j < i + 3; j++) {
          if (j == imp) continue;
          cout << "? " << j << " " << imp << " " << not_imp << endl;
          cin >> v[j];
        }
        continue;
      } else if (i == not_imp || i + 1 == not_imp || i + 2 == not_imp) {
        for (j = i; j < i + 3; j++) {
          if (j == not_imp) continue;
          cout << "? " << j << " " << imp << " " << not_imp << endl;
          cin >> v[j];
        }
        continue;
      } else if (a[(i + 2) / 3]) {
        cout << "? " << i << " " << i + 1 << " " << not_imp << endl;
        long long r;
        cin >> r;
        if (r == 1) {
          v[i + 2] = 0;
          cout << "? " << i << " " << imp << " " << not_imp << endl;
          cin >> r;
          v[i] = r;
          v[i + 1] = (r ^ 1);
        } else {
          v[i + 1] = 0;
          v[i] = 0;
          cout << "? " << i + 2 << " " << imp << " " << not_imp << endl;
          cin >> r;
          v[i + 2] = r;
        }
      } else {
        cout << "? " << i << " " << i + 1 << " " << imp << endl;
        long long r;
        cin >> r;
        if (r == 0) {
          v[i + 2] = 1;
          cout << "? " << i << " " << imp << " " << not_imp << endl;
          cin >> r;
          v[i] = r;
          v[i + 1] = (r ^ 1);
        } else {
          v[i + 1] = 1;
          v[i] = 1;
          cout << "? " << i + 2 << " " << imp << " " << not_imp << endl;
          cin >> r;
          v[i + 2] = r;
        }
      }
    }
    for (i = 1; i <= n; i++)
      if (v[i] == 0) ans.push_back(i);
    k = ans.size();
    cout << "! " << k << " ";
    for (auto u : ans) cout << u << " ";
    cout << endl;
  }
  return 0;
}
