// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg.proto
#include "stdafx.h"
#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "msg.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace NetProto {
class NetLoginDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<NetLogin>
     _instance;
} _NetLogin_default_instance_;
class NetCreateRoleDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<NetCreateRole>
     _instance;
} _NetCreateRole_default_instance_;

namespace protobuf_msg_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[2];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetLogin, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetLogin, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetLogin, account_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetLogin, platform_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetLogin, token_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetLogin, serverid_),
  0,
  2,
  1,
  3,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetCreateRole, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetCreateRole, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetCreateRole, name_),
  0,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, sizeof(NetLogin)},
  { 13, 19, sizeof(NetCreateRole)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_NetLogin_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&_NetCreateRole_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "msg.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

}  // namespace
void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _NetLogin_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_NetLogin_default_instance_);_NetCreateRole_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_NetCreateRole_default_instance_);}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\tmsg.proto\022\010NetProto\"N\n\010NetLogin\022\017\n\007acc"
      "ount\030\001 \001(\t\022\020\n\010platform\030\002 \001(\005\022\r\n\005token\030\003 "
      "\001(\t\022\020\n\010serverid\030\004 \001(\005\"\035\n\rNetCreateRole\022\014"
      "\n\004name\030\001 \001(\t"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 132);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "msg.proto", &protobuf_RegisterTypes);
}
} // anonymous namespace

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_msg_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int NetLogin::kAccountFieldNumber;
const int NetLogin::kPlatformFieldNumber;
const int NetLogin::kTokenFieldNumber;
const int NetLogin::kServeridFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

NetLogin::NetLogin()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_msg_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:NetProto.NetLogin)
}
NetLogin::NetLogin(const NetLogin& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  account_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_account()) {
    account_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.account_);
  }
  token_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_token()) {
    token_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.token_);
  }
  ::memcpy(&platform_, &from.platform_,
    static_cast<size_t>(reinterpret_cast<char*>(&serverid_) -
    reinterpret_cast<char*>(&platform_)) + sizeof(serverid_));
  // @@protoc_insertion_point(copy_constructor:NetProto.NetLogin)
}

void NetLogin::SharedCtor() {
  _cached_size_ = 0;
  account_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  token_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&platform_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&serverid_) -
      reinterpret_cast<char*>(&platform_)) + sizeof(serverid_));
}

NetLogin::~NetLogin() {
  // @@protoc_insertion_point(destructor:NetProto.NetLogin)
  SharedDtor();
}

void NetLogin::SharedDtor() {
  account_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  token_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void NetLogin::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* NetLogin::descriptor() {
  protobuf_msg_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_msg_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const NetLogin& NetLogin::default_instance() {
  protobuf_msg_2eproto::InitDefaults();
  return *internal_default_instance();
}

NetLogin* NetLogin::New(::google::protobuf::Arena* arena) const {
  NetLogin* n = new NetLogin;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void NetLogin::Clear() {
// @@protoc_insertion_point(message_clear_start:NetProto.NetLogin)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(!account_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*account_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(!token_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*token_.UnsafeRawStringPointer())->clear();
    }
  }
  if (cached_has_bits & 12u) {
    ::memset(&platform_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&serverid_) -
        reinterpret_cast<char*>(&platform_)) + sizeof(serverid_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool NetLogin::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:NetProto.NetLogin)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string account = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_account()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->account().data(), static_cast<int>(this->account().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "NetProto.NetLogin.account");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 platform = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          set_has_platform();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &platform_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string token = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_token()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->token().data(), static_cast<int>(this->token().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "NetProto.NetLogin.token");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 serverid = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          set_has_serverid();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &serverid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:NetProto.NetLogin)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:NetProto.NetLogin)
  return false;
#undef DO_
}

void NetLogin::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:NetProto.NetLogin)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string account = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->account().data(), static_cast<int>(this->account().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "NetProto.NetLogin.account");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->account(), output);
  }

  // optional int32 platform = 2;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->platform(), output);
  }

  // optional string token = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->token().data(), static_cast<int>(this->token().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "NetProto.NetLogin.token");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->token(), output);
  }

  // optional int32 serverid = 4;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->serverid(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:NetProto.NetLogin)
}

::google::protobuf::uint8* NetLogin::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:NetProto.NetLogin)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string account = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->account().data(), static_cast<int>(this->account().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "NetProto.NetLogin.account");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->account(), target);
  }

  // optional int32 platform = 2;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->platform(), target);
  }

  // optional string token = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->token().data(), static_cast<int>(this->token().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "NetProto.NetLogin.token");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->token(), target);
  }

  // optional int32 serverid = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->serverid(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:NetProto.NetLogin)
  return target;
}

