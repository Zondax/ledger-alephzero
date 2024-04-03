/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
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
#include "substrate_types_V18.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V18 0
#define PD_CALL_BALANCES_V18 5
#define PD_CALL_STAKING_V18 8
#define PD_CALL_SESSION_V18 10
#define PD_CALL_VESTING_V18 14
#define PD_CALL_UTILITY_V18 15
#define PD_CALL_MULTISIG_V18 16
#define PD_CALL_SUDO_V18 17
#define PD_CALL_CONTRACTS_V18 18
#define PD_CALL_NOMINATIONPOOLS_V18 19
#define PD_CALL_PROXY_V18 22

#define PD_CALL_UTILITY_BATCH_V18 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V18_t;

#define PD_CALL_UTILITY_BATCH_ALL_V18 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V18_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V18 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V18_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V18 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V18_t;

#define PD_CALL_BALANCES_UPGRADE_ACCOUNTS_V18 6
typedef struct {
    pd_VecAccountId_t who;
} pd_balances_upgrade_accounts_V18_t;

#define PD_CALL_BALANCES_FORCE_SET_BALANCE_V18 8
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
} pd_balances_force_set_balance_V18_t;

#define PD_CALL_VESTING_VEST_V18 0
typedef struct {
} pd_vesting_vest_V18_t;

#define PD_CALL_VESTING_VEST_OTHER_V18 1
typedef struct {
    pd_AccountIdLookupOfT_t target;
} pd_vesting_vest_other_V18_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V18 2
typedef struct {
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_vested_transfer_V18_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V18 3
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_force_vested_transfer_V18_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V18 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V18_t;

#define PD_CALL_UTILITY_DISPATCH_AS_V18 3
typedef struct {
    pd_BoxPalletsOrigin_t as_origin;
    pd_Call_t call;
} pd_utility_dispatch_as_V18_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V18 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V18_t;

#define PD_CALL_SUDO_SUDO_V18 0
typedef struct {
    pd_Call_t call;
} pd_sudo_sudo_V18_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V18 1
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_sudo_sudo_unchecked_weight_V18_t;

#define PD_CALL_SUDO_SET_KEY_V18 2
typedef struct {
    pd_AccountIdLookupOfT_t new_;
} pd_sudo_set_key_V18_t;

#define PD_CALL_SUDO_SUDO_AS_V18 3
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V18_t;

#define PD_CALL_NOMINATIONPOOLS_POOL_WITHDRAW_UNBONDED_V18 4
typedef struct {
    pd_PoolId_t pool_id;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_pool_withdraw_unbonded_V18_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_WITH_POOL_ID_V18 7
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t root;
    pd_AccountIdLookupOfT_t nominator;
    pd_AccountIdLookupOfT_t bouncer;
    pd_PoolId_t pool_id;
} pd_nominationpools_create_with_pool_id_V18_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CONFIGS_V18 11
typedef struct {
    pd_ConfigOpBalanceOfT_t min_join_bond;
    pd_ConfigOpBalanceOfT_t min_create_bond;
    pd_ConfigOpu32_t max_pools;
    pd_ConfigOpu32_t max_members;
    pd_ConfigOpu32_t max_members_per_pool;
    pd_ConfigOpPerbill_t global_max_commission;
} pd_nominationpools_set_configs_V18_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_OTHER_V18 14
typedef struct {
    pd_AccountIdLookupOfT_t member;
    pd_BondExtraBalanceOfT_t extra;
} pd_nominationpools_bond_extra_other_V18_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V18 3
typedef struct {
} pd_proxy_remove_proxies_V18_t;

#define PD_CALL_PROXY_ANNOUNCE_V18 6
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_CallHashOf_t call_hash;
} pd_proxy_announce_V18_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V18 7
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_CallHashOf_t call_hash;
} pd_proxy_remove_announcement_V18_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V18 8
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_CallHashOf_t call_hash;
} pd_proxy_reject_announcement_V18_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V18 9
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V18_t;

#endif

