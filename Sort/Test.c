#include"Sort.h"
int main()
{
	srand((unsigned int)time(NULL));
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	if (a1 == NULL)
	{
		perror("malloc");
		return 1;
	}
	if (a2 == NULL)
	{
		perror("malloc");
		return 1;
	}
	if (a3 == NULL)
	{
		perror("malloc");
		return 1;
	}
	if (a4 == NULL)
	{
		perror("malloc");
		return 1;
	}
	for (int i = 0; i < N; i++)
	{
		a1[i]=a2[i]=a3[i]=a4[i] = rand();
	}
	//int begin1 = clock();
	//HeapSort(a1, N);
	//int end1 = clock();
	//printf("HeapSort:%d\n", end1 - begin1);
	//int begin2 = clock();
	//ShellSort(a2, N);
	//int end2 = clock();
	//printf("ShellSort:%d\n", end2 - begin2);
	int begin3 = clock();
	QuickSort(a2, 0,N-1);
	int end3 = clock();
	printf("QuickSort:%d\n", end3 - begin3);
	//int begin4 = clock();
	//MergeSort(a4,N);
	//int end4 = clock();
	//printf("MergeSort:%d", end4 - begin4);
	/*int a[] = {10,6,7,1,3,9,4,2};
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort(a,0,n-1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}*/
	free(a1);
	a1 = NULL;
	free(a2);
	a2 = NULL;
	free(a3);
	a3 = NULL;
	free(a4);
	a4 = NULL;
	return 0;
}