#include <bits/stdc++.h>
using namespace std;
set<long long int> v;
void fun(long long int A, long long int B, long long int a, long long int b) {
  long long int ct = 0;
  ct = abs(a - A);
  for (long long int i = min(B, a); i >= 0; i--) {
    long long int x = i;
    if (A < (a - i)) break;
    long long int y = b - (B - i);
    v.insert(x + y);
  }
}
void solve(long long int t) {
  long long int i, j, n, m, k;
  string s;
  v.clear();
  long long int a, b;
  cin >> a >> b;
  n = a + b;
  if (n & 1) {
    fun(n / 2, 1 + n / 2, a, b);
    fun(1 + n / 2, n / 2, a, b);
  } else {
    fun(n / 2, n / 2, a, b);
  }
  cout << v.size() << endl;
  set<long long int>::iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return;
}
int main() {
  long long int t, tt = 1;
  cin >> tt;
  for (t = 1; t <= tt; t++) solve(t);
  return 0;
}
