#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long double Pi = 3.141592653;
const long long mod = 998244353;
long long INF = 1000000000000000000;
struct mycmp {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    return (a.first < b.first) || (a.first == b.first && a.second > b.second);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    vector<long long> arr(n + 1, 0);
    int diff = abs(a - b);
    if (a == b) {
      arr[1] = 1;
      arr[2] = n;
      int idx = 3;
      s.erase(1);
      s.erase(n);
      while (idx <= n) {
        if (a == 0 && b == 0) break;
        arr[idx] = *s.begin();
        s.erase(s.begin());
        --a;
        ++idx;
        if (idx <= n) {
          arr[idx] = *s.rbegin();
          int y = *s.rbegin();
          s.erase(y);
          ++idx;
          --b;
        }
      }
      if (a == 0 && b == 0) {
        while (idx <= n) {
          arr[idx] = *s.begin();
          ++idx;
          s.erase(s.begin());
        }
        for (long long i = 1; i <= n; i++) cout << arr[i] << " ";
        cout << "\n";
      } else
        cout << -1 << "\n";
    } else if (a == b + 1) {
      arr[1] = 1;
      arr[2] = n;
      int idx = 3;
      s.erase(1);
      s.erase(n);
      while (idx <= n) {
        if (b == 0) break;
        arr[idx] = *s.begin();
        s.erase(s.begin());
        --a;
        ++idx;
        if (idx <= n) {
          arr[idx] = *s.rbegin();
          int y = *s.rbegin();
          s.erase(y);
          ++idx;
          --b;
        }
      }
      if (a) {
        if (idx <= n) {
          arr[idx] = *s.rbegin();
          int y = *s.rbegin();
          s.erase(y);
          ++idx;
          --a;
        }
        while (idx <= n) {
          if (a == 0) break;
          arr[idx] = *s.rbegin();
          int y = *s.rbegin();
          s.erase(y);
          ++idx;
          if (idx <= n) {
            arr[idx] = *s.rbegin();
            ++idx;
            --a;
            y = *s.rbegin();
            s.erase(y);
            if (idx <= n) {
              arr[idx] = *s.begin();
              s.erase(s.begin());
              ++idx;
            }
          }
        }
      }
      if (a == 0 && b == 0) {
        while (idx <= n) {
          arr[idx] = *s.begin();
          ++idx;
          s.erase(s.begin());
        }
        for (long long i = 1; i <= n; i++) cout << arr[i] << " ";
        cout << "\n";
      } else
        cout << -1 << "\n";
    } else if (b == a + 1) {
      arr[1] = n;
      arr[2] = 1;
      int idx = 3;
      s.erase(1);
      s.erase(n);
      while (idx <= n) {
        if (a == 0) break;
        arr[idx] = *s.rbegin();
        int y = *s.rbegin();
        s.erase(y);
        --b;
        ++idx;
        if (idx <= n) {
          arr[idx] = *s.begin();
          int y = *s.begin();
          s.erase(y);
          ++idx;
          --a;
        }
      }
      if (b) {
        if (idx <= n) {
          arr[idx] = *s.begin();
          int y = *s.begin();
          s.erase(y);
          ++idx;
          --b;
        }
        while (idx <= n) {
          if (b == 0) break;
          arr[idx] = *s.begin();
          int y = *s.begin();
          s.erase(y);
          ++idx;
          if (idx <= n) {
            arr[idx] = *s.begin();
            s.erase(s.begin());
            ++idx;
            --b;
            if (idx <= n) {
              arr[idx] = *s.rbegin();
              y = *s.rbegin();
              s.erase(y);
              ++idx;
            }
          }
        }
      }
      if (a == 0 && b == 0) {
        while (idx <= n) {
          arr[idx] = *s.begin();
          ++idx;
          s.erase(s.begin());
        }
        for (long long i = 1; i <= n; i++) cout << arr[i] << " ";
        cout << "\n";
      } else
        cout << -1 << "\n";
    } else
      cout << -1 << "\n";
  }
}
