/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V9.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V9 0
#define PD_CALL_TIMESTAMP_V9 4
#define PD_CALL_BALANCES_V9 5
#define PD_CALL_SESSION_V9 10
#define PD_CALL_VESTING_V9 14
#define PD_CALL_UTILITY_V9 15
#define PD_CALL_MULTISIG_V9 16
#define PD_CALL_SUDO_V9 17

#define PD_CALL_BALANCES_TRANSFER_ALL_V9 4
typedef struct {
    pd_LookupasStaticLookupSource_V9_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V9_t;

#define PD_CALL_SESSION_SET_KEYS_V9 0
typedef struct {
    pd_Keys_V9_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V9_t;

#define PD_CALL_SESSION_PURGE_KEYS_V9 1
typedef struct {
} pd_session_purge_keys_V9_t;

#define PD_CALL_UTILITY_BATCH_V9 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V9_t;

#define PD_CALL_UTILITY_BATCH_ALL_V9 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V9_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V9 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V9_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V9 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V9_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V9 5
typedef struct {
    pd_LookupasStaticLookupSource_V9_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V9_t;

#define PD_CALL_VESTING_VEST_V9 0
typedef struct {
} pd_vesting_vest_V9_t;

#define PD_CALL_VESTING_VEST_OTHER_V9 1
typedef struct {
    pd_LookupasStaticLookupSource_V9_t target;
} pd_vesting_vest_other_V9_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V9 2
typedef struct {
    pd_LookupasStaticLookupSource_V9_t target;
    pd_VestingInfo_V9_t schedule;
} pd_vesting_vested_transfer_V9_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V9 3
typedef struct {
    pd_LookupasStaticLookupSource_V9_t source;
    pd_LookupasStaticLookupSource_V9_t target;
    pd_VestingInfo_V9_t schedule;
} pd_vesting_force_vested_transfer_V9_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V9 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V9_t;

#define PD_CALL_SUDO_SUDO_V9 0
typedef struct {
    pd_Call_t call;
} pd_sudo_sudo_V9_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V9 1
typedef struct {
    pd_Call_t call;
    pd_Weight_V9_t weight;
} pd_sudo_sudo_unchecked_weight_V9_t;

#define PD_CALL_SUDO_SET_KEY_V9 2
typedef struct {
    pd_LookupasStaticLookupSource_V9_t new_;
} pd_sudo_set_key_V9_t;

#define PD_CALL_SUDO_SUDO_AS_V9 3
typedef struct {
    pd_LookupasStaticLookupSource_V9_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V9_t;

#endif

typedef union {
    pd_balances_transfer_all_V9_t balances_transfer_all_V9;
    pd_session_set_keys_V9_t session_set_keys_V9;
    pd_session_purge_keys_V9_t session_purge_keys_V9;
    pd_utility_batch_V9_t utility_batch_V9;
    pd_utility_batch_all_V9_t utility_batch_all_V9;
    pd_utility_force_batch_V9_t utility_force_batch_V9;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V9_t timestamp_set_V9;
    pd_balances_force_unreserve_V9_t balances_force_unreserve_V9;
    pd_vesting_vest_V9_t vesting_vest_V9;
    pd_vesting_vest_other_V9_t vesting_vest_other_V9;
    pd_vesting_vested_transfer_V9_t vesting_vested_transfer_V9;
    pd_vesting_force_vested_transfer_V9_t vesting_force_vested_transfer_V9;
    pd_vesting_merge_schedules_V9_t vesting_merge_schedules_V9;
    pd_sudo_sudo_V9_t sudo_sudo_V9;
    pd_sudo_sudo_unchecked_weight_V9_t sudo_sudo_unchecked_weight_V9;
    pd_sudo_set_key_V9_t sudo_set_key_V9;
    pd_sudo_sudo_as_V9_t sudo_sudo_as_V9;
#endif
} pd_MethodBasic_V9_t;

#define PD_CALL_BALANCES_TRANSFER_V9 0
typedef struct {
    pd_LookupasStaticLookupSource_V9_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V9_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V9 2
typedef struct {
    pd_LookupasStaticLookupSource_V9_t source;
    pd_LookupasStaticLookupSource_V9_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V9_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V9 3
typedef struct {
    pd_LookupasStaticLookupSource_V9_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V9_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V9 0
typedef struct {
    pd_Perbill_V9_t ratio;
} pd_system_fill_block_V9_t;

#define PD_CALL_SYSTEM_REMARK_V9 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V9_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V9 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V9_t;

#define PD_CALL_SYSTEM_SET_CODE_V9 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V9_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V9 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V9_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V9 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V9_t;

#define PD_CALL_BALANCES_SET_BALANCE_V9 1
typedef struct {
    pd_LookupasStaticLookupSource_V9_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V9_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V9 0
typedef struct {
    pd_VecAccountId_V9_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V9_t;

#define PD_CALL_MULTISIG_AS_MULTI_V9 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V9_t other_signatories;
    pd_OptionTimepoint_V9_t maybe_timepoint;
    pd_OpaqueCall_V9_t call;
    pd_bool_t store_call;
    pd_Weight_V9_t max_weight;
} pd_multisig_as_multi_V9_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V9 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V9_t other_signatories;
    pd_OptionTimepoint_V9_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V9_t max_weight;
} pd_multisig_approve_as_multi_V9_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V9 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V9_t other_signatories;
    pd_Timepoint_V9_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V9_t;

#endif

typedef union {
    pd_balances_transfer_V9_t balances_transfer_V9;
    pd_balances_force_transfer_V9_t balances_force_transfer_V9;
    pd_balances_transfer_keep_alive_V9_t balances_transfer_keep_alive_V9;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V9_t system_fill_block_V9;
    pd_system_remark_V9_t system_remark_V9;
    pd_system_set_heap_pages_V9_t system_set_heap_pages_V9;
    pd_system_set_code_V9_t system_set_code_V9;
    pd_system_set_code_without_checks_V9_t system_set_code_without_checks_V9;
    pd_system_remark_with_event_V9_t system_remark_with_event_V9;
    pd_balances_set_balance_V9_t balances_set_balance_V9;
    pd_multisig_as_multi_threshold_1_V9_t multisig_as_multi_threshold_1_V9;
    pd_multisig_as_multi_V9_t multisig_as_multi_V9;
    pd_multisig_approve_as_multi_V9_t multisig_approve_as_multi_V9;
    pd_multisig_cancel_as_multi_V9_t multisig_cancel_as_multi_V9;
#endif
} pd_MethodNested_V9_t;

typedef union {
    pd_MethodBasic_V9_t basic;
    pd_MethodNested_V9_t nested;
} pd_Method_V9_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
