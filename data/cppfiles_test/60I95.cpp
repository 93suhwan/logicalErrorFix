#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = 2e5 + 5;
const int MN = 4e5 + 1;
bool sortbysecdesc(const pair<long long int, long long int> &a,
                   const pair<long long int, long long int> &b) {
  return a.second < b.second || ((a.first == b.first) && a.second < b.second);
}
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
long long int ceild(long long int a, long long int b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
long long int floord(long long int a, long long int b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
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
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  long long int s = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    s += arr[i];
  }
  float p = (float)s / n;
  s = s - p * (n - 2);
  long long int left = 0;
  long long int right = n - 1;
  long long int ans = 0;
  sort((arr).begin(), (arr).end());
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i + 1; j < n; j++) {
      if (arr[i] + arr[j] == s) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
