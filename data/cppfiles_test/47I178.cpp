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
vector<bool> isPrime(1e7, true);
void sieve() {
  for (int p = 2; p * p <= 1e7; p++)
    if (isPrime[p] == true)
      for (int i = p * p; i <= 1e7; i += p) isPrime[i] = false;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> pos, neg;
  map<int, int> make_pair;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x < 0) {
      neg.push_back(x);
    } else if (x > 0) {
      pos.push_back(x);
    }
    ++make_pair[x];
  }
  sort(neg.begin(), neg.end());
  sort(pos.begin(), pos.end(), greater<int>());
  long long ans = 0;
  ;
  ;
  if (neg.empty()) {
    int w = k;
    while (!pos.empty()) {
      --w;
      if (pos.size() == 1) {
        ans += (pos.back());
        break;
      }
      int x = pos.back();
      --make_pair[pos.back()];
      pos.pop_back();
      if (k >= make_pair[pos.back()] && w < make_pair[pos.back()]) {
        ans += (2 * x);
        w = k;
      }
    }
  } else if (pos.empty()) {
    int w = k;
    while (!neg.empty()) {
      --w;
      if (neg.size() == 1) {
        ans += abs(neg.back());
        break;
      }
      int x = neg.back();
      --make_pair[neg.back()];
      neg.pop_back();
      if (k >= make_pair[neg.back()] && w < make_pair[neg.back()]) {
        ans += abs(2 * x);
        w = k;
      }
    }
  } else {
    if (pos[0] > abs(neg[0])) {
      int w = k;
      while (!neg.empty()) {
        --w;
        if (neg.size() == 1) {
          ans += abs(2 * neg.back());
          break;
        }
        int x = neg.back();
        --make_pair[neg.back()];
        neg.pop_back();
        if (k >= make_pair[neg.back()] && w < make_pair[neg.back()]) {
          ans += abs(2 * x);
          w = k;
        }
      }
      w = k;
      while (!pos.empty()) {
        --w;
        if (pos.size() == 1) {
          ans += (pos.back());
          break;
        }
        int x = pos.back();
        --make_pair[pos.back()];
        pos.pop_back();
        if (k >= make_pair[pos.back()] && w < make_pair[pos.back()]) {
          ans += (2 * x);
          w = k;
        }
      }
    } else {
      int w = k;
      while (!pos.empty()) {
        --w;
        if (pos.size() == 1) {
          ans += (2 * pos.back());
          break;
        }
        int x = pos.back();
        --make_pair[pos.back()];
        pos.pop_back();
        if (k >= make_pair[pos.back()] && w < make_pair[pos.back()]) {
          ans += (2 * x);
          w = k;
        }
      }
      w = k;
      while (!neg.empty()) {
        --w;
        if (neg.size() == 1) {
          ans += abs(neg.back());
          break;
        }
        int x = neg.back();
        --make_pair[neg.back()];
        neg.pop_back();
        if (k >= make_pair[neg.back()] && w < make_pair[neg.back()]) {
          ans += abs(2 * x);
          w = k;
        }
      }
    }
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
