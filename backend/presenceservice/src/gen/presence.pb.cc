// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: presence.proto

#include "presence.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace presence {
class UpdateUserConnectionRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<UpdateUserConnectionRequest> _instance;
} _UpdateUserConnectionRequest_default_instance_;
class UpdateUserConnectionReplyDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<UpdateUserConnectionReply> _instance;
} _UpdateUserConnectionReply_default_instance_;
}  // namespace presence
static void InitDefaultsscc_info_UpdateUserConnectionReply_presence_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::presence::_UpdateUserConnectionReply_default_instance_;
    new (ptr) ::presence::UpdateUserConnectionReply();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::presence::UpdateUserConnectionReply::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_UpdateUserConnectionReply_presence_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_UpdateUserConnectionReply_presence_2eproto}, {}};

static void InitDefaultsscc_info_UpdateUserConnectionRequest_presence_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::presence::_UpdateUserConnectionRequest_default_instance_;
    new (ptr) ::presence::UpdateUserConnectionRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::presence::UpdateUserConnectionRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_UpdateUserConnectionRequest_presence_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_UpdateUserConnectionRequest_presence_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_presence_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_presence_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_presence_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_presence_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::presence::UpdateUserConnectionRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::presence::UpdateUserConnectionRequest, device_id_),
  PROTOBUF_FIELD_OFFSET(::presence::UpdateUserConnectionRequest, user_id_),
  PROTOBUF_FIELD_OFFSET(::presence::UpdateUserConnectionRequest, status_),
  PROTOBUF_FIELD_OFFSET(::presence::UpdateUserConnectionRequest, last_seen_timestamp_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::presence::UpdateUserConnectionReply, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::presence::UpdateUserConnectionReply, user_id_),
  PROTOBUF_FIELD_OFFSET(::presence::UpdateUserConnectionReply, status_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::presence::UpdateUserConnectionRequest)},
  { 9, -1, sizeof(::presence::UpdateUserConnectionReply)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::presence::_UpdateUserConnectionRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::presence::_UpdateUserConnectionReply_default_instance_),
};

const char descriptor_table_protodef_presence_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016presence.proto\022\010presence\"\212\001\n\033UpdateUse"
  "rConnectionRequest\022\021\n\tdevice_id\030\001 \001(\t\022\017\n"
  "\007user_id\030\002 \001(\t\022*\n\006status\030\003 \001(\0162\032.presenc"
  "e.ConnectionStatus\022\033\n\023last_seen_timestam"
  "p\030\004 \001(\003\"X\n\031UpdateUserConnectionReply\022\017\n\007"
  "user_id\030\001 \001(\t\022*\n\006status\030\002 \001(\0162\032.presence"
  ".ConnectionStatus*O\n\020ConnectionStatus\022\020\n"
  "\014UNDETERMINED\020\000\022\r\n\tCONNECTED\020\001\022\010\n\004AWAY\020\002"
  "\022\020\n\014DISCONNECTED\020\0032p\n\020PresenceRecorder\022\\"
  "\n\014UpdateStatus\022%.presence.UpdateUserConn"
  "ectionRequest\032#.presence.UpdateUserConne"
  "ctionReply\"\000b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_presence_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_presence_2eproto_sccs[2] = {
  &scc_info_UpdateUserConnectionReply_presence_2eproto.base,
  &scc_info_UpdateUserConnectionRequest_presence_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_presence_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_presence_2eproto = {
  false, false, descriptor_table_protodef_presence_2eproto, "presence.proto", 460,
  &descriptor_table_presence_2eproto_once, descriptor_table_presence_2eproto_sccs, descriptor_table_presence_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_presence_2eproto::offsets,
  file_level_metadata_presence_2eproto, 2, file_level_enum_descriptors_presence_2eproto, file_level_service_descriptors_presence_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_presence_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_presence_2eproto)), true);
namespace presence {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ConnectionStatus_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_presence_2eproto);
  return file_level_enum_descriptors_presence_2eproto[0];
}
bool ConnectionStatus_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void UpdateUserConnectionRequest::InitAsDefaultInstance() {
}
class UpdateUserConnectionRequest::_Internal {
 public:
};

