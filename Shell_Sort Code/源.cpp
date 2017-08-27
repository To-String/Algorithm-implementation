#include<iostream>
using namespace std;

void printElem(const int *arr, const int count)
{
	cout << "\n输出排序前的元素序列：";
	for (auto it = 0; it < count; ++it)
	{
		cout << arr[it] << " ";
	}
	cout << endl;
}

void Shell_Sord(int *const arr, const int length)
{

	for (int gap = length / 2; gap > 0; gap /= 2) //步长  
	{
		for (int i = 0; i < gap; ++i)         // 共gap个组，对每一组都执行  直接插入排序
		{
			for (int j = i + gap; j < length; j += gap)
			{
				if (arr[j] < arr[j - gap])   // 如果a[j] < a[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移。
				{
					int temp = arr[j];  //记录a[j]的值，找对位置后进行插入
					int k = j - gap;
					while ((k >= 0) && (temp < arr[k])) // 比较这个小组的数字，若arr[k] 大于temp，交换两个数字的位置
					{
						arr[k + gap] = arr[k]; // 进行交换
						k -= gap;
					}
					arr[k + gap] = temp;  //把arr[j]  记录的数字插入合适的位置
				}
			}
		}
	}
}

int main()
{
	while (true)
	{
		{
			cout << "\n************************ 欢迎来到来到希尔排序的世界！**********************\n" << endl
				<< "输入0，退出程序！" << endl
				<< "输入1，进行希尔排序！" << endl
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
			Shell_Sord(assignCapacity, arraySize);

			cout << "\n输出排序后的元素序列：";
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