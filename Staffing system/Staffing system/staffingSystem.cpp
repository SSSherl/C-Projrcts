#include<iostream>
#include "workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
//���Զ�̬
void test01()
{
	Worker* worker = NULL;
	worker = new Employee(1, "Bob", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "Jessica", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "Sherl", 3);
	worker->showInfo();
	delete worker;
}
int main()
{
	WorkerManager wm;
	int choice = 0;
	
	while (true)
	{
		wm.showMenu();
		std::cout << "���������ѡ��" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 0://�˳�����ϵͳ
			wm.exitFunction();
			break;
		case 1://����ְ����Ϣ
			wm.addFunction();
			break;
		case 2://��ʾְ����Ϣ
			wm.showWorker();
			break;
		case 3://ɾ����ְְ��
			wm.deleteWorker();
			break;
		case 4://�޸�ְ����Ϣ
			wm.modifyWorker();
			break;
		case 5://����ְ����Ϣ
			wm.findWorker();
			break;
		case 6://���ձ������
			wm.sortWorker();
			break;
		case 7://��������ĵ�
			wm.clearFile();
			break;
		default://�������������Ļ
			system("cls");
			break;
		}
	}
	system("pause");//����ͣ��
	return 0;
}
