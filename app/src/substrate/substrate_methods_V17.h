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
#include "substrate_types_V17.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V17 0
#define PD_CALL_BALANCES_V17 5
#define PD_CALL_STAKING_V17 8
#define PD_CALL_SESSION_V17 10
#define PD_CALL_VESTING_V17 14
#define PD_CALL_UTILITY_V17 15
#define PD_CALL_MULTISIG_V17 16
#define PD_CALL_SUDO_V17 17
#define PD_CALL_CONTRACTS_V17 18
#define PD_CALL_NOMINATIONPOOLS_V17 19

#define PD_CALL_UTILITY_BATCH_V17 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V17_t;

#define PD_CALL_UTILITY_BATCH_ALL_V17 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V17_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V17 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V17_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V17 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V17_t;

#define PD_CALL_BALANCES_UPGRADE_ACCOUNTS_V17 6
typedef struct {
    pd_VecAccountId_t who;
} pd_balances_upgrade_accounts_V17_t;

#define PD_CALL_BALANCES_FORCE_SET_BALANCE_V17 8
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
} pd_balances_force_set_balance_V17_t;

#define PD_CALL_VESTING_VEST_V17 0
typedef struct {
} pd_vesting_vest_V17_t;

#define PD_CALL_VESTING_VEST_OTHER_V17 1
typedef struct {
    pd_AccountIdLookupOfT_t target;
} pd_vesting_vest_other_V17_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V17 2
typedef struct {
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_vested_transfer_V17_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V17 3
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_force_vested_transfer_V17_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V17 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V17_t;

#define PD_CALL_UTILITY_DISPATCH_AS_V17 3
typedef struct {
    pd_BoxPalletsOrigin_t as_origin;
    pd_Call_t call;
} pd_utility_dispatch_as_V17_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V17 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V17_t;

#define PD_CALL_SUDO_SUDO_V17 0
typedef struct {
    pd_Call_t call;
} pd_sudo_sudo_V17_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V17 1
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_sudo_sudo_unchecked_weight_V17_t;

#define PD_CALL_SUDO_SET_KEY_V17 2
typedef struct {
    pd_AccountIdLookupOfT_t new_;
} pd_sudo_set_key_V17_t;

#define PD_CALL_SUDO_SUDO_AS_V17 3
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V17_t;

#define PD_CALL_NOMINATIONPOOLS_POOL_WITHDRAW_UNBONDED_V17 4
typedef struct {
    pd_PoolId_t pool_id;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_pool_withdraw_unbonded_V17_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_WITH_POOL_ID_V17 7
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t root;
    pd_AccountIdLookupOfT_t nominator;
    pd_AccountIdLookupOfT_t bouncer;
    pd_PoolId_t pool_id;
} pd_nominationpools_create_with_pool_id_V17_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CONFIGS_V17 11
typedef struct {
    pd_ConfigOpBalanceOfT_t min_join_bond;
    pd_ConfigOpBalanceOfT_t min_create_bond;
    pd_ConfigOpu32_t max_pools;
    pd_ConfigOpu32_t max_members;
    pd_ConfigOpu32_t max_members_per_pool;
    pd_ConfigOpPerbill_t global_max_commission;
} pd_nominationpools_set_configs_V17_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_OTHER_V17 14
typedef struct {
    pd_AccountIdLookupOfT_t member;
    pd_BondExtraBalanceOfT_t extra;
} pd_nominationpools_bond_extra_other_V17_t;

#endif

typedef union {
    pd_utility_batch_V17_t utility_batch_V17;
    pd_utility_batch_all_V17_t utility_batch_all_V17;
    pd_utility_force_batch_V17_t utility_force_batch_V17;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_balances_force_unreserve_V17_t balances_force_unreserve_V17;
    pd_balances_upgrade_accounts_V17_t balances_upgrade_accounts_V17;
    pd_balances_force_set_balance_V17_t balances_force_set_balance_V17;
    pd_vesting_vest_V17_t vesting_vest_V17;
    pd_vesting_vest_other_V17_t vesting_vest_other_V17;
    pd_vesting_vested_transfer_V17_t vesting_vested_transfer_V17;
    pd_vesting_force_vested_transfer_V17_t vesting_force_vested_transfer_V17;
    pd_vesting_merge_schedules_V17_t vesting_merge_schedules_V17;
    pd_utility_dispatch_as_V17_t utility_dispatch_as_V17;
    pd_utility_with_weight_V17_t utility_with_weight_V17;
    pd_sudo_sudo_V17_t sudo_sudo_V17;
    pd_sudo_sudo_unchecked_weight_V17_t sudo_sudo_unchecked_weight_V17;
    pd_sudo_set_key_V17_t sudo_set_key_V17;
    pd_sudo_sudo_as_V17_t sudo_sudo_as_V17;
    pd_nominationpools_pool_withdraw_unbonded_V17_t nominationpools_pool_withdraw_unbonded_V17;
    pd_nominationpools_create_with_pool_id_V17_t nominationpools_create_with_pool_id_V17;
    pd_nominationpools_set_configs_V17_t nominationpools_set_configs_V17;
    pd_nominationpools_bond_extra_other_V17_t nominationpools_bond_extra_other_V17;
#endif
} pd_MethodBasic_V17_t;

#define PD_CALL_BALANCES_TRANSFER_ALLOW_DEATH_V17 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_allow_death_V17_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V17 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V17_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V17 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V17_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V17 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V17_t;

#define PD_CALL_BALANCES_TRANSFER_V17 7
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V17_t;

#define PD_CALL_STAKING_BOND_V17 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_RewardDestination_t payee;
} pd_staking_bond_V17_t;

