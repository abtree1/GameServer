#include "stdafx.h"

//#############################################
CSaveTimerTask::CSaveTimerTask() {
	//获取存储的sqls
	CTimerTaskMgr::GetInstance()->SaveToDB(mSqls);
}

CSaveTimerTask::Run() {

}

CSaveTimerTask::Finish() {

}
//#############################################

CLoadTimerTask::CLoadTimerTask() {
	//查询所有记录
	mSqls.push_back("SELECT * FROM `g_timertask`");
}

CLoadTimerTask::Run() {
	mpResult = mpStmt->executeQuery(mSqls[0]);
	while (mpResult && mpResult->next()) {
		//解析每一个timertask
	}
}

CLoadTimerTask::Finish() {

}
//#############################################