size_t NetLogin::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:NetProto.NetLogin)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (_has_bits_[0 / 32] & 15u) {
    // optional string account = 1;
    if (has_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->account());
    }

    // optional string token = 3;
    if (has_token()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->token());
    }

    // optional int32 platform = 2;
    if (has_platform()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->platform());
    }

    // optional int32 serverid = 4;
    if (has_serverid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->serverid());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void NetLogin::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:NetProto.NetLogin)
  GOOGLE_DCHECK_NE(&from, this);
  const NetLogin* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const NetLogin>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:NetProto.NetLogin)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:NetProto.NetLogin)
    MergeFrom(*source);
  }
}

void NetLogin::MergeFrom(const NetLogin& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:NetProto.NetLogin)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_account();
      account_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.account_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_token();
      token_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.token_);
    }
    if (cached_has_bits & 0x00000004u) {
      platform_ = from.platform_;
    }
    if (cached_has_bits & 0x00000008u) {
      serverid_ = from.serverid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void NetLogin::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:NetProto.NetLogin)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NetLogin::CopyFrom(const NetLogin& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:NetProto.NetLogin)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NetLogin::IsInitialized() const {
  return true;
}

void NetLogin::Swap(NetLogin* other) {
  if (other == this) return;
  InternalSwap(other);
}
void NetLogin::InternalSwap(NetLogin* other) {
  using std::swap;
  account_.Swap(&other->account_);
  token_.Swap(&other->token_);
  swap(platform_, other->platform_);
  swap(serverid_, other->serverid_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata NetLogin::GetMetadata() const {
  protobuf_msg_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_msg_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// NetLogin

// optional string account = 1;
bool NetLogin::has_account() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void NetLogin::set_has_account() {
  _has_bits_[0] |= 0x00000001u;
}
void NetLogin::clear_has_account() {
  _has_bits_[0] &= ~0x00000001u;
}
void NetLogin::clear_account() {
  account_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_account();
}
const ::std::string& NetLogin::account() const {
  // @@protoc_insertion_point(field_get:NetProto.NetLogin.account)
  return account_.GetNoArena();
}
void NetLogin::set_account(const ::std::string& value) {
  set_has_account();
  account_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.NetLogin.account)
}
#if LANG_CXX11
void NetLogin::set_account(::std::string&& value) {
  set_has_account();
  account_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.NetLogin.account)
}
#endif
void NetLogin::set_account(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_account();
  account_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.NetLogin.account)
}
void NetLogin::set_account(const char* value, size_t size) {
  set_has_account();
  account_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.NetLogin.account)
}
::std::string* NetLogin::mutable_account() {
  set_has_account();
  // @@protoc_insertion_point(field_mutable:NetProto.NetLogin.account)
  return account_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* NetLogin::release_account() {
  // @@protoc_insertion_point(field_release:NetProto.NetLogin.account)
  clear_has_account();
  return account_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void NetLogin::set_allocated_account(::std::string* account) {
  if (account != NULL) {
    set_has_account();
  } else {
    clear_has_account();
  }
  account_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), account);
  // @@protoc_insertion_point(field_set_allocated:NetProto.NetLogin.account)
}

// optional int32 platform = 2;
bool NetLogin::has_platform() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
void NetLogin::set_has_platform() {
  _has_bits_[0] |= 0x00000004u;
}
void NetLogin::clear_has_platform() {
  _has_bits_[0] &= ~0x00000004u;
}
void NetLogin::clear_platform() {
  platform_ = 0;
  clear_has_platform();
}
::google::protobuf::int32 NetLogin::platform() const {
  // @@protoc_insertion_point(field_get:NetProto.NetLogin.platform)
  return platform_;
}
void NetLogin::set_platform(::google::protobuf::int32 value) {
  set_has_platform();
  platform_ = value;
  // @@protoc_insertion_point(field_set:NetProto.NetLogin.platform)
}

// optional string token = 3;
bool NetLogin::has_token() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void NetLogin::set_has_token() {
  _has_bits_[0] |= 0x00000002u;
}
void NetLogin::clear_has_token() {
  _has_bits_[0] &= ~0x00000002u;
}
void NetLogin::clear_token() {
  token_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_token();
}
const ::std::string& NetLogin::token() const {
  // @@protoc_insertion_point(field_get:NetProto.NetLogin.token)
  return token_.GetNoArena();
}
void NetLogin::set_token(const ::std::string& value) {
  set_has_token();
  token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.NetLogin.token)
}
#if LANG_CXX11
void NetLogin::set_token(::std::string&& value) {
  set_has_token();
  token_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.NetLogin.token)
}
#endif
void NetLogin::set_token(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_token();
  token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.NetLogin.token)
}
void NetLogin::set_token(const char* value, size_t size) {
  set_has_token();
  token_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.NetLogin.token)
}
::std::string* NetLogin::mutable_token() {
  set_has_token();
  // @@protoc_insertion_point(field_mutable:NetProto.NetLogin.token)
  return token_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* NetLogin::release_token() {
  // @@protoc_insertion_point(field_release:NetProto.NetLogin.token)
  clear_has_token();
  return token_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void NetLogin::set_allocated_token(::std::string* token) {
  if (token != NULL) {
    set_has_token();
  } else {
    clear_has_token();
  }
  token_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), token);
  // @@protoc_insertion_point(field_set_allocated:NetProto.NetLogin.token)
}

