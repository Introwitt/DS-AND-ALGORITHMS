#include<iostream>
#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std:: chrono;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubble_sort(int arr[],int n){

    for(int i=0; i < n-1; i++){
        for(int j=0; j< n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
}

int main(){

    auto start = high_resolution_clock::now(); 

    int n;
    cout<<"Enter the number of elements in array"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    bubble_sort(arr,n);
    cout<<"After sorting"<<endl;
    printarray(arr,n);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);
    cout<<"Time duration in nanoseconds: "<<duration.count() <<endl;
    return 0;
        
}