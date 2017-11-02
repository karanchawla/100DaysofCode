#include <vector> 
#include <iostream>

using namespace std; 

void merge(vector<int> arr, vector<int> aux, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while(i <= mid && j<=high)
	{
		if(arr[i] < arr[j])
			aux[k++] = arr[i++];
		else
			aux[k++] = arr[j++];
	}

	while(i <= mid)
		aux[k++] = arr[i++];

	for(int i = 0; i <= high; i++)
		arr[i] = aux[i];
}

void mergeSort(vector<int> arr, vector<int> aux, int low, int high)
{
	if(high==low)
		return;

	int mid = low + (high-low)/2;

	mergeSort(arr, aux, low, mid);
	mergeSort(arr, aux, mid+1, high);

	merge(arr, aux, low, mid, high);
}