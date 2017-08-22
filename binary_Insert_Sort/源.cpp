#include<iostream>
using namespace std;

void printElem(const int *arr, const int count)
{
	cout << "输出打印前的元素序列：";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void binary_Insert_Sort(int *const arr, const int length)
{
	for (int i = 1; i < length; ++i)
	{     
		//使用二分查找在有序序列中进行查找，获取插入下标

		int key = arr[i]; //记录要插入的数据  
		int left = 0;
		int right = i - 1; //right其实随着循环改变，依次是0,1,2,3,4....，  这样
		while (left <= right)  //这里的left，每循环的第一次都是0
		{           //int middle = (left + right) /2
			int middle = left + ((right - left) >> 1);//*此处的mid的计算一定要放在while循环内部，
			if (arr[middle] > key)  //每次循环都是有序序列的中间那个元素首先跟key比较，
			{
				right = middle - 1; // 赋值给right， 是因为能够把middle右边的数给排除，然后最后一个数字是mid前一个数字
			}
			else
			{
				left = middle + 1;  //  赋值给left， 是因为能够把middle左边的数给排除，然后第一个数字是mid的后一个
			}
		}
		          //此时已经退出while循环，将有序序列向后移动left个位置，移动完后，那个新元素要插入的位置就是空的
		for (int j = i - 1; j >= left; --j)
		{
			arr[j + 1] = arr[j];  
		}

		arr[left] = key;  //然后把要插入的数据元素插入这个位置

	}

}

int main()
{
	while (true)
	{
		{
			cout << "\n************************ 欢迎来到来到二分(折半)插入排序的世界！**********************\n" << endl
				<< "输入0，退出程序！" << endl
				<< "输入1，进行二分(折半)插入排序！" << endl
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
			if ((cin >> arraySize) && (arraySize <= 0))
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
			binary_Insert_Sort(assignCapacity, arraySize);

			cout << "输出排序后的元素序列：\n";
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