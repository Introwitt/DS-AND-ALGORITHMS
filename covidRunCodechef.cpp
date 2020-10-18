#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t-->0){
		int n, k, x, y;
		cin>>n>>k>>x>>y;
		int cities[n] = {0};
		cities[x] = 1;

		int index = x;
		bool ansfound = true;
		while(1){
			index = (index+k)%n;
			if(index == y){
				cout<<"YES"<<endl;
				ansfound = true;
				break;
			}
			else if(cities[index] == 0){
				cities[index] = 1;
			}
			else{
				ansfound = false;
				break;
			}
		}

		if(!ansfound)
			cout<<"NO"<<endl;
	}

	return 0;
}