#include <bits/stdc++.h>
using namespace std;
template <class T>
void _print(vector<vector<T>> x) {
  for (long long i = 0; i < x.size(); i++) {
    i == 0 ? cout << "[ " : cout << "\t   [ ";
    for (auto it : x[i]) cout << it << "\t";
    cout << "]" << '\n';
  }
}
template <class T>
void _print(map<T, T> x) {
  cout << "[ ";
  for (auto it : x) cout << "(" << it.first << ":" << it.second << ") ";
  cout << "]" << '\n';
}
template <class T>
void _print(vector<T> v1) {
  cout << "[ ";
  for (auto i : v1) cout << i << " ";
  cout << "]" << '\n';
}
template <class T>
void _print(T x) {
  cout << x << '\n';
}
long long mrrishabh17() {
  long long testCases;
  cin >> testCases;
  for (long long loop = 1; loop <= testCases; loop++) {
    map<char, long long> make_pair;
    string s;
    cin >> s;
    for (long long i = 0; i < 26; i++) {
      make_pair[s[i]] = i + 1;
    }
    cin >> s;
    long long time = 0;
    for (long long i = 0; i < s.length() - 1; i++) {
      time += abs(make_pair[s[i]] - make_pair[s[i + 1]]);
    }
    cout << time << '\n';
  }
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  mrrishabh17();
  return 0;
}
