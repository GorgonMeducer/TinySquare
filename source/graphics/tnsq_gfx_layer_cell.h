/*
 * Copyright (c) 2023, AlgoOy
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author     Notes
 * 2023-07-08     AlgoOy     the first version
 */
 
#ifndef __TNSQ_GFX_LAYER_CELL_H__
#define __TNSQ_GFX_LAYER_CELL_H__

#include "rtdef.h"

#include "arm_2d_helper.h"

#include "__tnsq_gfx_layer.h"
 
#ifdef   __cplusplus
extern "C" {
#endif

#if defined(__clang__)
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wunknown-warning-option"
#   pragma clang diagnostic ignored "-Wreserved-identifier"
#   pragma clang diagnostic ignored "-Wmissing-declarations"
#   pragma clang diagnostic ignored "-Wpadded"
#elif __IS_COMPILER_ARM_COMPILER_5__
#elif __IS_COMPILER_GCC__
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wformat="
#   pragma GCC diagnostic ignored "-Wpedantic"
#   pragma GCC diagnostic ignored "-Wpadded"
#endif

#ifdef __TNSQ_GFX_LAYER_CELL_IMPLEMENT__
#   undef __TNSQ_GFX_LAYER_CELL_IMPLEMENT__
#   define __ARM_2D_IMPL__
#endif
#include "arm_2d_utils.h"

typedef struct tnsq_gfx_layer_cell_t tnsq_gfx_layer_cell_t;
typedef struct tnsq_gfx_layer_cell_cfg_t tnsq_gfx_layer_cell_cfg_t;
typedef struct tnsq_gfx_cell_t tnsq_gfx_cell_t;

struct tnsq_gfx_cell_t
{
    COLOUR_INT tColor;
    rt_uint8_t chOpacity;
    rt_bool_t bIsDirty;
};

struct tnsq_gfx_layer_cell_cfg_t
{
    rt_uint16_t hwXCount;
    rt_uint16_t hwYCount;
    tnsq_gfx_cell_t *ptCells;
};

struct tnsq_gfx_layer_cell_t
{
    ARM_PRIVATE
    (
        implement (tnsq_gfx_layer_base_t);
        struct
        {
            rt_uint16_t hwXCount;
            rt_uint16_t hwYCount;
            rt_uint16_t totalCount;
        } tCount;
        struct
        {
            rt_uint8_t hwXPixel;
            rt_uint8_t hwYPixel;
        } tPixel;
    )
    tnsq_gfx_cell_t *ptCells;
};

#define tnsq_gfx_layer_cell_init(__TNSQ_GFX_LAYER_CELL_CFG_PTR, ...) \
            __tnsq_gfx_layer_cell_init((__TNSQ_GFX_LAYER_CELL_CFG_PTR), (NULL, ##__VA_ARGS__))

ARM_NONNULL(1) tnsq_gfx_layer_cell_t *__tnsq_gfx_layer_cell_init(tnsq_gfx_layer_cell_cfg_t *ptLayerCFG, tnsq_gfx_layer_cell_t *ptLayer);

void tnsq_gfx_layer_cell_draw(tnsq_gfx_layer_cell_t *ptLayer, rt_uint16_t iX, rt_uint16_t iY, rt_uint8_t chOpacity, COLOUR_INT tColor);

#if defined(__clang__)
#   pragma clang diagnostic pop
#elif __IS_COMPILER_GCC__
#   pragma GCC diagnostic pop
#endif

#ifdef   __cplusplus
}
#endif
 
#endif
