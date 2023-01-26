#include <bits/stdc++.h>
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
void read(vector<T>& a, int n) {
  a.resize(n);
  for (int i = (0); i < (n); ++i) cin >> a[i];
}
template <class T>
void read(vector<vector<T>>& a, int n, int m) {
  a.resize(n, vector<T>(m));
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) cin >> a[i][j];
}
template <class T>
void print(vector<T>& a, int n) {
  for (int i = (0); i < (n); ++i) cout << a[i] << ' ';
  cout << '\n';
}
template <class T>
void print(vector<vector<T>>& a, int n, int m) {
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (m); ++j) cout << a[i][j] << ' ';
    cout << '\n';
  }
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1e9 + 7;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
string s, t, rem;
int n, m;
vector<int> freq;
void solve() {
  cin >> t;
  s = rem = "";
  n = t.length();
  freq.clear();
  freq.resize(26, 0);
  for (int i = (n)-1; i >= (0); --i) {
    if (freq[t[i] - 'a'] == 0) rem += t[i];
    freq[t[i] - 'a']++;
  }
  reverse(begin(rem), end(rem));
  m = 0;
  for (int i = (0); i < (rem.size()); ++i) {
    if (freq[rem[i] - 'a'] % (i + 1) != 0) {
      cout << -1 << '\n';
      return;
    }
    freq[rem[i] - 'a'] /= (i + 1);
    m += freq[rem[i] - 'a'];
  }
  s = t.substr(0, m);
  int j = 0, cycle = 0;
  set<char> removed;
  for (int i = (0); i < (n); ++i) {
    while (removed.count(s[j])) {
      j++;
      if (j == m) {
        j = 0;
        if (cycle == rem.length()) {
          cout << -1 << '\n';
          return;
        }
        removed.insert(rem[cycle]);
        cycle++;
      }
    }
    if (t[i] != s[j]) {
      cout << -1 << '\n';
      return;
    }
    j++;
    if (j == m) {
      j = 0;
      if (cycle == rem.length()) {
        cout << -1 << '\n';
        return;
      }
      removed.insert(rem[cycle]);
      cycle++;
    }
  }
  cout << s << ' ' << rem << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
