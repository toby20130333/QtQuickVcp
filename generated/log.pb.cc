// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: log.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "log.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace pb {

namespace {

const ::google::protobuf::Descriptor* LogMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LogMessage_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_log_2eproto() {
  protobuf_AddDesc_log_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "log.proto");
  GOOGLE_CHECK(file != NULL);
  LogMessage_descriptor_ = file->message_type(0);
  static const int LogMessage_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogMessage, origin_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogMessage, pid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogMessage, level_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogMessage, tag_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogMessage, text_),
  };
  LogMessage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      LogMessage_descriptor_,
      LogMessage::default_instance_,
      LogMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogMessage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogMessage, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(LogMessage));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_log_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    LogMessage_descriptor_, &LogMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_log_2eproto() {
  delete LogMessage::default_instance_;
  delete LogMessage_reflection_;
}

void protobuf_AddDesc_log_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_nanopb_2eproto();
  ::pb::protobuf_AddDesc_types_2eproto();
  ::pb::protobuf_AddDesc_value_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\tlog.proto\022\002pb\032\014nanopb.proto\032\013types.pro"
    "to\032\013value.proto\"p\n\nLogMessage\022\035\n\006origin\030"
    "\n \002(\0162\r.pb.MsgOrigin\022\013\n\003pid\030\024 \002(\005\022\033\n\005lev"
    "el\030\036 \002(\0162\014.pb.MsgLevel\022\013\n\003tag\030( \002(\t\022\014\n\004t"
    "ext\0302 \002(\t", 169);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "log.proto", &protobuf_RegisterTypes);
  LogMessage::default_instance_ = new LogMessage();
  LogMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_log_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_log_2eproto {
  StaticDescriptorInitializer_log_2eproto() {
    protobuf_AddDesc_log_2eproto();
  }
} static_descriptor_initializer_log_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int LogMessage::kOriginFieldNumber;
const int LogMessage::kPidFieldNumber;
const int LogMessage::kLevelFieldNumber;
const int LogMessage::kTagFieldNumber;
const int LogMessage::kTextFieldNumber;
#endif  // !_MSC_VER

LogMessage::LogMessage()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void LogMessage::InitAsDefaultInstance() {
}

LogMessage::LogMessage(const LogMessage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void LogMessage::SharedCtor() {
  _cached_size_ = 0;
  origin_ = 0;
  pid_ = 0;
  level_ = 0;
  tag_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  text_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LogMessage::~LogMessage() {
  SharedDtor();
}

void LogMessage::SharedDtor() {
  if (tag_ != &::google::protobuf::internal::kEmptyString) {
    delete tag_;
  }
  if (text_ != &::google::protobuf::internal::kEmptyString) {
    delete text_;
  }
  if (this != default_instance_) {
  }
}

void LogMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LogMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LogMessage_descriptor_;
}

const LogMessage& LogMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_log_2eproto();
  return *default_instance_;
}

LogMessage* LogMessage::default_instance_ = NULL;

LogMessage* LogMessage::New() const {
  return new LogMessage;
}

void LogMessage::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    origin_ = 0;
    pid_ = 0;
    level_ = 0;
    if (has_tag()) {
      if (tag_ != &::google::protobuf::internal::kEmptyString) {
        tag_->clear();
      }
    }
    if (has_text()) {
      if (text_ != &::google::protobuf::internal::kEmptyString) {
        text_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool LogMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .pb.MsgOrigin origin = 10;
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::pb::MsgOrigin_IsValid(value)) {
            set_origin(static_cast< ::pb::MsgOrigin >(value));
          } else {
            mutable_unknown_fields()->AddVarint(10, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(160)) goto parse_pid;
        break;
      }

      // required int32 pid = 20;
      case 20: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_pid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &pid_)));
          set_has_pid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(240)) goto parse_level;
        break;
      }

      // required .pb.MsgLevel level = 30;
      case 30: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_level:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::pb::MsgLevel_IsValid(value)) {
            set_level(static_cast< ::pb::MsgLevel >(value));
          } else {
            mutable_unknown_fields()->AddVarint(30, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(322)) goto parse_tag;
        break;
      }

      // required string tag = 40;
      case 40: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_tag:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_tag()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->tag().data(), this->tag().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(402)) goto parse_text;
        break;
      }

      // required string text = 50;
      case 50: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_text:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_text()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->text().data(), this->text().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void LogMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .pb.MsgOrigin origin = 10;
  if (has_origin()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      10, this->origin(), output);
  }

  // required int32 pid = 20;
  if (has_pid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(20, this->pid(), output);
  }

  // required .pb.MsgLevel level = 30;
  if (has_level()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      30, this->level(), output);
  }

  // required string tag = 40;
  if (has_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->tag().data(), this->tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      40, this->tag(), output);
  }

  // required string text = 50;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      50, this->text(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* LogMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .pb.MsgOrigin origin = 10;
  if (has_origin()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      10, this->origin(), target);
  }

  // required int32 pid = 20;
  if (has_pid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(20, this->pid(), target);
  }

  // required .pb.MsgLevel level = 30;
  if (has_level()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      30, this->level(), target);
  }

  // required string tag = 40;
  if (has_tag()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->tag().data(), this->tag().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        40, this->tag(), target);
  }

  // required string text = 50;
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        50, this->text(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int LogMessage::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .pb.MsgOrigin origin = 10;
    if (has_origin()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->origin());
    }

    // required int32 pid = 20;
    if (has_pid()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->pid());
    }

    // required .pb.MsgLevel level = 30;
    if (has_level()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->level());
    }

    // required string tag = 40;
    if (has_tag()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->tag());
    }

    // required string text = 50;
    if (has_text()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->text());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void LogMessage::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const LogMessage* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const LogMessage*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void LogMessage::MergeFrom(const LogMessage& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_origin()) {
      set_origin(from.origin());
    }
    if (from.has_pid()) {
      set_pid(from.pid());
    }
    if (from.has_level()) {
      set_level(from.level());
    }
    if (from.has_tag()) {
      set_tag(from.tag());
    }
    if (from.has_text()) {
      set_text(from.text());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void LogMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LogMessage::CopyFrom(const LogMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LogMessage::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;

  return true;
}

void LogMessage::Swap(LogMessage* other) {
  if (other != this) {
    std::swap(origin_, other->origin_);
    std::swap(pid_, other->pid_);
    std::swap(level_, other->level_);
    std::swap(tag_, other->tag_);
    std::swap(text_, other->text_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata LogMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LogMessage_descriptor_;
  metadata.reflection = LogMessage_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb

// @@protoc_insertion_point(global_scope)