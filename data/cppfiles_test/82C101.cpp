#include <bits/stdc++.h>
using namespace std;
int R = 1e9 + 7;
template <typename T>
T last(vector<T>& v) {
  return v[v.size() - 1];
}
template <typename T>
void print(vector<T>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << endl;
}
template <typename T1, typename T2>
void print(vector<pair<T1, T2>>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    cout << '(' << v[i].first << ',' << v[i].second << "),";
  }
  cout << "]" << endl;
}
template <typename T>
void print(vector<vector<T>>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    print(v[i]);
  }
  cout << "]" << endl;
}
template <typename T>
void print(set<T>& v) {
  cout << "{";
  for (auto i : v) {
    cout << i << ' ';
  }
  cout << "}" << endl;
}
template <typename T1, typename T2>
void print(map<T1, T2>& v) {
  cout << "{";
  for (auto i : v) {
    cout << i.first << ':' << i.second << ',';
  }
  cout << "}" << endl;
}
template <typename T>
bool in(set<T>& indices, T x) {
  return indices.find(x) != indices.end();
}
template <typename T, typename T_>
bool in(map<T, T_>& indices, T x) {
  return indices.find(x) != indices.end();
}
int power(int x, int y) {
  int res = 1;
  x = x % R;
  if (x == 0) return 0;
  while (y > 0) {
    if (y % 2 == 1) res = (res * x) % R;
    y /= 2;
    x = (x * x) % R;
  }
  return res;
}
bool compare(int a, int b) { return (a < b); }
void add(map<int, vector<int>>& m, int i, int score) {
  if (m.find(score) == m.end())
    m[score] = vector<int>(1, i);
  else
    m[score].push_back(i);
}
void TestCase() {
  int n, q;
  cin >> n >> q;
  string rods;
  cin >> rods;
  vector<int> score(n + 1);
  map<int, vector<int>> up;
  map<int, vector<int>> down;
  map<int, vector<int>> rise;
  map<int, vector<int>> fall;
  for (int i = 0; i < n; i++) {
    int factor = (i % 2 == 0) ? 1 : -1;
    if (rods[i] == '+') {
      score[i + 1] = score[i] + factor * 1;
      if (factor == 1) {
        add(up, i, score[i]);
        if (i > 0 && score[i] > score[i - 1]) {
          add(rise, i - 1, score[i - 1]);
        }
      } else {
        add(down, i, score[i]);
        if (i > 0 && score[i] < score[i - 1]) {
          add(fall, i - 1, score[i - 1]);
        }
      }
    } else {
      score[i + 1] = score[i] - factor * 1;
      if (factor == -1) {
        add(up, i, score[i]);
        if (i > 0 && score[i] > score[i - 1]) {
          add(rise, i - 1, score[i - 1]);
        }
      } else {
        add(down, i, score[i]);
        if (i > 0 && score[i] < score[i - 1]) {
          add(fall, i - 1, score[i - 1]);
        }
      }
    }
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int diff = abs(score[r] - score[l - 1]);
    if (diff == 0) {
      cout << 0 << '\n';
    } else if (diff % 2 == 0) {
      cout << 2 << '\n';
      int del = score[r] - score[l - 1];
      int index1;
      int index2;
      if (del > 0) {
        int base1 = score[l - 1];
        index1 = *(lower_bound(up[base1].begin(), up[base1].end(), l - 1));
        int base2 = del / 2 + score[l - 1];
        index2 = *(lower_bound(up[base2].begin(), up[base2].end(), l - 1));
      } else {
        int base1 = score[l - 1];
        index1 = *(lower_bound(down[base1].begin(), down[base1].end(), l - 1));
        int base2 = del / 2 + score[l - 1];
        index2 = *(lower_bound(down[base2].begin(), down[base2].end(), l - 1));
      }
      cout << index1 + 1 << ' ' << index2 + 1 << '\n';
    } else {
      cout << 1 << '\n';
      int del = score[r] - score[l - 1];
      int index;
      if (del > 0) {
        int base = del / 2 + score[l - 1];
        index = *(lower_bound(up[base].begin(), up[base].end(), l - 1));
      } else {
        int base = (del + 1) / 2 + score[l - 1];
        index = *(lower_bound(down[base].begin(), down[base].end(), l - 1));
      }
      cout << index + 1 << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  T = 1;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    TestCase();
  }
}
