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
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
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
template <class T>
void _print(multiset<T> v) {
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n], count = 0;
    vector<int> freq[n + 1];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      freq[a[i]].push_back(i);
      if (freq[a[i]].size() == k) {
        count += k;
      } else if (freq[a[i]].size() > k) {
        count++;
      }
    }
    count = n - count;
    int ans[n];
    memset(ans, 0, sizeof ans);
    int color = 1;
    if (count < k) count = 0;
    for (int i = 1; i < n + 1; i++) {
      if (freq[i].size() >= k) {
        for (int j = 0; j < k; j++) {
          ans[freq[i][j]] = j + 1;
        }
      } else if (count) {
        for (int j = 0; j < freq[i].size() && count; j++) {
          ans[freq[i][j]] = color;
          color++;
          count--;
          if (color == k + 1) {
            color = 1;
            if (count < k) {
              count = 0;
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}
