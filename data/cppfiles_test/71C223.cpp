#include <bits/stdc++.h>
using namespace std;
void _print(int a) { cout << a; }
void _print(long long a) { cout << a; }
void _print(char a) { cout << a; }
void _print(string s) { cout << s; }
void _print(bool s) { cout << s; }
template <class T>
void _print(vector<T> v) {
  cout << "[ ";
  for (auto i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(set<T> s) {
  cout << "[ ";
  for (auto i : s) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(vector<vector<T>> v) {
  for (long long i = 0; i < v.size(); i++) {
    for (long long j = 0; j < v[i].size(); j++) {
      _print(v[i][j]);
      cout << " ";
    }
    cout << "\n";
  }
}
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template <class T>
void output_vector(vector<T>& v) {
  for (long long i = 0; i < v.size() - 1; i++) {
    cout << v[i] << " ";
  }
  cout << v.back() << "\n";
}
void getSol(long long curr, long long p, set<long long>& poss1, long long& a,
            long long& b) {
  if (p == 0) {
    poss1.insert(curr);
  } else {
    poss1.insert(curr);
    getSol(curr * 10 + a, p - 1, poss1, a, b);
    getSol(curr * 10 + b, p - 1, poss1, a, b);
  }
}
set<long long> poss1;
void make() {
  long long p1 = 1, p2 = 2;
  getSol(0, 11, poss1, p1, p2);
  for (long long i = 0; i <= 9; i++) {
    for (long long j = 0; j <= 9; j++) {
      getSol(0, 11, poss1, i, j);
    }
  }
}
void solve() {
  long long n, k;
  cin >> n >> k;
  string pp = to_string(n);
  set<long long> poss;
  for (long long i = 1; i <= 9; i++) {
    long long qq = 0;
    for (long long j = 0; j < pp.size(); j++) {
      qq = 10 * qq + i;
    }
    poss.insert(qq);
  }
  for (long long i = 1; i <= 9; i++) {
    long long qq = 0;
    for (long long j = 0; j < pp.size() + 1; j++) {
      qq = 10 * qq + i;
    }
    poss.insert(qq);
  }
  long long mini = 1e16;
  for (auto it : poss) {
    if (it >= n) {
      mini = min(mini, it);
    }
  }
  if (k == 1) {
    cout << mini << "\n";
    return;
  }
  cout << min(mini, *poss1.lower_bound(n)) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  make();
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
