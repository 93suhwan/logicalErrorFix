#include <bits/stdc++.h>
using namespace std;
void Ludociel() {}
const int Mx = (int)1e6 + 7;
const int Md = (int)1e9 + 7;
const long long Inf = (long long)1e18 + 7;
int n;
long long Aq[Mx], Cnt[Mx];
int main() {
  Ludociel();
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 0; i <= n; i++) Cnt[i] = false;
    for (int i = 1; i <= n; i++) {
      cin >> Aq[i];
      Cnt[Aq[i]]++;
    }
    sort(Aq + 1, Aq + n + 1);
    cout << Cnt[0] << ' ';
    long long sum = false;
    if (sum < 0) {
      for (int i = 1; i <= n; i++) cout << -1 << ' ';
    } else {
      int stop = -1;
      vector<pair<long long, long long>> Can;
      Can.clear();
      if (Cnt[0] > 1) Can.push_back({0, Cnt[0] - 1});
      for (int i = 1; i <= n; i++) {
        cout << sum + Cnt[i] << ' ';
        stop = i;
        if (Cnt[i]) {
          if (Cnt[i] > 1) Can.push_back({i, Cnt[i] - 1});
        } else {
          if (Can.empty()) {
            break;
          } else {
            long long num = Can.back().first, wer = Can.back().second;
            Can.pop_back();
            sum += (i - num);
            if (wer > 1) {
              Can.push_back({num, wer - 1});
            }
          }
        }
      }
      for (int i = stop + 1; i <= n; i++) cout << -1 << ' ';
    }
    cout << '\n';
  }
}
