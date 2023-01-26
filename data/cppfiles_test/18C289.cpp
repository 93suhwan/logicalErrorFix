#include <bits/stdc++.h>
using namespace std;
struct Chord {
  int p1;
  int p2;
  int sects = 0;
};
int n, k;
vector<Chord> chords;
bool isect(int c1, int c2) {
  int p11 = chords[c1].p1;
  int p12 = chords[c1].p2;
  if (p11 > p12) swap(p11, p12);
  int p21 = chords[c2].p1;
  int p22 = chords[c2].p2;
  int count = 0;
  if (p11 < p21 && p21 < p12) {
    count++;
  }
  if (p11 < p22 && p22 < p12) {
    count++;
  }
  return count == 1;
}
int count_sects() {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (isect(i, j)) ret++;
    }
  }
  return ret;
}
void solve() {
  cin >> n >> k;
  int N = 2 * n;
  set<int> left;
  for (int i = 0; i < N; i++) {
    left.insert(i);
  }
  chords = vector<Chord>(n);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    left.erase(x);
    left.erase(y);
    chords[n - 1 - i].p1 = x;
    chords[n - 1 - i].p2 = y;
  }
  for (int i = 0; i < n - k; i++) {
    int x = *left.begin();
    left.erase(x);
    chords[i].p1 = x;
    int y = (x + N / 2) % N;
    int off = 0;
    while (true) {
      assert(off <= 10 * n);
      int big = (y + off) % N;
      int small = (y - off + N) % N;
      if (left.count(big)) {
        left.erase(big);
        chords[i].p2 = big;
        break;
      }
      if (left.count(small)) {
        left.erase(small);
        chords[i].p2 = small;
        break;
      }
      off++;
    }
  }
  assert(left.size() == 0);
  int best = count_sects();
  bool inc = true;
  while (inc) {
    inc = false;
    for (int i = 0; i < n - k; i++) {
      for (int j = 0; j < n - k; j++) {
        if (i == j) continue;
        if (!isect(i, j)) {
          vector<int> pts;
          pts.push_back(chords[i].p1);
          pts.push_back(chords[i].p2);
          pts.push_back(chords[j].p1);
          pts.push_back(chords[j].p2);
          sort(pts.begin(), pts.end());
          chords[i].p1 = pts[0];
          chords[i].p2 = pts[2];
          chords[j].p1 = pts[1];
          chords[j].p2 = pts[3];
          assert(isect(i, j));
          inc = true;
        }
      }
    }
  }
  best = count_sects();
  cout << best << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t-- > 0) solve();
  return 0;
}
