#include "stdafx.h"

//#############################################
CSaveTimerTask::CSaveTimerTask() {
	//��ȡ�洢��sqls
	CTimerTaskMgr::GetInstance()->SaveToDB(mSqls);
}

CSaveTimerTask::Run() {

}

CSaveTimerTask::Finish() {

}
//#############################################

CLoadTimerTask::CLoadTimerTask() {
	//��ѯ���м�¼
	mSqls.push_back("SELECT * FROM `g_timertask`");
}

CLoadTimerTask::Run() {
	mpResult = mpStmt->executeQuery(mSqls[0]);
	while (mpResult && mpResult->next()) {
		//����ÿһ��timertask
	}
}

CLoadTimerTask::Finish() {

}
//#############################################