UpdateUserConnectionRequest::UpdateUserConnectionRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:presence.UpdateUserConnectionRequest)
}
UpdateUserConnectionRequest::UpdateUserConnectionRequest(const UpdateUserConnectionRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  device_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_device_id().empty()) {
    device_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_device_id(),
      GetArena());
  }
  user_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_user_id().empty()) {
    user_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_user_id(),
      GetArena());
  }
  ::memcpy(&last_seen_timestamp_, &from.last_seen_timestamp_,
    static_cast<size_t>(reinterpret_cast<char*>(&status_) -
    reinterpret_cast<char*>(&last_seen_timestamp_)) + sizeof(status_));
  // @@protoc_insertion_point(copy_constructor:presence.UpdateUserConnectionRequest)
}

void UpdateUserConnectionRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_UpdateUserConnectionRequest_presence_2eproto.base);
  device_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  user_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&last_seen_timestamp_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&status_) -
      reinterpret_cast<char*>(&last_seen_timestamp_)) + sizeof(status_));
}

UpdateUserConnectionRequest::~UpdateUserConnectionRequest() {
  // @@protoc_insertion_point(destructor:presence.UpdateUserConnectionRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void UpdateUserConnectionRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  device_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  user_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void UpdateUserConnectionRequest::ArenaDtor(void* object) {
  UpdateUserConnectionRequest* _this = reinterpret_cast< UpdateUserConnectionRequest* >(object);
  (void)_this;
}
void UpdateUserConnectionRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void UpdateUserConnectionRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const UpdateUserConnectionRequest& UpdateUserConnectionRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_UpdateUserConnectionRequest_presence_2eproto.base);
  return *internal_default_instance();
}


void UpdateUserConnectionRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:presence.UpdateUserConnectionRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  device_id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  user_id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::memset(&last_seen_timestamp_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&status_) -
      reinterpret_cast<char*>(&last_seen_timestamp_)) + sizeof(status_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* UpdateUserConnectionRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string device_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_device_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "presence.UpdateUserConnectionRequest.device_id"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string user_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_user_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "presence.UpdateUserConnectionRequest.user_id"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .presence.ConnectionStatus status = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_status(static_cast<::presence::ConnectionStatus>(val));
        } else goto handle_unusual;
        continue;
      // int64 last_seen_timestamp = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          last_seen_timestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* UpdateUserConnectionRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:presence.UpdateUserConnectionRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string device_id = 1;
  if (this->device_id().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_device_id().data(), static_cast<int>(this->_internal_device_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "presence.UpdateUserConnectionRequest.device_id");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_device_id(), target);
  }

  // string user_id = 2;
  if (this->user_id().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_user_id().data(), static_cast<int>(this->_internal_user_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "presence.UpdateUserConnectionRequest.user_id");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_user_id(), target);
  }

  // .presence.ConnectionStatus status = 3;
  if (this->status() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      3, this->_internal_status(), target);
  }

  // int64 last_seen_timestamp = 4;
  if (this->last_seen_timestamp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(4, this->_internal_last_seen_timestamp(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:presence.UpdateUserConnectionRequest)
  return target;
}

size_t UpdateUserConnectionRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:presence.UpdateUserConnectionRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string device_id = 1;
  if (this->device_id().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_device_id());
  }

  // string user_id = 2;
  if (this->user_id().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_user_id());
  }

  // int64 last_seen_timestamp = 4;
  if (this->last_seen_timestamp() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_last_seen_timestamp());
  }

  // .presence.ConnectionStatus status = 3;
  if (this->status() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_status());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void UpdateUserConnectionRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:presence.UpdateUserConnectionRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const UpdateUserConnectionRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<UpdateUserConnectionRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:presence.UpdateUserConnectionRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:presence.UpdateUserConnectionRequest)
    MergeFrom(*source);
  }
}

void UpdateUserConnectionRequest::MergeFrom(const UpdateUserConnectionRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:presence.UpdateUserConnectionRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.device_id().size() > 0) {
    _internal_set_device_id(from._internal_device_id());
  }
  if (from.user_id().size() > 0) {
    _internal_set_user_id(from._internal_user_id());
  }
  if (from.last_seen_timestamp() != 0) {
    _internal_set_last_seen_timestamp(from._internal_last_seen_timestamp());
  }
  if (from.status() != 0) {
    _internal_set_status(from._internal_status());
  }
}

void UpdateUserConnectionRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:presence.UpdateUserConnectionRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateUserConnectionRequest::CopyFrom(const UpdateUserConnectionRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:presence.UpdateUserConnectionRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateUserConnectionRequest::IsInitialized() const {
  return true;
}

void UpdateUserConnectionRequest::InternalSwap(UpdateUserConnectionRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  device_id_.Swap(&other->device_id_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  user_id_.Swap(&other->user_id_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(UpdateUserConnectionRequest, status_)
      + sizeof(UpdateUserConnectionRequest::status_)
      - PROTOBUF_FIELD_OFFSET(UpdateUserConnectionRequest, last_seen_timestamp_)>(
          reinterpret_cast<char*>(&last_seen_timestamp_),
          reinterpret_cast<char*>(&other->last_seen_timestamp_));
}

::PROTOBUF_NAMESPACE_ID::Metadata UpdateUserConnectionRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void UpdateUserConnectionReply::InitAsDefaultInstance() {
}
class UpdateUserConnectionReply::_Internal {
 public:
};

UpdateUserConnectionReply::UpdateUserConnectionReply(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:presence.UpdateUserConnectionReply)
}
UpdateUserConnectionReply::UpdateUserConnectionReply(const UpdateUserConnectionReply& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  user_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_user_id().empty()) {
    user_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_user_id(),
      GetArena());
  }
  status_ = from.status_;
  // @@protoc_insertion_point(copy_constructor:presence.UpdateUserConnectionReply)
}

void UpdateUserConnectionReply::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_UpdateUserConnectionReply_presence_2eproto.base);
  user_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  status_ = 0;
}

UpdateUserConnectionReply::~UpdateUserConnectionReply() {
  // @@protoc_insertion_point(destructor:presence.UpdateUserConnectionReply)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void UpdateUserConnectionReply::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  user_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void UpdateUserConnectionReply::ArenaDtor(void* object) {
  UpdateUserConnectionReply* _this = reinterpret_cast< UpdateUserConnectionReply* >(object);
  (void)_this;
}
void UpdateUserConnectionReply::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void UpdateUserConnectionReply::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const UpdateUserConnectionReply& UpdateUserConnectionReply::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_UpdateUserConnectionReply_presence_2eproto.base);
  return *internal_default_instance();
}


void UpdateUserConnectionReply::Clear() {
// @@protoc_insertion_point(message_clear_start:presence.UpdateUserConnectionReply)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  user_id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  status_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* UpdateUserConnectionReply::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string user_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_user_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "presence.UpdateUserConnectionReply.user_id"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .presence.ConnectionStatus status = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_status(static_cast<::presence::ConnectionStatus>(val));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* UpdateUserConnectionReply::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:presence.UpdateUserConnectionReply)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string user_id = 1;
  if (this->user_id().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_user_id().data(), static_cast<int>(this->_internal_user_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "presence.UpdateUserConnectionReply.user_id");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_user_id(), target);
  }

  // .presence.ConnectionStatus status = 2;
  if (this->status() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      2, this->_internal_status(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:presence.UpdateUserConnectionReply)
  return target;
}

size_t UpdateUserConnectionReply::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:presence.UpdateUserConnectionReply)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string user_id = 1;
  if (this->user_id().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_user_id());
  }

  // .presence.ConnectionStatus status = 2;
  if (this->status() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_status());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void UpdateUserConnectionReply::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:presence.UpdateUserConnectionReply)
  GOOGLE_DCHECK_NE(&from, this);
  const UpdateUserConnectionReply* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<UpdateUserConnectionReply>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:presence.UpdateUserConnectionReply)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:presence.UpdateUserConnectionReply)
    MergeFrom(*source);
  }
}

void UpdateUserConnectionReply::MergeFrom(const UpdateUserConnectionReply& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:presence.UpdateUserConnectionReply)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.user_id().size() > 0) {
    _internal_set_user_id(from._internal_user_id());
  }
  if (from.status() != 0) {
    _internal_set_status(from._internal_status());
  }
}

void UpdateUserConnectionReply::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:presence.UpdateUserConnectionReply)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateUserConnectionReply::CopyFrom(const UpdateUserConnectionReply& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:presence.UpdateUserConnectionReply)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateUserConnectionReply::IsInitialized() const {
  return true;
}

void UpdateUserConnectionReply::InternalSwap(UpdateUserConnectionReply* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  user_id_.Swap(&other->user_id_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(status_, other->status_);
}

::PROTOBUF_NAMESPACE_ID::Metadata UpdateUserConnectionReply::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace presence
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::presence::UpdateUserConnectionRequest* Arena::CreateMaybeMessage< ::presence::UpdateUserConnectionRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::presence::UpdateUserConnectionRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::presence::UpdateUserConnectionReply* Arena::CreateMaybeMessage< ::presence::UpdateUserConnectionReply >(Arena* arena) {
  return Arena::CreateMessageInternal< ::presence::UpdateUserConnectionReply >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
