#pragma once
#include<iostream>
#include<string>

class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual std::string getDept() = 0;

	int m_id;//ְ�����
	std::string m_name;//ְ������
	int m_deptId;//ְ�����ű��
};