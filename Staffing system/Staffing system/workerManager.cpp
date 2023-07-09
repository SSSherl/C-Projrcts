#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
constexpr auto FILENAME = "workerFile.txt";

WorkerManager::WorkerManager()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	//文件不存在时，进行一系列初始化
	if (!ifs.is_open())
	{
		//std::cout << "文件不存在！" << std::endl;//测试
		//初始化人数
		this->m_workerNum = 0;
		//初始化成员数组的指针
		this->m_workerArr = NULL;
		//初始化文件是否创建
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	//文件为空时，进行一系列初始化
	if (ifs.eof())
	{
		//std::cout << "文件不存在！" << std::endl;//测试
		//初始化人数
		this->m_workerNum = 0;
		//初始化成员数组的指针
		this->m_workerArr = NULL;
		//初始化文件是否创建
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空时，读取人数
	this->m_workerNum = getNum();
	//文件不为空时，往数组中载入原有数据
	//先开辟空间
	this->m_workerArr = new Worker * [this->m_workerNum];
	//在调用载入函数
	loadWorker();

}
WorkerManager::~WorkerManager()
{
	//释放堆区数据
	if (this->m_workerArr != NULL)
	{
		delete[] m_workerArr;
	}
}

void WorkerManager::showMenu()
{
	std::cout << "*******************************************************" << std::endl;
	std::cout << "*******************欢迎来到职工管理系统****************" << std::endl;
	std::cout << "*********************0.退出管理系统********************" << std::endl;
	std::cout << "*********************1.增加职工信息********************" << std::endl;
	std::cout << "*********************2.显示职工信息********************" << std::endl;
	std::cout << "*********************3.删除离职职工********************" << std::endl;
	std::cout << "*********************4.修改职工信息********************" << std::endl;
	std::cout << "*********************5.查找职工信息********************" << std::endl;
	std::cout << "*********************6.按照编号排序********************" << std::endl;
	std::cout << "*********************7.清空所有文档********************" << std::endl;
	std::cout << "*******************************************************" << std::endl;
	std::cout << std::endl;
}
void WorkerManager::exitFunction()
{
	std::cout << "欢迎下次使用！" << std::endl;
	system("pause");
	exit(0);//退出程序
}

void WorkerManager::addFunction()
{
	int addNum = 0;
	std::cout << "请输入增加职工的数量:	" << std::endl;
	std::cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_workerNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker * [newSize+3];

		//将原空间内容放入新空间
		if (this->m_workerArr != NULL)
		{
			for (int i = 0; i < this->m_workerNum; i++)
			{
				newSpace[i] = this->m_workerArr[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			std::string name;
			int deptId;

			std::cout << "请输入第" << i + 1 << "位职员编号" << std::endl;
			std::cin >> id;

			std::cout << "请输入第" << i + 1 << "位职员姓名" << std::endl;
			std::cin >> name;

			std::cout << "请选择该职员的岗位编号" << std::endl;
			std::cout << "1.员工" << std::endl;
			std::cout << "2.经理" << std::endl;
			std::cout << "3.老板" << std::endl;
			std::cin >> deptId;

			Worker* worker = NULL;
			switch (deptId)
			{
			case 1://员工
				worker = new Employee(id, name, 1);
				break;
			case 2://经理
				worker = new Manager(id, name, 2);
				break;
			case 3://老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_workerNum + i] = worker;//缓冲区溢出解决方法1：改成解引用；2数组再加3或4
		}
		//释放原有空间
		delete [] this->m_workerArr;

		//更改新空间指向
		this->m_workerArr = newSpace;

		//更新个数
		this->m_workerNum = newSize;

		//提示信息
		std::cout << "成功添加" << addNum << "位新职员！" << std::endl;

		//保存文件
		this->saveFile();

		//更新文件是否为空
		this->m_fileIsEmpty = false;
	}
	else
	{
		std::cout << "输入有误！" << std::endl;
	}
	system("pause");

}

void WorkerManager::saveFile()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);

	for (int i = 0; i < this->m_workerNum; i++)
	{
		ofs << this->m_workerArr[i]->m_id << "		" << this->m_workerArr[i]->m_name << "		"
			<< this->m_workerArr[i]->getDept() << "		" << std::endl;
	}

}
int WorkerManager::getNum()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);
	int id;
	std::string name;
	int deptId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> deptId)
	{
		//记录人数
		num++;
	}
	ifs.close();
	return num;
}
void WorkerManager::loadWorker()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);
	int id;
	std::string name;
	int deptId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deptId)
	{
		Worker* worker = NULL;
		if (id == 1)//普通员工
		{
			worker = new Employee(id, name, deptId);
		}
		else if (id == 2)//经理
		{
			worker = new Manager(id, name, deptId);
		}
		else//老板
		{
			worker = new Boss(id, name, deptId);
		}

		//存入数组
		this->m_workerArr[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManager::showWorker()
{
	if (this->m_fileIsEmpty)
	{
		std::cout << "文件不存在或为空" << std::endl;
	}
	else
	{
		for (int i = 0; i < this->m_workerNum; i++)
		{
			//利用多态调用showInfo函数
			this->m_workerArr[i]->showInfo();
		}
	}
	system("pause");
}
int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_workerNum; i++)
	{
		if (this->m_workerArr[i]->m_id == id)
		{
			index = i;
			break;
		}
		
	}
	return index;
}
void WorkerManager::deleteWorker()
{
	if (this->m_fileIsEmpty)
	{
		std::cout << "文件不存在或为空" << std::endl;
	}
	else
	{
		int id = 0;
		std::cout << "请输入要删除职工的ID：	";
		std::cin >> id;
		int index = isExist(id);
		if (index == -1)
		{
			std::cout << "职工不存在！" << std::endl;
		}
		else
		{
			for (int i = index; i < this->m_workerNum-1; i++)
			{
				this->m_workerArr[i] = this->m_workerArr[i + 1];
			}
			//更新删除之后的职工人数
			this->m_workerNum--;
			//更新文件数据
			this->saveFile();

			std::cout << "删除成功！" << std::endl;
		}
	}
	system("pause");

	
}
void WorkerManager::modifyWorker()
{
	if (this->m_fileIsEmpty)
	{
		std::cout << "文件不存在或为空" << std::endl;
	}
	else
	{
		int id = 0;
		std::cout << "请输入要修改职工的ID：	";
		std::cin >> id;
		int index = isExist(id);
		if (index == -1)
		{
			std::cout << "职工不存在！" << std::endl;
		}
		else
		{
			//删除原有职工的信息
			delete this->m_workerArr[index];

			int newId = 0;
			std::string newName = "";
			int newDeptId = 0;

			std::cout << "请输入新的职工号:	";
			std::cin >> newId;

			std::cout << "请输入新的职工姓名:	";
			std::cin >> newName;

			std::cout << "请选择该职员新的岗位编号" << std::endl;
			std::cout << "1.员工" << std::endl;
			std::cout << "2.经理" << std::endl;
			std::cout << "3.老板" << std::endl;
			std::cin >> newDeptId;

			Worker* worker = NULL;
			switch (newDeptId)
			{
			case 1://员工
				worker = new Employee(newId, newName, 1);
				break;
			case 2://经理
				worker = new Manager(newId, newName, 2);
				break;
			case 3://老板
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}

			this->m_workerArr[index] = worker;

			std::cout << "修改成功！" << std::endl;

			this->saveFile();
		}
	}
	system("pause");
}
void WorkerManager::findWorker()
{
	std::cout << "请选择查找方法：		" << std::endl;
	std::cout << "1.按ID查找" << std::endl;
	std::cout << "2.按姓名查找" << std::endl;

	int select = 0;
	std::cin >> select;
	//按ID查找
	if (select == 1)
	{
		int aimId = 0;
		std::cout << "请输入要查找的职员ID：	";
		std::cin >> aimId;
		int temp = isExist(aimId);
		if (temp == -1)
		{
			std::cout << "该职工不存在！" << std::endl;
		}
		else
		{
			std::cout << "已查到该职工信息如下：	" << std::endl;
			this->m_workerArr[temp]->showInfo();
		}
	}
	//按姓名查找
	if (select == 2)
	{
		std::string aimName = "";
		std::cout << "请输入要查找的职员姓名：	";
		std::cin >> aimName;
		int flag = 0;
		for (int i = 0; i < this->m_workerNum; i++)
		{
			if (this->m_workerArr[i]->m_name == aimName)
			{
				std::cout << "已查到该职工信息如下：	" << std::endl;
				this->m_workerArr[i]->showInfo();
				flag = 1;
				break;
			}
			if (flag)
			{
				std::cout << "该职工不存在！" << std::endl;
			}
		}
	}
	system("pause");

}
void WorkerManager::sortWorker()
{
	std::cout << "请选择排序方式：	" << std::endl;
	std::cout << "1.按ID升序排列" << std::endl;
	std::cout << "2.按ID降序排列" << std::endl;
	int select = 0;
	std::cin >> select;
	Worker* tempt = m_workerArr[0];
	if(select == 2)//降序
	{
		for (int i = 0; i < this->m_workerNum - 1; i++)
		{
			for (int j = i + 1; j < this->m_workerNum; j++)
			{
				if (this->m_workerArr[i]->m_id < this->m_workerArr[j]->m_id)
				{
					tempt = m_workerArr[i];
					m_workerArr[i] = m_workerArr[j];
					m_workerArr[j] = tempt;
				}
			}
		}
	}
	else if (select == 1)
	{
		for (int i = 0; i < this->m_workerNum - 1; i++)
		{
			for (int j = i + 1; j < this->m_workerNum; j++)
			{
				if (this->m_workerArr[i]->m_id > this->m_workerArr[j]->m_id)
				{
					tempt = m_workerArr[i];
					m_workerArr[i] = m_workerArr[j];
					m_workerArr[j] = tempt;
				}
			}
		}
	}

	this->saveFile();

	std::cout << "排序成功！排序结果如下：	" << std::endl;
	this->showWorker();
	system("pause");
}

void WorkerManager::clearFile()
{
	std::cout << "清空操作会使数据全部被删除，确定要执行清空吗？" << std::endl;
	std::cout << "1.是" << std::endl;
	std::cout << "2.否" << std::endl;
	int select = 0;
	std::cin >> select;
	if (select == 1)
	{
		//打开模式ios：：trunc如果存在 删除文件并重建创建
		std::ofstream ofs(FILENAME, std::ios::trunc);
		ofs.close();

		if (this->m_workerArr != NULL)
		{
			for (int i = 0; i < this->m_workerNum; i++)
			{
				if (this->m_workerArr[i] != NULL)
				{
					delete this->m_workerArr[i];
				}
			}
			this->m_workerNum = 0;
			delete[] this->m_workerArr;
			this->m_workerArr = NULL;
			this->m_fileIsEmpty = true;
		}
		std::cout << "清空成功！" << std::endl;

	}
	system("pause");
}