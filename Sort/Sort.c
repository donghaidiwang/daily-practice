#include"Sort.h"
#include"Stack.h"
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end+1] = tmp;
	}
}
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* a, int n)
{
	int left = 0,right=n-1;
	while (left < right)
	{
		int minIndex = left, maxIndex = left;
		for (int i = left;i <= right; i++)
		{
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
			if (a[i] > a[maxIndex])
			{
				maxIndex = i;
			}
		}
		Swap(&a[left], &a[minIndex]);
		//如果left和maxIndex重合，left换了会导致maxIndex不指向最大值改变，要修正
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		Swap(&a[right], &a[maxIndex]);
		left++;
		right--;
	}
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//建大堆
	for(int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int exchange = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchange = 1;
			}
		}
		if (exchange==0)
		{
			break;
		}
	}
}
int GetMidIndex(int* a, int left, int right)//三数取中优化快排
{
	int mid = (left + right) >> 1;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else //a[left] <= a[mid]
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (left > right)
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
//hoare法 左右指针法
int PartSort1(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;
	while (left < right)
	{
		//找小
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//找大
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	int meeti = right;
	Swap(&a[keyi], &a[meeti]);
	return meeti;
}
//挖坑法
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = a[left];
	while (left < right)
	{
		//左边是坑，找小放到左边的坑
		while (left < right && a[right] >= key)
		{
			right--;
		}
		//找到小，放左坑，右边成为新的坑
		a[left] = a[right];
		//找大
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//找到大，放右坑，左边变成新的坑
		a[right] = a[left];
	}
	//相遇为坑，将key放入最后的坑
	a[right] = key;
	return right;
}
//前后指针法
int PartSort3(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left, prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	if (end - begin > 100)
	{
		int meeti = PartSort3(a, begin, end);
		QuickSort(a, begin, meeti - 1);
		QuickSort(a, meeti + 1, end);
	}
	else
	{
		HeapSort(a + begin, end - begin + 1);
	}
}
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);
		int keyi = PartSort1(a, left, right);
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi-1);
		}
		if (right > keyi + 1)
		{
			StackPush(&st, keyi+1);
			StackPush(&st, right);
		}
	}
	StackDestroy(&st);
}
void _MergeSort(int* a, int left, int right,int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	//归并完成以后，拷贝回到原数组
	memcpy(a + left, tmp + left, sizeof(a[0])*(right - left+1));
	/*for (int j = left; j <= right; j++)
	{
		a[j] = tmp[j];
	}*/

}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(a[0]) * n);
	if (tmp == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1,tmp);
	free(tmp);
}
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(a[0]) * n);
	if (tmp == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int left = begin1, right = end2;
			//如果第二个区间不存在，或者第一个区间不够gap个，就不进行归并
			if (begin2 >= n)
			{
				break;
			}
			//如果第二个区间存在，但是不够gap个，调整区间大小
			if (end2>=n)
			{
				right=end2 = n - 1;
			}
			int j = left;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			//归并完成以后，拷贝回到原数组
			memcpy(a + left, tmp + left, sizeof(a[0]) * (right - left + 1));
		}
		gap *= 2;
	}
	free(tmp);
}
void CountSort(int* a, int n)
{
	int i,j,min = 0,max=0;
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int) * range);
	if (count == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	for (i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	j = 0;
	for (i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i+min;
		}
	}
	free(count);
}