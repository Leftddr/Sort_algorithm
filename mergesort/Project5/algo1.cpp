#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#pragma warning (disable:4996)

void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);

int main() {
	int i;
	int n = 9;
	int list[9] = { 21,10,12,20,25,13,15,22,24 };
	merge_sort(list, 0, n - 1);
	for (i = 0; i < n; i++) {
		printf("%d\n", list[i]);
	}
	system("pause");
	return 0;
}

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	int *sorted = (int*)malloc(sizeof(list));//크기를 전달해줘야 한다.
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}
	if (i > mid) {
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];
		}
	}
	else 
		for (l = i; l <= mid; l++) {
			sorted[k++] = list[l];
		}

	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right) {
	static int count = 0;
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right); 
		merge(list, left, mid, right);
	}
	count++;
	printf("count=%d\n", count);
}



