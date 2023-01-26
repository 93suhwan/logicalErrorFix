#include <bits/stdc++.h>
using namespace std;
const int W = 1e7 + 10;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> input);
template <class T>
void _print(set<T> input);
template <class T, class V>
void _print(map<T, V> input);
template <class T>
void _print(multiset<T> input);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> input) {
  cerr << "[ ";
  for (T i : input) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> input) {
  cerr << "[ ";
  for (T i : input) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> input) {
  cerr << "[ ";
  for (T i : input) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> input) {
  cerr << "[ ";
  for (auto i : input) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
inline void Alporis() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long input[W];
long long Sum_Of[W];
int main() {
  Alporis();
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> input[n + 1];
    vector<long long> ans(n, -1);
    map<long long, vector<long long>> hashIndex;
    vector<long long> left;
    for (long long i = 0; i < n; i++) {
      long long in;
      cin >> in;
      input[in].emplace_back(i);
    }
    for (long long i = 1; i < n + 1; i++) {
      if (input[i].size() >= k) {
        for (long long j = 0; j < k; j++) {
          ans[input[i][j]] = j;
        }
      } else {
        for (auto itr : input[i]) {
          left.push_back(itr);
          if (left.size() >= k) {
            int id = 0;
            for (auto j : left) {
              ans[j] = id++;
            }
            left.clear();
          }
        }
      }
    }
    for (long long i : ans) cout << i + 1 << " ";
    cout << "\n";
  }
  return 0;
}
