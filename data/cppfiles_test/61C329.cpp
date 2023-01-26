#include <bits/stdc++.h>
using namespace std;
long long int mod(long long int x) {
  return ((x % 1000000007 + 1000000007) % 1000000007);
}
long long int add(long long int a, long long int b) {
  return mod(mod(a) + mod(b));
}
long long int mul(long long int a, long long int b) {
  return mod(mod(a) * mod(b));
}
bool cmp(const int &a, const int &b) { return a > b; }
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string a;
    cin >> a;
    for (int i = 0; i < n; i++) {
      if (a[i] == 'R') {
        if (i - 1 >= 0 && a[i - 1] == '?') a[i - 1] = 'B';
        if (i < n - 1 && a[i + 1] == '?') a[i + 1] = 'B';
      }
      if (a[i] == 'B') {
        if (i - 1 >= 0 && a[i - 1] == '?') a[i - 1] = 'R';
        if (i < n - 1 && a[i + 1] == '?') a[i + 1] = 'R';
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == 'R') {
        if (i - 1 >= 0 && a[i - 1] == '?') a[i - 1] = 'B';
        if (i < n - 1 && a[i + 1] == '?') a[i + 1] = 'B';
      }
      if (a[i] == 'B') {
        if (i - 1 >= 0 && a[i - 1] == '?') a[i - 1] = 'R';
        if (i < n - 1 && a[i + 1] == '?') a[i + 1] = 'R';
      }
    }
    int flag = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] == '?') {
        flag = 0;
        break;
      }
    }
    if (flag == 1)
      cout << a << endl;
    else {
      string s(n, 'B');
      for (int i = 0; i < n; i = i + 2) {
        s[i] = 'R';
      }
      cout << s << endl;
    }
  }
  return 0;
}
