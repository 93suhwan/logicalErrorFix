#include <bits/stdc++.h>
using namespace std;
const long long xxx = 1e4;
const long long maxn = xxx + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 998244353;
const double pi = acos(-1.0);
inline void updmin(long long& a, long long b) { a > b ? a = b : 0; }
inline void updmax(long long& a, long long b) { a < b ? a = b : 0; }
long long ans[maxn], cnt[2];
int main(int argc, char const* argv[]) {
  int cases;
  cin >> cases;
  for (int cas = 1; cas <= cases; cas++) {
    long long n;
    cin >> n;
    fill_n(ans + 1, n, -1);
    long long p = 0, pre = 0, pos;
    for (p = 1; p <= n - 2; p += 3) {
      cout << "? " << p << " " << p + 1 << " " << p + 2 << "\n";
      cout.flush();
      long long res;
      cin >> res;
      if (p > 1 && res != pre) {
        pos = p;
      }
      ans[p] = res;
      pre = res;
    }
    pre = -1;
    for (p = pos - 3; p <= pos; p += 1) {
      long long res;
      if (ans[p] != -1) {
        res = ans[p];
      } else {
        cout << "? " << p << " " << p + 1 << " " << p + 2 << "\n";
        cout.flush();
        cin >> res;
      }
      if (p > pos - 3 && res != pre) {
        break;
      }
      ans[p] = res;
      pre = res;
    }
    long long tag[2];
    ans[p - 1] = pre;
    tag[pre] = p - 1;
    ans[p + 2] = pre ^ 1;
    tag[pre ^ 1] = p + 2;
    cnt[0] = cnt[1] = 1;
    for (long long i = pos - 3; i <= pos; i += 1) {
      if (i == p - 1 || i == p + 2) {
        continue;
      }
      cout << "? " << i << " " << p - 1 << " " << p + 2 << "\n";
      cout.flush();
      long long res;
      cin >> res;
      ans[i] = res;
      cnt[res] += 1;
    }
    for (long long i = 1; i <= n; i += 3) {
      if (i == pos || i == pos - 3) {
        continue;
      }
      long long prio = ans[i];
      long long tp[2];
      for (long long j = 0; j <= 1; j++) {
        cout << "? " << i + j << " " << i + j + 1 << " " << tag[prio ^ 1]
             << "\n";
        cout.flush();
        long long res;
        cin >> res;
        tp[j] = res;
      }
      if (tp[0] == prio && tp[1] == prio) {
        ans[i] = ans[i + 1] = ans[i + 2] = prio;
      } else if (tp[1] == prio) {
        ans[i] = prio ^ 1;
        ans[i + 1] = ans[i + 2] = prio;
      } else if (tp[0] == prio) {
        ans[i + 2] = prio ^ 1;
        ans[i] = ans[i + 1] = prio;
      } else {
        ans[i] = ans[i + 2] = prio;
        ans[i + 1] = prio;
      }
      for (long long j = 0; j <= 2; j++) {
        cnt[ans[i + j]] += 1;
      }
    }
    cout << "! " << cnt[0] << " ";
    for (long long i = 1; i <= n; i++) {
      if (ans[i] == 0) {
        cout << i << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
