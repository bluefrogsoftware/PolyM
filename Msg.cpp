#include "Msg.hpp"

#include <atomic>

namespace PolyM {

namespace {

MsgUID generateUniqueId()
{
    static std::atomic<MsgUID> i(0);
    return ++i;
}

}

Msg::Msg(unsigned long long msgId)
  : msgId_(msgId), uniqueId_(generateUniqueId())
{
}

std::unique_ptr<Msg> Msg::move()
{
    return std::unique_ptr<Msg>(new Msg(std::move(*this)));
}

unsigned long long Msg::getMsgId() const
{
    return msgId_;
}

MsgUID Msg::getUniqueId() const
{
    return uniqueId_;
}

}
