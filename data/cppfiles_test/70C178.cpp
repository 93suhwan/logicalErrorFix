#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 10;
const long double eps = 1e-9;
const int inf = 1.01e9;
const long long llinf = (long long)1.01e18;
const long long MOD = 1e9 + 7;
const string Y = "YES";
const string N = "NO";
template <typename T>
inline int sz(T structure) {
  return (int)(structure.size());
}
template <typename T>
inline void chkmax(T& max, T a) {
  if (max < a) max = a;
}
template <typename T>
inline void chkmin(T& min, T a) {
  if (min > a) min = a;
}
template <class T>
inline istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) is >> x;
  return is;
}
template <class T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < sz(v); ++i) os << ' ' << v[i];
  }
  return os;
}
inline int Bit(int mask, int b) { return (mask >> b) & 1; }
void precalc() {}
void solve() {
  string s;
  cin >> s;
  vector<int> count(26, 0);
  for (int i = 0; i < 26; ++i) {
    count[i] += count_if((s).begin(), (s).end(),
                         [i](char c) { return ((i + 'a') == c); });
  }
  vector<pair<int, char>> letters;
  for (int i = 0; i < 26; ++i) {
    if (count[i] != 0) {
      letters.push_back(make_pair(count[i], i + 'a'));
    }
  }
  string cs = s;
  reverse((cs).begin(), (cs).end());
  vector<char> pasts;
  pasts.push_back(cs[0]);
  cs.erase(cs.begin());
  while (cs.size()) {
    if (find((pasts).begin(), (pasts).end(), cs[0]) == pasts.end())
      pasts.push_back(cs[0]);
    cs.erase(cs.begin());
  }
  string ans2 = "";
  for (auto el : pasts) ans2 += el;
  int div = letters.size();
  int ptr = 0;
  while (ptr != letters.size()) {
    for (int i = 0; i < letters.size(); ++i) {
      if (letters[i].second == ans2[ptr]) {
        if (letters[i].first % div != 0) {
          cout << -1 << endl;
          return;
        }
        letters[i].first /= div;
        break;
      }
    }
    ptr++;
    div--;
  }
  int sum = 0;
  for (int i = 0; i < letters.size(); ++i) sum += letters[i].first;
  string ans1 = "";
  for (int i = 0; i < sum; ++i) ans1 += s[i];
  reverse((ans2).begin(), (ans2).end());
  string check = ans1;
  string tmp = check;
  int ans2_ptr = 0;
  while (check.size() < s.size() && ans2_ptr < ans2.size()) {
    string tmp_to = "";
    for (int i = 0; i < tmp.size(); ++i) {
      if (tmp[i] != ans2[ans2_ptr]) tmp_to += tmp[i];
    }
    tmp = tmp_to;
    check += tmp;
    ans2_ptr++;
  }
  if (check != s) {
    cout << -1 << endl;
    return;
  }
  cout << ans1 << " " << ans2 << endl;
}
int main() {
  precalc();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
