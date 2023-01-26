#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e5 + 100;
const int MOD = 1e9 + 7;
vector<int> lst;
vector<pair<int, int> > dels;
int p[N], used[N], cnt[N], pairs[N], ans[N];
vector<int> a[N], b[N];
void gen_dels(const vector<pair<int, int> >& d, int x, int y,
              vector<int>& res) {
  if (x >= ((int)(d).size())) {
    res.push_back(y);
    return;
  }
  for (int i = 0; i <= d[x].second; ++i) {
    gen_dels(d, x + 1, y, res);
    y *= d[x].first;
  }
}
void init() {
  for (int i = 2; i < N; ++i) {
    if (p[i] == 0) {
      p[i] = i;
      lst.push_back(i);
    }
    for (int j = 0; j < ((int)(lst).size()) && lst[j] * i < N && lst[j] <= p[i];
         ++j) {
      p[lst[j] * i] = lst[j];
    }
    dels.clear();
    for (int j = i; j > 1; j /= p[j]) {
      if (((int)(dels).size()) == 0 || dels.back().first != p[j]) {
        dels.push_back(make_pair(p[j], 1));
      } else {
        ++(dels.back().second);
      }
    }
    gen_dels(dels, 0, 1, b[i]);
  }
}
int gcd(int a, int b) {
  while (b > 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int get(const vector<pair<int, int> >& d) {
  int res = 1;
  for (const pair<int, int>& x : d) {
    for (int i = 0; i < x.second; ++i) {
      res *= x.first;
    }
  }
  return res;
}
int gcd(const vector<pair<int, int> >& a, const vector<pair<int, int> >& b) {
  return gcd(get(a), get(b));
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    dels.clear();
    while (x > 1) {
      if (((int)(dels).size()) == 0 || dels.back().first != p[x]) {
        dels.push_back(make_pair(p[x], 1));
      } else {
        ++(dels.back().second);
      }
      x /= p[x];
    }
    gen_dels(dels, 0, 1, a[i]);
  }
  for (int g = 1; g <= n; ++g) {
    lst.clear();
    for (int i = g; i <= n; i += g) {
      for (int d : a[i]) {
        if (used[d] != g) {
          used[d] = g;
          cnt[d] = 0;
          lst.push_back(d);
        }
        ++cnt[d];
      }
    }
    sort((lst).begin(), (lst).end());
    for (int d : lst) {
      pairs[d] = (ll(cnt[d]) * cnt[d]) % MOD;
    }
    for (int i = ((int)(lst).size()) - 1; i >= 0; --i) {
      for (int d : b[lst[i]]) {
        if (d != lst[i]) {
          pairs[d] -= pairs[lst[i]];
          if (pairs[d] < 0) {
            pairs[d] += MOD;
          }
        }
      }
    }
    for (int d : lst) {
      ans[g] = (ans[g] + ll(d) * pairs[d]) % MOD;
    }
  }
  for (int g = n; g >= 1; --g) {
    for (int i = 2 * g; i <= n; i += g) {
      ans[g] -= ans[i];
      if (ans[g] < 0) {
        ans[g] += MOD;
      }
    }
  }
  int ans2 = 0;
  for (int g = 1; g <= n; ++g) {
    ans2 = (ans2 + ll(g) * ans[g]) % MOD;
  }
  printf("%d\n", ans2);
}
int main() {
  init();
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
