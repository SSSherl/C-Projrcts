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

	//�ļ�������ʱ������һϵ�г�ʼ��
	if (!ifs.is_open())
	{
		//std::cout << "�ļ������ڣ�" << std::endl;//����
		//��ʼ������
		this->m_workerNum = 0;
		//��ʼ����Ա�����ָ��
		this->m_workerArr = NULL;
		//��ʼ���ļ��Ƿ񴴽�
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	//�ļ�Ϊ��ʱ������һϵ�г�ʼ��
	if (ifs.eof())
	{
		//std::cout << "�ļ������ڣ�" << std::endl;//����
		//��ʼ������
		this->m_workerNum = 0;
		//��ʼ����Ա�����ָ��
		this->m_workerArr = NULL;
		//��ʼ���ļ��Ƿ񴴽�
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��ʱ����ȡ����
	this->m_workerNum = getNum();
	//�ļ���Ϊ��ʱ��������������ԭ������
	//�ȿ��ٿռ�
	this->m_workerArr = new Worker * [this->m_workerNum];
	//�ڵ������뺯��
	loadWorker();

}
WorkerManager::~WorkerManager()
{
	//�ͷŶ�������
	if (this->m_workerArr != NULL)
	{
		delete[] m_workerArr;
	}
}

void WorkerManager::showMenu()
{
	std::cout << "*******************************************************" << std::endl;
	std::cout << "*******************��ӭ����ְ������ϵͳ****************" << std::endl;
	std::cout << "*********************0.�˳�����ϵͳ********************" << std::endl;
	std::cout << "*********************1.����ְ����Ϣ********************" << std::endl;
	std::cout << "*********************2.��ʾְ����Ϣ********************" << std::endl;
	std::cout << "*********************3.ɾ����ְְ��********************" << std::endl;
	std::cout << "*********************4.�޸�ְ����Ϣ********************" << std::endl;
	std::cout << "*********************5.����ְ����Ϣ********************" << std::endl;
	std::cout << "*********************6.���ձ������********************" << std::endl;
	std::cout << "*********************7.��������ĵ�********************" << std::endl;
	std::cout << "*******************************************************" << std::endl;
	std::cout << std::endl;
}
void WorkerManager::exitFunction()
{
	std::cout << "��ӭ�´�ʹ�ã�" << std::endl;
	system("pause");
	exit(0);//�˳�����
}

void WorkerManager::addFunction()
{
	int addNum = 0;
	std::cout << "����������ְ��������:	" << std::endl;
	std::cin >> addNum;
	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_workerNum + addNum;
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize+3];

		//��ԭ�ռ����ݷ����¿ռ�
		if (this->m_workerArr != NULL)
		{
			for (int i = 0; i < this->m_workerNum; i++)
			{
				newSpace[i] = this->m_workerArr[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			std::string name;
			int deptId;

			std::cout << "�������" << i + 1 << "λְԱ���" << std::endl;
			std::cin >> id;

			std::cout << "�������" << i + 1 << "λְԱ����" << std::endl;
			std::cin >> name;

			std::cout << "��ѡ���ְԱ�ĸ�λ���" << std::endl;
			std::cout << "1.Ա��" << std::endl;
			std::cout << "2.����" << std::endl;
			std::cout << "3.�ϰ�" << std::endl;
			std::cin >> deptId;

			Worker* worker = NULL;
			switch (deptId)
			{
			case 1://Ա��
				worker = new Employee(id, name, 1);
				break;
			case 2://����
				worker = new Manager(id, name, 2);
				break;
			case 3://�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_workerNum + i] = worker;//����������������1���ĳɽ����ã�2�����ټ�3��4
		}
		//�ͷ�ԭ�пռ�
		delete [] this->m_workerArr;

		//�����¿ռ�ָ��
		this->m_workerArr = newSpace;

		//���¸���
		this->m_workerNum = newSize;

		//��ʾ��Ϣ
		std::cout << "�ɹ����" << addNum << "λ��ְԱ��" << std::endl;

		//�����ļ�
		this->saveFile();

		//�����ļ��Ƿ�Ϊ��
		this->m_fileIsEmpty = false;
	}
	else
	{
		std::cout << "��������" << std::endl;
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
		//��¼����
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
		if (id == 1)//��ͨԱ��
		{
			worker = new Employee(id, name, deptId);
		}
		else if (id == 2)//����
		{
			worker = new Manager(id, name, deptId);
		}
		else//�ϰ�
		{
			worker = new Boss(id, name, deptId);
		}

		//��������
		this->m_workerArr[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManager::showWorker()
{
	if (this->m_fileIsEmpty)
	{
		std::cout << "�ļ������ڻ�Ϊ��" << std::endl;
	}
	else
	{
		for (int i = 0; i < this->m_workerNum; i++)
		{
			//���ö�̬����showInfo����
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
		std::cout << "�ļ������ڻ�Ϊ��" << std::endl;
	}
	else
	{
		int id = 0;
		std::cout << "������Ҫɾ��ְ����ID��	";
		std::cin >> id;
		int index = isExist(id);
		if (index == -1)
		{
			std::cout << "ְ�������ڣ�" << std::endl;
		}
		else
		{
			for (int i = index; i < this->m_workerNum-1; i++)
			{
				this->m_workerArr[i] = this->m_workerArr[i + 1];
			}
			//����ɾ��֮���ְ������
			this->m_workerNum--;
			//�����ļ�����
			this->saveFile();

			std::cout << "ɾ���ɹ���" << std::endl;
		}
	}
	system("pause");

	
}
void WorkerManager::modifyWorker()
{
	if (this->m_fileIsEmpty)
	{
		std::cout << "�ļ������ڻ�Ϊ��" << std::endl;
	}
	else
	{
		int id = 0;
		std::cout << "������Ҫ�޸�ְ����ID��	";
		std::cin >> id;
		int index = isExist(id);
		if (index == -1)
		{
			std::cout << "ְ�������ڣ�" << std::endl;
		}
		else
		{
			//ɾ��ԭ��ְ������Ϣ
			delete this->m_workerArr[index];

			int newId = 0;
			std::string newName = "";
			int newDeptId = 0;

			std::cout << "�������µ�ְ����:	";
			std::cin >> newId;

			std::cout << "�������µ�ְ������:	";
			std::cin >> newName;

			std::cout << "��ѡ���ְԱ�µĸ�λ���" << std::endl;
			std::cout << "1.Ա��" << std::endl;
			std::cout << "2.����" << std::endl;
			std::cout << "3.�ϰ�" << std::endl;
			std::cin >> newDeptId;

			Worker* worker = NULL;
			switch (newDeptId)
			{
			case 1://Ա��
				worker = new Employee(newId, newName, 1);
				break;
			case 2://����
				worker = new Manager(newId, newName, 2);
				break;
			case 3://�ϰ�
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}

			this->m_workerArr[index] = worker;

			std::cout << "�޸ĳɹ���" << std::endl;

			this->saveFile();
		}
	}
	system("pause");
}
void WorkerManager::findWorker()
{
	std::cout << "��ѡ����ҷ�����		" << std::endl;
	std::cout << "1.��ID����" << std::endl;
	std::cout << "2.����������" << std::endl;

	int select = 0;
	std::cin >> select;
	//��ID����
	if (select == 1)
	{
		int aimId = 0;
		std::cout << "������Ҫ���ҵ�ְԱID��	";
		std::cin >> aimId;
		int temp = isExist(aimId);
		if (temp == -1)
		{
			std::cout << "��ְ�������ڣ�" << std::endl;
		}
		else
		{
			std::cout << "�Ѳ鵽��ְ����Ϣ���£�	" << std::endl;
			this->m_workerArr[temp]->showInfo();
		}
	}
	//����������
	if (select == 2)
	{
		std::string aimName = "";
		std::cout << "������Ҫ���ҵ�ְԱ������	";
		std::cin >> aimName;
		int flag = 0;
		for (int i = 0; i < this->m_workerNum; i++)
		{
			if (this->m_workerArr[i]->m_name == aimName)
			{
				std::cout << "�Ѳ鵽��ְ����Ϣ���£�	" << std::endl;
				this->m_workerArr[i]->showInfo();
				flag = 1;
				break;
			}
			if (flag)
			{
				std::cout << "��ְ�������ڣ�" << std::endl;
			}
		}
	}
	system("pause");

}
void WorkerManager::sortWorker()
{
	std::cout << "��ѡ������ʽ��	" << std::endl;
	std::cout << "1.��ID��������" << std::endl;
	std::cout << "2.��ID��������" << std::endl;
	int select = 0;
	std::cin >> select;
	Worker* tempt = m_workerArr[0];
	if(select == 2)//����
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

	std::cout << "����ɹ������������£�	" << std::endl;
	this->showWorker();
	system("pause");
}

void WorkerManager::clearFile()
{
	std::cout << "��ղ�����ʹ����ȫ����ɾ����ȷ��Ҫִ�������" << std::endl;
	std::cout << "1.��" << std::endl;
	std::cout << "2.��" << std::endl;
	int select = 0;
	std::cin >> select;
	if (select == 1)
	{
		//��ģʽios����trunc������� ɾ���ļ����ؽ�����
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
		std::cout << "��ճɹ���" << std::endl;

	}
	system("pause");
}