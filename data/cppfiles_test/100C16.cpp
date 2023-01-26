#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
template <typename T>
T add(T x) {
  return x;
}
template <typename T, typename... Ts>
T add(T x, Ts... y) {
  T res = x + add(y...);
  if (res >= MOD) res -= MOD;
  return res;
}
template <typename T, typename... Ts>
T sub(T x, Ts... y) {
  return add(x, MOD - add(y...));
}
template <typename T, typename... Ts>
void udd(T& x, Ts... y) {
  x = add(x, y...);
}
template <typename T>
T mul(T x) {
  return x;
}
template <typename T, typename... Ts>
T mul(T x, Ts... y) {
  return (x * 1ll * mul(y...)) % MOD;
}
template <typename T, typename... Ts>
void uul(T& x, Ts... y) {
  x = mul(x, y...);
}
int bin(long long a, long long deg) {
  int r = 1;
  while (deg) {
    if (deg & 1) uul(r, a);
    deg >>= 1;
    uul(a, a);
  }
  return r;
}
long long inv(long long x) {
  assert(x);
  return bin(x, MOD - 2);
}
vector<long long> fac(2 * 1e5 + 1);
void precalc() {
  fac[0] = 1;
  for (int i = 1; i <= 2 * 1e5; ++i) {
    fac[i] = mul(fac[i - 1], i);
  }
}
long long solve(size_t n, vector<int>& a) {
  long long maxx = a[0];
  long long maxx_cnt = 1;
  long long second_max = -1;
  long long second_max_cnt = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > maxx) {
      second_max = maxx;
      second_max_cnt = maxx_cnt;
      maxx = a[i];
      maxx_cnt = 1;
    } else if (a[i] == maxx) {
      ++maxx_cnt;
    } else if (second_max < a[i] && a[i] < maxx) {
      second_max = a[i];
      second_max_cnt = 1;
    } else if (a[i] == second_max) {
      ++second_max_cnt;
    }
  }
  if (second_max == -1) {
    return fac[n];
  }
  if (maxx_cnt > 1) {
    return fac[n];
  }
  if (second_max != maxx - 1) {
    return 0;
  }
  return mul(fac[n], inv(second_max_cnt + 1), second_max_cnt);
}
int getNext(vector<int>& a, int cur) {
  int n = a.size();
  int i = (cur + 1) % n;
  while (a[i] == 0) {
    i = (i + 1) % n;
    if (i == cur) {
      return cur;
    }
  }
  return i;
}
bool eval(vector<int>& a) {
  int i = 0;
  int next;
  int total_sum = 0;
  for (auto& val : a) {
    total_sum += val;
  }
  do {
    next = getNext(a, i);
    if (i == next) {
      if (total_sum == 1) {
        return true;
      }
      return false;
    }
    --a[i];
    --total_sum;
    i = next;
  } while (next != -1);
  return true;
}
long long getAns(vector<int>& initial_perm) {
  size_t n = initial_perm.size();
  vector<int> perm(n);
  for (int i = 0; i < n; ++i) {
    perm[i] = i;
  }
  long long ans = 0;
  vector<int> input(n);
  do {
    for (int i = 0; i < n; ++i) {
      input[i] = initial_perm[perm[i]];
    }
    if (eval(input)) {
      ans = (ans + 1) % MOD;
    }
  } while (next_permutation(perm.begin(), perm.end()));
  return ans;
}
int main() {
  precalc();
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& val : a) {
      cin >> val;
    }
    cout << solve(n, a) << endl;
  }
}
