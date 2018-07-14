#include "MyTool.h"

#include <iostream>

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

using namespace std;

namespace MyTool {

/**************************************************************/
	       /***************�����***************/

	Cursor::Cursor()
	{
	}

	Cursor::~Cursor()
	{
	}

	//��궨λ���� 
	void Cursor::Pos(int x, int y)
	{
		//��ȡĿ������
		xy = { (short)y,(short)x };
		
		//��ȡ���
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		//�޸Ĺ��λ�õ�Ŀ������
		SetConsoleCursorPosition(hout, xy);
	}

	//��궨λ���� 
	//-- x����
	void Cursor::Posx(int & x, int y)
	{
		//��ȡĿ������
		xy = { (short)y,(short)x };

		//��ȡ���
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		//�޸Ĺ��λ�õ�Ŀ������
		SetConsoleCursorPosition(hout, xy);

		//x����
		x++;
	}


	//��궨λ���� 
	//-- y����
	void Cursor::Posy(int x, int & y)
	{
		//��ȡĿ������
		xy = { (short)y,(short)x };

		//��ȡ���
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		//�޸Ĺ��λ�õ�Ŀ������
		SetConsoleCursorPosition(hout, xy);

		//y����
		y++;
	}

/**************************************************************/


/**************************************************************/
           /***************�Ʊ���***************/

   /*
	*  xyΪ��ʼ���꣨���У�        *
	*  Length ����   Wide ���     *
	*  A����߿��   B����߿��   *
	*  C�ָ��߷���                 *
	*/

	Table::Table()
	{
	}

	Table::~Table()
	{
	}

	//�߿򹹽�����  xyΪ��ʼ����  ABΪ�߿����
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

	//���߹�������  xyΪ��ʼ����  CΪ�߿����
	void Table::Create_line(int x, int y, int Length, char C)
	{
		cursor.Pos(x, y);
		for (int i = 0;i < Length;i++)
			cout << C;
	}

	//���߹���������������  xyΪ��ʼ����  CΪ�߿����  timesΪ�ظ�����  hΪÿ���ظ��������
	void Table::Create_lines(int x, int y, int Length, char C, int times, int h)
	{
		for (int i = 0;i < times;i++) {
			cursor.Pos(x, y);
			for (int j = 0;j < Length;j++)
				cout << C;
			x += h;
		}
	}

	//���߹�������  xyΪ��ʼ����  CΪ�߿����
	void Table::Create_lline(int x, int y, int Length, char C)
	{
		for (int i = 0;i < Length;i++) {
			cursor.Posx(x, y);
			cout << C;
		}
	}

	//���߹���������������  xyΪ��ʼ����  CΪ�߿����  timesΪ�ظ�����  hΪÿ���ظ��������
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