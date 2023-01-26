#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
const int M = 5e4 + 9;
const int INF = 1e9;
int n, m, T;
char s[N];
int ans;
int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 1) + (x << 3) + (s ^ '0');
    s = getchar();
  }
  return f * x;
}
bool Check(int x) {
  int cnt = 0;
  while (x) {
    x /= 10;
    cnt++;
  }
  return cnt == n;
}
string C(int x) {
  string S = "";
  int a[N];
  for (int i = n; i >= 1; i--) {
    a[i] = x % 10;
    x /= 10;
  }
  for (int i = 1; i <= n; i++) S += char('1' + a[i] - 1);
  return S;
}
bool check(string S) {
  char X;
  for (int i = 1; i <= n; i++) {
    if (s[i] != 'X' and s[i] != '_') {
      if (s[i] != S[i - 1]) return false;
    }
    if (s[i] == '_') continue;
    if (s[i] == 'X') {
      if (!X)
        X = S[i - 1];
      else if (X != S[i - 1])
        return false;
    }
  }
  return true;
}
int main() {
  cin >> s + 1;
  n = strlen(s + 1);
  int x = 0;
  while (x <= INF) {
    if (!Check(x)) {
      x += 25;
      continue;
    }
    if (check(C(x))) ans++;
    x += 25;
  }
  cout << ans << endl;
  return 0;
}
