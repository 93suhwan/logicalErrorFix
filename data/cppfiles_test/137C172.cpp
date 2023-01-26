#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
const long long maxn = 2e5 + 10;
bool check(string a, string b) {
  for (long long i = 0; i + a.size() <= b.size(); ++i) {
    if (i != 0 && b[i - 1] == '0') return false;
    long long f = 1;
    for (long long j = 0; j < a.size(); ++j) {
      if (a[j] != b[i + j]) {
        f = 0;
        break;
      }
    }
    if (f)
      for (long long j = i + a.size(); j < b.size(); ++j) {
        if (b[j] == '0') {
          f = 0;
          break;
        }
      }
    if (f) return true;
  }
  return false;
}
string turn2(long long x) {
  string s = "";
  while (x) {
    long long now = x % 2;
    s = (char)(now + '0') + s;
    x /= 2;
  }
  return s;
}
inline void solve() {
  long long x = read(), y = read();
  string a1, a2;
  a1 = a2 = turn2(x);
  string b = turn2(y);
  if (b.back() == '0') {
    if (a1 == b)
      puts("YES");
    else
      puts("NO");
    return;
  }
  if (a1.back() == '1') {
    reverse(a2.begin(), a2.end());
    if (check(a1, b)) {
      puts("YES");
      return;
    }
    if (check(a2, b)) {
      puts("YES");
      return;
    }
    puts("NO");
    return;
  } else {
    string a3, a4;
    a3 = a4 = a1 + '1';
    reverse(a4.begin(), a4.end());
    while (a1.back() == '0') {
      a1.pop_back();
    }
    a2 = a1;
    reverse(a2.begin(), a2.end());
    if (check(a1, b)) {
      puts("YES");
      return;
    }
    if (check(a2, b)) {
      puts("YES");
      return;
    }
    if (check(a3, b)) {
      puts("YES");
      return;
    }
    if (check(a4, b)) {
      puts("YES");
      return;
    }
    puts("NO");
    return;
  }
}
signed main() {
  solve();
  return 0;
}
