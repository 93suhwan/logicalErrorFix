#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
bool iseven(long long int n) {
  if ((n & 1) == 0) return true;
  return false;
}
void print(long long int t) { cout << t; }
void print(int t) { cout << t; }
void print(string t) { cout << t; }
void print(char t) { cout << t; }
void print(double t) { cout << t; }
void print(long double t) { cout << t; }
template <class T, class V>
void print(pair<T, V> p);
template <class T>
void print(vector<T> v);
template <class T>
void print(set<T> v);
template <class T, class V>
void print(map<T, V> v);
template <class T>
void print(multiset<T> v);
template <class T, class V>
void print(pair<T, V> p) {
  cout << "{";
  print(p.first);
  cout << ",";
  print(p.second);
  cout << "}";
}
template <class T>
void print(vector<T> v) {
  cout << "[ ";
  for (T i : v) {
    print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void print(set<T> v) {
  cout << "[ ";
  for (T i : v) {
    print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void print(multiset<T> v) {
  cout << "[ ";
  for (T i : v) {
    print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void print(map<T, V> v) {
  cout << "[ ";
  for (auto i : v) {
    print(i);
    cout << " ";
  }
  cout << "]";
}
void solve() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, q;
    cin >> n >> q;
    vector<char> a(n + 1);
    for (long long int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    vector<long long int> pre(n + 1);
    for (long long int i = 1; i <= n; ++i) {
      if (a[i] == '+') {
        if (!iseven(i)) {
          pre[i] = pre[i - 1] + 1;
        } else {
          pre[i] = pre[i - 1] - 1;
        }
      } else {
        if (!iseven(i)) {
          pre[i] = pre[i - 1] - 1;
        } else {
          pre[i] = pre[i - 1] + 1;
        }
      }
    }
    while (q--) {
      long long int l, r;
      cin >> l >> r;
      long long int sum = pre[r] - pre[l - 1];
      long long int ans = 0;
      if (sum == 0) {
        ans = 0;
      } else if (!iseven(sum)) {
        ans = 1;
      } else {
        ans = 2;
      }
      cout << ans << '\n';
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
