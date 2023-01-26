#include <bits/stdc++.h>
using namespace std;
void swap(vector<int> &v, int i, int j) {
  if (i < 0 || j >= v.size()) {
    return;
  }
  auto temp = v[i];
  v[i] = v[j];
  v[j] = temp;
  return;
}
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
void dv(vector<int> g1) {
  for (auto i = g1.begin(); i != g1.end(); ++i) {
    cout << *i << " ";
  }
}
int invert(int a) {
  if (a == 0) {
    return 1;
  } else if (a == 1) {
    return 0;
  } else {
    return -1;
  }
}
int fact(int n) {
  int res = 1;
  for (int i = 2; i <= n; i++) res = res * i % 1000000007;
  return res;
}
int nCr(int n, int r) {
  return (fact(n) / (fact(r) * fact(n - r))) % 1000000007;
}
int nCr1(int a, int b) {
  if (b > a) {
    return 0;
  } else {
    int ans = 1;
    for (int i = b + 1; i < a + 1; ++i) {
      ans = ans * i % 1000000007;
    }
    return ans;
  }
}
int func(int a) {
  if (a % 2 == 0) {
    return -1;
  } else {
    return 1;
  }
}
int sumofdigits(int n) {
  int sum = 0;
  while (n) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}
int poweroftwo(int n) {
  if (n <= 0) {
    return -1;
  }
  int ans = 0;
  while (n != 1) {
    n = n / 2;
    ans++;
  }
  return ans;
}
int noofdigits(int n) {
  if (n <= 0) {
    return 0;
  }
  int ans = 0;
  while (n) {
    ans++;
    n = n / 10;
  }
  return ans;
}
int nooofonesinbits(int n) {
  int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
int __ceil(int a, int b) { return (a + b - 1) / b; }
int __pow(int a, int b) {
  if (b == 0) {
    return 1;
  }
  int res = __pow(a, b / 2);
  if (b % 2) {
    return res * res * a;
  } else {
    return res * res;
  }
}
void dpv(vector<vector<int>> a) {
  int n = a.size();
  int m = a[0].size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < m; y++) {
        cin >> a[x][y];
      }
    }
    vector<vector<int>> b(n, vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        b[i][j] = a[i][j];
      }
    }
    for (int j = 0; j < n; ++j) {
      b[j][m] = j;
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    vector<vector<int>> tl(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int x = (i - 1 < 0 ? 1000000007 : tl[i - 1][j]),
            y = (j - 1 < 0 ? 1000000007 : tl[i][j - 1]), z = b[i][j];
        tl[i][j] = min(min(x, y), z);
      }
    }
    vector<vector<int>> tr(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = m - 1; j >= 0; --j) {
        int x = (i - 1 < 0 ? -1 : tr[i - 1][j]),
            y = (j + 1 > m - 1 ? -1 : tr[i][j + 1]), z = b[i][j];
        tr[i][j] = max(x, max(y, z));
      }
    }
    vector<vector<int>> bl(n, vector<int>(m));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
        int x = (i + 1 > n - 1 ? -1 : bl[i + 1][j]),
            y = (j - 1 < 0 ? -1 : bl[i][j - 1]), z = b[i][j];
        bl[i][j] = max(x, max(y, z));
      }
    }
    vector<vector<int>> br(n, vector<int>(m));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        int x = (i + 1 > n - 1 ? 1000000007 : br[i + 1][j]),
            y = (j + 1 > m - 1 ? 1000000007 : br[i][j + 1]), z = b[i][j];
        br[i][j] = min(x, min(y, z));
      }
    }
    string ans = "";
    int f = 0;
    for (int i = 0; i < n; ++i) {
      ans += "B";
    }
    int a1 = -1, a2 = -1;
    for (int i = 0; i < n - 1; ++i) {
      if (f == 1) {
        break;
      }
      for (int j = 0; j < m - 1; ++j) {
        int x = tl[i][j], y = bl[i + 1][j], z = tr[i][j + 1],
            w = br[i + 1][j + 1];
        if (x > y && w > z && f == 0) {
          for (int z = 0; z < i + 1; ++z) {
            ans[b[z][m]] = 'R';
          }
          a1 = i + 1;
          a2 = j + 1;
          f = 1;
          break;
        }
      }
      if (f == 1) {
        break;
      }
    }
    if (a2 == -1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << ans << ' ' << a2 << endl;
    }
  }
}
