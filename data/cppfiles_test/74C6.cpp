#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
using namespace std;
const int MAXVAL = (int)1.5e7;
const int BOUND = 28;
int mas[1005];
int last[MAXVAL], answer[1005];
pair<int, int> solve(int n) {
  for (int mask = 0; mask < (1 << n); mask++) {
    int bit = __builtin_popcount(mask);
    if (bit == n / 2) {
      int sum = 0;
      for (int first = 0; first < n; first++)
        if ((mask >> first) & 1) {
          sum += mas[first + 1];
        }
      if (last[sum] != 0) {
        return make_pair(last[sum], mask);
      }
      last[sum] = mask;
    }
  }
  return make_pair(-1, -1);
}
void trickyCase(int n) {
  pair<int, int> res = solve(min(n, BOUND));
  if (res.first == -1) {
    cout << "NO\n", exit(0);
  }
  int m = min(n, BOUND);
  int A = res.first ^ (res.first & res.second);
  int B = res.second ^ (res.first & res.second);
  vector<int> ones, twoes;
  for (int i = 0; i < m; i++) {
    if ((A >> i) & 1) ones.push_back(mas[i + 1]);
    if ((B >> i) & 1) twoes.push_back(mas[i + 1]);
  }
  set<int> opa;
  for (int i = 1; i <= n; i++) opa.insert(mas[i]);
  for (int first : ones) opa.erase(first);
  for (int first : twoes) opa.erase(first);
  cout << "YES\n";
  cout << "0 ";
  answer[0] = 0;
  for (int i = 0; i < (int)ones.size(); i++) {
    answer[2 * i + 1] = ones[i] - answer[2 * i];
    answer[2 * i + 2] = twoes[i] - answer[2 * i + 1];
    cout << answer[2 * i + 1] << ' ';
    if (i != (int)ones.size() - 1) cout << answer[2 * i + 2] << ' ';
  }
  for (auto it : opa) {
    cout << it << ' ';
  }
  cout << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> mas[i];
  if (n == 2) {
    if (mas[1] != mas[2]) cout << "NO\n", exit(0);
    cout << "YES\n";
    cout << "0 " << mas[1] << '\n';
  }
  if (n == 3) {
    if (mas[1] == mas[2] || mas[2] == mas[3] || mas[3] == mas[1]) {
      set<int> opa;
      for (int i = 1; i <= 3; i++) opa.insert(mas[i]);
      cout << "YES\n";
      cout << "0 " << *opa.begin() << ' ' << *opa.rbegin() << '\n';
      exit(0);
    }
    if ((mas[1] + mas[2] + mas[3]) % 2 == 1) cout << "NO\n", exit(0);
    cout << "YES\n";
    cout << (mas[1] + mas[3] - mas[2]) / 2 << ' '
         << (mas[1] + mas[2] - mas[3]) / 2 << ' '
         << (mas[2] + mas[3] - mas[1]) / 2 << '\n';
  }
  if (n > 3) {
    set<int> odd, even;
    for (int i = 1; i <= n; i++)
      if (mas[i] % 2 == 1)
        odd.insert(mas[i]);
      else
        even.insert(mas[i]);
    if ((int)odd.size() + (int)even.size() != n) {
      int pos = 0;
      set<int> all;
      for (int i = 1; i <= n; i++) {
        if (all.find(mas[i]) != all.end()) {
          pos = i;
          break;
        }
        all.insert(mas[i]);
      }
      cout << "YES\n";
      cout << "0 ";
      for (int i = 1; i <= n; i++)
        if (i != pos) cout << mas[i] << ' ';
      cout << '\n', exit(0);
    }
    if ((int)odd.size() >= 2 && (int)even.size() >= 1) {
      int A = *odd.begin();
      int B = *(++odd.begin());
      int C = *even.begin();
      int d = (A + B - C) / 2;
      cout << "YES\n";
      cout << d << ' ';
      bool fl = false;
      for (int i = 1; i <= n; i++) {
        if (fl || mas[i] != C) {
          cout << mas[i] - d << ' ';
        }
        if (mas[i] == C) fl = true;
      }
      exit(0);
    }
    if ((int)even.size() >= 3) {
      int A = *even.begin();
      int B = *(++even.begin());
      int C = *(++(++even.begin()));
      int d = (A + B - C) / 2;
      cout << "YES\n";
      cout << d << ' ';
      bool fl = false;
      for (int i = 1; i <= n; i++) {
        if (fl || mas[i] != C) {
          cout << mas[i] - d << ' ';
        }
        if (mas[i] == C) fl = true;
      }
      exit(0);
    }
    trickyCase(n);
  }
  return 0;
}
