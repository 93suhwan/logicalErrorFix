#include <bits/stdc++.h>
using namespace std;
int res[3400];
int s[10004];
vector<int> vec;
int ask(int x, int y, int z) {
  cout << "? " << x << ' ' << y << ' ' << z << endl;
  int c;
  cin >> c;
  if (c == -1) {
    exit(0);
  }
  return c;
}
void solve() {
  vec.clear();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i += 3) {
    res[(i + 2) / 3] = ask(i, i + 1, i + 2);
  }
  int br, bw;
  for (int i = 1; i <= n / 3; ++i) {
    if (res[i] == 0) {
      br = i;
      break;
    }
  }
  for (int i = 1; i <= n / 3; ++i) {
    if (res[i] == 1) {
      bw = i;
      break;
    }
  }
  int r1, r2, r3, pw, pr;
  r1 = ask(br * 3 - 2, br * 3 - 1, bw * 3 - 2);
  r2 = ask(br * 3 - 2, br * 3 - 1, bw * 3 - 1);
  r3 = ask(br * 3 - 2, br * 3 - 1, bw * 3);
  if (r1 + r2 + r3 == 0) {
    pr = br * 3 - 2;
    vec.push_back(br * 3 - 2);
    vec.push_back(br * 3 - 1);
    r1 = ask(pr, bw * 3 - 2, bw * 3 - 1);
    r2 = ask(pr, bw * 3 - 2, bw * 3);
    r3 = ask(pr, bw * 3 - 1, bw * 3);
    if (r1 + r2 + r3 != 3) {
      if (r1 == 1) {
        pw = bw * 3 - 2;
        vec.push_back(bw * 3);
      } else if (r2 == 1) {
        pw = bw * 3 - 2;
        vec.push_back(bw * 3 - 1);
      } else {
        pw = bw * 3 - 1;
        vec.push_back(bw * 3 - 2);
      }
    } else {
      pw = bw * 3 - 2;
    }
    int temp = ask(br * 3 - 2, pw, br * 3);
    if (temp == 0) {
      vec.push_back(br * 3);
    }
  } else if (r1 + r2 + r3 >= 2) {
    if (r1 + r2 + r3 == 3) {
      pw = bw * 3 - 2;
    } else if (r1 == 0) {
      pw = bw * 3 - 1;
      vec.push_back(bw * 3 - 2);
    } else if (r2 == 0) {
      pw = bw * 3 - 2;
      vec.push_back(bw * 3 - 1);
    } else {
      pw = bw * 3 - 2;
      vec.push_back(bw * 3);
    }
    r1 = ask(pw, br * 3 - 2, br * 3 - 1);
    r2 = ask(pw, br * 3 - 2, br * 3);
    r3 = ask(pw, br * 3 - 1, br * 3);
    if (r1 + r2 + r3 == 0) {
      vec.push_back(br * 3 - 2);
      vec.push_back(br * 3 - 1);
      vec.push_back(br * 3);
      pr = br * 3 - 2;
    } else {
      if (r1 == 0) {
        vec.push_back(br * 3 - 2);
        vec.push_back(br * 3 - 1);
        pr = br * 3 - 2;
      } else if (r2 == 0) {
        vec.push_back(br * 3 - 2);
        vec.push_back(br * 3);
        pr = br * 3 - 2;
      } else {
        vec.push_back(br * 3);
        vec.push_back(br * 3 - 1);
        pr = br * 3 - 1;
      }
    }
  }
  for (int i = 1; i <= n / 3; ++i) {
    if (i == br || i == bw) {
      continue;
    }
    if (res[i] == 1) {
      r1 = ask(i * 3 - 2, i * 3 - 1, pr);
      r2 = ask(i * 3 - 1, i * 3, pr);
      if (r1 == 0 && r2 == 0) {
        vec.push_back(i * 3 - 1);
      } else if (r1 == 0) {
        vec.push_back(i * 3 - 2);
      } else if (r2 == 0) {
        vec.push_back(i * 3);
      }
    } else {
      r1 = ask(i * 3 - 2, i * 3 - 1, pw);
      r2 = ask(i * 3 - 1, i * 3, pw);
      if (r1 == 0 && r2 == 0) {
        vec.push_back(i * 3 - 2);
        vec.push_back(i * 3 - 1);
        vec.push_back(i * 3);
      } else if (r1 == 1 && r2 == 0) {
        vec.push_back(i * 3 - 1);
        vec.push_back(i * 3);
      } else if (r2 == 1 && r1 == 0) {
        vec.push_back(i * 3 - 2);
        vec.push_back(i * 3 - 1);
      } else {
        vec.push_back(i * 3 - 2);
        vec.push_back(i * 3);
      }
    }
  }
  sort(vec.begin(), vec.end());
  cout << "! " << vec.size();
  for (auto x : vec) {
    cout << ' ' << x;
  }
  cout << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  srand(time(0));
  while (t--) {
    for (int i = 1; i <= 10000; ++i) {
      s[i] = rand() % 2;
    }
    solve();
  }
  return 0;
}
