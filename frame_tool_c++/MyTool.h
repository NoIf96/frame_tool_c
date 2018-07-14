#pragma once
#ifndef MYTOOLBASE_H_INCLUDED
#define MYTOOLBASE_H_INCLUDED

#include <Windows.h>

/*
 #---------------------------------------#
 *    ���򣺹��߰�                       *
 *    �汾��1.0                          *
 *    ���ߣ�NoIf                           *
 *    ���ڣ�2017-02-08                   *
 *    ���ԣ�C++                          *
 *    ��������궨λ���������           *
 *    ���ܣ��ճ�ʹ�ø��๤��             *
 #---------------------------------------#
 */

namespace MyTool
{
/**************************************************************/
              /***************�����***************/

	class Cursor
	{
	public:
		Cursor();
		~Cursor();
		void Pos(int x, int y);    //��궨λ����
		void Posx(int &x, int y);  //��궨λ���� -- x����
		void Posy(int x, int &y);  //��궨λ���� -- y����

	private:
		HANDLE hout;
		COORD xy;
	};
/**************************************************************/


/**************************************************************/
              /***************�Ʊ���***************/
   /*
	*  xyΪ��ʼ���꣨���У�        *
	*  Length ����   Wide ���     *
	*  A����߿��   B����߿��   *
	*  C�ָ��߷���                 *
	*/

	class Table
	{
	public:
		Table();
		~Table();

		//�߿򹹽�����  xyΪ��ʼ����  ABΪ�߿����
		void Create_border(int x, int y, int Length, int Wide, char A, char B);

		//���߹�������  xyΪ��ʼ����  CΪ�߿����
		void Create_line(int x, int y, int Length, char C);

		//���߹���������������  xyΪ��ʼ����  CΪ�߿����  timesΪ�ظ�����  hΪÿ���ظ��������
		void Create_lines(int x, int y, int Length, char C, int times, int h);

		//���߹�������  xyΪ��ʼ����  CΪ�߿����
		void Create_lline(int x, int y, int Length, char C);

		//���߹���������������  xyΪ��ʼ����  CΪ�߿����  timesΪ�ظ�����  hΪÿ���ظ��������
		void Create_llines(int x, int y, int Length, char C, int times, int h);

	private:
		Cursor cursor;

	};


}









#endif
