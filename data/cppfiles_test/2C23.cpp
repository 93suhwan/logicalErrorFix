#include <bits/stdc++.h>
using namespace std;
template <typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> pai) {
  return os << '(' << pai.first << ' ' << pai.second << ')';
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
  cout << '[';
  for (auto p : v) cout << p << ",";
  cout << "]";
  return os;
}
template <typename T, typename V>
ostream &operator<<(ostream &os, const set<T, V> v) {
  cout << "{";
  for (auto p : v) cout << p << ",";
  cout << "}";
  return os;
}
template <typename T, typename V>
ostream &operator<<(ostream &os, const map<T, V> v) {
  cout << "{";
  for (auto p : v) cout << p << ",";
  cout << "}";
  return os;
}
template <typename T>
void get_max(T &a, T b) {
  a = max(a, b);
}
template <typename T>
void get_min(T &a, T b) {
  a = min(a, b);
}
const int MAXN = 6000 + 10;
int N;
vector<pair<long long, long long> > xy;
int cnt[MAXN][4][4][4];
int gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int getArea(pair<long long, long long> a, pair<long long, long long> b,
            pair<long long, long long> c) {
  long long area = (a.first - b.first) * (a.second + b.second) +
                   (b.first - c.first) * (b.second + c.second) +
                   (c.first - a.first) * (c.second + a.second);
  return (area % 4 + 4) % 4;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    xy.push_back({x, y});
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      int x = xy[j].first % 4;
      int y = xy[j].second % 4;
      int g =
          gcd(abs(xy[i].first - xy[j].first), abs(xy[i].second - xy[j].second));
      g %= 4;
      cnt[i][x][y][g]++;
    }
  }
  long long odd = 0, even = 0;
  for (int i = 0; i < N; i++) {
    for (int a = 0; a < 4; a++) {
      for (int b = 0; b < 4; b++) {
        for (int aa = 0; aa < 4; aa++) {
          for (int bb = 0; bb < 4; bb++) {
            int area = getArea(xy[i], {a, b}, {aa, bb});
            if (area % 2) continue;
            if (a % 2 != aa % 2 || b % 2 != bb % 2) continue;
            int ab = 2;
            if (a == aa && b == bb) ab = 0;
            for (int c = 0; c < 4; c++) {
              for (int cc = (c & 1); cc < 4; cc += 2) {
                int B = (c + cc + ab) % 4;
                if (area != B) continue;
                if (a == aa && b == bb && c == cc) {
                  if (c % 2)
                    odd += cnt[i][a][b][c] * (cnt[i][aa][bb][cc] - 1);
                  else
                    even += cnt[i][a][b][c] * (cnt[i][aa][bb][cc] - 1);
                } else {
                  if (c % 2)
                    odd += cnt[i][a][b][c] * cnt[i][aa][bb][cc];
                  else
                    even += cnt[i][a][b][c] * cnt[i][aa][bb][cc];
                }
              }
            }
          }
        }
      }
    }
  }
  0;
  cout << even / 6 + odd / 2;
  return 0;
}
