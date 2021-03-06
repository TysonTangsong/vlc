/*****************************************************************************
 * color_config.h: ISO/IEC 23001-8:2016 color mappings
 *****************************************************************************
 * Copyright (C) 2018 VideoLabs, VLC authors and VideoLAN
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#ifndef VLC_MP4_COLOR_CONFIG_H_
#define VLC_MP4_COLOR_CONFIG_H_

#include <vlc_es.h>

/* no free spec, grabbed from av1 bitstream spec */

enum iso_23001_8_cp
{
    ISO_23001_8_CP_BT_709 = 1,
    ISO_23001_8_CP_UNSPECIFIED,
    ISO_23001_8_CP_BT_470_M,
    ISO_23001_8_CP_BT_470_B_G,
    ISO_23001_8_CP_BT_601,
    ISO_23001_8_CP_SMPTE_240,
    ISO_23001_8_CP_GENERIC_FILM,
    ISO_23001_8_CP_BT_2020, /* BT.2100 */
    ISO_23001_8_CP_XYZ, /* SMPTE 428 */
    ISO_23001_8_CP_SMPTE_431,
    ISO_23001_8_CP_SMPTE_432,
    ISO_23001_8_CP_EBU_3213,
};

static const uint8_t iso_23001_8_cp_to_vlc_primaries_table[] =
{
    [0]                             = COLOR_PRIMARIES_UNDEF,
    [ISO_23001_8_CP_BT_709]         = COLOR_PRIMARIES_BT709,
    [ISO_23001_8_CP_UNSPECIFIED]    = COLOR_PRIMARIES_UNDEF,
    [ISO_23001_8_CP_BT_470_M]       = COLOR_PRIMARIES_BT470_M,
    [ISO_23001_8_CP_BT_470_B_G]     = COLOR_PRIMARIES_BT470_BG,
    [ISO_23001_8_CP_BT_601]         = COLOR_PRIMARIES_SMTPE_170,
    [ISO_23001_8_CP_SMPTE_240]      = COLOR_PRIMARIES_SMTPE_240,
    [ISO_23001_8_CP_GENERIC_FILM]   = COLOR_PRIMARIES_UNDEF,
    [ISO_23001_8_CP_BT_2020]        = COLOR_PRIMARIES_BT2020,
    [ISO_23001_8_CP_XYZ]            = COLOR_PRIMARIES_UNDEF,
    [ISO_23001_8_CP_SMPTE_431]      = COLOR_PRIMARIES_UNDEF,
    [ISO_23001_8_CP_SMPTE_432]      = COLOR_PRIMARIES_UNDEF,
    [ISO_23001_8_CP_EBU_3213]       = COLOR_PRIMARIES_EBU_3213,
};

static inline uint8_t iso_23001_8_cp_to_vlc_primaries( uint8_t v )
{
    return v < ARRAY_SIZE(iso_23001_8_cp_to_vlc_primaries_table)
           ? iso_23001_8_cp_to_vlc_primaries_table[v]
           : COLOR_PRIMARIES_UNDEF;
}

enum iso_23001_8_tc
{
    ISO_23001_8_TC_RESERVED_0 = 0,
    ISO_23001_8_TC_BT_709,
    ISO_23001_8_TC_UNSPECIFIED,
    ISO_23001_8_TC_RESERVED_3,
    ISO_23001_8_TC_BT_470_M,
    ISO_23001_8_TC_BT_470_B_G,
    ISO_23001_8_TC_BT_601,
    ISO_23001_8_TC_SMPTE_240,
    ISO_23001_8_TC_LINEAR,
    ISO_23001_8_TC_LOG_100,
    ISO_23001_8_TC_LOG_100_SQRT10,
    ISO_23001_8_TC_IEC_61966,
    ISO_23001_8_TC_BT_1361,
    ISO_23001_8_TC_SRGB,
    ISO_23001_8_TC_BT_2020_10_BIT,
    ISO_23001_8_TC_BT_2020_12_BIT,
    ISO_23001_8_TC_SMPTE_2084,
    ISO_23001_8_TC_SMPTE_428,
    ISO_23001_8_TC_HLG /* BT.2100 HLG, ARIB STD-B67 */
};

