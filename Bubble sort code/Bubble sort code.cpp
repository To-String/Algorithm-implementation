#include<iostream>
#include<cassert>
using namespace std;
void printElem(const int arr[], const int count)
{
	cout << "�������ǰ��Ԫ�أ�\n";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
	}
}
void swapElem(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void bubbleSort(int *const arr, const int length)
{
	assert((length > 0));
	int  count = 0;
	for (int i = 1; i < length; ++i)   //length��������ֻ�ý���length-1��,Ҳ����д��int i=0;i<length-1
	{
		for (int j = 0; j < length - i; ++j)  //�ӵ�1λ��ʼ�Ƚ�ֱ�����һ����δ��λ����
		{
			if (arr[j] > arr[j + 1])  //ֻҪ�ĳɡ�<"�ţ��Ϳ���ʵ�ֽ�����������������
			{
				swapElem(arr[j], arr[j + 1]);
			}
		}
		++count;
	}
	cout << "��ͨð�ݻ���" << count << "�����������" << endl;
	/*for (int i = 1; i < length; ++i)   //length��������ֻ�ý���length-1��,Ҳ����д��int i=0;i<length-1
	{
	for (int j = length - 1; 1 <= j; --j) //�����ǴӺ��濪ʼ�Ƚ�Ԫ�أ�ÿ�αȽ��У����������ŵ����
	{
	if (arr[j] < arr[j - 1]) //���ɡ�>" �ţ��Ϳ���ʵ�ֽ�������������
	{
	swapElem(arr[j - 1], arr[j]);  //��ʵ�����ʵ�ε�˳����Բ��øģ� ���Ǹ��ˣ�������ǿ�ɶ���
	}
	}
	}*/
}
int main()
{
	while (true)
	{
		{
			cout << "\n************************ ��ӭ��������ð����������磡**********************\n" << endl
				<< "����0���˳�����" << endl
				<< "����1������ð������" << endl
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
			bubbleSort(assignCapacity, arraySize);
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