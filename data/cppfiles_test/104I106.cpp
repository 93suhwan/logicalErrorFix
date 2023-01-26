#include <bits/stdc++.h>
using namespace std;
mt19937 rng((long long)chrono::steady_clock::now().time_since_epoch().count());
const long long mod = 1e9 + 7;
long long n, a[200010];
void op_ida(long long Ini, vector<long long> &ans) {
  for (long long ini = Ini; ini <= n - 2; ini++) {
    long long meio = ini + 1, fim = ini + 2;
    if (a[meio] == 0) continue;
    if (a[fim] == 1) {
      ans.push_back(ini);
      a[meio] = a[fim] = 0;
      continue;
    }
    if (meio <= n - 2) {
      if (a[fim + 1] == 1) {
        ans.push_back(meio);
        a[meio] = a[fim + 1] = 0;
      } else {
        ans.push_back(meio);
        ans.push_back(ini);
        a[meio] = a[fim] = 0;
        a[fim + 1] = 1;
      }
      continue;
    }
    cout << "NO\n";
    exit(0);
  }
}
void op_volta(long long Ini, vector<long long> &ans) {
  for (long long ini = Ini; ini >= 3; ini--) {
    long long meio = ini - 1, fim = ini - 2;
    if (a[meio] == 0) continue;
    if (a[fim] == 1) {
      ans.push_back(fim);
      a[meio] = a[fim] = 0;
      continue;
    }
    if (meio >= 3) {
      if (a[fim - 1] == 1) {
        ans.push_back(fim - 1);
        a[meio] = a[fim - 1] = 0;
      } else {
        ans.push_back(fim - 1);
        ans.push_back(fim);
        a[meio] = a[fim] = 0;
        a[fim - 1] = 1;
      }
      continue;
    }
    cout << "NO\n";
    exit(0);
  }
}
void solve() {
  cin >> n;
  a[n + 1] = a[0] = 0;
  long long tot = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    tot += a[i];
    cout << a[i] << " ";
  }
  cout << "\n";
  if (tot & 1 or tot == n) {
    cout << "NO\n";
    return;
  }
  if (a[1] == 0) {
    vector<long long> ans;
    op_ida(1, ans);
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto u : ans) cout << u << " ";
    cout << "\n";
    return;
  }
  if (a[n] == 0) {
    vector<long long> ans;
    op_volta(n, ans);
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto u : ans) cout << u << " ";
    cout << "\n";
    return;
  }
  long long pref = 0;
  for (long long i = 1; i <= n; i++) {
    pref += a[i];
    if (a[i] == 1) continue;
    if (pref % 2 == 0) {
      vector<long long> ans;
      op_ida(i, ans);
      op_volta(i, ans);
      cout << "YES\n";
      cout << ans.size() << "\n";
      for (auto u : ans) cout << u << " ";
      cout << "\n";
      return;
    } else {
      long long j = i;
      while (j <= n and a[j] == 0) j++;
      j--;
      if ((j - i + 1) & 1) {
        vector<long long> ans;
        while (j != i) {
          a[j] = a[j - 1] = 1;
          ans.push_back(j - 1);
          j -= 2;
        }
        ans.push_back(i - 1);
        a[i + 1] = 0;
        a[i - 1] = 0;
        op_ida(i, ans);
        op_volta(i, ans);
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (auto u : ans) cout << u << " ";
        cout << "\n";
        return;
      }
      i = j;
    }
  }
  cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve();
}
