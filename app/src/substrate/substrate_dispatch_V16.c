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

#include "substrate_dispatch_V16.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_V16(
    parser_context_t* c, pd_balances_transfer_V16_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V16(
    parser_context_t* c, pd_balances_force_transfer_V16_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V16(
    parser_context_t* c, pd_balances_transfer_keep_alive_V16_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V16(
    parser_context_t* c, pd_balances_transfer_all_V16_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V16(
    parser_context_t* c, pd_session_set_keys_V16_t* m)
{
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V16(
    parser_context_t* c, pd_session_purge_keys_V16_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V16(
    parser_context_t* c, pd_utility_batch_V16_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V16(
    parser_context_t* c, pd_utility_batch_all_V16_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V16(
    parser_context_t* c, pd_utility_force_batch_V16_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V16(
    parser_context_t* c, pd_system_remark_V16_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V16(
    parser_context_t* c, pd_system_set_heap_pages_V16_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V16(
    parser_context_t* c, pd_system_set_code_V16_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V16(
    parser_context_t* c, pd_system_set_code_without_checks_V16_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V16(
    parser_context_t* c, pd_system_remark_with_event_V16_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V16(
    parser_context_t* c, pd_balances_set_balance_V16_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V16(
    parser_context_t* c, pd_balances_force_unreserve_V16_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V16(
    parser_context_t* c, pd_vesting_vest_V16_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V16(
    parser_context_t* c, pd_vesting_vest_other_V16_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V16(
    parser_context_t* c, pd_vesting_vested_transfer_V16_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V16(
    parser_context_t* c, pd_vesting_force_vested_transfer_V16_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_merge_schedules_V16(
    parser_context_t* c, pd_vesting_merge_schedules_V16_t* m)
{
    CHECK_ERROR(_readu32(c, &m->schedule1_index))
    CHECK_ERROR(_readu32(c, &m->schedule2_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V16(
    parser_context_t* c, pd_utility_with_weight_V16_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V16(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V16_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V16(
    parser_context_t* c, pd_multisig_as_multi_V16_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V16(
    parser_context_t* c, pd_multisig_approve_as_multi_V16_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V16(
    parser_context_t* c, pd_multisig_cancel_as_multi_V16_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_V16(
    parser_context_t* c, pd_sudo_sudo_V16_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight_V16(
    parser_context_t* c, pd_sudo_sudo_unchecked_weight_V16_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V16(
    parser_context_t* c, pd_sudo_set_key_V16_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as_V16(
    parser_context_t* c, pd_sudo_sudo_as_V16_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V16(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V16_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V16(c, &method->nested.balances_transfer_V16))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V16(c, &method->nested.balances_force_transfer_V16))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V16(c, &method->nested.balances_transfer_keep_alive_V16))
        break;
    case 1284: /* module 5 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V16(c, &method->basic.balances_transfer_all_V16))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V16(c, &method->basic.session_set_keys_V16))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V16(c, &method->basic.session_purge_keys_V16))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V16(c, &method->basic.utility_batch_V16))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V16(c, &method->basic.utility_batch_all_V16))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V16(c, &method->basic.utility_force_batch_V16))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_remark_V16(c, &method->nested.system_remark_V16))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V16(c, &method->nested.system_set_heap_pages_V16))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_code_V16(c, &method->nested.system_set_code_V16))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V16(c, &method->nested.system_set_code_without_checks_V16))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V16(c, &method->nested.system_remark_with_event_V16))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V16(c, &method->nested.balances_set_balance_V16))
        break;
    case 1285: /* module 5 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V16(c, &method->basic.balances_force_unreserve_V16))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V16(c, &method->basic.vesting_vest_V16))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V16(c, &method->basic.vesting_vest_other_V16))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V16(c, &method->basic.vesting_vested_transfer_V16))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V16(c, &method->basic.vesting_force_vested_transfer_V16))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_vesting_merge_schedules_V16(c, &method->basic.vesting_merge_schedules_V16))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_utility_with_weight_V16(c, &method->basic.utility_with_weight_V16))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V16(c, &method->nested.multisig_as_multi_threshold_1_V16))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V16(c, &method->nested.multisig_as_multi_V16))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V16(c, &method->nested.multisig_approve_as_multi_V16))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V16(c, &method->nested.multisig_cancel_as_multi_V16))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_sudo_sudo_V16(c, &method->basic.sudo_sudo_V16))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight_V16(c, &method->basic.sudo_sudo_unchecked_weight_V16))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V16(c, &method->basic.sudo_set_key_V16))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_sudo_sudo_as_V16(c, &method->basic.sudo_sudo_as_V16))
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

const char* _getMethod_ModuleName_V16(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 5:
        return STR_MO_BALANCES;
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
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V16(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        return STR_ME_TRANSFER;
    case 1282: /* module 5 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1283: /* module 5 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1284: /* module 5 call 4 */
        return STR_ME_TRANSFER_ALL;
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
        return _getMethod_Name_V16_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V16_ParserFull(uint16_t callPrivIdx)
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
        return STR_ME_SET_BALANCE;
    case 1285: /* module 5 call 5 */
        return STR_ME_FORCE_UNRESERVE;
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
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V16(uint8_t moduleIdx, uint8_t callIdx)
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
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V16(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
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
            return STR_IT_new_reserved;
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
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V16(
    pd_Method_V16_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V16 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_V16.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V16 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V16.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V16 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V16.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V16 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V16.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V16 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V16.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V16 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_keep_alive_V16.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V16 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V16.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V16 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_transfer_all_V16.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V16 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V16.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V16 - keys */;
            return _toStringKeys(
                &m->basic.session_set_keys_V16.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V16 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V16.proof,
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
        case 0: /* utility_batch_V16 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V16.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V16 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V16.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V16 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V16.calls,
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
        case 0: /* system_remark_V16 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V16.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V16 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V16.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_code_V16 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V16.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V16 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V16.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V16 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V16.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V16 - who */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_set_balance_V16.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V16 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V16.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V16 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V16.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1285: /* module 5 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V16 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_unreserve_V16.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V16 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V16.amount,
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
        case 0: /* vesting_vest_other_V16 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_vest_other_V16.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V16 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_vested_transfer_V16.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V16 - schedule */;
            return _toStringVestingInfo(
                &m->basic.vesting_vested_transfer_V16.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V16 - source */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_force_vested_transfer_V16.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V16 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.vesting_force_vested_transfer_V16.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V16 - schedule */;
            return _toStringVestingInfo(
                &m->basic.vesting_force_vested_transfer_V16.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* vesting_merge_schedules_V16 - schedule1_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V16.schedule1_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_merge_schedules_V16 - schedule2_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V16.schedule2_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* utility_with_weight_V16 - call */;
            return _toStringCall(
                &m->basic.utility_with_weight_V16.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_with_weight_V16 - weight */;
            return _toStringWeight(
                &m->basic.utility_with_weight_V16.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V16 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_threshold_1_V16.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V16 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V16.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V16 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V16.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V16 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_V16.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V16 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_as_multi_V16.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V16 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_V16.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V16 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_as_multi_V16.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V16 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V16.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V16 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_approve_as_multi_V16.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V16 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_approve_as_multi_V16.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V16 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V16.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V16 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_approve_as_multi_V16.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V16 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V16.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V16 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_cancel_as_multi_V16.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V16 - timepoint */;
            return _toStringTimepoint(
                &m->nested.multisig_cancel_as_multi_V16.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V16 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V16.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_V16 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_V16.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_unchecked_weight_V16 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_unchecked_weight_V16.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_unchecked_weight_V16 - weight */;
            return _toStringWeight(
                &m->basic.sudo_sudo_unchecked_weight_V16.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* sudo_set_key_V16 - new_ */;
            return _toStringAccountIdLookupOfT(
                &m->basic.sudo_set_key_V16.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_as_V16 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.sudo_sudo_as_V16.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_as_V16 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_as_V16.call,
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

bool _getMethod_ItemIsExpert_V16(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V16(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1284: // Balances:Transfer all
    case 1285: // Balances:Force unreserve
    case 2560: // Session:Set keys
    case 2561: // Session:Purge keys
    case 3584: // Vesting:Vest
    case 3585: // Vesting:Vest other
    case 3586: // Vesting:Vested transfer
    case 3587: // Vesting:Force vested transfer
    case 3588: // Vesting:Merge schedules
    case 3840: // Utility:Batch
    case 3842: // Utility:Batch all
    case 3844: // Utility:Force batch
    case 3845: // Utility:With weight
    case 4352: // Sudo:Sudo
    case 4353: // Sudo:Sudo unchecked weight
    case 4354: // Sudo:Set key
    case 4355: // Sudo:Sudo as
        return false;
    default:
        return true;
    }
}