#define PD_CALL_STAKING_BOND_EXTRA_V17 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V17_t;

#define PD_CALL_STAKING_UNBOND_V17 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V17_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V17 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V17_t;

#define PD_CALL_STAKING_VALIDATE_V17 4
typedef struct {
    pd_ValidatorPrefs_t prefs;
} pd_staking_validate_V17_t;

#define PD_CALL_STAKING_NOMINATE_V17 5
typedef struct {
    pd_VecAccountIdLookupOfT_t targets;
} pd_staking_nominate_V17_t;

#define PD_CALL_STAKING_CHILL_V17 6
typedef struct {
} pd_staking_chill_V17_t;

#define PD_CALL_STAKING_SET_PAYEE_V17 7
typedef struct {
    pd_RewardDestination_t payee;
} pd_staking_set_payee_V17_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V17 8
typedef struct {
} pd_staking_set_controller_V17_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V17 18
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_V17_t;

#define PD_CALL_STAKING_REBOND_V17 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V17_t;

#define PD_CALL_SESSION_SET_KEYS_V17 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V17_t;

#define PD_CALL_SESSION_PURGE_KEYS_V17 1
typedef struct {
} pd_session_purge_keys_V17_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V17 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V17_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V17 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V17_t;

#define PD_CALL_SYSTEM_SET_CODE_V17 2
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V17_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V17 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V17_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V17 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V17_t;

