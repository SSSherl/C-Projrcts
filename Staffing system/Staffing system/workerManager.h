#pragma once
#include<iostream>
#include"worker.h"
//管理类负责内容
//与用户的沟通菜单界面
//对职工的增删查改操作
//与文件的读写交互
class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	//成员函数展示菜单
	void showMenu();
	//退出功能
	void exitFunction();
	//增加功能
	void addFunction();
	//保存文件
	void saveFile();
	//文件不为空时，进行人数的读取
	int getNum();
	//文件不为空时，进行文件数据的读取
	void loadWorker();
	//显示员工信息
	void showWorker();
	//职工是否存在，不存在返回-1，存在则返回职工在数组中的位置
	int isExist(int id);
	//删除员工信息
	void deleteWorker();
	//修改职工信息
	void modifyWorker();
	//查找员工
	void findWorker();
	//为职工信息排序
	void sortWorker();
	//清空文件
	void clearFile();
	//析构函数
	~WorkerManager();
	//成员属性，人数个数
	int m_workerNum;
	//成员数组的指针
	Worker** m_workerArr;
	//文件是否为空
	bool m_fileIsEmpty;

};
