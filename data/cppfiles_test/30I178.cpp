#include <bits/stdc++.h>
using namespace std;
template <class T, class T1>
T1 power(T1 a, T b) {
  if (!b) return 1;
  T1 y = 1;
  while (b > 1) {
    if (b & 1) y *= a;
    a *= a;
    b = b >> 1;
  }
  return a * y;
}
template <class T>
T gcd(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void seive(vector<int>& prime, int n) {
  vector<bool> trace(n + 1, false);
  for (int i = 2; i * i <= n; i++) {
    if (trace[i]) continue;
    for (int j = 2 * i; j <= n; j += i) {
      if (!trace[j]) trace[j] = true;
    }
  }
  for (int i = 2; i < n; i++)
    if (!trace[i]) prime.push_back(i);
}
long long run(string& s, int i, int j, char c) {
  char del = '#';
  long long res = 0;
  while (i <= j) {
    if (s[i] == s[j]) {
      i++;
      j--;
    } else if (c != '#') {
      if (s[i] == c)
        i++;
      else if (s[j] == c)
        j--;
      else
        return INT_MAX;
      res++;
    } else {
      res += min(run(s, i + 1, j, s[i]) + 1, run(s, i, j - 1, s[j]) + 1);
      break;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    } else if (n == 2) {
      cout << (s[0] != s[1]) << "\n";
      continue;
    }
    int startmax = 0;
    int endmin = n - 1;
    for (int i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) {
        startmax = i;
        break;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] != s[i + 1]) {
        endmin = i;
        break;
      }
    }
    long long res = INT_MAX;
    for (int i = 0; i <= startmax; i++) {
      for (int j = n - 1; j >= endmin; j--) {
        if (s[i] != s[j]) continue;
        char c = '#';
        long long ans = 0;
        if (i == startmax) {
          c = s[0];
          ans = startmax;
        }
        if (j == endmin) {
          if (c != '#') break;
          c = s[n - 1];
          ans = n - endmin - 1;
        }
        res = min(res, run(s, i, j, c) + ans);
      }
    }
    if (res >= INT_MAX)
      cout << -1 << "\n";
    else
      cout << res << "\n";
  }
  return 0;
}
