#pragma once
#include<iostream>
#include"worker.h"
//�����ϰ���
class Boss:public Worker
{
public:
	//���캯��
	Boss(int id, std::string name, int deptId);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual std::string getDept();
};
