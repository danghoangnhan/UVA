#include <iostream>	
using namespace std;
#define MAXSIZE 200		
struct turtle
{
	string name;
	int index;
};
	
void shell_sort(turtle start[], turtle last[], int capacity)
{
	// ��l���A���Q�t������̲ת��A�Q�t�s���C
	for (int i = 0; i < capacity; i++)
		for (int j = 0; j < capacity; j++)
			if (start[j].name == last[i].name) {
				start[j].index = last[i].index;
				break;
			}
	
	// ��l���A�Q�t�Ƨ�
	for (int i = capacity; i > 1; i--) {
		// ����l���A�Q�t�Ǹ�i�M�]i - 1�^�����Q�t�b�ƻ��m (current, previous) 
		int current, previous;
		for (int j = 0; j < capacity; j++) {
			if (start[j].index == i)        current = j;
			if (start[j].index == (i - 1))  previous = j;
		}
		
		// �p�G�Ǹ��Q�t�]i - 1�^�b�Ǹ�i���Q�t���U��A�h��Ǹ�(i-1)�Q�t�\��̤W�Y
		if (previous > current)	{
			cout << start[previous].name << endl;
			turtle tmp = start[previous];
			for (int j = previous; j > 0; j--) {   // ��l���A�Ǹ�(i-1)�H�W���Q�t���U�h���@�Ӧ�m 
				start[j].name = start[j - 1].name;
				start[j].index = start[j - 1].index;
			}
			start[0].name = tmp.name;    // ��l���A�Ǹ�(i-1)�Q�t�@��̳��� 
			start[0].index = tmp.index;
		}
	}
}
	
int main(int ac, char *av[])
{
	int cases, capacity;
	turtle start[MAXSIZE];
	turtle last[MAXSIZE];
	
	freopen("10152.in", "r", stdin);
    freopen("10152.out","w",stdout);
	
	cin >> cases;
	while(cases--) {
		cin >> capacity;
		cin.ignore();
		
		// ��J��l�Q�t�C
		for (int i = 0; i < capacity; i++)
			getline(cin, start[i].name);
		
		// ��J�̲ׯQ�t�ȩ̀ǵ��s���q1��n
		for (int i = 0; i < capacity; i++) {
			getline(cin, last[i].name);
			last[i].index = (i + 1);
		}
		
		// ���l���A�Q�t�Ƨ�
		shell_sort(start, last, capacity);
		
		if (cases>0)cout << endl;
	}	
	return 0;
}

