#include <bits/stdc++.h>
using namespace std;
long long a, b, mod1 = 998244353, mod2 = 1000000007, mod3 = 4294967291;
string s1, s2;
struct ha {
  long long q1, q2, q3;
  bool operator==(const ha &aa) const {
    return (q1 == aa.q1 && q2 == aa.q2 && q3 == aa.q3);
  }
} has[500001], gg[500001], base[500001];
void mo(ha &qq) {
  qq.q1 %= mod1;
  qq.q1 += mod1;
  qq.q1 %= mod1;
  qq.q2 %= mod2;
  qq.q2 += mod2;
  qq.q2 %= mod2;
  qq.q3 %= mod3;
  qq.q3 += mod3;
  qq.q3 %= mod3;
}
ha get(long long ll, long long rr) {
  ha tt;
  tt.q1 = has[rr].q1 - has[ll - 1].q1 * base[rr - ll + 1].q1;
  tt.q2 = has[rr].q2 - has[ll - 1].q2 * base[rr - ll + 1].q2;
  tt.q3 = has[rr].q3 - has[ll - 1].q3 * base[rr - ll + 1].q3;
  mo(tt);
  return tt;
}
ha get1(long long ll, long long rr) {
  ha tt;
  tt.q1 = gg[rr].q1 - gg[ll - 1].q1 * base[rr - ll].q1;
  tt.q2 = gg[rr].q2 - gg[ll - 1].q2 * base[rr - ll].q2;
  tt.q3 = gg[rr].q3 - gg[ll - 1].q3 * base[rr - ll].q3;
  mo(tt);
  return tt;
}
int main() {
  base[0].q1 = base[0].q2 = base[0].q3 = 1;
  for (int i = 1; i <= 500000; i++) {
    base[i].q1 = base[i - 1].q1 * 10;
    base[i].q2 = base[i - 1].q2 * 10;
    base[i].q3 = base[i - 1].q3 * 10;
    mo(base[i]);
  }
  cin >> s1 >> s2;
  for (int i = 1; i <= s1.size(); i++) {
    has[i].q1 = has[i - 1].q1 * 10 + s1[i - 1] - '0';
    has[i].q2 = has[i - 1].q2 * 10 + s1[i - 1] - '0';
    has[i].q3 = has[i - 1].q3 * 10 + s1[i - 1] - '0';
    mo(has[i]);
  }
  for (int i = 1; i <= s2.size(); i++) {
    gg[i].q1 = gg[i - 1].q1 * 10 + s2[i - 1] - '0';
    gg[i].q2 = gg[i - 1].q2 * 10 + s2[i - 1] - '0';
    gg[i].q3 = gg[i - 1].q3 * 10 + s2[i - 1] - '0';
    mo(gg[i]);
  }
  b = s2.size();
  for (int i = s2.size() - 1; i + s2.size() - 1 <= s1.size(); i++) {
    ha f1 = get(i - b + 2, i), f2 = get(i + 1, i + b - 1);
    f1.q1 = f1.q1 + f2.q1, f1.q2 = f1.q2 + f2.q2, f1.q3 = f1.q3 + f2.q3;
    mo(f1);
    if (f1.q1 == gg[b].q1 && f1.q2 == gg[b].q2 && f1.q3 == gg[b].q3) {
      long long l1 = i - b + 2, r1 = i, l2 = i + 1, r2 = i + b - 1;
      printf("%lld %lld\n%lld %lld", l1, r1, l2, r2);
      return 0;
    }
  }
  for (int i = s2.size(); i <= s1.size(); i++) {
    long long ll = 1, rr = s2.size(), ann = 0;
    while (ll <= rr) {
      long long mid = ((ll + rr) >> 1);
      if (get(i - s2.size() + 1, i - s2.size() + mid) == get1(1, mid)) {
        ann = mid;
        ll = mid + 1;
      } else
        rr = mid - 1;
    }
    long long tt = i + b - ann;
    if (tt > s1.size() + 1) continue;
    ha f1, f2;
    if (s1[0] == '3' && s1[1] == '1' && tt >= 9681) {
      cout << i - s2.size() + 1 << " " << i << " " << i + 1 << " " << tt
           << "\n";
      f1 = get(i - s2.size() + 1, i), f2 = get(i + 1, tt);
      f1.q1 = f1.q1 + f2.q1, f1.q2 = f1.q2 + f2.q2, f1.q3 = f1.q3 + f2.q3;
      mo(f1);
      cout << f1.q1 << " " << f1.q2 << " " << f1.q3 << " " << gg[b].q1 << " "
           << gg[b].q2 << " " << gg[b].q3 << "\n";
    }
    if (i + 1 <= tt - 1) {
      f1 = get(i - s2.size() + 1, i), f2 = get(i + 1, tt - 1);
      f1.q1 = f1.q1 + f2.q1, f1.q2 = f1.q2 + f2.q2, f1.q3 = f1.q3 + f2.q3;
      mo(f1);
      if (f1.q1 == gg[b].q1 && f1.q2 == gg[b].q2 && f1.q3 == gg[b].q3) {
        long long l1 = i - s2.size() + 1, r1 = i, l2 = i + 1, r2 = tt - 1;
        printf("%lld %lld\n%lld %lld", l1, r1, l2, r2);
        return 0;
      }
    }
    if (tt <= s1.size() && i + 1 <= tt) {
      f1 = get(i - s2.size() + 1, i), f2 = get(i + 1, tt);
      f1.q1 = f1.q1 + f2.q1, f1.q2 = f1.q2 + f2.q2, f1.q3 = f1.q3 + f2.q3;
      mo(f1);
      if (f1.q1 == gg[b].q1 && f1.q2 == gg[b].q2 && f1.q3 == gg[b].q3) {
        long long l1 = i - s2.size() + 1, r1 = i, l2 = i + 1, r2 = tt;
        printf("%lld %lld\n%lld %lld", l1, r1, l2, r2);
        return 0;
      }
    }
  }
  for (int i = s1.size() - s2.size() + 1; i >= 1; i--) {
    long long ll = 1, rr = s2.size(), ann = 0;
    while (ll <= rr) {
      long long mid = ((ll + rr) >> 1);
      if (get(i, i + mid - 1) == get1(1, mid)) {
        ann = mid;
        ll = mid + 1;
      } else
        rr = mid - 1;
    }
    long long tt = i - (long long)(s2.size()) + ann;
    if (tt < 0) continue;
    ha f1, f2;
    if (tt + 1 <= i - 1) {
      f1 = get(i, i + s2.size() - 1), f2 = get(tt + 1, i - 1);
      f1.q1 = f1.q1 + f2.q1, f1.q2 = f1.q2 + f2.q2, f1.q3 = f1.q3 + f2.q3;
      mo(f1);
      if (f1.q1 == gg[b].q1 && f1.q2 == gg[b].q2 && f1.q3 == gg[b].q3) {
        long long l1 = tt + 1, r1 = i - 1, l2 = i, r2 = i + s2.size() - 1;
        printf("%lld %lld\n%lld %lld", l1, r1, l2, r2);
        return 0;
      }
    }
    if (tt > 0 && tt <= i - 1) {
      f1 = get(i, i + s2.size() - 1), f2 = get(i - s2.size() + ann, i - 1);
      f1.q1 = f1.q1 + f2.q1, f1.q2 = f1.q2 + f2.q2, f1.q3 = f1.q3 + f2.q3;
      mo(f1);
      if (f1.q1 == gg[b].q1 && f1.q2 == gg[b].q2 && f1.q3 == gg[b].q3) {
        long long l1 = tt, r1 = i - 1, l2 = i, r2 = i + s2.size() - 1;
        printf("%lld %lld\n%lld %lld", l1, r1, l2, r2);
        return 0;
      }
    }
  }
  return 0;
}
