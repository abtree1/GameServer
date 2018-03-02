#include "stdafx.h"

bool operator >(const IRankListImpl &lcx, const IRankListImpl &rcx) {
	if (lcx.mScore > rcx.mScore)
		return true;
	return false;
}

bool operator >=(const IRankListImpl &lcx, const IRankListImpl &rcx) {
	if (lcx.mScore >= rcx.mScore)
		return true;
	return false;
}

bool operator <(const IRankListImpl &lcx, const IRankListImpl &rcx) {
	if (lcx >= rcx)
		return false;
	return true;
}

bool operator <=(const IRankListImpl &lcx, const IRankListImpl &rcx) {
	if (lcx > rcx)
		return false;
	return true;
}

//¿½±´Ê±²»¿½±´ÅÅÃû
IRankListImpl &IRankListImpl::operator=(const IRankListImpl &lcx) {
	this->mScore = lcx.mScore;
	this->mId = lcx.mId;
	return *this;
}

UINT IRankListImpl::GetId() {
	return this->mId;
}

SRankListData &SRankListData::operator=(const SRankListData &lcx) {
	IRankListImpl::operator =(lcx);
	this->tstr = lcx.tstr;
	this->tint = lcx.tint;
	return *this;
}