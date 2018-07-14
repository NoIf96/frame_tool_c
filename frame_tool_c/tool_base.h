#pragma once
#ifndef TOOLBASE_H_INCLUDED
#define TOOLBASE_H_INCLUDED

/**************************************************************/
/*  ��λ����  */
//x������y����

//��λ����
void Pos(int x, int y);

//��λ��������x����
void Posx(int &x, int y);

//��λ��������y����
void Posy(int x, int &y);
/**************************************************************/

/**************************************************************/
/*�����������*/
/*
*  xyΪ��ʼ���꣨���У�        *
*  Length ����   Wide ���     *
*  A����߿��   B����߿��   *
*  C�ָ��߷���                 *
*/


//�߿򹹽�����  xyΪ��ʼ����  ABΪ�߿����
void Table_border(int x, int y, int Length, int Wide, char A, char B);

//�ָ��߹�������  xyΪ��ʼ����  CΪ�߿����
void Table_line(int x, int y, int Length, char C);

//�ָ��߹���������������  xyΪ��ʼ����  CΪ�߿����  timesΪ�ظ�����  hΪÿ���ظ��������
void Table_lines(int x, int y, int Length, char C, int times, int h);

//���׹�������  xyΪ��ʼ����  CΪ�߿����  Lengthλ10����ֵ�ǿ���ʹ��
void Table_tail(int x, int y, int Length, char C);
/**************************************************************/

#endif
