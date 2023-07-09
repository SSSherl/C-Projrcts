#pragma once
#include<iostream>
#include"worker.h"
//创建经理类
class Manager :public Worker
{
public:
	//构造函数
	Manager(int id, std::string name, int deptId);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual std::string getDept();
};
