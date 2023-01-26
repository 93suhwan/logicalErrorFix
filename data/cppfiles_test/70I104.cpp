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
  sort((letters).begin(), (letters).end());
  reverse((letters).begin(), (letters).end());
  int len = sz(letters);
  reverse((s).begin(), (s).end());
  string ans2 = "";
  char first = s[0];
  ans2 += first;
  char past = first;
  int am = -1;
  vector<int> pasts;
  pasts.push_back(past);
  vector<int> available_divs;
  for (int i = len; i > 1; --i) available_divs.push_back(i);
  while (sz(s)) {
    bool end = true;
    for (int i = 0; i < sz(s); ++i) {
      if (find((pasts).begin(), (pasts).end(), s[i]) == pasts.end()) {
        end = false;
      }
    }
    if (end) {
      reverse((s).begin(), (s).end());
      reverse((ans2).begin(), (ans2).end());
      cout << s << " " << ans2 << endl;
      return;
    }
    for (int i = 0; i < len; ++i) {
      bool flag1 = false;
      if (letters[i].second == past) {
        flag1 = true;
        bool flag = false;
        for (int d = 0; d < sz(available_divs); ++d) {
          int div = available_divs[d];
          if (letters[i].first % div != 0) {
            continue;
          }
          flag = true;
          am = (am == -1 ? (letters[i].first / div)
                         : (am + letters[i].first / div));
          available_divs.erase(available_divs.begin() + d);
          break;
        }
        if (!flag) {
          cout << -1 << endl;
          return;
        }
      }
      if (flag1) break;
    }
    for (int i = 0; i < am; ++i) s.erase(s.begin());
    int ptr = 0;
    while ((find((pasts).begin(), (pasts).end(), s[ptr]) != pasts.end())) {
      ptr++;
    }
    past = s[ptr];
    pasts.push_back(past);
    ans2 += past;
  }
  assert(0);
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
