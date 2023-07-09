#pragma once
#include<iostream>
#include<string>

class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual std::string getDept() = 0;

	int m_id;//职工编号
	std::string m_name;//职工姓名
	int m_deptId;//职工部门编号
};