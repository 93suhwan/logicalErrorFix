#include <bits/stdc++.h>
const long long mod = 998244353;
const int maxn = 1023 * 5;
long long qpow[maxn];
long long inv_qpow[maxn];
int get_inv(int val) {
  int nume = mod - 2;
  int ans = 1;
  while (nume) {
    if (nume & 1) {
      ans = 1ll * val * ans % mod;
    }
    val = 1ll * val * val % mod;
    nume >>= 1;
  }
  return ans;
}
void init_data() {
  qpow[0] = 1;
  for (int i = 1; i < maxn; i++) {
    qpow[i] = 1ll * qpow[i - 1] * i % mod;
  }
  inv_qpow[maxn - 1] = get_inv(qpow[maxn - 1]);
  for (int i = maxn - 1; i > 0; i--) {
    inv_qpow[i - 1] = 1ll * inv_qpow[i] * i % mod;
  }
}
int get_C(int m, int n) {
  if (m < n) {
    return 0;
  }
  long long ans = 1;
  ans = qpow[m] * inv_qpow[n] % mod;
  ans = ans * inv_qpow[m - n] % mod;
  return ans;
}
char char_s[maxn];
int rec_num[maxn];
int main() {
  init_data();
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", char_s);
  if (k == 0) {
    printf("1\n");
    return 0;
  }
  rec_num[0] = (char_s[0] == '1');
  for (int i = 1; i < n; i++) {
    rec_num[i] = (char_s[i] == '1') + rec_num[i - 1];
  }
  if (rec_num[n - 1] < k) {
    printf("1\n");
    return 0;
  }
  long long ans = 0;
  for (int left_ = 0; left_ < n; left_++) {
    int last_num = left_ == 0 ? 0 : rec_num[left_ - 1];
    int right_ =
        std::upper_bound(rec_num, rec_num + n, last_num + k) - rec_num - 1;
    if (rec_num[right_] - last_num < k) {
      break;
    }
    int len_ = right_ - left_ + 1;
    if (char_s[left_] == '0') {
      ans = (ans + get_C(len_ - 1, k - 1)) % mod;
    } else {
      ans = (ans + get_C(len_ - 1, k)) % mod;
      if (right_ == n - 1) {
        ans = (ans + get_C(len_ - 1, k - 1)) % mod;
      }
    }
  }
  printf("%lld\n", ans);
}
