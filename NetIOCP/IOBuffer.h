#pragma once

#include <WinSock2.h>

namespace NetIOCP {
	class Socket;
	/*
	iocp单io操作数据记录
	*/
	class IOBuffer : public WSAOVERLAPPED {
	public:
		IOBuffer(unsigned int size, Socket& skt);
	private:
		IOBuffer(const IOBuffer&) = delete;
		IOBuffer& operator=(const IOBuffer&) = delete;
	public:
		//清空(只需使用量归0)
		void Clear() { mUsed = 0; }
		//获取socket对象
		Socket& GetSocket() { return mSocket; }
		//获取总容积
		unsigned long GetSize() const { return mBufferSize; }
		//获取使用量
		unsigned long GetUsed() const { return mUsed; }
		//获取剩余容积
		unsigned long GetResidualCapacity() const {	return mBufferSize - mUsed; }
		//设置当前读取指针
		void Seek(unsigned long offset) {
			if (mBufferSize <= offset) {
				throw std::exception("Out of range");
			}
			mSeek = offset;
		}
		unsigned long Seek() const { return mSeek; }
		//附件指针
		template<typename T>
		void SetAttachment(T t) {
			static_assert(sizeof(T) == sizeof(unsigned long),
				"The size of T must equal or less than size of unsigned long");
			mAttachment = reinterpret_cast<unsigned long>(t);
		}
		template<typename T>
		T GetAttachmentAs() { return reinterpret_cast<T>(mAttachment); }
		//设置使用量
		void SetUsed(unsigned long size) { mUsed = size; }
		//获取操作类型
		IO_Operation GetOperation() const { return mOperationType; }
		//设置当前操作类型（CompletionKey使用）
		void SetOperation(IO_Operation operation) { mOperationType = operation; }
		// 根据 seek 返回指针
		void* GetPointer();
		// 根据 index 返回指针
		void* GetPointer(unsigned long index);
		//从外部拷贝数据填充
		void CopyFrom(unsigned long startIndex, const void* source, int length);
		//增加数据 但不能超过最大容积
		unsigned long Append(const void *data, unsigned long length);
		static void* operator new(size_t objSize, size_t bufferSize);
		static void operator delete(void *pObj);
		static void operator delete(void *pObj, size_t);
	private:
		unsigned long mBufferSize{ 0l };  //总长度
		unsigned long mUsed{ 0l };  //当前使用
		unsigned long mAttachment{ 0l }; //附件指针(为使用)
		unsigned long mSeek{ 0l };  // 当前读取位置
		Socket& mSocket;  //socket（CompletionKey使用）
		IO_Operation mOperationType{ IO_Operation::IO_Termination }; //操作类型（CompletionKey使用）
		char mBuffer[0];  //保存接收到的数据
	};
}