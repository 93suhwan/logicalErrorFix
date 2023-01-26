#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
vector<long long> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
void solve(int ttc) {
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  vector<bool> rem(n + 1);
  for (int i = 1; i <= n; i++) {
    rem[i] = true;
  }
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    a.push_back(make_pair(l, r));
  }
  sort(a.begin(), a.end());
  for (int i = n - 1; i >= 0; i--) {
    int fir = a[i].first;
    int sec = a[i].second;
    if (fir == sec) {
      rem[fir] = false;
      cout << fir << " " << sec << " " << fir << "\n";
    } else if (rem[sec]) {
      rem[sec] = false;
      cout << fir << " " << sec << " " << sec << "\n";
    } else if (rem[fir] and fir != 1) {
      cout << fir << " " << sec << " " << fir << "\n";
      rem[fir] = false;
    } else {
      int f = 1;
      for (int i = 2; i < n; i++) {
        if (rem[i]) {
          rem[i] = false;
          cout << fir << " " << sec << " " << i << "\n";
          f = 0;
        }
      }
      if (f) cout << fir << " " << sec << " " << fir << "\n";
    }
  }
  cout << "\n";
}
bool cmp(pair<int, pair<int, int>> &x, pair<int, pair<int, int>> &y) {
  if (x.first == y.first) {
    return x.second.second > y.second.second;
  }
  return x.first < y.first;
}
void get(int ttc) {
  int n;
  cin >> n;
  vector<pair<int, pair<int, int>>> a;
  vector<bool> rem(n + 1);
  for (int i = 1; i <= n; i++) {
    rem[i] = true;
  }
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    a.push_back(make_pair(l + r, make_pair(l, r)));
  }
  sort(a.begin(), a.end(), cmp);
  ;
  for (int i = 0; i < n; i++) {
    int l = a[i].second.first;
    int r = a[i].second.second;
    cout << l << " " << r << " " << i + 1 << "\n";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int ttc = 1;
  cin >> ttc;
  for (int i = 1; i <= ttc; i++) {
    get(i);
  }
  return 0;
}
