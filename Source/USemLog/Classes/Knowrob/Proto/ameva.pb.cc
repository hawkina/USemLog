// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ameva.proto
#pragma warning (disable : 4125)
#include "ameva.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_viz_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_DrawMarkerAtParams_viz_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_viz_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_DrawMarkerTrajParams_viz_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_tutorial_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_HelloWorldParams_tutorial_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_viz_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SetEpisodeParams_viz_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_viz_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SetTaskParams_viz_2eproto;
namespace sl_pb {
class KRAmevaEventDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<KRAmevaEvent> _instance;
} _KRAmevaEvent_default_instance_;
}  // namespace sl_pb
static void InitDefaultsscc_info_KRAmevaEvent_ameva_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::sl_pb::_KRAmevaEvent_default_instance_;
    new (ptr) ::sl_pb::KRAmevaEvent();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::sl_pb::KRAmevaEvent::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<5> scc_info_KRAmevaEvent_ameva_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 5, 0, InitDefaultsscc_info_KRAmevaEvent_ameva_2eproto}, {
      &scc_info_SetTaskParams_viz_2eproto.base,
      &scc_info_SetEpisodeParams_viz_2eproto.base,
      &scc_info_DrawMarkerAtParams_viz_2eproto.base,
      &scc_info_DrawMarkerTrajParams_viz_2eproto.base,
      &scc_info_HelloWorldParams_tutorial_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_ameva_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_ameva_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_ameva_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_ameva_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::sl_pb::KRAmevaEvent, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::sl_pb::KRAmevaEvent, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::sl_pb::KRAmevaEvent, functocall_),
  PROTOBUF_FIELD_OFFSET(::sl_pb::KRAmevaEvent, settaskparam_),
  PROTOBUF_FIELD_OFFSET(::sl_pb::KRAmevaEvent, setepisodeparams_),
  PROTOBUF_FIELD_OFFSET(::sl_pb::KRAmevaEvent, drawmarkeratparams_),
  PROTOBUF_FIELD_OFFSET(::sl_pb::KRAmevaEvent, drawmarkertrajparams_),
  PROTOBUF_FIELD_OFFSET(::sl_pb::KRAmevaEvent, helloworldparams_),
  5,
  0,
  1,
  2,
  3,
  4,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, sizeof(::sl_pb::KRAmevaEvent)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::sl_pb::_KRAmevaEvent_default_instance_),
};

const char descriptor_table_protodef_ameva_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\013ameva.proto\022\005sl_pb\032\tviz.proto\032\016tutoria"
  "l.proto\032\rcontrol.proto\"\247\003\n\014KRAmevaEvent\022"
  "2\n\nfuncToCall\030\001 \002(\0162\036.sl_pb.KRAmevaEvent"
  ".FuncToCall\022*\n\014setTaskParam\030\002 \001(\0132\024.sl_p"
  "b.SetTaskParams\0221\n\020setEpisodeParams\030\003 \001("
  "\0132\027.sl_pb.SetEpisodeParams\0225\n\022drawMarker"
  "AtParams\030\004 \001(\0132\031.sl_pb.DrawMarkerAtParam"
  "s\0229\n\024drawMarkerTrajParams\030\005 \001(\0132\033.sl_pb."
  "DrawMarkerTrajParams\0221\n\020HelloWorldParams"
  "\030\006 \001(\0132\027.sl_pb.HelloWorldParams\"_\n\nFuncT"
  "oCall\022\013\n\007SetTask\020\001\022\016\n\nSetEpisode\020\002\022\020\n\014Dr"
  "awMarkerAt\020\003\022\022\n\016DrawMarkerTraj\020\004\022\016\n\nHell"
  "oWorld\020\005"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_ameva_2eproto_deps[3] = {
  &::descriptor_table_control_2eproto,
  &::descriptor_table_tutorial_2eproto,
  &::descriptor_table_viz_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_ameva_2eproto_sccs[1] = {
  &scc_info_KRAmevaEvent_ameva_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_ameva_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ameva_2eproto = {
  false, false, descriptor_table_protodef_ameva_2eproto, "ameva.proto", 488,
  &descriptor_table_ameva_2eproto_once, descriptor_table_ameva_2eproto_sccs, descriptor_table_ameva_2eproto_deps, 1, 3,
  schemas, file_default_instances, TableStruct_ameva_2eproto::offsets,
  file_level_metadata_ameva_2eproto, 1, file_level_enum_descriptors_ameva_2eproto, file_level_service_descriptors_ameva_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_ameva_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_ameva_2eproto)), true);
