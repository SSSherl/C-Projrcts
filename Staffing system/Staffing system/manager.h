#pragma once
#include<iostream>
#include"worker.h"
//����������
class Manager :public Worker
{
public:
	//���캯��
	Manager(int id, std::string name, int deptId);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual std::string getDept();
};
