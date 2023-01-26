#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int n, k;
int b[1010], done[1010], a[1010];
vector<pair<int, int> > od, ev;
unordered_map<int, int> rec[14];
const int max_siz = 13;
int mask1, mask2;
bool found;
int mask, sum, siz;
void dfs(int x) {
  if (siz > max_siz) return;
  if (found) return;
  if (x == k) {
    if (!siz) return;
    if (rec[siz].count(sum)) {
      mask1 = rec[siz][sum];
      mask2 = mask;
      found = 1;
      return;
    } else
      rec[siz][sum] = mask;
    return;
  }
  mask += (1 << x);
  sum += b[x];
  siz++;
  dfs(x + 1);
  mask -= (1 << x);
  sum -= b[x];
  siz--;
  dfs(x + 1);
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < int(n); i++) cin >> b[i];
  srand(7122);
  random_shuffle(b, b + n);
  for (int i = 0; i < int(n); i++) {
    if (b[i] & 1)
      od.push_back(make_pair(b[i], i));
    else
      ev.push_back(make_pair(b[i], i));
  }
  if (n == 2) {
    if (b[0] == b[1]) {
      cout << "YES" << '\n';
      cout << 0 << " " << b[0] << '\n';
    } else
      cout << "NO" << '\n';
    return 0;
  }
  if (n == 3) {
    if (b[0] == b[1]) {
      cout << "YES" << '\n';
      cout << 0 << " " << b[0] << " " << b[2] - b[0] << '\n';
    } else if (b[1] == b[2]) {
      cout << "YES" << '\n';
      cout << 0 << " " << b[1] << " " << b[0] - b[1] << '\n';
    } else if (b[0] == b[2]) {
      cout << "YES" << '\n';
      cout << 0 << " " << b[0] << " " << b[1] - b[0] << '\n';
    } else if ((b[0] + b[1] + b[2]) % 2 == 0) {
      cout << "YES" << '\n';
      cout << (-b[0] + b[1] + b[2]) / 2 << " " << (b[0] - b[1] + b[2]) / 2
           << " " << (b[0] + b[1] - b[2]) / 2 << '\n';
    } else
      cout << "NO" << '\n';
    return 0;
  }
  if (ev.size() >= 3) {
    cout << "YES" << '\n';
    a[0] = (-ev[0].first + ev[1].first + ev[2].first) / 2;
    a[1] = (ev[0].first - ev[1].first + ev[2].first) / 2;
    a[2] = (ev[0].first + ev[1].first - ev[2].first) / 2;
    done[ev[0].second] = 1;
    done[ev[1].second] = 1;
    done[ev[2].second] = 1;
    int cur = 3;
    for (int i = 0; i < int(n); i++) {
      if (!done[i]) {
        a[cur++] = b[i] - a[0];
      }
    }
    for (int i = 0; i < int(n); i++) cout << a[i] << " ";
    cout << '\n';
    return 0;
  }
  if (ev.size() >= 1 && od.size() >= 2) {
    cout << "YES" << '\n';
    a[0] = (-od[0].first + od[1].first + ev[0].first) / 2;
    a[1] = (od[0].first - od[1].first + ev[0].first) / 2;
    a[2] = (od[0].first + od[1].first - ev[0].first) / 2;
    done[od[0].second] = 1;
    done[od[1].second] = 1;
    done[ev[0].second] = 1;
    int cur = 3;
    for (int i = 0; i < int(n); i++) {
      if (!done[i]) a[cur++] = b[i] - a[0];
    }
    for (int i = 0; i < int(n); i++) cout << a[i] << " ";
    cout << '\n';
    return 0;
  }
  k = min(n, 27);
  dfs(0);
  if (!found) {
    cout << "NO" << '\n';
    return 0;
  }
  for (int i = 0; i < int(k); i++) {
    if ((mask1 & (1 << i)) == (1 << i) && (mask2 & (1 << i)) == (1 << i)) {
      mask1 -= (1 << i);
      mask2 -= (1 << i);
    }
  }
  vector<int> v1, v2, v;
  for (int i = 0; i < int(k); i++) {
    if ((mask1 & (1 << i)) == (1 << i)) {
      mask1 -= (1 << i);
      v1.push_back(i);
      done[i] = 1;
    }
    if ((mask2 & (1 << i)) == (1 << i)) {
      mask2 -= (1 << i);
      v2.push_back(i);
      done[i] = 1;
    }
  }
  for (int i = 0; i < int(v1.size()); i++) {
    v.push_back(v1[i]);
    if (i != v1.size() - 1) v.push_back(v2[i]);
  }
  cout << "YES" << '\n';
  a[0] = 0;
  for (int i = 0; i < int(v.size()); i++) a[i + 1] = b[v[i]] - a[i];
  int cur = v.size() + 1;
  for (int i = 0; i < int(n); i++) {
    if (!done[i]) a[cur++] = b[i] - a[0];
  }
  for (int i = 0; i < int(n); i++) cout << a[i] << " ";
  cout << '\n';
}