namespace sl_pb {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* KRAmevaEvent_FuncToCall_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_ameva_2eproto);
  return file_level_enum_descriptors_ameva_2eproto[0];
}
bool KRAmevaEvent_FuncToCall_IsValid(int value) {
  switch (value) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr KRAmevaEvent_FuncToCall KRAmevaEvent::SetTask;
constexpr KRAmevaEvent_FuncToCall KRAmevaEvent::SetEpisode;
constexpr KRAmevaEvent_FuncToCall KRAmevaEvent::DrawMarkerAt;
constexpr KRAmevaEvent_FuncToCall KRAmevaEvent::DrawMarkerTraj;
constexpr KRAmevaEvent_FuncToCall KRAmevaEvent::HelloWorld;
constexpr KRAmevaEvent_FuncToCall KRAmevaEvent::FuncToCall_MIN;
constexpr KRAmevaEvent_FuncToCall KRAmevaEvent::FuncToCall_MAX;
constexpr int KRAmevaEvent::FuncToCall_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

void KRAmevaEvent::InitAsDefaultInstance() {
  ::sl_pb::_KRAmevaEvent_default_instance_._instance.get_mutable()->settaskparam_ = const_cast< ::sl_pb::SetTaskParams*>(
      ::sl_pb::SetTaskParams::internal_default_instance());
  ::sl_pb::_KRAmevaEvent_default_instance_._instance.get_mutable()->setepisodeparams_ = const_cast< ::sl_pb::SetEpisodeParams*>(
      ::sl_pb::SetEpisodeParams::internal_default_instance());
  ::sl_pb::_KRAmevaEvent_default_instance_._instance.get_mutable()->drawmarkeratparams_ = const_cast< ::sl_pb::DrawMarkerAtParams*>(
      ::sl_pb::DrawMarkerAtParams::internal_default_instance());
  ::sl_pb::_KRAmevaEvent_default_instance_._instance.get_mutable()->drawmarkertrajparams_ = const_cast< ::sl_pb::DrawMarkerTrajParams*>(
      ::sl_pb::DrawMarkerTrajParams::internal_default_instance());
  ::sl_pb::_KRAmevaEvent_default_instance_._instance.get_mutable()->helloworldparams_ = const_cast< ::sl_pb::HelloWorldParams*>(
      ::sl_pb::HelloWorldParams::internal_default_instance());
}
class KRAmevaEvent::_Internal {
 public:
  using HasBits = decltype(std::declval<KRAmevaEvent>()._has_bits_);
  static void set_has_functocall(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static const ::sl_pb::SetTaskParams& settaskparam(const KRAmevaEvent* msg);
  static void set_has_settaskparam(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static const ::sl_pb::SetEpisodeParams& setepisodeparams(const KRAmevaEvent* msg);
  static void set_has_setepisodeparams(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static const ::sl_pb::DrawMarkerAtParams& drawmarkeratparams(const KRAmevaEvent* msg);
  static void set_has_drawmarkeratparams(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static const ::sl_pb::DrawMarkerTrajParams& drawmarkertrajparams(const KRAmevaEvent* msg);
  static void set_has_drawmarkertrajparams(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static const ::sl_pb::HelloWorldParams& helloworldparams(const KRAmevaEvent* msg);
  static void set_has_helloworldparams(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000020) ^ 0x00000020) != 0;
  }
};

const ::sl_pb::SetTaskParams&
KRAmevaEvent::_Internal::settaskparam(const KRAmevaEvent* msg) {
  return *msg->settaskparam_;
}
const ::sl_pb::SetEpisodeParams&
KRAmevaEvent::_Internal::setepisodeparams(const KRAmevaEvent* msg) {
  return *msg->setepisodeparams_;
}
const ::sl_pb::DrawMarkerAtParams&
KRAmevaEvent::_Internal::drawmarkeratparams(const KRAmevaEvent* msg) {
  return *msg->drawmarkeratparams_;
}
const ::sl_pb::DrawMarkerTrajParams&
KRAmevaEvent::_Internal::drawmarkertrajparams(const KRAmevaEvent* msg) {
  return *msg->drawmarkertrajparams_;
}
const ::sl_pb::HelloWorldParams&
KRAmevaEvent::_Internal::helloworldparams(const KRAmevaEvent* msg) {
  return *msg->helloworldparams_;
}
void KRAmevaEvent::clear_settaskparam() {
  if (settaskparam_ != nullptr) settaskparam_->Clear();
  _has_bits_[0] &= ~0x00000001u;
}
void KRAmevaEvent::clear_setepisodeparams() {
  if (setepisodeparams_ != nullptr) setepisodeparams_->Clear();
  _has_bits_[0] &= ~0x00000002u;
}
void KRAmevaEvent::clear_drawmarkeratparams() {
  if (drawmarkeratparams_ != nullptr) drawmarkeratparams_->Clear();
  _has_bits_[0] &= ~0x00000004u;
}
void KRAmevaEvent::clear_drawmarkertrajparams() {
  if (drawmarkertrajparams_ != nullptr) drawmarkertrajparams_->Clear();
  _has_bits_[0] &= ~0x00000008u;
}
void KRAmevaEvent::clear_helloworldparams() {
  if (helloworldparams_ != nullptr) helloworldparams_->Clear();
  _has_bits_[0] &= ~0x00000010u;
}
KRAmevaEvent::KRAmevaEvent(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:sl_pb.KRAmevaEvent)
}
KRAmevaEvent::KRAmevaEvent(const KRAmevaEvent& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_settaskparam()) {
    settaskparam_ = new ::sl_pb::SetTaskParams(*from.settaskparam_);
  } else {
    settaskparam_ = nullptr;
  }
  if (from._internal_has_setepisodeparams()) {
    setepisodeparams_ = new ::sl_pb::SetEpisodeParams(*from.setepisodeparams_);
  } else {
    setepisodeparams_ = nullptr;
  }
  if (from._internal_has_drawmarkeratparams()) {
    drawmarkeratparams_ = new ::sl_pb::DrawMarkerAtParams(*from.drawmarkeratparams_);
  } else {
    drawmarkeratparams_ = nullptr;
  }
  if (from._internal_has_drawmarkertrajparams()) {
    drawmarkertrajparams_ = new ::sl_pb::DrawMarkerTrajParams(*from.drawmarkertrajparams_);
  } else {
    drawmarkertrajparams_ = nullptr;
  }
  if (from._internal_has_helloworldparams()) {
    helloworldparams_ = new ::sl_pb::HelloWorldParams(*from.helloworldparams_);
  } else {
    helloworldparams_ = nullptr;
  }
  functocall_ = from.functocall_;
  // @@protoc_insertion_point(copy_constructor:sl_pb.KRAmevaEvent)
}

void KRAmevaEvent::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_KRAmevaEvent_ameva_2eproto.base);
  ::memset(&settaskparam_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&helloworldparams_) -
      reinterpret_cast<char*>(&settaskparam_)) + sizeof(helloworldparams_));
  functocall_ = 1;
}

