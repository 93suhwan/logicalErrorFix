#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long T, n, white, black, zy, xe, ans[N], k, type[N];
void findwhite() {
  long long fg = 1, col;
  for (long long i = xe; i < xe + 3; ++i) {
    cout << "? " << zy << ' ' << zy + 1 << ' ' << i << "\n";
    cout.flush();
    cin >> col;
    if (col == 0) {
      fg = 0;
      break;
    }
  }
  if (fg) {
    white = zy;
    ans[zy] = ans[zy + 1] = 1;
    return;
  }
  fg = 1;
  for (long long i = xe; i < xe + 3; ++i) {
    cout << "? " << zy << ' ' << zy + 2 << ' ' << i << "\n";
    cout.flush();
    cin >> col;
    if (col == 0) {
      fg = 0;
      break;
    }
  }
  if (fg) {
    white = zy;
    ans[zy] = ans[zy + 2] = 1;
    ans[zy + 1] = 0;
    return;
  }
  ans[zy] = 0;
  ans[zy + 1] = ans[zy + 2] = 1;
  white = zy + 1;
}
void findblack() {
  long long fg = 1, col;
  for (long long i = zy; i < zy + 3; ++i) {
    cout << "? " << xe << ' ' << xe + 1 << ' ' << i << "\n";
    cout.flush();
    cin >> col;
    if (col == 1) {
      fg = 0;
      break;
    }
  }
  if (fg) {
    black = xe;
    ans[xe] = ans[xe + 1] = 0;
    return;
  }
  fg = 1;
  for (long long i = zy; i < zy + 3; ++i) {
    cout << "? " << xe << ' ' << xe + 2 << ' ' << i << "\n";
    cout.flush();
    cin >> col;
    if (col == 1) {
      fg = 0;
      break;
    }
  }
  if (fg) {
    black = xe;
    ans[xe] = ans[xe + 2] = 0;
    return;
  }
  ans[xe + 1] = ans[xe + 2] = 0;
  black = xe + 1;
}
void solblack(long long i) {
  long long col;
  cout << "? " << i << ' ' << i + 1 << ' ' << white << "\n";
  cout.flush();
  cin >> col;
  if (col == 0) {
    ans[i] = ans[i + 1] = 0;
    cout << "? " << i + 2 << ' ' << black << ' ' << white << "\n";
    cout.flush();
    cin >> ans[i + 2];
  } else {
    ans[i + 2] = 0;
    cout << "? " << i << ' ' << black << ' ' << white << "\n";
    cout.flush();
    cin >> ans[i];
    if (ans[i] == 0)
      ans[i + 1] = 1;
    else
      ans[i + 1] = 0;
  }
}
void solwhite(long long i) {
  long long col;
  cout << "? " << i << ' ' << i + 1 << ' ' << black << "\n";
  cout.flush();
  cin >> col;
  if (col == 1) {
    ans[i] = ans[i + 1] = 1;
    cout << "? " << i + 2 << ' ' << black << ' ' << white << "\n";
    cout.flush();
    cin >> ans[i + 2];
  } else {
    ans[i + 2] = 1;
    cout << "? " << i << ' ' << black << ' ' << white << "\n";
    cout.flush();
    cin >> ans[i];
    if (ans[i] == 0)
      ans[i + 1] = 1;
    else
      ans[i + 1] = 0;
  }
}
signed main() {
  memset(ans, -1, sizeof(ans));
  cin >> T;
  while (T--) {
    k = 0;
    cin >> n;
    for (long long i = 1; i <= n; i += 3) {
      cout << "? " << i << ' ' << i + 1 << ' ' << i + 2 << "\n";
      cout.flush();
      cin >> type[i];
      if (type[i])
        zy = i;
      else
        xe = i;
    }
    findwhite();
    findblack();
    for (long long i = 1; i <= n; i += 3) {
      if (i == zy || i == xe) continue;
      if (!type[i])
        solblack(i);
      else
        solwhite(i);
    }
    for (long long i = 1; i <= n; ++i) {
      if (ans[i] != -1) continue;
      cout << "? " << i << ' ' << black << ' ' << white << "\n";
      cout.flush();
      cin >> ans[i];
    }
    for (long long i = 1; i <= n; ++i)
      if (ans[i] == 0) k++;
    cout << "! " << k << ' ';
    cout.flush();
    for (long long i = 1; i <= n; ++i) {
      if (ans[i] == 0) cout << i << ' ', cout.flush();
      ans[i] = -1;
      type[i] = 0;
    }
    cout << "\n";
    cout.flush();
  }
}
