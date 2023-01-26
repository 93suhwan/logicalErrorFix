#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(vector<T> a) {
  int n = a.size();
  for (long long i = 0; i < n; ++i) {
    cout << a[i] << (i == n - 1 ? "\n" : " ");
  }
}
int sum_vector(vector<int> v) { return accumulate(v.begin(), v.end(), 0); }
void sort_vector(vector<int> &v) { sort(v.begin(), v.end()); }
void sort_comp(vector<int> &v, bool func(int, int)) {
  sort(v.begin(), v.end(), func);
}
bool comp(int a, int b) { return a < b; }
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  while (a) {
    long long temp = a;
    a = b % a;
    b = temp;
  }
  return abs(b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
string binary(long long num) {
  string ans = "";
  do {
    ans = to_string(num % 2) + ans;
    num /= 2;
  } while (num);
  return ans;
}
const int mxn = 5e5 + 7;
const int d = 18;
const int mill = 1e6 + 3;
const long long mod = 998244353;
long long pwr(long long num, long long p) {
  long long res = 1;
  while (p > 0) {
    if (p & 1) res = (res * num) % mod;
    num = (num * num) % mod;
    p /= 2;
  }
  return res;
}
long long inverse(long long num) { return pwr(num, mod - 2); }
long long get_rand(long long n) { return ((rand() << 15) + rand()) % n; }
int query(int i, int j, int k) {
  cout << "? " << i << " " << j << " " << k << endl;
  int r;
  cin >> r;
  if (r == -1) {
    exit(0);
  }
  return r;
}
void solve() {
  int n;
  cin >> n;
  vector<int> trio(n / 3 + 3);
  vector<int> know(n + 3, -1);
  int groupi;
  int groupc;
  for (int i = 3; i <= n; i += 3) {
    trio[i / 3] = query(i, i - 1, i - 2);
    if (trio[i / 3] == 0) groupi = i / 3 - 1;
    if (trio[i / 3] == 1) groupc = i / 3 - 1;
  }
  int sm = 0;
  int i1i2c1 = query(groupi * 3 + 1, groupi * 3 + 2, groupc * 3 + 1);
  int i1i2c2 = query(groupi * 3 + 1, groupi * 3 + 2, groupc * 3 + 2);
  int i1i2c3 = query(groupi * 3 + 1, groupi * 3 + 2, groupc * 3 + 3);
  int i1i3c1 = query(groupi * 3 + 1, groupi * 3 + 3, groupc * 3 + 1);
  int i1i3c2 = query(groupi * 3 + 1, groupi * 3 + 3, groupc * 3 + 2);
  int i1i3c3 = query(groupi * 3 + 1, groupi * 3 + 3, groupc * 3 + 3);
  int xi1i2c1;
  int xi1i2c2;
  int xi1i2c3;
  int xi1i3c1;
  int xi1i3c2;
  int xi1i3c3;
  bool b1 = 0;
  bool b2 = 0;
  bool b3 = 0;
  bool b4 = 0;
  bool b5 = 0;
  bool b6 = 0;
  int c1, c2, c3, i1, i2, i3;
  bool f = 0;
  for (c1 = 0; c1 <= 1 && !f; c1++) {
    for (c2 = 0; c2 <= 1 && !f; c2++) {
      for (c3 = 0; c3 <= 1 && !f; c3++) {
        for (i1 = 0; i1 <= 1 && !f; i1++) {
          for (i2 = 0; i2 <= 1 && !f; i2++) {
            for (i3 = 0; i3 <= 1 && !f; i3++) {
              if (c1 + c2 + c3 < 2) continue;
              if (i1 + i2 + i3 > 1) continue;
              xi1i2c1 = (i1 + i2 + c1 + 1) / 3;
              xi1i2c2 = (i1 + i2 + c2 + 1) / 3;
              xi1i2c3 = (i1 + i2 + c3 + 1) / 3;
              xi1i3c1 = (i1 + i3 + c1 + 1) / 3;
              xi1i3c2 = (i1 + i3 + c2 + 1) / 3;
              xi1i3c3 = (i1 + i3 + c3 + 1) / 3;
              b1 = (xi1i2c1 == i1i2c1);
              b2 = (xi1i2c2 == i1i2c2);
              b3 = (xi1i2c3 == i1i2c3);
              b4 = (xi1i3c1 == i1i3c1);
              b5 = (xi1i3c2 == i1i3c2);
              b6 = (xi1i3c3 == i1i3c3);
              if (b1 && b2 && b3 && b4 && b5 && b6) {
                f = 1;
                break;
              }
            }
            if (f) break;
          }
          if (f) break;
        }
        if (f) break;
      }
      if (f) break;
    }
    if (f) break;
  }
  know[groupi * 3 + 1] = i1;
  know[groupi * 3 + 2] = i2;
  know[groupi * 3 + 3] = i3;
  int truei = 0;
  int truec = 0;
  if (i1 == 0)
    truei = groupi * 3 + 1;
  else if (i2 == 0)
    truei = groupi * 3 + 2;
  if (i1 + i2 + i3 == 0) {
    int a12 = query(groupi * 3 + 1, groupc * 3 + 1, groupc * 3 + 2);
    int a13 = query(groupi * 3 + 1, groupc * 3 + 1, groupc * 3 + 3);
    know[groupc * 3 + 1] = 0;
    know[groupc * 3 + 2] = 0;
    know[groupc * 3 + 3] = 0;
    if (a12 == 1) {
      know[groupc * 3 + 1] = 1;
      know[groupc * 3 + 2] = 1;
    }
    if (a13 == 1) {
      know[groupc * 3 + 1] = 1;
      know[groupc * 3 + 3] = 1;
    }
    if (a13 == 0 && a12 == 0) {
      know[groupc * 3 + 1] = 0;
      know[groupc * 3 + 2] = 1;
      know[groupc * 3 + 3] = 1;
    }
  } else {
    know[groupc * 3 + 1] = c1;
    know[groupc * 3 + 2] = c2;
    know[groupc * 3 + 3] = c3;
  }
  if (c1 == 1)
    truec = groupc * 3 + 1;
  else if (c2 == 1)
    truec = groupc * 3 + 2;
  int x, y;
  for (int i = 3; i <= n; i += 3) {
    if (know[i] != -1) continue;
    if (trio[i / 3] == 1) {
      x = query(truei, i, i - 1);
      y = query(truei, i, i - 2);
      know[i] = 0;
      know[i - 1] = 0;
      know[i - 2] = 0;
      if (x == 1) {
        know[i] = 1;
        know[i - 1] = 1;
      }
      if (y == 1) {
        know[i] = 1;
        know[i - 2] = 1;
      }
      if (x == 0 && y == 0) {
        know[i] = 0;
        know[i - 1] = 1;
        know[i - 2] = 1;
      }
    } else {
      x = query(truec, i, i - 1);
      y = query(truec, i, i - 2);
      know[i] = 1;
      know[i - 1] = 1;
      know[i - 2] = 1;
      if (x == 0) {
        know[i] = 0;
        know[i - 1] = 0;
      }
      if (y == 0) {
        know[i] = 0;
        know[i - 2] = 0;
      }
      if (x == 1 && y == 1) {
        know[i] = 1;
        know[i - 1] = 0;
        know[i - 2] = 0;
      }
    }
  }
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (know[i] == 0) count++;
  }
  cout << "! " << count << " ";
  for (int i = 1; i <= n; i++) {
    if (know[i] == 0) cout << i << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  for (int ii = 1; ii <= t; ii++) {
    solve();
  }
  return 0;
}
