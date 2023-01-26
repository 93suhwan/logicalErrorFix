#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  bool operator<(const P &p) {
    if (x != p.x)
      return x < p.x;
    else
      return y < p.y;
  }
};
const long long mod = 1e9 + 7;
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    map<int, int> count;
    map<int, int> step;
    if (s1[0] == '0') {
      count[0] = 1;
    } else if (s1[0] == '1') {
      count[1] = 1;
    } else {
      count[0] = 1;
      count[1] = 1;
    }
    for (int i = 0; i < n - 1; ++i) {
      map<int, int> tcount;
      map<int, int> tstep;
      vector<int> tgt;
      if (s2[i] == '0') {
        tgt.push_back(0);
      } else if (s2[i] == '1') {
        tgt.push_back(1);
      } else {
        tgt.push_back(0);
        tgt.push_back(1);
      }
      vector<int> next;
      if (s1[i + 1] == '0') {
        next.push_back(0);
      } else if (s1[i + 1] == '1') {
        next.push_back(1);
      } else {
        next.push_back(0);
        next.push_back(1);
      }
      for (auto it = count.begin(); it != count.end(); it++) {
        for (int j = 0; j < tgt.size(); ++j) {
          for (int k = 0; k < next.size(); ++k) {
            int ind = next[k] + tgt[j] - it->first;
            tcount[ind] += it->second;
            tcount[ind] %= mod;
            tstep[ind] +=
                ((long long)step[it->first] +
                 (long long)it->second * (long long)abs(tgt[j] - it->first)) %
                mod;
            tstep[ind] %= mod;
          }
        }
      }
      count = tcount;
      step = tstep;
    }
    if (s2[n - 1] == '0') {
      cout << step[0] << endl;
    } else if (s2[n - 1] == '1') {
      cout << step[1] << endl;
    } else {
      cout << (step[0] + step[1]) % mod << endl;
    }
  }
  return 0;
}
