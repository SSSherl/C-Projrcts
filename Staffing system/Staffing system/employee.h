#pragma once
#include<iostream>
#include "worker.h"

//��ͨԱ����
class Employee :public Worker
{
public:
	//���캯������ʼ��Ա����Ϣ
	Employee(int id, std::string name, int deptId);
	//��д��ʾ��Ϣ����
	virtual void showInfo();
	//��д��ȡ���ź���
	virtual std::string getDept();
};

