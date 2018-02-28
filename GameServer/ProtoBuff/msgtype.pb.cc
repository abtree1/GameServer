// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msgtype.proto
#include "stdafx.h"
#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "msgtype.pb.h"

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
class NetMsgPackDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<NetMsgPack>
     _instance;
} _NetMsgPack_default_instance_;

namespace protobuf_msgtype_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[2];

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
};

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetMsgPack, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetMsgPack, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetMsgPack, type_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetMsgPack, msg_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NetMsgPack, code_),
  2,
  0,
  1,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(NetMsgPack)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_NetMsgPack_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "msgtype.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace
void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _NetMsgPack_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_NetMsgPack_default_instance_);}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\rmsgtype.proto\022\010NetProto\"5\n\nNetMsgPack\022"
      "\014\n\004type\030\001 \001(\005\022\013\n\003msg\030\002 \001(\t\022\014\n\004code\030\003 \001(\t"
      "*6\n\017Net_C2S_MsgType\022\020\n\014NET_C2S_Init\020\000\022\021\n"
      "\rNET_C2S_Login\020\001*#\n\017Net_S2C_MsgType\022\020\n\014N"
      "ET_S2C_Init\020\000"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 173);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "msgtype.proto", &protobuf_RegisterTypes);
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

}  // namespace protobuf_msgtype_2eproto

const ::google::protobuf::EnumDescriptor* Net_C2S_MsgType_descriptor() {
  protobuf_msgtype_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_msgtype_2eproto::file_level_enum_descriptors[0];
}
bool Net_C2S_MsgType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* Net_S2C_MsgType_descriptor() {
  protobuf_msgtype_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_msgtype_2eproto::file_level_enum_descriptors[1];
}
bool Net_S2C_MsgType_IsValid(int value) {
  switch (value) {
    case 0:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int NetMsgPack::kTypeFieldNumber;
const int NetMsgPack::kMsgFieldNumber;
const int NetMsgPack::kCodeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

NetMsgPack::NetMsgPack()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_msgtype_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:NetProto.NetMsgPack)
}
NetMsgPack::NetMsgPack(const NetMsgPack& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  msg_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_msg()) {
    msg_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.msg_);
  }
  code_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_code()) {
    code_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.code_);
  }
  type_ = from.type_;
  // @@protoc_insertion_point(copy_constructor:NetProto.NetMsgPack)
}

void NetMsgPack::SharedCtor() {
  _cached_size_ = 0;
  msg_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  code_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = 0;
}

NetMsgPack::~NetMsgPack() {
  // @@protoc_insertion_point(destructor:NetProto.NetMsgPack)
  SharedDtor();
}

void NetMsgPack::SharedDtor() {
  msg_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  code_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void NetMsgPack::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* NetMsgPack::descriptor() {
  protobuf_msgtype_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_msgtype_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const NetMsgPack& NetMsgPack::default_instance() {
  protobuf_msgtype_2eproto::InitDefaults();
  return *internal_default_instance();
}

NetMsgPack* NetMsgPack::New(::google::protobuf::Arena* arena) const {
  NetMsgPack* n = new NetMsgPack;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void NetMsgPack::Clear() {
// @@protoc_insertion_point(message_clear_start:NetProto.NetMsgPack)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(!msg_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*msg_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(!code_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*code_.UnsafeRawStringPointer())->clear();
    }
  }
  type_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool NetMsgPack::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:NetProto.NetMsgPack)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 type = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_type();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &type_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string msg = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_msg()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->msg().data(), static_cast<int>(this->msg().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "NetProto.NetMsgPack.msg");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string code = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_code()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->code().data(), static_cast<int>(this->code().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "NetProto.NetMsgPack.code");
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
  // @@protoc_insertion_point(parse_success:NetProto.NetMsgPack)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:NetProto.NetMsgPack)
  return false;
#undef DO_
}

void NetMsgPack::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:NetProto.NetMsgPack)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 type = 1;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->type(), output);
  }

  // optional string msg = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->msg().data(), static_cast<int>(this->msg().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "NetProto.NetMsgPack.msg");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->msg(), output);
  }

  // optional string code = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->code().data(), static_cast<int>(this->code().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "NetProto.NetMsgPack.code");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->code(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:NetProto.NetMsgPack)
}

::google::protobuf::uint8* NetMsgPack::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:NetProto.NetMsgPack)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 type = 1;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->type(), target);
  }

  // optional string msg = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->msg().data(), static_cast<int>(this->msg().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "NetProto.NetMsgPack.msg");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->msg(), target);
  }

  // optional string code = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->code().data(), static_cast<int>(this->code().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "NetProto.NetMsgPack.code");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->code(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:NetProto.NetMsgPack)
  return target;
}

size_t NetMsgPack::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:NetProto.NetMsgPack)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (_has_bits_[0 / 32] & 7u) {
    // optional string msg = 2;
    if (has_msg()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->msg());
    }

    // optional string code = 3;
    if (has_code()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->code());
    }

    // optional int32 type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->type());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void NetMsgPack::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:NetProto.NetMsgPack)
  GOOGLE_DCHECK_NE(&from, this);
  const NetMsgPack* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const NetMsgPack>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:NetProto.NetMsgPack)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:NetProto.NetMsgPack)
    MergeFrom(*source);
  }
}

