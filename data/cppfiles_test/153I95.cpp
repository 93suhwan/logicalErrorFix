#include <bits/stdc++.h>
using namespace std;
long long lowbit(long long n) { return n & (-n); }
long long n;
vector<vector<long long>> hist;
vector<vector<long long>> cc;
vector<long long> dp;
long long maxS, maxI;
vector<int> pc;
long long count_pos(long long num) {
  for (int i = 0; i < n; i++)
    if ((1 << i) & num) return i;
  return -1;
}
long long bit_count(long long num) {
  long long count = 0;
  for (long long i = 0; i < n; i++)
    if ((1 << i) & num) count++;
  return count;
}
int gH[8388609][26];
int g[8388609];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  maxS = 1 << n;
  maxI = n;
  long long allOn = (1 << n) - 1;
  pc = vector<int>(maxS, 0);
  for (int i = 0; i < maxS; i++) {
    pc[i] = bit_count(i);
  }
  for (int i = 0; i < maxS; i++) fill(gH[i], gH[i] + 26, 1000000000);
  vector<vector<int>> hist(maxI, vector<int>(26, 0));
  for (long long i = 0; i < n; i++) {
    string ss;
    cin >> ss;
    for (long long j = 0; j < ss.size(); j++) {
      long long let = ss[j] - 'a';
      hist[i][let]++;
    }
  }
  fill(g, g + maxS, 0);
  for (long long s = 0; s < maxS; s++) {
    long long lb = lowbit(s);
    long long ps = s - lb;
    int lbi = count_pos(lb);
    long long prod = 1;
    if ((s & allOn) == 0)
      prod = 0;
    else {
      for (long long k = 0; k < 26; k++) {
        gH[s][k] = min(gH[ps][k], hist[lbi][k]);
        prod *= (long long)gH[s][k] + 1;
        prod %= 998244353;
      }
    }
    if (pc[s] & 1) {
      g[s] = prod;
    } else {
      g[s] = (998244353 - prod) % 998244353;
    }
  }
  for (long long i = 0; i < maxI; i++) {
    for (long long s = 0; s < maxS; s++) {
      if (s & (1 << i)) {
        g[s] += g[s ^ (1 << i)];
        g[s] %= 998244353;
      }
    }
  }
  long long result = 0;
  for (long long s = 0; s < maxS; s++) {
    long long c = 0;
    for (long long i = 0; i < maxI; i++) {
      if ((1 << i) & s) c += i + 1;
    }
    long long num = g[s] * pc[s] * c;
    result ^= num;
  }
  cout << result << endl;
}
