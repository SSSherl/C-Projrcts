#include<iostream>
#include"employee.h"

//���캯������ʼ��Ա����Ϣ
Employee::Employee(int id, std::string name, int deptId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = deptId;
}
//��д��ʾ��Ϣ����
void Employee::showInfo()
{
	std::cout << "ְ�����:	" << this->m_id << std::endl;
	std::cout << "ְ��������	" << this->m_name << std::endl;
	std::cout << "ְ�����ţ�	" << this->getDept() << std::endl;
	std::cout << "��λְ��	��ɾ�����������" << std::endl;

}
//��д��ȡ���ź���
std::string Employee::getDept()
{
	return std::string("Ա��");
}