KRAmevaEvent::~KRAmevaEvent() {
  // @@protoc_insertion_point(destructor:sl_pb.KRAmevaEvent)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void KRAmevaEvent::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete settaskparam_;
  if (this != internal_default_instance()) delete setepisodeparams_;
  if (this != internal_default_instance()) delete drawmarkeratparams_;
  if (this != internal_default_instance()) delete drawmarkertrajparams_;
  if (this != internal_default_instance()) delete helloworldparams_;
}

void KRAmevaEvent::ArenaDtor(void* object) {
  KRAmevaEvent* _this = reinterpret_cast< KRAmevaEvent* >(object);
  (void)_this;
}
void KRAmevaEvent::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void KRAmevaEvent::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const KRAmevaEvent& KRAmevaEvent::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_KRAmevaEvent_ameva_2eproto.base);
  return *internal_default_instance();
}


void KRAmevaEvent::Clear() {
// @@protoc_insertion_point(message_clear_start:sl_pb.KRAmevaEvent)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(settaskparam_ != nullptr);
      settaskparam_->Clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(setepisodeparams_ != nullptr);
      setepisodeparams_->Clear();
    }
    if (cached_has_bits & 0x00000004u) {
      GOOGLE_DCHECK(drawmarkeratparams_ != nullptr);
      drawmarkeratparams_->Clear();
    }
    if (cached_has_bits & 0x00000008u) {
      GOOGLE_DCHECK(drawmarkertrajparams_ != nullptr);
      drawmarkertrajparams_->Clear();
    }
    if (cached_has_bits & 0x00000010u) {
      GOOGLE_DCHECK(helloworldparams_ != nullptr);
      helloworldparams_->Clear();
    }
    functocall_ = 1;
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* KRAmevaEvent::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required .sl_pb.KRAmevaEvent.FuncToCall funcToCall = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::sl_pb::KRAmevaEvent_FuncToCall_IsValid(val))) {
            _internal_set_functocall(static_cast<::sl_pb::KRAmevaEvent_FuncToCall>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(1, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // optional .sl_pb.SetTaskParams setTaskParam = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_settaskparam(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .sl_pb.SetEpisodeParams setEpisodeParams = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_setepisodeparams(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .sl_pb.DrawMarkerAtParams drawMarkerAtParams = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_drawmarkeratparams(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .sl_pb.DrawMarkerTrajParams drawMarkerTrajParams = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr = ctx->ParseMessage(_internal_mutable_drawmarkertrajparams(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional .sl_pb.HelloWorldParams HelloWorldParams = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          ptr = ctx->ParseMessage(_internal_mutable_helloworldparams(), ptr);
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
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* KRAmevaEvent::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:sl_pb.KRAmevaEvent)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .sl_pb.KRAmevaEvent.FuncToCall funcToCall = 1;
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_functocall(), target);
  }

  // optional .sl_pb.SetTaskParams setTaskParam = 2;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::settaskparam(this), target, stream);
  }

  // optional .sl_pb.SetEpisodeParams setEpisodeParams = 3;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        3, _Internal::setepisodeparams(this), target, stream);
  }

  // optional .sl_pb.DrawMarkerAtParams drawMarkerAtParams = 4;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        4, _Internal::drawmarkeratparams(this), target, stream);
  }

  // optional .sl_pb.DrawMarkerTrajParams drawMarkerTrajParams = 5;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        5, _Internal::drawmarkertrajparams(this), target, stream);
  }

  // optional .sl_pb.HelloWorldParams HelloWorldParams = 6;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        6, _Internal::helloworldparams(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:sl_pb.KRAmevaEvent)
  return target;
}

