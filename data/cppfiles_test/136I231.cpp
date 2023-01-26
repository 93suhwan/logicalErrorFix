#include <bits/stdc++.h>
using namespace std;
void ha() { cout << "YES" << endl; }
void na() { cout << "NO" << endl; }
long long power(long long a, long long b) {
  long long c, d;
  if (b == 0) {
    return 1 % 1000000007;
  } else if (b == 1) {
    return a % 1000000007;
  } else if (b % 2 == 0) {
    c = power(a, b / 2);
    return (c * c) % 1000000007;
  } else {
    c = power(a, b / 2);
    d = (c * c) % 1000000007;
    d = (d * a) % 1000000007;
    return d;
  }
}
long long plainPower(long long a, long long b) {
  long long sum = 1, i;
  for (i = 1; i <= b; i++) {
    sum *= a;
  }
  return sum;
}
int absolute(int a) {
  if (a >= 0) {
    return a;
  } else {
    return (a * (-1));
  }
}
long long absolute(long long a) {
  if (a >= 0) {
    return a;
  } else {
    return (a * (-1));
  }
}
bool isPrime(int a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}
bool isTriangle(long long x1, long long y1, long long x2, long long y2,
                long long x3, long long y3) {
  long long area = (x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2));
  if (area) {
    return true;
  } else {
    return false;
  }
}
long long findRangeSum(long long hi, long long lo) {
  long long j = (hi * (hi + 1)) / 2;
  long long k = (lo * (lo + 1)) / 2;
  return j - k;
}
bool present(vector<int> &a, int n, int target) {
  int lo = 0, hi = n - 1, mid;
  while (lo <= hi) {
    mid = lo + ((hi - lo) / 2);
    if (a[mid] == target) {
      return true;
    } else if (a[mid] > target) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return false;
}
int Left_bound(vector<int> &a, int n, int target) {
  int lo = 0, hi = n - 1, mid, ans = -1;
  while (lo <= hi) {
    mid = lo + ((hi - lo) / 2);
    if (a[mid] <= target) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return ans + 1;
}
int Right_bound(vector<int> &a, int n, int target) {
  int lo = 0, hi = n - 1, mid, ans = n;
  while (lo <= hi) {
    mid = lo + ((hi - lo) / 2);
    if (a[mid] >= target) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ans + 1;
}
void debugger() {}
int cnt;
int target;
int dfs(vector<vector<int> > &adj, vector<int> &vis, vector<int> &val, int strt,
        int parent) {
  vis[strt] = val[strt];
  int xr = 0;
  for (int i = 0; i < adj[strt].size(); i++) {
    if (adj[strt][i] != parent) {
      xr = (xr ^ dfs(adj, vis, val, adj[strt][i], strt));
    }
  }
  vis[strt] = (xr ^ vis[strt]);
  if (vis[strt] == target) {
    cnt++;
    vis[strt] = 0;
  }
  return vis[strt];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long i, flag = 0, j, k, l, mini = 1000000007, minidx = -1;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < ((n * (n + 1)) / 2)) {
        flag = 1;
      }
      if (a[i] < mini) {
        mini = a[i];
        minidx = i;
      }
    }
    mini = a[minidx] - (((n * (n + 1)) / 2) - 1);
    if (flag) {
      na();
      continue;
    }
    k = 1;
    for (i = minidx; i < n; i++) {
      j = (k * mini);
      l = ((n * (n + 1)) / 2) - k;
      if (a[i % n] < l) {
        flag = 1;
        break;
      }
      k++;
    }
    if (flag) {
      na();
    } else {
      ha();
      for (i = 0; i < n; i++) {
        if (i == minidx) {
          cout << mini << " ";
        } else {
          cout << "1 ";
        }
      }
      cout << endl;
    }
  }
  return 0;
}
