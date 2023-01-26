#include <bits/stdc++.h>
using namespace std;
void array_debug(long long *a, long long n) {
  for (long long i = 0; i < (n); ++i) cout << a[i] << ' ';
}
void array_debug(int *a, int n) {
  for (int i = 0; i < (n); ++i) cout << a[i] << ' ';
}
void array_debug(long long *a, int n) {
  for (int i = 0; i < (n); ++i) cout << a[i] << ' ';
}
void _print(long long t) { cout << t; }
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(long double t) { cout << t; }
void _print(double t) { cout << t; }
template <class T, class V>
void _print(pair<T, V> p) {
  cout << "{";
  _print(p.first);
  cout << ",";
  _print(p.second);
  cout << "}";
}
template <class T>
void _print(vector<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(set<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(multiset<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cout << "[ ";
  for (auto i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
const long double eps = 1e-9;
const int mod = 1e9 + 7;
const long long inf = 1e18;
const int N1 = 2e5 + 10;
int code() {
  int n, k;
  cin >> n >> k;
  vector<int> pts(2 * n + 1, -1);
  for (int i = 1; i < (k + 1); ++i) {
    int x1, x2;
    cin >> x1 >> x2;
    pts[x1] = pts[x2] = i;
  }
  for (int i = 1; i < (2 * n + 1); ++i) {
    if (pts[i] != -1) continue;
    vector<int> v1[n + 2];
    set<int> cross;
    int mxx = 0;
    for (int j = 1; j < (2 * n + 1); ++j) {
      int k1 = ((i + j > 2 * n) ? (i + j - 2 * n) : (i + j));
      if (pts[k1] == -1) {
        v1[(int)cross.size()].push_back(k1);
        mxx = max(mxx, (int)cross.size());
      } else {
        if (cross.count(pts[k1]))
          cross.erase(pts[k1]);
        else
          cross.insert(pts[k1]);
      }
    }
    ++k;
    pts[i] = pts[v1[mxx][((int)v1[mxx].size() - 1) / 2]] = k;
  }
  int ans = 0;
  for (int i = 1; i < (2 * n + 1); ++i) {
    set<int> cross;
    for (int j = 1; j < (2 * n + 1); ++j) {
      int k1 = ((i + j > 2 * n) ? (i + j - 2 * n) : (i + j));
      if (pts[k1] == pts[i])
        break;
      else {
        if (cross.count(pts[k1]))
          cross.erase(pts[k1]);
        else
          cross.insert(pts[k1]);
      }
    }
    ans += (int)cross.size();
  }
  cout << ans / 4 << '\n';
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int i = 0; i < (tc); ++i) code();
  return 0;
}
