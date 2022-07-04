/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
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

#include "substrate_dispatch_V8.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V8(
    parser_context_t* c, pd_balances_transfer_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V8(
    parser_context_t* c, pd_balances_force_transfer_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V8(
    parser_context_t* c, pd_balances_transfer_keep_alive_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V8(
    parser_context_t* c, pd_balances_transfer_all_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V8(
    parser_context_t* c, pd_session_set_keys_V8_t* m)
{
    CHECK_ERROR(_readKeys_V8(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V8(
    parser_context_t* c, pd_session_purge_keys_V8_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V8(
    parser_context_t* c, pd_utility_batch_V8_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V8(
    parser_context_t* c, pd_utility_batch_all_V8_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V8(
    parser_context_t* c, pd_utility_force_batch_V8_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V8(
    parser_context_t* c, pd_system_fill_block_V8_t* m)
{
    CHECK_ERROR(_readPerbill_V8(c, &m->ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V8(
    parser_context_t* c, pd_system_remark_V8_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V8(
    parser_context_t* c, pd_system_set_heap_pages_V8_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V8(
    parser_context_t* c, pd_system_set_code_V8_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V8(
    parser_context_t* c, pd_system_set_code_without_checks_V8_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V8(
    parser_context_t* c, pd_system_remark_with_event_V8_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V8(
    parser_context_t* c, pd_timestamp_set_V8_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V8(
    parser_context_t* c, pd_balances_set_balance_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V8(
    parser_context_t* c, pd_balances_force_unreserve_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V8(
    parser_context_t* c, pd_vesting_vest_V8_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V8(
    parser_context_t* c, pd_vesting_vest_other_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V8(
    parser_context_t* c, pd_vesting_vested_transfer_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V8(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V8(
    parser_context_t* c, pd_vesting_force_vested_transfer_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V8(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_merge_schedules_V8(
    parser_context_t* c, pd_vesting_merge_schedules_V8_t* m)
{
    CHECK_ERROR(_readu32(c, &m->schedule1_index))
    CHECK_ERROR(_readu32(c, &m->schedule2_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V8(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V8_t* m)
{
    CHECK_ERROR(_readVecAccountId_V8(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V8(
    parser_context_t* c, pd_multisig_as_multi_V8_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V8(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V8(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V8(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V8(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V8(
    parser_context_t* c, pd_multisig_approve_as_multi_V8_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V8(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V8(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V8(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V8(
    parser_context_t* c, pd_multisig_cancel_as_multi_V8_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V8(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V8(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_V8(
    parser_context_t* c, pd_sudo_sudo_V8_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight_V8(
    parser_context_t* c, pd_sudo_sudo_unchecked_weight_V8_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight_V8(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V8(
    parser_context_t* c, pd_sudo_set_key_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as_V8(
    parser_context_t* c, pd_sudo_sudo_as_V8_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V8(c, &m->who))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V8(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V8_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V8(c, &method->nested.balances_transfer_V8))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V8(c, &method->nested.balances_force_transfer_V8))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V8(c, &method->nested.balances_transfer_keep_alive_V8))
        break;
    case 1284: /* module 5 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V8(c, &method->basic.balances_transfer_all_V8))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V8(c, &method->basic.session_set_keys_V8))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V8(c, &method->basic.session_purge_keys_V8))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V8(c, &method->basic.utility_batch_V8))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V8(c, &method->basic.utility_batch_all_V8))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V8(c, &method->basic.utility_force_batch_V8))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V8(c, &method->nested.system_fill_block_V8))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V8(c, &method->nested.system_remark_V8))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V8(c, &method->nested.system_set_heap_pages_V8))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V8(c, &method->nested.system_set_code_V8))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V8(c, &method->nested.system_set_code_without_checks_V8))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V8(c, &method->nested.system_remark_with_event_V8))
        break;
    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V8(c, &method->basic.timestamp_set_V8))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V8(c, &method->nested.balances_set_balance_V8))
        break;
    case 1285: /* module 5 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V8(c, &method->basic.balances_force_unreserve_V8))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V8(c, &method->basic.vesting_vest_V8))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V8(c, &method->basic.vesting_vest_other_V8))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V8(c, &method->basic.vesting_vested_transfer_V8))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V8(c, &method->basic.vesting_force_vested_transfer_V8))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_vesting_merge_schedules_V8(c, &method->basic.vesting_merge_schedules_V8))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V8(c, &method->nested.multisig_as_multi_threshold_1_V8))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V8(c, &method->nested.multisig_as_multi_V8))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V8(c, &method->nested.multisig_approve_as_multi_V8))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V8(c, &method->nested.multisig_cancel_as_multi_V8))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_sudo_sudo_V8(c, &method->basic.sudo_sudo_V8))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight_V8(c, &method->basic.sudo_sudo_unchecked_weight_V8))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V8(c, &method->basic.sudo_set_key_V8))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_sudo_sudo_as_V8(c, &method->basic.sudo_sudo_as_V8))
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

const char* _getMethod_ModuleName_V8(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 5:
        return STR_MO_BALANCES;
    case 10:
        return STR_MO_SESSION;
    case 15:
        return STR_MO_UTILITY;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 4:
        return STR_MO_TIMESTAMP;
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

const char* _getMethod_Name_V8(uint8_t moduleIdx, uint8_t callIdx)
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
        return _getMethod_Name_V8_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V8_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 8: /* module 0 call 8 */
        return STR_ME_REMARK_WITH_EVENT;
    case 1024: /* module 4 call 0 */
        return STR_ME_SET;
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

uint8_t _getMethod_NumItems_V8(uint8_t moduleIdx, uint8_t callIdx)
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
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 8: /* module 0 call 8 */
        return 1;
    case 1024: /* module 4 call 0 */
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
    case 4096: /* module 16 call 0 */
        return 2;
    case 4097: /* module 16 call 1 */
        return 6;
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

const char* _getMethod_ItemName_V8(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
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
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
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
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
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
            return STR_IT_store_call;
        case 5:
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

parser_error_t _getMethod_ItemValue_V8(
    pd_Method_V8_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V8 - dest */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->nested.balances_transfer_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V8 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V8 - source */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->nested.balances_force_transfer_V8.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V8 - dest */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->nested.balances_force_transfer_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V8 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V8 - dest */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->nested.balances_transfer_keep_alive_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V8 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V8.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V8 - dest */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->basic.balances_transfer_all_V8.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V8 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V8.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V8 - keys */;
            return _toStringKeys_V8(
                &m->basic.session_set_keys_V8.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V8 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V8.proof,
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
        case 0: /* utility_batch_V8 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V8.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V8 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V8.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V8 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V8.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V8 - ratio */;
            return _toStringPerbill_V8(
                &m->nested.system_fill_block_V8.ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V8 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_V8.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V8 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V8.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V8 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V8.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V8 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V8.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V8 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_with_event_V8.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V8 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V8.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V8 - who */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->nested.balances_set_balance_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V8 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V8.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V8 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V8.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1285: /* module 5 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V8 - who */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->basic.balances_force_unreserve_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V8 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V8.amount,
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
        case 0: /* vesting_vest_other_V8 - target */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->basic.vesting_vest_other_V8.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V8 - target */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->basic.vesting_vested_transfer_V8.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V8 - schedule */;
            return _toStringVestingInfo_V8(
                &m->basic.vesting_vested_transfer_V8.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V8 - source */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->basic.vesting_force_vested_transfer_V8.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V8 - target */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->basic.vesting_force_vested_transfer_V8.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V8 - schedule */;
            return _toStringVestingInfo_V8(
                &m->basic.vesting_force_vested_transfer_V8.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* vesting_merge_schedules_V8 - schedule1_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V8.schedule1_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_merge_schedules_V8 - schedule2_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V8.schedule2_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V8 - other_signatories */;
            return _toStringVecAccountId_V8(
                &m->nested.multisig_as_multi_threshold_1_V8.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V8 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V8 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V8.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V8 - other_signatories */;
            return _toStringVecAccountId_V8(
                &m->nested.multisig_as_multi_V8.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V8 - maybe_timepoint */;
            return _toStringOptionTimepoint_V8(
                &m->nested.multisig_as_multi_V8.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V8 - call */;
            return _toStringOpaqueCall_V8(
                &m->nested.multisig_as_multi_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V8 - store_call */;
            return _toStringbool(
                &m->nested.multisig_as_multi_V8.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V8 - max_weight */;
            return _toStringWeight_V8(
                &m->nested.multisig_as_multi_V8.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V8 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V8.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V8 - other_signatories */;
            return _toStringVecAccountId_V8(
                &m->nested.multisig_approve_as_multi_V8.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V8 - maybe_timepoint */;
            return _toStringOptionTimepoint_V8(
                &m->nested.multisig_approve_as_multi_V8.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V8 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V8.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V8 - max_weight */;
            return _toStringWeight_V8(
                &m->nested.multisig_approve_as_multi_V8.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V8 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V8.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V8 - other_signatories */;
            return _toStringVecAccountId_V8(
                &m->nested.multisig_cancel_as_multi_V8.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V8 - timepoint */;
            return _toStringTimepoint_V8(
                &m->nested.multisig_cancel_as_multi_V8.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V8 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V8.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_V8 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_unchecked_weight_V8 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_unchecked_weight_V8.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_unchecked_weight_V8 - weight */;
            return _toStringWeight_V8(
                &m->basic.sudo_sudo_unchecked_weight_V8.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* sudo_set_key_V8 - new_ */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->basic.sudo_set_key_V8.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_as_V8 - who */;
            return _toStringLookupasStaticLookupSource_V8(
                &m->basic.sudo_sudo_as_V8.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_as_V8 - call */;
            return _toStringCall(
                &m->basic.sudo_sudo_as_V8.call,
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

bool _getMethod_ItemIsExpert_V8(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V8(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: // Timestamp:Set
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
    case 4352: // Sudo:Sudo
    case 4353: // Sudo:Sudo unchecked weight
    case 4354: // Sudo:Set key
    case 4355: // Sudo:Sudo as
        return false;
    default:
        return true;
    }
}
