#include <bits\stdc++.h>
using namespace std;
int main(){
	int i,j,k=0,n;
	cin>>n;
	vector <int> a;
	while(n--){
		string s;
		cin>>s;
		vector <char> v;
		int p=0;
		for(i=0;i<s.length();i++){
			v.push_back(s[i]);
		}
		if(s.length()==1){
			cout<<0<<endl;
		}
		else if(count(v.begin(),v.end(),v[0])==s.length()){
			cout<<1<<endl;
		}
		else{
			vector <char> c;
			for(j=0;j<s.length();j++){
				int m=count(v.begin(),v.end(),v[j]);
				if(m>1){
					p++;
					v.erase(remove(v.begin(),v.end(),v[j]),v.end());
				}
				else{
					c.push_back(v[j]);
				}
			}
			int b = ((c.size())/2);
			cout<<p<<endl;

		}

	}
	return 0;
}