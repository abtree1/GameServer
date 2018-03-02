#include "stdafx.h"

bool operator >(const STimerTaskData &lcx, const STimerTaskData &rcx) {
	if (lcx.time < rcx.time)
		return true;
	return false;
}

bool operator >=(const STimerTaskData &lcx, const STimerTaskData &rcx) {
	if (lcx.time <= rcx.time)
		return true;
	return false;
}

bool operator <(const STimerTaskData &lcx, const STimerTaskData &rcx) {
	if (lcx >= rcx)
		return false;
	return true;
}

bool operator <=(const STimerTaskData &lcx, const STimerTaskData &rcx) {
	if (lcx > rcx)
		return false;
	return true;
}

STimerTaskData &STimerTaskData::operator =(const STimerTaskData& lcx) {
	this->id = lcx.id;
	this->time = lcx.time;
	this->type = lcx.type;
	this->params.Clear();
	this->params.CopyFrom(lcx.params);
	return *this;
}

UINT STimerTaskData::GetId() {
	return this->id;
}

void CTimerTaskEvent::DelEvent(int id) {
	int from = mRankListHandle.getRank(id);
	if (from < 0) {//��ʾû�м�¼��task id
		return; //ֱ�ӷ��سɹ�
	}
	//����Ҫɾ����Timer Task �ƶ�����ĩβ
	int to = mRankListHandle.mRankList.size() - 1;
	mRankListHandle.moveRankList(from, to);
	//ɾ������
	DelTail();
}

void CTimerTaskEvent::DelTail() {
	if (mRankListHandle.mRankList.empty())
		return;
	auto id = GetBack()->GetId();
	mRankListHandle.mRankList.pop_back();
	mRankListHandle.mRankListKV.erase(id);
}

STimerTaskData* CTimerTaskEvent::GetBack() {
	if (mRankListHandle.mRankList.empty())
		return nullptr;
	return &mRankListHandle.mRankList[mRankListHandle.mRankList.size() - 1];
}