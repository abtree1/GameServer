// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg.proto

#ifndef PROTOBUF_msg_2eproto__INCLUDED
#define PROTOBUF_msg_2eproto__INCLUDED

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
class NetCreateRole;
class NetCreateRoleDefaultTypeInternal;
extern NetCreateRoleDefaultTypeInternal _NetCreateRole_default_instance_;
class NetLogin;
class NetLoginDefaultTypeInternal;
extern NetLoginDefaultTypeInternal _NetLogin_default_instance_;
}  // namespace NetProto

namespace NetProto {

namespace protobuf_msg_2eproto {
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
}  // namespace protobuf_msg_2eproto

// ===================================================================

class NetLogin : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.NetLogin) */ {
 public:
  NetLogin();
  virtual ~NetLogin();

  NetLogin(const NetLogin& from);

  inline NetLogin& operator=(const NetLogin& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  NetLogin(NetLogin&& from) noexcept
    : NetLogin() {
    *this = ::std::move(from);
  }

  inline NetLogin& operator=(NetLogin&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const NetLogin& default_instance();

  static inline const NetLogin* internal_default_instance() {
    return reinterpret_cast<const NetLogin*>(
               &_NetLogin_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(NetLogin* other);
  friend void swap(NetLogin& a, NetLogin& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline NetLogin* New() const PROTOBUF_FINAL { return New(NULL); }

  NetLogin* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const NetLogin& from);
  void MergeFrom(const NetLogin& from);
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
  void InternalSwap(NetLogin* other);
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

  // string account = 1;
  void clear_account();
  static const int kAccountFieldNumber = 1;
  const ::std::string& account() const;
  void set_account(const ::std::string& value);
  #if LANG_CXX11
  void set_account(::std::string&& value);
  #endif
  void set_account(const char* value);
  void set_account(const char* value, size_t size);
  ::std::string* mutable_account();
  ::std::string* release_account();
  void set_allocated_account(::std::string* account);

  // string token = 3;
  void clear_token();
  static const int kTokenFieldNumber = 3;
  const ::std::string& token() const;
  void set_token(const ::std::string& value);
  #if LANG_CXX11
  void set_token(::std::string&& value);
  #endif
  void set_token(const char* value);
  void set_token(const char* value, size_t size);
  ::std::string* mutable_token();
  ::std::string* release_token();
  void set_allocated_token(::std::string* token);

  // int32 platform = 2;
  void clear_platform();
  static const int kPlatformFieldNumber = 2;
  ::google::protobuf::int32 platform() const;
  void set_platform(::google::protobuf::int32 value);

  // int32 serverid = 4;
  void clear_serverid();
  static const int kServeridFieldNumber = 4;
  ::google::protobuf::int32 serverid() const;
  void set_serverid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:NetProto.NetLogin)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr account_;
  ::google::protobuf::internal::ArenaStringPtr token_;
  ::google::protobuf::int32 platform_;
  ::google::protobuf::int32 serverid_;
  mutable int _cached_size_;
  friend struct protobuf_msg_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class NetCreateRole : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NetProto.NetCreateRole) */ {
 public:
  NetCreateRole();
  virtual ~NetCreateRole();

  NetCreateRole(const NetCreateRole& from);

  inline NetCreateRole& operator=(const NetCreateRole& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  NetCreateRole(NetCreateRole&& from) noexcept
    : NetCreateRole() {
    *this = ::std::move(from);
  }

  inline NetCreateRole& operator=(NetCreateRole&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const NetCreateRole& default_instance();

  static inline const NetCreateRole* internal_default_instance() {
    return reinterpret_cast<const NetCreateRole*>(
               &_NetCreateRole_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(NetCreateRole* other);
  friend void swap(NetCreateRole& a, NetCreateRole& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline NetCreateRole* New() const PROTOBUF_FINAL { return New(NULL); }

  NetCreateRole* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const NetCreateRole& from);
  void MergeFrom(const NetCreateRole& from);
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
  void InternalSwap(NetCreateRole* other);
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

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // @@protoc_insertion_point(class_scope:NetProto.NetCreateRole)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  mutable int _cached_size_;
  friend struct protobuf_msg_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// NetLogin

// string account = 1;
inline void NetLogin::clear_account() {
  account_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& NetLogin::account() const {
  // @@protoc_insertion_point(field_get:NetProto.NetLogin.account)
  return account_.GetNoArena();
}
inline void NetLogin::set_account(const ::std::string& value) {
  
  account_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.NetLogin.account)
}
#if LANG_CXX11
inline void NetLogin::set_account(::std::string&& value) {
  
  account_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.NetLogin.account)
}
#endif
inline void NetLogin::set_account(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  account_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.NetLogin.account)
}
inline void NetLogin::set_account(const char* value, size_t size) {
  
  account_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.NetLogin.account)
}
inline ::std::string* NetLogin::mutable_account() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.NetLogin.account)
  return account_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* NetLogin::release_account() {
  // @@protoc_insertion_point(field_release:NetProto.NetLogin.account)
  
  return account_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NetLogin::set_allocated_account(::std::string* account) {
  if (account != NULL) {
    
  } else {
    
  }
  account_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), account);
  // @@protoc_insertion_point(field_set_allocated:NetProto.NetLogin.account)
}

// int32 platform = 2;
inline void NetLogin::clear_platform() {
  platform_ = 0;
}
inline ::google::protobuf::int32 NetLogin::platform() const {
  // @@protoc_insertion_point(field_get:NetProto.NetLogin.platform)
  return platform_;
}
inline void NetLogin::set_platform(::google::protobuf::int32 value) {
  
  platform_ = value;
  // @@protoc_insertion_point(field_set:NetProto.NetLogin.platform)
}

// string token = 3;
inline void NetLogin::clear_token() {
  token_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& NetLogin::token() const {
  // @@protoc_insertion_point(field_get:NetProto.NetLogin.token)
  return token_.GetNoArena();
}
inline void NetLogin::set_token(const ::std::string& value) {
  
  token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.NetLogin.token)
}
#if LANG_CXX11
inline void NetLogin::set_token(::std::string&& value) {
  
  token_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.NetLogin.token)
}
#endif
inline void NetLogin::set_token(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.NetLogin.token)
}
inline void NetLogin::set_token(const char* value, size_t size) {
  
  token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.NetLogin.token)
}
inline ::std::string* NetLogin::mutable_token() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.NetLogin.token)
  return token_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* NetLogin::release_token() {
  // @@protoc_insertion_point(field_release:NetProto.NetLogin.token)
  
  return token_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NetLogin::set_allocated_token(::std::string* token) {
  if (token != NULL) {
    
  } else {
    
  }
  token_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), token);
  // @@protoc_insertion_point(field_set_allocated:NetProto.NetLogin.token)
}

