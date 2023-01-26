#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mp make_pair

int main(){
    int t;
    cin>>t;
    while(t--){
       ll x;
       cin>>x;
       x--;
       for(ll i=2;i<=min(x,100LL);i++){
            if(__gcd(x-i,i)==1){
            cout<<x-2<<' '<<i<<" 1\n";
            break;
            }
       }
    }


}
/*

10
101
*/
