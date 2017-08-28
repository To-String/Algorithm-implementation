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

void Shell_Sord2(int *const arr, const int length)
{
	for (int gap = length / 2; gap > 0; gap /= 2)
	{
		for (int j = gap; j < length; ++j)//从数组第gap个元素开始  
		{
			if (arr[j] < arr[j - gap])//每个元素与自己组内的数据进行直接插入排序  
			{
				int temp = arr[j];
				int k = j - gap;
				while ((k >= 0) && (temp < arr[k]))
				{
					arr[k + gap] = arr[k];
					k -= gap;
				}
				arr[k + gap] = temp;
			}
		}
	}

	/*假如数据是以n=10的一个数组49, 38, 65, 97, 26, 13, 27, 49, 55, 4为例

	第一次 gap = 10 / 2 = 5

49   38   65   97   26   13   27   49   55   4

1A                       1B

	2A                       2B

		3A                       3B

			 4A                       4B

                   5A                       5B

	第二次 gap = 5 / 2 = 2

	排序后：	13   27   49   55   4    49   38   65   97   26

			 1A        1B        1C        1D        1E

				  2A        2B        2C        2D        2E

	*/

	/*对第一种希尔排序进行优化，以第二次排序为例，原来是每次从1A到1E，从2A到2E，可以改成从1B开始，
	先和1A比较，然后取2B与2A比较，再取1C与前面自己组内的数据比较…….。*/

	/*这种每次从数组第gap个元素开始，每个元素与自己组内的数据进行直接插入排序显然也是正确的。*/

	
}

int main()
{
	while (true)
	{
		{
			cout << "\n************************ 欢迎来到来到希尔排序2的世界！**********************\n" << endl
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
			Shell_Sord2(assignCapacity, arraySize);

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