#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long i = 0, j = n - 1;
  long long ans = LLONG_MAX;
  bool flag = false;
  char x;
  while (i < j) {
    if (s[i] == s[j]) {
      i++;
      j--;
      continue;
    } else {
      break;
    }
  }
  if (i >= j) {
    cout << 0 << "\n";
    return;
  }
  x = s[i];
  long long c = 0;
  long long a = i, b = j;
  while (i < j) {
    if (s[i] == s[j]) {
      i++;
      j--;
      continue;
    } else {
      if (s[i] == x) {
        i++;
        c++;
      } else if (s[j] == x) {
        j--;
        c++;
      } else {
        flag = true;
        break;
      }
    }
  }
  if (flag) {
    ans = -1;
  } else {
    ans = min(ans, c);
  }
  i = a;
  j = b;
  x = s[j];
  c = 0;
  flag = false;
  while (i < j) {
    if (s[i] == s[j]) {
      i++;
      j--;
      continue;
    } else {
      if (s[i] == x) {
        i++;
        c++;
      } else if (s[j] == x) {
        j--;
        c++;
      } else {
        flag = true;
        break;
      }
    }
  }
  if (!flag) {
    if (ans == -1) {
      ans = c;
    } else
      ans = min(ans, c);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
