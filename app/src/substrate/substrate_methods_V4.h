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
#include "substrate_types_V4.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V4 0
#define PD_CALL_TIMESTAMP_V4 4
#define PD_CALL_BALANCES_V4 5
#define PD_CALL_SESSION_V4 10
#define PD_CALL_ELECTIONS_V4 12
#define PD_CALL_VESTING_V4 14
#define PD_CALL_UTILITY_V4 15
#define PD_CALL_MULTISIG_V4 16
#define PD_CALL_SUDO_V4 17

#define PD_CALL_BALANCES_TRANSFER_ALL_V4 4
typedef struct {
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V4_t;

#define PD_CALL_SESSION_SET_KEYS_V4 0
typedef struct {
    pd_Keys_V4_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V4_t;

#define PD_CALL_SESSION_PURGE_KEYS_V4 1
typedef struct {
} pd_session_purge_keys_V4_t;

#define PD_CALL_UTILITY_BATCH_V4 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V4_t;

#define PD_CALL_UTILITY_BATCH_ALL_V4 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V4_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V4 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V4_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V4 5
typedef struct {
    pd_LookupasStaticLookupSource_V4_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V4_t;

#define PD_CALL_ELECTIONS_CHANGE_MEMBERS_V4 0
typedef struct {
    pd_VecAccountId_V4_t members;
} pd_elections_change_members_V4_t;

#define PD_CALL_VESTING_VEST_V4 0
typedef struct {
} pd_vesting_vest_V4_t;

#define PD_CALL_VESTING_VEST_OTHER_V4 1
typedef struct {
    pd_LookupasStaticLookupSource_V4_t target;
} pd_vesting_vest_other_V4_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V4 2
typedef struct {
    pd_LookupasStaticLookupSource_V4_t target;
    pd_VestingInfo_V4_t schedule;
} pd_vesting_vested_transfer_V4_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V4 3
typedef struct {
    pd_LookupasStaticLookupSource_V4_t source;
    pd_LookupasStaticLookupSource_V4_t target;
    pd_VestingInfo_V4_t schedule;
} pd_vesting_force_vested_transfer_V4_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V4 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V4_t;

#define PD_CALL_SUDO_SUDO_V4 0
typedef struct {
    pd_Call_t call;
} pd_sudo_sudo_V4_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V4 1
typedef struct {
    pd_Call_t call;
    pd_Weight_V4_t weight;
} pd_sudo_sudo_unchecked_weight_V4_t;

#define PD_CALL_SUDO_SET_KEY_V4 2
typedef struct {
    pd_LookupasStaticLookupSource_V4_t new_;
} pd_sudo_set_key_V4_t;

#define PD_CALL_SUDO_SUDO_AS_V4 3
typedef struct {
    pd_LookupasStaticLookupSource_V4_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V4_t;

#endif

typedef union {
    pd_balances_transfer_all_V4_t balances_transfer_all_V4;
    pd_session_set_keys_V4_t session_set_keys_V4;
    pd_session_purge_keys_V4_t session_purge_keys_V4;
    pd_utility_batch_V4_t utility_batch_V4;
    pd_utility_batch_all_V4_t utility_batch_all_V4;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V4_t timestamp_set_V4;
    pd_balances_force_unreserve_V4_t balances_force_unreserve_V4;
    pd_elections_change_members_V4_t elections_change_members_V4;
    pd_vesting_vest_V4_t vesting_vest_V4;
    pd_vesting_vest_other_V4_t vesting_vest_other_V4;
    pd_vesting_vested_transfer_V4_t vesting_vested_transfer_V4;
    pd_vesting_force_vested_transfer_V4_t vesting_force_vested_transfer_V4;
    pd_vesting_merge_schedules_V4_t vesting_merge_schedules_V4;
    pd_sudo_sudo_V4_t sudo_sudo_V4;
    pd_sudo_sudo_unchecked_weight_V4_t sudo_sudo_unchecked_weight_V4;
    pd_sudo_set_key_V4_t sudo_set_key_V4;
    pd_sudo_sudo_as_V4_t sudo_sudo_as_V4;
#endif
} pd_MethodBasic_V4_t;

#define PD_CALL_BALANCES_TRANSFER_V4 0
typedef struct {
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V4_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V4 2
typedef struct {
    pd_LookupasStaticLookupSource_V4_t source;
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V4_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V4 3
typedef struct {
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V4_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V4 0
typedef struct {
    pd_Perbill_V4_t ratio;
} pd_system_fill_block_V4_t;

#define PD_CALL_SYSTEM_REMARK_V4 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V4_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V4 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V4_t;

#define PD_CALL_SYSTEM_SET_CODE_V4 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V4_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V4 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V4_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V4 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V4_t;

#define PD_CALL_BALANCES_SET_BALANCE_V4 1
typedef struct {
    pd_LookupasStaticLookupSource_V4_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V4_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V4 0
typedef struct {
    pd_VecAccountId_V4_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V4_t;

#define PD_CALL_MULTISIG_AS_MULTI_V4 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_OptionTimepoint_V4_t maybe_timepoint;
    pd_OpaqueCall_V4_t call;
    pd_bool_t store_call;
    pd_Weight_V4_t max_weight;
} pd_multisig_as_multi_V4_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V4 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_OptionTimepoint_V4_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V4_t max_weight;
} pd_multisig_approve_as_multi_V4_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V4 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_Timepoint_V4_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V4_t;

#endif

typedef union {
    pd_balances_transfer_V4_t balances_transfer_V4;
    pd_balances_force_transfer_V4_t balances_force_transfer_V4;
    pd_balances_transfer_keep_alive_V4_t balances_transfer_keep_alive_V4;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V4_t system_fill_block_V4;
    pd_system_remark_V4_t system_remark_V4;
    pd_system_set_heap_pages_V4_t system_set_heap_pages_V4;
    pd_system_set_code_V4_t system_set_code_V4;
    pd_system_set_code_without_checks_V4_t system_set_code_without_checks_V4;
    pd_system_remark_with_event_V4_t system_remark_with_event_V4;
    pd_balances_set_balance_V4_t balances_set_balance_V4;
    pd_multisig_as_multi_threshold_1_V4_t multisig_as_multi_threshold_1_V4;
    pd_multisig_as_multi_V4_t multisig_as_multi_V4;
    pd_multisig_approve_as_multi_V4_t multisig_approve_as_multi_V4;
    pd_multisig_cancel_as_multi_V4_t multisig_cancel_as_multi_V4;
#endif
} pd_MethodNested_V4_t;

typedef union {
    pd_MethodBasic_V4_t basic;
    pd_MethodNested_V4_t nested;
} pd_Method_V4_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
