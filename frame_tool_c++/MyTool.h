#pragma once
#ifndef MYTOOLBASE_H_INCLUDED
#define MYTOOLBASE_H_INCLUDED

#include <Windows.h>

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

namespace MyTool
{
/**************************************************************/
              /***************光标类***************/

	class Cursor
	{
	public:
		Cursor();
		~Cursor();
		void Pos(int x, int y);    //光标定位函数
		void Posx(int &x, int y);  //光标定位函数 -- x自增
		void Posy(int x, int &y);  //光标定位函数 -- y自增

	private:
		HANDLE hout;
		COORD xy;
	};
/**************************************************************/


/**************************************************************/
              /***************制表类***************/
   /*
	*  xy为起始坐标（行列）        *
	*  Length 长度   Wide 宽度     *
	*  A横向边框符   B竖向边框符   *
	*  C分割线符号                 *
	*/

	class Table
	{
	public:
		Table();
		~Table();

		//边框构建函数  xy为起始坐标  AB为边框符号
		void Create_border(int x, int y, int Length, int Wide, char A, char B);

		//横线构建函数  xy为起始坐标  C为边框符号
		void Create_line(int x, int y, int Length, char C);

		//横线构建函数（复数）  xy为起始坐标  C为边框符号  times为重复次数  h为每次重复相距行数
		void Create_lines(int x, int y, int Length, char C, int times, int h);

		//竖线构建函数  xy为起始坐标  C为边框符号
		void Create_lline(int x, int y, int Length, char C);

		//竖线构建函数（复数）  xy为起始坐标  C为边框符号  times为重复次数  h为每次重复相距行数
		void Create_llines(int x, int y, int Length, char C, int times, int h);

	private:
		Cursor cursor;

	};


}









#endif
