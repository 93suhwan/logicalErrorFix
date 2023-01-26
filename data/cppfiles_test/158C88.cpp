#include <bits/stdc++.h>
using namespace std;
using LL = long long;
mt19937_64 rng(time(0));
int random(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
const int maxn = 1000100;
void solve(int tc) {
  int n, m;
  cin >> n >> m;
  vector<int> tab(n);
  for (int i = (0); i < (n); ++i) cin >> tab[i];
  vector<string> correct(n);
  for (int i = (0); i < (n); ++i) cin >> correct[i];
  int all = (1 << n);
  long long best = -1;
  vector<int> odpowiedz;
  for (int mask = (0); mask < (all); ++mask) {
    vector<bool> bit(n);
    vector<long long> q_score(m, 0);
    for (int i = (0); i < (n); ++i) {
      if (mask & (1 << i))
        bit[i] = 1;
      else
        bit[i] = 0;
    }
    for (int i = (0); i < (n); ++i) {
      for (int q = (0); q < (m); ++q) {
        if (correct[i][q] == '1') {
          if (bit[i])
            q_score[q]++;
          else
            q_score[q]--;
        }
      }
    }
    vector<pair<int, int> > qs(m);
    for (int i = (0); i < (m); ++i) qs[i] = {q_score[i], i};
    sort(begin(qs), end(qs));
    vector<long long> policzone(n, 0);
    vector<int> tmp(m);
    for (int i = (0); i < (m); ++i) {
      int score = i + 1;
      int pytanie = qs[i].second;
      tmp[pytanie] = score;
      for (int student = (0); student < (n); ++student) {
        if (correct[student][pytanie] == '1') policzone[student] += score;
      }
    }
    long long opt = 0;
    for (int student = (0); student < (n); ++student)
      opt += abs(policzone[student] - tab[student]);
    if (opt > best) {
      best = opt;
      odpowiedz = tmp;
    }
  }
  0 && cerr;
  for (int i = (0); i < (m); ++i) cout << odpowiedz[i] << ' ';
  cout << "\n";
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  int tests;
  cin >> tests;
  for (int test = (1); test <= (tests); ++test) {
    solve(test);
  }
}
