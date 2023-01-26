#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;
const int MOD = 1e9 + 7;
const db PI = acos((db)-1);
mt19937 rng(0);
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class U>
T fstTrue(T lo, T hi, U first) {
  ++hi;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    first(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
struct Eff {
  bool solveRecur(ll N, ll A, ll B, string DA, string DB) {
    if (DA != DB) {
      if (A == 0 || A == N - 1) {
        DA = DB;
        return solveRecur(N, A, B, DA, DB);
      } else if (B == 0 || B == N - 1) {
        DB = DA;
        return solveRecur(N, A, B, DA, DB);
      }
      if (DA == "left") {
        swap(DA, DB);
        A = N - 1 - A;
        B = N - 1 - B;
        return 1 ^ solveRecur(N, A, B, DA, DB);
      }
      if (A < B) {
        swap(A, B);
        N--;
        A--;
        return solveRecur(N, A, B, DA, DB);
      } else if (A == B) {
        A++;
        B--;
        N--;
        A--;
        return solveRecur(N, A, B, DA, DB);
      }
      ll min_dist = min(N - 1 - A, B);
      return solveRecur(N, A + min_dist, B - min_dist, DA, DB);
    }
    map<string, bool> to_bool;
    to_bool["left"] = 0;
    to_bool["right"] = 1;
    map<bool, string> to_str;
    to_str[0] = "left";
    to_str[1] = "right";
    if (DA == "left") {
      DA = to_str[to_bool[DA] ^ 1];
      DB = to_str[to_bool[DB] ^ 1];
      A = N - 1 - A;
      B = N - 1 - B;
      return 1 ^ solveRecur(N, A, B, DA, DB);
    }
    if (A == B) {
      if (A == 0) {
        return 1;
      }
      return 0;
    }
    if (A < B) {
      return solveRecur(N, B, A + 1, DB, DA);
    }
    assert(A > B);
    if ((N + A - B + (N & 1)) % 2 == 0) {
      return 0;
    }
    return 1;
  }
  void solveTestCase() {
    ll N, A, B;
    cin >> N >> A >> B;
    string DA, DB;
    cin >> DA >> DB;
    if (solveRecur(N, A, B, DA, DB)) {
      cout << N - 1 << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
  void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
      solveTestCase();
    }
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  Eff e;
  e.solve();
}
