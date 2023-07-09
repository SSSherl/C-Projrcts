#include<iostream>
#include"boss.h"

//构造函数，进行初始化
Boss::Boss(int id, std::string name, int deptId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = deptId;
}

//显示个人信息
void Boss::showInfo()
{
	std::cout << "职工编号:	" << this->m_id << std::endl;
	std::cout << "职工姓名：	" << this->m_name << std::endl;
	std::cout << "职工部门：	" << this->getDept() << std::endl;
	std::cout << "岗位职责：	管理公司所有事务" << std::endl;
}
//获取岗位名称
std::string Boss::getDept()
{
	return std::string("老板");
}