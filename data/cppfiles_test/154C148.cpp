#include <bits/stdc++.h>
using namespace std;
long long t;
int min(long i, long j) {
  if (i >= j) {
    return j;
  }
  return i;
}
int max(long i, long j) {
  if (i >= j) {
    return i;
  }
  return j;
}
long long Mex(vector<long long> S) {
  long long mex = 0;
  if (S[0] > 0) {
    return 0;
  }
  for (int i = 1; i < S.size(); ++i) {
    if (S[i] - S[i - 1] >= 2) {
      return (S[i - 1] + 1);
    }
    mex = S[i] + 1;
  }
  return mex;
}
long long gcd(long long a, long long b) {
  for (long long i = b; i > 1; --i) {
    if (a % i == 0 && b % i == 0) {
      return i;
    }
  }
  return 1;
}
int NOD(int a, int b) {
  int div;
  if (a == b) return a;
  int d = a - b;
  if (d < 0) {
    d = -d;
    div = NOD(a, d);
  } else {
    div = NOD(b, d);
  }
  return div;
}
long long dist(long long x1, long long y1, long long x2, long long y2) {
  long long x = x1 - x2;
  if (x < 0) x *= -1;
  long long y = y1 - y2;
  if (y < 0) y *= -1;
  return x + y;
}
bool del(long long x) {
  for (long long i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
void find() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (a == b + c || b == a + c || c == a + b) {
    cout << "YES" << endl;
    return;
  }
  if (a == b & c % 2 == 0) {
    cout << "YES" << endl;
    return;
  }
  if (c == b & a % 2 == 0) {
    cout << "YES" << endl;
    return;
  }
  if (a == c & b % 2 == 0) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}
int main() {
  cin >> t;
  while (t--) {
    find();
  }
  return 0;
}
