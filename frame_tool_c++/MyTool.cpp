#include "MyTool.h"

#include <iostream>

/*
 #---------------------------------------#
 *    程序：工具包                       *
 *    版本：1.0                          *
 *    作者：NoIf                           *
 *    日期：2017-02-08                   *
 *    语言：C++                          *
 *    操作：光标定位，表格制作           *
 *    功能：日常使用各类工具             *
 #---------------------------------------#
 */

using namespace std;

namespace MyTool {

/**************************************************************/
	       /***************光标类***************/

	Cursor::Cursor()
	{
	}

	Cursor::~Cursor()
	{
	}

	//光标定位函数 
	void Cursor::Pos(int x, int y)
	{
		//获取目的坐标
		xy = { (short)y,(short)x };
		
		//获取句柄
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		//修改光标位置到目的坐标
		SetConsoleCursorPosition(hout, xy);
	}

	//光标定位函数 
	//-- x自增
	void Cursor::Posx(int & x, int y)
	{
		//获取目的坐标
		xy = { (short)y,(short)x };

		//获取句柄
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		//修改光标位置到目的坐标
		SetConsoleCursorPosition(hout, xy);

		//x自增
		x++;
	}


	//光标定位函数 
	//-- y自增
	void Cursor::Posy(int x, int & y)
	{
		//获取目的坐标
		xy = { (short)y,(short)x };

		//获取句柄
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		//修改光标位置到目的坐标
		SetConsoleCursorPosition(hout, xy);

		//y自增
		y++;
	}

/**************************************************************/


/**************************************************************/
           /***************制表类***************/

   /*
	*  xy为起始坐标（行列）        *
	*  Length 长度   Wide 宽度     *
	*  A横向边框符   B竖向边框符   *
	*  C分割线符号                 *
	*/

	Table::Table()
	{
	}

	Table::~Table()
	{
	}

	//边框构建函数  xy为起始坐标  AB为边框符号
	void Table::Create_border(int x, int y, int Length, int Wide, char A, char B)
	{
		for (int i = 0;i < Wide;i++) {
			cursor.Posx(x, y);
			if (i == 0 || i == Wide - 1)
				for (int k = 0;k < Length;k++)
					cout << A;
			else {
				for (int j = 0;j < Length;j++)
					if (j == 0 || j == Length - 1)
						cout << B;
					else
						cout << " ";
		
			}
		}
	}

	//横线构建函数  xy为起始坐标  C为边框符号
	void Table::Create_line(int x, int y, int Length, char C)
	{
		cursor.Pos(x, y);
		for (int i = 0;i < Length;i++)
			cout << C;
	}

	//横线构建函数（复数）  xy为起始坐标  C为边框符号  times为重复次数  h为每次重复相距行数
	void Table::Create_lines(int x, int y, int Length, char C, int times, int h)
	{
		for (int i = 0;i < times;i++) {
			cursor.Pos(x, y);
			for (int j = 0;j < Length;j++)
				cout << C;
			x += h;
		}
	}

	//竖线构建函数  xy为起始坐标  C为边框符号
	void Table::Create_lline(int x, int y, int Length, char C)
	{
		for (int i = 0;i < Length;i++) {
			cursor.Posx(x, y);
			cout << C;
		}
	}

	//竖线构建函数（复数）  xy为起始坐标  C为边框符号  times为重复次数  h为每次重复相距行数
	void Table::Create_llines(int x, int y, int Length, char C, int times, int h)
	{
		int n = x;
		for (int i = 0;i < times;i++) {
			for (int j = 0;j < Length;j++) {
				cursor.Posx(x, y);
				cout << C;
			}
			x = n;
			y += h;
		}
	}

/**************************************************************/
}