// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: info.proto

#include "info.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace sysinfo {

inline constexpr ServerResponse::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : msg_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR ServerResponse::ServerResponse(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct ServerResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ServerResponseDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ServerResponseDefaultTypeInternal() {}
  union {
    ServerResponse _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ServerResponseDefaultTypeInternal _ServerResponse_default_instance_;

inline constexpr Process::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : path_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        exefile_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        process_type_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        company_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        username_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        private_bytes_{::uint64_t{0u}},
        working_set_{::uint64_t{0u}},
        virtual_bytes_{::uint64_t{0u}},
        pid_{0u},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Process::Process(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct ProcessDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ProcessDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ProcessDefaultTypeInternal() {}
  union {
    Process _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ProcessDefaultTypeInternal _Process_default_instance_;
}  // namespace sysinfo
static ::_pb::Metadata file_level_metadata_info_2eproto[2];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_info_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_info_2eproto = nullptr;
const ::uint32_t TableStruct_info_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::sysinfo::Process, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::sysinfo::Process, _impl_.pid_),
    PROTOBUF_FIELD_OFFSET(::sysinfo::Process, _impl_.path_),
    PROTOBUF_FIELD_OFFSET(::sysinfo::Process, _impl_.exefile_),
    PROTOBUF_FIELD_OFFSET(::sysinfo::Process, _impl_.process_type_),
    PROTOBUF_FIELD_OFFSET(::sysinfo::Process, _impl_.company_),
    PROTOBUF_FIELD_OFFSET(::sysinfo::Process, _impl_.username_),
    PROTOBUF_FIELD_OFFSET(::sysinfo::Process, _impl_.private_bytes_),
    PROTOBUF_FIELD_OFFSET(::sysinfo::Process, _impl_.working_set_),
    PROTOBUF_FIELD_OFFSET(::sysinfo::Process, _impl_.virtual_bytes_),
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::sysinfo::ServerResponse, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::sysinfo::ServerResponse, _impl_.msg_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::sysinfo::Process)},
        {17, -1, -1, sizeof(::sysinfo::ServerResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::sysinfo::_Process_default_instance_._instance,
    &::sysinfo::_ServerResponse_default_instance_._instance,
};
const char descriptor_table_protodef_info_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\ninfo.proto\022\007sysinfo\"\261\001\n\007Process\022\013\n\003pid"
    "\030\001 \001(\r\022\014\n\004path\030\002 \001(\t\022\017\n\007exefile\030\003 \001(\t\022\024\n"
    "\014process_type\030\004 \001(\t\022\017\n\007company\030\005 \001(\t\022\020\n\010"
    "username\030\006 \001(\t\022\025\n\rprivate_bytes\030\007 \001(\004\022\023\n"
    "\013working_set\030\010 \001(\004\022\025\n\rvirtual_bytes\030\t \001("
    "\004\"\035\n\016ServerResponse\022\013\n\003msg\030\001 \001(\t2F\n\nSyst"
    "emInfo\0228\n\tProcesses\022\020.sysinfo.Process\032\027."
    "sysinfo.ServerResponse(\001b\006proto3"
};
static ::absl::once_flag descriptor_table_info_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_info_2eproto = {
    false,
    false,
    312,
    descriptor_table_protodef_info_2eproto,
    "info.proto",
    &descriptor_table_info_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_info_2eproto::offsets,
    file_level_metadata_info_2eproto,
    file_level_enum_descriptors_info_2eproto,
    file_level_service_descriptors_info_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_info_2eproto_getter() {
  return &descriptor_table_info_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_info_2eproto(&descriptor_table_info_2eproto);
namespace sysinfo {
// ===================================================================

class Process::_Internal {
 public:
};

Process::Process(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:sysinfo.Process)
}
inline PROTOBUF_NDEBUG_INLINE Process::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : path_(arena, from.path_),
        exefile_(arena, from.exefile_),
        process_type_(arena, from.process_type_),
        company_(arena, from.company_),
        username_(arena, from.username_),
        _cached_size_{0} {}

Process::Process(
    ::google::protobuf::Arena* arena,
    const Process& from)
    : ::google::protobuf::Message(arena) {
  Process* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, private_bytes_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, private_bytes_),
           offsetof(Impl_, pid_) -
               offsetof(Impl_, private_bytes_) +
               sizeof(Impl_::pid_));

  // @@protoc_insertion_point(copy_constructor:sysinfo.Process)
}
inline PROTOBUF_NDEBUG_INLINE Process::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : path_(arena),
        exefile_(arena),
        process_type_(arena),
        company_(arena),
        username_(arena),
        _cached_size_{0} {}

