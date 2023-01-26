#include <bits/stdc++.h>
using namespace std;
template <class C>
void min_self(C &a, C b) {
  a = min(a, b);
}
template <class C>
void max_self(C &a, C b) {
  a = max(a, b);
}
const long long MOD = 1000000007;
template <class T1, class T2>
void add(T1 &x, T2 y, long long m = MOD) {
  x += y;
  if (x >= m) x -= m;
}
template <class T1, class T2>
void sub(T1 &x, T2 y, long long m = MOD) {
  x -= y;
  if (x < 0) x += m;
}
long long mod(long long n, long long m = MOD) {
  n %= m;
  if (n < 0) n += m;
  return n;
}
const int MAXN = 1e5 + 5;
const int LOGN = 21;
const long long INF = 1e16;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void solve() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  vector<int> fr(26);
  int n = s.size();
  for (int i = 0; i < n; i++) fr[s[i] - 'a']++;
  if (!fr[0] || !fr[1] || !fr[2]) {
    cout << s, cout << "\n";
    return;
  }
  vector<string> perms = {"abc", "acb", "bac", "bca", "cab", "cba"};
  string best = "";
  for (auto perm : perms) {
    if (t == perm) continue;
    string temp = "";
    string alphabet = perm + "defghijklmnopqrstuvwxyz";
    for (int j = 0; j < 26; j++) {
      int c = alphabet[j] - 'a';
      for (int k = 0; k < fr[c]; k++) temp += alphabet[j];
    }
    if (best == "") best = temp;
    best = min(best, temp);
  }
  cout << best, cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; test++) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
