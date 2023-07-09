#pragma once
#include<iostream>
#include "worker.h"

//普通员工类
class Employee :public Worker
{
public:
	//构造函数，初始化员工信息
	Employee(int id, std::string name, int deptId);
	//重写显示信息函数
	virtual void showInfo();
	//重写获取部门函数
	virtual std::string getDept();
};

