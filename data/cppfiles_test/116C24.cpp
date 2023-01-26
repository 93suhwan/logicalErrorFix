#include <bits/stdc++.h>
template <class p, class q>
void umin(p& a, const q& b) {
  if (a > b) a = b;
}
template <class p, class q>
void umax(p& a, const q& b) {
  if (a < b) a = b;
}
using ll = long long;
using VI = std::vector<int>;
using namespace std;
using namespace std::chrono;
int n, m, k;
int const N = 3e5 + 3;
ll const P = 998244353;
ll const gen = 906409729;
ll const invgen = 483587622;
ll root[21];
ll invroot[21];
ll inv[3] = {0, 1, (P + 1) / 2};
void calc() {
  root[20] = gen;
  invroot[20] = invgen;
  for (int i = (19); i >= (0); i--) root[i] = (root[i + 1] * root[i + 1]) % P;
  for (int i = (19); i >= (0); i--)
    invroot[i] = (invroot[i + 1] * invroot[i + 1]) % P;
}
void fft(vector<ll>& b, bool invert) {
  int m = b.size();
  if (m == 1) return;
  vector<ll> b0, b1;
  for (int i = 0; 2 * i < m; i++) {
    b0.push_back(b[2 * i]);
    b1.push_back(b[2 * i + 1]);
  }
  fft(b0, invert);
  fft(b1, invert);
  ll w = 1;
  ll wn = (invert) ? invroot[(int)(log2)(m)] : root[(int)(log2)(m)];
  for (int i = 0; 2 * i < m; i++) {
    b[i] = (b0[i] + w * b1[i]) % P;
    b[i + m / 2] = ((b0[i] - w * b1[i]) % P + P) % P;
    w = (w * wn) % P;
    if (invert) {
      b[i] = (b[i] * inv[2]) % P;
      b[i + m / 2] = (b[i + m / 2] * inv[2]) % P;
    }
  }
}
void inverse(vector<ll>& ret, vector<ll> first, int r) {
  assert(r > 0);
  assert(first[0] == 1);
  if (r == 1) {
    ret = vector<ll>{1};
  } else {
    first.resize(r);
    vector<ll> halfinverse;
    inverse(halfinverse, first, r / 2);
    int s = 2 * r;
    first.resize(s);
    halfinverse.resize(s);
    fft(first, 0);
    fft(halfinverse, 0);
    ret = vector<ll>(s);
    for (int i = (0); i <= (s - 1); i++)
      ret[i] = (2 + P - (first[i] * halfinverse[i]) % P) % P;
    for (int i = (0); i <= (s - 1); i++) ret[i] = (halfinverse[i] * ret[i]) % P;
    fft(ret, 1);
    ret.resize(r);
  }
}
vector<VI> arrays;
VI D[N];
VI Din[N];
vector<ll> W;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  arrays = vector<VI>(n);
  for (int i = (1); i <= (n); i++) {
    int t;
    cin >> t;
    for (int j = (1); j <= (t); j++) {
      int s;
      cin >> s;
      arrays[i - 1].push_back(s);
    }
    for (int j = (0); j <= (t - 2); j++) {
      D[arrays[i - 1][j]].push_back(arrays[i - 1][j + 1]);
      Din[arrays[i - 1][j + 1]].push_back(arrays[i - 1][j]);
    }
  }
  for (int i = (1); i <= (k); i++) {
    sort(D[i].begin(), D[i].end());
    sort(Din[i].begin(), Din[i].end());
    D[i].erase(unique(D[i].begin(), D[i].end()), D[i].end());
    Din[i].erase(unique(Din[i].begin(), Din[i].end()), Din[i].end());
  }
  W = vector<ll>(m + 1);
  bool out = 1;
  for (int i = (1); i <= (k); i++) {
    if (Din[i].empty()) {
      int ww = 1;
      int ci = i;
      while (1) {
        if (((int)((D[ci]).size())) > 1 || ((int)((Din[ci]).size())) > 1)
          break;
        else if (((int)((D[ci]).size())) == 1) {
          ww++;
          ci = D[ci][0];
        } else {
          out = 0;
          if (ww <= m) W[ww]--;
          break;
        }
      }
    }
  }
  if (out) {
    cout << "0\n";
    return 0;
  }
  W[0] = 1;
  calc();
  vector<ll> ans;
  int pot2 = 1;
  while (pot2 <= m) pot2 *= 2;
  inverse(ans, W, pot2);
  if (((int)((ans).size())) > m)
    cout << ans[m] << "\n";
  else
    cout << "0\n";
  return 0;
}
