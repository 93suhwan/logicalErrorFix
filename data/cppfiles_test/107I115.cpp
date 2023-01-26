#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long bmod = 1e18 + 7;
void print(int a) { cerr << a; }
void print(double a) { cerr << a; }
void print(long long a) { cerr << a; }
void print(char a) { cerr << a; }
void print(string a) { cerr << a; }
void print(bool a) { cerr << a; }
template <class T, class X>
void print(pair<T, X> p);
template <class T>
void print(vector<T> v);
template <class T>
void print(set<T> v);
template <class T, class X>
void print(map<T, X> v);
template <class T>
void print(multiset<T> v);
template <class T, class X>
void print(pair<T, X> p) {
  cerr << "{";
  print(p.first);
  cerr << ",";
  print(p.second);
  cerr << "}";
}
template <class T>
void print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
  cerr << endl;
}
template <class T>
void print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void print(list<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class X>
void print(map<T, X> v) {
  cerr << "[ ";
  for (auto i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  if ((n - 2 < a + b) || (abs(a - b) > 1) || n < 3 || a > (n - 1) / 2 ||
      b > (n - 1) / 2) {
    cout << -1 << endl;
    return;
  }
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) arr[i] = i + 1;
  long long i = 0;
  if (a == b) {
    while (i < n && a > 0) {
      swap(arr[i], arr[i + 1]);
      a--;
      i += 2;
    }
  } else if (a > b) {
    i = n - 1;
    while (i < n && a > 0) {
      swap(arr[i], arr[i - 1]);
      a--;
      i -= 2;
    }
  } else {
    i = 0;
    while (i < n && b > 0) {
      swap(arr[i], arr[i + 1]);
      b--;
      i += 2;
    }
  }
  for (long long i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int p = 0;
  freopen("error.txt", "w", stderr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