inline void Process::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, private_bytes_),
           0,
           offsetof(Impl_, pid_) -
               offsetof(Impl_, private_bytes_) +
               sizeof(Impl_::pid_));
}
Process::~Process() {
  // @@protoc_insertion_point(destructor:sysinfo.Process)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Process::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.path_.Destroy();
  _impl_.exefile_.Destroy();
  _impl_.process_type_.Destroy();
  _impl_.company_.Destroy();
  _impl_.username_.Destroy();
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void Process::Clear() {
// @@protoc_insertion_point(message_clear_start:sysinfo.Process)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.path_.ClearToEmpty();
  _impl_.exefile_.ClearToEmpty();
  _impl_.process_type_.ClearToEmpty();
  _impl_.company_.ClearToEmpty();
  _impl_.username_.ClearToEmpty();
  ::memset(&_impl_.private_bytes_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.pid_) -
      reinterpret_cast<char*>(&_impl_.private_bytes_)) + sizeof(_impl_.pid_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Process::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<4, 9, 0, 70, 2> Process::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    9, 120,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294966784,  // skipmap
    offsetof(decltype(_table_), field_entries),
    9,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Process_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // uint32 pid = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Process, _impl_.pid_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(Process, _impl_.pid_)}},
    // string path = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(Process, _impl_.path_)}},
    // string exefile = 3;
    {::_pbi::TcParser::FastUS1,
     {26, 63, 0, PROTOBUF_FIELD_OFFSET(Process, _impl_.exefile_)}},
    // string process_type = 4;
    {::_pbi::TcParser::FastUS1,
     {34, 63, 0, PROTOBUF_FIELD_OFFSET(Process, _impl_.process_type_)}},
    // string company = 5;
    {::_pbi::TcParser::FastUS1,
     {42, 63, 0, PROTOBUF_FIELD_OFFSET(Process, _impl_.company_)}},
    // string username = 6;
    {::_pbi::TcParser::FastUS1,
     {50, 63, 0, PROTOBUF_FIELD_OFFSET(Process, _impl_.username_)}},
    // uint64 private_bytes = 7;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(Process, _impl_.private_bytes_), 63>(),
     {56, 63, 0, PROTOBUF_FIELD_OFFSET(Process, _impl_.private_bytes_)}},
    // uint64 working_set = 8;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(Process, _impl_.working_set_), 63>(),
     {64, 63, 0, PROTOBUF_FIELD_OFFSET(Process, _impl_.working_set_)}},
    // uint64 virtual_bytes = 9;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(Process, _impl_.virtual_bytes_), 63>(),
     {72, 63, 0, PROTOBUF_FIELD_OFFSET(Process, _impl_.virtual_bytes_)}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // uint32 pid = 1;
    {PROTOBUF_FIELD_OFFSET(Process, _impl_.pid_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt32)},
    // string path = 2;
    {PROTOBUF_FIELD_OFFSET(Process, _impl_.path_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string exefile = 3;
    {PROTOBUF_FIELD_OFFSET(Process, _impl_.exefile_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string process_type = 4;
    {PROTOBUF_FIELD_OFFSET(Process, _impl_.process_type_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string company = 5;
    {PROTOBUF_FIELD_OFFSET(Process, _impl_.company_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string username = 6;
    {PROTOBUF_FIELD_OFFSET(Process, _impl_.username_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // uint64 private_bytes = 7;
    {PROTOBUF_FIELD_OFFSET(Process, _impl_.private_bytes_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt64)},
    // uint64 working_set = 8;
    {PROTOBUF_FIELD_OFFSET(Process, _impl_.working_set_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt64)},
    // uint64 virtual_bytes = 9;
    {PROTOBUF_FIELD_OFFSET(Process, _impl_.virtual_bytes_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt64)},
  }},
  // no aux_entries
  {{
    "\17\0\4\7\14\7\10\0\0\0\0\0\0\0\0\0"
    "sysinfo.Process"
    "path"
    "exefile"
    "process_type"
    "company"
    "username"
  }},
};

::uint8_t* Process::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:sysinfo.Process)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // uint32 pid = 1;
  if (this->_internal_pid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(
        1, this->_internal_pid(), target);
  }

  // string path = 2;
  if (!this->_internal_path().empty()) {
    const std::string& _s = this->_internal_path();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "sysinfo.Process.path");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  // string exefile = 3;
  if (!this->_internal_exefile().empty()) {
    const std::string& _s = this->_internal_exefile();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "sysinfo.Process.exefile");
    target = stream->WriteStringMaybeAliased(3, _s, target);
  }

  // string process_type = 4;
  if (!this->_internal_process_type().empty()) {
    const std::string& _s = this->_internal_process_type();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "sysinfo.Process.process_type");
    target = stream->WriteStringMaybeAliased(4, _s, target);
  }

  // string company = 5;
  if (!this->_internal_company().empty()) {
    const std::string& _s = this->_internal_company();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "sysinfo.Process.company");
    target = stream->WriteStringMaybeAliased(5, _s, target);
  }

  // string username = 6;
  if (!this->_internal_username().empty()) {
    const std::string& _s = this->_internal_username();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "sysinfo.Process.username");
    target = stream->WriteStringMaybeAliased(6, _s, target);
  }

  // uint64 private_bytes = 7;
  if (this->_internal_private_bytes() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(
        7, this->_internal_private_bytes(), target);
  }

  // uint64 working_set = 8;
  if (this->_internal_working_set() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(
        8, this->_internal_working_set(), target);
  }

  // uint64 virtual_bytes = 9;
  if (this->_internal_virtual_bytes() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(
        9, this->_internal_virtual_bytes(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:sysinfo.Process)
  return target;
}

::size_t Process::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:sysinfo.Process)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string path = 2;
  if (!this->_internal_path().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_path());
  }

  // string exefile = 3;
  if (!this->_internal_exefile().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_exefile());
  }

  // string process_type = 4;
  if (!this->_internal_process_type().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_process_type());
  }

  // string company = 5;
  if (!this->_internal_company().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_company());
  }

  // string username = 6;
  if (!this->_internal_username().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_username());
  }

  // uint64 private_bytes = 7;
  if (this->_internal_private_bytes() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(
        this->_internal_private_bytes());
  }

  // uint64 working_set = 8;
  if (this->_internal_working_set() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(
        this->_internal_working_set());
  }

  // uint64 virtual_bytes = 9;
  if (this->_internal_virtual_bytes() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(
        this->_internal_virtual_bytes());
  }

  // uint32 pid = 1;
  if (this->_internal_pid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(
        this->_internal_pid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData Process::_class_data_ = {
    Process::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* Process::GetClassData() const {
  return &_class_data_;
}

void Process::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<Process*>(&to_msg);
  auto& from = static_cast<const Process&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:sysinfo.Process)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_path().empty()) {
    _this->_internal_set_path(from._internal_path());
  }
  if (!from._internal_exefile().empty()) {
    _this->_internal_set_exefile(from._internal_exefile());
  }
  if (!from._internal_process_type().empty()) {
    _this->_internal_set_process_type(from._internal_process_type());
  }
  if (!from._internal_company().empty()) {
    _this->_internal_set_company(from._internal_company());
  }
  if (!from._internal_username().empty()) {
    _this->_internal_set_username(from._internal_username());
  }
  if (from._internal_private_bytes() != 0) {
    _this->_internal_set_private_bytes(from._internal_private_bytes());
  }
  if (from._internal_working_set() != 0) {
    _this->_internal_set_working_set(from._internal_working_set());
  }
  if (from._internal_virtual_bytes() != 0) {
    _this->_internal_set_virtual_bytes(from._internal_virtual_bytes());
  }
  if (from._internal_pid() != 0) {
    _this->_internal_set_pid(from._internal_pid());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Process::CopyFrom(const Process& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:sysinfo.Process)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Process::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* Process::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void Process::InternalSwap(Process* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.path_, &other->_impl_.path_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.exefile_, &other->_impl_.exefile_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.process_type_, &other->_impl_.process_type_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.company_, &other->_impl_.company_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.username_, &other->_impl_.username_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Process, _impl_.pid_)
      + sizeof(Process::_impl_.pid_)
      - PROTOBUF_FIELD_OFFSET(Process, _impl_.private_bytes_)>(
          reinterpret_cast<char*>(&_impl_.private_bytes_),
          reinterpret_cast<char*>(&other->_impl_.private_bytes_));
}

::google::protobuf::Metadata Process::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_info_2eproto_getter, &descriptor_table_info_2eproto_once,
      file_level_metadata_info_2eproto[0]);
}
// ===================================================================

