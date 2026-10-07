#include<bits/std++.h>
using namespace std;
boolsubsetSum(vector<int> &arr, int index, int remaning){
	if(remaming==0) return true;
	if(index == arr.size() || remaining<0) return false;
	if(subsetSum(arr,index+1,remaining-arr[index])) return true;
	return subsetSum(arr,index+1,remaining;
	}
	int main(){
		int n;
		cout<"enter number of elements:";
		cin>>n;
		vector<int>arr(n);
		cout<<"Enter"<<nNN"Elements:";
		for(int i=0;i<n;i++)cin>>arr[i];
		int targer;
		cout<<"Enter target sum;";
		cin>>target;
		bool result=subsetSum(arr,0,target);
		cout<<(result?"A subset with the given sum exsts." : "NO such subset exists")<<endl;)
	}
	return 0;
}