#define PD_CALL_BALANCES_SET_BALANCE_DEPRECATED_V17 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t old_reserved;
} pd_balances_set_balance_deprecated_V17_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V17 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V17_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V17 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V17_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V17 11
typedef struct {
    pd_Percent_t factor;
} pd_staking_scale_validator_count_V17_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V17 12
typedef struct {
} pd_staking_force_no_eras_V17_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V17 13
typedef struct {
} pd_staking_force_new_era_V17_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V17 14
typedef struct {
    pd_VecAccountId_t invulnerables;
} pd_staking_set_invulnerables_V17_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V17 15
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V17_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V17 16
typedef struct {
} pd_staking_force_new_era_always_V17_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V17 17
typedef struct {
    pd_EraIndex_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V17_t;

#define PD_CALL_STAKING_REAP_STASH_V17 20
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V17_t;

#define PD_CALL_STAKING_KICK_V17 21
typedef struct {
    pd_VecAccountIdLookupOfT_t who;
} pd_staking_kick_V17_t;

#define PD_CALL_STAKING_SET_STAKING_CONFIGS_V17 22
typedef struct {
    pd_ConfigOpBalanceOfT_t min_nominator_bond;
    pd_ConfigOpBalanceOfT_t min_validator_bond;
    pd_ConfigOpu32_t max_nominator_count;
    pd_ConfigOpu32_t max_validator_count;
    pd_ConfigOpPercent_t chill_threshold;
    pd_ConfigOpPerbill_t min_commission;
} pd_staking_set_staking_configs_V17_t;

#define PD_CALL_STAKING_CHILL_OTHER_V17 23
typedef struct {
    pd_AccountId_t controller;
} pd_staking_chill_other_V17_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V17 24
typedef struct {
    pd_AccountId_t validator_stash;
} pd_staking_force_apply_min_commission_V17_t;

#define PD_CALL_STAKING_SET_MIN_COMMISSION_V17 25
typedef struct {
    pd_Perbill_t new_;
} pd_staking_set_min_commission_V17_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V17 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V17_t;

#define PD_CALL_MULTISIG_AS_MULTI_V17 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V17_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V17 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V17_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V17 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V17_t;

#define PD_CALL_CONTRACTS_CALL_OLD_WEIGHT_V17 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t data;
} pd_contracts_call_old_weight_V17_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_OLD_WEIGHT_V17 1
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_with_code_old_weight_V17_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_OLD_WEIGHT_V17 2
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_CodeHash_t code_hash;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_old_weight_V17_t;

#define PD_CALL_CONTRACTS_UPLOAD_CODE_V17 3
typedef struct {
    pd_Vecu8_t code;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Determinism_t determinism;
} pd_contracts_upload_code_V17_t;

#define PD_CALL_CONTRACTS_REMOVE_CODE_V17 4
typedef struct {
    pd_CodeHash_t code_hash;
} pd_contracts_remove_code_V17_t;

#define PD_CALL_CONTRACTS_SET_CODE_V17 5
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CodeHash_t code_hash;
} pd_contracts_set_code_V17_t;

#define PD_CALL_CONTRACTS_CALL_V17 6
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t data;
} pd_contracts_call_V17_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_V17 7
typedef struct {
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_with_code_V17_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_V17 8
typedef struct {
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_CodeHash_t code_hash;
    pd_Bytes_t data;
    pd_Bytes_t salt;
} pd_contracts_instantiate_V17_t;

#define PD_CALL_CONTRACTS_MIGRATE_V17 9
typedef struct {
    pd_Weight_t weight_limit;
} pd_contracts_migrate_V17_t;

#define PD_CALL_NOMINATIONPOOLS_JOIN_V17 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_PoolId_t pool_id;
} pd_nominationpools_join_V17_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_V17 1
typedef struct {
    pd_BondExtraBalanceOfT_t extra;
} pd_nominationpools_bond_extra_V17_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_V17 2
typedef struct {
} pd_nominationpools_claim_payout_V17_t;

#define PD_CALL_NOMINATIONPOOLS_UNBOND_V17 3
typedef struct {
    pd_AccountIdLookupOfT_t member_account;
    pd_CompactBalance_t unbonding_points;
} pd_nominationpools_unbond_V17_t;

#define PD_CALL_NOMINATIONPOOLS_WITHDRAW_UNBONDED_V17 5
typedef struct {
    pd_AccountIdLookupOfT_t member_account;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_withdraw_unbonded_V17_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_V17 6
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t root;
    pd_AccountIdLookupOfT_t nominator;
    pd_AccountIdLookupOfT_t bouncer;
} pd_nominationpools_create_V17_t;

#define PD_CALL_NOMINATIONPOOLS_NOMINATE_V17 8
typedef struct {
    pd_PoolId_t pool_id;
    pd_VecAccountId_t validators;
} pd_nominationpools_nominate_V17_t;

