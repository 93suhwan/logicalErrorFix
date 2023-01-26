#include <bits/stdc++.h>
using namespace std;
const int mod = 100000007;
const int mini = -2147483648;
const int maxi = 2147483647;
void _print(long long int t) { cerr << t; }
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
bool cmp(long long int x, long long int y) { return x > y; }
void solve() {
  long long int n, a, b;
  cin >> n >> a >> b;
  if (!(n & 1)) {
    if ((n - 2) <= a + b and a > (n / 2 - 1) || b > (n / 2 - 1)) {
      cout << -1;
      return;
    }
  } else {
    if ((n - 2) < a + b and a > (n / 2) || b > (n / 2)) {
      cout << -1;
      return;
    }
  }
  long long int maxx = 0, minn = 0, cnt = 0;
  if (b > a) {
    vector<long long> v(n);
    for (long long int i = 0; i < n; i++) {
      v[i] = i + 1;
    }
    long long int f = 0;
    for (long long int i = 0; i < n; i += 2) {
      if ((a + b) < minn + maxx) {
        break;
      };
      ;
      v[i] = n - i;
      v[i + 1] = i + 1;
      minn++;
      maxx++;
    }
    for (long long int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
  }
  minn = 0;
  maxx = 0;
  if (a > b) {
    vector<long long> v(n);
    for (long long int i = n - 1; i >= 0; i--) {
      v[i] = i + 1;
    }
    for (long long int i = n - 1; i >= 0; i -= 2) {
      if (minn == b and maxx == a) {
        break;
      }
      v[i] = n - i;
      v[i + 1] = i + 1;
      minn++;
      maxx++;
    }
    for (long long int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
  } else if (a == b) {
    vector<long long> v(n);
    for (long long int i = 0; i < n; i++) {
      v[i] = i + 1;
    }
    for (long long int i = 1; i < n - 1; i += 2) {
      if (cnt == a) continue;
      swap(v[i], v[i + 1]);
      cnt++;
    }
    for (long long int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
  }
}
signed main() {
  freopen("Error.txt", "w", stderr);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start = chrono::high_resolution_clock::now();
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  cerr << "\n"
       << "Time : " << duration.count() / 1e3 << " ms\n";
}
