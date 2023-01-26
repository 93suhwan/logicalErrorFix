#include <bits/stdc++.h>
using namespace std;
static long long mod = 1000000007;
void print(int a) { cerr << a; }
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
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0, count = 0;
  reverse(s.begin(), s.end());
  for (long long i = 0; i < s.length(); i++) {
    if (count > 0) {
      if (s[i] > '0') ans += (s[i] - '0') + 1;
    } else {
      if (s[i] > '0') ans += (s[i] - '0');
    }
    count++;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("error.txt", "w", stderr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