class ServerResponse::_Internal {
 public:
};

ServerResponse::ServerResponse(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:sysinfo.ServerResponse)
}
inline PROTOBUF_NDEBUG_INLINE ServerResponse::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : msg_(arena, from.msg_),
        _cached_size_{0} {}

ServerResponse::ServerResponse(
    ::google::protobuf::Arena* arena,
    const ServerResponse& from)
    : ::google::protobuf::Message(arena) {
  ServerResponse* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);

  // @@protoc_insertion_point(copy_constructor:sysinfo.ServerResponse)
}
inline PROTOBUF_NDEBUG_INLINE ServerResponse::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : msg_(arena),
        _cached_size_{0} {}

inline void ServerResponse::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
ServerResponse::~ServerResponse() {
  // @@protoc_insertion_point(destructor:sysinfo.ServerResponse)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void ServerResponse::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.msg_.Destroy();
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void ServerResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:sysinfo.ServerResponse)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.msg_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* ServerResponse::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 34, 2> ServerResponse::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_ServerResponse_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // string msg = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(ServerResponse, _impl_.msg_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string msg = 1;
    {PROTOBUF_FIELD_OFFSET(ServerResponse, _impl_.msg_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\26\3\0\0\0\0\0\0"
    "sysinfo.ServerResponse"
    "msg"
  }},
};

::uint8_t* ServerResponse::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:sysinfo.ServerResponse)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string msg = 1;
  if (!this->_internal_msg().empty()) {
    const std::string& _s = this->_internal_msg();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "sysinfo.ServerResponse.msg");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:sysinfo.ServerResponse)
  return target;
}

::size_t ServerResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:sysinfo.ServerResponse)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string msg = 1;
  if (!this->_internal_msg().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_msg());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData ServerResponse::_class_data_ = {
    ServerResponse::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* ServerResponse::GetClassData() const {
  return &_class_data_;
}

void ServerResponse::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<ServerResponse*>(&to_msg);
  auto& from = static_cast<const ServerResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:sysinfo.ServerResponse)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_msg().empty()) {
    _this->_internal_set_msg(from._internal_msg());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void ServerResponse::CopyFrom(const ServerResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:sysinfo.ServerResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool ServerResponse::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* ServerResponse::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void ServerResponse::InternalSwap(ServerResponse* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.msg_, &other->_impl_.msg_, arena);
}

::google::protobuf::Metadata ServerResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_info_2eproto_getter, &descriptor_table_info_2eproto_once,
      file_level_metadata_info_2eproto[1]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace sysinfo
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
