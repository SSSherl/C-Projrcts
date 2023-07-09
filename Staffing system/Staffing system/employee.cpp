#include<iostream>
#include"employee.h"

//构造函数，初始化员工信息
Employee::Employee(int id, std::string name, int deptId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = deptId;
}
//重写显示信息函数
void Employee::showInfo()
{
	std::cout << "职工编号:	" << this->m_id << std::endl;
	std::cout << "职工姓名：	" << this->m_name << std::endl;
	std::cout << "职工部门：	" << this->getDept() << std::endl;
	std::cout << "岗位职责：	完成经理交给的任务" << std::endl;

}
//重写获取部门函数
std::string Employee::getDept()
{
	return std::string("员工");
}