#define PD_CALL_NOMINATIONPOOLS_SET_STATE_V17 9
typedef struct {
    pd_PoolId_t pool_id;
    pd_PoolState_t state;
} pd_nominationpools_set_state_V17_t;

#define PD_CALL_NOMINATIONPOOLS_SET_METADATA_V17 10
typedef struct {
    pd_PoolId_t pool_id;
    pd_Vecu8_t metadata;
} pd_nominationpools_set_metadata_V17_t;

#define PD_CALL_NOMINATIONPOOLS_UPDATE_ROLES_V17 12
typedef struct {
    pd_PoolId_t pool_id;
    pd_ConfigOpAccountId_t new_root;
    pd_ConfigOpAccountId_t new_nominator;
    pd_ConfigOpAccountId_t new_bouncer;
} pd_nominationpools_update_roles_V17_t;

#define PD_CALL_NOMINATIONPOOLS_CHILL_V17 13
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_chill_V17_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CLAIM_PERMISSION_V17 15
typedef struct {
    pd_ClaimPermission_t permission;
} pd_nominationpools_set_claim_permission_V17_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_OTHER_V17 16
typedef struct {
    pd_AccountId_t other;
} pd_nominationpools_claim_payout_other_V17_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_V17 17
typedef struct {
    pd_PoolId_t pool_id;
    pd_OptionTuplePerbillAccountId_t new_commission;
} pd_nominationpools_set_commission_V17_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_MAX_V17 18
typedef struct {
    pd_PoolId_t pool_id;
    pd_Perbill_t max_commission;
} pd_nominationpools_set_commission_max_V17_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_CHANGE_RATE_V17 19
typedef struct {
    pd_PoolId_t pool_id;
    pd_CommissionChangeRateBlockNumber_t change_rate;
} pd_nominationpools_set_commission_change_rate_V17_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_COMMISSION_V17 20
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_claim_commission_V17_t;

#endif

