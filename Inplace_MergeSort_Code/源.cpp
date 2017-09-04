#include<iostream>
using namespace std;

void reverse(int *const arr,const int size) //��������
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

void swapMemory(int *const arr, const int headSize, const int endSize) //��������
{
	reverse(arr, headSize);
	reverse(arr + headSize, endSize);
	reverse(arr, headSize + endSize);
}

void inplace_Merge( int *const arr, int beg, int mid, int end)
{
	int i = beg;     // ָʾ����1
	int j = mid + 1; // ָʾ����2
	while (i < j && j <= end) //ԭ�ع鲢������������
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

void inplace_MergeSort(int *const arr, int beg, int end)  //ԭ������
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
	cout << "\n�������ǰ��Ԫ�����У�\n";
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
			cout << "\n************************ ��ӭ��������ԭ�ع鲢��������磡**********************\n" << endl
				<< "����0���˳�����" << endl
				<< "����1������ԭ�ع鲢����" << endl
				<< "����2��������" << endl;
		}
		cout << "************************* ����������Ҫʹ�õĹ��ܵ���� **********************" << endl;
		int select(0);
		cout << "���������ѡ��";
		cin >> select;
		if (select == 0)
		{
			cout << "�������˳�����л���ʹ��!" << endl;
			break;
		}
		switch (select)
		{
		case 1:
		{
			cout << "�����������������Ԫ�صĸ�����";
			int arraySize;
			if (cin >> arraySize && arraySize <= 0)
			{
				cout << "���������������ȷ���������(���ٴ���0)�������޷���������" << endl;
				system("pause");
				continue;
			}

			int *assignCapacity = new int[arraySize];
			if (!assignCapacity)
			{
				cout << "���󣬷��������ڴ�ʱʧ�ܣ����������г���" << endl;
				system("pause");
				exit(0);
			}
			cout << "��ֱ����������������" << arraySize << "��Ԫ�أ��м��Իس���������\n";
			for (int i = 0; i < arraySize; ++i)
			{
				cin >> assignCapacity[i];
			}

			printElem(assignCapacity, arraySize);
			inplace_MergeSort(assignCapacity, 0,arraySize-1);

			cout << "\n���������Ԫ�����У�\n";
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
			cout << "�����������������������룡" << endl;
			break;
		default:
			cout << "�������Ų���ȷ�����������룡" << endl;
		}
	}
	system("pause");
	return 0;
}