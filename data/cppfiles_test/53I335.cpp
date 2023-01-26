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
template <class T>
void _print(stack<T> v) {
  int k = v.size();
  cerr << "-> ";
  while (k--) {
    _print(v.top());
    v.pop();
    cerr << " ";
  }
  cerr << "||";
}
template <class T>
void _print(queue<T> v) {
  int k = v.size();
  cerr << "-> ";
  while (k--) {
    _print(v.front());
    v.pop();
    cerr << " ";
  }
  cerr << "->";
}
template <class T>
void _print(priority_queue<T> v) {
  int k = v.size();
  cerr << "-> ";
  while (k--) {
    _print(v.top());
    v.pop();
    cerr << " ";
  }
  cerr << "->";
}
void printans(bool ans) {
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
vector<int> primes;
void seive() {
  vector<bool> tp(300001, 1);
  tp[0] = tp[1] = 0;
  for (int i = 2; i < 300001; i++) {
    for (int j = i * 2; j < 300001; j += i) tp[j] = 0;
  }
  for (int i = 2; i < 300001; i++)
    if (tp[i]) primes.push_back(i);
}
void solve() {
  int n;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  bool f = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != c) {
      f = true;
      break;
    }
  }
  if (!f) {
    cout << 0 << endl;
    return;
  }
  int ans;
  int k, k1;
  for (int p : primes) {
    if (p > n) {
      break;
    }
    if (p < s.size()) {
      if (s[p] == c) {
        ans = 1;
        k = p;
        break;
      } else {
        ans = 2;
        k = p, k1 = p + 1;
      }
    } else {
      ans = 1;
      break;
    }
  }
  cout << ans << endl;
  if (ans == 1) {
    cout << k << endl;
  } else
    cout << k << " " << k + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  seive();
  while (t--) {
    solve();
  }
  return 0;
}
