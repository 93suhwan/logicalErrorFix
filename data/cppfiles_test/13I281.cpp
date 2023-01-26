#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(vector<T> a) {
  cout << a[0];
  for (long long i = 1; i < a.size(); ++i) {
    cout << ' ' << a[i];
  }
  cout << "\n";
}
int sum_vector(vector<int> v) { return accumulate(v.begin(), v.end(), 0); }
void sort_vector(vector<int> &v) { sort(v.begin(), v.end()); }
void sort_comp(vector<int> &v, bool func(int, int)) {
  sort(v.begin(), v.end(), func);
}
bool comp(array<long long, 2> a, array<long long, 2> b) { return a[1] < b[1]; }
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
const int mxn = 2e5 + 7;
const int d = 20;
const int mill = 1e6 + 3;
const long long mod = 1e9 + 7;
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
int mat[105][105];
void fillmat(int r, int c, int v, int h) {
  r -= r % 2;
  c -= c % 2;
  for (int i = 0; i < v / 2; i++) {
    int rr = i / (c / 2) * 2;
    int cc = i % (c / 2) * 2;
    mat[rr][cc] = (rr / 2) % 2;
    mat[rr + 1][cc] = (rr / 2) % 2;
    mat[rr][cc + 1] = 1 - (rr / 2) % 2;
    mat[rr + 1][cc + 1] = 1 - (rr / 2) % 2;
  }
  for (int i = v / 2; i < v / 2 + h / 2; i++) {
    int rr = i / (c / 2) * 2;
    int cc = i % (c / 2) * 2;
    mat[rr][cc] = 3 + (cc / 2) % 2;
    mat[rr][cc + 1] = 3 + (cc / 2) % 2;
    mat[rr + 1][cc] = 4 - (cc / 2) % 2;
    mat[rr + 1][cc + 1] = 4 - (cc / 2) % 2;
  }
}
void printmat(int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << char('a' + mat[i][j]);
    }
    cout << "\n";
  }
}
void solve() {
  int r, c, h, v;
  cin >> r >> c >> h;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      mat[i][j] = 0;
    }
  }
  v = r * c / 2 - h;
  int two2 = (r / 2) * (c / 2);
  if (r % 2) {
    h -= c / 2;
    if (h >= 0 && h % 2 == 0 && v % 2 == 0) {
      cout << "YES\n";
      for (int i = 0; i < c; i += 2) {
        mat[r - 1][i] = 24 + (i % 4 == 2);
        mat[r - 1][i + 1] = 24 + (i % 4 == 2);
      }
      fillmat(r, c, v, h);
      printmat(r, c);
      return;
    } else {
      cout << "NO\n";
      return;
    }
  }
  if (c % 2) {
    v -= r / 2;
    if (v >= 0 && h % 2 == 0 && v % 2 == 0) {
      cout << "YES\n";
      for (int i = 0; i < r; i += 2) {
        mat[i][c - 1] = 24 + (i % 4 == 2);
        mat[i + 1][c - 1] = 24 + (i % 4 == 2);
      }
      fillmat(r, c, v, h);
      printmat(r, c);
      return;
    } else {
      cout << "NO\n";
      return;
    }
  }
  if (h % 2 == 0 && v % 2 == 0) {
    cout << "YES\n";
    fillmat(r, c, v, h);
    printmat(r, c);
    return;
  } else {
    cout << "NO\n";
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  for (int ii = 1; ii <= t; ii++) {
    solve();
    cout << "\n";
  }
  return 0;
}