void NetMsgPack::MergeFrom(const NetMsgPack& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:NetProto.NetMsgPack)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_msg();
      msg_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.msg_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_code();
      code_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.code_);
    }
    if (cached_has_bits & 0x00000004u) {
      type_ = from.type_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void NetMsgPack::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:NetProto.NetMsgPack)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NetMsgPack::CopyFrom(const NetMsgPack& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:NetProto.NetMsgPack)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NetMsgPack::IsInitialized() const {
  return true;
}

void NetMsgPack::Swap(NetMsgPack* other) {
  if (other == this) return;
  InternalSwap(other);
}
void NetMsgPack::InternalSwap(NetMsgPack* other) {
  using std::swap;
  msg_.Swap(&other->msg_);
  code_.Swap(&other->code_);
  swap(type_, other->type_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata NetMsgPack::GetMetadata() const {
  protobuf_msgtype_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_msgtype_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// NetMsgPack

// optional int32 type = 1;
bool NetMsgPack::has_type() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
void NetMsgPack::set_has_type() {
  _has_bits_[0] |= 0x00000004u;
}
void NetMsgPack::clear_has_type() {
  _has_bits_[0] &= ~0x00000004u;
}
void NetMsgPack::clear_type() {
  type_ = 0;
  clear_has_type();
}
::google::protobuf::int32 NetMsgPack::type() const {
  // @@protoc_insertion_point(field_get:NetProto.NetMsgPack.type)
  return type_;
}
void NetMsgPack::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:NetProto.NetMsgPack.type)
}

// optional string msg = 2;
bool NetMsgPack::has_msg() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void NetMsgPack::set_has_msg() {
  _has_bits_[0] |= 0x00000001u;
}
void NetMsgPack::clear_has_msg() {
  _has_bits_[0] &= ~0x00000001u;
}
void NetMsgPack::clear_msg() {
  msg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_msg();
}
const ::std::string& NetMsgPack::msg() const {
  // @@protoc_insertion_point(field_get:NetProto.NetMsgPack.msg)
  return msg_.GetNoArena();
}
void NetMsgPack::set_msg(const ::std::string& value) {
  set_has_msg();
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.NetMsgPack.msg)
}
#if LANG_CXX11
void NetMsgPack::set_msg(::std::string&& value) {
  set_has_msg();
  msg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.NetMsgPack.msg)
}
#endif
void NetMsgPack::set_msg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_msg();
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.NetMsgPack.msg)
}
void NetMsgPack::set_msg(const char* value, size_t size) {
  set_has_msg();
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.NetMsgPack.msg)
}
::std::string* NetMsgPack::mutable_msg() {
  set_has_msg();
  // @@protoc_insertion_point(field_mutable:NetProto.NetMsgPack.msg)
  return msg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* NetMsgPack::release_msg() {
  // @@protoc_insertion_point(field_release:NetProto.NetMsgPack.msg)
  clear_has_msg();
  return msg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void NetMsgPack::set_allocated_msg(::std::string* msg) {
  if (msg != NULL) {
    set_has_msg();
  } else {
    clear_has_msg();
  }
  msg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), msg);
  // @@protoc_insertion_point(field_set_allocated:NetProto.NetMsgPack.msg)
}

// optional string code = 3;
bool NetMsgPack::has_code() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void NetMsgPack::set_has_code() {
  _has_bits_[0] |= 0x00000002u;
}
void NetMsgPack::clear_has_code() {
  _has_bits_[0] &= ~0x00000002u;
}
void NetMsgPack::clear_code() {
  code_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_code();
}
const ::std::string& NetMsgPack::code() const {
  // @@protoc_insertion_point(field_get:NetProto.NetMsgPack.code)
  return code_.GetNoArena();
}
void NetMsgPack::set_code(const ::std::string& value) {
  set_has_code();
  code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NetProto.NetMsgPack.code)
}
#if LANG_CXX11
void NetMsgPack::set_code(::std::string&& value) {
  set_has_code();
  code_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NetProto.NetMsgPack.code)
}
#endif
void NetMsgPack::set_code(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_code();
  code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NetProto.NetMsgPack.code)
}
void NetMsgPack::set_code(const char* value, size_t size) {
  set_has_code();
  code_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NetProto.NetMsgPack.code)
}
::std::string* NetMsgPack::mutable_code() {
  set_has_code();
  // @@protoc_insertion_point(field_mutable:NetProto.NetMsgPack.code)
  return code_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* NetMsgPack::release_code() {
  // @@protoc_insertion_point(field_release:NetProto.NetMsgPack.code)
  clear_has_code();
  return code_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void NetMsgPack::set_allocated_code(::std::string* code) {
  if (code != NULL) {
    set_has_code();
  } else {
    clear_has_code();
  }
  code_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), code);
  // @@protoc_insertion_point(field_set_allocated:NetProto.NetMsgPack.code)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace NetProto

// @@protoc_insertion_point(global_scope)
