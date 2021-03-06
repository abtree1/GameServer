// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msgserver.proto

#ifndef PROTOBUF_msgserver_2eproto__INCLUDED
#define PROTOBUF_msgserver_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace NetProto {
class CIdentifyKey;
class CIdentifyKeyDefaultTypeInternal;
extern CIdentifyKeyDefaultTypeInternal _CIdentifyKey_default_instance_;
class CSPNextData;
class CSPNextDataDefaultTypeInternal;
extern CSPNextDataDefaultTypeInternal _CSPNextData_default_instance_;
class CTimeTaskData;
class CTimeTaskDataDefaultTypeInternal;
extern CTimeTaskDataDefaultTypeInternal _CTimeTaskData_default_instance_;
}  // namespace NetProto

namespace NetProto {

namespace protobuf_msgserver_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_msgserver_2eproto

// ===================================================================

class CSPNextData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.CSPNextData) */ {
 public:
  CSPNextData();
  virtual ~CSPNextData();

  CSPNextData(const CSPNextData& from);

  inline CSPNextData& operator=(const CSPNextData& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CSPNextData(CSPNextData&& from) noexcept
    : CSPNextData() {
    *this = ::std::move(from);
  }

  inline CSPNextData& operator=(CSPNextData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const CSPNextData& default_instance();

  static inline const CSPNextData* internal_default_instance() {
    return reinterpret_cast<const CSPNextData*>(
               &_CSPNextData_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(CSPNextData* other);
  friend void swap(CSPNextData& a, CSPNextData& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CSPNextData* New() const PROTOBUF_FINAL { return New(NULL); }

  CSPNextData* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CSPNextData& from);
  void MergeFrom(const CSPNextData& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(CSPNextData* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated int32 ivalue_arr = 4;
  int ivalue_arr_size() const;
  void clear_ivalue_arr();
  static const int kIvalueArrFieldNumber = 4;
  ::google::protobuf::int32 ivalue_arr(int index) const;
  void set_ivalue_arr(int index, ::google::protobuf::int32 value);
  void add_ivalue_arr(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      ivalue_arr() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_ivalue_arr();

  // repeated string svalue_arr = 5;
  int svalue_arr_size() const;
  void clear_svalue_arr();
  static const int kSvalueArrFieldNumber = 5;
  const ::std::string& svalue_arr(int index) const;
  ::std::string* mutable_svalue_arr(int index);
  void set_svalue_arr(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_svalue_arr(int index, ::std::string&& value);
  #endif
  void set_svalue_arr(int index, const char* value);
  void set_svalue_arr(int index, const char* value, size_t size);
  ::std::string* add_svalue_arr();
  void add_svalue_arr(const ::std::string& value);
  #if LANG_CXX11
  void add_svalue_arr(::std::string&& value);
  #endif
  void add_svalue_arr(const char* value);
  void add_svalue_arr(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& svalue_arr() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_svalue_arr();

  // string svalue = 3;
  void clear_svalue();
  static const int kSvalueFieldNumber = 3;
  const ::std::string& svalue() const;
  void set_svalue(const ::std::string& value);
  #if LANG_CXX11
  void set_svalue(::std::string&& value);
  #endif
  void set_svalue(const char* value);
  void set_svalue(const char* value, size_t size);
  ::std::string* mutable_svalue();
  ::std::string* release_svalue();
  void set_allocated_svalue(::std::string* svalue);

  // uint32 type = 1;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::google::protobuf::uint32 type() const;
  void set_type(::google::protobuf::uint32 value);

  // int32 ivalue = 2;
  void clear_ivalue();
  static const int kIvalueFieldNumber = 2;
  ::google::protobuf::int32 ivalue() const;
  void set_ivalue(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:NetProto.CSPNextData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > ivalue_arr_;
  mutable int _ivalue_arr_cached_byte_size_;
  ::google::protobuf::RepeatedPtrField< ::std::string> svalue_arr_;
  ::google::protobuf::internal::ArenaStringPtr svalue_;
  ::google::protobuf::uint32 type_;
  ::google::protobuf::int32 ivalue_;
  mutable int _cached_size_;
  friend struct protobuf_msgserver_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class CIdentifyKey : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.CIdentifyKey) */ {
 public:
  CIdentifyKey();
  virtual ~CIdentifyKey();

  CIdentifyKey(const CIdentifyKey& from);

  inline CIdentifyKey& operator=(const CIdentifyKey& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CIdentifyKey(CIdentifyKey&& from) noexcept
    : CIdentifyKey() {
    *this = ::std::move(from);
  }

  inline CIdentifyKey& operator=(CIdentifyKey&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const CIdentifyKey& default_instance();

  static inline const CIdentifyKey* internal_default_instance() {
    return reinterpret_cast<const CIdentifyKey*>(
               &_CIdentifyKey_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(CIdentifyKey* other);
  friend void swap(CIdentifyKey& a, CIdentifyKey& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CIdentifyKey* New() const PROTOBUF_FINAL { return New(NULL); }

  CIdentifyKey* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CIdentifyKey& from);
  void MergeFrom(const CIdentifyKey& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(CIdentifyKey* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint32 type = 1;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::google::protobuf::uint32 type() const;
  void set_type(::google::protobuf::uint32 value);

  // int32 ivalue = 2;
  void clear_ivalue();
  static const int kIvalueFieldNumber = 2;
  ::google::protobuf::int32 ivalue() const;
  void set_ivalue(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:NetProto.CIdentifyKey)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 type_;
  ::google::protobuf::int32 ivalue_;
  mutable int _cached_size_;
  friend struct protobuf_msgserver_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class CTimeTaskData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.CTimeTaskData) */ {
 public:
  CTimeTaskData();
  virtual ~CTimeTaskData();

  CTimeTaskData(const CTimeTaskData& from);

  inline CTimeTaskData& operator=(const CTimeTaskData& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CTimeTaskData(CTimeTaskData&& from) noexcept
    : CTimeTaskData() {
    *this = ::std::move(from);
  }

  inline CTimeTaskData& operator=(CTimeTaskData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const CTimeTaskData& default_instance();

  static inline const CTimeTaskData* internal_default_instance() {
    return reinterpret_cast<const CTimeTaskData*>(
               &_CTimeTaskData_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(CTimeTaskData* other);
  friend void swap(CTimeTaskData& a, CTimeTaskData& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CTimeTaskData* New() const PROTOBUF_FINAL { return New(NULL); }

  CTimeTaskData* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CTimeTaskData& from);
  void MergeFrom(const CTimeTaskData& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(CTimeTaskData* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated int32 ivalue_arr = 4;
  int ivalue_arr_size() const;
  void clear_ivalue_arr();
  static const int kIvalueArrFieldNumber = 4;
  ::google::protobuf::int32 ivalue_arr(int index) const;
  void set_ivalue_arr(int index, ::google::protobuf::int32 value);
  void add_ivalue_arr(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      ivalue_arr() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_ivalue_arr();

  // repeated string svalue_arr = 5;
  int svalue_arr_size() const;
  void clear_svalue_arr();
  static const int kSvalueArrFieldNumber = 5;
  const ::std::string& svalue_arr(int index) const;
  ::std::string* mutable_svalue_arr(int index);
  void set_svalue_arr(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_svalue_arr(int index, ::std::string&& value);
  #endif
  void set_svalue_arr(int index, const char* value);
  void set_svalue_arr(int index, const char* value, size_t size);
  ::std::string* add_svalue_arr();
  void add_svalue_arr(const ::std::string& value);
  #if LANG_CXX11
  void add_svalue_arr(::std::string&& value);
  #endif
  void add_svalue_arr(const char* value);
  void add_svalue_arr(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& svalue_arr() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_svalue_arr();

  // string svalue = 3;
  void clear_svalue();
  static const int kSvalueFieldNumber = 3;
  const ::std::string& svalue() const;
  void set_svalue(const ::std::string& value);
  #if LANG_CXX11
  void set_svalue(::std::string&& value);
  #endif
  void set_svalue(const char* value);
  void set_svalue(const char* value, size_t size);
  ::std::string* mutable_svalue();
  ::std::string* release_svalue();
  void set_allocated_svalue(::std::string* svalue);

  // uint32 type = 1;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::google::protobuf::uint32 type() const;
  void set_type(::google::protobuf::uint32 value);

  // int32 ivalue = 2;
  void clear_ivalue();
  static const int kIvalueFieldNumber = 2;
  ::google::protobuf::int32 ivalue() const;
  void set_ivalue(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:NetProto.CTimeTaskData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > ivalue_arr_;
  mutable int _ivalue_arr_cached_byte_size_;
  ::google::protobuf::RepeatedPtrField< ::std::string> svalue_arr_;
  ::google::protobuf::internal::ArenaStringPtr svalue_;
  ::google::protobuf::uint32 type_;
  ::google::protobuf::int32 ivalue_;
  mutable int _cached_size_;
  friend struct protobuf_msgserver_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CSPNextData

// uint32 type = 1;
inline void CSPNextData::clear_type() {
  type_ = 0u;
}
inline ::google::protobuf::uint32 CSPNextData::type() const {
  // @@protoc_insertion_point(field_get:NetProto.CSPNextData.type)
  return type_;
}
inline void CSPNextData::set_type(::google::protobuf::uint32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:NetProto.CSPNextData.type)
}

// int32 ivalue = 2;
inline void CSPNextData::clear_ivalue() {
  ivalue_ = 0;
}
inline ::google::protobuf::int32 CSPNextData::ivalue() const {
  // @@protoc_insertion_point(field_get:NetProto.CSPNextData.ivalue)
  return ivalue_;
}
inline void CSPNextData::set_ivalue(::google::protobuf::int32 value) {
  
  ivalue_ = value;
  // @@protoc_insertion_point(field_set:NetProto.CSPNextData.ivalue)
}

// string svalue = 3;
inline void CSPNextData::clear_svalue() {
  svalue_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CSPNextData::svalue() const {
  // @@protoc_insertion_point(field_get:NetProto.CSPNextData.svalue)
  return svalue_.GetNoArena();
}
inline void CSPNextData::set_svalue(const ::std::string& value) {
  
  svalue_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.CSPNextData.svalue)
}
#if LANG_CXX11
inline void CSPNextData::set_svalue(::std::string&& value) {
  
  svalue_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.CSPNextData.svalue)
}
#endif
inline void CSPNextData::set_svalue(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  svalue_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.CSPNextData.svalue)
}
inline void CSPNextData::set_svalue(const char* value, size_t size) {
  
  svalue_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.CSPNextData.svalue)
}
inline ::std::string* CSPNextData::mutable_svalue() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.CSPNextData.svalue)
  return svalue_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CSPNextData::release_svalue() {
  // @@protoc_insertion_point(field_release:NetProto.CSPNextData.svalue)
  
  return svalue_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CSPNextData::set_allocated_svalue(::std::string* svalue) {
  if (svalue != NULL) {
    
  } else {
    
  }
  svalue_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), svalue);
  // @@protoc_insertion_point(field_set_allocated:NetProto.CSPNextData.svalue)
}

// repeated int32 ivalue_arr = 4;
inline int CSPNextData::ivalue_arr_size() const {
  return ivalue_arr_.size();
}
inline void CSPNextData::clear_ivalue_arr() {
  ivalue_arr_.Clear();
}
inline ::google::protobuf::int32 CSPNextData::ivalue_arr(int index) const {
  // @@protoc_insertion_point(field_get:NetProto.CSPNextData.ivalue_arr)
  return ivalue_arr_.Get(index);
}
inline void CSPNextData::set_ivalue_arr(int index, ::google::protobuf::int32 value) {
  ivalue_arr_.Set(index, value);
  // @@protoc_insertion_point(field_set:NetProto.CSPNextData.ivalue_arr)
}
inline void CSPNextData::add_ivalue_arr(::google::protobuf::int32 value) {
  ivalue_arr_.Add(value);
  // @@protoc_insertion_point(field_add:NetProto.CSPNextData.ivalue_arr)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
CSPNextData::ivalue_arr() const {
  // @@protoc_insertion_point(field_list:NetProto.CSPNextData.ivalue_arr)
  return ivalue_arr_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
CSPNextData::mutable_ivalue_arr() {
  // @@protoc_insertion_point(field_mutable_list:NetProto.CSPNextData.ivalue_arr)
  return &ivalue_arr_;
}

// repeated string svalue_arr = 5;
inline int CSPNextData::svalue_arr_size() const {
  return svalue_arr_.size();
}
inline void CSPNextData::clear_svalue_arr() {
  svalue_arr_.Clear();
}
inline const ::std::string& CSPNextData::svalue_arr(int index) const {
  // @@protoc_insertion_point(field_get:NetProto.CSPNextData.svalue_arr)
  return svalue_arr_.Get(index);
}
inline ::std::string* CSPNextData::mutable_svalue_arr(int index) {
  // @@protoc_insertion_point(field_mutable:NetProto.CSPNextData.svalue_arr)
  return svalue_arr_.Mutable(index);
}
inline void CSPNextData::set_svalue_arr(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:NetProto.CSPNextData.svalue_arr)
  svalue_arr_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void CSPNextData::set_svalue_arr(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:NetProto.CSPNextData.svalue_arr)
  svalue_arr_.Mutable(index)->assign(std::move(value));
}
#endif
inline void CSPNextData::set_svalue_arr(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  svalue_arr_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:NetProto.CSPNextData.svalue_arr)
}
inline void CSPNextData::set_svalue_arr(int index, const char* value, size_t size) {
  svalue_arr_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:NetProto.CSPNextData.svalue_arr)
}
inline ::std::string* CSPNextData::add_svalue_arr() {
  // @@protoc_insertion_point(field_add_mutable:NetProto.CSPNextData.svalue_arr)
  return svalue_arr_.Add();
}
inline void CSPNextData::add_svalue_arr(const ::std::string& value) {
  svalue_arr_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:NetProto.CSPNextData.svalue_arr)
}
#if LANG_CXX11
inline void CSPNextData::add_svalue_arr(::std::string&& value) {
  svalue_arr_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:NetProto.CSPNextData.svalue_arr)
}
#endif
inline void CSPNextData::add_svalue_arr(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  svalue_arr_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:NetProto.CSPNextData.svalue_arr)
}
inline void CSPNextData::add_svalue_arr(const char* value, size_t size) {
  svalue_arr_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:NetProto.CSPNextData.svalue_arr)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
CSPNextData::svalue_arr() const {
  // @@protoc_insertion_point(field_list:NetProto.CSPNextData.svalue_arr)
  return svalue_arr_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
CSPNextData::mutable_svalue_arr() {
  // @@protoc_insertion_point(field_mutable_list:NetProto.CSPNextData.svalue_arr)
  return &svalue_arr_;
}

// -------------------------------------------------------------------

// CIdentifyKey

// uint32 type = 1;
inline void CIdentifyKey::clear_type() {
  type_ = 0u;
}
inline ::google::protobuf::uint32 CIdentifyKey::type() const {
  // @@protoc_insertion_point(field_get:NetProto.CIdentifyKey.type)
  return type_;
}
inline void CIdentifyKey::set_type(::google::protobuf::uint32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:NetProto.CIdentifyKey.type)
}

// int32 ivalue = 2;
inline void CIdentifyKey::clear_ivalue() {
  ivalue_ = 0;
}
inline ::google::protobuf::int32 CIdentifyKey::ivalue() const {
  // @@protoc_insertion_point(field_get:NetProto.CIdentifyKey.ivalue)
  return ivalue_;
}
inline void CIdentifyKey::set_ivalue(::google::protobuf::int32 value) {
  
  ivalue_ = value;
  // @@protoc_insertion_point(field_set:NetProto.CIdentifyKey.ivalue)
}

// -------------------------------------------------------------------

// CTimeTaskData

// uint32 type = 1;
inline void CTimeTaskData::clear_type() {
  type_ = 0u;
}
inline ::google::protobuf::uint32 CTimeTaskData::type() const {
  // @@protoc_insertion_point(field_get:NetProto.CTimeTaskData.type)
  return type_;
}
inline void CTimeTaskData::set_type(::google::protobuf::uint32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:NetProto.CTimeTaskData.type)
}

// int32 ivalue = 2;
inline void CTimeTaskData::clear_ivalue() {
  ivalue_ = 0;
}
inline ::google::protobuf::int32 CTimeTaskData::ivalue() const {
  // @@protoc_insertion_point(field_get:NetProto.CTimeTaskData.ivalue)
  return ivalue_;
}
inline void CTimeTaskData::set_ivalue(::google::protobuf::int32 value) {
  
  ivalue_ = value;
  // @@protoc_insertion_point(field_set:NetProto.CTimeTaskData.ivalue)
}

// string svalue = 3;
inline void CTimeTaskData::clear_svalue() {
  svalue_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CTimeTaskData::svalue() const {
  // @@protoc_insertion_point(field_get:NetProto.CTimeTaskData.svalue)
  return svalue_.GetNoArena();
}
inline void CTimeTaskData::set_svalue(const ::std::string& value) {
  
  svalue_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.CTimeTaskData.svalue)
}
#if LANG_CXX11
inline void CTimeTaskData::set_svalue(::std::string&& value) {
  
  svalue_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.CTimeTaskData.svalue)
}
#endif
inline void CTimeTaskData::set_svalue(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  svalue_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.CTimeTaskData.svalue)
}
inline void CTimeTaskData::set_svalue(const char* value, size_t size) {
  
  svalue_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.CTimeTaskData.svalue)
}
inline ::std::string* CTimeTaskData::mutable_svalue() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.CTimeTaskData.svalue)
  return svalue_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CTimeTaskData::release_svalue() {
  // @@protoc_insertion_point(field_release:NetProto.CTimeTaskData.svalue)
  
  return svalue_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CTimeTaskData::set_allocated_svalue(::std::string* svalue) {
  if (svalue != NULL) {
    
  } else {
    
  }
  svalue_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), svalue);
  // @@protoc_insertion_point(field_set_allocated:NetProto.CTimeTaskData.svalue)
}

// repeated int32 ivalue_arr = 4;
inline int CTimeTaskData::ivalue_arr_size() const {
  return ivalue_arr_.size();
}
inline void CTimeTaskData::clear_ivalue_arr() {
  ivalue_arr_.Clear();
}
inline ::google::protobuf::int32 CTimeTaskData::ivalue_arr(int index) const {
  // @@protoc_insertion_point(field_get:NetProto.CTimeTaskData.ivalue_arr)
  return ivalue_arr_.Get(index);
}
inline void CTimeTaskData::set_ivalue_arr(int index, ::google::protobuf::int32 value) {
  ivalue_arr_.Set(index, value);
  // @@protoc_insertion_point(field_set:NetProto.CTimeTaskData.ivalue_arr)
}
inline void CTimeTaskData::add_ivalue_arr(::google::protobuf::int32 value) {
  ivalue_arr_.Add(value);
  // @@protoc_insertion_point(field_add:NetProto.CTimeTaskData.ivalue_arr)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
CTimeTaskData::ivalue_arr() const {
  // @@protoc_insertion_point(field_list:NetProto.CTimeTaskData.ivalue_arr)
  return ivalue_arr_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
CTimeTaskData::mutable_ivalue_arr() {
  // @@protoc_insertion_point(field_mutable_list:NetProto.CTimeTaskData.ivalue_arr)
  return &ivalue_arr_;
}

// repeated string svalue_arr = 5;
inline int CTimeTaskData::svalue_arr_size() const {
  return svalue_arr_.size();
}
inline void CTimeTaskData::clear_svalue_arr() {
  svalue_arr_.Clear();
}
inline const ::std::string& CTimeTaskData::svalue_arr(int index) const {
  // @@protoc_insertion_point(field_get:NetProto.CTimeTaskData.svalue_arr)
  return svalue_arr_.Get(index);
}
inline ::std::string* CTimeTaskData::mutable_svalue_arr(int index) {
  // @@protoc_insertion_point(field_mutable:NetProto.CTimeTaskData.svalue_arr)
  return svalue_arr_.Mutable(index);
}
inline void CTimeTaskData::set_svalue_arr(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:NetProto.CTimeTaskData.svalue_arr)
  svalue_arr_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void CTimeTaskData::set_svalue_arr(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:NetProto.CTimeTaskData.svalue_arr)
  svalue_arr_.Mutable(index)->assign(std::move(value));
}
#endif
inline void CTimeTaskData::set_svalue_arr(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  svalue_arr_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:NetProto.CTimeTaskData.svalue_arr)
}
inline void CTimeTaskData::set_svalue_arr(int index, const char* value, size_t size) {
  svalue_arr_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:NetProto.CTimeTaskData.svalue_arr)
}
inline ::std::string* CTimeTaskData::add_svalue_arr() {
  // @@protoc_insertion_point(field_add_mutable:NetProto.CTimeTaskData.svalue_arr)
  return svalue_arr_.Add();
}
inline void CTimeTaskData::add_svalue_arr(const ::std::string& value) {
  svalue_arr_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:NetProto.CTimeTaskData.svalue_arr)
}
#if LANG_CXX11
inline void CTimeTaskData::add_svalue_arr(::std::string&& value) {
  svalue_arr_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:NetProto.CTimeTaskData.svalue_arr)
}
#endif
inline void CTimeTaskData::add_svalue_arr(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  svalue_arr_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:NetProto.CTimeTaskData.svalue_arr)
}
inline void CTimeTaskData::add_svalue_arr(const char* value, size_t size) {
  svalue_arr_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:NetProto.CTimeTaskData.svalue_arr)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
CTimeTaskData::svalue_arr() const {
  // @@protoc_insertion_point(field_list:NetProto.CTimeTaskData.svalue_arr)
  return svalue_arr_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
CTimeTaskData::mutable_svalue_arr() {
  // @@protoc_insertion_point(field_mutable_list:NetProto.CTimeTaskData.svalue_arr)
  return &svalue_arr_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace NetProto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_msgserver_2eproto__INCLUDED