size_t KRAmevaEvent::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:sl_pb.KRAmevaEvent)
  size_t total_size = 0;

  // required .sl_pb.KRAmevaEvent.FuncToCall funcToCall = 1;
  if (_internal_has_functocall()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_functocall());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    // optional .sl_pb.SetTaskParams setTaskParam = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *settaskparam_);
    }

    // optional .sl_pb.SetEpisodeParams setEpisodeParams = 3;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *setepisodeparams_);
    }

    // optional .sl_pb.DrawMarkerAtParams drawMarkerAtParams = 4;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *drawmarkeratparams_);
    }

    // optional .sl_pb.DrawMarkerTrajParams drawMarkerTrajParams = 5;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *drawmarkertrajparams_);
    }

    // optional .sl_pb.HelloWorldParams HelloWorldParams = 6;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *helloworldparams_);
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void KRAmevaEvent::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:sl_pb.KRAmevaEvent)
  GOOGLE_DCHECK_NE(&from, this);
  const KRAmevaEvent* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<KRAmevaEvent>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:sl_pb.KRAmevaEvent)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:sl_pb.KRAmevaEvent)
    MergeFrom(*source);
  }
}

void KRAmevaEvent::MergeFrom(const KRAmevaEvent& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:sl_pb.KRAmevaEvent)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_mutable_settaskparam()->::sl_pb::SetTaskParams::MergeFrom(from._internal_settaskparam());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_mutable_setepisodeparams()->::sl_pb::SetEpisodeParams::MergeFrom(from._internal_setepisodeparams());
    }
    if (cached_has_bits & 0x00000004u) {
      _internal_mutable_drawmarkeratparams()->::sl_pb::DrawMarkerAtParams::MergeFrom(from._internal_drawmarkeratparams());
    }
    if (cached_has_bits & 0x00000008u) {
      _internal_mutable_drawmarkertrajparams()->::sl_pb::DrawMarkerTrajParams::MergeFrom(from._internal_drawmarkertrajparams());
    }
    if (cached_has_bits & 0x00000010u) {
      _internal_mutable_helloworldparams()->::sl_pb::HelloWorldParams::MergeFrom(from._internal_helloworldparams());
    }
    if (cached_has_bits & 0x00000020u) {
      functocall_ = from.functocall_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void KRAmevaEvent::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:sl_pb.KRAmevaEvent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void KRAmevaEvent::CopyFrom(const KRAmevaEvent& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:sl_pb.KRAmevaEvent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool KRAmevaEvent::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  if (_internal_has_settaskparam()) {
    if (!settaskparam_->IsInitialized()) return false;
  }
  if (_internal_has_setepisodeparams()) {
    if (!setepisodeparams_->IsInitialized()) return false;
  }
  if (_internal_has_drawmarkeratparams()) {
    if (!drawmarkeratparams_->IsInitialized()) return false;
  }
  if (_internal_has_drawmarkertrajparams()) {
    if (!drawmarkertrajparams_->IsInitialized()) return false;
  }
  if (_internal_has_helloworldparams()) {
    if (!helloworldparams_->IsInitialized()) return false;
  }
  return true;
}

void KRAmevaEvent::InternalSwap(KRAmevaEvent* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(KRAmevaEvent, helloworldparams_)
      + sizeof(KRAmevaEvent::helloworldparams_)
      - PROTOBUF_FIELD_OFFSET(KRAmevaEvent, settaskparam_)>(
          reinterpret_cast<char*>(&settaskparam_),
          reinterpret_cast<char*>(&other->settaskparam_));
  swap(functocall_, other->functocall_);
}

::PROTOBUF_NAMESPACE_ID::Metadata KRAmevaEvent::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace sl_pb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::sl_pb::KRAmevaEvent* Arena::CreateMaybeMessage< ::sl_pb::KRAmevaEvent >(Arena* arena) {
  return Arena::CreateMessageInternal< ::sl_pb::KRAmevaEvent >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
