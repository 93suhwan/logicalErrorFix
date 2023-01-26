#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
vector<int> divisors(int n){
	vector<int> div;
	div.push_back(1);
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			div.push_back(i);
			if(n/i!=i)
			div.push_back(n/i);
		}
	}
	if(n!=1)
	div.push_back(n);

	// for(auto &ele:div) cout<<ele<<" ";
	// 	cout<<endl;
	return div;
}
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	bool flag = true;
	for(int i=0;i<n;i++){
		if(v[i]!=0){
			flag = false;
			break;
		}
	}
	if(flag){
		for(int i=0;i<n;i++) cout<<i+1<<" ";
			cout<<endl;
		return;
	}
	vector<int> set_bits(30);
	for(int i=0;i<n;i++){
		for(int j=0;j<30;j++){
			if((v[i]>>j)&1) set_bits[j]++;
		}
	}
	int gc=0;
	for(auto &ele:set_bits){
		if(ele!=0) gc=__gcd(gc,ele);
	}
	vector<int> div = divisors(gc);
	for(auto &ele : div) cout<<ele<<" ";
		cout<<endl;
}	

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}