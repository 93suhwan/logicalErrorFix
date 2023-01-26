#include <bits/stdc++.h>
using namespace std;
const int64_t Nmax = 2e5 + 10;
const int64_t mod = 1000000007;
vector<int64_t> prime;
int64_t is_power_of_two(int64_t a) { return a && (!(a & (a - 1))); }
int64_t isperfectsquare(int64_t a) {
  double b = sqrt(a);
  return (b - ceil(b) == 0);
}
int64_t pow(int64_t a, int64_t b, int64_t m) {
  a = a % m;
  int64_t res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b = b / 2;
  }
  return res;
}
int64_t mod_add(int64_t a, int64_t b, int64_t m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
int64_t mod_mul(int64_t a, int64_t b, int64_t m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
int64_t mod_sub(int64_t a, int64_t b, int64_t m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
int64_t mod_div(int64_t a, int64_t b, int64_t m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, pow(b, m - 2, m), m));
}
void sieve(int64_t n) {
  bool isprime[n + 1];
  memset(isprime, true, sizeof(isprime));
  prime.push_back(2);
  for (int64_t i = 3; i <= sqrt(n); i += 2) {
    if (isprime[i]) {
      for (int64_t j = i * i; j <= n; j += i) {
        isprime[j] = false;
      }
    }
  }
  for (int64_t i = 3; i <= n; i += 2) {
    if (isprime[i]) {
      prime.push_back(i);
    }
  }
}
vector<pair<int64_t, int64_t>> Getprimefactors(int64_t n) {
  vector<pair<int64_t, int64_t>> pr;
  for (int64_t i = 2; i <= sqrt(n); i++) {
    int64_t cnt = 0;
    while (n % i == 0) {
      cnt++;
      n /= i;
    }
    if (cnt) pr.push_back({i, cnt});
  }
  if (n > 1) {
    pr.push_back({n, 1});
  }
  return pr;
}
void solve() {
  int64_t n, od = 0, ev = 0, sub = 0, ans = 0;
  cin >> n;
  vector<int64_t> a(n), even, odd, fr(n, 0);
  for (int64_t i = 0; i <= n - 1; i++) {
    cin >> a[i];
    if (a[i] & 1) {
      od++;
      odd.push_back(i);
    } else {
      ev++;
      even.push_back(i);
    }
  }
  if (abs(od - ev) > 1) {
    cout << "-1\n";
    return;
  }
  bool oddd = true;
  if (n & 1) {
    if (od > ev) {
      oddd = true;
    } else {
      oddd = false;
    }
  } else {
    if (a[0] & 1) {
      oddd = true;
    } else {
      oddd = false;
    }
  }
  for (int64_t i = 0; i <= n - 1; i++) {
    if (fr[i]) {
      sub--;
      continue;
    }
    if (oddd && !(a[i] & 1)) {
      auto it = *odd.begin();
      ans += (it - i - sub);
      sub++;
      fr[it]++;
      odd.erase(odd.begin());
      even.erase(even.begin());
    } else if (!oddd && a[i] & 1) {
      auto it = *even.begin();
      ans += (it - i - sub);
      sub++;
      fr[it]++;
      even.erase(even.begin());
      odd.erase(odd.begin());
    } else {
      if (oddd) {
        odd.erase(odd.begin());
      } else {
        even.erase(even.begin());
      }
      oddd = !oddd;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
