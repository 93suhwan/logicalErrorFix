#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pi = pair<ll, ll>;
void setIO(string name = "") {
  if ((int)(name).size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
ll gcd(ll a, ll b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b) return gcd(a % b, b);
  return gcd(a, b % a);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    int n = a.size();
    string b = a, c = a, d = a;
    b[0] = (a[0] == 'a') ? 'b' : 'a';
    c[n - 1] = (a[n - 1] == 'b') ? 'a' : 'b';
    d[0] = (a[0] == 'a') ? 'b' : 'a';
    d[n - 1] = (a[n - 1] == 'b') ? 'a' : 'b';
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == 'a' && a[i + 1] == 'b') {
        sum++;
      } else if (a[i] == 'b' && a[i + 1] == 'a') {
        sum--;
      }
    }
    if (sum == 0) {
      cout << a << endl;
      continue;
    }
    sum = 0;
    for (int i = 0; i < n - 1; i++) {
      if (b[i] == 'a' && b[i + 1] == 'b') {
        sum++;
      } else if (b[i] == 'b' && b[i + 1] == 'a') {
        sum--;
      }
    }
    if (sum == 0) {
      cout << b << endl;
      continue;
    }
    sum = 0;
    for (int i = 0; i < n - 1; i++) {
      if (c[i] == 'a' && c[i + 1] == 'b') {
        sum++;
      } else if (c[i] == 'b' && c[i + 1] == 'a') {
        sum--;
      }
    }
    if (sum == 0) {
      cout << c << endl;
      continue;
    }
    sum = 0;
    for (int i = 0; i < n - 1; i++) {
      if (d[i] == 'a' && d[i + 1] == 'b') {
        sum++;
      } else if (d[i] == 'b' && d[i + 1] == 'a') {
        sum--;
      }
    }
    if (sum == 0) {
      cout << d << endl;
      continue;
    }
  }
}
