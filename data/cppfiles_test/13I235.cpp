#include <bits/stdc++.h>
using namespace std;
long long int INF = 1e9 + 5;
long long int mod = 998244353;
void _print(long long int t) { cerr << t; }
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
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> ans(n + 1, vector<char>(m + 1));
    long long int cnt = 0;
    long long int n1 = n, m1 = m;
    if (n & 1) {
      n--;
      cnt += m / 2;
    }
    if (m & 1) {
      m--;
    }
    if (cnt > k || ((k - cnt) & 1)) {
      cout << "NO\n";
      continue;
    }
    k -= cnt;
    long long int maxi = (m / 2) * n;
    if (k > maxi) {
      cout << "NO\n";
      continue;
    }
    n = n1;
    m = m1;
    if (n & 1) {
      bool f = 0;
      for (long long int i = 1; i <= m; i += 2) {
        if (!f) {
          ans[n][i] = ans[n][i + 1] = 'y';
        } else {
          ans[n][i] = ans[n][i + 1] = 'z';
        }
        f ^= 1;
      }
      n--;
    }
    if (m & 1) {
      bool f = 0;
      for (long long int i = 1; i <= n; i += 2) {
        if (!f) {
          ans[i][m] = ans[i + 1][m] = 'y';
        } else {
          ans[i][m] = ans[i + 1][m] = 'z';
        }
        f ^= 1;
      }
      m--;
    }
    long long int x = -1, y = -1;
    for (long long int i = 1; i <= n; i += 2) {
      bool f = 0;
      for (long long int j = 1; j <= m; j += 2) {
        if (!k) {
          x = i;
          y = j;
          break;
        }
        k -= 2;
        ans[i][j] = ans[i][j + 1] = 'a';
        ans[i + 1][j] = ans[i + 1][j + 1] = 'b';
      }
      if (!k) {
        break;
      }
    }
    if (x != -1) {
      if (y != 1) {
        for (long long int i = x; i <= n; i += 2) {
          for (long long int j = y; j <= m; j += 2) {
            ans[i][j] = ans[i + 1][j] = 'e';
            ans[i][j + 1] = ans[i + 1][j + 1] = 'f';
          }
        }
        x += 2;
      }
      for (long long int i = x; i <= n; i += 2) {
        for (long long int j = 1; j <= m; j += 2) {
          ans[i][j] = ans[i + 1][j] = 'c';
          ans[i][j + 1] = ans[i + 1][j + 1] = 'd';
        }
      }
    }
    cout << "YES\n";
    for (long long int i = 1; i < (long long int)ans.size(); i++) {
      for (long long int j = 1; j < (long long int)ans[i].size(); j++) {
        cout << ans[i][j];
      }
      cout << "\n";
    }
  }
}
