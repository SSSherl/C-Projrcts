#include<iostream>
#include"manager.h"

//���캯�������г�ʼ��
Manager::Manager(int id, std::string name, int deptId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = deptId;
}

//��ʾ������Ϣ
void Manager::showInfo()
{
	std::cout << "ְ�����:	" << this->m_id << std::endl;
	std::cout << "ְ��������	" << this->m_name << std::endl;
	std::cout << "ְ�����ţ�	" << this->getDept() << std::endl;
	std::cout << "��λְ��	����ϰ彻�������� �·������Ա��" << std::endl;
}
//��ȡ��λ����
std::string Manager::getDept()
{
	return std::string("����");
}