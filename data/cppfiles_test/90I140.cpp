#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int K = 18;
const int MAXN = 2e5 + 5;
int st[MAXN][K + 1];
int logg[MAXN + 1];
void initLog() {
  logg[1] = 0;
  for (int i = 2; i <= MAXN; i++) logg[i] = logg[i / 2] + 1;
}
void buildSparse(vector<pair<int, int> > &a) {
  int N = a.size();
  for (int i = 0; i < N; i++) st[i][0] = a[i].second;
  for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int querySparse(int L, int R) {
  if (L > R) return 2e9;
  int j = logg[R - L + 1];
  int maxi = min(st[L][j], st[R - (1 << j) + 1][j]);
  return maxi;
}
bool comp(pair<int, int> &a, pair<int, int> &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
vector<long long> dp[N];
void TEST_CASES() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<pair<int, int> > b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  sort(b.begin(), b.end(), comp);
  buildSparse(b);
  vector<bool> rem(m);
  for (int i = 0; i < m; i++) {
    int l = b[i].first;
    int r = b[i].second;
    int id = lower_bound(a.begin(), a.end(), l) - a.begin();
    if (id < a.size() && a[id] <= r) {
      rem[i] = 1;
      continue;
    }
    int q = querySparse(i + 1, m - 1);
    if (q <= r) {
      rem[i] = 1;
    }
  }
  {
    vector<pair<int, int> > c;
    for (int i = 0; i < m; i++) {
      if (!rem[i]) {
        c.push_back(b[i]);
      }
    }
    swap(b, c);
    m = b.size();
    if (m == 0) {
      cout << "0\n";
      return;
    }
  }
  vector<int> bam(n);
  vector<int> dan(n);
  vector<int> idbam(n);
  vector<int> iddan(n);
  for (int i = 0; i < n; i++) {
    int now = a[i];
    int low = 0, high = m - 1;
    int ans1 = 0, ans2 = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      pair<int, int> x = b[mid];
      if (x.second < now) {
        low = mid + 1;
        ans1 = mid + 1;
        ans2 = mid;
      } else {
        high = mid - 1;
      }
    }
    bam[i] = ans1;
    idbam[i] = ans2;
    int id = lower_bound(b.begin(), b.end(), make_pair(now, -1)) - b.begin();
    if (id < b.size()) {
      dan[i] = m - id;
      iddan[i] = id;
    } else {
      dan[i] = 0;
      iddan[i] = -1;
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    bam[i] -= bam[i - 1];
  }
  for (int i = 0; i < n - 1; i++) {
    dan[i] -= dan[i + 1];
  }
  for (int i = 0; i < n; i++) {
    dp[i].clear();
    dp[i].resize(bam[i] + 1, 1e18);
  }
  dp[n].clear();
  dp[n].resize(dan[n - 1] + 1, 1e18);
  dp[n][0] = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = bam[i]; j >= 0; j--) {
      long long ans = 1e18;
      long long l = (j == 0 ? 0 : (long long)a[i] - b[idbam[i] - j + 1].second);
      int low = 0, high = dan[i];
      int aa = 0;
      while (low <= high) {
        int k = (low + high) / 2;
        long long r =
            (k == 0 ? 0 : (long long)b[iddan[i] + k - 1].first - a[i]);
        if (l >= r) {
          low = k + 1;
          aa = k;
        } else {
          high = k - 1;
        }
      }
      for (int k = min(aa + 5, dan[i]); k >= max(0, aa - 5); k--) {
        long long r =
            (k == 0 ? 0 : (long long)b[iddan[i] + k - 1].first - a[i]);
        long long tmp = min(r, l) * 2 + max(r, l) + dp[i + 1][dan[i] - k];
        ans = min(ans, tmp);
      }
      for (int k = 0; k <= min(5, dan[i]); k++) {
        long long r =
            (k == 0 ? 0 : (long long)b[iddan[i] + k - 1].first - a[i]);
        long long tmp = min(r, l) * 2 + max(r, l) + dp[i + 1][dan[i] - k];
        ans = min(ans, tmp);
      }
      for (int k = dan[i]; k >= max(0, dan[i] - 5); k--) {
        long long r =
            (k == 0 ? 0 : (long long)b[iddan[i] + k - 1].first - a[i]);
        long long tmp = min(r, l) * 2 + max(r, l) + dp[i + 1][dan[i] - k];
        ans = min(ans, tmp);
      }
      dp[i][j] = ans;
    }
  }
  cout << dp[0][bam[0]] << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  initLog();
  int t = 1;
  cin >> t;
  while (t--) {
    TEST_CASES();
  }
  return 0;
}
