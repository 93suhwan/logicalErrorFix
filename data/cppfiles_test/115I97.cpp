#include <bits/stdc++.h>
using namespace std;
long long nr1lin[1000005], nr2lin[1000005], gresit[1000005], gresitcol[1000005],
    n, m, nrgresitelin, nrgresitecol, plin, inv2, pcol;
long long nr1col[1000005], nr2col[1000005], nrceau1, nrceau2;
map<pair<int, int>, int> valori;
void updateazalinie(int x, int y, int val1, int val2) {
  if (val1 == val2) {
    return;
  }
  if (val2 == 0) {
    if ((x + y) % 2 == 0) {
      nrceau1--;
    } else {
      nrceau2--;
    }
    if (val1 % 2 == y % 2) {
      nr1lin[x]--;
    } else {
      nr2lin[x]--;
    }
    if ((nr1lin[x] == 0 || nr2lin[x] == 0) && gresit[x] == 1) {
      gresit[x] = 0;
      nrgresitelin--;
    }
    if (nr1lin[x] == 0 && nr2lin[x] == 0) {
      plin = (plin * 2) % 998244353;
    }
  } else if (val1 == 0) {
    if ((x + y) % 2 == 0) {
      nrceau1++;
    } else {
      nrceau2++;
    }
    if (nr1lin[x] == 0 && nr2lin[x] == 0) {
      plin = (plin * inv2) % 998244353;
    }
    if (val2 % 2 == y % 2) {
      nr1lin[x]++;
    } else {
      nr2lin[x]++;
    }
    if ((nr1lin[x] != 0 && nr2lin[x] != 0) && gresit[x] == 0) {
      gresit[x] = 1;
      nrgresitelin++;
    }
  }
}
void updateazacol(int x, int y, int val1, int val2) {
  if (val1 == val2) {
    return;
  }
  if (val2 == 0) {
    if (val1 % 2 == x % 2) {
      nr1col[y]--;
    } else {
      nr2col[y]--;
    }
    if ((nr1col[y] == 0 || nr2col[y] == 0) && gresitcol[y] == 1) {
      gresitcol[y] = 0;
      nrgresitecol--;
    }
    if (nr1col[y] == 0 && nr2col[y] == 0) {
      pcol = (pcol * 2) % 998244353;
    }
  } else if (val1 == 0) {
    if (nr1col[y] == 0 && nr2col[y] == 0) {
      pcol = (pcol * inv2) % 998244353;
    }
    if (val2 % 2 == x % 2) {
      nr1col[y]++;
    } else {
      nr2col[y]++;
    }
    if ((nr1col[y] != 0 && nr2col[y] != 0) && gresitcol[y] == 0) {
      gresitcol[y] = 1;
      nrgresitecol++;
    }
  }
}
long long rez() {
  long long pfin = 0;
  if (nrgresitelin == 0) {
    pfin = (pfin + plin) % 998244353;
  }
  if (nrgresitecol == 0) {
    pfin = (pfin + pcol) % 998244353;
  }
  if (nrgresitelin == 0 && nrgresitecol == 0) {
    if (nrceau1 == 0) {
      pfin = (pfin - 1 + 998244353) % 998244353;
    }
    if (nrceau2 == 0) {
      pfin = (pfin - 1 + 998244353) % 998244353;
    }
  }
  return pfin;
}
long long ridput(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long rez = ridput(a, b / 2);
  if (b % 2 == 0) {
    return (rez * rez) % 998244353;
  }
  return ((rez * rez) % 998244353 * a) % 998244353;
}
int q, i, x, y, val;
long long inv;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> q;
  inv2 = ridput(2, 998244353 - 2);
  plin = pcol = 1;
  for (i = 1; i <= n; i++) {
    plin = (plin * 2) % 998244353;
  }
  for (i = 1; i <= m; i++) {
    pcol = (pcol * 2) % 998244353;
  }
  nrceau1 = 0;
  nrceau2 = 0;
  for (i = 1; i <= q; i++) {
    cin >> x >> y >> val;
    val++;
    if (val == 0) {
      int inainte = valori[{x, y}];
      if (inainte == 0) {
        cout << rez() << '\n';
        continue;
      }
      updateazalinie(x, y, inainte, 0);
      updateazacol(x, y, inainte, 0);
      valori[{x, y}] = val;
    } else {
      int inainte = valori[{x, y}];
      if (inainte == val) {
        cout << rez() << '\n';
        continue;
      }
      updateazalinie(x, y, inainte, 0);
      updateazalinie(x, y, 0, val);
      updateazacol(x, y, inainte, 0);
      updateazacol(x, y, 0, val);
      valori[{x, y}] = val;
    }
    cout << rez() << '\n';
  }
  return 0;
}