typedef union {
    pd_utility_batch_V18_t utility_batch_V18;
    pd_utility_batch_all_V18_t utility_batch_all_V18;
    pd_utility_force_batch_V18_t utility_force_batch_V18;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_balances_force_unreserve_V18_t balances_force_unreserve_V18;
    pd_balances_upgrade_accounts_V18_t balances_upgrade_accounts_V18;
    pd_balances_force_set_balance_V18_t balances_force_set_balance_V18;
    pd_vesting_vest_V18_t vesting_vest_V18;
    pd_vesting_vest_other_V18_t vesting_vest_other_V18;
    pd_vesting_vested_transfer_V18_t vesting_vested_transfer_V18;
    pd_vesting_force_vested_transfer_V18_t vesting_force_vested_transfer_V18;
    pd_vesting_merge_schedules_V18_t vesting_merge_schedules_V18;
    pd_utility_dispatch_as_V18_t utility_dispatch_as_V18;
    pd_utility_with_weight_V18_t utility_with_weight_V18;
    pd_sudo_sudo_V18_t sudo_sudo_V18;
    pd_sudo_sudo_unchecked_weight_V18_t sudo_sudo_unchecked_weight_V18;
    pd_sudo_set_key_V18_t sudo_set_key_V18;
    pd_sudo_sudo_as_V18_t sudo_sudo_as_V18;
    pd_nominationpools_pool_withdraw_unbonded_V18_t nominationpools_pool_withdraw_unbonded_V18;
    pd_nominationpools_create_with_pool_id_V18_t nominationpools_create_with_pool_id_V18;
    pd_nominationpools_set_configs_V18_t nominationpools_set_configs_V18;
    pd_nominationpools_bond_extra_other_V18_t nominationpools_bond_extra_other_V18;
    pd_proxy_remove_proxies_V18_t proxy_remove_proxies_V18;
    pd_proxy_announce_V18_t proxy_announce_V18;
    pd_proxy_remove_announcement_V18_t proxy_remove_announcement_V18;
    pd_proxy_reject_announcement_V18_t proxy_reject_announcement_V18;
    pd_proxy_proxy_announced_V18_t proxy_proxy_announced_V18;
#endif
} pd_MethodBasic_V18_t;

#define PD_CALL_BALANCES_TRANSFER_ALLOW_DEATH_V18 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_allow_death_V18_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V18 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V18_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V18 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V18_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V18 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V18_t;

#define PD_CALL_STAKING_BOND_V18 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_RewardDestination_t payee;
} pd_staking_bond_V18_t;

#define PD_CALL_STAKING_BOND_EXTRA_V18 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V18_t;

#define PD_CALL_STAKING_UNBOND_V18 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V18_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V18 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V18_t;

#define PD_CALL_STAKING_VALIDATE_V18 4
typedef struct {
    pd_ValidatorPrefs_t prefs;
} pd_staking_validate_V18_t;

#define PD_CALL_STAKING_NOMINATE_V18 5
typedef struct {
    pd_VecAccountIdLookupOfT_t targets;
} pd_staking_nominate_V18_t;

#define PD_CALL_STAKING_CHILL_V18 6
typedef struct {
} pd_staking_chill_V18_t;

#define PD_CALL_STAKING_SET_PAYEE_V18 7
typedef struct {
    pd_RewardDestination_t payee;
} pd_staking_set_payee_V18_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V18 8
typedef struct {
} pd_staking_set_controller_V18_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V18 18
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_V18_t;

#define PD_CALL_STAKING_REBOND_V18 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V18_t;

#define PD_CALL_SESSION_SET_KEYS_V18 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V18_t;

#define PD_CALL_SESSION_PURGE_KEYS_V18 1
typedef struct {
} pd_session_purge_keys_V18_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V18 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V18_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V18 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V18_t;