// optional int32 serverid = 4;
bool NetLogin::has_serverid() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
void NetLogin::set_has_serverid() {
  _has_bits_[0] |= 0x00000008u;
}
void NetLogin::clear_has_serverid() {
  _has_bits_[0] &= ~0x00000008u;
}
void NetLogin::clear_serverid() {
  serverid_ = 0;
  clear_has_serverid();
}
::google::protobuf::int32 NetLogin::serverid() const {
  // @@protoc_insertion_point(field_get:NetProto.NetLogin.serverid)
  return serverid_;
}
void NetLogin::set_serverid(::google::protobuf::int32 value) {
  set_has_serverid();
  serverid_ = value;
  // @@protoc_insertion_point(field_set:NetProto.NetLogin.serverid)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int NetCreateRole::kNameFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

NetCreateRole::NetCreateRole()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_msg_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:NetProto.NetCreateRole)
}
NetCreateRole::NetCreateRole(const NetCreateRole& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_name()) {
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  // @@protoc_insertion_point(copy_constructor:NetProto.NetCreateRole)
}

void NetCreateRole::SharedCtor() {
  _cached_size_ = 0;
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

NetCreateRole::~NetCreateRole() {
  // @@protoc_insertion_point(destructor:NetProto.NetCreateRole)
  SharedDtor();
}

void NetCreateRole::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void NetCreateRole::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* NetCreateRole::descriptor() {
  protobuf_msg_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_msg_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const NetCreateRole& NetCreateRole::default_instance() {
  protobuf_msg_2eproto::InitDefaults();
  return *internal_default_instance();
}

NetCreateRole* NetCreateRole::New(::google::protobuf::Arena* arena) const {
  NetCreateRole* n = new NetCreateRole;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void NetCreateRole::Clear() {
// @@protoc_insertion_point(message_clear_start:NetProto.NetCreateRole)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (has_name()) {
    GOOGLE_DCHECK(!name_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
    (*name_.UnsafeRawStringPointer())->clear();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool NetCreateRole::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:NetProto.NetCreateRole)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string name = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), static_cast<int>(this->name().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "NetProto.NetCreateRole.name");
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:NetProto.NetCreateRole)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:NetProto.NetCreateRole)
  return false;
#undef DO_
}

void NetCreateRole::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:NetProto.NetCreateRole)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string name = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "NetProto.NetCreateRole.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->name(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:NetProto.NetCreateRole)
}

::google::protobuf::uint8* NetCreateRole::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:NetProto.NetCreateRole)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional string name = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "NetProto.NetCreateRole.name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:NetProto.NetCreateRole)
  return target;
}

size_t NetCreateRole::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:NetProto.NetCreateRole)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // optional string name = 1;
  if (has_name()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void NetCreateRole::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:NetProto.NetCreateRole)
  GOOGLE_DCHECK_NE(&from, this);
  const NetCreateRole* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const NetCreateRole>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:NetProto.NetCreateRole)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:NetProto.NetCreateRole)
    MergeFrom(*source);
  }
}

void NetCreateRole::MergeFrom(const NetCreateRole& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:NetProto.NetCreateRole)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_name()) {
    set_has_name();
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
}

void NetCreateRole::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:NetProto.NetCreateRole)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NetCreateRole::CopyFrom(const NetCreateRole& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:NetProto.NetCreateRole)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NetCreateRole::IsInitialized() const {
  return true;
}

void NetCreateRole::Swap(NetCreateRole* other) {
  if (other == this) return;
  InternalSwap(other);
}
void NetCreateRole::InternalSwap(NetCreateRole* other) {
  using std::swap;
  name_.Swap(&other->name_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata NetCreateRole::GetMetadata() const {
  protobuf_msg_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_msg_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// NetCreateRole

// optional string name = 1;
bool NetCreateRole::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void NetCreateRole::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
void NetCreateRole::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
void NetCreateRole::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
const ::std::string& NetCreateRole::name() const {
  // @@protoc_insertion_point(field_get:NetProto.NetCreateRole.name)
  return name_.GetNoArena();
}
void NetCreateRole::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.NetCreateRole.name)
}
#if LANG_CXX11
void NetCreateRole::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.NetCreateRole.name)
}
#endif
void NetCreateRole::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.NetCreateRole.name)
}
void NetCreateRole::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.NetCreateRole.name)
}
::std::string* NetCreateRole::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:NetProto.NetCreateRole.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* NetCreateRole::release_name() {
  // @@protoc_insertion_point(field_release:NetProto.NetCreateRole.name)
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void NetCreateRole::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:NetProto.NetCreateRole.name)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace NetProto

// @@protoc_insertion_point(global_scope)
