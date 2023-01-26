#include <bits/stdc++.h>
using namespace std;
int ansNum = 1;
bool debug = true;
long long fast_exp(long long base, long long exp) {
  long long ans = 1;
  while (exp > 0) {
    if (exp & 1) ans = (ans * base);
    base = (base * base);
    exp /= 2;
  }
  return ans;
}
void TLEsol() {
  long long n, s;
  cin >> s >> n;
  long long mul = 0, t = 0;
  vector<long long> cnt(10);
  while (s > 0) {
    long long rem = s % 10;
    s /= 10;
    cnt[mul] = rem;
    t += rem;
    mul++;
  }
  vector<long long> res;
  while (t < n) {
    for (int i = 1; i < 10; i++) {
      if (cnt[i] > 0) {
        cnt[i]--;
        cnt[i - 1] += 10;
        t += 9;
        break;
      }
    }
  }
  int i = 0;
  while (res.size() < n - 1) {
    while (cnt[i] == 0) i++;
    res.push_back(fast_exp(10, i));
    cnt[i]--;
  }
  long long last = 0;
  while (i < 10) {
    last += cnt[i] * fast_exp(10, i);
    i++;
  }
  res.push_back(last);
  for (auto e : res) cout << e << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    TLEsol();
  }
  return 0;
}
