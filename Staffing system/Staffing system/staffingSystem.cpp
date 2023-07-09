#include<iostream>
#include "workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
//测试多态
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
		std::cout << "请输入你的选择：" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 0://退出管理系统
			wm.exitFunction();
			break;
		case 1://增加职工信息
			wm.addFunction();
			break;
		case 2://显示职工信息
			wm.showWorker();
			break;
		case 3://删除离职职工
			wm.deleteWorker();
			break;
		case 4://修改职工信息
			wm.modifyWorker();
			break;
		case 5://查找职工信息
			wm.findWorker();
			break;
		case 6://按照编号排序
			wm.sortWorker();
			break;
		case 7://清空所有文档
			wm.clearFile();
			break;
		default://输入其他清空屏幕
			system("cls");
			break;
		}
	}
	system("pause");//界面停留
	return 0;
}
