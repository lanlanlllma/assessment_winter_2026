#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace rmproto {

struct Frame {
    uint8_t version = 1;
    uint16_t seq    = 0;
    uint8_t type    = 0;
    std::vector<uint8_t> payload;
};

// CRC16-CCITT（poly=0x1021，init=0xFFFF）
uint16_t Crc16Ccitt(const uint8_t* data, size_t len);

// 将一帧序列化为字节序列。
// 线上的字节格式（字段为小端序）：
//   SOF[2] = 0xA5 0x5A
//   version[1]
//   payload_len[2]  （payload 的字节数）
//   seq[2]
//   type[1]
//   payload[payload_len]
//   crc16[2]  （覆盖 version..payload）
std::vector<uint8_t> Encode(const Frame& f);

// 尝试从字节流中解码出一帧。
// - 若找到一帧有效数据：设置 out 并返回 true，同时从 buffer 中移除已处理的字节。
// - 若数据不足：返回 false，并保持 buffer 不变。
// - 若数据无效：丢弃字节直到可能的 SOF，然后继续尝试。
bool TryDecode(std::vector<uint8_t>& buffer, Frame& out);

// CLI 辅助：解析十六进制字符串，例如 "A5 5A 01 00" 或 "a55a0100"。
bool ParseHexBytes(const std::string& text, std::vector<uint8_t>& out);
std::string ToHex(const std::vector<uint8_t>& bytes);

} // namespace rmproto
