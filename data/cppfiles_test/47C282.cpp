#include <bits/stdc++.h>
using namespace std;
void io() {}
int main() {
  io();
  int cases;
  scanf("%d", &cases);
  for (int tc = 0; tc < cases; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<long long> pos;
    vector<long long> neg;
    for (int i = 0; i < n; i++) {
      long long input;
      scanf("%lld", &input);
      if (input > 0) {
        pos.push_back(input);
      } else if (input < 0) {
        neg.push_back(-input);
      }
    }
    sort(pos.begin(), pos.end(), greater<long long>());
    sort(neg.begin(), neg.end(), greater<long long>());
    long long sol = 0;
    for (int i = 0; i < (int)pos.size(); i += m) {
      sol += pos[i];
    }
    for (int i = 0; i < (int)neg.size(); i += m) {
      sol += neg[i];
    }
    sol *= 2;
    if (!pos.empty() && !neg.empty()) {
      sol -= max(pos[0], neg[0]);
    } else if (!pos.empty()) {
      sol -= pos[0];
    } else if (!neg.empty()) {
      sol -= neg[0];
    }
    printf("%lld\n", sol);
  }
  return 0;
}
