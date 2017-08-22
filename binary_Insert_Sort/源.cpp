#include<iostream>
using namespace std;

void printElem(const int *arr, const int count)
{
	cout << "�����ӡǰ��Ԫ�����У�";
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
		//ʹ�ö��ֲ��������������н��в��ң���ȡ�����±�

		int key = arr[i]; //��¼Ҫ���������  
		int left = 0;
		int right = i - 1; //right��ʵ����ѭ���ı䣬������0,1,2,3,4....��  ����
		while (left <= right)  //�����left��ÿѭ���ĵ�һ�ζ���0
		{           //int middle = (left + right) /2
			int middle = left + ((right - left) >> 1);//*�˴���mid�ļ���һ��Ҫ����whileѭ���ڲ���
			if (arr[middle] > key)  //ÿ��ѭ�������������е��м��Ǹ�Ԫ�����ȸ�key�Ƚϣ�
			{
				right = middle - 1; // ��ֵ��right�� ����Ϊ�ܹ���middle�ұߵ������ų���Ȼ�����һ��������midǰһ������
			}
			else
			{
				left = middle + 1;  //  ��ֵ��left�� ����Ϊ�ܹ���middle��ߵ������ų���Ȼ���һ��������mid�ĺ�һ��
			}
		}
		          //��ʱ�Ѿ��˳�whileѭ������������������ƶ�left��λ�ã��ƶ�����Ǹ���Ԫ��Ҫ�����λ�þ��ǿյ�
		for (int j = i - 1; j >= left; --j)
		{
			arr[j + 1] = arr[j];  
		}

		arr[left] = key;  //Ȼ���Ҫ���������Ԫ�ز������λ��

	}

}

int main()
{
	while (true)
	{
		{
			cout << "\n************************ ��ӭ������������(�۰�)������������磡**********************\n" << endl
				<< "����0���˳�����" << endl
				<< "����1�����ж���(�۰�)��������" << endl
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
			if ((cin >> arraySize) && (arraySize <= 0))
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
			binary_Insert_Sort(assignCapacity, arraySize);

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