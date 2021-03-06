int partition(int* arr,int left,int right){
  //选取第一个数为轴
	int pivot = arr[left];
	while (left<right) {
    //从最右边right比较，遇到比轴小的则交换位置，记录当前right，然后从左边比较，比轴大的则和之前的right交换位置，直至left=right
		while (left < right && arr[right] > pivot)
			right--;
		arr[left] = arr[right];
		while (left < right && arr[left] < pivot)
			left++;
		arr[right] = arr[left];
	}
	arr[left] = pivot;
	return left;
}

void sort(int * arr,int left,int right){
	if (left < right) {
		int pivot = partition(arr, left, right);//将当前选的轴置于自己的位置
		sort(arr, left, pivot-1);
		sort(arr, pivot+1, right);
	}
}
