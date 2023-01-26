#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
const int mxn = 12000;
const int mod = 998244353;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % mod;
      res %= mod;
    }
    a = a * a % mod;
    a %= mod;
    b /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n, p, h;
  cin >> n >> p >> h;
  long long nupto = (1ll << n);
  vector<vi> a(2);
  for (int i = 0; i < nupto / 2; i++) {
    a[0].push_back(i);
  }
  for (int i = nupto / 2; i < nupto; i++) {
    a[1].push_back(i);
  }
  const int m = nupto / 2 - 1;
  auto magicalhash = [&](vi score) -> long long {
    long long nowh = 0;
    for (int i = 0; i < nupto; i++) {
      if (score[i] == -1) continue;
      long long now = (i + 1) % mod;
      now *= binpow(p, score[i]) % mod;
      nowh += now;
      nowh %= mod;
    }
    return nowh;
  };
  auto f = [&](int t1, int t2) -> void {
    vi rbt = a[t1], rbe = a[t2];
    std::map<long long, vi> mp;
    for (int msk = 0; msk < (1 << m); msk++) {
      int now = 0;
      vi game = rbt;
      vi score(32, -1);
      int depth = n - 1;
      while ((int)(game).size() != 1) {
        vi negame;
        for (int i = 0; i < (int)(game).size(); i += 2) {
          if (msk & (1 << now)) {
            negame.push_back(game[i + 1]);
            score[game[i]] = (1 << depth) + 1;
          } else {
            negame.push_back(game[i]);
            score[game[i + 1]] = (1 << depth) + 1;
          }
          now++;
        }
        depth--;
        swap(game, negame);
      }
      score[game[0]] = 1;
      long long h1 = (magicalhash(score) + mod) % mod;
      mp[h1] = score;
    }
    for (int msk = 0; msk < (1 << m); msk++) {
      int now = 0;
      vi game = rbe;
      vi score(32, -1);
      int depth = n - 1;
      while ((int)(game).size() != 1) {
        vi negame;
        for (int i = 0; i < (int)(game).size(); i += 2) {
          if (msk & (1 << now)) {
            negame.push_back(game[i + 1]);
            score[game[i]] = (1 << depth) + 1;
          } else {
            negame.push_back(game[i]);
            score[game[i + 1]] = (1 << depth) + 1;
          }
          now++;
        }
        depth--;
        swap(game, negame);
      }
      score[game[0]] = 2;
      long long h1 = (magicalhash(score) + mod) % mod;
      long long h2 = (h - h1 + mod) % mod;
      if (mp.find(h2) != mp.end()) {
        vi score1 = mp[h2];
        for (int i = 0; i < nupto; i++) {
          if (score[i] == -1) {
            cout << score1[i] << " ";
          } else {
            cout << score[i] << " ";
          }
        }
        cout << "\n";
        exit(0);
      }
    }
  };
  f(0, 1);
  f(1, 0);
  cout << "-1\n";
  return 0;
}
