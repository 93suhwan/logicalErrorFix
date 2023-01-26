#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long FastMod(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b = b >> 1;
  }
  return res;
}
int32_t main() {
  fast();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    char c;
    cin >> c;
    string str;
    cin >> str;
    bool flag = true;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      if (str[i] != c) {
        flag = false;
        cnt++;
      }
    }
    if (flag) {
      cout << 0 << "\n";
      continue;
    }
    if (str[n - 1] == c) {
      cout << 1 << "\n";
      cout << n << "\n";
      continue;
    }
    set<long long> s;
    for (long long i = 0; i < n; i++) {
      if (str[i] != c) s.insert(i + 1);
    }
    long long ele;
    flag = false;
    for (long long i = 2; i <= n; i++) {
      long long val = i;
      bool check = true;
      for (long long j = val; j <= n; j += val) {
        if (s.find(j) != s.end()) {
          check = false;
          break;
        }
      }
      if (check) {
        flag = true;
        ele = val;
        break;
      }
    }
    if (flag) {
      cout << 1 << "\n";
      cout << ele << "\n";
      continue;
    }
    cout << 2 << "\n";
    cout << n - 1 << " " << n << "\n";
  }
  return 0;
}
