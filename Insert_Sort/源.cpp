#include<iostream>
using namespace std;

void printElem(const int arr[], const int count)
{
	cout << "�������ǰ��Ԫ�أ�\n";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void insertSort(int *const arr, const int length)
{
	for (int i = 1; i < length; ++i)  //�ӵ�2�����ݿ�ʼ����  
	{
		int j = i - 1;
		int temp = arr[i];  //��¼Ҫ���������  
		while (j >= 0 && arr[j] > temp)  //�Ӻ���ǰ���ҵ�����С������λ��  
		{ 
			arr[j + 1] = arr[j];   //���Ų��  
			--j;
		}
		if (j != i - 1)  //���ڱ���С����(��ʵ���if���ȥ����ֱ�Ӻ�������Ҳ�ǿ��Ե�)  
		{
			arr[j + 1] = temp;  //��Ҫ��������ݲ�����ʵ�λ��
		}
		
	}
}
int main()
{
	while (true)
	{
		{
			cout << "\n************************ ��ӭ��������������������磡**********************\n" << endl
				<< "����0���˳�����" << endl
				<< "����1�����в�������" << endl
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
			insertSort(assignCapacity, arraySize);

			cout << "���������Ԫ�����У�\n";
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