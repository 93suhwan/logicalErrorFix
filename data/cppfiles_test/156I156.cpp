#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;

const int inf = 1e9;
const ll llinf = 1e18;
const int mod = 1e9 + 7;
const double PI = acos(-1);

struct chash {
    const uint64_t C = ll(2e18*PI)+71;
    const int RANDOM = rand();
    ll operator()(ll x) const {
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

template<class K> using sset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
template<class K, class V> using gphash = gp_hash_table<K, V, chash, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>, hash_standard_resize_policy< hash_exponential_size_policy<>, hash_load_check_resize_trigger<>, true> >;

inline ll ceil0(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

inline ll floor0(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
}

void setIO() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

#define ll __int128

ll arr[300000], n, k;

ll check(ll x){
    if(x > arr[0]) return llinf;
    ll sum = x;
    ll ans = arr[0] - x;
    for(int i = 1; i < n; i++) sum += arr[i];
    for(int i = n - 1; i >= 1; i--){
        if(sum <= k) break;
        if(arr[i] > x){
            sum -= arr[i] - x;
            ans++;
        }
    } 
    ans += max((ll)0, sum - k);
    return ans;
}

int main(){
    setIO();
    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        n = a, k = b;
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            arr[i] = x;
        }
        sort(arr, arr + n);
        ll ans = llinf;
        ll l = -n, r = 0;
        while(l < r){
            ll mid = (l + r)/2;
            ll mm = check(mid), ml = check(mid - 1), mr = check(mid + 1);
            if(mm <= ml && mm < mr) l = r = mid;
            else if(ml < mm) r = mid - 1;
            else if(mr <= mm) l = mid + 1;
        }
        ans = min(ans, check(l));
        l = 1; r = arr[0];
        while(l < r){
            ll mid = (l + r)/2;
            ll mm = check(mid), ml = check(mid - 1), mr = check(mid + 1);
            if(mm <= ml && mm < mr) l = r = mid;
            else if(ml < mm) r = mid - 1;
            else if(mr <= mm) l = mid + 1;
        }
        ans = min(ans, check(l));
        assert(ans < arr[0] + n);
        cout << (long long)ans << endl; 
    }
}