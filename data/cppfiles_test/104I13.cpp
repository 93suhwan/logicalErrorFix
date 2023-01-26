#include <bits/stdc++.h>

using namespace std;

#define let auto
#define int int_fast64_t
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) MAX(a, b)
#define min(a, b) MIN(a, b)

struct Dish {
  int a;
  int b;
};

const int kMaxN = 2 * 10'000 + 1;
Dish eat[kMaxN];
int var[kMaxN];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            auto min_a = max(m - b, 0);
            auto min_b = max(m - a, 0);
            eat[i] = {min_a, min_b};
            var[i] = m - min_a - min_b;
            diff += (a - min_a) - (b - min_b);
        }
        for (int i = 0; i < n; ++i) {
            if (diff > 0) {
                auto take = min(diff, var[i]);
                diff -= take;
                eat[i].a += take;
                var[i] -= take;
            } else {
                auto take = min(-diff, var[i]);
                diff += take;
                eat[i].b += take;
                var[i] -= take;
            }
            if (var[i] != 0) {
                eat[i].a += var[i] / 2;
                eat[i].b += (var[i] + 1) / 2;
                diff = var[i] % 2;
            }
        }
        cout << diff << '\n';
        for (int i = 0; i < n; ++i) {
            cout << eat[i].a << ' ' << eat[i].b << '\n';
        }
    }
}