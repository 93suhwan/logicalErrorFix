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
using fb = V<bool>;
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
const int mx = 200005;
struct Eff {
  int to_weight[mx];
  char REV(char a) {
    if (a == 'L') return 'R';
    return 'L';
  }
  void solve() {
    int N;
    cin >> N;
    vi A;
    for (int i = 1; i <= N; i++) {
      int val;
      cin >> val;
      A.push_back(val);
    }
    sort(begin(A), end(A));
    for (int i = 0; i < N; i++) {
      to_weight[i + 1] = A[i];
    }
    string S;
    cin >> S;
    if (N % 2 == 0) S.push_back('R');
    vector<pair<int, char>> placed_weights;
    pi rang = make_pair(0, 0);
    placed_weights.push_back(make_pair(0, S[0]));
    for (int i = 2; i < int((S).size()); i += 2) {
      if (S[i] == S[i - 2]) {
        if (S[i] != S[i - 1]) {
          placed_weights.push_back(make_pair(++rang.second, S[i - 1]));
          placed_weights.push_back(make_pair(++rang.second, S[i]));
        } else {
          rang.second += 2;
          placed_weights.push_back(make_pair(rang.second, S[i]));
          placed_weights.push_back(make_pair(rang.second - 1, REV(S[i])));
        }
      } else if (S[i] != S[i - 2]) {
        if (S[i - 1] == S[i]) {
          rang.second++;
          rang.first--;
          placed_weights.push_back(make_pair(rang.second, S[i]));
          placed_weights.push_back(make_pair(rang.first, S[i]));
        } else {
          rang.second++;
          rang.first--;
          placed_weights.push_back(make_pair(rang.first, S[i]));
          placed_weights.push_back(make_pair(rang.second, S[i]));
        }
      }
    }
    if (N % 2 == 0) placed_weights.pop_back();
    int min_ele = MOD;
    map<int, int> m;
    for (auto u : placed_weights) {
      ckmin(min_ele, u.first);
      m[u.first];
    }
    int cur_ele = 0;
    for (auto& u : m) {
      u.second = ++cur_ele;
    }
    for (auto& u : placed_weights) {
      u.first = m[u.first];
    }
    for (const auto& u : placed_weights) {
      assert(u.first <= N);
      cout << to_weight[u.first] << " " << u.second << "\n";
    }
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  Eff e;
  e.solve();
}
