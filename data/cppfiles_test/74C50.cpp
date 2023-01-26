#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using db = double;
using ldb = long double;
const int maxn = 1000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
const int MAXA = 1000000;
int a[maxn + 5];
int cnt[MAXA + 5];
int ans[maxn + 5];
bitset<13000005> ok[14];
void solve(vi &A) {
  int n = (int)A.size();
  ans[1] = (A[0] + A[1] - A[2]) / 2;
  ans[2] = A[0] - ans[1];
  ans[3] = A[1] - ans[1];
  for (auto i = 3; i <= n - 1; i++) ans[i + 1] = A[i] - ans[1];
  puts("YES");
  for (auto i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
  exit(0);
}
int main() {
  int n;
  scanf("%d", &n);
  for (auto i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (auto i = 1; i <= n; i++) cnt[a[i]]++;
  for (auto i = 1; i <= MAXA; i++)
    if (cnt[i] > 1) {
      int tot = 0;
      for (auto i = 1; i <= n; i++)
        if (cnt[a[i]]) {
          ans[++tot] = a[i];
          cnt[a[i]] = 0;
        }
      puts("YES");
      for (auto i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
      return 0;
    }
  if (n == 2) return puts("NO"), 0;
  vi odd, even;
  for (auto i = 1; i <= n; i++)
    if (a[i] & 1)
      odd.push_back(a[i]);
    else
      even.push_back(a[i]);
  if ((int)odd.size() == 1) {
    if ((int)even.size() <= 2) return puts("NO"), 0;
    vi tmp;
    for (auto x : even) tmp.push_back(x);
    for (auto x : odd) tmp.push_back(x);
    solve(tmp);
  } else if ((int)odd.size() == 0)
    solve(even);
  else if ((int)even.size()) {
    vi tmp;
    tmp.push_back(even.back());
    even.pop_back();
    for (auto x : odd) tmp.push_back(x);
    for (auto x : even) tmp.push_back(x);
    solve(tmp);
  } else {
    int nn = min(27, n);
    int N = 1 << nn;
    for (auto msk = 1; msk <= N - 1; msk++)
      if (__builtin_popcount(msk) <= 13) {
        int c = __builtin_popcount(msk);
        int sum = 0;
        for (int S = msk; S; S -= S & -S) sum += a[__builtin_ctz(S) + 1];
        if (ok[c][sum]) {
          for (auto msk2 = 1; msk2 <= N - 1; msk2++)
            if (__builtin_popcount(msk2) == c) {
              int sum2 = 0;
              for (int S = msk2; S; S -= S & -S)
                sum2 += a[__builtin_ctz(S) + 1];
              if (sum2 == sum) {
                vi A, B;
                for (auto i = 0; i <= 26; i++)
                  if (msk >> i & 1) A.push_back(a[i + 1]), cnt[a[i + 1]] = 0;
                for (auto i = 0; i <= 26; i++)
                  if (msk2 >> i & 1) B.push_back(a[i + 1]), cnt[a[i + 1]] = 0;
                vi C;
                for (auto i = 0; i <= (int)A.size() - 1; i++)
                  C.push_back(A[i]), C.push_back(B[i]);
                int now = 0;
                int tot = 0;
                for (auto x : C) {
                  now = x - now;
                  ans[++tot] = now;
                }
                for (auto i = 1; i <= n; i++)
                  if (cnt[a[i]]) ans[++tot] = a[i] - now;
                puts("YES");
                for (auto i = 1; i <= n; i++)
                  printf("%d%c", ans[i], " \n"[i == n]);
                return 0;
              }
            }
        }
        ok[c].set(sum);
      }
  }
  puts("NO");
  return 0;
}
