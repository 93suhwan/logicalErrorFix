#include <bits/stdc++.h>
using namespace std;
long long t, n, a[200020], lmt;
bool is_nprm(vector<long long> v) {
  if (!v.size()) {
    return 0;
  }
  long long num = 0, dg = 1;
  for (int i = v.size() - 1; i >= 0; i--) {
    num += dg * v[i];
    dg *= 10;
  }
  if (num == 1) {
    return 1;
  }
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return 1;
    }
  }
  return 0;
}
vector<long long> trye, ans;
void tryee(long long i) {
  if (i > lmt) {
    return;
  }
  trye.push_back(a[i]);
  tryee(i + 1);
  if (is_nprm(trye)) {
    if (trye.size() < ans.size() || ans.size() == 0) {
      ans = trye;
    }
  }
  trye.pop_back();
  tryee(i + 1);
  if (is_nprm(trye)) {
    if (trye.size() < ans.size() || ans.size() == 0) {
      ans = trye;
    }
  }
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    trye.clear();
    ans.clear();
    cin >> n;
    lmt = min(9ll, n);
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      a[i] = c - '0';
    }
    tryee(1);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i];
    }
    cout << "\n";
  }
}
