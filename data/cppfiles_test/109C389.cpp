#include <bits/stdc++.h>
using namespace std;
long long mkItll(string str) {
  long long val = 0, len = str.size();
  for (long long i = 0; i < len; i++) {
    val = val * 10 + str[i] - 48;
  }
  return val;
}
bool isSubstring(string s1, string s2) {
  int M = s1.length();
  int N = s2.length();
  for (int i = 0; i <= N - M; i++) {
    int j;
    for (j = 0; j < M; j++)
      if (s2[i + j] != s1[j]) break;
    if (j == M) return 1;
  }
  return 0;
}
bool comp(string s1, string s2) {
  if (s1.size() < s2.size()) return true;
  return false;
}
int a[409], id[409];
bool bl(int x, int y) {
  if (a[x] < a[y]) return true;
  if (a[x] > a[y]) return false;
  return x > y;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    ans = (s[n - 1] - '0');
    long long x = 0;
    for (int i = 0; i < n - 1; i++) {
      x = s[i] - '0';
      if (x == 0)
        continue;
      else
        ans += (x + 1);
    }
    cout << ans << '\n';
  }
  return 0;
}
