#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &a, U b) {
  a = (a > b ? b : a);
}
template <typename T, typename U>
inline void amax(T &a, U b) {
  a = (a > b ? a : b);
}
int ask(int x, int y, int z) {
  cout << "? " << x << " " << y << " " << z << endl;
  int res;
  cin >> res;
  return res;
}
void print(vector<int> imp) {
  cout << "! ";
  cout << ((int)imp.size()) << " ";
  for (int v : imp) cout << v << " ";
  cout << endl;
}
void solve() {
  int n;
  cin >> n;
  int im = -1, cm = -1;
  vector<int> impostor;
  vector<int> for_one_each;
  int done[2]{};
  vector<int> res(n);
  for (int i = 0; i < n; i += 3) {
    res[i] = ask(i + 1, i + 2, i + 3);
    if (!done[res[i]]) {
      done[res[i]] = 1;
      for_one_each.push_back(i + 1);
      for_one_each.push_back(i + 2);
      for_one_each.push_back(i + 3);
    }
  }
  int prev = res[for_one_each.front() - 1];
  for (int i = 1; i < 4; ++i) {
    vector<int> cand;
    cand.push_back(for_one_each[i]);
    cand.push_back(for_one_each[i + 1]);
    cand.push_back(for_one_each[i + 2]);
    int cur = ask(cand[0], cand[1], cand[2]);
    if (cur != prev) {
      if (cur == 1)
        im = for_one_each[i - 1], cm = for_one_each[i + 2];
      else
        cm = for_one_each[i - 1], im = for_one_each[i + 2];
      impostor.push_back(im);
      break;
    }
    prev = cur;
  }
  for (int i = 0; i < n; i += 3) {
    if (res[i]) {
      if ((cm - 1) / 3 == i) {
        for (int x = 0; x < 3; ++x) {
          if (i + 1 + x == cm) continue;
          if (!ask(cm, im, i + 1 + x)) impostor.push_back(i + 1 + x);
        }
      } else {
        int r = ask(i + 1, i + 2, im);
        if (!r) {
          if (!ask(cm, im, i + 1))
            impostor.push_back(i + 1);
          else
            impostor.push_back(i + 2);
        } else {
          if (!ask(cm, im, i + 3)) impostor.push_back(i + 3);
        }
      }
    } else {
      if ((im - 1) / 3 == i) {
        for (int x = 0; x < 3; ++x) {
          if (i + 1 + x == im) continue;
          if (!ask(cm, im, i + 1 + x)) impostor.push_back(i + 1 + x);
        }
      } else {
        int r = ask(i + 1, i + 2, cm);
        if (r) {
          if (!ask(cm, im, i + 1))
            impostor.push_back(i + 1);
          else
            impostor.push_back(i + 2);
        } else {
          if (!ask(cm, im, i + 3)) impostor.push_back(i + 3);
        }
      }
    }
  }
  print(impostor);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
