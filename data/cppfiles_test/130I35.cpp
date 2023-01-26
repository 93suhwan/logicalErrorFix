#include <bits/stdc++.h>
using namespace std;
double PI = (acos(-1));
long long md = 1000000007;
long long pw(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m);
    m = (m * m);
    b /= 2;
  }
  return c;
}
long long pwmd(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = ((c * m)) % md;
    m = (m * m) % md;
    b /= 2;
  }
  return c;
}
long long modinv(long long n) { return pwmd(n, md - 2); }
long long nc2(long long n) { return (1ll * n * (n - 1)) / 2; }
bool prime(long long a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) return false;
  }
  return true;
}
long long ceel(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n / 3);
  for (long long i = 0; i < n / 3; i++) {
    cout << "? " << (3 * i) + 1 << " " << (3 * i) + 2 << " " << (3 * i) + 3
         << endl;
    cin >> a[i];
  }
  long long x;
  for (long long i = 1; i < n / 3; i++) {
    if (a[i] != a[i - 1]) {
      x = i - 1;
      break;
    }
  }
  vector<long long> v(4);
  v[0] = a[x];
  cout << "? " << (3 * x) + 2 << " " << (3 * x) + 3 << " " << (3 * x) + 4
       << endl;
  cin >> v[1];
  cout << "? " << (3 * x) + 3 << " " << (3 * x) + 4 << " " << (3 * x) + 5
       << endl;
  cin >> v[2];
  v[3] = a[x + 1];
  long long p, q;
  if (v[0] == 0) {
    for (long long i = 1; i < 4; i++) {
      if (v[i] != v[i - 1]) {
        p = (3 * x) + i;
        q = (3 * x) + i + 3;
        break;
      }
    }
  } else {
    for (long long i = 1; i < 4; i++) {
      if (v[i] != v[i - 1]) {
        q = (3 * x) + i;
        p = (3 * x) + i + 3;
        break;
      }
    }
  }
  vector<long long> ans;
  ans.push_back(p);
  for (long long i = 1; i < 7; i++) {
    if ((3 * x) + i != p && (3 * x) + i != q) {
      cout << "? " << (3 * x) + i << " " << p << " " << q << endl;
      long long q;
      cin >> q;
      if (q == 0) {
        ans.push_back((3 * x) + i);
      }
    }
  }
  for (long long i = 0; i < n / 3; i++) {
    if (i != x && i != x + 1) {
      if (v[i] == 0) {
        long long u, v;
        cout << "? " << q << " " << (3 * i) + 1 << " " << (3 * i) + 2 << endl;
        cin >> u;
        cout << "? " << q << " " << (3 * i) + 1 << " " << (3 * i) + 3 << endl;
        cin >> v;
        if (u == 0 && v == 0) {
          ans.push_back((3 * i) + 1);
          ans.push_back((3 * i) + 2);
          ans.push_back((3 * i) + 3);
        } else if (u == 0 && v == 1) {
          ans.push_back((3 * i) + 1);
          ans.push_back((3 * i) + 2);
        } else if (u == 1 && v == 1) {
          ans.push_back((3 * i) + 2);
          ans.push_back((3 * i) + 3);
        } else {
          ans.push_back((3 * i) + 1);
          ans.push_back((3 * i) + 3);
        }
      } else {
        long long u, v;
        cout << "? " << p << " " << (3 * i) + 1 << " " << (3 * i) + 2 << endl;
        cin >> u;
        cout << "? " << p << " " << (3 * i) + 1 << " " << (3 * i) + 3 << endl;
        cin >> v;
        if (u == 0 && v == 0) {
          ans.push_back((3 * i) + 1);
        } else if (u == 1 && v == 0) {
          ans.push_back((3 * i) + 3);
        } else if (u == 0 && v == 1) {
          ans.push_back((3 * i) + 2);
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << "! " << (int)ans.size();
  for (long long i = 0; i < (int)ans.size(); i++) cout << " " << ans[i];
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
  return 0;
}