#define PD_CALL_SYSTEM_SET_CODE_V18 2
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V18_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V18 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V18_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V18 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V18_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V18 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V18_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V18 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V18_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V18 11
typedef struct {
    pd_Percent_t factor;
} pd_staking_scale_validator_count_V18_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V18 12
typedef struct {
} pd_staking_force_no_eras_V18_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V18 13
typedef struct {
} pd_staking_force_new_era_V18_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V18 14
typedef struct {
    pd_VecAccountId_t invulnerables;
} pd_staking_set_invulnerables_V18_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V18 15
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V18_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V18 16
typedef struct {
} pd_staking_force_new_era_always_V18_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V18 17
typedef struct {
    pd_EraIndex_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V18_t;

#define PD_CALL_STAKING_REAP_STASH_V18 20
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V18_t;

#define PD_CALL_STAKING_KICK_V18 21
typedef struct {
    pd_VecAccountIdLookupOfT_t who;
} pd_staking_kick_V18_t;

#define PD_CALL_STAKING_SET_STAKING_CONFIGS_V18 22
typedef struct {
    pd_ConfigOpBalanceOfT_t min_nominator_bond;
    pd_ConfigOpBalanceOfT_t min_validator_bond;
    pd_ConfigOpu32_t max_nominator_count;
    pd_ConfigOpu32_t max_validator_count;
    pd_ConfigOpPercent_t chill_threshold;
    pd_ConfigOpPerbill_t min_commission;
} pd_staking_set_staking_configs_V18_t;

#define PD_CALL_STAKING_CHILL_OTHER_V18 23
typedef struct {
    pd_AccountId_t controller;
} pd_staking_chill_other_V18_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V18 24
typedef struct {
    pd_AccountId_t validator_stash;
} pd_staking_force_apply_min_commission_V18_t;

#define PD_CALL_STAKING_SET_MIN_COMMISSION_V18 25
typedef struct {
    pd_Perbill_t new_;
} pd_staking_set_min_commission_V18_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V18 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V18_t;

#define PD_CALL_MULTISIG_AS_MULTI_V18 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V18_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V18 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V18_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V18 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V18_t;

#define PD_CALL_CONTRACTS_CALL_OLD_WEIGHT_V18 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t data;
} pd_contracts_call_old_weight_V18_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_OLD_WEIGHT_V18 1
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_with_code_old_weight_V18_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_OLD_WEIGHT_V18 2
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_CodeHash_t code_hash;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_old_weight_V18_t;

#define PD_CALL_CONTRACTS_UPLOAD_CODE_V18 3
typedef struct {
    pd_Vecu8_t code;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Determinism_t determinism;
} pd_contracts_upload_code_V18_t;

#define PD_CALL_CONTRACTS_REMOVE_CODE_V18 4
typedef struct {
    pd_CodeHash_t code_hash;
} pd_contracts_remove_code_V18_t;

#define PD_CALL_CONTRACTS_SET_CODE_V18 5
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CodeHash_t code_hash;
} pd_contracts_set_code_V18_t;

#define PD_CALL_CONTRACTS_CALL_V18 6
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t data;
} pd_contracts_call_V18_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_V18 7
typedef struct {
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_with_code_V18_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_V18 8
typedef struct {
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_CodeHash_t code_hash;
    pd_Bytes_t data;
    pd_Bytes_t salt;
} pd_contracts_instantiate_V18_t;

#define PD_CALL_CONTRACTS_MIGRATE_V18 9
typedef struct {
    pd_Weight_t weight_limit;
} pd_contracts_migrate_V18_t;

#define PD_CALL_NOMINATIONPOOLS_JOIN_V18 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_PoolId_t pool_id;
} pd_nominationpools_join_V18_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_V18 1
typedef struct {
    pd_BondExtraBalanceOfT_t extra;
} pd_nominationpools_bond_extra_V18_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_V18 2
typedef struct {
} pd_nominationpools_claim_payout_V18_t;

#define PD_CALL_NOMINATIONPOOLS_UNBOND_V18 3
typedef struct {
    pd_AccountIdLookupOfT_t member_account;
    pd_CompactBalance_t unbonding_points;
} pd_nominationpools_unbond_V18_t;

#define PD_CALL_NOMINATIONPOOLS_WITHDRAW_UNBONDED_V18 5
typedef struct {
    pd_AccountIdLookupOfT_t member_account;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_withdraw_unbonded_V18_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_V18 6
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t root;
    pd_AccountIdLookupOfT_t nominator;
    pd_AccountIdLookupOfT_t bouncer;
} pd_nominationpools_create_V18_t;

#define PD_CALL_NOMINATIONPOOLS_NOMINATE_V18 8
typedef struct {
    pd_PoolId_t pool_id;
    pd_VecAccountId_t validators;
} pd_nominationpools_nominate_V18_t;

