#include"commonalgorithm.h"
void QuickSort(int *list, int length) {

}        

int _Merge(int *list, int length, int left, int right) {
	//选左边第一位为中间位
	int inter = list[left];
	int inter_index = left;
	left++;
	while (left <= right) {
		if (list[left] <= inter && list[right] > inter) {
			left++;
			right--;
		}
		else if (list[left] <= inter && list[right] <= inter) {
			left++;
		}
		else if (list[left] > inter && list[right] > inter) {
			right--;
		}
		else {
			int temp = list[left];
			list[left] = list[right];
			list[right] = temp;
			left++;
			right--;
		}

	}
	return 0;
}

void SelectSort(int *list, int length)
{
	
	for (int i = 0; i < length; i++) {
		
	}
}