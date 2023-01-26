#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int solve(){
	ll n,f1=1,f2=1;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
	cin>>a[i];
	if(n==2){
	if(a[0]!=a[1]){
	cout<<max(a[0],a[1])<<endl;;
	return 0;
}
	else
	cout<<0<<endl;
	return 0;
}
	ll d1,d2;
	for(ll i=0;i<n-2;i++){
	if(i%2==0)
	d1=__gcd(a[i],a[i+2]);
	if(i%2!=0)
	d2=__gcd(a[i],a[i+2]);

}
    if(n==3)
    d2=a[1];
    for(ll i=0;i<n;i++){
		if(i%2==0){
			if(a[i]%d1!=0)
			f1=0;
			if(a[i]%d2==0)
			f2=0;
		}
		if(i%2!=0){
			if(a[i]%d2!=0)
			f2=0;
			if(a[i]%d1==0)
			f1=0;
		}
		if(!f1 & !f2){
			cout<<0<<endl;
			return 0;
		}
	}
	if(f1){
	cout<<d1<<endl;
	return 0;
}
    if(f2){
	cout<<d2<<endl;
	return 0;
}
    return 0;
}
int main(){
	fastIO;
	ll T=1;
	cin>>T;
	while(T--){
		solve();
	}
}
