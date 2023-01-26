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
void solve() {
  long long n, k;
  cin >> n >> k;
  string pp = to_string(n);
  vector<long long> poss;
  for (long long i = 1; i <= 9; i++) {
    long long qq = 0;
    for (long long j = 0; j < pp.size(); j++) {
      qq = 10 * qq + i;
    }
    poss.push_back(qq);
  }
  for (long long i = 1; i <= 9; i++) {
    long long qq = 0;
    for (long long j = 0; j < pp.size() + 1; j++) {
      qq = 10 * qq + i;
    }
    poss.push_back(qq);
  }
  long long mini = 1e16;
  for (long long i = 0; i < poss.size(); i++) {
    if (poss[i] >= n) {
      mini = min(mini, poss[i]);
    }
  }
  if (k == 1) {
    cout << mini << "\n";
    return;
  }
  vector<long long> poss1;
  for (long long i = 1; i <= 9; i++) {
    long long qq = i;
    for (long long k = 0; k < pp.size() - 1; k++) {
      qq = 10 * qq;
    }
    poss1.push_back(qq);
  }
  for (long long i = 1; i <= 9; i++) {
    long long qq = i;
    for (long long k = 0; k < pp.size(); k++) {
      qq = 10 * qq;
    }
    poss1.push_back(qq);
  }
  for (long long i = 1; i <= 9; i++) {
    for (long long j = 1; j <= 9; j++) {
      long long qq = 0;
      for (long long k = 0; k < pp.size(); k++) {
        qq = 10 * qq + j;
      }
      string rs = to_string(qq);
      for (long long k = 0; k < rs.size(); k++) {
        char temp = rs[k];
        rs[k] = ('0' + i);
        poss1.push_back(stol(rs));
        rs[k] = temp;
      }
    }
  }
  for (long long i = 1; i <= 9; i++) {
    for (long long j = 1; j <= 9; j++) {
      long long qq = 0;
      for (long long k = 0; k < pp.size() + 1; k++) {
        qq = 10 * qq + j;
      }
      string rs = to_string(qq);
      for (long long k = 0; k < rs.size(); k++) {
        char temp = rs[k];
        rs[k] = ('0' + i);
        poss1.push_back(stol(rs));
        rs[k] = temp;
      }
    }
  }
  for (long long i = 0; i < poss1.size(); i++) {
    if (poss1[i] >= n) {
      mini = min(mini, poss1[i]);
    }
  }
  cout << mini << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
