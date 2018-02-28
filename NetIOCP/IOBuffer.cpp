#include "stdafx.h"

namespace NetIOCP {
	IOBuffer::IOBuffer(unsigned int size, Socket& skt)
		:mSocket(skt)
		,mBufferSize(size) {
		memset(this, 0, sizeof(WSAOVERLAPPED));
	}

	unsigned long IOBuffer::Append(const void *data, unsigned long length) {
		if (nullptr == data)
			return 0;
		unsigned long validCapacity = mBufferSize - mUsed;
		if (0 == validCapacity)
			return 0;
		unsigned long appended = validCapacity > length ? length : validCapacity;
		memcpy(&mBuffer[mUsed], data, appended);
		mUsed += appended;
		return appended;
	}

	void* IOBuffer::GetPointer() {
		return &mBuffer[mSeek];
	}

	void* IOBuffer::GetPointer(unsigned long index) {
		if(index >= mBufferSize)
			std::exception("Out of range");
		return &mBuffer[index];
	}
	
	void IOBuffer::CopyFrom(unsigned long startIndex, const void* source, int length) {
		::memcpy(GetPointer(startIndex), source, length);
	}

	void* IOBuffer::operator new(size_t objSize, size_t bufferSize) {
		return ::operator new(objSize + bufferSize);
	}

	void IOBuffer::operator delete(void *pObj) {
		if (nullptr != pObj) {
			delete[] static_cast<char*>(pObj);
		}
	}

	void IOBuffer::operator delete(void *pObj, size_t) {
		if (nullptr != pObj) {
			delete[] static_cast<char*>(pObj);
		}
	}
}