// int32 serverid = 4;
inline void NetLogin::clear_serverid() {
  serverid_ = 0;
}
inline ::google::protobuf::int32 NetLogin::serverid() const {
  // @@protoc_insertion_point(field_get:NetProto.NetLogin.serverid)
  return serverid_;
}
inline void NetLogin::set_serverid(::google::protobuf::int32 value) {
  
  serverid_ = value;
  // @@protoc_insertion_point(field_set:NetProto.NetLogin.serverid)
}

// -------------------------------------------------------------------

// NetCreateRole

// string name = 1;
inline void NetCreateRole::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& NetCreateRole::name() const {
  // @@protoc_insertion_point(field_get:NetProto.NetCreateRole.name)
  return name_.GetNoArena();
}
inline void NetCreateRole::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.NetCreateRole.name)
}
#if LANG_CXX11
inline void NetCreateRole::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.NetCreateRole.name)
}
#endif
inline void NetCreateRole::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.NetCreateRole.name)
}
inline void NetCreateRole::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.NetCreateRole.name)
}
inline ::std::string* NetCreateRole::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:NetProto.NetCreateRole.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* NetCreateRole::release_name() {
  // @@protoc_insertion_point(field_release:NetProto.NetCreateRole.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void NetCreateRole::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:NetProto.NetCreateRole.name)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace NetProto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_msg_2eproto__INCLUDED
