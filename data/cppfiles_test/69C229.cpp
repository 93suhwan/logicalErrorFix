#include <bits/stdc++.h>
using namespace std;
int check(string a, string b) {
  int n = a.size();
  int m = b.size();
  int rem = 0;
  int add = 0;
  int i = 0;
  int j = 0;
  while (i < n && j < m) {
    if (a[i] == b[j]) {
      i++;
      j++;
    } else {
      rem++;
      i++;
    }
  }
  while (i < n) {
    i++;
    add++;
  }
  while (j < m) {
    j++;
    add++;
  }
  return rem + add;
}
void solve() {
  int n;
  cin >> n;
  long long int M = 1e17;
  int mx = INT_MAX;
  for (int i = 0; i <= 62; i++) {
    string a = to_string(n);
    string b = to_string((long long int)(pow(2, i)));
    mx = min(mx, check(a, b));
  }
  cout << mx;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
