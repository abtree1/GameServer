#pragma once
class CPlayer;

//���� ΪPlayer������Ļ���
/*
	��ʵ�ʿ��������� �����ճ�Player���������ά��
	�˴�����Player����� Ŀ�ľ��ǽ�Player����Զ�����
	���ݰ�װΪ�������Player�� �Ա���Player��������
*/
class IPlayerData {
public:
	IPlayerData(CPlayer* player) :mpPlayer(player) {}
	~IPlayerData() = default;
protected:
	CPlayer* mpPlayer; //data ���������Player(ÿ�����ʵ��������ĳ��Player)
};