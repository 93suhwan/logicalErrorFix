#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int imax = INT_MAX;
const int imin = INT_MIN;
const int mod = 1e9 + 7;
template <class T>
void _print(vector<T> arr) {
  cerr << "[ ";
  for (auto x : arr) {
    cerr << x << " ";
  }
  cerr << "]";
  cerr << "\n";
}
template <class T, class V>
void _print(map<T, V> map) {
  cerr << "{ \n";
  for (auto x : map) {
    cerr << "\t" << x.first << " : " << x.second << "\n";
  }
  cerr << "}";
  cerr << "\n";
}
template <class T, class V>
void _print(unordered_map<T, V> map) {
  cerr << "{ \n";
  for (auto x : map) {
    cerr << "\t" << x.first << " : " << x.second << "\n";
  }
  cerr << "}";
  cerr << "\n";
}
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{ " << p.first << " " << p.second << " }"
       << "\n";
}
template <class T>
void _print(T x) {
  cerr << x << "\n";
}
bool f(pair<string, int> p1, pair<string, int> p2) {
  for (int i = 0; i < p1.first.size(); i++) {
    if (p1.first[i] != p2.first[i]) {
      if (i % 2) {
        return p2.first[i] < p1.first[i];
      } else {
        return p2.first[i] > p1.first[i];
      }
    }
  }
  return true;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<pair<string, int>> ar(n);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    ar[i].first = temp;
    ar[i].second = i + 1;
  }
  sort(ar.begin(), ar.end(), f);
  for (int i = 0; i < n; i++) {
    cout << ar[i].second << " ";
  }
  return;
}
int main() {
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  end = chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end - start;
  cerr << "Time Taken : " << elapsed_seconds.count() << "s\n";
  return 0;
}