#define PD_CALL_NOMINATIONPOOLS_SET_STATE_V18 9
typedef struct {
    pd_PoolId_t pool_id;
    pd_PoolState_t state;
} pd_nominationpools_set_state_V18_t;

#define PD_CALL_NOMINATIONPOOLS_SET_METADATA_V18 10
typedef struct {
    pd_PoolId_t pool_id;
    pd_Vecu8_t metadata;
} pd_nominationpools_set_metadata_V18_t;

#define PD_CALL_NOMINATIONPOOLS_UPDATE_ROLES_V18 12
typedef struct {
    pd_PoolId_t pool_id;
    pd_ConfigOpAccountId_t new_root;
    pd_ConfigOpAccountId_t new_nominator;
    pd_ConfigOpAccountId_t new_bouncer;
} pd_nominationpools_update_roles_V18_t;

#define PD_CALL_NOMINATIONPOOLS_CHILL_V18 13
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_chill_V18_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CLAIM_PERMISSION_V18 15
typedef struct {
    pd_ClaimPermission_t permission;
} pd_nominationpools_set_claim_permission_V18_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_OTHER_V18 16
typedef struct {
    pd_AccountId_t other;
} pd_nominationpools_claim_payout_other_V18_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_V18 17
typedef struct {
    pd_PoolId_t pool_id;
    pd_OptionTuplePerbillAccountId_t new_commission;
} pd_nominationpools_set_commission_V18_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_MAX_V18 18
typedef struct {
    pd_PoolId_t pool_id;
    pd_Perbill_t max_commission;
} pd_nominationpools_set_commission_max_V18_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_CHANGE_RATE_V18 19
typedef struct {
    pd_PoolId_t pool_id;
    pd_CommissionChangeRateBlockNumber_t change_rate;
} pd_nominationpools_set_commission_change_rate_V18_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_COMMISSION_V18 20
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_claim_commission_V18_t;

#define PD_CALL_PROXY_PROXY_V18 0
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V18_t;

#define PD_CALL_PROXY_ADD_PROXY_V18 1
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V18_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V18 2
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V18_t;

