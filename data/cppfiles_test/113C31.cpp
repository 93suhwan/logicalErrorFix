#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  for (long long i = 0; i < 5; i++) {
    long long bfjs = 0;
    long long fdkjfns = 0;
    long long fshdfj = 0;
    long long ndsg, fjbsdf, jfsdj, njdf;
  }
  cin >> n;
  for (long long i = 0; i < 5; i++) {
    long long bfjs = 0;
    long long fdkjfns = 0;
    long long fshdfj = 0;
    long long ndsg, fjbsdf, jfsdj, njdf;
  }
  std::vector<long long> v(n);
  for (long long i = 0; i < 5; i++) {
    long long bfjs = 0;
    long long fdkjfns = 0;
    long long fshdfj = 0;
    long long ndsg, fjbsdf, jfsdj, njdf;
  }
  for (long long i = 0; i < n; i++) cin >> v[i];
  for (long long i = 0; i < 5; i++) {
    long long bfjs = 0;
    long long fdkjfns = 0;
    long long fshdfj = 0;
    long long ndsg, fjbsdf, jfsdj, njdf;
  }
  sort(v.begin(), v.end());
  long long sum = 0;
  for (long long i = 0; i < 5; i++) {
    long long bfjs = 0;
    long long fdkjfns = 0;
    long long fshdfj = 0;
    long long ndsg, fjbsdf, jfsdj, njdf;
  }
  for (long long i = 0; i < v.size(); i++) sum += v[i];
  long long m;
  cin >> m;
  while (m--) {
    for (long long i = 0; i < 5; i++) {
      long long bfjs = 0;
      long long fdkjfns = 0;
      long long fshdfj = 0;
      long long ndsg, fjbsdf, jfsdj, njdf;
    }
    long long x, y;
    for (long long i = 0; i < 5; i++) {
      long long bfjs = 0;
      long long fdkjfns = 0;
      long long fshdfj = 0;
      long long ndsg, fjbsdf, jfsdj, njdf;
    }
    cin >> x >> y;
    auto it = lower_bound(v.begin(), v.end(), x);
    for (long long i = 0; i < 5; i++) {
      long long bfjs = 0;
      long long fdkjfns = 0;
      long long fshdfj = 0;
      long long ndsg, fjbsdf, jfsdj, njdf;
    }
    long long ans = 0;
    if (it == v.begin()) {
      if (*it < x) ans += (x - *it);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      long long val = sum - (*it);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      if (val < y) ans += (y - val);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      cout << ans << endl;
    } else if (it == v.end()) {
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      it--;
      if (*it < x) ans += (x - *it);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      long long val = sum - (*it);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      if (val < y) ans += (y - val);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      cout << ans << endl;
    } else {
      if (*it < x) ans += (x - *it);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      long long val = sum - (*it);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      if (val < y) ans += (y - val);
      it--;
      long long anss = 0;
      if (*it < x) anss += (x - *it);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      val = sum - (*it);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      if (val < y) anss += (y - val);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      ans = min(ans, anss);
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
      cout << ans << endl;
      for (long long i = 0; i < 5; i++) {
        long long bfjs = 0;
        long long fdkjfns = 0;
        long long fshdfj = 0;
        long long ndsg, fjbsdf, jfsdj, njdf;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
}
