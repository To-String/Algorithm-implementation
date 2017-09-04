#include<iostream>
using namespace std;


/*
* 函数功能：将一个数组中的两个相邻有序区间合并成一个
*
* 参数说明：
*     arr -- 包含两个有序区间的数组
*     start -- 第1个有序区间的起始地址。
*     mid   -- 第1个有序区间的结束地址。也是第2个有序区间的起始地址。
*     end   -- 第2个有序区间的结束地址。
*/
void merge(int *const arr, const int start, const int mid, const int end)
{

	int *tmp = new int[end - start + 1];    // tmp是汇总2个有序区的临时区域
	int i = start;            // 第1个有序区的索引
	int j = mid + 1;        // 第2个有序区的索引
	int k = 0;               // k是临时存放合并序列的下标

							 // 扫描第一段和第二段序列，直到有一个扫描结束
	while (i <= mid && j <= end)
	{
		// 判断第一段和第二段取出的数哪个更小，将其存入合并序列，并继续向下扫描
		if (arr[i] <= arr[j])
		{
			tmp[k++] = arr[i++];
			//i++
			//k++
		}
		else
		{
			tmp[k++] = arr[j++];
			//j++
			//k++
		}
	}

	// 若第一段序列还没扫描完，将其全部复制到合并序列
	while (i <= mid)  //将左边剩余元素填充进tmp中
	{
		tmp[k++] = arr[i++];
	}

	// 若第二段序列还没扫描完，将其全部复制到合并序列
	while (j <= end) //将右序列剩余元素填充进tmp中
	{
		tmp[k++] = arr[j++];
	}

	// 将排序后的元素，全部都整合到数组arr中。
	for (i = 0; i < k; ++i)
	{
		arr[start + i] = tmp[i];
	}

	delete[] tmp;
	tmp = nullptr;
}


/*
* 归并排序(从上往下)
*
* 参数说明：
*     arr -- 待排序的数组
*     start -- 数组的起始地址
*     end -- 数组的结束地址
*/
void mergeSortUp2Down(int *const arr, const int start, const int end)
{
	/* if(a==NULL || start >= end)
	return ;*/

	if (start < end)
	{
		int mid = (end + start) / 2;
		mergeSortUp2Down(arr, start, mid); // 递归排序a[start...mid] ,左边归并排序，使得左子序列有序
		mergeSortUp2Down(arr, mid + 1, end); // 递归排序a[mid+1...end]  右边归并排序，使得右子序列有序

											 // a[start...mid] 和 a[mid...end]是两个有序空间，
											 // 将它们排序成一个有序空间a[start...end]
		merge(arr, start, mid, end);  //将两个有序子数组合并操作
	}
}

void printElem(const int *const arr, const int count)
{
	cout << "\n输出排序前的元素序列：\n";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	while (true)
	{
		{
			cout << "\n************************ 欢迎来到来到自顶向下归并排序的世界！**********************\n" << endl
				<< "输入0，退出程序！" << endl
				<< "输入1，进行自顶向下归并排序！" << endl
				<< "输入2，清屏！" << endl;
		}
		cout << "************************* 请输入你想要使用的功能的序号 **********************" << endl;
		int select(0);
		cout << "请输入你的选择：";
		cin >> select;
		if (select == 0)
		{
			cout << "程序已退出，感谢你的使用!" << endl;
			break;
		}
		switch (select)
		{
		case 1:
		{
			cout << "请输入你想进行排序元素的个数：";
			int arraySize;
			if (cin >> arraySize && arraySize <= 0)
			{
				cout << "输入错误，请输入正确的数组个数(至少大于0)，否则无法进行排序！" << endl;
				system("pause");
				continue;
			}

			int *assignCapacity = new int[arraySize];
			if (!assignCapacity)
			{
				cout << "错误，分配数组内存时失败，请重新运行程序！" << endl;
				system("pause");
				exit(0);
			}
			cout << "请分别输入你想排序的这" << arraySize << "个元素，中间以回车键隔开：\n";
			for (int i = 0; i < arraySize; ++i)
			{
				cin >> assignCapacity[i];
			}

			printElem(assignCapacity, arraySize);
			mergeSortUp2Down(assignCapacity, 0, arraySize - 1);

			cout << "\n输出排序后的元素序列：\n";
			for (int k = 0; k < arraySize; ++k)
			{
				cout << assignCapacity[k] << " ";
			}
			cout << endl;
			delete[]assignCapacity;
			assignCapacity = nullptr;
			break;
		}
		case 2:
			system("cls");
			cout << "程序已清屏！可以重新输入！" << endl;
			break;
		default:
			cout << "输入的序号不正确，请重新输入！" << endl;
		}
	}
	system("pause");
	return 0;
}