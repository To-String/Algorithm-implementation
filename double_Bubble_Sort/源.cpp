#include<iostream>
#include<cassert>
using namespace std;

void printElem(const int *arr, const int count)
{
	cout << "\n�������ǰ��Ԫ�أ�\n";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
}

void swapElem(int &a, int  &b) 
{
	int temp = a;
	a = b;
	b = temp;
}

void double_Bubble_Sort( int *const arr,const  int length)
{
	assert(length > 0);

	int count = 1;
	for (int i = 0; i < length - 1; ++i)
	{
		bool flag = false; 
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swapElem(arr[j], arr[j + 1]);
				flag = true;
			}
		}

		if (!flag)	    // �����־Ϊfalse��˵�����ֱ���û�н������Ѿ����������У����Խ�������
		{
			break;
		}

		for (int k = length - i - 1 - 1; k > i; --k)
		{
			if (arr[k] < arr[k - 1])
			{ // ��С����ǰ����
				swapElem(arr[k], arr[k - 1]);
				flag = true;
			}
		}
		++count;
		if (!flag)	    // �����־Ϊfalse��˵�����ֱ���û�н������Ѿ����������У����Խ�������
		{
			break;
		}
	}
	cout << "\n�������,˫��ð��������" << count << "�˾����������" << endl;

	/* ˫��ð�������ʱ�临�Ӷ��뵥����ͬ��*/
}

int main()
{
	while (true)
	{
		{
			cout << "\n************************ ��ӭ��������˫��ð����������磡**********************\n" << endl
				<< "����0���˳�����" << endl
				<< "����1������˫��ð������" << endl
				<< "����2��������" << endl;
		}
		cout << "************************* ����������Ҫʹ�õĹ��ܵ���� **********************" << endl;
		int select(0);
		cout << "���������ѡ��";
		cin >> select;
		if (select == 0)
		{
			cout << "�������˳�����л���ʹ�ã�" << endl;
			break;
		}
		switch (select)
		{
		case 1:
		{
			cout << "������������������Ԫ�صĸ�����";
			int arraySize(0);
			cin >> arraySize;
			if (arraySize <= 0)
			{
				cout << "���������������ȷ���������(���ٴ���0)�������޷���������" << endl;
				system("pause");
				exit(0);
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
			double_Bubble_Sort(assignCapacity, arraySize);
			cout << "\n���������Ԫ��˳��";
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