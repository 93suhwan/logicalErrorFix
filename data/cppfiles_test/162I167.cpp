#include<iostream>
#include<bits\stdc++.h>
using namespace std;
typedef long long int ll;

bool check(vector<ll> v,ll mid,ll n){

    for(ll i = 2;i < n;i++){

        ll mg = v[i]/3;

        ll g1 = ceil(double(mid - v[i-2])/2.0);
        ll g2 = mid - v[i-1];

        g1 = max(g1,(ll)0);
        g2 = max(g2,(ll)0);

        ll req = max(g1,g2);

        ll d = min(req,mg);

        v[i-2] += 2*d;
        v[i-1] += d;
        v[i] -= 3*d;
    }
    for(ll i = 0;i < n;i++){
        if(v[i] < mid){
            return false;
        }
    }
    return true;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        vector<ll> v(n);

        ll end = -1;
        ll start = INT32_MAX;

        for(int i = 0;i < n;i++){
            cin >> v[i];
            end = max(end,v[i]);
            start = min(start,v[i]);
        }

        ll ans = -1;

        while(start <= end){
            ll mid = start + (end - start)/2;

            if(check(v,mid,n)){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        cout << max(ans,ll(1)) << endl;
    }   
    return 0;
}