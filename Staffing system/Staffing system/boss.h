#pragma once
#include<iostream>
#include"worker.h"
//创建老板类
class Boss:public Worker
{
public:
	//构造函数
	Boss(int id, std::string name, int deptId);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual std::string getDept();
};
