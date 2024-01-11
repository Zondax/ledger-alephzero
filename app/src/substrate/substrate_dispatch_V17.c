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

#include "substrate_dispatch_V17.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_allow_death_V17(
    parser_context_t* c, pd_balances_transfer_allow_death_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V17(
    parser_context_t* c, pd_balances_force_transfer_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V17(
    parser_context_t* c, pd_balances_transfer_keep_alive_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V17(
    parser_context_t* c, pd_balances_transfer_all_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V17(
    parser_context_t* c, pd_balances_transfer_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V17(
    parser_context_t* c, pd_staking_bond_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V17(
    parser_context_t* c, pd_staking_bond_extra_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V17(
    parser_context_t* c, pd_staking_unbond_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V17(
    parser_context_t* c, pd_staking_withdraw_unbonded_V17_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V17(
    parser_context_t* c, pd_staking_validate_V17_t* m)
{
    CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V17(
    parser_context_t* c, pd_staking_nominate_V17_t* m)
{
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V17(
    parser_context_t* c, pd_staking_chill_V17_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V17(
    parser_context_t* c, pd_staking_set_payee_V17_t* m)
{
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V17(
    parser_context_t* c, pd_staking_set_controller_V17_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V17(
    parser_context_t* c, pd_staking_payout_stakers_V17_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V17(
    parser_context_t* c, pd_staking_rebond_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V17(
    parser_context_t* c, pd_session_set_keys_V17_t* m)
{
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V17(
    parser_context_t* c, pd_session_purge_keys_V17_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V17(
    parser_context_t* c, pd_utility_batch_V17_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V17(
    parser_context_t* c, pd_utility_batch_all_V17_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V17(
    parser_context_t* c, pd_utility_force_batch_V17_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V17(
    parser_context_t* c, pd_system_remark_V17_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V17(
    parser_context_t* c, pd_system_set_heap_pages_V17_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V17(
    parser_context_t* c, pd_system_set_code_V17_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V17(
    parser_context_t* c, pd_system_set_code_without_checks_V17_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V17(
    parser_context_t* c, pd_system_remark_with_event_V17_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_deprecated_V17(
    parser_context_t* c, pd_balances_set_balance_deprecated_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->old_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V17(
    parser_context_t* c, pd_balances_force_unreserve_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_upgrade_accounts_V17(
    parser_context_t* c, pd_balances_upgrade_accounts_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_set_balance_V17(
    parser_context_t* c, pd_balances_force_set_balance_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V17(
    parser_context_t* c, pd_staking_set_validator_count_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V17(
    parser_context_t* c, pd_staking_increase_validator_count_V17_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V17(
    parser_context_t* c, pd_staking_scale_validator_count_V17_t* m)
{
    CHECK_ERROR(_readPercent(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V17(
    parser_context_t* c, pd_staking_force_no_eras_V17_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V17(
    parser_context_t* c, pd_staking_force_new_era_V17_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V17(
    parser_context_t* c, pd_staking_set_invulnerables_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V17(
    parser_context_t* c, pd_staking_force_unstake_V17_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V17(
    parser_context_t* c, pd_staking_force_new_era_always_V17_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V17(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V17_t* m)
{
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V17(
    parser_context_t* c, pd_staking_reap_stash_V17_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V17(
    parser_context_t* c, pd_staking_kick_V17_t* m)
{
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_staking_configs_V17(
    parser_context_t* c, pd_staking_set_staking_configs_V17_t* m)
{
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_nominator_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_validator_bond))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_nominator_count))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_validator_count))
    CHECK_ERROR(_readConfigOpPercent(c, &m->chill_threshold))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->min_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V17(
    parser_context_t* c, pd_staking_chill_other_V17_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_apply_min_commission_V17(
    parser_context_t* c, pd_staking_force_apply_min_commission_V17_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_commission_V17(
    parser_context_t* c, pd_staking_set_min_commission_V17_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V17(
    parser_context_t* c, pd_vesting_vest_V17_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V17(
    parser_context_t* c, pd_vesting_vest_other_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V17(
    parser_context_t* c, pd_vesting_vested_transfer_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V17(
    parser_context_t* c, pd_vesting_force_vested_transfer_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_merge_schedules_V17(
    parser_context_t* c, pd_vesting_merge_schedules_V17_t* m)
{
    CHECK_ERROR(_readu32(c, &m->schedule1_index))
    CHECK_ERROR(_readu32(c, &m->schedule2_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_dispatch_as_V17(
    parser_context_t* c, pd_utility_dispatch_as_V17_t* m)
{
    CHECK_ERROR(_readBoxPalletsOrigin(c, &m->as_origin))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V17(
    parser_context_t* c, pd_utility_with_weight_V17_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V17(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V17_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V17(
    parser_context_t* c, pd_multisig_as_multi_V17_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V17(
    parser_context_t* c, pd_multisig_approve_as_multi_V17_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V17(
    parser_context_t* c, pd_multisig_cancel_as_multi_V17_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_V17(
    parser_context_t* c, pd_sudo_sudo_V17_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight_V17(
    parser_context_t* c, pd_sudo_sudo_unchecked_weight_V17_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V17(
    parser_context_t* c, pd_sudo_set_key_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as_V17(
    parser_context_t* c, pd_sudo_sudo_as_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_call_old_weight_V17(
    parser_context_t* c, pd_contracts_call_old_weight_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readVecu8(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_with_code_old_weight_V17(
    parser_context_t* c, pd_contracts_instantiate_with_code_old_weight_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readVecu8(c, &m->code))
    CHECK_ERROR(_readVecu8(c, &m->data))
    CHECK_ERROR(_readVecu8(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_old_weight_V17(
    parser_context_t* c, pd_contracts_instantiate_old_weight_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    CHECK_ERROR(_readVecu8(c, &m->data))
    CHECK_ERROR(_readVecu8(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_upload_code_V17(
    parser_context_t* c, pd_contracts_upload_code_V17_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readDeterminism(c, &m->determinism))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_remove_code_V17(
    parser_context_t* c, pd_contracts_remove_code_V17_t* m)
{
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_set_code_V17(
    parser_context_t* c, pd_contracts_set_code_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_call_V17(
    parser_context_t* c, pd_contracts_call_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readVecu8(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_with_code_V17(
    parser_context_t* c, pd_contracts_instantiate_with_code_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readVecu8(c, &m->code))
    CHECK_ERROR(_readVecu8(c, &m->data))
    CHECK_ERROR(_readVecu8(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_V17(
    parser_context_t* c, pd_contracts_instantiate_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    CHECK_ERROR(_readBytes(c, &m->data))
    CHECK_ERROR(_readBytes(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_migrate_V17(
    parser_context_t* c, pd_contracts_migrate_V17_t* m)
{
    CHECK_ERROR(_readWeight(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_join_V17(
    parser_context_t* c, pd_nominationpools_join_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_bond_extra_V17(
    parser_context_t* c, pd_nominationpools_bond_extra_V17_t* m)
{
    CHECK_ERROR(_readBondExtraBalanceOfT(c, &m->extra))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_claim_payout_V17(
    parser_context_t* c, pd_nominationpools_claim_payout_V17_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_unbond_V17(
    parser_context_t* c, pd_nominationpools_unbond_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member_account))
    CHECK_ERROR(_readCompactBalance(c, &m->unbonding_points))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_pool_withdraw_unbonded_V17(
    parser_context_t* c, pd_nominationpools_pool_withdraw_unbonded_V17_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_withdraw_unbonded_V17(
    parser_context_t* c, pd_nominationpools_withdraw_unbonded_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member_account))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_create_V17(
    parser_context_t* c, pd_nominationpools_create_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->root))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->nominator))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->bouncer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_create_with_pool_id_V17(
    parser_context_t* c, pd_nominationpools_create_with_pool_id_V17_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->root))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->nominator))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->bouncer))
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_nominate_V17(
    parser_context_t* c, pd_nominationpools_nominate_V17_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readVecAccountId(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_state_V17(
    parser_context_t* c, pd_nominationpools_set_state_V17_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readPoolState(c, &m->state))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_metadata_V17(
    parser_context_t* c, pd_nominationpools_set_metadata_V17_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readVecu8(c, &m->metadata))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_configs_V17(
    parser_context_t* c, pd_nominationpools_set_configs_V17_t* m)
{
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_join_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_create_bond))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_pools))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_members))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_members_per_pool))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->global_max_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_update_roles_V17(
    parser_context_t* c, pd_nominationpools_update_roles_V17_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readConfigOpAccountId(c, &m->new_root))
    CHECK_ERROR(_readConfigOpAccountId(c, &m->new_nominator))
    CHECK_ERROR(_readConfigOpAccountId(c, &m->new_bouncer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_chill_V17(
    parser_context_t* c, pd_nominationpools_chill_V17_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_bond_extra_other_V17(
    parser_context_t* c, pd_nominationpools_bond_extra_other_V17_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member))
    CHECK_ERROR(_readBondExtraBalanceOfT(c, &m->extra))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_claim_permission_V17(
    parser_context_t* c, pd_nominationpools_set_claim_permission_V17_t* m)
{
    CHECK_ERROR(_readClaimPermission(c, &m->permission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_claim_payout_other_V17(
    parser_context_t* c, pd_nominationpools_claim_payout_other_V17_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->other))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_commission_V17(
    parser_context_t* c, pd_nominationpools_set_commission_V17_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readOptionTuplePerbillAccountId(c, &m->new_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_commission_max_V17(
    parser_context_t* c, pd_nominationpools_set_commission_max_V17_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readPerbill(c, &m->max_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_commission_change_rate_V17(
    parser_context_t* c, pd_nominationpools_set_commission_change_rate_V17_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readCommissionChangeRateBlockNumber(c, &m->change_rate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_claim_commission_V17(
    parser_context_t* c, pd_nominationpools_claim_commission_V17_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V17(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V17_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_allow_death_V17(c, &method->nested.balances_transfer_allow_death_V17))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V17(c, &method->nested.balances_force_transfer_V17))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V17(c, &method->nested.balances_transfer_keep_alive_V17))
        break;
    case 1284: /* module 5 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V17(c, &method->nested.balances_transfer_all_V17))
        break;
    case 1287: /* module 5 call 7 */
        CHECK_ERROR(_readMethod_balances_transfer_V17(c, &method->nested.balances_transfer_V17))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V17(c, &method->nested.staking_bond_V17))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V17(c, &method->nested.staking_bond_extra_V17))
        break;
    case 2050: /* module 8 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V17(c, &method->nested.staking_unbond_V17))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V17(c, &method->nested.staking_withdraw_unbonded_V17))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V17(c, &method->nested.staking_validate_V17))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V17(c, &method->nested.staking_nominate_V17))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V17(c, &method->nested.staking_chill_V17))
        break;
    case 2055: /* module 8 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V17(c, &method->nested.staking_set_payee_V17))
        break;
    case 2056: /* module 8 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V17(c, &method->nested.staking_set_controller_V17))
        break;
    case 2066: /* module 8 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V17(c, &method->nested.staking_payout_stakers_V17))
        break;
    case 2067: /* module 8 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V17(c, &method->nested.staking_rebond_V17))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V17(c, &method->nested.session_set_keys_V17))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V17(c, &method->nested.session_purge_keys_V17))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V17(c, &method->basic.utility_batch_V17))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V17(c, &method->basic.utility_batch_all_V17))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V17(c, &method->basic.utility_force_batch_V17))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_remark_V17(c, &method->nested.system_remark_V17))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V17(c, &method->nested.system_set_heap_pages_V17))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_code_V17(c, &method->nested.system_set_code_V17))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V17(c, &method->nested.system_set_code_without_checks_V17))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V17(c, &method->nested.system_remark_with_event_V17))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_deprecated_V17(c, &method->nested.balances_set_balance_deprecated_V17))
        break;
    case 1285: /* module 5 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V17(c, &method->basic.balances_force_unreserve_V17))
        break;
    case 1286: /* module 5 call 6 */
        CHECK_ERROR(_readMethod_balances_upgrade_accounts_V17(c, &method->basic.balances_upgrade_accounts_V17))
        break;
    case 1288: /* module 5 call 8 */
        CHECK_ERROR(_readMethod_balances_force_set_balance_V17(c, &method->basic.balances_force_set_balance_V17))
        break;
    case 2057: /* module 8 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V17(c, &method->nested.staking_set_validator_count_V17))
        break;
    case 2058: /* module 8 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V17(c, &method->nested.staking_increase_validator_count_V17))
        break;
    case 2059: /* module 8 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V17(c, &method->nested.staking_scale_validator_count_V17))
        break;
    case 2060: /* module 8 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V17(c, &method->nested.staking_force_no_eras_V17))
        break;
    case 2061: /* module 8 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V17(c, &method->nested.staking_force_new_era_V17))
        break;
    case 2062: /* module 8 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V17(c, &method->nested.staking_set_invulnerables_V17))
        break;
    case 2063: /* module 8 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V17(c, &method->nested.staking_force_unstake_V17))
        break;
    case 2064: /* module 8 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V17(c, &method->nested.staking_force_new_era_always_V17))
        break;
    case 2065: /* module 8 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V17(c, &method->nested.staking_cancel_deferred_slash_V17))
        break;
    case 2068: /* module 8 call 20 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V17(c, &method->nested.staking_reap_stash_V17))
        break;
    case 2069: /* module 8 call 21 */
        CHECK_ERROR(_readMethod_staking_kick_V17(c, &method->nested.staking_kick_V17))
        break;
    case 2070: /* module 8 call 22 */
        CHECK_ERROR(_readMethod_staking_set_staking_configs_V17(c, &method->nested.staking_set_staking_configs_V17))
        break;
    case 2071: /* module 8 call 23 */
        CHECK_ERROR(_readMethod_staking_chill_other_V17(c, &method->nested.staking_chill_other_V17))
        break;
    case 2072: /* module 8 call 24 */
        CHECK_ERROR(_readMethod_staking_force_apply_min_commission_V17(c, &method->nested.staking_force_apply_min_commission_V17))
        break;
    case 2073: /* module 8 call 25 */
        CHECK_ERROR(_readMethod_staking_set_min_commission_V17(c, &method->nested.staking_set_min_commission_V17))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V17(c, &method->basic.vesting_vest_V17))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V17(c, &method->basic.vesting_vest_other_V17))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V17(c, &method->basic.vesting_vested_transfer_V17))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V17(c, &method->basic.vesting_force_vested_transfer_V17))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_vesting_merge_schedules_V17(c, &method->basic.vesting_merge_schedules_V17))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_utility_dispatch_as_V17(c, &method->basic.utility_dispatch_as_V17))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_utility_with_weight_V17(c, &method->basic.utility_with_weight_V17))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V17(c, &method->nested.multisig_as_multi_threshold_1_V17))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V17(c, &method->nested.multisig_as_multi_V17))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V17(c, &method->nested.multisig_approve_as_multi_V17))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V17(c, &method->nested.multisig_cancel_as_multi_V17))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_sudo_sudo_V17(c, &method->basic.sudo_sudo_V17))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight_V17(c, &method->basic.sudo_sudo_unchecked_weight_V17))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V17(c, &method->basic.sudo_set_key_V17))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_sudo_sudo_as_V17(c, &method->basic.sudo_sudo_as_V17))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_contracts_call_old_weight_V17(c, &method->nested.contracts_call_old_weight_V17))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_contracts_instantiate_with_code_old_weight_V17(c, &method->nested.contracts_instantiate_with_code_old_weight_V17))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_contracts_instantiate_old_weight_V17(c, &method->nested.contracts_instantiate_old_weight_V17))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_contracts_upload_code_V17(c, &method->nested.contracts_upload_code_V17))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_contracts_remove_code_V17(c, &method->nested.contracts_remove_code_V17))
        break;
    case 4613: /* module 18 call 5 */
        CHECK_ERROR(_readMethod_contracts_set_code_V17(c, &method->nested.contracts_set_code_V17))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_contracts_call_V17(c, &method->nested.contracts_call_V17))
        break;
    case 4615: /* module 18 call 7 */
        CHECK_ERROR(_readMethod_contracts_instantiate_with_code_V17(c, &method->nested.contracts_instantiate_with_code_V17))
        break;
    case 4616: /* module 18 call 8 */
        CHECK_ERROR(_readMethod_contracts_instantiate_V17(c, &method->nested.contracts_instantiate_V17))
        break;
    case 4617: /* module 18 call 9 */
        CHECK_ERROR(_readMethod_contracts_migrate_V17(c, &method->nested.contracts_migrate_V17))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_nominationpools_join_V17(c, &method->nested.nominationpools_join_V17))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_nominationpools_bond_extra_V17(c, &method->nested.nominationpools_bond_extra_V17))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_nominationpools_claim_payout_V17(c, &method->nested.nominationpools_claim_payout_V17))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_nominationpools_unbond_V17(c, &method->nested.nominationpools_unbond_V17))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_nominationpools_pool_withdraw_unbonded_V17(c, &method->basic.nominationpools_pool_withdraw_unbonded_V17))
        break;
    case 4869: /* module 19 call 5 */
        CHECK_ERROR(_readMethod_nominationpools_withdraw_unbonded_V17(c, &method->nested.nominationpools_withdraw_unbonded_V17))
        break;
    case 4870: /* module 19 call 6 */
        CHECK_ERROR(_readMethod_nominationpools_create_V17(c, &method->nested.nominationpools_create_V17))
        break;
    case 4871: /* module 19 call 7 */
        CHECK_ERROR(_readMethod_nominationpools_create_with_pool_id_V17(c, &method->basic.nominationpools_create_with_pool_id_V17))
        break;
    case 4872: /* module 19 call 8 */
        CHECK_ERROR(_readMethod_nominationpools_nominate_V17(c, &method->nested.nominationpools_nominate_V17))
        break;
    case 4873: /* module 19 call 9 */
        CHECK_ERROR(_readMethod_nominationpools_set_state_V17(c, &method->nested.nominationpools_set_state_V17))
        break;
    case 4874: /* module 19 call 10 */
        CHECK_ERROR(_readMethod_nominationpools_set_metadata_V17(c, &method->nested.nominationpools_set_metadata_V17))
        break;
    case 4875: /* module 19 call 11 */
        CHECK_ERROR(_readMethod_nominationpools_set_configs_V17(c, &method->basic.nominationpools_set_configs_V17))
        break;
    case 4876: /* module 19 call 12 */
        CHECK_ERROR(_readMethod_nominationpools_update_roles_V17(c, &method->nested.nominationpools_update_roles_V17))
        break;
    case 4877: /* module 19 call 13 */
        CHECK_ERROR(_readMethod_nominationpools_chill_V17(c, &method->nested.nominationpools_chill_V17))
        break;
    case 4878: /* module 19 call 14 */
        CHECK_ERROR(_readMethod_nominationpools_bond_extra_other_V17(c, &method->basic.nominationpools_bond_extra_other_V17))
        break;
    case 4879: /* module 19 call 15 */
        CHECK_ERROR(_readMethod_nominationpools_set_claim_permission_V17(c, &method->nested.nominationpools_set_claim_permission_V17))
        break;
    case 4880: /* module 19 call 16 */
        CHECK_ERROR(_readMethod_nominationpools_claim_payout_other_V17(c, &method->nested.nominationpools_claim_payout_other_V17))
        break;
    case 4881: /* module 19 call 17 */
        CHECK_ERROR(_readMethod_nominationpools_set_commission_V17(c, &method->nested.nominationpools_set_commission_V17))
        break;
    case 4882: /* module 19 call 18 */
        CHECK_ERROR(_readMethod_nominationpools_set_commission_max_V17(c, &method->nested.nominationpools_set_commission_max_V17))
        break;
    case 4883: /* module 19 call 19 */
        CHECK_ERROR(_readMethod_nominationpools_set_commission_change_rate_V17(c, &method->nested.nominationpools_set_commission_change_rate_V17))
        break;
    case 4884: /* module 19 call 20 */
        CHECK_ERROR(_readMethod_nominationpools_claim_commission_V17(c, &method->nested.nominationpools_claim_commission_V17))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V17(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 5:
        return STR_MO_BALANCES;
    case 8:
        return STR_MO_STAKING;
    case 10:
        return STR_MO_SESSION;
    case 15:
        return STR_MO_UTILITY;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0:
        return STR_MO_SYSTEM;
    case 14:
        return STR_MO_VESTING;
    case 16:
        return STR_MO_MULTISIG;
    case 17:
        return STR_MO_SUDO;
    case 18:
        return STR_MO_CONTRACTS;
    case 19:
        return STR_MO_NOMINATIONPOOLS;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V17(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        return STR_ME_TRANSFER_ALLOW_DEATH;
    case 1282: /* module 5 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1283: /* module 5 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1284: /* module 5 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 1287: /* module 5 call 7 */
        return STR_ME_TRANSFER;
    case 2048: /* module 8 call 0 */
        return STR_ME_BOND;
    case 2049: /* module 8 call 1 */
        return STR_ME_BOND_EXTRA;
    case 2050: /* module 8 call 2 */
        return STR_ME_UNBOND;
    case 2051: /* module 8 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 2052: /* module 8 call 4 */
        return STR_ME_VALIDATE;
    case 2053: /* module 8 call 5 */
        return STR_ME_NOMINATE;
    case 2054: /* module 8 call 6 */
        return STR_ME_CHILL;
    case 2055: /* module 8 call 7 */
        return STR_ME_SET_PAYEE;
    case 2056: /* module 8 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 2066: /* module 8 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 2067: /* module 8 call 19 */
        return STR_ME_REBOND;
    case 2560: /* module 10 call 0 */
        return STR_ME_SET_KEYS;
    case 2561: /* module 10 call 1 */
        return STR_ME_PURGE_KEYS;
    case 3840: /* module 15 call 0 */
        return STR_ME_BATCH;
    case 3842: /* module 15 call 2 */
        return STR_ME_BATCH_ALL;
    case 3844: /* module 15 call 4 */
        return STR_ME_FORCE_BATCH;
    default:
        return _getMethod_Name_V17_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V17_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0: /* module 0 call 0 */
        return STR_ME_REMARK;
    case 1: /* module 0 call 1 */
        return STR_ME_SET_HEAP_PAGES;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_CODE;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 7: /* module 0 call 7 */
        return STR_ME_REMARK_WITH_EVENT;
    case 1281: /* module 5 call 1 */
        return STR_ME_SET_BALANCE_DEPRECATED;
    case 1285: /* module 5 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 1286: /* module 5 call 6 */
        return STR_ME_UPGRADE_ACCOUNTS;
    case 1288: /* module 5 call 8 */
        return STR_ME_FORCE_SET_BALANCE;
    case 2057: /* module 8 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 2058: /* module 8 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 2059: /* module 8 call 11 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 2060: /* module 8 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 2061: /* module 8 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 2062: /* module 8 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 2063: /* module 8 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 2064: /* module 8 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 2065: /* module 8 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 2068: /* module 8 call 20 */
        return STR_ME_REAP_STASH;
    case 2069: /* module 8 call 21 */
        return STR_ME_KICK;
    case 2070: /* module 8 call 22 */
        return STR_ME_SET_STAKING_CONFIGS;
    case 2071: /* module 8 call 23 */
        return STR_ME_CHILL_OTHER;
    case 2072: /* module 8 call 24 */
        return STR_ME_FORCE_APPLY_MIN_COMMISSION;
    case 2073: /* module 8 call 25 */
        return STR_ME_SET_MIN_COMMISSION;
    case 3584: /* module 14 call 0 */
        return STR_ME_VEST;
    case 3585: /* module 14 call 1 */
        return STR_ME_VEST_OTHER;
    case 3586: /* module 14 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 3587: /* module 14 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 3588: /* module 14 call 4 */
        return STR_ME_MERGE_SCHEDULES;
    case 3843: /* module 15 call 3 */
        return STR_ME_DISPATCH_AS;
    case 3845: /* module 15 call 5 */
        return STR_ME_WITH_WEIGHT;
    case 4096: /* module 16 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 4097: /* module 16 call 1 */
        return STR_ME_AS_MULTI;
    case 4098: /* module 16 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 4099: /* module 16 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 4352: /* module 17 call 0 */
        return STR_ME_SUDO;
    case 4353: /* module 17 call 1 */
        return STR_ME_SUDO_UNCHECKED_WEIGHT;
    case 4354: /* module 17 call 2 */
        return STR_ME_SET_KEY;
    case 4355: /* module 17 call 3 */
        return STR_ME_SUDO_AS;
    case 4608: /* module 18 call 0 */
        return STR_ME_CALL_OLD_WEIGHT;
    case 4609: /* module 18 call 1 */
        return STR_ME_INSTANTIATE_WITH_CODE_OLD_WEIGHT;
    case 4610: /* module 18 call 2 */
        return STR_ME_INSTANTIATE_OLD_WEIGHT;
    case 4611: /* module 18 call 3 */
        return STR_ME_UPLOAD_CODE;
    case 4612: /* module 18 call 4 */
        return STR_ME_REMOVE_CODE;
    case 4613: /* module 18 call 5 */
        return STR_ME_SET_CODE;
    case 4614: /* module 18 call 6 */
        return STR_ME_CALL;
    case 4615: /* module 18 call 7 */
        return STR_ME_INSTANTIATE_WITH_CODE;
    case 4616: /* module 18 call 8 */
        return STR_ME_INSTANTIATE;
    case 4617: /* module 18 call 9 */
        return STR_ME_MIGRATE;
    case 4864: /* module 19 call 0 */
        return STR_ME_JOIN;
    case 4865: /* module 19 call 1 */
        return STR_ME_BOND_EXTRA;
    case 4866: /* module 19 call 2 */
        return STR_ME_CLAIM_PAYOUT;
    case 4867: /* module 19 call 3 */
        return STR_ME_UNBOND;
    case 4868: /* module 19 call 4 */
        return STR_ME_POOL_WITHDRAW_UNBONDED;
    case 4869: /* module 19 call 5 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 4870: /* module 19 call 6 */
        return STR_ME_CREATE;
    case 4871: /* module 19 call 7 */
        return STR_ME_CREATE_WITH_POOL_ID;
    case 4872: /* module 19 call 8 */
        return STR_ME_NOMINATE;
    case 4873: /* module 19 call 9 */
        return STR_ME_SET_STATE;
    case 4874: /* module 19 call 10 */
        return STR_ME_SET_METADATA;
    case 4875: /* module 19 call 11 */
        return STR_ME_SET_CONFIGS;
    case 4876: /* module 19 call 12 */
        return STR_ME_UPDATE_ROLES;
    case 4877: /* module 19 call 13 */
        return STR_ME_CHILL;
    case 4878: /* module 19 call 14 */
        return STR_ME_BOND_EXTRA_OTHER;
    case 4879: /* module 19 call 15 */
        return STR_ME_SET_CLAIM_PERMISSION;
    case 4880: /* module 19 call 16 */
        return STR_ME_CLAIM_PAYOUT_OTHER;
    case 4881: /* module 19 call 17 */
        return STR_ME_SET_COMMISSION;
    case 4882: /* module 19 call 18 */
        return STR_ME_SET_COMMISSION_MAX;
    case 4883: /* module 19 call 19 */
        return STR_ME_SET_COMMISSION_CHANGE_RATE;
    case 4884: /* module 19 call 20 */
        return STR_ME_CLAIM_COMMISSION;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V17(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        return 2;
    case 1282: /* module 5 call 2 */
        return 3;
    case 1283: /* module 5 call 3 */
        return 2;
    case 1284: /* module 5 call 4 */
        return 2;
    case 1287: /* module 5 call 7 */
        return 2;
    case 2048: /* module 8 call 0 */
        return 2;
    case 2049: /* module 8 call 1 */
        return 1;
    case 2050: /* module 8 call 2 */
        return 1;
    case 2051: /* module 8 call 3 */
        return 1;
    case 2052: /* module 8 call 4 */
        return 1;
    case 2053: /* module 8 call 5 */
        return 1;
    case 2054: /* module 8 call 6 */
        return 0;
    case 2055: /* module 8 call 7 */
        return 1;
    case 2056: /* module 8 call 8 */
        return 0;
    case 2066: /* module 8 call 18 */
        return 2;
    case 2067: /* module 8 call 19 */
        return 1;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2561: /* module 10 call 1 */
        return 0;
    case 3840: /* module 15 call 0 */
        return 1;
    case 3842: /* module 15 call 2 */
        return 1;
    case 3844: /* module 15 call 4 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 1281: /* module 5 call 1 */
        return 3;
    case 1285: /* module 5 call 5 */
        return 2;
    case 1286: /* module 5 call 6 */
        return 1;
    case 1288: /* module 5 call 8 */
        return 2;
    case 2057: /* module 8 call 9 */
        return 1;
    case 2058: /* module 8 call 10 */
        return 1;
    case 2059: /* module 8 call 11 */
        return 1;
    case 2060: /* module 8 call 12 */
        return 0;
    case 2061: /* module 8 call 13 */
        return 0;
    case 2062: /* module 8 call 14 */
        return 1;
    case 2063: /* module 8 call 15 */
        return 2;
    case 2064: /* module 8 call 16 */
        return 0;
    case 2065: /* module 8 call 17 */
        return 2;
    case 2068: /* module 8 call 20 */
        return 2;
    case 2069: /* module 8 call 21 */
        return 1;
    case 2070: /* module 8 call 22 */
        return 6;
    case 2071: /* module 8 call 23 */
        return 1;
    case 2072: /* module 8 call 24 */
        return 1;
    case 2073: /* module 8 call 25 */
        return 1;
    case 3584: /* module 14 call 0 */
        return 0;
    case 3585: /* module 14 call 1 */
        return 1;
    case 3586: /* module 14 call 2 */
        return 2;
    case 3587: /* module 14 call 3 */
        return 3;
    case 3588: /* module 14 call 4 */
        return 2;
    case 3843: /* module 15 call 3 */
        return 2;
    case 3845: /* module 15 call 5 */
        return 2;
    case 4096: /* module 16 call 0 */
        return 2;
    case 4097: /* module 16 call 1 */
        return 5;
    case 4098: /* module 16 call 2 */
        return 5;
    case 4099: /* module 16 call 3 */
        return 4;
    case 4352: /* module 17 call 0 */
        return 1;
    case 4353: /* module 17 call 1 */
        return 2;
    case 4354: /* module 17 call 2 */
        return 1;
    case 4355: /* module 17 call 3 */
        return 2;
    case 4608: /* module 18 call 0 */
        return 5;
    case 4609: /* module 18 call 1 */
        return 6;
    case 4610: /* module 18 call 2 */
        return 6;
    case 4611: /* module 18 call 3 */
        return 3;
    case 4612: /* module 18 call 4 */
        return 1;
    case 4613: /* module 18 call 5 */
        return 2;
    case 4614: /* module 18 call 6 */
        return 5;
    case 4615: /* module 18 call 7 */
        return 6;
    case 4616: /* module 18 call 8 */
        return 6;
    case 4617: /* module 18 call 9 */
        return 1;
    case 4864: /* module 19 call 0 */
        return 2;
    case 4865: /* module 19 call 1 */
        return 1;
    case 4866: /* module 19 call 2 */
        return 0;
    case 4867: /* module 19 call 3 */
        return 2;
    case 4868: /* module 19 call 4 */
        return 2;
    case 4869: /* module 19 call 5 */
        return 2;
    case 4870: /* module 19 call 6 */
        return 4;
    case 4871: /* module 19 call 7 */
        return 5;
    case 4872: /* module 19 call 8 */
        return 2;
    case 4873: /* module 19 call 9 */
        return 2;
    case 4874: /* module 19 call 10 */
        return 2;
    case 4875: /* module 19 call 11 */
        return 6;
    case 4876: /* module 19 call 12 */
        return 4;
    case 4877: /* module 19 call 13 */
        return 1;
    case 4878: /* module 19 call 14 */
        return 2;
    case 4879: /* module 19 call 15 */
        return 1;
    case 4880: /* module 19 call 16 */
        return 1;
    case 4881: /* module 19 call 17 */
        return 2;
    case 4882: /* module 19 call 18 */
        return 2;
    case 4883: /* module 19 call 19 */
        return 2;
    case 4884: /* module 19 call 20 */
        return 1;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V17(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 1287: /* module 5 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_old_reserved;
        default:
            return NULL;
        }
    case 1285: /* module 5 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1286: /* module 5 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1288: /* module 5 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        default:
            return NULL;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_factor;
        default:
            return NULL;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_min_nominator_bond;
        case 1:
            return STR_IT_min_validator_bond;
        case 2:
            return STR_IT_max_nominator_count;
        case 3:
            return STR_IT_max_validator_count;
        case 4:
            return STR_IT_chill_threshold;
        case 5:
            return STR_IT_min_commission;
        default:
            return NULL;
        }
    case 2071: /* module 8 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 2072: /* module 8 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        default:
            return NULL;
        }
    case 2073: /* module 8 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_schedule1_index;
        case 1:
            return STR_IT_schedule2_index;
        default:
            return NULL;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_as_origin;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_gas_limit;
        case 3:
            return STR_IT_storage_deposit_limit;
        case 4:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code_hash;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        case 1:
            return STR_IT_storage_deposit_limit;
        case 2:
            return STR_IT_determinism;
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code_hash;
        default:
            return NULL;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_code_hash;
        default:
            return NULL;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_gas_limit;
        case 3:
            return STR_IT_storage_deposit_limit;
        case 4:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 4615: /* module 18 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code_hash;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 4617: /* module 18 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_extra;
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_member_account;
        case 1:
            return STR_IT_unbonding_points;
        default:
            return NULL;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 4869: /* module 19 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_member_account;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 4870: /* module 19 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_root;
        case 2:
            return STR_IT_nominator;
        case 3:
            return STR_IT_bouncer;
        default:
            return NULL;
        }
    case 4871: /* module 19 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_root;
        case 2:
            return STR_IT_nominator;
        case 3:
            return STR_IT_bouncer;
        case 4:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 4872: /* module 19 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_validators;
        default:
            return NULL;
        }
    case 4873: /* module 19 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_state;
        default:
            return NULL;
        }
    case 4874: /* module 19 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_metadata;
        default:
            return NULL;
        }
    case 4875: /* module 19 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_min_join_bond;
        case 1:
            return STR_IT_min_create_bond;
        case 2:
            return STR_IT_max_pools;
        case 3:
            return STR_IT_max_members;
        case 4:
            return STR_IT_max_members_per_pool;
        case 5:
            return STR_IT_global_max_commission;
        default:
            return NULL;
        }
    case 4876: /* module 19 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_new_root;
        case 2:
            return STR_IT_new_nominator;
        case 3:
            return STR_IT_new_bouncer;
        default:
            return NULL;
        }
    case 4877: /* module 19 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 4878: /* module 19 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_member;
        case 1:
            return STR_IT_extra;
        default:
            return NULL;
        }
    case 4879: /* module 19 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_permission;
        default:
            return NULL;
        }
    case 4880: /* module 19 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other;
        default:
            return NULL;
        }
    case 4881: /* module 19 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_new_commission;
        default:
            return NULL;
        }
    case 4882: /* module 19 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_max_commission;
        default:
            return NULL;
        }
    case 4883: /* module 19 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_change_rate;
        default:
            return NULL;
        }
    case 4884: /* module 19 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V17(
    pd_Method_V17_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_allow_death_V17 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_allow_death_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_allow_death_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_allow_death_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V17 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V17.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V17 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V17 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_keep_alive_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V17 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_all_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V17 - keep_alive */;
            return _toStringbool(
                &m->nested.balances_transfer_all_V17.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1287: /* module 5 call 7 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V17 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_bond_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V17 - payee */;
            return _toStringRewardDestination(
                &m->nested.staking_bond_V17.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_bond_extra_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_unbond_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V17 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_withdraw_unbonded_V17.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V17 - prefs */;
            return _toStringValidatorPrefs(
                &m->nested.staking_validate_V17.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V17 - targets */;
            return _toStringVecAccountIdLookupOfT(
                &m->nested.staking_nominate_V17.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V17 - payee */;
            return _toStringRewardDestination(
                &m->nested.staking_set_payee_V17.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V17 - validator_stash */;
            return _toStringAccountId(
                &m->nested.staking_payout_stakers_V17.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V17 - era */;
            return _toStringEraIndex(
                &m->nested.staking_payout_stakers_V17.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_rebond_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V17 - keys */;
            return _toStringKeys(
                &m->nested.session_set_keys_V17.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V17 - proof */;
            return _toStringBytes(
                &m->nested.session_set_keys_V17.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V17 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V17.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V17 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V17.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V17 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V17.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_remark_V17 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V17.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V17 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V17.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_code_V17 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V17.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V17 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V17.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V17 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V17.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_deprecated_V17 - who */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_set_balance_deprecated_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_deprecated_V17 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_deprecated_V17.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_deprecated_V17 - old_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_deprecated_V17.old_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1285: /* module 5 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V17 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_unreserve_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V17 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1286: /* module 5 call 6 */
        switch (itemIdx) {
        case 0: /* balances_upgrade_accounts_V17 - who */;
            return _toStringVecAccountId(
                &m->basic.balances_upgrade_accounts_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1288: /* module 5 call 8 */
        switch (itemIdx) {
        case 0: /* balances_force_set_balance_V17 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_set_balance_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_set_balance_V17 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_force_set_balance_V17.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V17 - new_ */;
            return _toStringCompactu32(
                &m->nested.staking_set_validator_count_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V17 - additional */;
            return _toStringCompactu32(
                &m->nested.staking_increase_validator_count_V17.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V17 - factor */;
            return _toStringPercent(
                &m->nested.staking_scale_validator_count_V17.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V17 - invulnerables */;
            return _toStringVecAccountId(
                &m->nested.staking_set_invulnerables_V17.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V17 - stash */;
            return _toStringAccountId(
                &m->nested.staking_force_unstake_V17.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V17 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_force_unstake_V17.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V17 - era */;
            return _toStringEraIndex(
                &m->nested.staking_cancel_deferred_slash_V17.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V17 - slash_indices */;
            return _toStringVecu32(
                &m->nested.staking_cancel_deferred_slash_V17.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V17 - stash */;
            return _toStringAccountId(
                &m->nested.staking_reap_stash_V17.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V17 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_reap_stash_V17.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        case 0: /* staking_kick_V17 - who */;
            return _toStringVecAccountIdLookupOfT(
                &m->nested.staking_kick_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0: /* staking_set_staking_configs_V17 - min_nominator_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->nested.staking_set_staking_configs_V17.min_nominator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_staking_configs_V17 - min_validator_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->nested.staking_set_staking_configs_V17.min_validator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_set_staking_configs_V17 - max_nominator_count */;
            return _toStringConfigOpu32(
                &m->nested.staking_set_staking_configs_V17.max_nominator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_set_staking_configs_V17 - max_validator_count */;
            return _toStringConfigOpu32(
                &m->nested.staking_set_staking_configs_V17.max_validator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_set_staking_configs_V17 - chill_threshold */;
            return _toStringConfigOpPercent(
                &m->nested.staking_set_staking_configs_V17.chill_threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* staking_set_staking_configs_V17 - min_commission */;
            return _toStringConfigOpPerbill(
                &m->nested.staking_set_staking_configs_V17.min_commission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2071: /* module 8 call 23 */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V17 - controller */;
            return _toStringAccountId(
                &m->nested.staking_chill_other_V17.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2072: /* module 8 call 24 */
        switch (itemIdx) {
        case 0: /* staking_force_apply_min_commission_V17 - validator_stash */;
            return _toStringAccountId(
                &m->nested.staking_force_apply_min_commission_V17.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2073: /* module 8 call 25 */
        switch (itemIdx) {
        case 0: /* staking_set_min_commission_V17 - new_ */;
            return _toStringPerbill(
                &m->nested.staking_set_min_commission_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V17 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_vest_other_V17.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V17 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_vested_transfer_V17.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V17 - schedule */;
            return _toStringVestingInfo(
                &m->basic.vesting_vested_transfer_V17.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V17 - source */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_force_vested_transfer_V17.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V17 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_force_vested_transfer_V17.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V17 - schedule */;
            return _toStringVestingInfo(
                &m->basic.vesting_force_vested_transfer_V17.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* vesting_merge_schedules_V17 - schedule1_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V17.schedule1_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_merge_schedules_V17 - schedule2_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V17.schedule2_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0: /* utility_dispatch_as_V17 - as_origin */;
            return _toStringBoxPalletsOrigin(
                &m->basic.utility_dispatch_as_V17.as_origin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_dispatch_as_V17 - call */;
            return _toStringCall(
                &m->basic.utility_dispatch_as_V17.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* utility_with_weight_V17 - call */;
            return _toStringCall(
                &m->basic.utility_with_weight_V17.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_with_weight_V17 - weight */;
            return _toStringWeight(
                &m->basic.utility_with_weight_V17.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V17 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_threshold_1_V17.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V17 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V17.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V17 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V17.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V17 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_V17.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V17 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_as_multi_V17.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V17 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_V17.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V17 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_as_multi_V17.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V17 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V17.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V17 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_approve_as_multi_V17.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V17 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_approve_as_multi_V17.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V17 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V17.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V17 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_approve_as_multi_V17.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V17 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V17.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V17 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_cancel_as_multi_V17.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V17 - timepoint */;
            return _toStringTimepoint(
                &m->nested.multisig_cancel_as_multi_V17.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V17 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V17.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_V17 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_V17.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_unchecked_weight_V17 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_unchecked_weight_V17.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_unchecked_weight_V17 - weight */;
            return _toStringWeight(
                &m->basic.sudo_sudo_unchecked_weight_V17.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* sudo_set_key_V17 - new_ */;
            return _toStringAccountIdLookupOfT(
                &m->basic.sudo_set_key_V17.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_as_V17 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.sudo_sudo_as_V17.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_as_V17 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_as_V17.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* contracts_call_old_weight_V17 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.contracts_call_old_weight_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_call_old_weight_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.contracts_call_old_weight_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_call_old_weight_V17 - gas_limit */;
            return _toStringCompactu64(
                &m->nested.contracts_call_old_weight_V17.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_call_old_weight_V17 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->nested.contracts_call_old_weight_V17.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_call_old_weight_V17 - data */;
            return _toStringVecu8(
                &m->nested.contracts_call_old_weight_V17.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_with_code_old_weight_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.contracts_instantiate_with_code_old_weight_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_with_code_old_weight_V17 - gas_limit */;
            return _toStringCompactu64(
                &m->nested.contracts_instantiate_with_code_old_weight_V17.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_with_code_old_weight_V17 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->nested.contracts_instantiate_with_code_old_weight_V17.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_with_code_old_weight_V17 - code */;
            return _toStringVecu8(
                &m->nested.contracts_instantiate_with_code_old_weight_V17.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_with_code_old_weight_V17 - data */;
            return _toStringVecu8(
                &m->nested.contracts_instantiate_with_code_old_weight_V17.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_with_code_old_weight_V17 - salt */;
            return _toStringVecu8(
                &m->nested.contracts_instantiate_with_code_old_weight_V17.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_old_weight_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.contracts_instantiate_old_weight_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_old_weight_V17 - gas_limit */;
            return _toStringCompactu64(
                &m->nested.contracts_instantiate_old_weight_V17.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_old_weight_V17 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->nested.contracts_instantiate_old_weight_V17.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_old_weight_V17 - code_hash */;
            return _toStringCodeHash(
                &m->nested.contracts_instantiate_old_weight_V17.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_old_weight_V17 - data */;
            return _toStringVecu8(
                &m->nested.contracts_instantiate_old_weight_V17.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_old_weight_V17 - salt */;
            return _toStringVecu8(
                &m->nested.contracts_instantiate_old_weight_V17.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0: /* contracts_upload_code_V17 - code */;
            return _toStringVecu8(
                &m->nested.contracts_upload_code_V17.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_upload_code_V17 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->nested.contracts_upload_code_V17.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_upload_code_V17 - determinism */;
            return _toStringDeterminism(
                &m->nested.contracts_upload_code_V17.determinism,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0: /* contracts_remove_code_V17 - code_hash */;
            return _toStringCodeHash(
                &m->nested.contracts_remove_code_V17.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0: /* contracts_set_code_V17 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.contracts_set_code_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_set_code_V17 - code_hash */;
            return _toStringCodeHash(
                &m->nested.contracts_set_code_V17.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0: /* contracts_call_V17 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.contracts_call_V17.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_call_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.contracts_call_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_call_V17 - gas_limit */;
            return _toStringWeight(
                &m->nested.contracts_call_V17.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_call_V17 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->nested.contracts_call_V17.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_call_V17 - data */;
            return _toStringVecu8(
                &m->nested.contracts_call_V17.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4615: /* module 18 call 7 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_with_code_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.contracts_instantiate_with_code_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_with_code_V17 - gas_limit */;
            return _toStringWeight(
                &m->nested.contracts_instantiate_with_code_V17.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_with_code_V17 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->nested.contracts_instantiate_with_code_V17.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_with_code_V17 - code */;
            return _toStringVecu8(
                &m->nested.contracts_instantiate_with_code_V17.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_with_code_V17 - data */;
            return _toStringVecu8(
                &m->nested.contracts_instantiate_with_code_V17.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_with_code_V17 - salt */;
            return _toStringVecu8(
                &m->nested.contracts_instantiate_with_code_V17.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.contracts_instantiate_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_V17 - gas_limit */;
            return _toStringWeight(
                &m->nested.contracts_instantiate_V17.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_V17 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->nested.contracts_instantiate_V17.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_V17 - code_hash */;
            return _toStringCodeHash(
                &m->nested.contracts_instantiate_V17.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_V17 - data */;
            return _toStringBytes(
                &m->nested.contracts_instantiate_V17.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_V17 - salt */;
            return _toStringBytes(
                &m->nested.contracts_instantiate_V17.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4617: /* module 18 call 9 */
        switch (itemIdx) {
        case 0: /* contracts_migrate_V17 - weight_limit */;
            return _toStringWeight(
                &m->nested.contracts_migrate_V17.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* nominationpools_join_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.nominationpools_join_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_join_V17 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_join_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        case 0: /* nominationpools_bond_extra_V17 - extra */;
            return _toStringBondExtraBalanceOfT(
                &m->nested.nominationpools_bond_extra_V17.extra,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0: /* nominationpools_unbond_V17 - member_account */;
            return _toStringAccountIdLookupOfT(
                &m->nested.nominationpools_unbond_V17.member_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_unbond_V17 - unbonding_points */;
            return _toStringCompactBalance(
                &m->nested.nominationpools_unbond_V17.unbonding_points,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0: /* nominationpools_pool_withdraw_unbonded_V17 - pool_id */;
            return _toStringPoolId(
                &m->basic.nominationpools_pool_withdraw_unbonded_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_pool_withdraw_unbonded_V17 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.nominationpools_pool_withdraw_unbonded_V17.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4869: /* module 19 call 5 */
        switch (itemIdx) {
        case 0: /* nominationpools_withdraw_unbonded_V17 - member_account */;
            return _toStringAccountIdLookupOfT(
                &m->nested.nominationpools_withdraw_unbonded_V17.member_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_withdraw_unbonded_V17 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.nominationpools_withdraw_unbonded_V17.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4870: /* module 19 call 6 */
        switch (itemIdx) {
        case 0: /* nominationpools_create_V17 - amount */;
            return _toStringCompactBalance(
                &m->nested.nominationpools_create_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_create_V17 - root */;
            return _toStringAccountIdLookupOfT(
                &m->nested.nominationpools_create_V17.root,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nominationpools_create_V17 - nominator */;
            return _toStringAccountIdLookupOfT(
                &m->nested.nominationpools_create_V17.nominator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nominationpools_create_V17 - bouncer */;
            return _toStringAccountIdLookupOfT(
                &m->nested.nominationpools_create_V17.bouncer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4871: /* module 19 call 7 */
        switch (itemIdx) {
        case 0: /* nominationpools_create_with_pool_id_V17 - amount */;
            return _toStringCompactBalance(
                &m->basic.nominationpools_create_with_pool_id_V17.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_create_with_pool_id_V17 - root */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nominationpools_create_with_pool_id_V17.root,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nominationpools_create_with_pool_id_V17 - nominator */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nominationpools_create_with_pool_id_V17.nominator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nominationpools_create_with_pool_id_V17 - bouncer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nominationpools_create_with_pool_id_V17.bouncer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* nominationpools_create_with_pool_id_V17 - pool_id */;
            return _toStringPoolId(
                &m->basic.nominationpools_create_with_pool_id_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4872: /* module 19 call 8 */
        switch (itemIdx) {
        case 0: /* nominationpools_nominate_V17 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_nominate_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_nominate_V17 - validators */;
            return _toStringVecAccountId(
                &m->nested.nominationpools_nominate_V17.validators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4873: /* module 19 call 9 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_state_V17 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_set_state_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_state_V17 - state */;
            return _toStringPoolState(
                &m->nested.nominationpools_set_state_V17.state,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4874: /* module 19 call 10 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_metadata_V17 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_set_metadata_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_metadata_V17 - metadata */;
            return _toStringVecu8(
                &m->nested.nominationpools_set_metadata_V17.metadata,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4875: /* module 19 call 11 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_configs_V17 - min_join_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->basic.nominationpools_set_configs_V17.min_join_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_configs_V17 - min_create_bond */;
            return _toStringConfigOpBalanceOfT(
                &m->basic.nominationpools_set_configs_V17.min_create_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nominationpools_set_configs_V17 - max_pools */;
            return _toStringConfigOpu32(
                &m->basic.nominationpools_set_configs_V17.max_pools,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nominationpools_set_configs_V17 - max_members */;
            return _toStringConfigOpu32(
                &m->basic.nominationpools_set_configs_V17.max_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* nominationpools_set_configs_V17 - max_members_per_pool */;
            return _toStringConfigOpu32(
                &m->basic.nominationpools_set_configs_V17.max_members_per_pool,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* nominationpools_set_configs_V17 - global_max_commission */;
            return _toStringConfigOpPerbill(
                &m->basic.nominationpools_set_configs_V17.global_max_commission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4876: /* module 19 call 12 */
        switch (itemIdx) {
        case 0: /* nominationpools_update_roles_V17 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_update_roles_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_update_roles_V17 - new_root */;
            return _toStringConfigOpAccountId(
                &m->nested.nominationpools_update_roles_V17.new_root,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nominationpools_update_roles_V17 - new_nominator */;
            return _toStringConfigOpAccountId(
                &m->nested.nominationpools_update_roles_V17.new_nominator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nominationpools_update_roles_V17 - new_bouncer */;
            return _toStringConfigOpAccountId(
                &m->nested.nominationpools_update_roles_V17.new_bouncer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4877: /* module 19 call 13 */
        switch (itemIdx) {
        case 0: /* nominationpools_chill_V17 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_chill_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4878: /* module 19 call 14 */
        switch (itemIdx) {
        case 0: /* nominationpools_bond_extra_other_V17 - member */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nominationpools_bond_extra_other_V17.member,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_bond_extra_other_V17 - extra */;
            return _toStringBondExtraBalanceOfT(
                &m->basic.nominationpools_bond_extra_other_V17.extra,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4879: /* module 19 call 15 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_claim_permission_V17 - permission */;
            return _toStringClaimPermission(
                &m->nested.nominationpools_set_claim_permission_V17.permission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4880: /* module 19 call 16 */
        switch (itemIdx) {
        case 0: /* nominationpools_claim_payout_other_V17 - other */;
            return _toStringAccountId(
                &m->nested.nominationpools_claim_payout_other_V17.other,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4881: /* module 19 call 17 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_commission_V17 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_set_commission_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_commission_V17 - new_commission */;
            return _toStringOptionTuplePerbillAccountId(
                &m->nested.nominationpools_set_commission_V17.new_commission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4882: /* module 19 call 18 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_commission_max_V17 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_set_commission_max_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_commission_max_V17 - max_commission */;
            return _toStringPerbill(
                &m->nested.nominationpools_set_commission_max_V17.max_commission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4883: /* module 19 call 19 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_commission_change_rate_V17 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_set_commission_change_rate_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_commission_change_rate_V17 - change_rate */;
            return _toStringCommissionChangeRateBlockNumber(
                &m->nested.nominationpools_set_commission_change_rate_V17.change_rate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4884: /* module 19 call 20 */
        switch (itemIdx) {
        case 0: /* nominationpools_claim_commission_V17 - pool_id */;
            return _toStringPoolId(
                &m->nested.nominationpools_claim_commission_V17.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V17(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2051: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2063: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2068: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 4868: // NominationPools:Pool withdraw unbonded
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 4869: // NominationPools:Withdraw Unbonded
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V17(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1285: // Balances:Force unreserve
    case 1286: // Balances:Upgrade accounts
    case 1288: // Balances:Force set balance
    case 3584: // Vesting:Vest
    case 3585: // Vesting:Vest other
    case 3586: // Vesting:Vested transfer
    case 3587: // Vesting:Force vested transfer
    case 3588: // Vesting:Merge schedules
    case 3840: // Utility:Batch
    case 3842: // Utility:Batch all
    case 3843: // Utility:Dispatch as
    case 3844: // Utility:Force batch
    case 3845: // Utility:With weight
    case 4352: // Sudo:Sudo
    case 4353: // Sudo:Sudo unchecked weight
    case 4354: // Sudo:Set key
    case 4355: // Sudo:Sudo as
    case 4868: // NominationPools:Pool withdraw unbonded
    case 4871: // NominationPools:Create with pool id
    case 4875: // NominationPools:Set configs
    case 4878: // NominationPools:Bond extra other
        return false;
    default:
        return true;
    }
}
