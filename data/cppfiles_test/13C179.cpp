#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T, class S>
ostream& operator<<(ostream& o, pair<T, S> p) {
  return o << '(' << p.first << ", " << p.second << ')';
}
template <template <class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type operator<<(
    ostream& o, T<A...> V) {
  o << '[';
  for (auto a : V) o << a << ", ";
  return o << ']';
}
template <long long int i, class... T>
typename enable_if<i == sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {}
template <long long int i, class... T>
    typename enable_if < i<sizeof...(T)>::type _p(ostream& o, tuple<T...> t) {
  _p<i + 1>(o << get<i>(t) << ", ", t);
}
template <class... T>
ostream& operator<<(ostream& o, tuple<T...> t) {
  _p<0>(o << '(', t);
  return o << ')';
}
long long int M = 1000000007;
long long int inv(long long int a, long long int b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
long long int gcd(long long int x, long long int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
pair<long long int, long long int> neigh[4] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
short dp[101][101][5001];
long long int r(long long int n, long long int m, long long int k) {
  if (k < 0 || k > n * m / 2) return false;
  if (!n || !m) {
    return true;
  }
  if (~dp[n][m][k]) {
    return dp[n][m][k];
  } else if (n % 2) {
    return dp[n][m][k] = r(n - 1, m, k - m / 2);
  } else if (m % 2) {
    return dp[n][m][k] = r(n, m - 1, k);
  } else {
    return dp[n][m][k] = r(n, m - 1, k) || r(n - 1, m, k - m / 2);
  }
}
set<char> construct(pair<long long int, long long int> x,
                    vector<vector<char>>& v) {
  set<char> s;
  for (long long int i = x.first - 1; i < (x.first + 2); i++) {
    for (long long int j = x.second - 1; j < (x.second + 1); j++) {
      if ((i >= 0 && i < v.size()) && (j >= 0 && j < v[0].size())) {
        s.insert(v[i][j]);
      }
    }
  }
  return s;
}
void getNext(pair<long long int, long long int> x,
             pair<long long int, long long int> y, vector<vector<char>>& v) {
  set<char> s1 = construct(x, v);
  set<char> s2 = construct(y, v);
  char res = 0;
  for (long long int i = 'a'; i < ('z' + 1); i++) {
    if (!s1.count(i) && !s2.count(i)) {
      res = i;
      break;
    }
  }
  v[x.first][x.second] = res;
  v[y.first][y.second] = res;
}
void res(long long int n, long long int m, long long int k, long long int a,
         long long int b, vector<vector<char>>& v) {
  if (!n || !m) {
    return;
  }
  if (n % 2 || (n % 2 == 0 && m % 2 == 0 && r(n - 1, m, k - m / 2))) {
    for (long long int i = b; i < m + b; i += 2) {
      getNext({a, i}, {a, i + 1}, v);
    }
    res(n - 1, m, k - m / 2, a + 1, b, v);
  } else {
    for (long long int i = a; i < n + a; i += 2) {
      getNext({i, b}, {i + 1, b}, v);
    }
    res(n, m - 1, k, a, b + 1, v);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int _t;
  cin >> _t;
  for (long long int _t1 = 0; _t1 < (_t); _t1++) {
    long long int n;
    cin >> n;
    long long int m;
    cin >> m;
    long long int k;
    cin >> k;
    for (long long int i = 0; i < (n + 1); i++)
      for (long long int j = 0; j < (m + 1); j++)
        for (long long int p = 0; p < (k + 1); p++) dp[i][j][p] = -1;
    if (r(n, m, k)) {
      cout << "YES" << endl;
      vector<vector<char>> re(n, vector<char>(m));
      res(n, m, k, 0, 0, re);
      for (long long int i = 0; i < (n); i++) {
        for (long long int j = 0; j < (m); j++) {
          cout << re[i][j];
        }
        cout << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
}
