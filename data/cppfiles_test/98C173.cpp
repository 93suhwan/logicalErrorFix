#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &e : v) is >> e;
  return is;
}
struct Init {
  Init() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} initialize;
int main() {
  int t;
  cin >> t;
  for (; t--;) {
    string S, T;
    cin >> S >> T;
    vector<int> idx(26);
    for (int i = 0; i < 26; i++) idx[S[i] - 'a'] = i;
    int sum = 0;
    for (int i = 1; i < T.size(); i++)
      sum += abs(idx[T[i] - 'a'] - idx[T[i - 1] - 'a']);
    cout << sum << "\n";
  }
}
