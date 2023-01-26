#include <bits/stdc++.h>
using namespace std;
const int B = 600;
int tcnt[300001];
long long tree[300001], V[B + 1];
void update(int n) {
  for (int v = n;; n++) {
    tree[n] += v;
    tcnt[n]++;
    if (n % B == B - 1) break;
  }
}
long long get_sum(int s, int e) {
  if (s / B == e / B) return tree[e] - (s % B ? tree[s - 1] : 0);
  long long ret = tree[s / B * B + B - 1] - (s % B ? tree[s - 1] : 0) + tree[e];
  s = s / B * B + B;
  e = e / B * B;
  while (s + B - 1 < e) {
    ret += tree[s + B - 1];
    s += B;
  }
  return ret;
}
int get_cnt(int s, int e) {
  if (s / B == e / B) return tcnt[e] - (s % B ? tcnt[s - 1] : 0);
  int ret = tcnt[s / B * B + B - 1] - (s % B ? tcnt[s - 1] : 0) + tcnt[e];
  s = s / B * B + B;
  e = e / B * B;
  while (s + B - 1 < e) {
    ret += tcnt[s + B - 1];
    s += B;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ((void)0);
  ((void)0);
  ((void)0);
  int N;
  long long ans = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a <= B)
      ans += V[a];
    else {
      long long cv;
      int cc, n;
      for (int i = 1; i <= a; i = n) {
        n = a / (a / i) + 1;
        cv = get_sum(i, n - 1);
        cc = get_cnt(i, n - 1);
        ans += cv;
        ans += 1LL * cc * a - (a / i) * cv;
      }
      for (int i = 2 * a;; i += a) {
        cv = get_sum(i - a, min(i - 1, 300000));
        cc = get_cnt(i - a, min(i - 1, 300000));
        ans += cv - 1LL * cc * (i - a);
        ans += 1LL * a * cc;
        if (i > 300000) break;
      }
    }
    for (int i = 1; i <= B; i++) V[i] += a % i + i % a;
    update(a);
    cout << ans << ' ';
  }
  return 0;
}
