#include<iostream>
using namespace std;

void reverse(int *const arr,const int size) //逆序数组
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int temp = arr[left];
		arr[left++] = arr[right];
		arr[right--] = temp;
		//left++
		//right--
	}
}

void swapMemory(int *const arr, const int headSize, const int endSize) //交换数据
{
	reverse(arr, headSize);
	reverse(arr + headSize, endSize);
	reverse(arr, headSize + endSize);
}

void inplace_Merge( int *const arr, int beg, int mid, int end)
{
	int i = beg;     // 指示有序串1
	int j = mid + 1; // 指示有序串2
	while (i < j && j <= end) //原地归并结束的条件。
	{
		while (i < j && arr[i] <= arr[j])
		{
			++i;
		}
		int index = j;
		while (j <= end && arr[j] <= arr[i])
		{
			++j;
		}
		swapMemory(&arr[i], index - i, j - index);//swap [i,index) and [index,j)
		i += (j - index);
	}
}

void inplace_MergeSort(int *const arr, int beg, int end)  //原地排序
{
	if (beg < end)
	{
		int mid = (beg + end) / 2;
		inplace_MergeSort(arr, beg, mid);
		inplace_MergeSort(arr, mid + 1, end);
		inplace_Merge(arr, beg, mid, end);
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
			cout << "\n************************ 欢迎来到来到原地归并排序的世界！**********************\n" << endl
				<< "输入0，退出程序！" << endl
				<< "输入1，进行原地归并排序！" << endl
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
			inplace_MergeSort(assignCapacity, 0,arraySize-1);

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