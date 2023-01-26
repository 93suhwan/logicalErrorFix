#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using pi64 = pair<i64, i64>;
constexpr i64 MAXN = 3 * 100 * 1000 + 5LL;
constexpr i64 MOD = 1000000007LL;
constexpr i64 INF64 = MOD * MOD;
ostream& operator<<(ostream& os, const pi64 p) {
  os << p.first << " " << p.second;
  return os;
}
ostream& operator<<(ostream& os, const vector<i64>& v) {
  for (i64 i = 0; i < v.size(); ++i) {
    os << v[i] << " \n"[i + 1 == v.size()];
  }
  return os;
}
bool solve(string_view S, string_view T) {
  for (i64 start = 0; start < S.size(); ++start) {
    for (i64 moves_right = 0; moves_right + start <= S.size(); ++moves_right) {
      const i64 moves_left = T.size() - moves_right;
      string buf(S.substr(start, moves_right));
      for (i64 i = 1; i <= moves_left; ++i) {
        if (start + moves_right - 1 - i < 0) {
          break;
        }
        buf.push_back(S[start + moves_right - 1 - i]);
      }
      if (buf == T) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  mt19937 gen(seed);
  i64 T;
  cin >> T;
  ;
  for (; T-- > 0;) {
    string S;
    cin >> S;
    ;
    string T;
    cin >> T;
    ;
    cout << (solve(S, T) ? "YES" : "NO") << "\n";
  }
  return 0;
}
