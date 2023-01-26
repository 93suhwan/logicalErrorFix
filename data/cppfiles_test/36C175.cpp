#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long int x1, y1;
  long long int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long int modInverse(long long int a, long long int m) {
  long long int x, y;
  long long int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    return -1;
  else {
    long long int res = (x % m + m) % m;
    return res;
  }
}
long long int ncr(long long int n, long long int r) {
  long long int ans = 1;
  if (n < r) {
    return 0;
  }
  r = max(r, n - r);
  if (r == n) {
    return 1;
  }
  for (long long int i = r + 1; i <= n; i++) {
    ans *= i;
    ans %= mod;
    ans *= modInverse(i - r, mod);
    ans %= mod;
  }
  return ans % mod;
}
long long int fact(long long int n) {
  long long int ans = 1;
  for (long long int i = 1; i <= n; i++) {
    ans *= i;
    ans %= mod;
  }
  return ans;
}
void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void print(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
bool status[400000];
int dif[100000] = {0};
void siv(int N) {
  int sq = sqrt(N);
  for (int i = 4; i <= N; i += 2) {
    status[i] = 1;
  }
  for (int i = 3; i <= sq; i += 2) {
    if (status[i] == 0) {
      for (int j = i * i; j <= N; j += i) status[j] = 1;
    }
  }
  status[1] = 1;
}
void setDif() {
  int j = 0;
  for (int i = 2; i < 400000; i++) {
    if (status[i] == 0) {
      dif[j] = (i);
      j++;
    }
  }
}
struct cmpStruct {
  bool operator()(pair<int, int> const &lhs, pair<int, int> const &rhs) const {
    if (lhs.first != rhs.first)
      return lhs.first < rhs.first;
    else {
      return lhs.second < rhs.second;
    }
  }
};
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
bool desc(const int &a, const int &b) { return a > b; }
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long int t) { cerr << t; }
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
long long power(long long n, long long p) {
  if (p == 0) return 1;
  if (p == 1) return n;
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * n;
    n = n * n;
    p = p / 2;
  }
  return ans;
}
void NO() {
  cout << "NO"
       << "\n";
}
void YES() {
  cout << "YES"
       << "\n";
}
void No() {
  cout << "No"
       << "\n";
}
void Yes() {
  cout << "Yes"
       << "\n";
}
void ces(int cas) { cout << "Case " << cas << ": "; }
priority_queue<pair<int, int>> pq;
int main() {
  fastIO();
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "a" << endl;
      continue;
    }
    char ch = 'a';
    if (n < 27) {
      for (int i = 0; i < n; i++) {
        cout << ch;
        ch++;
      }
      cout << endl;
      continue;
    }
    int x = n / 2;
    for (int i = 0; i < x; i++) {
      cout << 'a';
    }
    cout << 'b';
    for (int i = 0; i < x - 1; i++) {
      cout << 'a';
    }
    if (n % 2) {
      cout << 'c';
    }
    cout << endl;
  }
  return 0;
}
