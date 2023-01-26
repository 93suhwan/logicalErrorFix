#include <bits/stdc++.h>
using namespace std;
struct coord {
  coord(long long xx, long long yy) : x(xx), y(yy) {}
  long long x;
  long long y;
};
long long Ask(coord x) {
  cout << "? " << x.x << " " << x.y << endl;
  long long ans;
  cin >> ans;
  return ans;
}
void solve() {
  vector<long long> ans;
  vector<coord> edges;
  edges.emplace_back(1, 1);
  edges.emplace_back(1, 1e9);
  edges.emplace_back(1e9, 1e9);
  edges.emplace_back(1e9, 1);
  for (auto e : edges) {
    ans.push_back(Ask(e));
  }
  vector<long long> width;
  {
    long long fir = ans[0] + 1;
    long long sec = 1e9 - ans[1];
    if (sec >= fir) {
      width.push_back(Ask({1, fir}));
    } else {
      width.push_back(Ask({1, (fir + sec) / 2}));
    }
  }
  {
    long long fir = ans[1] + 1;
    long long sec = 1e9 - ans[2];
    if (sec >= fir) {
      width.push_back(Ask({fir, (long long)1e9}));
    } else {
      width.push_back(Ask({(fir + sec) / 2, (long long)1e9}));
    }
  }
  {
    long long fir = ans[3] + 1;
    long long sec = 1e9 - ans[2];
    if (sec >= fir) {
      width.push_back(Ask({(long long)1e9, fir}));
    } else {
      width.push_back(Ask({(long long)1e9, (fir + sec) / 2}));
    }
  }
  {
    long long fir = ans[0] + 1;
    long long sec = 1e9 - ans[3];
    if (sec >= fir) {
      width.push_back(Ask({fir, (long long)1}));
    } else {
      width.push_back(Ask({(fir + sec) / 2, (long long)1}));
    }
  }
  cout << "! " << width[0] + 1 << " " << width[3] + 1 << " "
       << (long long)1e9 - width[2] << " " << (long long)1e9 - width[1] << endl;
}
int main() {
  ios::sync_with_stdio(false);
  long long t = 1;
  while (t--) solve();
}
