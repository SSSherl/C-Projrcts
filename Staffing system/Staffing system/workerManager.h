#pragma once
#include<iostream>
#include"worker.h"
//�����ฺ������
//���û��Ĺ�ͨ�˵�����
//��ְ������ɾ��Ĳ���
//���ļ��Ķ�д����
class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	//��Ա����չʾ�˵�
	void showMenu();
	//�˳�����
	void exitFunction();
	//���ӹ���
	void addFunction();
	//�����ļ�
	void saveFile();
	//�ļ���Ϊ��ʱ�����������Ķ�ȡ
	int getNum();
	//�ļ���Ϊ��ʱ�������ļ����ݵĶ�ȡ
	void loadWorker();
	//��ʾԱ����Ϣ
	void showWorker();
	//ְ���Ƿ���ڣ������ڷ���-1�������򷵻�ְ���������е�λ��
	int isExist(int id);
	//ɾ��Ա����Ϣ
	void deleteWorker();
	//�޸�ְ����Ϣ
	void modifyWorker();
	//����Ա��
	void findWorker();
	//Ϊְ����Ϣ����
	void sortWorker();
	//����ļ�
	void clearFile();
	//��������
	~WorkerManager();
	//��Ա���ԣ���������
	int m_workerNum;
	//��Ա�����ָ��
	Worker** m_workerArr;
	//�ļ��Ƿ�Ϊ��
	bool m_fileIsEmpty;

};
