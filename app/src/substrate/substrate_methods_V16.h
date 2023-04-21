/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
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
#pragma once

#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V16.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V16 0
#define PD_CALL_BALANCES_V16 5
#define PD_CALL_SESSION_V16 10
#define PD_CALL_VESTING_V16 14
#define PD_CALL_UTILITY_V16 15
#define PD_CALL_MULTISIG_V16 16
#define PD_CALL_SUDO_V16 17

#define PD_CALL_BALANCES_TRANSFER_ALL_V16 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V16_t;

#define PD_CALL_SESSION_SET_KEYS_V16 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V16_t;

#define PD_CALL_SESSION_PURGE_KEYS_V16 1
typedef struct {
} pd_session_purge_keys_V16_t;

#define PD_CALL_UTILITY_BATCH_V16 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V16_t;

#define PD_CALL_UTILITY_BATCH_ALL_V16 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V16_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V16 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V16_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V16 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V16_t;

#define PD_CALL_VESTING_VEST_V16 0
typedef struct {
} pd_vesting_vest_V16_t;

#define PD_CALL_VESTING_VEST_OTHER_V16 1
typedef struct {
    pd_AccountIdLookupOfT_t target;
} pd_vesting_vest_other_V16_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V16 2
typedef struct {
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_vested_transfer_V16_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V16 3
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_force_vested_transfer_V16_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V16 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V16_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V16 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V16_t;

#define PD_CALL_SUDO_SUDO_V16 0
typedef struct {
    pd_Call_t call;
} pd_sudo_sudo_V16_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V16 1
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_sudo_sudo_unchecked_weight_V16_t;

#define PD_CALL_SUDO_SET_KEY_V16 2
typedef struct {
    pd_AccountIdLookupOfT_t new_;
} pd_sudo_set_key_V16_t;

#define PD_CALL_SUDO_SUDO_AS_V16 3
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V16_t;

#endif

typedef union {
    pd_balances_transfer_all_V16_t balances_transfer_all_V16;
    pd_session_set_keys_V16_t session_set_keys_V16;
    pd_session_purge_keys_V16_t session_purge_keys_V16;
    pd_utility_batch_V16_t utility_batch_V16;
    pd_utility_batch_all_V16_t utility_batch_all_V16;
    pd_utility_force_batch_V16_t utility_force_batch_V16;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_balances_force_unreserve_V16_t balances_force_unreserve_V16;
    pd_vesting_vest_V16_t vesting_vest_V16;
    pd_vesting_vest_other_V16_t vesting_vest_other_V16;
    pd_vesting_vested_transfer_V16_t vesting_vested_transfer_V16;
    pd_vesting_force_vested_transfer_V16_t vesting_force_vested_transfer_V16;
    pd_vesting_merge_schedules_V16_t vesting_merge_schedules_V16;
    pd_utility_with_weight_V16_t utility_with_weight_V16;
    pd_sudo_sudo_V16_t sudo_sudo_V16;
    pd_sudo_sudo_unchecked_weight_V16_t sudo_sudo_unchecked_weight_V16;
    pd_sudo_set_key_V16_t sudo_set_key_V16;
    pd_sudo_sudo_as_V16_t sudo_sudo_as_V16;
#endif
} pd_MethodBasic_V16_t;

#define PD_CALL_BALANCES_TRANSFER_V16 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V16_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V16 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V16_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V16 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V16_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V16 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V16_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V16 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V16_t;

#define PD_CALL_SYSTEM_SET_CODE_V16 2
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V16_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V16 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V16_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V16 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V16_t;

#define PD_CALL_BALANCES_SET_BALANCE_V16 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V16_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V16 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V16_t;

#define PD_CALL_MULTISIG_AS_MULTI_V16 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V16_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V16 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V16_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V16 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V16_t;

#endif

typedef union {
    pd_balances_transfer_V16_t balances_transfer_V16;
    pd_balances_force_transfer_V16_t balances_force_transfer_V16;
    pd_balances_transfer_keep_alive_V16_t balances_transfer_keep_alive_V16;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_remark_V16_t system_remark_V16;
    pd_system_set_heap_pages_V16_t system_set_heap_pages_V16;
    pd_system_set_code_V16_t system_set_code_V16;
    pd_system_set_code_without_checks_V16_t system_set_code_without_checks_V16;
    pd_system_remark_with_event_V16_t system_remark_with_event_V16;
    pd_balances_set_balance_V16_t balances_set_balance_V16;
    pd_multisig_as_multi_threshold_1_V16_t multisig_as_multi_threshold_1_V16;
    pd_multisig_as_multi_V16_t multisig_as_multi_V16;
    pd_multisig_approve_as_multi_V16_t multisig_approve_as_multi_V16;
    pd_multisig_cancel_as_multi_V16_t multisig_cancel_as_multi_V16;
#endif
} pd_MethodNested_V16_t;

typedef union {
    pd_MethodBasic_V16_t basic;
    pd_MethodNested_V16_t nested;
} pd_Method_V16_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
