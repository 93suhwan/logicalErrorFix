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
  auto compare = [](string perm) {
    string alphabet = perm + "defghijklmnopqrstuvwxyz";
    vector<int> where(26);
    for (int i = 0; i < 26; i++) where[alphabet[i] - 'a'] = i;
    auto comp = [&](char a, char b) -> bool {
      return where[a - 'a'] < where[b - 'a'];
    };
    return comp;
  };
  vector<string> perms = {"abc", "acb", "bac", "bca", "cab", "cba"};
  string best = s;
  for (auto perm : perms) {
    if (perm == t) continue;
    string temp = s;
    sort(temp.begin(), temp.end(), compare(perm));
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
