#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#pragma warning (disable:4996)

void merge1(int, int, int);
void merge2(int, int);
void merge_sort1(int, int);
void merge_sort2(int, int*);
void quick_sort_asc(int, int);
int partition(int, int);
void display();

int arr[8] = { 123,34,189,56,150,12,9,240 };
int arr3[8] = { 123,34,189,56,150,12,9,240 };

int main() {
	int arr2[8] = { 123,34,189,56,150,12,9,240 };
	merge_sort1(0, 7);
	display();
	merge_sort2(8, arr2);
	for (int i = 0; i < 8; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");
	quick_sort_asc(0, 7);
	for (int i = 0; i < 8; i++) {
		printf("%d ", arr3[i]);
	}
	printf("\n");
	system("pause");
}

void merge1(int left, int mid, int right) {
	
	int *temp = (int *)malloc(sizeof(arr));
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i]<=arr[j]) {
			temp[k++] = arr[i];
			i++;
		}
		else {
			temp[k++] = arr[j];
			j++;
		}
	}
	if (i > mid) {
		for (l = j; l <= right; l++) { temp[k++] = arr[j]; j++; }
	}
	else {
		for (l = i; l <= mid; l++) { temp[k++] = arr[i]; i++; }
	}
	for (l = left; l <= right; l++) {
		arr[l] = temp[l];
	}
}
void merge_sort1(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort1(left, mid);
		merge_sort1(mid + 1, right);
		merge1(left, mid, right);
	}
}
void merge2(int h, int m, int*temp1,int*temp2,int *arr){
	int i = 0, j = 0, k = 0;
	while (i < h && j < m) {
		if (temp1[i] <= temp2[j]) {
			arr[k] = temp1[i];
			i++;
		}
		else if (temp1[i] > temp2[j]) {
			arr[k] = temp2[j];
			j++;
		}
		k++;
	}
	if (i >= h) {
		while (j < m) { arr[k] = temp2[j]; k++; j++; } //arr에 정렬된 temp 집어넣기
	}
	else {
		while (i < h) { arr[k] = temp1[i]; k++; i++; }
	}
}
void merge_sort2(int size,int *arr){
	if (size > 1) {
		int k = 0;
		int temp1[8];
		int temp2[8];
		int h = size / 2; //h=size의 절반의 값
		int m = size - h; // m는 size에서 h를 뺀 값
		for (int i = 0; i < h; i++) { temp1[i] = arr[k]; k++; } // temp1배열에 arr[k]까지 저장
		for (int i = 0; i < m; i++) { temp2[i] = arr[k]; k++; }//temp2배열에 arr[k+1]부터 끝까지 저장
		merge_sort2(h,temp1);
		merge_sort2(m,temp2);
		merge2(h, m, temp1, temp2, arr);
	}
}
void display() {
	for (int i = 0; i < 8; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void quick_sort_asc(int left, int right) {
	if (left < right) {
		int part = partition(left, right);
		quick_sort_asc(left, part - 1);
		quick_sort_asc(part + 1, right);
	}
}

int partition(int left, int right) {
	int first = left;
	int pivot = first;
	int temp;

	for (int i = left + 1; i <= right; i++) {
		if (arr3[i] <= arr3[pivot]) {//첫번째 기준 값이랑 다음값을 계속 옮겨 다니면서 비교해준다.
			first++;
			temp = arr3[i];
			arr3[i] = arr3[first];
			arr3[first] = temp;
		}
	}

	temp = arr3[pivot];
	arr3[pivot] = arr3[first];
	arr3[first] = temp;
	right = first; // 기준점을 first변수에 들어있는 값으로 바꾸어 준다.
	return right;
}