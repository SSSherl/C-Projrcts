#include<iostream>
#include"boss.h"

//���캯�������г�ʼ��
Boss::Boss(int id, std::string name, int deptId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = deptId;
}

//��ʾ������Ϣ
void Boss::showInfo()
{
	std::cout << "ְ�����:	" << this->m_id << std::endl;
	std::cout << "ְ��������	" << this->m_name << std::endl;
	std::cout << "ְ�����ţ�	" << this->getDept() << std::endl;
	std::cout << "��λְ��	����˾��������" << std::endl;
}
//��ȡ��λ����
std::string Boss::getDept()
{
	return std::string("�ϰ�");
}