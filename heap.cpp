#include<iostream>
#include<vector>
using namespace std;

class heap {
	vector<int> v;
	bool minHeap;
	bool compare(int index, int parent){
		if(minHeap)
			return v[parent] > v[index];
		else
			return v[parent] <v[index];
	}
	void heapify(int index){
		int left = 2*index;
		int right = left + 1;

		int last = v.size()-1;
		int minIndex = index;

		if(left <= last && compare(left, index))
			minIndex = left;
		if(right <= last && compare(right, index))
			minIndex = right;
		
		if(minIndex != index){
			swap(v[minIndex], v[index]);
			heapify(minIndex);
		}
	}
public:
	heap(int value = 10, bool type = true){
		v.reserve(value);
		v.push_back(-1);
		minHeap = type;
	}
	void push(int value){
		v.push_back(value);
		int index = v.size()-1;
		int parent = index/2;
		while(index>1 && compare(index, parent)){
			swap(v[index], v[parent]);
			index = parent;
			parent = parent/2;
		}
	}
	void pop(){
		int last = v.size()-1;
		swap(v[1], v[last]);
		v.pop_back();
		heapify(1);
	}
	int top(){
		return v[1];
	}
	bool isEmpty(){
		if(v.size() == 1)
			return true;
		else
			return false;
	}
};

int main(){
	int n;
	cin>>n;
	heap H(n, true);
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		H.push(temp);
	}
	while(!H.isEmpty()){
		cout<<H.top()<<" ";
		H.pop();
	}

	return 0;
}