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
void solve() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> ar(n);
    for (long long i = 0; i < n; i++) cin >> ar[i];
    vector<long long> max(n);
    long long last = ar[n - 1];
    for (long long i = 0; i < n; i++) {
      max[i] = ar[i] % 3;
      if (i == 0) {
        max[i] += (ar[2] / 3) * 2;
      } else {
        if (i + 1 < n) {
          max[i] += ar[i + 1] / 3;
        }
        if (i + 2 < n) {
          max[i] += (ar[i + 2] / 3) * 2;
        }
      }
    };
    ;
    while (max[n - 1] + 3 <= last && max[n - 1] < max[n - 2] &&
           max[n - 1] < max[n - 3]) {
      max[n - 1] += 3;
      max[n - 2] -= 1;
      max[n - 3] -= 2;
    };
    sort((max).begin(), (max).end());
    cout << max[0] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
