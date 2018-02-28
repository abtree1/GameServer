#pragma once

#include <WinSock2.h>

namespace NetIOCP {
	class Socket;

	class IOBuffer : public WSAOVERLAPPED {
	public:
		IOBuffer(unsigned int size, Socket& skt);
	private:
		IOBuffer(const IOBuffer&) = delete;
		IOBuffer& operator=(const IOBuffer&) = delete;
	public:
		void Clear() { mUsed = 0; }
		Socket& GetSocket() { return mSocket; }
		unsigned long GetSize() const { return mBufferSize; }
		unsigned long GetUsed() const { return mUsed; }
		unsigned long GetResidualCapacity() const {	return mBufferSize - mUsed; }
		void Seek(unsigned long offset) {
			if (mBufferSize <= offset) {
				throw std::exception("Out of range");
			}
			mSeek = offset;
		}
		unsigned long Seek() const { return mSeek; }
		template<typename T>
		void SetAttachment(T t) {
			static_assert(sizeof(T) == sizeof(unsigned long),
				"The size of T must equal or less than size of unsigned long");
			mAttachment = reinterpret_cast<unsigned long>(t);
		}
		template<typename T>
		T GetAttachmentAs() { return reinterpret_cast<T>(mAttachment); }
		void SetUsed(unsigned long size) { mUsed = size; }
		IO_Operation GetOperation() const { return mOperationType; }
		void SetOperation(IO_Operation operation) { mOperationType = operation; }
		// 根据 seek 返回指针
		void* GetPointer();
		// 根据 index 返回指针
		void* GetPointer(unsigned long index);
		void CopyFrom(unsigned long startIndex, const void* source, int length);
		unsigned long Append(const void *data, unsigned long length);
		static void* operator new(size_t objSize, size_t bufferSize);
		static void operator delete(void *pObj);
		static void operator delete(void *pObj, size_t);
	private:
		unsigned long mBufferSize{ 0l };
		unsigned long mUsed{ 0l };
		unsigned long mAttachment{ 0l };
		unsigned long mSeek{ 0l };
		Socket& mSocket;
		IO_Operation mOperationType{ IO_Operation::IO_Termination };
		char mBuffer[0];
	};
}