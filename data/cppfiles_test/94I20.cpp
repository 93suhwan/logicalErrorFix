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
int withoutcarry(string s) {
  int ans = 1;
  for (int i = 0; i < s.size(); i++) ans *= (s[i] - '0' + 1);
  ans -= 2;
  return ans;
}
int carry2(string s) {
  ;
  if (s.size() < 3) {
    if (s.size() == 1) {
      int k = 10 + s[0] - '0';
      int ans = 10 - (k - 9);
      ;
      return ans;
    } else if (s.size() == 2) {
      int p = s[1] - '0' + 1;
      int k = 10 + s[0] - '0';
      int ans = 10 - (k - 9);
      ans = ans * p;
      ;
      return ans;
    }
  }
  int nxt = carry2(s.substr(2));
  int p0 = 10 + s[0] - '0' - 1;
  int p1 = s[1] - '0' + 1;
  int k;
  if (p0 >= 10) {
    k = 10 - (p0 - 9);
  } else {
    k = p0 + 1;
  }
  int ans = k * p1 * nxt;
  p0++;
  if (p0 >= 10) {
    k = 10 - (p0 - 9);
  } else {
    k = p0 + 1;
  }
  ans += k;
  ;
  return ans;
}
int carry(string s) {
  int ans = 1;
  int nxt = carry2(s.substr(2));
  int p0 = s[0] - '0' - 1;
  int p1 = s[1] - '0';
  p0++;
  p1++;
  ans = p0 * p1 * nxt;
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  s = to_string(n);
  ;
  int ans = withoutcarry(s);
  if (s.size() < 3) {
    cout << ans << endl;
    return;
  }
  for (int i = 0; i < s.size() - 2; i++) {
    if (s[i] != '0') {
      int k = withoutcarry(s.substr(0, i));
      if (k <= 0) k = 1;
      ans += carry(s) * k;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
