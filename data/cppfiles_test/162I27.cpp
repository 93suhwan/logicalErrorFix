#include <bits/stdc++.h>
using namespace std;
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
void showpq(priority_queue<long long> gq) {
  priority_queue<long long> g = gq;
  while (!g.empty()) {
    cerr << '\t' << g.top();
    g.pop();
  }
  cerr << '\n';
}
bool sortbysec(const vector<int> &a, const vector<int> &b) {
  return (a[1] < b[1]);
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long bsearch(long long sum, long long mini, long long n, long long k) {
  long long min = -1 * (sum / n) - 1;
  long long max = mini;
  long long mid = (min + max) / 2;
  while (min + 1 != max) {
    if (sum + (mid * n) > k) {
      max = mid;
    } else
      min = mid;
    mid = (min + max) / 2;
  }
  return mini - min;
}
void solve() {
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];
    int last = ar[n - 1];
    for (int i = 2; i < n; i++) {
      ar[i - 1] += ar[i] / 3;
      ar[i - 2] += 2 * (ar[i] / 3);
      ar[i] %= 3;
    }
    while (ar[n - 1] <= last && ar[n - 1] + 3 <= ar[n - 2] - 1 &&
           ar[n - 1] + 3 <= ar[n - 3] - 2) {
      ar[n - 1] += 3;
      ar[n - 2] -= 1;
      ar[n - 3] -= 2;
    }
    sort((ar).begin(), (ar).end());
    cout << ar[0] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