#define PD_CALL_PROXY_CREATE_PURE_V18 4
typedef struct {
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_create_pure_V18_t;

#define PD_CALL_PROXY_KILL_PURE_V18 5
typedef struct {
    pd_AccountIdLookupOfT_t spawner;
    pd_ProxyType_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_pure_V18_t;

#endif

typedef union {
    pd_balances_transfer_allow_death_V18_t balances_transfer_allow_death_V18;
    pd_balances_force_transfer_V18_t balances_force_transfer_V18;
    pd_balances_transfer_keep_alive_V18_t balances_transfer_keep_alive_V18;
    pd_balances_transfer_all_V18_t balances_transfer_all_V18;
    pd_staking_bond_V18_t staking_bond_V18;
    pd_staking_bond_extra_V18_t staking_bond_extra_V18;
    pd_staking_unbond_V18_t staking_unbond_V18;
    pd_staking_withdraw_unbonded_V18_t staking_withdraw_unbonded_V18;
    pd_staking_validate_V18_t staking_validate_V18;
    pd_staking_nominate_V18_t staking_nominate_V18;
    pd_staking_chill_V18_t staking_chill_V18;
    pd_staking_set_payee_V18_t staking_set_payee_V18;
    pd_staking_set_controller_V18_t staking_set_controller_V18;
    pd_staking_payout_stakers_V18_t staking_payout_stakers_V18;
    pd_staking_rebond_V18_t staking_rebond_V18;
    pd_session_set_keys_V18_t session_set_keys_V18;
    pd_session_purge_keys_V18_t session_purge_keys_V18;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_remark_V18_t system_remark_V18;
    pd_system_set_heap_pages_V18_t system_set_heap_pages_V18;
    pd_system_set_code_V18_t system_set_code_V18;
    pd_system_set_code_without_checks_V18_t system_set_code_without_checks_V18;
    pd_system_remark_with_event_V18_t system_remark_with_event_V18;
    pd_staking_set_validator_count_V18_t staking_set_validator_count_V18;
    pd_staking_increase_validator_count_V18_t staking_increase_validator_count_V18;
    pd_staking_scale_validator_count_V18_t staking_scale_validator_count_V18;
    pd_staking_force_no_eras_V18_t staking_force_no_eras_V18;
    pd_staking_force_new_era_V18_t staking_force_new_era_V18;
    pd_staking_set_invulnerables_V18_t staking_set_invulnerables_V18;
    pd_staking_force_unstake_V18_t staking_force_unstake_V18;
    pd_staking_force_new_era_always_V18_t staking_force_new_era_always_V18;
    pd_staking_cancel_deferred_slash_V18_t staking_cancel_deferred_slash_V18;
    pd_staking_reap_stash_V18_t staking_reap_stash_V18;
    pd_staking_kick_V18_t staking_kick_V18;
    pd_staking_set_staking_configs_V18_t staking_set_staking_configs_V18;
    pd_staking_chill_other_V18_t staking_chill_other_V18;
    pd_staking_force_apply_min_commission_V18_t staking_force_apply_min_commission_V18;
    pd_staking_set_min_commission_V18_t staking_set_min_commission_V18;
    pd_multisig_as_multi_threshold_1_V18_t multisig_as_multi_threshold_1_V18;
    pd_multisig_as_multi_V18_t multisig_as_multi_V18;
    pd_multisig_approve_as_multi_V18_t multisig_approve_as_multi_V18;
    pd_multisig_cancel_as_multi_V18_t multisig_cancel_as_multi_V18;
    pd_contracts_call_old_weight_V18_t contracts_call_old_weight_V18;
    pd_contracts_instantiate_with_code_old_weight_V18_t contracts_instantiate_with_code_old_weight_V18;
    pd_contracts_instantiate_old_weight_V18_t contracts_instantiate_old_weight_V18;
    pd_contracts_upload_code_V18_t contracts_upload_code_V18;
    pd_contracts_remove_code_V18_t contracts_remove_code_V18;
    pd_contracts_set_code_V18_t contracts_set_code_V18;
    pd_contracts_call_V18_t contracts_call_V18;
    pd_contracts_instantiate_with_code_V18_t contracts_instantiate_with_code_V18;
    pd_contracts_instantiate_V18_t contracts_instantiate_V18;
    pd_contracts_migrate_V18_t contracts_migrate_V18;
    pd_nominationpools_join_V18_t nominationpools_join_V18;
    pd_nominationpools_bond_extra_V18_t nominationpools_bond_extra_V18;
    pd_nominationpools_claim_payout_V18_t nominationpools_claim_payout_V18;
    pd_nominationpools_unbond_V18_t nominationpools_unbond_V18;
    pd_nominationpools_withdraw_unbonded_V18_t nominationpools_withdraw_unbonded_V18;
    pd_nominationpools_create_V18_t nominationpools_create_V18;
    pd_nominationpools_nominate_V18_t nominationpools_nominate_V18;
    pd_nominationpools_set_state_V18_t nominationpools_set_state_V18;
    pd_nominationpools_set_metadata_V18_t nominationpools_set_metadata_V18;
    pd_nominationpools_update_roles_V18_t nominationpools_update_roles_V18;
    pd_nominationpools_chill_V18_t nominationpools_chill_V18;
    pd_nominationpools_set_claim_permission_V18_t nominationpools_set_claim_permission_V18;
    pd_nominationpools_claim_payout_other_V18_t nominationpools_claim_payout_other_V18;
    pd_nominationpools_set_commission_V18_t nominationpools_set_commission_V18;
    pd_nominationpools_set_commission_max_V18_t nominationpools_set_commission_max_V18;
    pd_nominationpools_set_commission_change_rate_V18_t nominationpools_set_commission_change_rate_V18;
    pd_nominationpools_claim_commission_V18_t nominationpools_claim_commission_V18;
    pd_proxy_proxy_V18_t proxy_proxy_V18;
    pd_proxy_add_proxy_V18_t proxy_add_proxy_V18;
    pd_proxy_remove_proxy_V18_t proxy_remove_proxy_V18;
    pd_proxy_create_pure_V18_t proxy_create_pure_V18;
    pd_proxy_kill_pure_V18_t proxy_kill_pure_V18;
#endif
} pd_MethodNested_V18_t;

typedef union {
    pd_MethodBasic_V18_t basic;
    pd_MethodNested_V18_t nested;
} pd_Method_V18_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
