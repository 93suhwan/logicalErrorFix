#include <bits/stdc++.h>
using namespace std;
const long long int M1 = 1e9 + 7;
const long long int M = 998244353;
const long long int M2 = 1000000000000000001;
long long int mod(long long int x) { return (x % M); }
long long int mod_minus(long long int a, long long int b) {
  long long int ans = (mod(a) - mod(b));
  if (ans < 0) ans = mod(ans + M);
  return ans;
}
long long int mod_mul(long long int a, long long int b) {
  return mod(mod(a) * mod(b));
}
long long int mod_add(long long int a, long long int b) {
  return mod(mod(a) + mod(b));
}
long long int ceill(long long int a, long long int b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
long long int extended_gcd(long long int a, long long int b, long long int &x,
                           long long int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long int x1, y1, ans = extended_gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return ans;
}
long long int power_mod(long long int a, long long int b, long long int m) {
  long long int ans = 1;
  while (b != 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    a = a * a;
    a %= m;
    b /= 2;
  }
  return ans;
}
long long int mod_inverse(long long int a, long long int m) {
  return power_mod(a, m - 2, m);
}
void mod_inverse_array(long long int inv[], long long int u, long long int m) {
  inv[1] = 1;
  for (long long int i = 2; i <= u; i++) {
    inv[i] = ((-(m / i) * inv[m % i] % m) + m) % m;
  }
}
long long int N_C_r_mod_m(long long int N, long long int r,
                          long long int factorial[]) {
  long long int a = factorial[N], b = mod_inverse(factorial[N - r], M),
                c = mod_inverse(factorial[r], M);
  return mod_mul(a, mod_mul(b, c));
}
void prime_factorization(long long int n,
                         unordered_map<long long int, long long int> &m) {
  long long int i = 2;
  while (n % i == 0) {
    m[i]++;
    n = n / i;
  }
  for (i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      m[i]++;
      n = n / i;
    }
  }
  if (n != 1) m[n]++;
}
void linear_sieve(vector<long long int> &pr, long long int lp[],
                  long long int N) {
  for (long long int i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (long long int j = 0;
         j < (long long int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
      lp[i * pr[j]] = pr[j];
  }
}
bool isPowerOfTwo(long long int x) { return x && (!(x & (x - 1))); }
struct segtree {
  long long int size;
  vector<long long int> value;
  void init(long long int n) {
    size = 1;
    while (size < n) {
      size *= 2;
    }
    value.assign(2 * size, 0);
  }
  void build(vector<long long int> &A, long long int x, long long int lx,
             long long int rx) {
    if (rx - lx <= 1) {
      if (lx < A.size()) {
        value[x] = A[lx];
      }
      return;
    }
    long long int m = (lx + rx) / 2;
    build(A, 2 * x + 1, lx, m);
    build(A, 2 * x + 2, m, rx);
    value[x] = min(value[2 * x + 1], value[2 * x + 2]);
  }
  void build(vector<long long int> &A) { build(A, 0, 0, size); }
  void set(long long int i, long long int v, long long int x, long long int lx,
           long long int rx) {
    if ((rx - lx <= 1)) {
      value[x] = v;
      return;
    }
    long long int m = (lx + rx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    value[x] = min(value[2 * x + 1], value[2 * x + 2]);
  }
  void set(long long int i, long long int v) { set(i, v, 0, 0, size); }
  long long int calc(long long int l, long long int r, long long int x,
                     long long int lx, long long int rx) {
    if (lx >= r || rx <= l) return M2;
    if (lx >= l && rx <= r) return value[x];
    long long int m = (lx + rx) / 2;
    long long int s1 = calc(l, r, 2 * x + 1, lx, m);
    long long int s2 = calc(l, r, 2 * x + 2, m, rx);
    return min(s1, s2);
  }
  long long int calc(long long int l, long long int r) {
    return calc(l, r, 0, 0, size);
  }
};
void solve() {
  long long int n;
  cin >> n;
  vector<string> s(n);
  long long int oa = 0, ob = 0, oc = 0, od = 0, oe = 0;
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> s[i];
  }
  long long int ca[n], cb[n], ce[n], cd[n], cc[n];
  for (long long int i = 0; i <= n - 1; i++) {
    long long int l = s[i].size();
    long long int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (char ch : s[i]) {
      if (ch == 'a') {
        a++;
      } else if (ch == 'b') {
        b++;
      } else if (ch == 'c') {
        c++;
      } else if (ch == 'd') {
        d++;
      } else {
        e++;
      }
    }
    oa += a;
    ob += b;
    oc += c;
    od += d;
    oe += e;
    ca[i] = l - 2 * a;
    cb[i] = l - 2 * b;
    cc[i] = l - 2 * c;
    cd[i] = l - 2 * d;
    ce[i] = l - 2 * e;
  }
  sort(ca, ca + n, greater<long long int>());
  sort(cb, cb + n, greater<long long int>());
  sort(cc, cc + n, greater<long long int>());
  sort(cd, cd + n, greater<long long int>());
  sort(ce, ce + n, greater<long long int>());
  long long int ans = 0;
  long long int L = oa + ob + oc + od + oe;
  long long int ansa = n;
  oa *= 2;
  ob *= 2;
  oc *= 2;
  od *= 2;
  oe *= 2;
  for (long long int i = 0; i <= n - 1; i++) {
    if (oa > L) {
      break;
    } else {
      ansa--;
      oa += (ca[i]);
    }
  }
  ans = max(ans, ansa);
  ansa = n;
  for (long long int i = 0; i <= n - 1; i++) {
    if ((ob) > L) {
      break;
    } else {
      ansa--;
      ob += (cb[i]);
    }
  }
  ans = max(ans, ansa);
  ansa = n;
  for (long long int i = 0; i <= n - 1; i++) {
    if ((oc) > L) {
      break;
    } else {
      ansa--;
      oc += (cc[i]);
    }
  }
  ans = max(ans, ansa);
  ansa = n;
  for (long long int i = 0; i <= n - 1; i++) {
    if ((od) > L) {
      break;
    } else {
      ansa--;
      od += (cd[i]);
    }
  }
  ans = max(ans, ansa);
  ansa = n;
  for (long long int i = 0; i <= n - 1; i++) {
    if ((oe) > L) {
      break;
    } else {
      ansa--;
      oe += (ce[i]);
    }
  }
  ans = max(ans, ansa);
  cout << ans << "\n";
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
