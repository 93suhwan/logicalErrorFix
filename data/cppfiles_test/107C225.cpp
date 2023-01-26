#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 50;
const int M = 5e3 + 50;
int n, m, u, k, l, r, t, x, y;
int cnt, cnt1, cnt2, ans;
int mn = INT_MAX;
int mx = INT_MIN;
const int fx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int fy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MOD = (1ll << 30);
const int mod = 1e9 + 7;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (abs(a.second) == abs(b.second)) {
    return abs(a.first) < abs(b.first);
  }
  return abs(a.second) < abs(b.second);
}
bool cmp1(const pair<string, pair<int, int>> &a,
          const pair<string, pair<int, int>> &b) {
  return abs(a.second.first) < abs(b.second.first);
}
bool isPowerOfTwo(long long n) { return (ceil(log2(n)) == floor(log2(n))); }
int makedigit(string n, int x) {
  int res = 0;
  for (int i = 0; i < x; i++) {
    res = res * 10 + (n[i] - '0');
  }
  return res;
}
string inttostrng(int a) {
  ostringstream temp;
  string str;
  temp << a;
  return temp.str();
}
void clearr(int vis[N], int n) {
  for (int i = 0; i < n; i++) {
    vis[i] = 0;
  }
}
long long pow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % m;
    }
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
bool is_prime[N];
void prime() {
  is_prime[0] = is_prime[1] = true;
  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i] == false) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = true;
      }
    }
  }
}
bool is_palidrome(string second) {
  for (int i = 0; i < second.size() / 2; i++) {
    if (second[i] != second[second.size() - i - 1]) {
      return false;
    }
  }
  return true;
}
long long sum(long long x) {
  if (x < 0) {
    return -1;
  }
  long long second = 0;
  while (x) {
    int rem = x % 10;
    second += rem;
    x /= 10;
  }
  return second;
}
long long poww(long long x, long long y) {
  long long pw = 1;
  for (int i = 1; i <= y; i++) {
    pw *= x;
  }
  return pw;
}
long long pp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a);
    }
    b >>= 1;
    a = (a * a);
  }
  return ans;
}
void dfs(int x, int y, char c[200][200], int n) {
  if (x <= 0 or x > 2 or y <= 0 or y > n) {
    return;
  }
  if (c[x][y] == '1' or c[x][y] == '.') {
    return;
  }
  if (c[x][y] == '0') {
    c[x][y] = '.';
  }
  dfs(x, y + 1, c, n);
  dfs(x + 1, y, c, n);
  dfs(x + 1, y + 1, c, n);
  dfs(x - 1, y, c, n);
  dfs(x - 1, y + 1, c, n);
  dfs(x, y + 1, c, n);
}
int getPairsCount(int arr[], int n, int diff) {
  int ret = 0;
  map<int, int> m;
  for (int i = 1; i <= n; i++) {
    if (m.find(diff - arr[i]) != m.end()) {
      ret += m[diff - arr[i]];
    }
    m[arr[i]]++;
  }
  return ret;
}
bool chk(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  if (n == 1) return false;
  return true;
}
void solve() {
  cin >> n >> l >> r;
  vector<int> v(n);
  if (abs(l - r) > 1) {
    cout << -1 << "\n";
    return;
  } else if ((l + r) > n - 2) {
    cout << -1 << "\n";
    return;
  }
  if (l == 0 and r == 0) {
    for (int i = 0; i < n; i++) {
      v[i] = i + 1;
    }
  } else if (l == r) {
    int second = 1, e = n, a = l, b = r;
    for (int i = 0; i < n; i++) {
      if (b == 0) {
        v[i] = e;
        e--;
        continue;
      }
      if (i % 2 == 1) {
        v[i] = second;
        second++;
      } else {
        v[i] = e;
        e--;
      }
      if (i > 1 and i < n - 1 and b != 0) {
        if (v[i - 1] < v[i] and v[i - 1] < v[i - 2]) {
          b--;
        }
      }
    }
  } else if (l > r and r != 0) {
    int second = 1, e = n, a = l, b = r;
    for (int i = 0; i < n; i++) {
      if (b == 0) {
        v[i] = e;
        e--;
        continue;
      }
      if (i % 2 == 0) {
        v[i] = second;
        second++;
      } else {
        v[i] = e;
        e--;
      }
      if (i > 1 and i < n - 1 and b != 0) {
        if (v[i - 1] > v[i] and v[i - 1] > v[i - 2]) {
          a--;
        }
        if (v[i - 1] < v[i] and v[i - 1] < v[i - 2]) {
          b--;
        }
      }
    }
  } else if (l > r and r == 0) {
    for (int i = 0; i < n; i++) {
      v[i] = i + 1;
    }
    swap(v[n - 1], v[n - 2]);
  } else if (l < r and l != 0) {
    int second = 1, e = n, a = l, b = r;
    for (int i = 0; i < n; i++) {
      if (a == 0) {
        v[i] = second;
        second++;
        continue;
      }
      if (i % 2 == 1) {
        v[i] = second;
        second++;
      } else {
        v[i] = e;
        e--;
      }
      if (i > 1 and i < n - 1 and a != 0) {
        if (v[i - 1] > v[i] and v[i - 1] > v[i - 2]) {
          a--;
        }
        if (v[i - 1] < v[i] and v[i - 1] < v[i - 2]) {
          b--;
        }
      }
    }
  } else if (l < r and l == 0) {
    for (int i = 0; i < n; i++) {
      v[i] = i + 1;
    }
    swap(v[0], v[1]);
  }
  int a = 0, b = 0;
  for (int i = 1; i < n - 1; i++) {
    if (v[i - 1] < v[i] and v[i] > v[i + 1]) {
      a++;
    }
    if (v[i - 1] > v[i] and v[i] < v[i + 1]) {
      b++;
    }
  }
  if (a != l or b != r) {
    cout << -1 << "\n";
  } else {
    for (int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
    cout << "\n";
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    solve();
  }
}
