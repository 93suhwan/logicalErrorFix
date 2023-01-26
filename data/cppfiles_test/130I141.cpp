#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
struct debug {
  ~debug() { cerr << endl; }
  template <class c>
  debug& operator<<(c x) {
    cerr << x;
    return *this;
  }
  template <class c, class d>
  debug& operator<<(pair<c, d> x) {
    *this << "(" << x.first << ", " << x.second << ")";
    return *this;
  }
  template <class c>
  debug& operator<<(vector<c> x) {
    *this << "[";
    int f = 0;
    for (auto it : x) {
      *this << (f ? ", " : "");
      *this << it;
      f = 1;
    }
    *this << "]";
    return *this;
  };
};
int arr[] = {0, 1, 1, 1, 0, 0, 1, 0, 0};
int local(int a, int b, int c) {
  assert(a != b && a != c && b != c);
  --a;
  --b;
  --c;
  int x = arr[a] + arr[b] + arr[c];
  return x > 1;
}
int print(int a, int b, int c) {
  printf("? %d %d %d\n", a, b, c);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}
void printAns(vector<int> v) {
  sort(v.begin(), v.end());
  printf("! %d ", (int)v.size());
  for (int i : v) {
    printf("%d ", i);
  }
  puts("");
  fflush(stdout);
}
void solve() {
  int n;
  scanf("%d", &n);
  vector<int> crew;
  vector<int> imp;
  vector<int> got;
  for (int i = 1; i <= n; i += 3) {
    if (print(i, i + 1, i + 2) == 0) {
      imp = {i, i + 1, i + 2};
      got.push_back(0);
    } else {
      crew = {i, i + 1, i + 2};
      got.push_back(1);
    }
  }
  vector<pair<int, int>> perm = {{0, 1}, {0, 2}, {1, 2}};
  vector<int> ans;
  int zero = 0;
  int one = 0;
  int three = 0;
  vector<int> zeroV;
  vector<int> oneV;
  int threeOne = -1;
  vector<vector<int>> X;
  for (int i = 0; i < 2; i++) {
    int a = imp[perm[i].first];
    int b = imp[perm[i].second];
    vector<int> x;
    int s = 0;
    for (int j = 0; j < 3; j++) {
      int c = crew[j];
      x.push_back(print(a, b, c) == 0);
      s += x.back();
    }
    if (s == 0) {
      zero++;
    } else if (s == 1) {
      one++, oneV = x;
    } else if (s == 3) {
      three++, threeOne = i;
    } else {
      cerr << "[LINE: " << 108 << "] -> ";
      debug() << "["
              << "s"
              << ": " << s << "]  ";
      assert(false);
    }
    X.push_back(x);
  }
  int good, bad;
  if (zero > 0) {
    if (threeOne == -1) {
      threeOne = 2;
    }
    ans.push_back(imp[perm[threeOne].first]);
    ans.push_back(imp[perm[threeOne].second]);
    good = crew[0];
  } else if (one > 0) {
    if (threeOne == -1) {
      threeOne = 2;
    }
    ans.push_back(imp[perm[threeOne].first]);
    ans.push_back(imp[perm[threeOne].second]);
    int idx;
    if (oneV[0] == 1)
      idx = 0;
    else if (oneV[1] == 1)
      idx = 1;
    else if (oneV[2] == 1)
      idx = 2;
    ans.push_back(crew[idx]);
    if (idx != 1) good = crew[1];
    if (idx != 2) good = crew[2];
  } else if (three > 1) {
    ans.push_back(imp[0]);
    ans.push_back(imp[1]);
    ans.push_back(imp[2]);
    int x = print(imp[0], crew[0], crew[1]);
    if (x == 0) {
      x = print(imp[0], crew[2], crew[1]);
      if (x == 1) {
        ans.push_back(crew[0]);
      } else {
        ans.push_back(crew[1]);
      }
      good = crew[2];
    } else {
      x = print(imp[0], crew[0], crew[2]);
      if (x == 0) ans.push_back(crew[2]);
      good = crew[0];
    }
  } else {
    assert(false);
  }
  bad = ans[0];
  for (int i = 1; i <= n; i += 3) {
    if (i != crew[0] && i != imp[0]) {
      if (print(good, bad, i) == 0) ans.push_back(i);
      if (print(good, bad, i + 1) == 0) ans.push_back(i + 1);
      if (print(good, bad, i + 2) == 0) ans.push_back(i + 2);
    }
  }
  printAns(ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}