typedef union {
    pd_balances_transfer_allow_death_V17_t balances_transfer_allow_death_V17;
    pd_balances_force_transfer_V17_t balances_force_transfer_V17;
    pd_balances_transfer_keep_alive_V17_t balances_transfer_keep_alive_V17;
    pd_balances_transfer_all_V17_t balances_transfer_all_V17;
    pd_balances_transfer_V17_t balances_transfer_V17;
    pd_staking_bond_V17_t staking_bond_V17;
    pd_staking_bond_extra_V17_t staking_bond_extra_V17;
    pd_staking_unbond_V17_t staking_unbond_V17;
    pd_staking_withdraw_unbonded_V17_t staking_withdraw_unbonded_V17;
    pd_staking_validate_V17_t staking_validate_V17;
    pd_staking_nominate_V17_t staking_nominate_V17;
    pd_staking_chill_V17_t staking_chill_V17;
    pd_staking_set_payee_V17_t staking_set_payee_V17;
    pd_staking_set_controller_V17_t staking_set_controller_V17;
    pd_staking_payout_stakers_V17_t staking_payout_stakers_V17;
    pd_staking_rebond_V17_t staking_rebond_V17;
    pd_session_set_keys_V17_t session_set_keys_V17;
    pd_session_purge_keys_V17_t session_purge_keys_V17;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_remark_V17_t system_remark_V17;
    pd_system_set_heap_pages_V17_t system_set_heap_pages_V17;
    pd_system_set_code_V17_t system_set_code_V17;
    pd_system_set_code_without_checks_V17_t system_set_code_without_checks_V17;
    pd_system_remark_with_event_V17_t system_remark_with_event_V17;
    pd_balances_set_balance_deprecated_V17_t balances_set_balance_deprecated_V17;
    pd_staking_set_validator_count_V17_t staking_set_validator_count_V17;
    pd_staking_increase_validator_count_V17_t staking_increase_validator_count_V17;
    pd_staking_scale_validator_count_V17_t staking_scale_validator_count_V17;
    pd_staking_force_no_eras_V17_t staking_force_no_eras_V17;
    pd_staking_force_new_era_V17_t staking_force_new_era_V17;
    pd_staking_set_invulnerables_V17_t staking_set_invulnerables_V17;
    pd_staking_force_unstake_V17_t staking_force_unstake_V17;
    pd_staking_force_new_era_always_V17_t staking_force_new_era_always_V17;
    pd_staking_cancel_deferred_slash_V17_t staking_cancel_deferred_slash_V17;
    pd_staking_reap_stash_V17_t staking_reap_stash_V17;
    pd_staking_kick_V17_t staking_kick_V17;
    pd_staking_set_staking_configs_V17_t staking_set_staking_configs_V17;
    pd_staking_chill_other_V17_t staking_chill_other_V17;
    pd_staking_force_apply_min_commission_V17_t staking_force_apply_min_commission_V17;
    pd_staking_set_min_commission_V17_t staking_set_min_commission_V17;
    pd_multisig_as_multi_threshold_1_V17_t multisig_as_multi_threshold_1_V17;
    pd_multisig_as_multi_V17_t multisig_as_multi_V17;
    pd_multisig_approve_as_multi_V17_t multisig_approve_as_multi_V17;
    pd_multisig_cancel_as_multi_V17_t multisig_cancel_as_multi_V17;
    pd_contracts_call_old_weight_V17_t contracts_call_old_weight_V17;
    pd_contracts_instantiate_with_code_old_weight_V17_t contracts_instantiate_with_code_old_weight_V17;
    pd_contracts_instantiate_old_weight_V17_t contracts_instantiate_old_weight_V17;
    pd_contracts_upload_code_V17_t contracts_upload_code_V17;
    pd_contracts_remove_code_V17_t contracts_remove_code_V17;
    pd_contracts_set_code_V17_t contracts_set_code_V17;
    pd_contracts_call_V17_t contracts_call_V17;
    pd_contracts_instantiate_with_code_V17_t contracts_instantiate_with_code_V17;
    pd_contracts_instantiate_V17_t contracts_instantiate_V17;
    pd_contracts_migrate_V17_t contracts_migrate_V17;
    pd_nominationpools_join_V17_t nominationpools_join_V17;
    pd_nominationpools_bond_extra_V17_t nominationpools_bond_extra_V17;
    pd_nominationpools_claim_payout_V17_t nominationpools_claim_payout_V17;
    pd_nominationpools_unbond_V17_t nominationpools_unbond_V17;
    pd_nominationpools_withdraw_unbonded_V17_t nominationpools_withdraw_unbonded_V17;
    pd_nominationpools_create_V17_t nominationpools_create_V17;
    pd_nominationpools_nominate_V17_t nominationpools_nominate_V17;
    pd_nominationpools_set_state_V17_t nominationpools_set_state_V17;
    pd_nominationpools_set_metadata_V17_t nominationpools_set_metadata_V17;
    pd_nominationpools_update_roles_V17_t nominationpools_update_roles_V17;
    pd_nominationpools_chill_V17_t nominationpools_chill_V17;
    pd_nominationpools_set_claim_permission_V17_t nominationpools_set_claim_permission_V17;
    pd_nominationpools_claim_payout_other_V17_t nominationpools_claim_payout_other_V17;
    pd_nominationpools_set_commission_V17_t nominationpools_set_commission_V17;
    pd_nominationpools_set_commission_max_V17_t nominationpools_set_commission_max_V17;
    pd_nominationpools_set_commission_change_rate_V17_t nominationpools_set_commission_change_rate_V17;
    pd_nominationpools_claim_commission_V17_t nominationpools_claim_commission_V17;
#endif
} pd_MethodNested_V17_t;

typedef union {
    pd_MethodBasic_V17_t basic;
    pd_MethodNested_V17_t nested;
} pd_Method_V17_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
