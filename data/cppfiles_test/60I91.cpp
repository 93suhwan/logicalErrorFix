#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (a == 0) ? b : gcd(b % a, a); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void p(vector<int> v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
}
int minmax(vector<int> a, int i, int j) {
  int tmp = i;
  int m = a[i] & a[j];
  for (; i < j; i++) {
    a[i] = a[j - i] = a[i] & a[j - i];
  }
  for (i = tmp; i < j; i++) {
    m = max(m, a[i]);
  }
  return m;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m = INT_MAX;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        m = min(m, minmax(a, i, j));
      }
    }
    cout << m << endl;
  }
  return 0;
}
