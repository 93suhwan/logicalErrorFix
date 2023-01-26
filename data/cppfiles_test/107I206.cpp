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
  if ((n - 2 < a + b) || (abs(a - b) > 1) || n < 3) {
    cout << -1 << endl;
    return;
  }
  vector<long long> arr, brr;
  for (long long i = 1; i < (n + 1) / 2; i++) arr.push_back(i);
  for (long long i = (n + 1) / 2; i < n + 1; i++) brr.push_back(i);
  reverse(brr.begin(), brr.end());
  if (a > b) {
    for (long long i = 0; i < a; i++) {
      cout << arr[i] << " " << brr[i] << " ";
    }
    for (long long i = a; i < brr.size(); i++) cout << brr[i] << " ";
    for (long long i = arr.size() - 1; i >= a; i--) cout << arr[i] << " ";
    cout << endl;
  } else {
    for (long long i = 0; i < b; i++) {
      cout << brr[i] << " " << arr[i] << " ";
    }
    if (a == b)
      for (long long i = b; i < brr.size(); i++) cout << brr[i] << " ";
    else
      for (long long i = brr.size() - 1; i >= b; i--) cout << brr[i] << " ";
    for (long long i = arr.size() - 1; i >= b; i--) cout << arr[i] << " ";
    cout << endl;
  }
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
