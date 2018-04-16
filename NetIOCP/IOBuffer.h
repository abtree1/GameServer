#pragma once

#include <WinSock2.h>

namespace NetIOCP {
	class Socket;
	/*
	iocp��io�������ݼ�¼
	*/
	class IOBuffer : public WSAOVERLAPPED {
	public:
		IOBuffer(unsigned int size, Socket& skt);
	private:
		IOBuffer(const IOBuffer&) = delete;
		IOBuffer& operator=(const IOBuffer&) = delete;
	public:
		//���(ֻ��ʹ������0)
		void Clear() { mUsed = 0; }
		//��ȡsocket����
		Socket& GetSocket() { return mSocket; }
		//��ȡ���ݻ�
		unsigned long GetSize() const { return mBufferSize; }
		//��ȡʹ����
		unsigned long GetUsed() const { return mUsed; }
		//��ȡʣ���ݻ�
		unsigned long GetResidualCapacity() const {	return mBufferSize - mUsed; }
		//���õ�ǰ��ȡָ��
		void Seek(unsigned long offset) {
			if (mBufferSize <= offset) {
				throw std::exception("Out of range");
			}
			mSeek = offset;
		}
		unsigned long Seek() const { return mSeek; }
		//����ָ��
		template<typename T>
		void SetAttachment(T t) {
			static_assert(sizeof(T) == sizeof(unsigned long),
				"The size of T must equal or less than size of unsigned long");
			mAttachment = reinterpret_cast<unsigned long>(t);
		}
		template<typename T>
		T GetAttachmentAs() { return reinterpret_cast<T>(mAttachment); }
		//����ʹ����
		void SetUsed(unsigned long size) { mUsed = size; }
		//��ȡ��������
		IO_Operation GetOperation() const { return mOperationType; }
		//���õ�ǰ�������ͣ�CompletionKeyʹ�ã�
		void SetOperation(IO_Operation operation) { mOperationType = operation; }
		// ���� seek ����ָ��
		void* GetPointer();
		// ���� index ����ָ��
		void* GetPointer(unsigned long index);
		//���ⲿ�����������
		void CopyFrom(unsigned long startIndex, const void* source, int length);
		//�������� �����ܳ�������ݻ�
		unsigned long Append(const void *data, unsigned long length);
		static void* operator new(size_t objSize, size_t bufferSize);
		static void operator delete(void *pObj);
		static void operator delete(void *pObj, size_t);
	private:
		unsigned long mBufferSize{ 0l };  //�ܳ���
		unsigned long mUsed{ 0l };  //��ǰʹ��
		unsigned long mAttachment{ 0l }; //����ָ��(Ϊʹ��)
		unsigned long mSeek{ 0l };  // ��ǰ��ȡλ��
		Socket& mSocket;  //socket��CompletionKeyʹ�ã�
		IO_Operation mOperationType{ IO_Operation::IO_Termination }; //�������ͣ�CompletionKeyʹ�ã�
		char mBuffer[0];  //������յ�������
	};
}