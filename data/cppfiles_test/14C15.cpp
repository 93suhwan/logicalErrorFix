#include <bits/stdc++.h>
using namespace std;
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
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<int> sorted = arr;
    sort((sorted).begin(), (sorted).end());
    vector<vector<int>> ans;
    int count = 0;
    ;
    for (int i = n - 1; i >= 0; i--) {
      int element = sorted[i];
      int r = n + 1;
      for (int j = i; j >= 0; j--) {
        if (arr[j] == element) {
          r = j;
          break;
        }
      }
      if (r < i) {
        count++;
        ans.push_back({r + 1, i + 1, 1});
        rotate(arr.begin() + r, arr.begin() + r + 1, arr.begin() + i + 1);
        ;
      }
    }
    cout << count << '\n';
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
