/*
 * Copyright (c) 2023, AlgoOy
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author     Notes
 * 2023-07-08     AlgoOy     the first version
 */
 
#ifndef __TNSQ_GFX_STAGE_H__
#define __TNSQ_GFX_STAGE_H__

#include "rtdef.h"

#include "arm_2d_helper_scene.h"

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

#ifdef __TNSQ_GFX_STAGE_IMPLEMENT__
#   undef __TNSQ_GFX_STAGE_IMPLEMENT__
#   define __ARM_2D_IMPL__
#endif
#include "arm_2d_utils.h"

struct tnsq_gfx_disp_adapter_t
{
    arm_2d_scene_player_t *ptPlayer;
    arm_fsm_rt_t (*ptPlayerTask)(void);
};
typedef struct tnsq_gfx_disp_adapter_t tnsq_gfx_disp_adapter_t;

struct tnsq_gfx_stage_cfg_t
{
    tnsq_gfx_disp_adapter_t ptDispAdapter;
};
typedef struct tnsq_gfx_stage_cfg_t tnsq_gfx_stage_cfg_t;

struct tnsq_gfx_stage_t
{
    ARM_PRIVATE
	(
        implement(arm_2d_scene_t);
        rt_bool_t blsUserAllocated;
        rt_uint8_t chLayerID;
        tnsq_gfx_stage_cfg_t tStageCFG;
        tnsq_gfx_layer_base_t *ptLayersList;
    )
};
typedef struct tnsq_gfx_stage_t tnsq_gfx_stage_t;

#define tnsq_gfx_stage_init(__TNSQ_GFX_STAGE_CFG_PTR, ...) __tnsq_gfx_stage_init((__TNSQ_GFX_STAGE_CFG_PTR), (NULL, ##__VA_ARGS__))

ARM_NONNULL(1) tnsq_gfx_stage_t *__tnsq_gfx_stage_init(tnsq_gfx_stage_cfg_t *ptStageCFG, tnsq_gfx_stage_t *ptStage);

ARM_NONNULL(1, 2) rt_uint8_t tnsq_gfx_register_layer_to_stage(tnsq_gfx_stage_t *ptStage, void *ptLayer);

ARM_NONNULL(1) void tnsq_gfx_remove_layer(tnsq_gfx_stage_t *ptStage, rt_uint8_t chLayerID);

void tnsq_gfx_make_layer_visible(tnsq_gfx_stage_t *ptStage, rt_uint8_t chLayerID);
void tnsq_gfx_make_layer_invisible(tnsq_gfx_stage_t *ptStage, rt_uint8_t chLayerID);

void *tnsq_gfx_get_layer_ptr(tnsq_gfx_stage_t *ptStage, rt_uint8_t chLayerID);

#if defined(__clang__)
#   pragma clang diagnostic pop
#elif __IS_COMPILER_GCC__
#   pragma GCC diagnostic pop
#endif

#ifdef   __cplusplus
}
#endif

#endif
