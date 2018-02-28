#pragma once

//next data �¼��������б�
enum ENextDataKeyType {
	ENDKT_LoginSession = 0,
	ENDKT_LoginAccount = 1
};
/************************************************************************
	Next Data ��Ҫ���ڽ��ʱ������ ��ĳЩ��Ҫ�ȴ�ǰ��������ɵ��߼�
************************************************************************/
class CNextDataMgr : public CSingleton<CNextDataMgr>
{
SINGLETION_FRIEND_CLASS_REGISTER(CNextDataMgr);
private:
	CNextDataMgr() = default;
	~CNextDataMgr();
public:
	//ע��next data �¼� �������ڱ������ݵĶ���
	CNextData* createTemp(CSPNextData& data);
	//����ע���next data���¼�
	template<typename T>
	void handleTemp(CSPNextData& data, T *handle, TypeFunc<T> func) {
		string key = data.SerializeAsString();
		auto it = mTemps.find(key);
		if (it == mTemps.end()) {
			return;
		}
		if (it->second) {
			it->second->handle<T>(handle, func);
			delete it->second;
		}
		mTemps.erase(it);
	}
	//��ȡע���next data�¼�
	CNextData* findTemp(CSPNextData& data);
	//�쳣���������
	void dirtyHandleTemp(CSPNextData& data);  //������ʵ��ɾ������
private:
	//��������ע���next data�¼�
	map<string, CNextData*> mTemps;
};