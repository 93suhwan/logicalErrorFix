#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) is >> x;
  return is;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  bool f = 0;
  for (const T& x : v) (f ? os << ' ' : os) << x, f = 1;
  return os;
}
void say(bool tag) { cout << (tag ? "YES\n" : "NO\n"); }
bool check(int n, int m, int k) {
  if (n % 2 == 1) {
    if (k < m / 2) return 0;
    k -= m / 2;
  } else if (m % 2 == 1) {
    k = n * m / 2 - k;
    if (k < n / 2) return 0;
    k -= n / 2;
  }
  return k % 2 == 0;
}
void sol() {
  int n, m, k;
  cin >> n >> m >> k;
  if (!check(n, m, k)) return say(0);
  say(1);
  vector<string> v(n, string(m, ' '));
  auto in_range = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  auto put = [&](int x, int y, int h) {
    set<char> S;
    for (char i = 'a'; i <= 'h'; i++) S.insert(i);
    if (h) {
      if (in_range(x - 1, y)) S.erase(v[x - 1][y]);
      if (in_range(x - 1, y + 1)) S.erase(v[x - 1][y + 1]);
      if (in_range(x, y - 1)) S.erase(v[x][y - 1]);
      if (in_range(x, y + 2)) S.erase(v[x][y + 2]);
      if (in_range(x + 1, y)) S.erase(v[x + 1][y]);
      if (in_range(x + 1, y + 1)) S.erase(v[x + 1][y + 1]);
      char c = *S.begin();
      v[x][y] = v[x][y + 1] = c;
      k--;
    } else {
      if (in_range(x - 1, y)) S.erase(v[x - 1][y]);
      if (in_range(x, y - 1)) S.erase(v[x][y - 1]);
      if (in_range(x, y + 1)) S.erase(v[x][y + 1]);
      if (in_range(x + 1, y - 1)) S.erase(v[x + 1][y - 1]);
      if (in_range(x + 1, y + 1)) S.erase(v[x + 1][y + 1]);
      if (in_range(x + 2, y)) S.erase(v[x + 2][y]);
      char c = *S.begin();
      v[x][y] = v[x + 1][y] = c;
    }
  };
  if (n % 2 == 1) {
    for (int j = 0; j < m; j += 2) {
      put(0, j, 1);
    }
    for (int i = 1; i < n; i += 2) {
      for (int j = 0; j < m; j += 2) {
        if (k) {
          put(i, j, 1);
          put(i + 1, j, 1);
        } else {
          put(i, j, 0);
          put(i, j + 1, 0);
        }
      }
    }
  } else if (m % 2 == 1) {
    for (int i = 0; i < n; i += 2) {
      put(i, 0, 0);
    }
    for (int i = 0; i < n; i += 2) {
      for (int j = 1; j < m; j += 2) {
        if (k) {
          put(i, j, 1);
          put(i + 1, j, 1);
        } else {
          put(i, j, 0);
          put(i, j + 1, 0);
        }
      }
    }
  } else {
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j += 2) {
        if (k) {
          put(i, j, 1);
          put(i + 1, j, 1);
        } else {
          put(i, j, 0);
          put(i, j + 1, 0);
        }
      }
    }
  }
  for (string& s : v) {
    cout << s << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    sol();
  }
  return 0;
}
