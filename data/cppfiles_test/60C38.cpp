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
      m &= a[i];
    }
    cout << m << endl;
  }
  return 0;
}
