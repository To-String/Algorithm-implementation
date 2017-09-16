#include<iostream>
#include<cassert>
using namespace std;
void printElem(const int arr[], const int count)
{
	cout << "输出排序前的元素：\n";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
}
void swapElem(int *const a, int *const b) //用指针传递，说明该函数只能修改值，不能修改指针的指向，也可写为 int &a,int &b
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubbleSort(int *const arr, const int length)
{
	assert(length > 0);
	int count = 1;		   //设置一个计数，看看几趟就能完成排序
	for (int i = 0; i < length - 1; ++i)
	{
		bool flag = false;   //设定一个标记，若为false，则表示此次循环没有进行交换，也就是待排序列已经有序，排序已然完成。
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swapElem(&arr[j], &arr[j + 1]);
				flag = true;
			}
		}
		if (!flag)	    // 如果标志为false，说明本轮遍历没有交换，已经是有序数列，可以结束排序
		{
			break;
		}
		++count;			  //说明这一趟已完成，加1计数
	}
	cout << "\n交换完毕,标志冒泡排序花了" << count << "趟就完成了排序！" << endl;



	/*冒泡排序的时间复杂度是O(N2)。
假设被排序的数列中有N个数。遍历一趟的时间复杂度是O(N)，需要遍历多少次呢？N-1次！因此，冒泡排序的时间复杂度是O(N2)。*/
}
int main()
{
	while (true)
	{
		{
			cout << "\n************************ 欢迎来到来到冒泡排序的世界！**********************\n" << endl
				<< "输入0，退出程序！" << endl
				<< "输入1，进行冒泡排序！" << endl
				<< "输入2，清屏！" << endl;
		}
		cout << "************************* 请输入你想要使用的功能的序号 **********************" << endl;
		int select(0);
		cout << "请输入你的选择：";
		cin >> select;
		if (select == 0)
		{
			cout << "程序已退出，感谢你的使用！" << endl;
			break;
		}
		switch (select)
		{
		case 1:
		{
			cout << "请输入你想排序数组元素的个数：";
			int arraySize(0);
			
			if (cin >> arraySize && arraySize <= 0)
			{
				cout << "输入错误，请输入正确的数组个数(至少大于0)，否则无法进行排序！" << endl;
				system("pause");
				exit(0);
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
			bubbleSort(assignCapacity, arraySize);
			cout << "\n输出排序后的元素顺序：";
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