static const uint8_t iso_23001_8_tc_to_vlc_xfer_table[] =
{
    [ISO_23001_8_TC_RESERVED_0]     = TRANSFER_FUNC_UNDEF,
    [ISO_23001_8_TC_BT_709]         = TRANSFER_FUNC_BT709,
    [ISO_23001_8_TC_UNSPECIFIED]    = TRANSFER_FUNC_UNDEF,
    [ISO_23001_8_TC_RESERVED_3]     = TRANSFER_FUNC_UNDEF,
    [ISO_23001_8_TC_BT_470_M]       = TRANSFER_FUNC_BT470_M,
    [ISO_23001_8_TC_BT_470_B_G]     = TRANSFER_FUNC_BT470_BG,
    [ISO_23001_8_TC_BT_601]         = TRANSFER_FUNC_BT709,
    [ISO_23001_8_TC_SMPTE_240]      = TRANSFER_FUNC_SMPTE_240,
    [ISO_23001_8_TC_LINEAR]         = TRANSFER_FUNC_LINEAR,
    [ISO_23001_8_TC_LOG_100]        = TRANSFER_FUNC_UNDEF,
    [ISO_23001_8_TC_LOG_100_SQRT10] = TRANSFER_FUNC_UNDEF,
    [ISO_23001_8_TC_IEC_61966]      = TRANSFER_FUNC_UNDEF,
    [ISO_23001_8_TC_BT_1361]        = TRANSFER_FUNC_UNDEF,
    [ISO_23001_8_TC_SRGB]           = TRANSFER_FUNC_SRGB,
    [ISO_23001_8_TC_BT_2020_10_BIT] = TRANSFER_FUNC_BT2020,
    [ISO_23001_8_TC_BT_2020_12_BIT] = TRANSFER_FUNC_BT2020,
    [ISO_23001_8_TC_SMPTE_2084]     = TRANSFER_FUNC_SMPTE_ST2084,
    [ISO_23001_8_TC_SMPTE_428]      = TRANSFER_FUNC_UNDEF,
    [ISO_23001_8_TC_HLG]            = TRANSFER_FUNC_HLG,
};

static inline uint8_t iso_23001_8_tc_to_vlc_xfer( uint8_t v )
{
    return v < ARRAY_SIZE(iso_23001_8_tc_to_vlc_xfer_table)
           ? iso_23001_8_tc_to_vlc_xfer_table[v]
           : TRANSFER_FUNC_UNDEF;
}

enum iso_23001_8_mc
{
    ISO_23001_8_MC_IDENTITY = 0,
    ISO_23001_8_MC_BT_709,
    ISO_23001_8_MC_UNSPECIFIED,
    ISO_23001_8_MC_RESERVED_3,
    ISO_23001_8_MC_FCC,
    ISO_23001_8_MC_BT_470_B_G,
    ISO_23001_8_MC_BT_601,
    ISO_23001_8_MC_SMPTE_240,
    ISO_23001_8_MC_SMPTE_YCGCO,
    ISO_23001_8_MC_BT_2020_NCL,
    ISO_23001_8_MC_BT_2020_CL,
    ISO_23001_8_MC_SMPTE_2085,
    ISO_23001_8_MC_CHROMAT_NCL,
    ISO_23001_8_MC_CHROMAT_CL,
    ISO_23001_8_MC_ICTCP,
};

static const uint8_t iso_23001_8_mc_to_vlc_coeffs_table[] =
{
    [ISO_23001_8_MC_IDENTITY]    = COLOR_SPACE_UNDEF,
    [ISO_23001_8_MC_BT_709]      = COLOR_SPACE_BT709,
    [ISO_23001_8_MC_UNSPECIFIED] = COLOR_SPACE_UNDEF,
    [ISO_23001_8_MC_RESERVED_3]  = COLOR_SPACE_UNDEF,
    [ISO_23001_8_MC_FCC]         = COLOR_SPACE_UNDEF,
    [ISO_23001_8_MC_BT_470_B_G]  = COLOR_SPACE_BT601,
    [ISO_23001_8_MC_BT_601]      = COLOR_SPACE_BT601,
    [ISO_23001_8_MC_SMPTE_240]   = COLOR_SPACE_UNDEF,
    [ISO_23001_8_MC_SMPTE_YCGCO] = COLOR_SPACE_UNDEF,
    [ISO_23001_8_MC_BT_2020_NCL] = COLOR_SPACE_BT2020,
    [ISO_23001_8_MC_BT_2020_CL]  = COLOR_SPACE_BT2020,
    [ISO_23001_8_MC_SMPTE_2085]  = COLOR_SPACE_UNDEF,
    [ISO_23001_8_MC_CHROMAT_NCL] = COLOR_SPACE_UNDEF,
    [ISO_23001_8_MC_CHROMAT_CL]  = COLOR_SPACE_UNDEF,
    [ISO_23001_8_MC_ICTCP]       = COLOR_SPACE_UNDEF,
};

static inline uint8_t iso_23001_8_mc_to_vlc_coeffs( uint8_t v )
{
    return v < ARRAY_SIZE(iso_23001_8_mc_to_vlc_coeffs_table)
           ? iso_23001_8_mc_to_vlc_coeffs_table[v]
           : COLOR_SPACE_UNDEF;
}

#endif VLC_MP4_COLOR_CONFIG_H_
