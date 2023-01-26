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
vector<vector<long long>> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n + 5);
    for (long long i = 0; i < n; i++) {
      long long a, b;
      cin >> a >> b;
      v[a]++;
      v[b + 1]--;
    }
    for (long long i = 1; i <= n; i++) v[i] += v[i - 1];
    map<long long, vector<long long>> m;
    for (long long i = 1; i <= n; i++) {
      m[v[i]].push_back(i);
    }
    vector<pair<long long, long long>> vec, temp;
    vec.push_back({1, n});
    map<pair<long long, long long>, long long> ans;
    for (auto& x : m) {
      long long j = 0;
      sort(vec.begin(), vec.end());
      for (int i = 0; i < vec.size(); i++) {
        long long del = x.second[j++];
        ans[vec[i]] = del;
        if (del != vec[i].first) temp.push_back({vec[i].first, del - 1});
        if (del != vec[i].second) temp.push_back({del + 1, vec[i].second});
      }
      vec.clear();
      swap(temp, vec);
    }
    for (auto& x : ans) {
      cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }
    cout << endl;
  }
  return 0;
}
