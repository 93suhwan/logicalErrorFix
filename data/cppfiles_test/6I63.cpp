#include<bits/stdc++.h>
#define int long long
#define p pair<int, int>
#define endl '\n'
const int INF = 1000000001;
const int MOD = 1000000007;

using namespace std;

vector<vector<int>> del;
vector<int> was, num;
int C = 0;

int sum_gcd_fast(vector<int> &a, int cnt){
    vector<int> all;
    for (int q: a){
        for (int q1: del[q]){
            if (was[q1] != cnt){
                was[q1] = cnt, num[q1] = 0;
                all.push_back(q1);
            }
            num[q1]++;
        }
    }
    for (int q: all){
        num[q] = num[q]*num[q];
    }
    sort(all.rbegin(), all.rend());
    int ans = 0;
    for (int q: all){
        ans += num[q]*q;
        for (int q1: del[q]){
            num[q1] -= num[q];
        }
    }
    return ans;
}

int sum_gcd_slow(vector<int> &a){
    num.assign(C, 0);
    vector<int> quan(C, 0);
    for (int q: a){
        quan[q]++;
    }
    for (int q = 1; q < C; q++){
        for (int q1 = q; q1 < C; q1 += q){
            num[q] += quan[q1];
        }
    }
    for (int &q: num){
        q *= q;
    }
    int ans = 0;
    for (int q = C-1; q > 0; q--){
        for (int q1 = 2*q; q1 < C; q1 += q){
            num[q] -= num[q1];
        }
        ans += num[q]*q;
    }
    return ans;
}

int easy(vector<int> &a){
    int ans = 0;
    for (int q = 1; q < a.size(); q++){
        for (int q1 = 1; q1 < a.size(); q1++){
            ans += __gcd(a[q], a[q1])*__gcd(q, q1) % MOD;
        }
    }
    return ans % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int q = 1; q <= n; q++){
        cin >> a[q];
        C = max(C, a[q]+1);
    }
    del.resize(C), was.assign(C, -1), num.assign(C, 0);
    for (int q = 1; q < C; q++){
        for (int q1 = q; q1 < C; q1 += q){
            del[q1].push_back(q);
        }
    }
    vector<int> sums(n+1);
    int cnt = 0;
    for (int q = 1; q <= n; q++){
        vector<int> now;
        for (int q1 = q; q1 <= n; q1 += q){
            now.push_back(a[q1]);
        }
        sums[q] = sum_gcd_fast(now, cnt++);
    }
    int ans = 0;
    for (int q = n; q > 0; q--){
        ans += sums[q] % MOD*q % MOD;
        for (int q1: del[q]){
            sums[q1] -= sums[q];
        }
    }
    cout << ans % MOD << endl;
    return 0;
}
