/***************************************************************************
* Copyright (c) 2017, Nico Caprioli                                        *
*                                                                          *
* Distributed under the terms of the LGPLv3 License.                       *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/
#pragma once
#ifndef WEB_BINARY_COMPRESSION_ATTRIBUTES_VALUES_CHARSETS_H
#define WEB_BINARY_COMPRESSION_ATTRIBUTES_VALUES_CHARSETS_H
#include <memory>
#include <unordered_map>
#include "NumericLiterals.hpp"
#include "attributes/types/Charset.hpp"

namespace WebBinaryCompression::Attributes::Values::Charsets {
using namespace std::string_view_literals;
/**
 * \brief Maps all \link Types::Charset \endlink names to their equivalent.
 */
const std::unordered_map<std::string_view, std::shared_ptr<Types::Charset>,
                         Types::CharsetHasher> elements = {
  {
    "utf-8"sv,
    std::make_shared<Types::Charset>(0x06_uint8)
  },
  {
    "adobe-standard-encoding"sv,
    std::make_shared<Types::Charset>(0x07_uint8)
  },
  {
    "adobe-symbol-encoding"sv,
    std::make_shared<Types::Charset>(0x08_uint8)
  },
  {
    "amiga-1251"sv,
    std::make_shared<Types::Charset>(0x09_uint8)
  },
  {
    "ansi_x3.110-1983"sv,
    std::make_shared<Types::Charset>(0x0A_uint8)
  },
  {
    "asmo_449"sv,
    std::make_shared<Types::Charset>(0x0B_uint8)
  },
  {
    "big5"sv,
    std::make_shared<Types::Charset>(0x0C_uint8)
  },
  {
    "big5-hkscs"sv,
    std::make_shared<Types::Charset>(0x0D_uint8)
  },
  {
    "bocu-1"sv,
    std::make_shared<Types::Charset>(0x0E_uint8)
  },
  {
    "brf"sv,
    std::make_shared<Types::Charset>(0x0F_uint8)
  },
  {
    "bs_4730"sv,
    std::make_shared<Types::Charset>(0x10_uint8)
  },
  {
    "bs_viewdata"sv,
    std::make_shared<Types::Charset>(0x11_uint8)
  },
  {
    "cesu-8"sv,
    std::make_shared<Types::Charset>(0x12_uint8)
  },
  {
    "cp50220"sv,
    std::make_shared<Types::Charset>(0x13_uint8)
  },
  {
    "cp51932"sv,
    std::make_shared<Types::Charset>(0x14_uint8)
  },
  {
    "csa_z243.4-1985-1"sv,
    std::make_shared<Types::Charset>(0x15_uint8)
  },
  {
    "csa_z243.4-1985-2"sv,
    std::make_shared<Types::Charset>(0x16_uint8)
  },
  {
    "csa_z243.4-1985-gr"sv,
    std::make_shared<Types::Charset>(0x17_uint8)
  },
  {
    "csn_369103"sv,
    std::make_shared<Types::Charset>(0x18_uint8)
  },
  {
    "dec-mcs"sv,
    std::make_shared<Types::Charset>(0x19_uint8)
  },
  {
    "din_66003"sv,
    std::make_shared<Types::Charset>(0x1A_uint8)
  },
  {
    "dk-us"sv,
    std::make_shared<Types::Charset>(0x1B_uint8)
  },
  {
    "ds_2089"sv,
    std::make_shared<Types::Charset>(0x1C_uint8)
  },
  {
    "ebcdic-at-de"sv,
    std::make_shared<Types::Charset>(0x1D_uint8)
  },
  {
    "ebcdic-at-de-a"sv,
    std::make_shared<Types::Charset>(0x1E_uint8)
  },
  {
    "ebcdic-ca-fr"sv,
    std::make_shared<Types::Charset>(0x1F_uint8)
  },
  {
    "ebcdic-dk-no"sv,
    std::make_shared<Types::Charset>(0x20_uint8)
  },
  {
    "ebcdic-dk-no-a"sv,
    std::make_shared<Types::Charset>(0x21_uint8)
  },
  {
    "ebcdic-es"sv,
    std::make_shared<Types::Charset>(0x22_uint8)
  },
  {
    "ebcdic-es-a"sv,
    std::make_shared<Types::Charset>(0x23_uint8)
  },
  {
    "ebcdic-es-s"sv,
    std::make_shared<Types::Charset>(0x24_uint8)
  },
  {
    "ebcdic-fi-se"sv,
    std::make_shared<Types::Charset>(0x25_uint8)
  },
  {
    "ebcdic-fi-se-a"sv,
    std::make_shared<Types::Charset>(0x26_uint8)
  },
  {
    "ebcdic-fr"sv,
    std::make_shared<Types::Charset>(0x27_uint8)
  },
  {
    "ebcdic-it"sv,
    std::make_shared<Types::Charset>(0x28_uint8)
  },
  {
    "ebcdic-pt"sv,
    std::make_shared<Types::Charset>(0x29_uint8)
  },
  {
    "ebcdic-uk"sv,
    std::make_shared<Types::Charset>(0x2A_uint8)
  },
  {
    "ebcdic-us"sv,
    std::make_shared<Types::Charset>(0x2B_uint8)
  },
  {
    "ecma-cyrillic"sv,
    std::make_shared<Types::Charset>(0x2C_uint8)
  },
  {
    "es"sv,
    std::make_shared<Types::Charset>(0x2D_uint8)
  },
  {
    "es2"sv,
    std::make_shared<Types::Charset>(0x2E_uint8)
  },
  {
    "euc-jp"sv,
    std::make_shared<Types::Charset>(0x2F_uint8)
  },
  {
    "euc-kr"sv,
    std::make_shared<Types::Charset>(0x30_uint8)
  },
  {
    "gb_1988-80"sv,
    std::make_shared<Types::Charset>(0x31_uint8)
  },
  {
    "gb_2312-80"sv,
    std::make_shared<Types::Charset>(0x32_uint8)
  },
  {
    "gb18030"sv,
    std::make_shared<Types::Charset>(0x33_uint8)
  },
  {
    "gb2312"sv,
    std::make_shared<Types::Charset>(0x34_uint8)
  },
  {
    "gbk"sv,
    std::make_shared<Types::Charset>(0x35_uint8)
  },
  {
    "gost_19768-74"sv,
    std::make_shared<Types::Charset>(0x36_uint8)
  },
  {
    "greek7"sv,
    std::make_shared<Types::Charset>(0x37_uint8)
  },
  {
    "greek7-old"sv,
    std::make_shared<Types::Charset>(0x38_uint8)
  },
  {
    "greek-ccitt"sv,
    std::make_shared<Types::Charset>(0x39_uint8)
  },
  {
    "hp-desktop"sv,
    std::make_shared<Types::Charset>(0x3A_uint8)
  },
  {
    "hp-legal"sv,
    std::make_shared<Types::Charset>(0x3B_uint8)
  },
  {
    "hp-math8"sv,
    std::make_shared<Types::Charset>(0x3C_uint8)
  },
  {
    "hp-pi-font"sv,
    std::make_shared<Types::Charset>(0x3D_uint8)
  },
  {
    "hp-roman8"sv,
    std::make_shared<Types::Charset>(0x3E_uint8)
  },
  {
    "hz-gb-2312"sv,
    std::make_shared<Types::Charset>(0x3F_uint8)
  },
  {
    "ibm00858"sv,
    std::make_shared<Types::Charset>(0x40_uint8)
  },
  {
    "ibm00924"sv,
    std::make_shared<Types::Charset>(0x41_uint8)
  },
  {
    "ibm01140"sv,
    std::make_shared<Types::Charset>(0x42_uint8)
  },
  {
    "ibm01141"sv,
    std::make_shared<Types::Charset>(0x43_uint8)
  },
  {
    "ibm01142"sv,
    std::make_shared<Types::Charset>(0x44_uint8)
  },
  {
    "ibm01143"sv,
    std::make_shared<Types::Charset>(0x45_uint8)
  },
  {
    "ibm01144"sv,
    std::make_shared<Types::Charset>(0x46_uint8)
  },
  {
    "ibm01145"sv,
    std::make_shared<Types::Charset>(0x47_uint8)
  },
  {
    "ibm01146"sv,
    std::make_shared<Types::Charset>(0x48_uint8)
  },
  {
    "ibm01147"sv,
    std::make_shared<Types::Charset>(0x49_uint8)
  },
  {
    "ibm01148"sv,
    std::make_shared<Types::Charset>(0x4A_uint8)
  },
  {
    "ibm01149"sv,
    std::make_shared<Types::Charset>(0x4B_uint8)
  },
  {
    "ibm037"sv,
    std::make_shared<Types::Charset>(0x4C_uint8)
  },
  {
    "ibm038"sv,
    std::make_shared<Types::Charset>(0x4D_uint8)
  },
  {
    "ibm1026"sv,
    std::make_shared<Types::Charset>(0x4E_uint8)
  },
  {
    "ibm1047"sv,
    std::make_shared<Types::Charset>(0x4F_uint8)
  },
  {
    "ibm273"sv,
    std::make_shared<Types::Charset>(0x50_uint8)
  },
  {
    "ibm274"sv,
    std::make_shared<Types::Charset>(0x51_uint8)
  },
  {
    "ibm275"sv,
    std::make_shared<Types::Charset>(0x52_uint8)
  },
  {
    "ibm277"sv,
    std::make_shared<Types::Charset>(0x53_uint8)
  },
  {
    "ibm278"sv,
    std::make_shared<Types::Charset>(0x54_uint8)
  },
  {
    "ibm280"sv,
    std::make_shared<Types::Charset>(0x55_uint8)
  },
  {
    "ibm281"sv,
    std::make_shared<Types::Charset>(0x56_uint8)
  },
  {
    "ibm284"sv,
    std::make_shared<Types::Charset>(0x57_uint8)
  },
  {
    "ibm285"sv,
    std::make_shared<Types::Charset>(0x58_uint8)
  },
  {
    "ibm290"sv,
    std::make_shared<Types::Charset>(0x59_uint8)
  },
  {
    "ibm297"sv,
    std::make_shared<Types::Charset>(0x5A_uint8)
  },
  {
    "ibm420"sv,
    std::make_shared<Types::Charset>(0x5B_uint8)
  },
  {
    "ibm423"sv,
    std::make_shared<Types::Charset>(0x5C_uint8)
  },
  {
    "ibm424"sv,
    std::make_shared<Types::Charset>(0x5D_uint8)
  },
  {
    "ibm437"sv,
    std::make_shared<Types::Charset>(0x5E_uint8)
  },
  {
    "ibm500"sv,
    std::make_shared<Types::Charset>(0x5F_uint8)
  },
  {
    "ibm775"sv,
    std::make_shared<Types::Charset>(0x60_uint8)
  },
  {
    "ibm850"sv,
    std::make_shared<Types::Charset>(0x61_uint8)
  },
  {
    "ibm851"sv,
    std::make_shared<Types::Charset>(0x62_uint8)
  },
  {
    "ibm852"sv,
    std::make_shared<Types::Charset>(0x63_uint8)
  },
  {
    "ibm855"sv,
    std::make_shared<Types::Charset>(0x64_uint8)
  },
  {
    "ibm857"sv,
    std::make_shared<Types::Charset>(0x65_uint8)
  },
  {
    "ibm860"sv,
    std::make_shared<Types::Charset>(0x66_uint8)
  },
  {
    "ibm861"sv,
    std::make_shared<Types::Charset>(0x67_uint8)
  },
  {
    "ibm862"sv,
    std::make_shared<Types::Charset>(0x68_uint8)
  },
  {
    "ibm863"sv,
    std::make_shared<Types::Charset>(0x69_uint8)
  },
  {
    "ibm864"sv,
    std::make_shared<Types::Charset>(0x6A_uint8)
  },
  {
    "ibm865"sv,
    std::make_shared<Types::Charset>(0x6B_uint8)
  },
  {
    "ibm866"sv,
    std::make_shared<Types::Charset>(0x6C_uint8)
  },
  {
    "ibm868"sv,
    std::make_shared<Types::Charset>(0x6D_uint8)
  },
  {
    "ibm869"sv,
    std::make_shared<Types::Charset>(0x6E_uint8)
  },
  {
    "ibm870"sv,
    std::make_shared<Types::Charset>(0x6F_uint8)
  },
  {
    "ibm871"sv,
    std::make_shared<Types::Charset>(0x70_uint8)
  },
  {
    "ibm880"sv,
    std::make_shared<Types::Charset>(0x71_uint8)
  },
  {
    "ibm891"sv,
    std::make_shared<Types::Charset>(0x72_uint8)
  },
  {
    "ibm903"sv,
    std::make_shared<Types::Charset>(0x73_uint8)
  },
  {
    "ibm904"sv,
    std::make_shared<Types::Charset>(0x74_uint8)
  },
  {
    "ibm905"sv,
    std::make_shared<Types::Charset>(0x75_uint8)
  },
  {
    "ibm918"sv,
    std::make_shared<Types::Charset>(0x76_uint8)
  },
  {
    "ibm-symbols"sv,
    std::make_shared<Types::Charset>(0x77_uint8)
  },
  {
    "ibm-thai"sv,
    std::make_shared<Types::Charset>(0x78_uint8)
  },
  {
    "iec_p27-1"sv,
    std::make_shared<Types::Charset>(0x79_uint8)
  },
  {
    "inis"sv,
    std::make_shared<Types::Charset>(0x7A_uint8)
  },
  {
    "inis-8"sv,
    std::make_shared<Types::Charset>(0x7B_uint8)
  },
  {
    "inis-cyrillic"sv,
    std::make_shared<Types::Charset>(0x7C_uint8)
  },
  {
    "invariant"sv,
    std::make_shared<Types::Charset>(0x7D_uint8)
  },
  {
    "iso_10367-box"sv,
    std::make_shared<Types::Charset>(0x7E_uint8)
  },
  {
    "iso_2033-1983"sv,
    std::make_shared<Types::Charset>(0x7F_uint8)
  },
  {
    "iso_5427"sv,
    std::make_shared<Types::Charset>(0x8000_uint16)
  },
  {
    "iso_5427:1981"sv,
    std::make_shared<Types::Charset>(0x8001_uint16)
  },
  {
    "iso_5428:1980"sv,
    std::make_shared<Types::Charset>(0x8002_uint16)
  },
  {
    "iso_646.basic:1983"sv,
    std::make_shared<Types::Charset>(0x8003_uint16)
  },
  {
    "iso_646.irv:1983"sv,
    std::make_shared<Types::Charset>(0x8004_uint16)
  },
  {
    "iso_6937-2-25"sv,
    std::make_shared<Types::Charset>(0x8005_uint16)
  },
  {
    "iso_6937-2-add"sv,
    std::make_shared<Types::Charset>(0x8006_uint16)
  },
  {
    "iso_8859-6-e"sv,
    std::make_shared<Types::Charset>(0x8007_uint16)
  },
  {
    "iso_8859-6-i"sv,
    std::make_shared<Types::Charset>(0x8008_uint16)
  },
  {
    "iso_8859-8-e"sv,
    std::make_shared<Types::Charset>(0x8009_uint16)
  },
  {
    "iso_8859-8-i"sv,
    std::make_shared<Types::Charset>(0x800A_uint16)
  },
  {
    "iso_8859-supp"sv,
    std::make_shared<Types::Charset>(0x800B_uint16)
  },
  {
    "iso-10646-j-1"sv,
    std::make_shared<Types::Charset>(0x800C_uint16)
  },
  {
    "iso-10646-ucs-2"sv,
    std::make_shared<Types::Charset>(0x800D_uint16)
  },
  {
    "iso-10646-ucs-4"sv,
    std::make_shared<Types::Charset>(0x800E_uint16)
  },
  {
    "iso-10646-ucs-basic"sv,
    std::make_shared<Types::Charset>(0x800F_uint16)
  },
  {
    "iso-10646-unicode-latin1"sv,
    std::make_shared<Types::Charset>(0x8010_uint16)
  },
  {
    "iso-10646-utf-1"sv,
    std::make_shared<Types::Charset>(0x8011_uint16)
  },
  {
    "iso-11548-1"sv,
    std::make_shared<Types::Charset>(0x8012_uint16)
  },
  {
    "iso-2022-cn"sv,
    std::make_shared<Types::Charset>(0x8013_uint16)
  },
  {
    "iso-2022-cn-ext"sv,
    std::make_shared<Types::Charset>(0x8014_uint16)
  },
  {
    "iso-2022-jp"sv,
    std::make_shared<Types::Charset>(0x8015_uint16)
  },
  {
    "iso-2022-jp-2"sv,
    std::make_shared<Types::Charset>(0x8016_uint16)
  },
  {
    "iso-2022-kr"sv,
    std::make_shared<Types::Charset>(0x8017_uint16)
  },
  {
    "iso-8859-1"sv,
    std::make_shared<Types::Charset>(0x8018_uint16)
  },
  {
    "iso-8859-10"sv,
    std::make_shared<Types::Charset>(0x8019_uint16)
  },
  {
    "iso-8859-13"sv,
    std::make_shared<Types::Charset>(0x801A_uint16)
  },
  {
    "iso-8859-14"sv,
    std::make_shared<Types::Charset>(0x801B_uint16)
  },
  {
    "iso-8859-15"sv,
    std::make_shared<Types::Charset>(0x801C_uint16)
  },
  {
    "iso-8859-16"sv,
    std::make_shared<Types::Charset>(0x801D_uint16)
  },
  {
    "iso-8859-1-windows-3.0-latin-1"sv,
    std::make_shared<Types::Charset>(0x801E_uint16)
  },
  {
    "iso-8859-1-windows-3.1-latin-1"sv,
    std::make_shared<Types::Charset>(0x801F_uint16)
  },
  {
    "iso-8859-2"sv,
    std::make_shared<Types::Charset>(0x8020_uint16)
  },
  {
    "iso-8859-2-windows-latin-2"sv,
    std::make_shared<Types::Charset>(0x8021_uint16)
  },
  {
    "iso-8859-3"sv,
    std::make_shared<Types::Charset>(0x8022_uint16)
  },
  {
    "iso-8859-4"sv,
    std::make_shared<Types::Charset>(0x8023_uint16)
  },
  {
    "iso-8859-5"sv,
    std::make_shared<Types::Charset>(0x8024_uint16)
  },
  {
    "iso-8859-6"sv,
    std::make_shared<Types::Charset>(0x8025_uint16)
  },
  {
    "iso-8859-7"sv,
    std::make_shared<Types::Charset>(0x8026_uint16)
  },
  {
    "iso-8859-8"sv,
    std::make_shared<Types::Charset>(0x8027_uint16)
  },
  {
    "iso-8859-9"sv,
    std::make_shared<Types::Charset>(0x8028_uint16)
  },
  {
    "iso-8859-9-windows-latin-5"sv,
    std::make_shared<Types::Charset>(0x8029_uint16)
  },
  {
    "iso-ir-90"sv,
    std::make_shared<Types::Charset>(0x802A_uint16)
  },
  {
    "iso-unicode-ibm-1261"sv,
    std::make_shared<Types::Charset>(0x802B_uint16)
  },
  {
    "iso-unicode-ibm-1264"sv,
    std::make_shared<Types::Charset>(0x802C_uint16)
  },
  {
    "iso-unicode-ibm-1265"sv,
    std::make_shared<Types::Charset>(0x802D_uint16)
  },
  {
    "iso-unicode-ibm-1268"sv,
    std::make_shared<Types::Charset>(0x802E_uint16)
  },
  {
    "iso-unicode-ibm-1276"sv,
    std::make_shared<Types::Charset>(0x802F_uint16)
  },
  {
    "it"sv,
    std::make_shared<Types::Charset>(0x8030_uint16)
  },
  {
    "jis_c6220-1969-jp"sv,
    std::make_shared<Types::Charset>(0x8031_uint16)
  },
  {
    "jis_c6220-1969-ro"sv,
    std::make_shared<Types::Charset>(0x8032_uint16)
  },
  {
    "jis_c6226-1978"sv,
    std::make_shared<Types::Charset>(0x8033_uint16)
  },
  {
    "jis_c6226-1983"sv,
    std::make_shared<Types::Charset>(0x8034_uint16)
  },
  {
    "jis_c6229-1984-a"sv,
    std::make_shared<Types::Charset>(0x8035_uint16)
  },
  {
    "jis_c6229-1984-b"sv,
    std::make_shared<Types::Charset>(0x8036_uint16)
  },
  {
    "jis_c6229-1984-b-add"sv,
    std::make_shared<Types::Charset>(0x8037_uint16)
  },
  {
    "jis_c6229-1984-hand"sv,
    std::make_shared<Types::Charset>(0x8038_uint16)
  },
  {
    "jis_c6229-1984-hand-add"sv,
    std::make_shared<Types::Charset>(0x8039_uint16)
  },
  {
    "jis_c6229-1984-kana"sv,
    std::make_shared<Types::Charset>(0x803A_uint16)
  },
  {
    "jis_encoding"sv,
    std::make_shared<Types::Charset>(0x803B_uint16)
  },
  {
    "jis_x0201"sv,
    std::make_shared<Types::Charset>(0x803C_uint16)
  },
  {
    "jis_x0212-1990"sv,
    std::make_shared<Types::Charset>(0x803D_uint16)
  },
  {
    "jus_i.b1.002"sv,
    std::make_shared<Types::Charset>(0x803E_uint16)
  },
  {
    "jus_i.b1.003-mac"sv,
    std::make_shared<Types::Charset>(0x803F_uint16)
  },
  {
    "jus_i.b1.003-serb"sv,
    std::make_shared<Types::Charset>(0x8040_uint16)
  },
  {
    "koi7-switched"sv,
    std::make_shared<Types::Charset>(0x8041_uint16)
  },
  {
    "koi8-r"sv,
    std::make_shared<Types::Charset>(0x8042_uint16)
  },
  {
    "koi8-u"sv,
    std::make_shared<Types::Charset>(0x8043_uint16)
  },
  {
    "ks_c_5601-1987"sv,
    std::make_shared<Types::Charset>(0x8044_uint16)
  },
  {
    "ksc5636"sv,
    std::make_shared<Types::Charset>(0x8045_uint16)
  },
  {
    "kz-1048"sv,
    std::make_shared<Types::Charset>(0x8046_uint16)
  },
  {
    "latin-greek"sv,
    std::make_shared<Types::Charset>(0x8047_uint16)
  },
  {
    "latin-greek-1"sv,
    std::make_shared<Types::Charset>(0x8048_uint16)
  },
  {
    "latin-lap"sv,
    std::make_shared<Types::Charset>(0x8049_uint16)
  },
  {
    "macintosh"sv,
    std::make_shared<Types::Charset>(0x804A_uint16)
  },
  {
    "microsoft-publishing"sv,
    std::make_shared<Types::Charset>(0x804B_uint16)
  },
  {
    "mnem"sv,
    std::make_shared<Types::Charset>(0x804C_uint16)
  },
  {
    "mnemonic"sv,
    std::make_shared<Types::Charset>(0x804D_uint16)
  },
  {
    "msz_7795.3"sv,
    std::make_shared<Types::Charset>(0x804E_uint16)
  },
  {
    "nats-dano"sv,
    std::make_shared<Types::Charset>(0x804F_uint16)
  },
  {
    "nats-dano-add"sv,
    std::make_shared<Types::Charset>(0x8050_uint16)
  },
  {
    "nats-sefi"sv,
    std::make_shared<Types::Charset>(0x8051_uint16)
  },
  {
    "nats-sefi-add"sv,
    std::make_shared<Types::Charset>(0x8052_uint16)
  },
  {
    "nc_nc00-10:81"sv,
    std::make_shared<Types::Charset>(0x8053_uint16)
  },
  {
    "nf_z_62-010"sv,
    std::make_shared<Types::Charset>(0x8054_uint16)
  },
  {
    "ns_4551-1"sv,
    std::make_shared<Types::Charset>(0x8055_uint16)
  },
  {
    "ns_4551-2"sv,
    std::make_shared<Types::Charset>(0x8056_uint16)
  },
  {
    "osd_ebcdic_df03_irv"sv,
    std::make_shared<Types::Charset>(0x8057_uint16)
  },
  {
    "osd_ebcdic_df04_1"sv,
    std::make_shared<Types::Charset>(0x8058_uint16)
  },
  {
    "osd_ebcdic_df04_15"sv,
    std::make_shared<Types::Charset>(0x8059_uint16)
  },
  {
    "pc8-danish-norwegian"sv,
    std::make_shared<Types::Charset>(0x805A_uint16)
  },
  {
    "pc8-turkish"sv,
    std::make_shared<Types::Charset>(0x805B_uint16)
  },
  {
    "pt"sv,
    std::make_shared<Types::Charset>(0x805C_uint16)
  },
  {
    "pt2"sv,
    std::make_shared<Types::Charset>(0x805D_uint16)
  },
  {
    "ptcp154"sv,
    std::make_shared<Types::Charset>(0x805E_uint16)
  },
  {
    "scsu"sv,
    std::make_shared<Types::Charset>(0x805F_uint16)
  },
  {
    "sen_850200_b"sv,
    std::make_shared<Types::Charset>(0x8060_uint16)
  },
  {
    "sen_850200_c"sv,
    std::make_shared<Types::Charset>(0x8061_uint16)
  },
  {
    "shift_jis"sv,
    std::make_shared<Types::Charset>(0x8062_uint16)
  },
  {
    "t.101-g2"sv,
    std::make_shared<Types::Charset>(0x8063_uint16)
  },
  {
    "t.61-7bit"sv,
    std::make_shared<Types::Charset>(0x8064_uint16)
  },
  {
    "t.61-8bit"sv,
    std::make_shared<Types::Charset>(0x8065_uint16)
  },
  {
    "tis-620"sv,
    std::make_shared<Types::Charset>(0x8066_uint16)
  },
  {
    "tscii"sv,
    std::make_shared<Types::Charset>(0x8067_uint16)
  },
  {
    "unicode-1-1"sv,
    std::make_shared<Types::Charset>(0x8068_uint16)
  },
  {
    "unicode-1-1-utf-7"sv,
    std::make_shared<Types::Charset>(0x8069_uint16)
  },
  {
    "unknown-8bit"sv,
    std::make_shared<Types::Charset>(0x806A_uint16)
  },
  {
    "us-ascii"sv,
    std::make_shared<Types::Charset>(0x806B_uint16)
  },
  {
    "us-dk"sv,
    std::make_shared<Types::Charset>(0x806C_uint16)
  },
  {
    "utf-16"sv,
    std::make_shared<Types::Charset>(0x806D_uint16)
  },
  {
    "utf-16be"sv,
    std::make_shared<Types::Charset>(0x806E_uint16)
  },
  {
    "utf-16le"sv,
    std::make_shared<Types::Charset>(0x806F_uint16)
  },
  {
    "utf-32"sv,
    std::make_shared<Types::Charset>(0x8070_uint16)
  },
  {
    "utf-32be"sv,
    std::make_shared<Types::Charset>(0x8071_uint16)
  },
  {
    "utf-32le"sv,
    std::make_shared<Types::Charset>(0x8072_uint16)
  },
  {
    "utf-7"sv,
    std::make_shared<Types::Charset>(0x8073_uint16)
  },
  {
    "ventura-international"sv,
    std::make_shared<Types::Charset>(0x8074_uint16)
  },
  {
    "ventura-math"sv,
    std::make_shared<Types::Charset>(0x8075_uint16)
  },
  {
    "ventura-us"sv,
    std::make_shared<Types::Charset>(0x8076_uint16)
  },
  {
    "videotex-suppl"sv,
    std::make_shared<Types::Charset>(0x8077_uint16)
  },
  {
    "viqr"sv,
    std::make_shared<Types::Charset>(0x8078_uint16)
  },
  {
    "viscii"sv,
    std::make_shared<Types::Charset>(0x8079_uint16)
  },
  {
    "windows-1250"sv,
    std::make_shared<Types::Charset>(0x807A_uint16)
  },
  {
    "windows-1251"sv,
    std::make_shared<Types::Charset>(0x807B_uint16)
  },
  {
    "windows-1252"sv,
    std::make_shared<Types::Charset>(0x807C_uint16)
  },
  {
    "windows-1253"sv,
    std::make_shared<Types::Charset>(0x807D_uint16)
  },
  {
    "windows-1254"sv,
    std::make_shared<Types::Charset>(0x807E_uint16)
  },
  {
    "windows-1255"sv,
    std::make_shared<Types::Charset>(0x807F_uint16)
  },
  {
    "windows-1256"sv,
    std::make_shared<Types::Charset>(0x8080_uint16)
  },
  {
    "windows-1257"sv,
    std::make_shared<Types::Charset>(0x8081_uint16)
  },
  {
    "windows-1258"sv,
    std::make_shared<Types::Charset>(0x8082_uint16)
  },
  {
    "windows-31j"sv,
    std::make_shared<Types::Charset>(0x8083_uint16)
  },
  {
    "windows-874"sv,
    std::make_shared<Types::Charset>(0x8084_uint16)
  }
};
}  // namespace WebBinaryCompression::Attributes::Values::Charsets
#endif
