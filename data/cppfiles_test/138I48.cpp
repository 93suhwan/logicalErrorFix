#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using PII = pair<int, int>;
const int N = 1 << 18;
int p[N], cnt[N];
LL pref[2 * N];
LL ANS = 0;
int par(int a) {
  if (p[a] == a) return a;
  return p[a] = par(p[a]);
}
void upd(int a, int mul) {
  a = par(a);
  LL sum = pref[a + 1] - pref[a - cnt[a] + 1];
  ANS += sum * mul;
}
void unite(int a, int b) {
  a = par(a);
  b = par(b);
  if (a == b) assert(0);
  upd(a, -1);
  upd(b, -1);
  p[a] = b;
  cnt[b] += cnt[a];
  upd(b, 1);
}
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<PII> arr(n + m), when;
  for (int i = (0); i < (n); ++i) {
    cin >> arr[i].first;
    arr[i].second = 1;
    ANS += arr[i].first;
  }
  for (int i = (0); i < (m); ++i) {
    cin >> arr[i + n].first;
    arr[i + n].second = 0;
  }
  sort(arr.begin(), arr.end());
  for (int i = (0); i < (n + m); ++i) {
    pref[i + 1] = pref[i] + arr[i].first;
    if (i) when.push_back(make_pair(arr[i].first - arr[i - 1].first, i));
    p[i] = i;
    cnt[i] = arr[i].second;
  }
  sort(when.begin(), when.end());
  vector<PII> K(q);
  VI ans(q);
  for (int i = (0); i < (q); ++i) {
    cin >> K[i].first;
    K[i].second = i;
  }
  sort(K.begin(), K.end());
  int i = 0, j = 0;
  while (true) {
    if (i != (int)when.size() && when[i].first <= K[j].first) {
      int I = when[i].second;
      i++;
      unite(I - 1, I);
      continue;
    }
    ans[K[j].second] = ANS;
    j++;
    if (j == q) break;
  }
  for (int k = (0); k < (q); ++k) cout << ans[k] << "\n";
  return 0;
}
