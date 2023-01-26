#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0)
    return power((a % 1000000007 * a % 1000000007) % 1000000007, b / 2);
  return (a % 1000000007 *
          power((a % 1000000007 * a % 1000000007) % 1000000007, b / 2)) %
         1000000007;
}
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
template <class T>
void _print(unordered_set<T> v) {
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
template <class T, class V>
void _print(unordered_map<T, V> v) {
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
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), ans(n);
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      m[arr[i]].push_back(i);
    }
    vector<int> rem;
    for (auto x : m) {
      vector<int> idx = x.second;
      int cnt = 1;
      int flag = 0;
      if (idx.size() >= k) {
        for (auto ele : idx) {
          ans[ele] = cnt;
          if (flag == 0) cnt++;
          if (cnt == k + 1) {
            flag = 1;
            cnt = 0;
          }
        }
      } else {
        for (auto ele : idx) rem.push_back(ele);
      }
    }
    for (int i = 0; i <= ((int)(rem).size()) - k; i += k)
      for (int j = 0; j < k; j++) ans[rem[i + j]] = j + 1;
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
