#include<iostream>
using namespace std;

void printElem(const int arr[], const int count)
{
	cout << "输出排序前的元素：\n";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void insertSort(int *const arr, const int length)
{
	for (int i = 1; i < length; ++i)  //从第2个数据开始插入  
	{
		int j = i - 1;
		int temp = arr[i];  //记录要插入的数据  
		while (j >= 0 && arr[j] > temp)  //从后向前，找到比其小的数的位置  
		{ 
			arr[j + 1] = arr[j];   //向后挪动  
			--j;
		}
		if (j != i - 1)  //存在比其小的数(其实这个if语句去掉，直接后面的语句也是可以的)  
		{
			arr[j + 1] = temp;  //把要插入的数据插入合适的位置
		}
		
	}
}
int main()
{
	while (true)
	{
		{
			cout << "\n************************ 欢迎来到来到插入排序的世界！**********************\n" << endl
				<< "输入0，退出程序！" << endl
				<< "输入1，进行插入排序！" << endl
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
			insertSort(assignCapacity, arraySize);

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