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
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
const long long dx[4] = {0, 1, 0, -1};
const long long dy[4] = {1, 0, -1, 0};
void solve() {
  string a, s;
  cin >> a >> s;
  string ans;
  int i = (long long)((a).size()) - 1, j = (long long)((s).size()) - 1;
  if (j < i) {
    cout << "-1\n";
    return;
  }
  while (i >= 0 && j >= 0) {
    int ai = a[i] - '0';
    int sj = s[j] - '0';
    if (sj >= ai) {
      ans.push_back(sj - ai + '0');
      i--;
      j--;
    } else {
      string temp;
      if (j - 1 < 0) {
        cout << "-1\n";
        return;
      }
      temp.push_back(s[j - 1]);
      temp.push_back(s[j]);
      int val = stoll(temp);
      if (val > 18) {
        cout << "-1\n";
        return;
      }
      ans.push_back(val - ai + '0');
      i--;
      j -= 2;
    }
  }
  if (i >= 0 && j < 0) {
    cout << "-1\n";
    return;
  }
  while (j >= 0) ans.push_back(s[j--]);
  reverse(ans.begin(), ans.end());
  cout << stoll(ans) << "\n";
  return;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
